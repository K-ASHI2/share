#include"DxLib.h"
#include"extern.h"
#include"function.h"

void difficulty_select() {	// 0:easy  1:normal  2:hard  -1:キャンセル

	select_window();
	//キャンセルの処理
	if (button[KEY_ATTACK] == 1 || button[KEY_PAUSE] == 1) {
		//maploadの値からステージ選択画面で選択されたステージのカーソルの位置求める
		change_flag(e_stage_select, (mapload - 1) / 100 - 1, (mapload - 1) % 100 / 10 - 1);
	}

	if (button[KEY_JUMP] == 1) {
		efs(efs_decision);
		mapload += cursor * 1000;	//難易度を設定する
		change_flag(e_gameplay);
	}
}
