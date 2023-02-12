#include"DxLib.h"
#include"extern.h"
#include"function.h"
#include"math.h"

void drawPlayWindow()
{
	const static int black = font.getBlack();
	const static int font0 = font.getFont(0);
	const static int font2 = font.getFont(2);

	//ゲームプレイ中の画面外の描画
	DrawGraph(0, 0, img.frame, TRUE);       //画面の一番上から落下するように見せるための外枠の描画

	//NEXTの描画
	drawNext();

	//難易度の表示
	const static int color = font.getWhite();	//難易度の色

	//ハイスコア
	DrawStringToHandle(535, 50, "HISCORE", black, font0);
	//10桁のスコアを一けたずつ計算して表示する
	for (int i = 0; i < 10; i++)
	{
		int s = hiscore % (int)pow(10.0, (double)(i + 1));
		if (i > 0)
		{
			s /= (int)pow(10.0, (double)i);
		}
		DrawFormatStringToHandle(750 - 12 * i, 50, black, font0, "%d", s);
	}

	//スコア
	DrawStringToHandle(535, 80, "SCORE", black, font0);

	//オーバーフロー対策
	if (player1.getScore() > 10000000000)
	{
		player1.setScore(9999999999);
	}
	//10桁のスコアを一けたずつ計算して表示する
	for (int i = 0; i < 10; i++)
	{
		long long s = player1.getScore() % (long long)pow(10.0, (double)(i + 1));
		if (i > 0)
		{
			s /= (int)pow(10.0, (double)i);
		}
		DrawFormatStringToHandle(750 - 12 * i, 80, black,font0, "%d", s);
	}

	DrawStringToHandle(335, 110, "TIME", black, font2);
	if (timelimit / 120 >= 10)
	{
		DrawFormatStringToHandle(350, 150, black, font2, "%d", timelimit / 60);
	}
	else
	{
		DrawFormatStringToHandle(356, 150, black, font2, "%d", timelimit / 60);
	}

	//コンボの描画
	DrawStringToHandle(335, 190, "COMBO", black, font2);
	drawCombo(344, 230, player1);

	//HPバーの描画
	drawComboCountBar();

	//デバッグ用の数値
	//DrawFormatString(580, 330, black, "block[i][j].y : %3d", player1.getBlock(player1.getX(), player1.getY()).getY());
	//DrawFormatString(580, 360, black, "x  : %3d", player1.getX());
	//DrawFormatString(580, 390, black, "y  : %3d", player1.getY());
	//DrawFormatString(580, 420, black, "color : %3d", player1.getBlock(player1.getX(), player1.getY()).getColor());
	//DrawFormatString(580, 450, black, "vanish : %3d", player1.shotVanishCheck(player1.getX(), player1.getY()));
}

void drawVsWindow()
{
	const static int black = font.getBlack();
	const static int font2 = font.getFont(2);
	const static int font5 = font.getFont(5);

	//ゲームプレイ中の画面外の描画

	//対戦モードは画面の枠より上から落ちた方が見やすいからいらない
	//DrawGraph(0, 0, img.frame, TRUE);

	//レベルの表示
	DrawStringToHandle(355, 80, "LEVEL", black, font2);
	drawLevel(320, 120, player1);
	drawLevel(425, 120, player2);
	
	//コンボ数とコンボバーの描画
	//drawComboCountBarVS();

	//連鎖数の描画
	/*DrawStringToHandle(355, 180, "CHAIN", black, font2);
	drawChain(320, 220, player1);
	drawChain(425, 220, player2);*/

	//スコア
	DrawStringToHandle(305, 550, "1P SCORE", black, font5);
	DrawStringToHandle(410, 550, "2P SCORE", black, font5);

	//オーバーフロー対策
	if (player1.getScore() > 100000000)
	{
		player1.setScore(99999999);
	}
	//8桁のスコアを一けたずつ計算して表示する
	for (int i = 0; i < 8; i++)
	{
		long long s = player1.getScore() % (long long)pow(10.0, (double)(i + 1));
		if (i > 0)
		{
			s /= (int)pow(10.0, (double)i);
		}
		DrawFormatStringToHandle(376 - 10 * i,570, black, font5, "%d", s);
	}

	if (player2.getScore() > 100000000)
	{
		player2.setScore(99999999);
	}
	//8桁のスコアを一けたずつ計算して表示する
	for (int i = 0; i < 8; i++)
	{
		long long s = player2.getScore() % (long long)pow(10.0, (double)(i + 1));
		if (i > 0)
		{
			s /= (int)pow(10.0, (double)i);
		}
		DrawFormatStringToHandle(481 - 10 * i, 570, black, font5, "%d", s);
	}

	//NEXTの描画
	drawNext();

	//デバッグ用の数値
	//DrawFormatString(580, 330, black, "block[i][j].y : %3d", player1.getBlock(player1.getX(), player1.getY()).getY());
	//(580, 360, black, "x  : %3d", player1.getX());
	//DrawFormatString(580, 390, black, "y  : %3d", player1.getY());
	//DrawFormatString(580, 420, black, "color : %3d", player1.getBlock(player1.getX(), player1.getY()).getColor());
	//DrawFormatString(580, 450, black, "vanish : %3d", player1.shotVanishCheck(player1.getX(), player1.getY()));
}

