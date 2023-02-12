#include"DxLib.h"
#include"extern.h"
#include"function.h"

void KeyConfig() {

	SelectWindow();
	if (button[KEY_SHOT] == 1){
		if (cursor == N_o_i - 2) {	//���Z�b�g
			init_key_p();
			efs(efs_decision);
		}
		else if (cursor == N_o_i - 1) {
			ChangeFlag(e_title, 3);
			efs(efs_back);
		}
	}
	if (Key[KEY_INPUT_X] == 1 && count == 0) {//�L�[�{�[�h���͂̂�
		cursor = N_o_i - 1;//�J�[�\������ԉ��ɂ���
		count = 12;
		efs(efs_back);
	}
	//�J�[�\�������킹���ʒu�ŃQ�[���p�b�h�̃{�^���������ƃp�b�h�̃{�^�����ݒ肳���
	//�㉺���E���������V���b�g�A�{���A�ᑬ�A�|�[�Y�݂̂Ɋւ��čs��
	if (cursor < 4) {
		//�\���L�[�ȊO�̃{�^���ɑ΂��Đݒ肷��
		for (int i = 4; i <= 15; i++) {
			if (Pad[i] == 1) {
				efs(efs_decision);
				int k = key_p[cursor + 4];	//���X�̃{�^����ۑ�����
				key_p[cursor + 4] = i;
				switch (key_p[cursor + 4]) {
				case PAD_A:		cPad[cursor + 4] = "PAD_A";			break;
				case PAD_B:		cPad[cursor + 4] = "PAD_B";			break;
				case PAD_X:		cPad[cursor + 4] = "PAD_X";			break;
				case PAD_Y:		cPad[cursor + 4] = "PAD_Y";			break;
				case PAD_LB:	cPad[cursor + 4] = "PAD_LB";		break;
				case PAD_RB:	cPad[cursor + 4] = "PAD_RB";		break;
				case PAD_LT:	cPad[cursor + 4] = "PAD_LT";		break;
				case PAD_RT:	cPad[cursor + 4] = "PAD_RT";		break;
				case PAD_BACK:	cPad[cursor + 4] = "PAD_BACK";		break;
				case PAD_START: cPad[cursor + 4] = "PAD_START";		break;
				default:		cPad[cursor + 4] = "�g�p�ł��܂���";break;
				}
				//���łɑ��̃{�^���Ƃ��Ďg���Ă����Ȃ����ւ���
				for (int j = 4; j <= 7; j++) {
					if (key_p[j] == i && j != cursor + 4) {
						key_p[j] = k;
						switch (key_p[j]) {
						case PAD_A:		cPad[j] = "PAD_A";			break;
						case PAD_B:		cPad[j] = "PAD_B";			break;
						case PAD_X:		cPad[j] = "PAD_X";			break;
						case PAD_Y:		cPad[j] = "PAD_Y";			break;
						case PAD_LB:	cPad[j] = "PAD_LB";			break;
						case PAD_RB:	cPad[j] = "PAD_RB";			break;
						case PAD_LT:	cPad[j] = "PAD_LT";			break;
						case PAD_RT:	cPad[j] = "PAD_RT";			break;
						case PAD_BACK:	cPad[j] = "PAD_BACK";		break;
						case PAD_START: cPad[j] = "PAD_START";		break;
						default:		cPad[j] = "�g�p�ł��܂���"; break;
						}
						break;
					}
				}
				break;
			}
		}
	}
}

//�L�[�R���t�B�O�̕`��
void DrawKeyConfig() {
	DrawGraph(0, 0, img.background_2, TRUE);
	//�㉺���E�͕ύX����K�v�͂Ȃ�
	DrawRed(100, 100, "SHOT", 0);
	DrawRed(100, 150, "BOMB", 1);
	DrawRed(100, 200, "SLOW", 2);
	DrawRed(100, 250, "PAUSE", 3);
	DrawRed(100, 300, "RESET", 4);
	DrawRed(100, 350, "QUIT", 5);
	for (int i = 4; i < 8; i++) {//4�`7�̃{�^�����ύX�ł���{�^��
		char *p = NULL;
		switch (key_p[i]) {
		case PAD_A:		p = "PAD_A";			break;
		case PAD_B:		p = "PAD_B";			break;
		case PAD_X:		p = "PAD_X";			break;
		case PAD_Y:		p = "PAD_Y";			break;
		case PAD_LB:	p = "PAD_LB";			break;
		case PAD_RB:	p = "PAD_RB";			break;
		case PAD_LT:	p = "PAD_LT";			break;
		case PAD_RT:	p = "PAD_RT";			break;
		case PAD_BACK:	p = "PAD_BACK";			break;
		case PAD_START: p = "PAD_START";		break;
		default:		p = "�g�p�ł��܂���";	break;
		}
		DrawRed(300, 100 + (i - 4) * 50, p, i - 4);
	}
	//DrawGraph(60, 98 + cursor * 50, img.arrow, TRUE);    //���̕`��
}
