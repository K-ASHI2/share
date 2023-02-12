#include"DxLib.h"
#include"math.h"
#include"extern.h"
#include"function.h"	//���ʂ̊֐�

void DrawStage() {

	//��ʃN���A
	ClearDrawScreen();

	//�w�i�̕`��
	DrawBackground();

	DrawMap();	//��ʓ��̃}�b�v�̕`��

	//�X�N���[���o�[�̕\��
	DrawGraph(0, WINDOW_HEIGHT, img.bar1, TRUE);
	DrawTurnGraph(2, WINDOW_HEIGHT + 2, img.barRIGHT, TRUE);
	DrawGraph(WINDOW_WIDTH - 2 - 16, WINDOW_HEIGHT + 2, img.barRIGHT, TRUE);
	DrawGraph(WINDOW_WIDTH, 0, img.bar2, TRUE);
	DrawGraph(WINDOW_WIDTH + 2, 2, img.barUP, TRUE);
	DrawGraph(WINDOW_WIDTH + 2, WINDOW_HEIGHT - 2 - 16, img.barDOWN, TRUE);
	//�E���̊p
	DrawGraph(WINDOW_WIDTH, WINDOW_HEIGHT, img.bar3, TRUE);

	//�X�N���[���o�[�̕`�� 
	//�X�N���[�����Ȃ��ꍇ�͕\�����Ȃ�
	if (width_size * block_size > WINDOW_WIDTH) {
		if (scrollbar.click == 1) {
			DrawGraph(scrollbar.x, scrollbar.y, img.scrollbar, TRUE);
		}
		else {
			//�������ŃX�N���[���o�[��`��
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 192);
			DrawGraph(scrollbar.x, scrollbar.y, img.scrollbar, TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
	}
	if (height_size * block_size > WINDOW_HEIGHT) {
		if (scrollbar2.click == 1) {
			DrawGraph(scrollbar2.x, scrollbar2.y, img.scrollbarV, TRUE);
		}
		else {
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 192);
			DrawGraph(scrollbar2.x, scrollbar2.y, img.scrollbarV, TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
	}

	DrawGraph(0, 500, img.cs_bg[0], TRUE);			//��ʉ��̈�ԉ��̔w�i

	//4�̃��j���[��I�сA�I�����ꂽ���e�̃{�^�����\�������
	for (int i = 1; i < 5; i++) {	//���j���[�̕`��
		if (menu_b != i)	//�I������Ă��Ȃ����j���[�����Ɏ����Ă���
			DrawGraph(0, 500, img.cs_bg[i], TRUE);
	}
	DrawGraph(0, 500, img.cs_bg[menu_b], TRUE);//�I�����ꂽ���j���[����Ԏ�O�ɕ`�悷��
	DrawStringToHandle(59, 505, "�G", GetColor(0, 0, 0), Font[0]);
	DrawStringToHandle(167, 505, "�u���b�N", GetColor(0, 0, 0), Font[0]);
	DrawStringToHandle(318, 505, "���̑�", GetColor(0, 0, 0), Font[0]);
	DrawStringToHandle(442, 505, "�X�e�[�^�X", GetColor(0, 0, 0), Font[0]);

	//���j���[�̕`��
	DrawCSMenu();
	
	//���݂̃t�@�C���̈ʒu��`��
	//DrawStringToHandle(32, 35, CurrentFile, GetColor(0, 0, 0), Font[0]);
	//DrawFormatStringToHandle(32, 30, red, Font[0], "c_move : %d", c_move);
	//DrawFormatStringToHandle(32, 70, red, Font[0], "mx2 : %d", mx2);

	ScreenFlip();
}
