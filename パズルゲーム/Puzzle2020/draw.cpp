#include"DxLib.h"
#include"extern.h"
#include"function.h"

void draw()
{
	ClearDrawScreen();  //画面に描画されているものを消す

	switch (menuWindow.getFlag())
	{
	case e_title:
		menuWindow.drawTitle();
		break;

	case e_movemenu:
		menuWindow.drawMoveMenu();
		break;

	case e_operationmenu:
		menuWindow.drawOperationMenu();
		break;

	case e_start:
		menuWindow.drawStart();
		break;

	case e_gameplay:
		drawPlay();
		break;

	case e_clear:
		menuWindow.drawClear();
		break;

	case e_win:
		menuWindow.drawWin();
		break;

	case e_pause:
		menuWindow.drawPause();
		break;

	case e_keyconfig:
		menuWindow.drawKeyConfig();
		break;

	case e_manual:
		menuWindow.drawManual();
		break;
	}
	keyPad.drawEx();//操作説明の表示
	ScreenFlip();
}
