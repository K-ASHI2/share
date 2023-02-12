#include"DxLib.h"
#include"extern.h"
#include"function.h"

//マップファイルに書き込む関数
void WriteMap() {

	FILE *fp = NULL;

	if ((fp = fopen(CurrentFile, "w")) == NULL) {
		OutputDebugString("MapData Write Error\n");
		exit(EXIT_FAILURE);
	}
	//パラメータの説明
	fprintf(fp, "/横幅,縦幅,背景,音楽,スクロール,\n");

	//パラメータ
	fprintf(fp, " %d,", width_size);
	fprintf(fp, " %d,", height_size);
	fprintf(fp, " %d,", background_n);
	fprintf(fp, " %d,", music_n);
	fprintf(fp, " %d,", scroll_v);
	fprintf(fp, "\n");

	//マップデータ
	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			fprintf(fp, " %d,", map[i][j]);
		}
		fprintf(fp, "\n");
	}

	fclose(fp);
}
