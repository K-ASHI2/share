#include"DxLib.h"
#include"math.h"
#include"extern.h"
#include"function.h"	//���ʂ̊֐�

//X���W,Y���W,�����̐�,�����̐�,�{�^���̐F�@�������ɍ����T�C�Y�̃{�^���𐶐�����
void DrawButton(int x, int y, int s, int n, unsigned int Color) {
	DrawBox(x - 7, y - 5, x + 8 + 20 * s + 10 * n, y + 23, GetColor(0, 0, 0), FALSE); //�{�^���̘g�̕`��
	DrawBox(x - 6, y - 4, x + 7 + 20 * s + 10 * n, y + 22, Color, TRUE); //�{�^���̐F�̕`��
}

//�����̃{�^���̏��� ���W�Ɛ������󂯎�肻�̍��W�Ɛ�����\������
void DrawButton2(int x, int y, const char *c) {

	if (sx >= 0 && sy >= 0) {
		//�{�^����������Ă����
		if (JudgeMouse(x, y, 0, 1) == 1) {
			//map��ύX���� map���ύX���ꂽ���ƂŃ{�^���̕`����ς��
			if (map[sx][sy] != 0) {
				map[sx][sy] = FigureChange(map[sx][sy], 4, atoi(c));
			}
		}
		//�����̓}�b�v��1000�̈ʂŕ\����A���̑������{�^���̐��l�Ɠ������Ȃ�Ԃɂ���
		if (map[sx][sy] >= 1000 && (map[sx][sy] % 10000) / 1000 == atoi(c)) {
			DrawButton(x, y, 0, 1, redbutton);
		}
		else {
			DrawButton(x, y, 0, 1, bluebutton);
		}
	}
	else {
		DrawButton(x, y, 0, 1, bluebutton);
	}
	DrawStringToHandle(x, y, c, black, Font[0]);
}

//���E�̃{�^���̏��� ���W�ƕ����Ɖ��Ԗڂ����󂯎�肻�̍��W�ƕ�����\������@1:�� 2:�E
void DrawButton3(int x, int y, const char *c, int b) {

	if (sx >= 0 && sy >= 0) {
		if (JudgeMouse(x, y, 1, 0) == 1) {	//�{�^����������Ă����
			if (map[sx][sy] != 0) {
				//map��ύX���� map���ύX���ꂽ���ƂŃ{�^���̕`����ς��
				map[sx][sy] = FigureChange(map[sx][sy], 5, b);
			}
		}
		//�����̓}�b�v��1���̈ʂŕ\����A1:�� 2:�E
		if (map[sx][sy] >= 10000 && (map[sx][sy] % 100000) / 10000 == b) {
			DrawButton(x, y, 1, 0, redbutton);
		}
		else {
			DrawButton(x, y, 1, 0, bluebutton);
		}
	}
	else {
		DrawButton(x, y, 1, 0, bluebutton);
	}
	DrawStringToHandle(x, y, c, black, Font[0]);
}

//�����`�̃{�^������� �I������Ă����1��Ԃ�
int DrawButton4(int x1, int y1) {
	return DrawButton4(x1, y1, 32, 32);
}

//�����`�̃{�^������� �I������Ă����1��Ԃ�
int DrawButton4(int x1, int y1, int size_x, int size_y) {

	int x2 = x1 + size_x, y2 = y1 + size_y;
	int  r = 0;
	DrawBox(x1, y1, x2, y2, black, FALSE);
	DrawBox(x1 + 1, y1 + 1, x2 - 1, y2 - 1, GetColor(210, 210, 210), TRUE);

	if (x1 < mx && x2 > mx && y1 < my && y2 > my && MouseL) {	//�I�����ꂽ�O���b�h�̕ۑ�
		sx2 = mx;	//���j���[���̑I������Ă���x�Ay���W��ۑ�����
		sy2 = my;
		r = 1;
	}
	if (x1 < sx2 && x2 > sx2 && y1 < sy2 && y2 > sy2) {	//�I�����ꂽ�O���b�h�̕\��
		for (int i = 1; i < 3; i++) {
			DrawBox(x1 - i, y1 - i, x2 + i, y2 + i, GetColor(255, 0, 0), FALSE);
		}
		DrawBox(x1 - 3, y1 - 3, x2 + 3, y2 + 3, black, FALSE);
	}
	return r;
}
