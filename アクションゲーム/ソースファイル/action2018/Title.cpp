#include"DxLib.h"
#include"extern.h"
#include"function.h"

void title() {

	select_window();
	if (button[KEY_ATTACK] == 1) {	//キャンセル
		cursor = N_o_i - 1;			//カーソルを一番下にする
	}
	if (button[KEY_JUMP] == 1) {	//決定
		efs(efs_decision);//決定の効果音
		switch (cursor) {
		case 0:		//ゲームスタート(ステージ選択)
			change_flag(e_stage_select);
			break;
		//case 1:		//ステージ作成
		//	mode_flag = em_createStage;
		//	change_flag(e_stage_select);
		//	break;
		//case 2:		//作成されたステージの選択
		//	mode_flag = em_play_cs;
		//	change_flag(e_stage_select);
		//	break;
		case 1:	mode_flag = em_end; break;
		}
	}
}
