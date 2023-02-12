#include"DxLib.h"
#include"extern.h"
#include"function.h"

//マップチップ読み込み
void ReadMap() {
	FILE *fp = NULL;

	//mapload変数から読み込むファイル名の文字列を生成し、そのファイルを開く
	fp = fopen(mapToChar(), "r");

	if (fp == NULL) {
		OutputDebugString("MapData Read Error\n");	//もしマップデータが開くことが出来なかったらデバッグ画面に"Map Data Read Error"と表示
		exit(EXIT_FAILURE);
	}

	static int LENGTH = 16;	//入力の桁数の限界
	char inputc[16];	//入力の数字を入れる配列
	int input[16];		//入力の文字コードを入れる配列
	int n = 0;	//敵の持つステータスの項目の番号
	int j = 0;	//敵の出現情報の配列の添え字

	input[0] = getc(fp);
	inputc[0] = (char)input[0];

	//最初の行は/で始まっていればならない
	if (input[0] == '/') {
		while (getc(fp) != '\n');
	}
	else {
		fclose(fp);
		OutputDebugString("MapData Format Error\n");
		exit(EXIT_FAILURE);
	}
	for (int j = 0; j < 5; j++) {
		//for文だが実質無限ループに近いので一つの項目を読んだらbreakで抜ける
		for (int i = 0; i < LENGTH; i++) {
			input[i] = getc(fp);
			inputc[i] = (char)input[i];
			//'/'で始まる行はコメント行なので行末まで読み飛ばす
			if (input[i] == '/') {
				//fgetsでも1行読み取れるが配列の長さが文字数分必要で長くなりすぎるため使わない
				while (getc(fp) != '\n');
				i = -1;
				continue;
			}
			//,が来たらその文字までを区切りとして読み取る
			else if (input[i] == ',') {
				//文字が無ければ読み飛ばす
				if (i == 0) {
					i = -1;
					continue;
				}
				inputc[i] = '\0';
				switch (j) {
				case 0:	width_size = atoi(inputc); break;
				case 1:	height_size = atoi(inputc); break;
				case 2:	background_n = atoi(inputc); break;
				case 3:	music_n = atoi(inputc); break;
				case 4:	scroll_v = atoi(inputc); break;
				}
				//1項目読み取ったら次の項目を読むためにfor文を抜ける
				break;
			}
			else if (input[i] == '\n') {
				inputc[i] = '\0';
				break;
			}
			//ファイルの終わりまで読み込んでしまったら閉じる
			else if (input[i] == EOF) {
				fclose(fp);
				OutputDebugString("マップのステータスが不足しています。\n");
				exit(EXIT_FAILURE);
			}
		}
	}

	//ステータスの項目を読み終わったらその行は終わりまで飛ばす
	while (getc(fp) != '\n');

	//残りの行はマップ読み込みとなる
	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			//ファイルの終わりまで読み込んでしまったら閉じる
			if (fscanf(fp, "%d,", &map[i][j]) == EOF) {
				fclose(fp);
				OutputDebugString("マップのデータが不足しています。\n");
				exit(EXIT_FAILURE);
			}
		}
	}
	fclose(fp);
}