//コンボ数の描画
void drawCombo(int x, int y, CPlayer player)
{
	const static int black = font.getBlack();
	const static int font2 = font.getFont(2);

	if (player.getCombo() >= 100)
	{
		DrawFormatStringToHandle(x, y, black, font2, "%d", player.getCombo());
	}
	else if (player.getCombo() >= 10)
	{
		DrawFormatStringToHandle(x + 6, y, black, font2, "%d", player.getCombo());
	}
	else
	{
		DrawFormatStringToHandle(x + 12, y, black, font2, "%d", player.getCombo());
	}

}

//連鎖数の描画
//void drawChain(int x, int y, CPlayer player)
//{
//	const static int black = font.getBlack();
//	const static int font2 = font.getFont(2);
//
//	if (player.getChainCount() >= 100)
//	{
//		DrawFormatStringToHandle(x, y, black, font2, "%d", player.getCombo());
//	}
//	else if (player.getCombo() >= 10)
//	{
//		DrawFormatStringToHandle(x + 6, y, black, font2, "%d", player.getCombo());
//	}
//	else
//	{
//		DrawFormatStringToHandle(x + 12, y, black, font2, "%d", player.getCombo());
//	}
//
//}


//レベルの描画
void drawLevel(int x, int y, CPlayer player)
{
	const static int black = font.getBlack();
	const static int font2 = font.getFont(2);

	if (player.getLevel() >= 100)
	{
		DrawFormatStringToHandle(x, y, black, font2, "%d", player.getLevel());
	}
	else if (player.getLevel() >= 10)
	{
		DrawFormatStringToHandle(x + 6, y, black, font2, "%d", player.getLevel());
	}
	else
	{
		DrawFormatStringToHandle(x + 12, y, black, font2, "%d", player.getLevel());
	}

}

//コンボ数の描画
void drawVsCombo(int x, int y, CPlayer player)
{
	const static int black = font.getBlack();
	const static int font0 = font.getFont(0);

	if (player.getCombo() >= 100)
	{
		DrawFormatStringToHandle(x, y, black, font0, "%d", player.getCombo());
	}
	else if (player.getCombo() >= 10)
	{
		DrawFormatStringToHandle(x + 6, y, black, font0, "%d", player.getCombo());
	}
	else
	{
		DrawFormatStringToHandle(x + 12, y, black, font0, "%d", player.getCombo());
	}

}

//NEXTの描画
void drawNext()
{
	const static int black = font.getBlack();
	const static int font0 = font.getFont(0);

	//後でNEXTがずれる時に落下して移動するエフェクトをつける

	if (mode_flag == em_score_attack)
	{
		const static int x1 = 325, y1 = 442;
		DrawGraph(x1, y1, img.nextFrame2, TRUE);
		DrawGraph(x1 + 15, y1 - 15, getBlockImg(player1.getNextBlock(2).getColor()), TRUE);
		DrawGraph(x1 + 15, y1 + 37, getBlockImg(player1.getNextBlock(1).getColor()), TRUE);
		DrawGraph(x1 - 5, y1 - 45, img.nextFrame1, TRUE);
		DrawStringToHandle(340, 410, "NEXT", black, font0);
	}
	else if(mode_flag == em_vs)
	{
		const static int x1 = 307, y1 = 410;
		DrawGraph(x1, y1, img.nextFrame2, TRUE);
		DrawGraph(x1 + 15, y1 - 15, getBlockImg(player1.getNextBlock(2).getColor()), TRUE);
		DrawGraph(x1 + 15, y1 + 37, getBlockImg(player1.getNextBlock(1).getColor()), TRUE);
		DrawGraph(x1 - 5, y1 - 45, img.nextFrame1, TRUE);
		DrawStringToHandle(320, 379, "NEXT", black, font0);
		 
		const static int x2 = 418, y2 = 410;
		DrawGraph(x2, y2, img.nextFrame2, TRUE);
		DrawGraph(x2 + 15, y2 - 15, getBlockImg(player1.getNextBlock(2).getColor()), TRUE);
		DrawGraph(x2 + 15, y2 + 37, getBlockImg(player2.getNextBlock(1).getColor()), TRUE);
		DrawGraph(x2 - 5, y2 - 45, img.nextFrame1, TRUE);
		DrawStringToHandle(431, 379, "NEXT", black, font0);
	}
	//DrawFormatString(580, 420, black, "nextcolor0 : %3d", player.getNextBlock(1).getColor(0));
}

