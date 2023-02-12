#include"DxLib.h"
#include"extern.h"
#include"function.h"

//ポーズ画面の描画
void drawPause() {

	DrawGraph(0, 0, img.title, TRUE);
	DrawRed(100, 100, "COUTINUE", 0);
	DrawRed(100, 180, "STAGE SERECT", 1);
	DrawRed(100, 260, "TITLE", 2);
	switch (cursor) {
	case 0: DrawString(100, 500, "ゲームに戻ります", green); break;
	case 1: DrawString(100, 500, "ステージ選択をします", green); break;
	case 2: DrawString(100, 500, "タイトル画面に戻ります", green); break;
	}
	DrawGraph(60, 98 + cursor * 80, img.arrow, TRUE);

	DrawStringToHandle(400, 360, "十字ボタン 選択", red, Font[2]);
	DrawStringToHandle(400, 400, "A・B 　　　決定", red, Font[2]);
	DrawStringToHandle(400, 440, "X・Y 　　　キャンセル", red, Font[2]);
}
