#include"DxLib.h"
#include"extern.h"
#include"function.h"

void Option() {

	SelectWindow();
	if (button[KEY_BOMB] == 1) {//�L�����Z���������ꂽ��J�[�\������ԉ��ɂ���
		cursor = N_o_i - 1;
	}
	if (button[KEY_SHOT] == 1) {
		switch (cursor) {
		case 0:
			if (window_mode == 0) {
				ChangeWindowMode(FALSE);	//�t���X�N���[�����[�h
				window_mode = 1;
			}
			else {
				ChangeWindowMode(TRUE);		//�E�B���h�E���[�h
				window_mode = 0;
			}
			SetFont();	//�t�H���g�̐ݒ�
			Load();
			Sleep(1000);
			break;
		case 1: draw_ex = 1 - draw_ex; break;	//��������̃I���I�t
		case 2: draw_ex = 1; break;	//�����ݒ�ɖ߂�(�X�N���[�����[�h�ȊO)
		case 3: ChangeFlag(e_title, 2); break;	//�^�C�g���ɖ߂�
		}
	}
}

//�I�v�V�����̕`��
void DrawOption() {
	DrawGraph(0, 0, img.background_2, TRUE);		//�^�C�g����ʂ�`��
													//DrawRed(100, 100, "SOUND vol", 0);	//���ʐݒ�
	DrawRed(100, 100, "SCREEN MODE", 0);	//�E�B���h�E���[�h
	if (window_mode == 1) {
		DrawRed(300, 100, "WINDOW", 0);
	}
	else {
		DrawRed(300, 100, "FULL SCREEN", 0);
	}
	DrawRed(100, 150, "OPERATING", 1);	//�������
	if (draw_ex == 1) {
		DrawRed(300, 150, "ON", 1);
	}
	else {
		DrawRed(300, 150, "OFF", 1);
	}
	DrawRed(100, 200, "DEFAULT", 2);
	DrawRed(100, 250, "EXIT", 3);
	//DrawGraph(60, 98 + cursor * 50, img.arrow, TRUE);    //���̕`��
}
