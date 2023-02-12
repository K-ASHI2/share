#include"DxLib.h"
#include"extern.h"
#include"function.h"

void pause(void) {

	select_window();
	//キャンセル
	if (button[KEY_ATTACK] == 1 || button[KEY_PAUSE] == 1) {
		efs(efs_back);
		change_flag(e_gameplay);
	}
	if (button[KEY_JUMP] == 1) {
		efs(efs_decision);
		if (mode_flag == em_normal) {	//ステージ作成中でないなら
			switch (cursor) {
			case 0:
				change_flag(e_gameplay);
				break;
			case 1:
				change_flag(e_stage_select);
				break;
			case 2:
				change_flag(e_title);
				break;
			}
		}
	}
}
