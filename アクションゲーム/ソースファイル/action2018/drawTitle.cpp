#include"DxLib.h"
#include"extern.h"
#include"function.h"

//�^�C�g����ʂ̕`�悷�郁�\�b�h
void drawTitle() {

	DrawGraph(0, 0, img.title, TRUE);
	DrawRed(100, 100, "GAME START", 0);
	//DrawRed(100, 180, "menu2", 1);
	//DrawRed(100, 260, "menu3", 2);
	DrawRed(100, 180, "EXIT", 1);
	DrawStringToHandle(400, 360, "�\���{�^�� �I��", red, Font[2]);
	DrawStringToHandle(400, 400, "A�EB �@�@�@����", red, Font[2]);
	DrawStringToHandle(400, 440, "X�EY �@�@�@�L�����Z��", red, Font[2]);

	//�I�𒆂̍��ڂɊւ������
	switch (cursor) {
	case 0: DrawString(100, 500, "�X�e�[�W��I��ŃQ�[�����n�߂܂�", green); break;
	//case 1: DrawString(100, 500, "menu2", green); break;
	//case 2: DrawString(100, 500, "menu3", green); break;
	case 1: DrawString(100, 500, "�Q�[�����I�����܂�", green); break;
	}
	DrawGraph(60, 98 + cursor * 80, img.arrow, TRUE);
}
