#include"DxLib.h"
#include"extern.h"
#include"function.h"

//ハイスコアをファイルから読み込む関数
void LoadHiscore() {

	CreateSaveFile();	//セーブデータが無ければ作成する(直接readで開くとエラーとなる)

	FILE *fp = fopen("savedata/score.dat", "rb"); // ファイルを開く

	//ハイスコアをファイルから読み込む
	fread(&hiscore, sizeof(hiscore), 1, fp);

	fclose(fp); //ファイルを閉じる
}

//ハイスコアをファイルに書き込む関数
void WriteHiscore() {

	FILE *fp = fopen("savedata/score.dat", "wb");	//ファイルを書き込みで開く(ファイルが無かったら作る)
	fwrite(&hiscore, sizeof(hiscore), 1, fp); //ファイルに書き込む
	fclose(fp); //ファイルを閉じる
}

//セーブデータが無ければ作成する関数
void CreateSaveFile() {

	//ファイルが無かったら書き込む
	FILE *fp = fopen("savedata/score.dat", "ab");	//追加書き込みにすることですでにあるファイルを消さない
	if (fp == NULL) {
		hiscore = 0;
		fwrite(&hiscore, sizeof(hiscore), 1, fp);	//ファイルに書き込む
	}
	fclose(fp); //ファイルを閉じる
}