//コンボ時間のバーの描画
void drawComboCountBar()
{
	const static int black = font.getBlack();
	const static int font2 = font.getFont(2);
	const static int x = 328, y1 = 329, y2 = 359;	//ゲージのx座標、y座標
	const static int gf = 3;	//外枠の幅
	const static int gaugeX = 160, gaugeY = 20;	//ゲージの幅
	const static int gx = gaugeX - gf * 2, gy = gaugeY - gf * 2;	//ゲージの中身の幅

	//バーの詳細
	DrawStringToHandle(x, y1 - 50, "COMBO TIME", black, font2);

	//バーの中の背景
	const static int hx1 = x + gf, hy1 = y1 + gf, hx2 = x + gf + gx, hy2 = y1 + gf + gy;
	DrawBox(hx1, hy1, hx2, hy2, GetColor(144, 144, 144), TRUE);

	//ゲージの幅
	int hb =  gx * player1.getComboTime() / COMBO_TIME;

	//コンボ時間がある間はゲージが0にならないようにする
	if (hb == 0 && player1.getComboTime() > 0)
	{
		hb = 1;
	}

	//バーの残量に応じた色の出力
	DrawBox(hx1, hy1, hx1 + hb, hy2, GetHPColor(player1.getComboTime(), COMBO_TIME), TRUE);

	//バーの外枠の描画
	DrawTurnGraph(x, y1, img.HPbar, TRUE);
}

void drawComboCountBarVS()
{
	const static int black = font.getBlack();
	const static int font2 = font.getFont(2);

	//コンボ表示の枠(なくてもいいかも)
	//DrawGraph(296, 150, img.comboFrame, TRUE);

	DrawStringToHandle(355, 170, "COMBO", black, font2);
	//コンボ数は描画しない
	//コンボは時間内にコンボした数ではなく、ゲージが高い時に消すほど得点に高い補正をかける
	drawVsCombo(315, 170, player1);
	drawVsCombo(435, 170, player2);

	//バーの詳細
	//DrawStringToHandle(328, 179, "COMBO TIME", black, font2);
	const static int gaugeX = 40, gaugeY = 130;	//ゲージの幅
	const static int gf = 3;	//外枠の幅
	const static int gx = gaugeX - gf * 2, gy = gaugeY - gf * 2;	//ゲージの中身の幅

	{
		const static int x = 318, y1 = 219;	//ゲージのx座標、y座標

		//バーの中の背景
		const static int hx1 = x + gf, hy1 = y1 + gf, hx2 = x + gf + gx, hy2 = y1 + gf + gy;
		DrawBox(hx1, hy1, hx2, hy2, GetColor(144, 144, 144), TRUE);

		//ゲージを表示する
		int hb = gy * player1.getComboTime() / MAX_COMBO_TIME;

		//コンボ時間がある間はゲージが0にならないようにする
		if (hb == 0 && player1.getComboTime() > 0)
		{
			hb = 1;
		}

		//バーの残量に応じた色の出力
		DrawBox(hx1, hy2 - hb, hx2, hy2, GetHPColor(player1.getComboTime(), MAX_COMBO_TIME), TRUE);

		//バーの外枠の描画
		DrawGraph(x, y1, img.HPbar2, TRUE);
	}

	//2P側
	{
		const static int x = 438, y1 = 219;	//ゲージのx座標、y座標

		//バーの中の背景
		const static int hx1 = x + gf, hy1 = y1 + gf, hx2 = x + gf + gx, hy2 = y1 + gf + gy;
		DrawBox(hx1, hy1, hx2, hy2, GetColor(144, 144, 144), TRUE);

		//ゲージを表示する
		int hb = gy * player2.getComboTime() / MAX_COMBO_TIME;

		//コンボ時間がある間はゲージが0にならないようにする
		if (hb == 0 && player2.getComboTime() > 0)
		{
			hb = 1;
		}

		//バーの残量に応じた色の出力
		DrawBox(hx1, hy2 - hb, hx2, hy2, GetHPColor(player2.getComboTime(), MAX_COMBO_TIME), TRUE);

		//バーの外枠の描画
		DrawGraph(x, y1, img.HPbar2, TRUE);
	}
}

//バーの残量に応じた色を返す関数
int GetHPColor(int hp, int maxhp)
{
	int Red, Green, Blue;

	//0で割ることを回避
	if (maxhp == 0)
	{
		return 0;
	}
	//半分で区切るので変化量も半分となる
	//半分以上の時(緑→黄色)
	if (hp >= maxhp / 2)
	{
		Red = 355 - 243 * hp / maxhp;
		Green = 255;
		Blue = 112;
	}
	//半分未満の時(黄色→赤)
	else
	{
		Red = 255;
		Green = 510 * hp / maxhp;
		Blue = 224 * hp / maxhp;
	}
	return GetColor(Red, Green, Blue);
}
