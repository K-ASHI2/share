#include"DxLib.h"
#include"extern.h"
#include"function.h"

//x���W,y���W,������A�c�ɉ��Ԗڂ��������Ƃ��A�J�[�\���̈ʒu�������Ȃ�ԁA�Ⴄ�Ȃ獕�ŕ`�悷��֐�
void DrawRed(int x, int y, const TCHAR *String, int c) {

	if (cursor == c) {
		DrawString(x, y, String, red);
	}
	else {
		DrawString(x, y, String, black);
	}
}

//x���W,y���W,������A�c���ɉ��Ԗڂ��������Ƃ��A�J�[�\���̈ʒu�������Ȃ�ԁA�Ⴄ�Ȃ獕�ŕ`�悷��֐�
void DrawRed2(int x, int y, const TCHAR *String, int c, int c2) {

	if (cursor == c && cursor_LR == c2) {
		DrawString(x, y, String, red);
	}
	else {
		DrawString(x, y, String, black);
	}
}
