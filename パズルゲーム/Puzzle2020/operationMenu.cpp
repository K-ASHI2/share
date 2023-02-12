#include"DxLib.h"
#include"extern.h"
#include"function.h"

//対人モードのコントローラ選択
void CMenuWindow::operationMenu()
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
			padInputMode = epad_pad_pad;
			changeFlag(e_start);
			break;
		case 1:
			padInputMode = epad_keyboard_pad;
			changeFlag(e_start);
			break;
		case 2: changeFlag(e_title); break;
		}
	}
}

//タイトル画面の描画
void CMenuWindow::drawOperationMenu()
{
	const static int green = font.getGreen();
	const static int font0 = font.getFont(0);
	DrawGraph(0, 0, img.title, TRUE);
	drawRed(100, 100, "1P GAME PAD & 2P GAME PAD", 0);
	drawRed(100, 150, "1P KEYBOARD & 2P GAME PAD", 1);
	drawRed(100, 200, "BACK", 2);


	//選択中の項目に関する説明
	switch (cursor) {
	case 0: DrawString(100, 550, "1Pも2Pもゲームパッドを使います", green); break;
	case 1: DrawString(100, 550, "1Pはキーボード、2Pはゲームパッドを使います", green); break;
	case 2: DrawString(100, 550, "タイトル画面に戻ります", green); break;
	}
}
