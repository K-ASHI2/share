#include"DxLib.h"
#include"extern.h"
#include"function.h"	//���ʂ̊֐�

//�{�^����xy���W�A�����̐��A�����̐����󂯎��A������Ă��Ȃ����0�A������Ă����1��Ԃ�
int JudgeMouse(int x, int y, int s, int n) {

	//�����̐��Ɛ����̐����畝���v�Z���Ă���
	return(JudgeMouse2(x - 7, y - 5, x + 8 + 20 * s + 10 * n, y + 23));
}

//�{�^����4�̒��_�̍��W���󂯎��A������Ă��Ȃ����0�A������Ă����1��Ԃ�
int JudgeMouse2(int x1, int y1, int x2, int y2) {

	if (x1 < mx && x2 > mx && y1 < my && y2 > my && MouseL == 1)
		return 1;
	else
		return 0;
}

//�{�^����xy���W�A�����̐��A�����̐����󂯎��}�E�X�̕ς���sx��sy�Ŕ��肷��
int JudgeMouse3(int x, int y, int s, int n) {

	int x1 = x - 7, y1 = y - 5, x2 = x + 8 + 20 * s + 10 * n, y2 = y + 23;
	if (x1 < sx2 && x2 > sx2 && y1 < sy2 && y2 > sy2)
		return 1;
	else
		return 0;
}

//�{�^����xy���W�A�����̐��A�����̐����󂯎��1�t���[���O�̃}�E�X�̍��W�Ŕ��肷��
int JudgeMouse4(int x, int y, int s, int n) {

	int x1 = x - 7, y1 = y - 5, x2 = x + 8 + 20 * s + 10 * n, y2 = y + 23;
	if (x1 < mx2 && x2 > mx2 && y1 < my2 && y2 > my2 && P_MouseL)
		return 1;
	else
		return 0;
}
