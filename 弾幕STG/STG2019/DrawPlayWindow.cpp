#include"DxLib.h"
#include"extern.h"
#include"function.h"
#include"math.h"

void DrawPlayWindow() {
	//�Q�[���v���C���̉�ʊO�̕`��
	DrawGraph(0, 0, img.frame, TRUE);       //�O�g

	//��Փx�̕\��
	int color = white;	//��Փx�̐F
	char *dif_c[8];		//��Փx�̕�����
	switch (difficulty) {
	case ed_easy: color = red; *dif_c = "EASY";  break;
	case ed_normal: color = greenblue; *dif_c = "NORMAL"; break;
	case ed_hard: color = liteblack; *dif_c = "HARD";  break;
	case ed_lunatic: color = silver; *dif_c = "LUNATIC"; break;
	}
	DrawStringToHandle(625, 15, *dif_c, color, Font[0]);	//��Փx�\��

	//�n�C�X�R�A
	DrawStringToHandle(535, 50, "HISCORE", black, Font[0]);
	//10���̃X�R�A���ꂯ�����v�Z���ĕ\������
	for (int i = 0; i < 10; i++) {
		int s = hiscore % (int)pow(10.0, (double)(i + 1));
		if (i > 0) {
			s /= (int)pow(10.0, (double)i);
		}
		DrawFormatStringToHandle(750 - 12 * i, 50, black, Font[0], "%d", s);
	}

	//�X�R�A
	DrawStringToHandle(535, 80, "SCORE", black, Font[0]);
	//�I�[�o�[�t���[�΍�
	if (player.score > 10000000000) {
		player.score = 9999999999;
	}
	//10���̃X�R�A���ꂯ�����v�Z���ĕ\������
	for (int i = 0; i < 10; i++) {
		long long s = player.score % (long long)pow(10.0, (double)(i + 1));
		if (i > 0) {
			s /= (int)pow(10.0, (double)i);
		}
		DrawFormatStringToHandle(750 - 12 * i, 80, black, Font[0], "%d", s);
	}

	//�c�@
	DrawStringToHandle(535, 120, "LIFE", black, Font[0]);
	for (int i = 0; i < player.life - 1; i++) {
		if (i >= 8) {
			break;
		}
		DrawGraph(595 + i * 22, 120, img.life, TRUE);
	}
	//�{��
	DrawStringToHandle(535, 150, "BOMB", black, Font[0]);
	for (int i = 0; i < player.bomb; i++) {
		if (i >= 8) {
			break;
		}
		DrawGraph(595 + i * 22, 150, img.bomb, TRUE);
	}

	//�p���[
	DrawStringToHandle(535, 185, "POWER", black, Font[0]);
	DrawFormatStringToHandle(683, 185, black, Font[0], "%3.2f", player.power);
	//�ō��_
	DrawStringToHandle(535, 215, "ITEM SCORE", black, Font[0]);
	DrawFormatStringToHandle(650, 215, black, Font[0], "%7d", player.maxscore);
	//�O���C�Y
	DrawStringToHandle(535, 245, "GRAZE", black, Font[0]);
	DrawFormatStringToHandle(650, 245, black, Font[0], "%7d", player.graze);
	//HP�o�[�̕`��
	DrawHPBar();

	//�����̃o�[�̕`��
	DrawElementBar();

	//��������
	if (boss_flag == eb_boss && boss.time >= 0) {
		DrawFormatStringToHandle(475, 40, black, Font[0], "%2d", boss.time / 120);
	}

	//�f�o�b�O�p�̐��l
	//DrawFormatString(580, 360, black, "bomb_c  : %3d", player.bomb_c);
	//DrawFormatString(580, 390, black, "damaged : %3d", player.damaged);
	//DrawFormatString(580, 420, black, "item_k: %3d", item[0].kind);
	//DrawFormatString(580, 450, black, "sTCount  : %3d", stageTimeCount);
}

