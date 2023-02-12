#include"DxLib.h"
#include"extern.h"
#include"function.h"	//共通の関数

//ボタンのxy座標、文字の数、数字の数を受け取り、押されていなければ0、押されていれば1を返す
int JudgeMouse(int x, int y, int s, int n) {

	//文字の数と数字の数から幅を計算している
	return(JudgeMouse2(x - 7, y - 5, x + 8 + 20 * s + 10 * n, y + 23));
}

//ボタンの4つの頂点の座標を受け取り、押されていなければ0、押されていれば1を返す
int JudgeMouse2(int x1, int y1, int x2, int y2) {

	if (x1 < mx && x2 > mx && y1 < my && y2 > my && MouseL == 1)
		return 1;
	else
		return 0;
}

//ボタンのxy座標、文字の数、数字の数を受け取りマウスの変わりにsxとsyで判定する
int JudgeMouse3(int x, int y, int s, int n) {

	int x1 = x - 7, y1 = y - 5, x2 = x + 8 + 20 * s + 10 * n, y2 = y + 23;
	if (x1 < sx2 && x2 > sx2 && y1 < sy2 && y2 > sy2)
		return 1;
	else
		return 0;
}

//ボタンのxy座標、文字の数、数字の数を受け取り1フレーム前のマウスの座標で判定する
int JudgeMouse4(int x, int y, int s, int n) {

	int x1 = x - 7, y1 = y - 5, x2 = x + 8 + 20 * s + 10 * n, y2 = y + 23;
	if (x1 < mx2 && x2 > mx2 && y1 < my2 && y2 > my2 && P_MouseL)
		return 1;
	else
		return 0;
}
