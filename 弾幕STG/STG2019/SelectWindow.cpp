#include"DxLib.h"
#include"extern.h"
#include"function.h"

void SetSelectWindow(int n, int c) {		//�I����ʂ�ݒ肷�� n:���ڐ� c:�J�[�\���̈ʒu �f�t�H���g���� 0

	cursor = c;		//�J�[�\���̈ʒu�̏�����
	count = 0;		//���͂̊Ԋu�̏�����
	N_o_i = n;		//�c�̍��ڐ��̐ݒ�
}

//�I����ʂ�ݒ肷�� n:�c�̍��ڐ� n2:���̍��ڐ�  c:�c�J�[�\���̈ʒu �f�t�H���g 0 c2:���J�[�\���̈ʒu �f�t�H���g 0
void SetSelectWindow_LR(int n, int n2, int c, int c2) {

	SetSelectWindow(n, c);
	cursor_LR = c2;	//�J�[�\���̈ʒu�̏�����
	N_o_i_LR = n2;	//���̍��ڐ��̐ݒ�
}

//�I����ʂ̏c�J�[�\���̈ړ�
//�㉺�̑���ȊO�͂����ɏ����Ȃ�
void SelectWindow(int mode){

	if (count == 0) {
		if ((button[KEY_UP] > 0 && mode == 0) || button[KEY_UP] == 1) {
			efs(efs_select);//�I���̌��ʉ�
			if (cursor > 0) {
				cursor--;
				count = COUNT;
			}
			else {
				cursor = N_o_i - 1;
				count = COUNT;
			}
		}
		if ((button[KEY_DOWN] > 0 && mode == 0) || button[KEY_DOWN] == 1) {
			efs(efs_select);//�I���̌��ʉ�
			if (cursor < N_o_i - 1) {
				cursor++;
				count = COUNT;
			}
			else {
				cursor = 0;
				count = COUNT;
			}
		}
	}
}

//�I����ʂ̉��J�[�\���̈ړ�
//���E�̑���ȊO�͂����ɏ����Ȃ�
void SelectWindow_LR() {

	if (count == 0) {
		if (button[KEY_LEFT] > 0) {
			efs(efs_select);//�I���̌��ʉ�
			if (cursor_LR > 0) {
				cursor_LR--;
				count = COUNT;
			}
			else {
				cursor_LR = N_o_i_LR - 1;
				count = COUNT;
			}
		}
		if (button[KEY_RIGHT] > 0) {
			efs(efs_select);//�I���̌��ʉ�
			if (cursor_LR < N_o_i_LR - 1) {
				cursor_LR++;
				count = COUNT;
			}
			else {
				cursor_LR = 0;
				count = COUNT;
			}
		}
	}
}
