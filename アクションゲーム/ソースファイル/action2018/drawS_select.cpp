#pragma once
#include"DxLib.h"
#include"extern.h"
#include"function.h"

//ステージ選択の描画
void drawStageSelect(){

	DrawGraph(0, 0, img.title, TRUE);
	DrawString(100, 500, "ステージを選択してください", green);
	DrawRed2(100, 100, "1-1", 0, 0);
	DrawRed2(250, 100, "1-2", 0, 1);
	DrawRed2(400, 100, "1-3", 0, 2);
	DrawRed2(550, 100, "1-4", 0, 3);
	DrawRed2(100, 150, "2-1", 1, 0);
	DrawRed2(250, 150, "2-2", 1, 1);
	DrawRed2(400, 150, "2-3", 1, 2);
	DrawRed2(550, 150, "2-4", 1, 3);
	DrawRed2(100, 200, "3-1", 2, 0);
	DrawRed2(250, 200, "3-2", 2, 1);
	DrawRed2(400, 200, "3-3", 2, 2);
	DrawRed2(550, 200, "3-4", 2, 3);
	DrawRed2(100, 250, "4-1", 3, 0);
	DrawRed2(250, 250, "4-2", 3, 1);
	DrawRed2(400, 250, "4-3", 3, 2);
	DrawRed2(550, 250, "4-4", 3, 3);
	DrawGraph(60 + cursor_LR * 150, 98 + cursor * 50, img.arrow, TRUE);

	DrawStringToHandle(400, 360, "十字ボタン 選択", red, Font[2]);
	DrawStringToHandle(400, 400, "A・B 　　　決定", red, Font[2]);
	DrawStringToHandle(400, 440, "X・Y 　　　キャンセル", red, Font[2]);
}