#include"DxLib.h"
#include"extern.h"
#include"function.h"

void title() {

	select_window();
	if (button[KEY_ATTACK] == 1) {	//�L�����Z��
		cursor = N_o_i - 1;			//�J�[�\������ԉ��ɂ���
	}
	if (button[KEY_JUMP] == 1) {	//����
		efs(efs_decision);//����̌��ʉ�
		switch (cursor) {
		case 0:		//�Q�[���X�^�[�g(�X�e�[�W�I��)
			change_flag(e_stage_select);
			break;
		//case 1:		//�X�e�[�W�쐬
		//	mode_flag = em_createStage;
		//	change_flag(e_stage_select);
		//	break;
		//case 2:		//�쐬���ꂽ�X�e�[�W�̑I��
		//	mode_flag = em_play_cs;
		//	change_flag(e_stage_select);
		//	break;
		case 1:	mode_flag = em_end; break;
		}
	}
}
