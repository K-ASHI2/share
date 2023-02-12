#include"DxLib.h"
#include"extern.h"
#include"function.h"

void DrawBackground() {

	for (int i = 0; i < 4; i++) {
		DrawGraph(/*-stage_x + */background[background_n].size_x * i, 0, background[background_n].img, TRUE);
	}
}
