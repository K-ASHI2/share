#pragma once
#include"DxLib.h"
#include"extern.h"
#include"function.h"

//�`��̊֐�
void draw() {

	//��ʃN���A
	ClearDrawScreen();

	switch (flag) {
	case e_title:	//�^�C�g�����
		drawTitle();
		break;

	case e_clear:	//�N���A���
		
		//�Ō�̃X�e�[�W���N���A����ƕʂ̉摜��\������
		if (mapload % 1000 == 441) {
			DrawGraph(0, 0, img.allclear, TRUE);
		}
		else {
			DrawGraph(0, 0, img.clear, TRUE);
		}		break;

	case e_gameplay:	//�Q�[���v���C���
		draw_background();
		drawPlay();
		break;

	case e_gameover:	//�Q�[���I�[�o�[���
		DrawGraph(0, 0, img.gameover, TRUE);
		break;

	case e_stage_select:	//�X�e�[�W�I�����
		drawStageSelect();
		break;

	case e_difficulty_select:	//��Փx�I�����
		drawDifficultySelect();
		break;

	case e_pause:	//�|�[�Y���
		drawPause();
		break;

		//case e_option:
		//	DrawGraph(0, 0, img.title, TRUE);			//�^�C�g����ʂ�`��
		//	DrawString(100, 100, "SOUND vol", black);	//���ʐݒ�
		//	DrawString(100, 180, "OPERATING", black);	//�������
		//	DrawString(100, 260, "DEFAULT", black);
		//	DrawString(100, 340, "RETURN", black);
		//	DrawGraph(60, 98 + cursor * 80, img.arrow, TRUE);	//���̕`��
		//	break;

		//case e_keyconfig:
		//	DrawGraph(0, 0, img.title, TRUE);
		//	//�㉺���E�͕ύX����K�v�͂Ȃ�
		//	DrawString(100, 100, "SHOT", black);
		//	DrawString(100, 170, "BOMB", black);
		//	DrawString(100, 240, "SLOW", black);
		//	DrawString(100, 310, "PAUSE", black);
		//	DrawString(100, 380, "RESET", black);
		//	DrawString(100, 450, "QUIT", black);
		//	for (int i = 4; i < 8; i++) {//4�`7�̃{�^�����ύX�ł���{�^��
		//		char *p = NULL;
		//		switch (key_p[i]) {
		//		case PAD_A:		p = "PAD_A";			break;
		//		case PAD_B:		p = "PAD_B";			break;
		//		case PAD_X:		p = "PAD_X";			break;
		//		case PAD_Y:		p = "PAD_Y";			break;
		//		case PAD_LB:	p = "PAD_LB";			break;
		//		case PAD_RB:	p = "PAD_RB";			break;
		//		case PAD_BACK:	p = "PAD_BACK";			break;
		//		case PAD_START: p = "PAD_START";		break;
		//		default:		p = "�g�p�ł��܂���";	break;
		//		}
		//		DrawString(400, 100 + (i - 4) * 70, p, black);
		//	}
		//	DrawGraph(60, 98 + cursor * 70, img.arrow, TRUE);    //���̕`��
		//	break;

		//case soundtest:
		//	DrawGraph(0, 0, img.title, TRUE);
		//	DrawString(100, 100, "COUTINUE", black);
		//	DrawString(100, 180, "RETRY", black);
		//	DrawString(100, 260, "TITLE", black);
		//	DrawGraph(60, 98 + cursor * 80, img.arrow, TRUE);    //���̕`��
		//	break;   //�|�[�Y���
		//}
		//draw_ex();//��������̕\��
	}
	ScreenFlip();
}

//�w�肵�����Ԃ�����ʂ��؂�ւ�鎞�ɐ^���Âɂ���
void black_screen(int t) {
	ClearDrawScreen();
	ScreenFlip();
	WaitTimer(t);
}
