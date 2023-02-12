#include"DxLib.h"
#include"extern.h"
#include"function.h"

void update()
{
	switch(menuWindow.getFlag())
	{
		case e_title:
			menuWindow.title();
			break;

		case e_movemenu:
			menuWindow.moveMenu();
			break;

		case e_operationmenu:
			menuWindow.operationMenu();
			break;

		case e_start:
			menuWindow.start();
			break;

		case e_gameplay:
			if (mode_flag == em_score_attack)
			{
				player1.update();
			}
			else if (mode_flag == em_vs)
			{
				//少しずつ落下の間隔を早くしていく
				//数値については色々試すほうがよさそう
				const int MAXLEVEL = 99;
				//const int INTERVAL = 600;
				//const int MAXTIME = (MAXLEVEL - 1) * INTERVAL;
				//if (timeCount < MAXTIME)
				//{
				//	timeCount++;
				//	if (timeCount % INTERVAL == 0)
				//	{
				//		if (player1.getLevel() < MAXLEVEL)
				//		{
				//			player1.incrementLevel();
				//			player1.subDropInterval(1);
				//		}
				//		if (player2.getLevel() < MAXLEVEL)
				//		{
				//			player2.incrementLevel();
				//			player2.subDropInterval(1);
				//		}
				//	}
				//}

				//スコアで一定毎にレベルがあがる
				if (player1.getLevel() < MAXLEVEL)
				{
					//相手のスコアに応じてレベル上昇
					if (player2.getScore() > player1.getLevel() * 10000)
					{
						player1.incrementLevel();
						if (player1.getLevel() < 50)
						{
							player1.subDropInterval(2);
						}
						else
						{
							player1.subDropInterval(1);
						}
					}
				}
				if (player2.getLevel() < MAXLEVEL)
				{
					if (player1.getScore() > player2.getLevel() * 10000)
					{
						player2.incrementLevel();
						if (player2.getLevel() < 50)
						{
							player2.subDropInterval(2);
						}
						else
						{
							player2.subDropInterval(1);
						}
					}
				}

				//vs専用のupdateを作ってもいいかも
				player1.update();
				player2.update();
			}
			break;

		case e_clear:
			menuWindow.clear();
			break;

		case e_win:
			menuWindow.win();
			break;

		case e_pause:
			menuWindow.pause();
			break;

		case e_keyconfig:
			menuWindow.keyConfig();
			break;

		case e_manual:
			menuWindow.manual();
			break;
	}
}
