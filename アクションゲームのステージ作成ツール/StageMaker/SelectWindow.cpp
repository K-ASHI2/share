#pragma once
#include"DxLib.h"
#include"extern.h"
#include"function.h"

//�I����ʂ�ݒ肷�� n:���ڐ� c:�J�[�\���̈ʒu �f�t�H���g���� 0
void SetSelectWindow(int n, int c) {

	cursor = c;		//�J�[�\���̈ʒu�̏�����
	N_o_i = n;		//�c�̍��ڐ��̐ݒ�
}

//�I����ʂ�ݒ肷�� n:�c�̍��ڐ� n2:���̍��ڐ� c:�c�J�[�\���̈ʒu �f�t�H���g���� 0 c2:���J�[�\���̈ʒu �f�t�H���g���� 0
void SetSelectWindow_LR(int n, int n2, int c, int c2) {

	SetSelectWindow(n, c);
	cursor_LR = c2;		//�J�[�\���̈ʒu�̏�����
	N_o_i_LR = n2;		//���̍��ڐ��̐ݒ�
}

//�I����ʂ̏c�J�[�\���̈ړ�
//�㉺�̑���ȊO�͂����ɏ����Ȃ�
void SelectWindow() {

	if (button[KEY_UP] % 15 == 1) {
		//EffectSound(efs_select);//�I���̌��ʉ�
		if (cursor > 0) {
			cursor--;
		}
		else {
			cursor = N_o_i - 1;
		}
	}
	if (button[KEY_DOWN] % 15 == 1) {
		//EffectSound(efs_select);//�I���̌��ʉ�
		if (cursor < N_o_i - 1) {
			cursor++;
		}
		else {
			cursor = 0;
		}
	}
}

//�I����ʂ̉��J�[�\���̈ړ�
//���E�̑���ȊO�͂����ɏ����Ȃ�
void SelectWindow_LR() {

	if (button[KEY_LEFT] % 15 == 1) {
		//(efs_select);//�I���̌��ʉ�
		if (cursor_LR > 0) {
			cursor_LR--;
		}
		else {
			cursor_LR = N_o_i_LR - 1;
		}
	}
	if (button[KEY_RIGHT] % 15 == 1) {
		//EffectSound(efs_select);//�I���̌��ʉ�
		if (cursor_LR < N_o_i_LR - 1) {
			cursor_LR++;
		}
		else {
			cursor_LR = 0;
		}
	}
}

