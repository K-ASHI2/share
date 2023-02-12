#include"DxLib.h"
#include"extern.h"
#include"function.h"

//サウンドテスト
void SoundTest() {

	SelectWindow();	//縦カーソルの移動
	SelectWindow_LR();	//横カーソルの移動
	
	if (button[KEY_BOMB] == 1) {
		cursor = N_o_i - 1;//カーソルを一番下にする
		efs(efs_back);
	}
	//何もない位置にカーソルを合わせる場合、左にずらす
	if (cursor_LR == 1 && (cursor == 0 || cursor == 6)) {
		cursor_LR = 0;
	}
	if (button[KEY_SHOT] == 1) {//決定
		switch (cursor_LR) {
		case 0: 
			switch (cursor) {
			case 0: stage = es_title; break;
			case 1: stage = es_1_1; break;
			case 2: stage = es_2_1; break;
			case 3: stage = es_3_1; break;
			case 4: stage = es_4_1; break;
			case 5: stage = es_e_1; break;
			case 6: ChangeFlag(e_title); efs(efs_back); break;
			}
			break;
		case 1:
			switch (cursor) {
			case 1: stage = es_1_2; break;
			case 2: stage = es_2_2; break;
			case 3: stage = es_3_2; break;
			case 4: stage = es_4_2; break;
			case 5: stage = es_e_2; break;
			}
			break;
		}
		StageMusic();
	}
}

//サウンドテストの描画
void DrawSoundTest() {
	static int x1 = 100, x2 = 250;
	static int y1 = 100, y2 = 150, y3 = 200, y4 = 250, y5 = 300, y6 = 350, y7 = 400;
	DrawGraph(0, 0, img.background_2, TRUE);
	DrawRed2(x1, y1, "TITLE", 0, 0);
	DrawRed2(x1, y2, "1-1", 1, 0);
	DrawRed2(x2, y2, "1-2", 1, 1);
	DrawRed2(x1, y3, "2-1", 2, 0);
	DrawRed2(x2, y3, "2-2", 2, 1);
	DrawRed2(x1, y4, "3-1", 3, 0);
	DrawRed2(x2, y4, "3-2", 3, 1);
	DrawRed2(x1, y5, "4-1", 4, 0);
	DrawRed2(x2, y5, "4-2", 4, 1);
	DrawRed2(x1, y6, "e-1", 5, 0);
	DrawRed2(x2, y6, "e-2", 5, 1);
	DrawRed2(x1, y7, "EXIT", 6, 0);
	DrawGraph(60 + cursor_LR * 150, 98 + cursor * 50, img.arrow, TRUE);    //矢印の描画
}
