#include"DxLib.h"
#include"extern.h"
#include"function.h"

void Title() {

	SelectWindow();
	if (button[KEY_BOMB] == 1) {	//�L�����Z��
		cursor = N_o_i - 1;	//�J�[�\������ԉ��ɂ���
		efs(efs_back);
	}
	if (button[KEY_SHOT] == 1) {//����
		efs(efs_decision);
		switch (cursor) {
		case 0://�Q�[���X�^�[�g
			mode_flag = em_normal;	//�Q�[�����[�h��ʏ�X�^�[�g�ɖ߂�
			cancel_cursor = 0;
			ChangeFlag(e_characterselect);
			boss.mode_p = 0;
			world = ew_2;
			break;
		//case 1: //�G�N�X�g��
		//	cancel_cursor = 1;
		//	ChangeFlag(e_characterselect);
		//	world = ew_extra;
		//	break;
		//case 2: ChangeFlag(e_practice); break;	//�v���N�e�B�X
		case 1: 
			mode_flag = em_burragepractice;
			ChangeFlag(e_burragepractice);
			break;	//�e���v���N�e�B�X
		//case 4: ChangeFlag(e_option); break;	//�I�v�V����
		case 2: ChangeFlag(e_keyconfig); break;	//�L�[�R���t�B�O
		//case 3: ChangeFlag(e_soundtest); break;	//�T�E���h�e�X�g
		case 3:	mode_flag = em_end; break;		//�Q�[���I��
		}
	}
}

//�^�C�g����ʂ̕`��
void DrawTitle() {
	DrawGraph(0, 0, img.background_2, TRUE);
	DrawRed(100, 100, "GAME START", 0);
	//DrawRed(100, 150, "EXTRA START", 1);
	//DrawRed(100, 200, "PRACTICE", 2);
	DrawRed(100, 150, "BURRAGE PRACTICE", 1);
	//DrawRed(100, 300, "OPTION", 4);
	DrawRed(100, 200, "KEYCONFIG", 2);
	//DrawRed(100, 250, "SOUNDTEST", 3);
	DrawRed(100, 250, "EXIT", 3);
	//DrawGraph(60, 98 + cursor * 50, img.arrow, TRUE);    //���̕`��


	DrawStringToHandle(340, 60, "�G�̍U��������V���b�g�������A", green, Font[0]);
	DrawStringToHandle(340, 90, "hp��0�ɂ�����N���A�ł��B", green, Font[0]);
	DrawStringToHandle(340, 120, "�G�̍U����hp�����炷�ƕω����Ă����܂��B", green, Font[0]);
	DrawStringToHandle(340, 150, "�{�������Ɩ��G�ɂȂ苭���U�����ł��邪�A", green, Font[0]);
	DrawStringToHandle(340, 180, "��e����܂ł̉񐔐���������܂��B", green, Font[0]);
	DrawStringToHandle(340, 230, "�G�̒e���������e�ɋ߂Â��ƁA", green, Font[0]);
	DrawStringToHandle(340, 260, "�e�̑���(�F)�ɑΉ������Q�[�W�����܂�܂��B", green, Font[0]);
	DrawStringToHandle(340, 290, "�Q�[�W�����^���ɂȂ�ƌ�������0�ɂȂ�܂�", green, Font[0]);
	DrawStringToHandle(340, 320, "�����V���b�g�����Ă܂��B", green, Font[0]);
}
