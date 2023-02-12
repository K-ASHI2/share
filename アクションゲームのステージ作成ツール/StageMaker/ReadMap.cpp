#include"DxLib.h"
#include"extern.h"
#include"function.h"

//マップデータの読み込み
//マップチップのみのファイルでも自動判別できるようになっている
//_FileName:読み込むマップファイルのパス
void ReadMap(const char *_FileName) {
	FILE *fp = NULL;

	//引数からファイルのパスを受け取り、そのファイルを開く
	fp = fopen(_FileName, "r");

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
	//最初の行は/で始まっていればなら飛ばし、そうでなければマップデータのみのファイル読み込みを試す
	if (input[0] == '/') {
		while (getc(fp) != '\n');
	}
	else {
		fclose(fp);
		ReadSimpleMap(_FileName);
		return;
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
				MessageBox(hMainWnd, "マップのステータスが不足しています。", "STAGE MAKER", MB_OK);
				return;
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
				MessageBox(hMainWnd, "マップのデータが不足しています。", "STAGE MAKER", MB_OK);
				return;
			}
		}
	}
	fclose(fp);
}

//古いバージョンのマップ読み込み
//_FileName:読み込むマップファイルのパス
void ReadSimpleMap(const char *_FileName) {
	FILE *fp = NULL;

	//引数からファイルのパスを受け取り、そのファイルを開く
	fp = fopen(_FileName, "r");

	if (fp == NULL) {
		OutputDebugString("MapData Read Error\n");	//もしマップデータが開くことが出来なかったらデバッグ画面に"Map Data Read Error"と表示
		exit(EXIT_FAILURE);
	}
	int map2[HEIGHT_SIZE * MAX_WIDTH + 1];
	int k = 0;

	for (int i = 0; i < HEIGHT_SIZE * MAX_WIDTH + 1; i++) {
		map2[i] = 0;
	}

	while (fscanf(fp, "%d,", &map2[k]) != EOF) {
		k++;
		if (k > HEIGHT_SIZE * MAX_WIDTH) {
			fclose(fp);
			MessageBox(hMainWnd, "マップが読み込めませんでした。", "STAGE MAKER", MB_OK);
			return;
		}
	}

	//マップが読み込めたらステージの高さを画面の高さにそろえる
	height_size = HEIGHT_SIZE;

	//マップからの背景の読み込み
	if (k % HEIGHT_SIZE == 1)//読み込んだマップにあまりがある場合そのあまりが背景となる
		background_n = map2[k - 1];
	width_size = k / HEIGHT_SIZE;
	k = 0;
	for (int j = 0; j < HEIGHT_SIZE; j++) {
		for (int i = 0; i < width_size; i++) {
			map[i][j] = map2[k];
			k++;
		}
	}
	fclose(fp);
}

//引数を指定しない場合CurrentFileをパスとする
void ReadMap() {
	ReadMap(CurrentFile);
}

//新規作成
void NewMap() {
	/*ReadMap("default.txt");*/
	ReadMap("default2.csv");
	CurrentFile = "default2.csv";
}
