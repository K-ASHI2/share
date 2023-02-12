#include"DxLib.h"
#include"extern.h"
#include"function.h"

//ˆêlƒvƒŒƒC‚ÌƒQ[ƒ€ŠJŽn‘O
void CMenuWindow::start()
{
	/*if (player2.getCpuMove() != ec_player)
	{
		if (keyPad.getButton(KEY_SHOT) == 1)
		{
			changeFlag(e_gameplay);
		}
	}*/

	if (keyPad.getButton(KEY_SHOT) == 1)
	{
		stageStartFlag = true;
	}
	if (stageStartFlag)
	{
		stageStartCount--;
		if (stageStartCount == 0)
		{
			changeFlag(e_gameplay);
		}
	}
}

//ƒQ[ƒ€ŠJŽn‘O‚Ì‰æ–Ê‚Ì•`‰æ
void CMenuWindow::drawStart()
{
	const static int liteGreen = font.getLiteGreen();
	const static int font1 = font.getFont(1);
	const static int font7 = font.getFont(7);
	SetDrawBright(128, 128, 128);
	drawBackGround(player1);	//”wŒi‚Ì•`‰æ
	drawPlay();		//ƒQ[ƒ€ƒvƒŒƒC’†‚Ì•`‰æ
	SetDrawBright(255, 255, 255);

	if (!stageStartFlag)
	{
		DrawFormatStringToHandle(175, 200, liteGreen, font1, "PUSH DRAW BUTTUN");
	}
	else
	{
		if ((stageStartCount + 25) / 50 > 0)
		{
			DrawFormatStringToHandle(365, 200, liteGreen, font7, "%d", (stageStartCount + 25) / 50);
		}
		else {
			DrawFormatStringToHandle(330, 200, liteGreen, font7, "GO!");
		}
	}
}
