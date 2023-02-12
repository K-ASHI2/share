#include"DxLib.h"
#include"extern.h"
#include"function.h"

//x座標,y座標,文字列、縦に何番目かを引数とし、カーソルの位置が同じなら赤、違うなら黒で描画する関数
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

////x座標,y座標,文字列、縦横に何番目かを引数とし、カーソルの位置が同じなら赤、違うなら黒で描画する関数
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

//x座標,y座標,文字列、縦に何番目かを引数とし、カーソルの位置が同じなら赤、違うなら黒で描画する関数
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
