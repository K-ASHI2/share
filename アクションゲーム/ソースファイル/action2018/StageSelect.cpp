#include"DxLib.h"
#include"extern.h"
#include"function.h"

//�X�e�[�W�I�����
void stage_select() {

	select_window();	//�c�J�[�\���̈ړ�
	select_window_LR();	//���J�[�\���̈ړ�
	//�L�����Z��
	if (button[KEY_ATTACK] == 1 || button[KEY_PAUSE] == 1) {
		efs(efs_back);
		//�|�[�Y��ʂɖ߂鎞�͑I�����̈ʒu��2�Ԗڂɂ���
		if(cancel_flag == e_pause)
			change_flag(cancel_flag, 1);
		else
			change_flag(cancel_flag);
	}

	if (button[KEY_JUMP] == 1) {
		efs(efs_decision);
		//�c�̃J�[�\���Ń��[���h�A���̃J�[�\���ŃX�e�[�W��I��
		mapload = (cursor + 1) * 100 + (cursor_LR + 1) * 10 + 1;

		change_flag(e_difficulty_select, 1);
	}
}
