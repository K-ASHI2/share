#include"DxLib.h"
#include"extern.h"
#include"function.h"

//敵の出現情報を読み込む関数
void LoadEmerge() {

	int fp;
	switch (world) {
	case ew_1: fp = FileRead_open("pattern/emerge1.csv"); break;
	case ew_2: fp = FileRead_open("pattern/emerge2.csv"); break;
	case ew_3: fp = FileRead_open("pattern/emerge3.csv"); break;
	case ew_4: fp = FileRead_open("pattern/emerge4.csv"); break;
	case ew_extra: fp = FileRead_open("pattern/emergeExtra.csv"); break;
	}
		
	if (fp == NULL) {
		OutputDebugString("Enemy Data Read Error\n");	//もしマップデータが開くことが出来なかったらデバッグ画面に"Enemy Data Read Error"と表示
		exit(EXIT_FAILURE);
	}
	else{

		//最初の2行は説明のみ書いてあるので飛ばす
		for (int i = 0; i < 2; i++) {
			while (FileRead_getc(fp) != '\n');
		}

		char inputc[64];	//入力の数字を入れる配列
		int input[64];		//入力の文字コードを入れる配列
		int n = 0;	//敵の持つステータスの項目の番号
		int j = 0;	//敵の出現情報の配列の添え字
		while (1) {

			for (int i = 0; i < 64; i++) {
				//配列に入力の数字と文字コードを入れる
				inputc[i] = input[i] = FileRead_getc(fp);
				//'/'で始まる行はプログラムに関係ないので行末まで読み飛ばす
				if (input[i] == '/') {
					while (FileRead_getc(fp) != '\n');
					i = -1;
					continue;
				}
				else if (input[i] == ',' || input[i] == '\n') {
					inputc[i] = '\0';
					break;
				}
				if (input[i] == EOF) {
					FileRead_close(fp);
					return;
				}
			}
			//敵の出現データを入れる
			switch (n) {
			case 0: enemyemerge[j].frame = atoi(inputc); break;
			case 1: enemyemerge[j].pattern = atoi(inputc); break;
			case 2: enemyemerge[j].kind = atoi(inputc); break;
			case 3: enemyemerge[j].x = atoi(inputc); break;
			case 4: enemyemerge[j].y = atoi(inputc); break;
			case 5: enemyemerge[j].v = atoi(inputc); break;
			case 6: enemyemerge[j].hp = atoi(inputc); break;
			case 7: enemyemerge[j].wait = atoi(inputc); break;
			case 8: enemyemerge[j].bt = atoi(inputc); break;
			case 9: enemyemerge[j].bkind = atoi(inputc); break;
			case 10:enemyemerge[j].color = atoi(inputc); break;
			case 11:enemyemerge[j].item = atoi(inputc); break;
			}
			n++;
			if (n == 12) {
				n = 0;
				j++;
			}
		}

		/*while (fscanf(fp, "%d,", &map2[k]) != EOF) {
			k++;
		}*/

	}
	FileRead_close(fp);
}
