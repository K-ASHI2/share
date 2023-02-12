#include"DxLib.h"
#include"extern.h"
#include"function.h"
#include"block.h"

//ポーズ画面
void CMenuWindow::pause()
{
	selectWindow(1);
	if (keyPad.getButton(KEY_CANCEL) == 1 || keyPad.getButton(KEY_PAUSE) == 1)
	{
		changeFlag(e_gameplay);
		PlaybackFlag = 1;
		music.efs(efs_back);
	}

	if (keyPad.getButton(KEY_SHOT) == 1)
	{
		music.efs(efs_decision);
		switch (cursor)
		{
		case 0:
			changeFlag(e_gameplay);
			//ポーズ画面からリトライ以外で戻ってくる場合
			//フェードイン後に音楽を途中から再生するフラグを1にする
			PlaybackFlag = 1;
			break;
		case 1:
			//同じ曲が選ばれても問題ないように止めた曲を最初からの再生状態にする
			PlaySoundMem(music.getPlayingMusic(), DX_PLAYTYPE_LOOP, TRUE);

			//最初からにする
			changeFlag(e_start);
			init();
			break;
		case 2: 
			changeFlag(e_title);
			break;
		}
	}
}

//ポーズ画面の描画
void CMenuWindow::drawPause()
{
	SetDrawBright(96, 96, 96);
	drawPlay();		//ゲームプレイ中の描画
	SetDrawBright(255, 255, 255);

	const static int silver = font.getSilver();
	const static int litegreen = font.getLiteGreen();
	drawColor(307, 180, "COUTINUE", 0, silver, litegreen);
	drawColor(337, 230, "RETRY", 1, silver, litegreen);
	drawColor(337, 280, "TITLE", 2, silver, litegreen);
}
