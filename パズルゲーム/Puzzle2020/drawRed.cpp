#include"DxLib.h"
#include"extern.h"
#include"function.h"

//x���W,y���W,������A�c�ɉ��Ԗڂ��������Ƃ��A�J�[�\���̈ʒu�������Ȃ�ԁA�Ⴄ�Ȃ獕�ŕ`�悷��֐�
void CMenuWindow::drawRed(int x, int y, const char *String, int c)
{
	const static int red = font.getRed();
	const static int black = font.getBlack();

	if (cursor == c)
	{
		DrawString(x, y, String, red);
	}
	else
	{
		DrawString(x, y, String, black);
	}
}

////x���W,y���W,������A�c���ɉ��Ԗڂ��������Ƃ��A�J�[�\���̈ʒu�������Ȃ�ԁA�Ⴄ�Ȃ獕�ŕ`�悷��֐�
void CMenuWindow::drawRed2(int x, int y, const char *String, int c, int c2)
{
	const static int red = font.getRed();
	const static int black = font.getBlack();

	if (cursor == c && cursor_LR == c2)
	{
		DrawString(x, y, String, red);
	}
	else
	{
		DrawString(x, y, String, black);
	}
}

//x���W,y���W,������A�c�ɉ��Ԗڂ��������Ƃ��A�J�[�\���̈ʒu�������Ȃ�ԁA�Ⴄ�Ȃ獕�ŕ`�悷��֐�
void CMenuWindow::drawColor(int x, int y, const char *String, int c, unsigned int N_Color, unsigned int C_Color, unsigned int N_EdgeColor, unsigned int C_EdgeColor)
{
	if (cursor == c)
	{
		DrawString(x, y, String, C_Color, C_EdgeColor);
	}
	else
	{
		DrawString(x, y, String, N_Color, N_EdgeColor);
	}
}
