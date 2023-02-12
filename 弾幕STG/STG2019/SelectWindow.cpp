#include"DxLib.h"
#include"extern.h"
#include"function.h"

void SetSelectWindow(int n, int c) {		//選択画面を設定する n:項目数 c:カーソルの位置 デフォルト引数 0

	cursor = c;		//カーソルの位置の初期化
	count = 0;		//入力の間隔の初期化
	N_o_i = n;		//縦の項目数の設定
}

//選択画面を設定する n:縦の項目数 n2:横の項目数  c:縦カーソルの位置 デフォルト 0 c2:横カーソルの位置 デフォルト 0
void SetSelectWindow_LR(int n, int n2, int c, int c2) {

	SetSelectWindow(n, c);
	cursor_LR = c2;	//カーソルの位置の初期化
	N_o_i_LR = n2;	//横の項目数の設定
}

//選択画面の縦カーソルの移動
//上下の操作以外はここに書かない
void SelectWindow(int mode){

	if (count == 0) {
		if ((button[KEY_UP] > 0 && mode == 0) || button[KEY_UP] == 1) {
			efs(efs_select);//選択の効果音
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
			efs(efs_select);//選択の効果音
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

//選択画面の横カーソルの移動
//左右の操作以外はここに書かない
void SelectWindow_LR() {

	if (count == 0) {
		if (button[KEY_LEFT] > 0) {
			efs(efs_select);//選択の効果音
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
			efs(efs_select);//選択の効果音
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
