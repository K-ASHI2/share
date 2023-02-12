#include"DxLib.h"
#include"extern.h"
#include"function.h"

void Option() {

	SelectWindow();
	if (button[KEY_BOMB] == 1) {//キャンセルが押されたらカーソルを一番下にする
		cursor = N_o_i - 1;
	}
	if (button[KEY_SHOT] == 1) {
		switch (cursor) {
		case 0:
			if (window_mode == 0) {
				ChangeWindowMode(FALSE);	//フルスクリーンモード
				window_mode = 1;
			}
			else {
				ChangeWindowMode(TRUE);		//ウィンドウモード
				window_mode = 0;
			}
			SetFont();	//フォントの設定
			Load();
			Sleep(1000);
			break;
		case 1: draw_ex = 1 - draw_ex; break;	//操作説明のオンオフ
		case 2: draw_ex = 1; break;	//初期設定に戻す(スクリーンモード以外)
		case 3: ChangeFlag(e_title, 2); break;	//タイトルに戻る
		}
	}
}

//オプションの描画
void DrawOption() {
	DrawGraph(0, 0, img.background_2, TRUE);		//タイトル画面を描画
													//DrawRed(100, 100, "SOUND vol", 0);	//音量設定
	DrawRed(100, 100, "SCREEN MODE", 0);	//ウィンドウモード
	if (window_mode == 1) {
		DrawRed(300, 100, "WINDOW", 0);
	}
	else {
		DrawRed(300, 100, "FULL SCREEN", 0);
	}
	DrawRed(100, 150, "OPERATING", 1);	//操作説明
	if (draw_ex == 1) {
		DrawRed(300, 150, "ON", 1);
	}
	else {
		DrawRed(300, 150, "OFF", 1);
	}
	DrawRed(100, 200, "DEFAULT", 2);
	DrawRed(100, 250, "EXIT", 3);
	//DrawGraph(60, 98 + cursor * 50, img.arrow, TRUE);    //矢印の描画
}
