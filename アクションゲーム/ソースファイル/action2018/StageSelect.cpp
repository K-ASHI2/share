#include"DxLib.h"
#include"extern.h"
#include"function.h"

//ステージ選択画面
void stage_select() {

	select_window();	//縦カーソルの移動
	select_window_LR();	//横カーソルの移動
	//キャンセル
	if (button[KEY_ATTACK] == 1 || button[KEY_PAUSE] == 1) {
		efs(efs_back);
		//ポーズ画面に戻る時は選択肢の位置を2番目にする
		if(cancel_flag == e_pause)
			change_flag(cancel_flag, 1);
		else
			change_flag(cancel_flag);
	}

	if (button[KEY_JUMP] == 1) {
		efs(efs_decision);
		//縦のカーソルでワールド、横のカーソルでステージを選ぶ
		mapload = (cursor + 1) * 100 + (cursor_LR + 1) * 10 + 1;

		change_flag(e_difficulty_select, 1);
	}
}
