#include"DxLib.h"
#include"extern.h"
#include"function.h"

//x座標,y座標,文字列、縦に何番目かを引数とし、カーソルの位置が同じなら赤、違うなら黒で描画する関数
void DrawRed(int x, int y, const TCHAR *String, int c) {

	if (cursor == c) {
		DrawString(x, y, String, red);
	}
	else {
		DrawString(x, y, String, black);
	}
}

//x座標,y座標,文字列、縦横に何番目かを引数とし、カーソルの位置が同じなら赤、違うなら黒で描画する関数
void DrawRed2(int x, int y, const TCHAR *String, int c, int c2) {

	if (cursor == c && cursor_LR == c2) {
		DrawString(x, y, String, red);
	}
	else {
		DrawString(x, y, String, black);
	}
}
