#pragma once
#include"DxLib.h"
#include"extern.h"
#include"function.h"

//難易度選択の描画
void drawDifficultySelect() {

	DrawGraph(0, 0, img.title, TRUE);
	DrawRed(100, 100, "EASY", 0);
	DrawRed(100, 180, "NORMAL", 1);
	DrawRed(100, 260, "HARD", 2);
	DrawString(100, 500, "難易度の選択をしてください", green);

	DrawGraph(60, 98 + cursor * 80, img.arrow, TRUE);
	DrawStringToHandle(400, 360, "十字ボタン 選択", red, Font[2]);
	DrawStringToHandle(400, 400, "A・B 　　　決定", red, Font[2]);
	DrawStringToHandle(400, 440, "X・Y 　　　キャンセル", red, Font[2]);
}
