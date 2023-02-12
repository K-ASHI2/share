#include"DxLib.h"
#include"extern.h"
#include"function.h"

//CPU対戦の動作のメニュー
void CMenuWindow::moveMenu()
{
	selectWindow();

	//キャンセル
	if (keyPad.getButton(KEY_CANCEL) == 1)
	{
		cursor = N_o_i - 1;	//カーソルを一番下にする
		music.efs(efs_back);
	}

	//決定
	if (keyPad.getButton(KEY_SHOT) == 1)
	{
		music.efs(efs_decision);
		
		//難易度を選んだ(キャンセル以外)の場合、その難易度を保存する
		if (cursor != N_o_i - 1)
		{
			lastSelectedCPUMode = cursor;
		}

		switch (cursor)
		{
		case 0:
			player2.setCpuMove(ec_search);
			changeFlag(e_start);
			player2.setThinkingTime(40);
			break;
		case 1:
			player2.setCpuMove(ec_search);
			changeFlag(e_start);
			player2.setThinkingTime(25);
			break;
		case 2:
			player2.setCpuMove(ec_search);
			changeFlag(e_start);
			player2.setThinkingTime(10);
			break;
		case 3:
			player2.setCpuMove(ec_search);
			changeFlag(e_start);
			player2.setThinkingTime(0);
			break;
		case 4:	changeFlag(e_title); break;
		}
	}
}

//タイトル画面の描画
void CMenuWindow::drawMoveMenu()
{
	const static int green = font.getGreen();
	const static int font0 = font.getFont(0);
	DrawGraph(0, 0, img.title, TRUE);
	drawRed(100, 100, "LEVEL 1", 0);
	drawRed(100, 150, "LEVEL 2", 1);
	drawRed(100, 200, "LEVEL 3", 2);
	drawRed(100, 250, "LEVEL 4", 3);
	drawRed(100, 300, "BACK", 4);

	//選択中の項目に関する説明
	switch (cursor) {
	case 0:
	case 1:
	case 2:
	case 3:	DrawString(100, 550, "難易度を選んでください", green); break;
	case 4: DrawString(100, 550, "タイトル画面に戻ります", green); break;
	}
}
