#pragma once
#include"DxLib.h"
#include"extern.h"
#include"function.h"

//描画の関数
void draw() {

	//画面クリア
	ClearDrawScreen();

	switch (flag) {
	case e_title:	//タイトル画面
		drawTitle();
		break;

	case e_clear:	//クリア画面
		
		//最後のステージをクリアすると別の画像を表示する
		if (mapload % 1000 == 441) {
			DrawGraph(0, 0, img.allclear, TRUE);
		}
		else {
			DrawGraph(0, 0, img.clear, TRUE);
		}		break;

	case e_gameplay:	//ゲームプレイ画面
		draw_background();
		drawPlay();
		break;

	case e_gameover:	//ゲームオーバー画面
		DrawGraph(0, 0, img.gameover, TRUE);
		break;

	case e_stage_select:	//ステージ選択画面
		drawStageSelect();
		break;

	case e_difficulty_select:	//難易度選択画面
		drawDifficultySelect();
		break;

	case e_pause:	//ポーズ画面
		drawPause();
		break;

		//case e_option:
		//	DrawGraph(0, 0, img.title, TRUE);			//タイトル画面を描画
		//	DrawString(100, 100, "SOUND vol", black);	//音量設定
		//	DrawString(100, 180, "OPERATING", black);	//操作説明
		//	DrawString(100, 260, "DEFAULT", black);
		//	DrawString(100, 340, "RETURN", black);
		//	DrawGraph(60, 98 + cursor * 80, img.arrow, TRUE);	//矢印の描画
		//	break;

		//case e_keyconfig:
		//	DrawGraph(0, 0, img.title, TRUE);
		//	//上下左右は変更する必要はない
		//	DrawString(100, 100, "SHOT", black);
		//	DrawString(100, 170, "BOMB", black);
		//	DrawString(100, 240, "SLOW", black);
		//	DrawString(100, 310, "PAUSE", black);
		//	DrawString(100, 380, "RESET", black);
		//	DrawString(100, 450, "QUIT", black);
		//	for (int i = 4; i < 8; i++) {//4～7のボタンが変更できるボタン
		//		char *p = NULL;
		//		switch (key_p[i]) {
		//		case PAD_A:		p = "PAD_A";			break;
		//		case PAD_B:		p = "PAD_B";			break;
		//		case PAD_X:		p = "PAD_X";			break;
		//		case PAD_Y:		p = "PAD_Y";			break;
		//		case PAD_LB:	p = "PAD_LB";			break;
		//		case PAD_RB:	p = "PAD_RB";			break;
		//		case PAD_BACK:	p = "PAD_BACK";			break;
		//		case PAD_START: p = "PAD_START";		break;
		//		default:		p = "使用できません";	break;
		//		}
		//		DrawString(400, 100 + (i - 4) * 70, p, black);
		//	}
		//	DrawGraph(60, 98 + cursor * 70, img.arrow, TRUE);    //矢印の描画
		//	break;

		//case soundtest:
		//	DrawGraph(0, 0, img.title, TRUE);
		//	DrawString(100, 100, "COUTINUE", black);
		//	DrawString(100, 180, "RETRY", black);
		//	DrawString(100, 260, "TITLE", black);
		//	DrawGraph(60, 98 + cursor * 80, img.arrow, TRUE);    //矢印の描画
		//	break;   //ポーズ画面
		//}
		//draw_ex();//操作説明の表示
	}
	ScreenFlip();
}

//指定した時間だけ画面が切り替わる時に真っ暗にする
void black_screen(int t) {
	ClearDrawScreen();
	ScreenFlip();
	WaitTimer(t);
}
