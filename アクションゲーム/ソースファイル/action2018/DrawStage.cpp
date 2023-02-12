#include"DxLib.h"
#include"math.h"
#include"extern.h"
#include"function.h"	//共通の関数
#include"csExtern.h"	//ステージ作成のみに使用できる変数
#include"csFunction.h"	//ステージ作成のみに使用する関数

void drawStage() {

	//画面クリア
	ClearDrawScreen();

	//背景の描画
	draw_background();

	player.x = cx;	//
	draw_csmap();	//画面内のマップの描画

	DrawGraph(0, 480, img.bar1, TRUE);				//スクロールバーの枠の表示
	DrawGraph(2 + SbarX, 482, img.scrollbar, TRUE);	//スクロールバーの描画 横128 縦16
	DrawGraph(0, 500, img.cs_bg[0], TRUE);			//画面下の一番奥の背景

	//4つのメニューを選び、選択された内容のボタンが表示される
	for (int i = 1; i < 5; i++) {//メニューの描画
		if (menu_b != i)//選択されていないメニューを奥に持ってくる
			DrawGraph(0, 500, img.cs_bg[i], TRUE);
	}
	DrawGraph(0, 500, img.cs_bg[menu_b], TRUE);//選択されたメニューを一番手前に描画する
	DrawStringToHandle(59, 505, "敵", GetColor(0, 0, 0), Font[0]);
	DrawStringToHandle(167, 505, "ブロック", GetColor(0, 0, 0), Font[0]);
	DrawStringToHandle(318, 505, "その他", GetColor(0, 0, 0), Font[0]);
	DrawStringToHandle(442, 505, "ステータス", GetColor(0, 0, 0), Font[0]);

	//メニューの描画
	drawCSMenu();
	
	ScreenFlip();
}
