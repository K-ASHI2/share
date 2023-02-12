#include"DxLib.h"
#include"extern.h"
#include"function.h"

//ゲームオーバー画面の表示
void gameover() {

	if (button[KEY_JUMP] == 1) {	//決定ボタンが押されたらゲームプレイ画面に戻る
		change_flag(e_gameplay);
	}
}
