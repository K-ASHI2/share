#include"DxLib.h"
#include"extern.h"
#include"function.h"

//�L�[�R���t�B�O
void CMenuWindow::keyConfig()
{
	selectWindow();
	if (keyPad.getButton(KEY_SHOT) == 1)
	{
		//���Z�b�g
		if (cursor == N_o_i - 2)
		{
			keyPad.init();
			music.efs(efs_decision);
		}
		//�^�C�g���ɖ߂�
		else if (cursor == N_o_i - 1)
		{
			changeFlag(e_title, 1);
			music.efs(efs_back);
		}
	}

	//�L�[�{�[�h���͂̂�
	if (keyPad.getKey(KEY_INPUT_X) == 1 && cursor_count == 0)
	{
		cursor = N_o_i - 1;	//�J�[�\������ԉ��ɂ���
		cursor_count = 12;
		music.efs(efs_back);
	}

	//�J�[�\�������킹���ʒu�ŃQ�[���p�b�h�̃{�^���������ƃp�b�h�̃{�^�����ݒ肳���
	//�㉺���E���������h��A�L�����Z���A�|�[�Y�݂̂Ɋւ��čs��
	if (cursor < 3)
	{
		//cursor�ɍ�����������keyPad���ōs��
		keyPad.setKeyConfig(cursor);
	}
}

//�L�[�R���t�B�O�̕`��
void CMenuWindow::drawKeyConfig()
{
	const static int green = font.getGreen();

	DrawGraph(0, 0, img.title, TRUE);
	//�㉺���E�͕ύX����K�v�͂Ȃ�
	drawRed(100, 100, "DRAW", 0);
	drawRed(100, 150, "DROP", 1);
	drawRed(100, 200, "PAUSE", 2);
	drawRed(100, 250, "RESET", 3);
	drawRed(100, 300, "QUIT", 4);//�I�𒆂̍��ڂɊւ������

	//4�`6�̃{�^�����ύX�ł���
	for (int i = 4; i < 7; i++)
	{
		//�{�^���ɑΉ�����char
		drawRed(300, 100 + (i - 4) * 50, keyPad.getCPad(i), i - 4);
	}

	DrawString(100, 500, "�Q�[���p�b�h�Ń{�^���������Ɛݒ�ł��܂�", green);
	switch (cursor) {
	case 0:	DrawString(100, 550, "�h��{�^��", green); break;
	case 1:	DrawString(100, 550, "�u���b�N�𗎉�������{�^��", green); break;
	case 2:	DrawString(100, 550, "�|�[�Y�{�^��", green); break;
	case 3:	DrawString(100, 550, "�{�^���z�u���f�t�H���g�ɖ߂��܂�", green); break;
	case 4: DrawString(100, 550, "�^�C�g����ʂɖ߂�܂�", green); break;
	}
}
