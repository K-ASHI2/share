#include"DxLib.h"
#include"math.h"
#include"extern.h"
#include"function.h"	//共通の関数

//X座標,Y座標,文字の数,数字の数,ボタンの色　文字数に合うサイズのボタンを生成する
void DrawButton(int x, int y, int s, int n, unsigned int Color) {
	DrawBox(x - 7, y - 5, x + 8 + 20 * s + 10 * n, y + 23, GetColor(0, 0, 0), FALSE); //ボタンの枠の描画
	DrawBox(x - 6, y - 4, x + 7 + 20 * s + 10 * n, y + 22, Color, TRUE); //ボタンの色の描画
}

//速さのボタンの処理 座標と数字を受け取りその座標と数字を表示する
void DrawButton2(int x, int y, const char *c) {

	if (sx >= 0 && sy >= 0) {
		//ボタンが押されていれば
		if (JudgeMouse(x, y, 0, 1) == 1) {
			//mapを変更する mapが変更されたことでボタンの描画も変わる
			if (map[sx][sy] != 0) {
				map[sx][sy] = FigureChange(map[sx][sy], 4, atoi(c));
			}
		}
		//速さはマップの1000の位で表され、その速さがボタンの数値と等しいなら赤にする
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

//左右のボタンの処理 座標と文字と何番目かを受け取りその座標と文字を表示する　1:左 2:右
void DrawButton3(int x, int y, const char *c, int b) {

	if (sx >= 0 && sy >= 0) {
		if (JudgeMouse(x, y, 1, 0) == 1) {	//ボタンが押されていれば
			if (map[sx][sy] != 0) {
				//mapを変更する mapが変更されたことでボタンの描画も変わる
				map[sx][sy] = FigureChange(map[sx][sy], 5, b);
			}
		}
		//向きはマップの1万の位で表され、1:左 2:右
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

//正方形のボタンを作る 選択されていれば1を返す
int DrawButton4(int x1, int y1) {
	return DrawButton4(x1, y1, 32, 32);
}

//正方形のボタンを作る 選択されていれば1を返す
int DrawButton4(int x1, int y1, int size_x, int size_y) {

	int x2 = x1 + size_x, y2 = y1 + size_y;
	int  r = 0;
	DrawBox(x1, y1, x2, y2, black, FALSE);
	DrawBox(x1 + 1, y1 + 1, x2 - 1, y2 - 1, GetColor(210, 210, 210), TRUE);

	if (x1 < mx && x2 > mx && y1 < my && y2 > my && MouseL) {	//選択されたグリッドの保存
		sx2 = mx;	//メニュー内の選択されているx、y座標を保存する
		sy2 = my;
		r = 1;
	}
	if (x1 < sx2 && x2 > sx2 && y1 < sy2 && y2 > sy2) {	//選択されたグリッドの表示
		for (int i = 1; i < 3; i++) {
			DrawBox(x1 - i, y1 - i, x2 + i, y2 + i, GetColor(255, 0, 0), FALSE);
		}
		DrawBox(x1 - 3, y1 - 3, x2 + 3, y2 + 3, black, FALSE);
	}
	return r;
}
