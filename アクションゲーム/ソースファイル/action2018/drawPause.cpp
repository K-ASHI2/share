#include"DxLib.h"
#include"extern.h"
#include"function.h"

//�|�[�Y��ʂ̕`��
void drawPause() {

	DrawGraph(0, 0, img.title, TRUE);
	DrawRed(100, 100, "COUTINUE", 0);
	DrawRed(100, 180, "STAGE SERECT", 1);
	DrawRed(100, 260, "TITLE", 2);
	switch (cursor) {
	case 0: DrawString(100, 500, "�Q�[���ɖ߂�܂�", green); break;
	case 1: DrawString(100, 500, "�X�e�[�W�I�������܂�", green); break;
	case 2: DrawString(100, 500, "�^�C�g����ʂɖ߂�܂�", green); break;
	}
	DrawGraph(60, 98 + cursor * 80, img.arrow, TRUE);

	DrawStringToHandle(400, 360, "�\���{�^�� �I��", red, Font[2]);
	DrawStringToHandle(400, 400, "A�EB �@�@�@����", red, Font[2]);
	DrawStringToHandle(400, 440, "X�EY �@�@�@�L�����Z��", red, Font[2]);
}
