#include"DxLib.h"
#include"extern.h"
#include"function.h"
#include"math.h"

//リザルト画面
void CMenuWindow::clear()
{	
	//決定ボタンが押されたらタイトル画面に戻る
	if ((keyPad.getButton(KEY_SHOT) == 1 || keyPad.getButton(KEY_PAUSE) == 1) && clear_count > 120)
	{
		changeFlag(e_title);
		music.efs(efs_decision);
	}
}

//スコアアタックモードのリザルト画面の描画
void CMenuWindow::drawClear()
{
	const static int black = font.getBlack();
	const static int red = font.getRed();
	const static int font0 = font.getFont(0);

	SetDrawBright(128, 128, 128);
	drawBackGround(player1);	//背景の描画
	drawPlay();		//ゲームプレイ中の描画
	SetDrawBright(255, 255, 255);

	DrawGraph(200, 150, img.clear_frame, FALSE);	//なぜかTRUEだと透過される
	DrawString(357, 180, "RESULT", black);

	//点数の座標を中央に合わせる
	if (clear_count > 60)
	{
		if (player1.getScore() < 10)
		{
			DrawFormatString(296, 230, black, "%7d", player1.getScore());
		}
		else if (player1.getScore() < 100)
		{
			DrawFormatString(311, 230, black, "%7d", player1.getScore());
		}
		else if (player1.getScore() < 1000)
		{
			DrawFormatString(321, 230, black, "%7d", player1.getScore());
		}
		else if (player1.getScore() < 10000)
		{
			DrawFormatString(331, 230, black, "%7d", player1.getScore());
		}
		else
		{
			DrawFormatString(341, 230, black, "%7d", player1.getScore());
		}
	}

	if (clear_count > 120 && clear_count % 60 < 40)
	{
		if (hiscore_flag)
		{
			DrawStringToHandle(337, 290, "NEW RECORD!", red, font0);
		}
		else
		{
			DrawStringToHandle(335, 290, "PUSH BUTTON", red, font0);
		}
	}

	clear_count++;
	//オーバーフロー防止
	if (clear_count == 180)
	{
		clear_count = 120;
	}
}

//リザルト画面
void CMenuWindow::win()
{

	//連続で対戦できるようにした方がよさそう


	//決定ボタンが押されたらタイトル画面に戻る
	if ((keyPad.getButton(KEY_SHOT) == 1) && clear_count > 60)
	{
		changeFlag(e_start);
		init();
		music.efs(efs_decision);
	}
	//キャンセルかポーズボタンが押されたらタイトル画面に戻る
	else if ((keyPad.getButton(KEY_CANCEL) == 1 || keyPad.getButton(KEY_PAUSE) == 1) && clear_count > 60)
	{
		changeFlag(e_title);
		music.efs(efs_decision);
	}

	clear_count++;
	//オーバーフロー防止
	/*if (clear_count == 120)
	{
		clear_count = 60;
	}*/
}

//スコアアタックモードのリザルト画面の描画
void CMenuWindow::drawWin()
{
	const static int black = font.getBlack();
	const static int red = font.getRed();
	const static int font0 = font.getFont(0);

	SetDrawBright(128, 128, 128);
	drawBackGround(player1);	//背景の描画
	drawPlay();		//ゲームプレイ中の描画
	SetDrawBright(255, 255, 255);

	DrawGraph(200, 150, img.win_frame, FALSE);	//なぜかTRUEだと透過される
	//DrawString(357, 180, "RESULT", black);

	if (player1.getGameover())
	{
		DrawString(357, 200, "2P WIN", black);
	}
	else
	{
		DrawString(357, 200, "1P WIN", black);
	}

	if (clear_count > 60 && clear_count % 60 < 40)
	{
		DrawStringToHandle(268, 250, "PUSH SHOT BUTTUN : RETRY", red, font0);
		DrawStringToHandle(273, 280, "PUSH DROP BUTTUN : END", red, font0);
	}
}
