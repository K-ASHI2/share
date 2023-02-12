#include"DxLib.h"
#include"extern.h"
#include"function.h"

void Pause() {

	SelectWindow(1);
	if (button[KEY_BOMB] == 1 || button[KEY_PAUSE] == 1) {
		ChangeFlag(e_gameplay);
		PlaybackFlag = 1;
		efs(efs_back);
	}
	if (button[KEY_SHOT] == 1) {
		efs(efs_decision);
		switch (cursor) {
		case 0:
			ChangeFlag(e_gameplay);
			//ポーズ画面からリトライ以外で戻ってくる場合
			//フェードイン後に音楽を途中から再生するフラグを1にする
			PlaybackFlag = 1;
			break;
		case 1:
			//最初からにする チャプターを最初に戻す
			ChangeFlag(e_gameplay);
			init();
			//ポーズ画面からリトライで戻ってくる場合
			//フェードイン後に音楽を最初から再生するフラグを1にする
			PlaybackFlag = 2;
			break;
		case 2: 
			ChangeFlag(e_title);
			break;
		}
	}
}

//ポーズ画面の描画
void DrawPause() {

	SetDrawBright(128, 128, 128);
	DrawBackGround();	//背景の描画
	DrawPlay();		//ゲームプレイ中の描画
	SetDrawBright(255, 255, 255);

	//DrawGraph(200, 150, img.pause_frame, FALSE);
	DrawColor(307, 180, "COUTINUE", 0, black, white);
	DrawColor(337, 230, "RETRY", 1, black, white);
	DrawColor(337, 280, "TITLE", 2, black, white);
	//DrawGraph(60, 98 + cursor * 80, img.arrow, TRUE);    //矢印の描画
}