//�����̃o�[�̕`��
void DrawElementBar() {

	static int x = 628;
	static int gf = 3;	//�O�g�̕�
	static int gaugeX = 160, gaugeY = 20;	//�Q�[�W�̕�

	static int gx = gaugeX - gf * 2, gy = 20 - gf * 2;	//�Q�[�W�̒��g�̕�

	//�����Q�[�W�̍ő�l
	//static int MAX_ELEMENT = 1000;

	{
		static int y1 = 359;	//�Q�[�W��x���W�Ay���W
		//���݂̍U����HP�o�[
		DrawStringToHandle(x - 68, y1 + 1, "ICE", black, Font[0]);

		//HP�o�[�̒��̔w�i
		static int hx1 = x + gf, hy1 = y1 + gf, hx2 = x + gf + gx, hy2 = y1 + gf + gy;
		DrawBox(hx1, hy1, hx2, hy2, GetColor(144, 144, 144), TRUE);

		//HP�o�[�̊O�g�̕`��
		DrawGraph(x, y1, img.HPbar, TRUE);

		//HP�̃Q�[�W��\������
		int hb = gx * player.snowGauge / MAX_ELEMENT;

		DrawBox(hx1, hy1, hx1 + hb, hy2, GetColor(84, 255, 255), TRUE);
	}

	/*�T���_�[�Q�[�W*/

	{
		static int y1 = 389;

		//���݂̍U����HP�o�[
		DrawStringToHandle(x - 90, y1 + 1, "THUNDER", black, Font[0]);

		//HP�o�[�̒��̔w�i
		static int hx1 = x + gf, hy1 = y1 + gf, hx2 = x + gf + gx, hy2 = y1 + gf + gy;
		DrawBox(hx1, hy1, hx2, hy2, GetColor(144, 144, 144), TRUE);

		//HP�o�[�̊O�g�̕`��
		DrawGraph(x, y1, img.HPbar, TRUE);

		//HP�̃Q�[�W��\������
		int hb = gx * player.thunderGauge / MAX_ELEMENT;

		DrawBox(hx1, hy1, hx1 + hb, hy2, GetColor(255, 255, 56), TRUE);
	}

	/*�t�@�C�A�Q�[�W*/

	{
		static int y1 = 419;

		//���݂̍U����HP�o�[
		DrawStringToHandle(x - 70, y1 + 1, "FIRE", black, Font[0]);

		//HP�o�[�̒��̔w�i
		static int hx1 = x + gf, hy1 = y1 + gf, hx2 = x + gf + gx, hy2 = y1 + gf + gy;
		DrawBox(hx1, hy1, hx2, hy2, GetColor(144, 144, 144), TRUE);

		//HP�o�[�̊O�g�̕`��
		DrawGraph(x, y1, img.HPbar, TRUE);

		//HP�̃Q�[�W��\������
		int hb = gx * player.fireGauge / MAX_ELEMENT;

		DrawBox(hx1, hy1, hx1 + hb, hy2, GetColor(255, 80, 0), TRUE);
	}
}

//HP�o�[�̕`��
void DrawHPBar() {
	static int x = 628, y1 = 279, y2 = 309;	//�Q�[�W��x���W�Ay���W
	static int gf = 3;	//�O�g�̕�
	static int gaugeX = 160, gaugeY = 20;	//�Q�[�W�̕�

	static int gx = gaugeX - gf * 2, gy = 20 - gf * 2;	//�Q�[�W�̒��g�̕�

	//���݂̍U����HP�o�[
	DrawStringToHandle(x - 88, y1 + 1, "MODE HP", black, Font[0]);

	//HP�o�[�̒��̔w�i
	static int hx1 = x + gf, hy1 = y1 + gf, hx2 = x + gf + gx, hy2 = y1 + gf + gy;
	DrawBox(hx1, hy1, hx2, hy2, GetColor(144, 144, 144), TRUE);

	//HP�o�[�̊O�g�̕`��
	DrawGraph(x, y1, img.HPbar, TRUE);

	//HP�̃Q�[�W��\������
	int hb = 0;
	//0�Ŋ���Ȃ��悤�ɂ���
	if (boss.maxhp != 0) {
		hb = gx * boss.hp / boss.maxhp;
	}
	//�{�X��HP������Ԃ̓Q�[�W��0�ɂȂ�Ȃ��悤�ɂ���
	if (hb == 0 && boss.hp > 0) {
		hb = 1;
	}
	DrawBox(hx1, hy1, hx1 + hb, hy2, GetHPColor((int)boss.hp, (int)boss.maxhp), TRUE);


	//���v��HP�o�[
	DrawStringToHandle(x - 93, y2 + 1, "TOTAL HP", black, Font[0]);
	static int tx1 = x + gf, ty1 = y2 + gf, tx2 = x + gf + gx, ty2 = y2 + gf + gy;
	DrawBox(tx1, ty1, tx2, ty2, GetColor(144, 144, 144), TRUE);	//HP�o�[�̒��̔w�i
	DrawGraph(x, y2, img.HPbar, TRUE);	//HP�o�[�̊O�g�̕`��

	//���vHP�̃Q�[�W��\������
	int hb2 = 0;
	if (boss.maxtotalhp != 0) {
		hb2 = gx * boss.totalhp / boss.maxtotalhp;
	}
	DrawBox(tx1, ty1, tx1 + hb2, ty2, GetColor(127, 191, 255), TRUE);
	//�{�X��HP������Ԃ̓Q�[�W��0�ɂȂ�Ȃ��悤�ɂ���
	if (hb == 0 && boss.hp > 0) {
		hb = 1;
	}
}

//�G�̗̑͂ɉ�����HP�o�[�̐F��Ԃ��֐�
int GetHPColor(int hp, int maxhp) {

	int Red, Green, Blue;

	//0�Ŋ��邱�Ƃ����
	if (maxhp == 0) {
		return 0;
	}
	//hp�����ŋ�؂�̂ŕω��ʂ������ƂȂ�
	//hp�������ȏ�̎�(�΁����F)
	if (hp >= maxhp / 2) {
		Red = 355 - 243 * hp / maxhp;
		Green = 255;
		Blue = 112;
	}
	//hp�����������̎�(���F����)
	else {
		Red = 255;
		Green = 510 * hp / maxhp;
		Blue = 224 * hp / maxhp;
	}
	return GetColor(Red, Green, Blue);
}
