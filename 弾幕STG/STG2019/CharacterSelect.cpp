#include"DxLib.h"
#include"extern.h"
#include"function.h"

//�L�����I�����
void CharacterSelect() {

	SelectWindow();
	SelectWindow_LR();
	if (button[KEY_BOMB] == 1) {//�L�����Z��
		ChangeFlag(cancel_flag, cancel_cursor);
		cancel_cursor = 0;
		efs(efs_back);
	}
	if (button[KEY_SHOT] == 1) {	//����
		efs(efs_decision);
		switch (cursor_LR) {
		case 0: 
			switch (cursor) {
			case 0: player.character = player.D_Magician_A; break;
			case 1: player.character = player.L_Magician_A; break;
			case 2: ChangeFlag(e_title); break;
			}
			break;
		case 1:
			switch (cursor) {
			case 0: player.character = player.D_Magician_B; break;
			case 1: player.character = player.L_Magician_B; break;
			}
			break;
		}
		ChangeFlag(e_difficultyselect);
	}
}

//�L�����N�^�[�I����ʂ̕`��
void DrawCharacterSelect() {

	DrawGraph(0, 0, img.background_2, TRUE);
	DrawStringToHandle(320, 70, "PLAYER SELECT", black, Font[0]);
	DrawStringToHandle(80, 100, "Moon Magician", black, Font[0]);
	DrawString(100, 130, "�����蔻�肪������", black);

	DrawRed2(100, 160, "A�@ ���C�h�V���b�g", 0, 0);
	DrawRed2(100, 188, "�V���b�g�@�N���Z���g�J�b�^�[", 0, 0);
	DrawRed2(100, 213, "�{���@�@�X�^�[�_�X�g�G�N�X�v���[�W����", 0, 0);
	DrawRed2(100, 238, "�{�����@3", 0, 0);
	DrawRed2(100, 266, "�U���͈͂��L�������₷��", 0, 0);
	DrawRed2(100, 291, "�{���͑S��ʔ���ňЗ͂͂�������", 0, 0);

	DrawRed2(420, 160, "B  �@�ϑ����C�h�V���b�g", 0, 1);
	DrawRed2(420, 188, "�V���b�g�@�j���[���[���_�[�N�l�X", 0, 1);
	DrawRed2(420, 213, "�{���@�@�@�u���b�N�z�[��", 0, 1);
	DrawRed2(420, 238, "�{�����@4", 0, 1);
	DrawRed2(420, 266, "�ʏ�V���b�g���������������V���b�g�͋���", 0, 1);
	DrawRed2(420, 291, "�{���������̂ŏ�肭�g���Ƃ悢", 0, 1);

	DrawStringToHandle(80, 340, "Sun Magician", black, Font[0]);
	DrawString(100, 370, "�ړ����x������", black, Font[0]);

	DrawRed2(100, 400, "A�@�@���Η͊ђʃ��[�U�[", 1, 0);
	DrawRed2(100, 428, "�V���b�g�@�T���V���C�����C", 1, 0);
	DrawRed2(100, 453, "�{���@�@�@�\�[���[�X�p�[�N", 1, 0);
	DrawRed2(100, 475, "�{�����@2", 1, 0);
	DrawRed2(100, 503, "�U���͈͂����������Η�", 1, 0);
	DrawRed2(100, 528, "�{�������Ȃ������Η�", 1, 0);

	DrawRed2(420, 400, "B�@�@�S���ʃV���b�g", 1, 1);
	DrawRed2(420, 428, "�V���b�g�@�T���V���C���u���X�g", 1, 1);
	DrawRed2(420, 453, "�{���@�@�@�A���e�B���b�g�t���b�V��", 1, 1);
	DrawRed2(420, 475, "�{�����@5", 1, 1);
	DrawRed2(420, 503, "�{�������ƂĂ��������V���b�g���{�����ア", 1, 1);
	DrawRed2(420, 528, "�������Č������ނƋ������g���ɂ���", 1, 1);
}

