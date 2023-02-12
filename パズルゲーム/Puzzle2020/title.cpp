#include"DxLib.h"
#include"extern.h"
#include"function.h"

void CMenuWindow::title()
{
	selectWindow();

	//�L�����Z��
	if (keyPad.getButton(KEY_CANCEL) == 1)
	{
		cursor = N_o_i - 1;	//�J�[�\������ԉ��ɂ���
		music.efs(efs_back);
	}

	//����
	if (keyPad.getButton(KEY_SHOT) == 1)
	{	
		music.efs(efs_decision);
		switch (cursor)
		{
		case 0://cpu�ΐ탂�[�h
			mode_flag = em_vs;	//�Q�[�����[�h��ʏ�X�^�[�g�ɖ߂�
			cancel_cursor = 0;
			init();
			player1.setCpuMove(ec_player);
			changeFlag(e_movemenu, lastSelectedCPUMode);
			break;
		case 1:	//�ΐl�탂�[�h
			mode_flag = em_vs;	//�Q�[�����[�h��ʏ�X�^�[�g�ɖ߂�
			cancel_cursor = 1;
			init();
			player1.setCpuMove(ec_player);
			player2.setCpuMove(ec_player);
			changeFlag(e_operationmenu);
			break;
		case 2://�R���{�A�^�b�N
			mode_flag = em_score_attack;	//�Q�[�����[�h��ʏ�X�^�[�g�ɖ߂�
			cancel_cursor = 2;
			init();
			changeFlag(e_start);
			break;
		case 3://�}�j���A��
			changeFlag(e_manual);
			cancel_cursor = 3;
			break;
		case 4: //�L�[�R���t�B�O
			changeFlag(e_keyconfig);
			cancel_cursor = 4; 
			break;
		case 5:	mode_flag = em_end; break;		//�Q�[���I��
		//case 0://�Q�[���X�^�[�g
		//	mode_flag = em_score_attack;	//�Q�[�����[�h��ʏ�X�^�[�g�ɖ߂�
		//	cancel_cursor = 0;
		//	init();
		//	changeFlag(e_movemenu);
		//	break;
		//case 1:	//�ΐ탂�[�h
		//	mode_flag = em_vs;	//�Q�[�����[�h��ʏ�X�^�[�g�ɖ߂�
		//	cancel_cursor = 1;
		//	init();
		//	changeFlag(e_movemenu);
		//	break;	//�L�[�R���t�B�O
		//case 2: changeFlag(e_keyconfig); break;	//�L�[�R���t�B�O
		//case 3:	mode_flag = em_end; break;		//�Q�[���I��
		}
	}
}

