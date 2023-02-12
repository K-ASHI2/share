#include"DxLib.h"
#include"extern.h"
#include"function.h"
#include"math.h"

void drawPlayWindow()
{
	const static int black = font.getBlack();
	const static int font0 = font.getFont(0);
	const static int font2 = font.getFont(2);

	//�Q�[���v���C���̉�ʊO�̕`��
	DrawGraph(0, 0, img.frame, TRUE);       //��ʂ̈�ԏォ�痎������悤�Ɍ����邽�߂̊O�g�̕`��

	//NEXT�̕`��
	drawNext();

	//��Փx�̕\��
	const static int color = font.getWhite();	//��Փx�̐F

	//�n�C�X�R�A
	DrawStringToHandle(535, 50, "HISCORE", black, font0);
	//10���̃X�R�A���ꂯ�����v�Z���ĕ\������
	for (int i = 0; i < 10; i++)
	{
		int s = hiscore % (int)pow(10.0, (double)(i + 1));
		if (i > 0)
		{
			s /= (int)pow(10.0, (double)i);
		}
		DrawFormatStringToHandle(750 - 12 * i, 50, black, font0, "%d", s);
	}

	//�X�R�A
	DrawStringToHandle(535, 80, "SCORE", black, font0);

	//�I�[�o�[�t���[�΍�
	if (player1.getScore() > 10000000000)
	{
		player1.setScore(9999999999);
	}
	//10���̃X�R�A���ꂯ�����v�Z���ĕ\������
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

	//�R���{�̕`��
	DrawStringToHandle(335, 190, "COMBO", black, font2);
	drawCombo(344, 230, player1);

	//HP�o�[�̕`��
	drawComboCountBar();

	//�f�o�b�O�p�̐��l
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

	//�Q�[���v���C���̉�ʊO�̕`��

	//�ΐ탂�[�h�͉�ʂ̘g���ォ�痎�����������₷�����炢��Ȃ�
	//DrawGraph(0, 0, img.frame, TRUE);

	//���x���̕\��
	DrawStringToHandle(355, 80, "LEVEL", black, font2);
	drawLevel(320, 120, player1);
	drawLevel(425, 120, player2);
	
	//�R���{���ƃR���{�o�[�̕`��
	//drawComboCountBarVS();

	//�A�����̕`��
	/*DrawStringToHandle(355, 180, "CHAIN", black, font2);
	drawChain(320, 220, player1);
	drawChain(425, 220, player2);*/

	//�X�R�A
	DrawStringToHandle(305, 550, "1P SCORE", black, font5);
	DrawStringToHandle(410, 550, "2P SCORE", black, font5);

	//�I�[�o�[�t���[�΍�
	if (player1.getScore() > 100000000)
	{
		player1.setScore(99999999);
	}
	//8���̃X�R�A���ꂯ�����v�Z���ĕ\������
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
	//8���̃X�R�A���ꂯ�����v�Z���ĕ\������
	for (int i = 0; i < 8; i++)
	{
		long long s = player2.getScore() % (long long)pow(10.0, (double)(i + 1));
		if (i > 0)
		{
			s /= (int)pow(10.0, (double)i);
		}
		DrawFormatStringToHandle(481 - 10 * i, 570, black, font5, "%d", s);
	}

	//NEXT�̕`��
	drawNext();

	//�f�o�b�O�p�̐��l
	//DrawFormatString(580, 330, black, "block[i][j].y : %3d", player1.getBlock(player1.getX(), player1.getY()).getY());
	//(580, 360, black, "x  : %3d", player1.getX());
	//DrawFormatString(580, 390, black, "y  : %3d", player1.getY());
	//DrawFormatString(580, 420, black, "color : %3d", player1.getBlock(player1.getX(), player1.getY()).getColor());
	//DrawFormatString(580, 450, black, "vanish : %3d", player1.shotVanishCheck(player1.getX(), player1.getY()));
}

//�R���{���̕`��
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

//�A�����̕`��
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


//���x���̕`��
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

//�R���{���̕`��
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

