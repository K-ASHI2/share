#pragma once
#include"DxLib.h"
#include"extern.h"
#include"function.h"

//選択画面を設定する n:項目数 c:カーソルの位置 デフォルト引数 0
void SetSelectWindow(int n, int c) {

	cursor = c;		//カーソルの位置の初期化
	N_o_i = n;		//縦の項目数の設定
}

//選択画面を設定する n:縦の項目数 n2:横の項目数 c:縦カーソルの位置 デフォルト引数 0 c2:横カーソルの位置 デフォルト引数 0
void SetSelectWindow_LR(int n, int n2, int c, int c2) {

	SetSelectWindow(n, c);
	cursor_LR = c2;		//カーソルの位置の初期化
	N_o_i_LR = n2;		//横の項目数の設定
}

//選択画面の縦カーソルの移動
//上下の操作以外はここに書かない
void SelectWindow() {

	if (button[KEY_UP] % 15 == 1) {
		//EffectSound(efs_select);//選択の効果音
		if (cursor > 0) {
			cursor--;
		}
		else {
			cursor = N_o_i - 1;
		}
	}
	if (button[KEY_DOWN] % 15 == 1) {
		//EffectSound(efs_select);//選択の効果音
		if (cursor < N_o_i - 1) {
			cursor++;
		}
		else {
			cursor = 0;
		}
	}
}

//選択画面の横カーソルの移動
//左右の操作以外はここに書かない
void SelectWindow_LR() {

	if (button[KEY_LEFT] % 15 == 1) {
		//(efs_select);//選択の効果音
		if (cursor_LR > 0) {
			cursor_LR--;
		}
		else {
			cursor_LR = N_o_i_LR - 1;
		}
	}
	if (button[KEY_RIGHT] % 15 == 1) {
		//EffectSound(efs_select);//選択の効果音
		if (cursor_LR < N_o_i_LR - 1) {
			cursor_LR++;
		}
		else {
			cursor_LR = 0;
		}
	}
}

