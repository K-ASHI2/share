#include"DxLib.h"
#include"extern.h"
#include"function.h"

//�ΐl���[�h�̃R���g���[���I��
void CMenuWindow::operationMenu()
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

		//��Փx��I��(�L�����Z���ȊO)�̏ꍇ�A���̓�Փx��ۑ�����
		if (cursor != N_o_i - 1)
		{
			lastSelectedCPUMode = cursor;
		}

		switch (cursor)
		{
		case 0:
			padInputMode = epad_pad_pad;
			changeFlag(e_start);
			break;
		case 1:
			padInputMode = epad_keyboard_pad;
			changeFlag(e_start);
			break;
		case 2: changeFlag(e_title); break;
		}
	}
}

//�^�C�g����ʂ̕`��
void CMenuWindow::drawOperationMenu()
{
	const static int green = font.getGreen();
	const static int font0 = font.getFont(0);
	DrawGraph(0, 0, img.title, TRUE);
	drawRed(100, 100, "1P GAME PAD & 2P GAME PAD", 0);
	drawRed(100, 150, "1P KEYBOARD & 2P GAME PAD", 1);
	drawRed(100, 200, "BACK", 2);


	//�I�𒆂̍��ڂɊւ������
	switch (cursor) {
	case 0: DrawString(100, 550, "1P��2P���Q�[���p�b�h���g���܂�", green); break;
	case 1: DrawString(100, 550, "1P�̓L�[�{�[�h�A2P�̓Q�[���p�b�h���g���܂�", green); break;
	case 2: DrawString(100, 550, "�^�C�g����ʂɖ߂�܂�", green); break;
	}
}
