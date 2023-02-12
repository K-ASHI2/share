#include"DxLib.h"
#include"extern.h"
#include"function.h"

//mapload変数から読み込むテキストファイル名を生成し返す関数
//ファイル名の例 mapload = 111の時 : "map_e/1-1.txt"
char *mapToChar() {
	static char *r;	//実際に読み込むファイル名の先頭のポインタを保持する変数
	char *c;		//ファイル名を作っていくポインタ
	char d[2];		//itoa関数を使うときの値を保持する関数(終端文字も含めて配列の大きさは2にする)

	c = (char *)malloc(20);
	r = c;

	//easyもノーマルのマップを使う
	switch (mapload / 1000) {
	case 0: strcpy(c, "map_e/"); break;
	case 1: strcpy(c, "map_n/"); break;
	case 2: strcpy(c, "map_h/"); break;
	case 3: strcpy(c, "map_l/"); break;
	}

	//100の位をchar型に変換し、後ろに追加
	itoa(mapload % 1000 / 100, d, 10);
	strcat(c, d);
	//-を間に入れる
	strcat(c, "-");
	//10の位をchar型に変換し、後ろに追加
	itoa(mapload % 100 / 10, d, 10);
	strcat(c, d);
	//-を間に入れる
	strcat(c, "-");
	//1の位をchar型に変換し、後ろに追加
	itoa(mapload % 10, d, 10);
	strcat(c, d);
	//.txtを後ろに追加する
	strcat(c, ".txt");
	return r;
}