//NEXT�̕`��
void drawNext()
{
	const static int black = font.getBlack();
	const static int font0 = font.getFont(0);

	//���NEXT������鎞�ɗ������Ĉړ�����G�t�F�N�g������

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

//�R���{���Ԃ̃o�[�̕`��
void drawComboCountBar()
{
	const static int black = font.getBlack();
	const static int font2 = font.getFont(2);
	const static int x = 328, y1 = 329, y2 = 359;	//�Q�[�W��x���W�Ay���W
	const static int gf = 3;	//�O�g�̕�
	const static int gaugeX = 160, gaugeY = 20;	//�Q�[�W�̕�
	const static int gx = gaugeX - gf * 2, gy = gaugeY - gf * 2;	//�Q�[�W�̒��g�̕�

	//�o�[�̏ڍ�
	DrawStringToHandle(x, y1 - 50, "COMBO TIME", black, font2);

	//�o�[�̒��̔w�i
	const static int hx1 = x + gf, hy1 = y1 + gf, hx2 = x + gf + gx, hy2 = y1 + gf + gy;
	DrawBox(hx1, hy1, hx2, hy2, GetColor(144, 144, 144), TRUE);

	//�Q�[�W�̕�
	int hb =  gx * player1.getComboTime() / COMBO_TIME;

	//�R���{���Ԃ�����Ԃ̓Q�[�W��0�ɂȂ�Ȃ��悤�ɂ���
	if (hb == 0 && player1.getComboTime() > 0)
	{
		hb = 1;
	}

	//�o�[�̎c�ʂɉ������F�̏o��
	DrawBox(hx1, hy1, hx1 + hb, hy2, GetHPColor(player1.getComboTime(), COMBO_TIME), TRUE);

	//�o�[�̊O�g�̕`��
	DrawTurnGraph(x, y1, img.HPbar, TRUE);
}

void drawComboCountBarVS()
{
	const static int black = font.getBlack();
	const static int font2 = font.getFont(2);

	//�R���{�\���̘g(�Ȃ��Ă���������)
	//DrawGraph(296, 150, img.comboFrame, TRUE);

	DrawStringToHandle(355, 170, "COMBO", black, font2);
	//�R���{���͕`�悵�Ȃ�
	//�R���{�͎��ԓ��ɃR���{�������ł͂Ȃ��A�Q�[�W���������ɏ����قǓ��_�ɍ����␳��������
	drawVsCombo(315, 170, player1);
	drawVsCombo(435, 170, player2);

	//�o�[�̏ڍ�
	//DrawStringToHandle(328, 179, "COMBO TIME", black, font2);
	const static int gaugeX = 40, gaugeY = 130;	//�Q�[�W�̕�
	const static int gf = 3;	//�O�g�̕�
	const static int gx = gaugeX - gf * 2, gy = gaugeY - gf * 2;	//�Q�[�W�̒��g�̕�

	{
		const static int x = 318, y1 = 219;	//�Q�[�W��x���W�Ay���W

		//�o�[�̒��̔w�i
		const static int hx1 = x + gf, hy1 = y1 + gf, hx2 = x + gf + gx, hy2 = y1 + gf + gy;
		DrawBox(hx1, hy1, hx2, hy2, GetColor(144, 144, 144), TRUE);

		//�Q�[�W��\������
		int hb = gy * player1.getComboTime() / MAX_COMBO_TIME;

		//�R���{���Ԃ�����Ԃ̓Q�[�W��0�ɂȂ�Ȃ��悤�ɂ���
		if (hb == 0 && player1.getComboTime() > 0)
		{
			hb = 1;
		}

		//�o�[�̎c�ʂɉ������F�̏o��
		DrawBox(hx1, hy2 - hb, hx2, hy2, GetHPColor(player1.getComboTime(), MAX_COMBO_TIME), TRUE);

		//�o�[�̊O�g�̕`��
		DrawGraph(x, y1, img.HPbar2, TRUE);
	}

	//2P��
	{
		const static int x = 438, y1 = 219;	//�Q�[�W��x���W�Ay���W

		//�o�[�̒��̔w�i
		const static int hx1 = x + gf, hy1 = y1 + gf, hx2 = x + gf + gx, hy2 = y1 + gf + gy;
		DrawBox(hx1, hy1, hx2, hy2, GetColor(144, 144, 144), TRUE);

		//�Q�[�W��\������
		int hb = gy * player2.getComboTime() / MAX_COMBO_TIME;

		//�R���{���Ԃ�����Ԃ̓Q�[�W��0�ɂȂ�Ȃ��悤�ɂ���
		if (hb == 0 && player2.getComboTime() > 0)
		{
			hb = 1;
		}

		//�o�[�̎c�ʂɉ������F�̏o��
		DrawBox(hx1, hy2 - hb, hx2, hy2, GetHPColor(player2.getComboTime(), MAX_COMBO_TIME), TRUE);

		//�o�[�̊O�g�̕`��
		DrawGraph(x, y1, img.HPbar2, TRUE);
	}
}

//�o�[�̎c�ʂɉ������F��Ԃ��֐�
int GetHPColor(int hp, int maxhp)
{
	int Red, Green, Blue;

	//0�Ŋ��邱�Ƃ����
	if (maxhp == 0)
	{
		return 0;
	}
	//�����ŋ�؂�̂ŕω��ʂ������ƂȂ�
	//�����ȏ�̎�(�΁����F)
	if (hp >= maxhp / 2)
	{
		Red = 355 - 243 * hp / maxhp;
		Green = 255;
		Blue = 112;
	}
	//���������̎�(���F����)
	else
	{
		Red = 255;
		Green = 510 * hp / maxhp;
		Blue = 224 * hp / maxhp;
	}
	return GetColor(Red, Green, Blue);
}
