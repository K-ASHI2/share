#include"DxLib.h"
#include"math.h"
#include"extern.h"
#include"function.h"	//���ʂ̊֐�
#include"csExtern.h"	//�X�e�[�W�쐬�݂̂Ɏg�p�ł���ϐ�
#include"csFunction.h"	//�X�e�[�W�쐬�݂̂Ɏg�p����֐�

void drawStage() {

	//��ʃN���A
	ClearDrawScreen();

	//�w�i�̕`��
	draw_background();

	player.x = cx;	//
	draw_csmap();	//��ʓ��̃}�b�v�̕`��

	DrawGraph(0, 480, img.bar1, TRUE);				//�X�N���[���o�[�̘g�̕\��
	DrawGraph(2 + SbarX, 482, img.scrollbar, TRUE);	//�X�N���[���o�[�̕`�� ��128 �c16
	DrawGraph(0, 500, img.cs_bg[0], TRUE);			//��ʉ��̈�ԉ��̔w�i

	//4�̃��j���[��I�сA�I�����ꂽ���e�̃{�^�����\�������
	for (int i = 1; i < 5; i++) {//���j���[�̕`��
		if (menu_b != i)//�I������Ă��Ȃ����j���[�����Ɏ����Ă���
			DrawGraph(0, 500, img.cs_bg[i], TRUE);
	}
	DrawGraph(0, 500, img.cs_bg[menu_b], TRUE);//�I�����ꂽ���j���[����Ԏ�O�ɕ`�悷��
	DrawStringToHandle(59, 505, "�G", GetColor(0, 0, 0), Font[0]);
	DrawStringToHandle(167, 505, "�u���b�N", GetColor(0, 0, 0), Font[0]);
	DrawStringToHandle(318, 505, "���̑�", GetColor(0, 0, 0), Font[0]);
	DrawStringToHandle(442, 505, "�X�e�[�^�X", GetColor(0, 0, 0), Font[0]);

	//���j���[�̕`��
	drawCSMenu();
	
	ScreenFlip();
}
