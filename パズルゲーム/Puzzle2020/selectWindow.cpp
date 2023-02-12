#include"DxLib.h"
#include"extern.h"
#include"function.h"

//�I����ʂ�ݒ肷�� n:���ڐ� c:�J�[�\���̈ʒu �f�t�H���g���� 0
void CMenuWindow::setSelectWindow(int n, int c)
{
	cursor = c;		//�J�[�\���̈ʒu�̏�����
	cursor_count = 0;		//���͂̊Ԋu�̏�����
	N_o_i = n;		//�c�̍��ڐ��̐ݒ�
}

//�I����ʂ�ݒ肷�� n:�c�̍��ڐ� n2:���̍��ڐ�  c:�c�J�[�\���̈ʒu �f�t�H���g 0 c2:���J�[�\���̈ʒu �f�t�H���g 0
void CMenuWindow::setSelectWindow_LR(int n, int n2, int c, int c2)
{
	setSelectWindow(n, c);
	cursor_LR = c2;	//�J�[�\���̈ʒu�̏�����
	N_o_i_LR = n2;	//���̍��ڐ��̐ݒ�
}

//�I����ʂ̏c�J�[�\���̈ړ�
//�㉺�̑���ȊO�͂����ɏ����Ȃ�
void CMenuWindow::selectWindow(int mode)
{
	if (cursor_count == 0)
	{
		if ((keyPad.getButton(KEY_UP) > 0 && mode == 0) || keyPad.getButton(KEY_UP) == 1)
		{
			music.efs(efs_select);
			if (cursor > 0)
			{
				cursor--;
				cursor_count = COUNT;
			}
			else
			{
				cursor = N_o_i - 1;
				cursor_count = COUNT;
			}
		}
		if ((keyPad.getButton(KEY_DOWN) > 0 && mode == 0) || keyPad.getButton(KEY_DOWN) == 1)
		{
			music.efs(efs_select);
			if (cursor < N_o_i - 1)
			{
				cursor++;
				cursor_count = COUNT;
			}
			else
			{
				cursor = 0;
				cursor_count = COUNT;
			}
		}
	}

	if (cursor_count > 0)
	{
		cursor_count--;
	}
}

//�I����ʂ̉��J�[�\���̈ړ�
//���E�̑���ȊO�͂����ɏ����Ȃ�
void CMenuWindow::selectWindow_LR()
{
	if (cursor_count == 0)
	{
		if (keyPad.getButton(KEY_LEFT) > 0)
		{
			music.efs(efs_select);
			if (cursor_LR > 0)
			{
				cursor_LR--;
				cursor_count = COUNT;
			}
			else
			{
				cursor_LR = N_o_i_LR - 1;
				cursor_count = COUNT;
			}
		}
		if (keyPad.getButton(KEY_RIGHT) > 0)
		{
			music.efs(efs_select);
			if (cursor_LR < N_o_i_LR - 1)
			{
				cursor_LR++;
				cursor_count = COUNT;
			}
			else
			{
				cursor_LR = 0;
				cursor_count = COUNT;
			}
		}
	}

	if (cursor_count > 0)
	{
		cursor_count--;
	}
}
