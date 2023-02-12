#include"DxLib.h"
#include"math.h"
#include"extern.h"
#include"function.h"	//共通の関数

void DrawStage() {

	//画面クリア
	ClearDrawScreen();

	//背景の描画
	DrawBackground();

	DrawMap();	//画面内のマップの描画

	//スクロールバーの表示
	DrawGraph(0, WINDOW_HEIGHT, img.bar1, TRUE);
	DrawTurnGraph(2, WINDOW_HEIGHT + 2, img.barRIGHT, TRUE);
	DrawGraph(WINDOW_WIDTH - 2 - 16, WINDOW_HEIGHT + 2, img.barRIGHT, TRUE);
	DrawGraph(WINDOW_WIDTH, 0, img.bar2, TRUE);
	DrawGraph(WINDOW_WIDTH + 2, 2, img.barUP, TRUE);
	DrawGraph(WINDOW_WIDTH + 2, WINDOW_HEIGHT - 2 - 16, img.barDOWN, TRUE);
	//右下の角
	DrawGraph(WINDOW_WIDTH, WINDOW_HEIGHT, img.bar3, TRUE);

	//スクロールバーの描画 
	//スクロールしない場合は表示しない
	if (width_size * block_size > WINDOW_WIDTH) {
		if (scrollbar.click == 1) {
			DrawGraph(scrollbar.x, scrollbar.y, img.scrollbar, TRUE);
		}
		else {
			//半透明でスクロールバーを描画
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 192);
			DrawGraph(scrollbar.x, scrollbar.y, img.scrollbar, TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
	}
	if (height_size * block_size > WINDOW_HEIGHT) {
		if (scrollbar2.click == 1) {
			DrawGraph(scrollbar2.x, scrollbar2.y, img.scrollbarV, TRUE);
		}
		else {
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 192);
			DrawGraph(scrollbar2.x, scrollbar2.y, img.scrollbarV, TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
	}

	DrawGraph(0, 500, img.cs_bg[0], TRUE);			//画面下の一番奥の背景

	//4つのメニューを選び、選択された内容のボタンが表示される
	for (int i = 1; i < 5; i++) {	//メニューの描画
		if (menu_b != i)	//選択されていないメニューを奥に持ってくる
			DrawGraph(0, 500, img.cs_bg[i], TRUE);
	}
	DrawGraph(0, 500, img.cs_bg[menu_b], TRUE);//選択されたメニューを一番手前に描画する
	DrawStringToHandle(59, 505, "敵", GetColor(0, 0, 0), Font[0]);
	DrawStringToHandle(167, 505, "ブロック", GetColor(0, 0, 0), Font[0]);
	DrawStringToHandle(318, 505, "その他", GetColor(0, 0, 0), Font[0]);
	DrawStringToHandle(442, 505, "ステータス", GetColor(0, 0, 0), Font[0]);

	//メニューの描画
	DrawCSMenu();
	
	//現在のファイルの位置を描画
	//DrawStringToHandle(32, 35, CurrentFile, GetColor(0, 0, 0), Font[0]);
	//DrawFormatStringToHandle(32, 30, red, Font[0], "c_move : %d", c_move);
	//DrawFormatStringToHandle(32, 70, red, Font[0], "mx2 : %d", mx2);

	ScreenFlip();
}
