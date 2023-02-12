#include"DxLib.h"
#include"extern.h"
#include"function.h"

//タイトル画面の描画するメソッド
void drawTitle() {

	DrawGraph(0, 0, img.title, TRUE);
	DrawRed(100, 100, "GAME START", 0);
	//DrawRed(100, 180, "menu2", 1);
	//DrawRed(100, 260, "menu3", 2);
	DrawRed(100, 180, "EXIT", 1);
	DrawStringToHandle(400, 360, "十字ボタン 選択", red, Font[2]);
	DrawStringToHandle(400, 400, "A・B 　　　決定", red, Font[2]);
	DrawStringToHandle(400, 440, "X・Y 　　　キャンセル", red, Font[2]);

	//選択中の項目に関する説明
	switch (cursor) {
	case 0: DrawString(100, 500, "ステージを選んでゲームを始めます", green); break;
	//case 1: DrawString(100, 500, "menu2", green); break;
	//case 2: DrawString(100, 500, "menu3", green); break;
	case 1: DrawString(100, 500, "ゲームを終了します", green); break;
	}
	DrawGraph(60, 98 + cursor * 80, img.arrow, TRUE);
}
