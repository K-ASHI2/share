#include"DxLib.h"
#include"extern.h"
#include"function.h"

//弾幕プラクティス
void BurragePractice() {

	enum e_BurragePrsctice {
		ebp_WorldSelect,
		ebp_BurrageSelect1,
		ebp_BurrageSelect2,
		ebp_BurrageSelect3,
		ebp_BurrageSelect4,
		ebp_BurrageSelectE,
		ebp_DifficultySelect,
	};

	enum e_BurragePrsctice mode = ebp_WorldSelect;

	SelectWindow();	//縦カーソルの移動

	switch (mode) {
	case ebp_WorldSelect:
		if (button[KEY_BOMB] == 1) {
			ChangeFlag(e_title);
		}
		if (button[KEY_SHOT] == 1) {//決定
			efs(efs_decision);
			world = ew_2;
			cancel_cursor = cursor;
			switch (cursor) {
			case 0:
				boss.mode_p = 1;
				break;
			case 1:
				boss.mode_p = 2;
				break;
			case 2:
				boss.mode_p = 3;
				break;
			case 3:
				boss.mode_p = 4;
				break;
			case 4:
				boss.mode_p = 5;
				break;
			case 5:
				boss.mode_p = 6;
				break;
			case 6:
				boss.mode_p = 7;
				break;
			case 7:
				boss.mode_p = 8;
				break;
			case 8:
				boss.mode_p = 9;
				break;
			}
			ChangeFlag(e_characterselect);
			//mode = ebp_BurrageSelect1;
		}
	//case ebp_BurrageSelect1:
	//	if (button[KEY_BOMB] == 1) {
	//		mode = ebp_WorldSelect;
	//	}
	//	if (button[KEY_SHOT] == 1) {//決定
	//								//efm(5);//決定の効果音
	//		switch (cursor) {
	//		case 0:	//道中1
	//			//burrage = 1;
	//			break;
	//		case 1:	//中ボス通常1
	//			world = ew_2;
	//			break;
	//		case 2:	//3面
	//			world = ew_3;
	//			break;
	//		case 3:	//4面
	//			world = ew_4;
	//			break;
	//		case 4:	//EXTRA
	//			world = ew_extra;
	//			break;
	//		}
	//		ChangeFlag(e_characterselect);
	//	}
	}
}

//弾幕プラクティスの描画
void DrawBulletPractice() {

	DrawGraph(0, 0, img.background_2, TRUE);
	DrawRed(100, 100, "BURRAGE1", 0);
	DrawRed(100, 150, "BURRAGE2", 1);
	DrawRed(100, 200, "BURRAGE3", 2);
	DrawRed(100, 250, "BURRAGE4", 3);
	DrawRed(100, 300, "BURRAGE5", 4);
	DrawRed(100, 350, "BURRAGE6", 5);
	DrawRed(100, 400, "BURRAGE7", 6);
	DrawRed(100, 450, "BURRAGE8", 7);
	DrawRed(100, 500, "BURRAGE9", 8);
	//DrawGraph(60, 98 + cursor * 50, img.arrow, TRUE);    //矢印の描画
}
