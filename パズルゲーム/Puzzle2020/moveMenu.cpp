#include"DxLib.h"
#include"extern.h"
#include"function.h"

//CPU�ΐ�̓���̃��j���[
void CMenuWindow::moveMenu()
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
			player2.setCpuMove(ec_search);
			changeFlag(e_start);
			player2.setThinkingTime(40);
			break;
		case 1:
			player2.setCpuMove(ec_search);
			changeFlag(e_start);
			player2.setThinkingTime(25);
			break;
		case 2:
			player2.setCpuMove(ec_search);
			changeFlag(e_start);
			player2.setThinkingTime(10);
			break;
		case 3:
			player2.setCpuMove(ec_search);
			changeFlag(e_start);
			player2.setThinkingTime(0);
			break;
		case 4:	changeFlag(e_title); break;
		}
	}
}

//�^�C�g����ʂ̕`��
void CMenuWindow::drawMoveMenu()
{
	const static int green = font.getGreen();
	const static int font0 = font.getFont(0);
	DrawGraph(0, 0, img.title, TRUE);
	drawRed(100, 100, "LEVEL 1", 0);
	drawRed(100, 150, "LEVEL 2", 1);
	drawRed(100, 200, "LEVEL 3", 2);
	drawRed(100, 250, "LEVEL 4", 3);
	drawRed(100, 300, "BACK", 4);

	//�I�𒆂̍��ڂɊւ������
	switch (cursor) {
	case 0:
	case 1:
	case 2:
	case 3:	DrawString(100, 550, "��Փx��I��ł�������", green); break;
	case 4: DrawString(100, 550, "�^�C�g����ʂɖ߂�܂�", green); break;
	}
}