//�^�C�g����ʂ̕`��
void CMenuWindow::drawTitle()
{
	const static int green = font.getGreen();
	const static int font0 = font.getFont(0);
	DrawGraph(0, 0, img.title, TRUE);
	drawRed(100, 100, "VS CPU", 0);
	drawRed(100, 150, "VS PLAYER", 1);
	drawRed(100, 200, "COMBO ATTACK MODE", 2);
	drawRed(100, 250, "MANUAL", 3);
	drawRed(100, 300, "KEYCONFIG", 4);
	drawRed(100, 350, "EXIT", 5);
	//drawRed(100, 100, "GAME START", 0);
	//drawRed(100, 150, "VS START", 1);
	//drawRed(100, 200, "KEYCONFIG", 2);
	//drawRed(100, 250, "EXIT", 3);


	//�I�𒆂̍��ڂɊւ������
	switch (cursor) {
	case 0: DrawString(100, 550, "CPU�Ƒΐ킵�܂�", green);
		DrawStringToHandle(320, 60, "�J�[�\���𓮂����ău���b�N��h��A", green, font0);
		DrawStringToHandle(320, 90, "3�ȏ�c���ɐF�𑵂���Ə����܂��B", green, font0);
		DrawStringToHandle(320, 120, "�h��{�^���������ƃJ�[�\���̐F���h���܂��B", green, font0);
		DrawStringToHandle(320, 150, "��莞�Ԗ��Ƀu���b�N���������Ă��܂��B", green, font0);
		DrawStringToHandle(320, 180, "�u���b�N�̏��łɂ�闎���ŐF���������ꍇ�A", green, font0);
		DrawStringToHandle(320, 210, "�A���ƂȂ�A�A�����ɉ����ċ����U�����ł��܂��B", green, font0);
		DrawStringToHandle(320, 240, "�܂��A4�ȏ�ŏ����Ă��U�����邱�Ƃ��ł��܂��B", green, font0);
		DrawStringToHandle(320, 270, "�U������Ƒ���̏�ɔ��̃u���b�N���~��܂��B", green, font0);
		DrawStringToHandle(320, 300, "���̃u���b�N�͑����Ă������܂��񂪁A�h��܂��B", green, font0);
		DrawStringToHandle(320, 330, "��ʊO�ɓ��B����ƃQ�[���I�[�o�[�ł��B", green, font0);
		DrawStringToHandle(320, 360, "���ڂ���������MANUAL�Ō��邱�Ƃ��ł��܂��B", green, font0);
		break;

	case 1: DrawString(100, 550, "�v���C���[2�l�őΐ킵�܂�", green);
		DrawStringToHandle(320, 60, "�J�[�\���𓮂����ău���b�N��h��A", green, font0);
		DrawStringToHandle(320, 90, "3�ȏ�c���ɐF�𑵂���Ə����܂��B", green, font0);
		DrawStringToHandle(320, 120, "�h��{�^���������ƃJ�[�\���̐F���h���܂��B", green, font0);
		DrawStringToHandle(320, 150, "��莞�Ԗ��Ƀu���b�N���������Ă��܂��B", green, font0);
		DrawStringToHandle(320, 180, "�u���b�N�̏��łɂ�闎���ŐF���������ꍇ�A", green, font0);
		DrawStringToHandle(320, 210, "�A���ƂȂ�A�A�����ɉ����ċ����U�����ł��܂��B", green, font0);
		DrawStringToHandle(320, 240, "�܂��A4�ȏ�ŏ����Ă��U�����邱�Ƃ��ł��܂��B", green, font0);
		DrawStringToHandle(320, 270, "�U������Ƒ���̏�ɔ��̃u���b�N���~��܂��B", green, font0);
		DrawStringToHandle(320, 300, "���̃u���b�N�͑����Ă������܂��񂪁A�h��܂��B", green, font0);
		DrawStringToHandle(320, 330, "��ʊO�ɓ��B����ƃQ�[���I�[�o�[�ł��B", green, font0);
		DrawStringToHandle(320, 360, "���ڂ���������MANUAL�Ō��邱�Ƃ��ł��܂��B", green, font0); 
		break;
	case 2: DrawString(100, 550, "�ꕪ�ԂłȂ�ׂ��R���{���q�����[�h", green);
		DrawStringToHandle(320, 60, "�J�[�\���𓮂����ău���b�N��h��A", green, font0);
		DrawStringToHandle(320, 90, "3�ȏ�c���ɐF�𑵂���Ə����܂��B", green, font0);
		DrawStringToHandle(320, 120, "�h��{�^���������ƃJ�[�\���̐F���h���܂��B", green, font0);
		DrawStringToHandle(320, 150, "�u���b�N�������Ă���1.5�b�ȓ��ɏ�����", green, font0);
		DrawStringToHandle(320, 180, "�R���{���Ȃ���܂��B(�A���͂���܂���)", green, font0);
		DrawStringToHandle(320, 210, "�R���{�������قǃX�R�A����������܂��B", green, font0);
		DrawStringToHandle(320, 240, "�������Ԃ�1�����o�ƏI���ƂȂ�܂��B", green, font0);
		DrawStringToHandle(320, 270, "�������ԓ��ɂ�葽���̃X�R�A���҂��܂��傤�B", green, font0);
		break;
	case 3: DrawString(100, 550, "���[���̏ڍא���", green);
		DrawStringToHandle(320, 60, "�ΐ탂�[�h�̏ڍׂȗV�ѕ���A", green, font0);
		DrawStringToHandle(320, 90, "��̓I�Ȑ��l�ɂ��Č��邱�Ƃ��ł��܂��B", green, font0);
		break;
	case 4: DrawString(100, 550, "�R���g���[���̃{�^���ݒ�", green);
		DrawStringToHandle(320, 60, "�Q�[���p�b�h���g�p���鎞��", green, font0);
		DrawStringToHandle(320, 90, "�{�^���z�u�̐ݒ肪�ł��܂��B", green, font0);
		DrawStringToHandle(320, 120, "1P��2P�������{�^���z�u�ƂȂ�܂��B", green, font0);
		break;
	case 5: DrawString(100, 550, "�Q�[������߂�", green); break;
	}
}
