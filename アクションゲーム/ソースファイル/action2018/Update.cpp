#include"DxLib.h"
#include"extern.h"
#include"function.h"

void update() {
	
	switch (flag) {
	case e_title:
		title();
		break;

	case e_stage_select:
		stage_select();
		break;

	case e_difficulty_select:
		difficulty_select();
		break;

	case e_gameplay:
		playUpdate();	//ゲームプレイ中のアップデート処理
		break;

	case e_clear:
		clear();
		break;

	case e_gameover:
		gameover();
		break;

	case e_pause:
		pause();
		break;

		/*case e_option:
			option();
			break;*/

	case e_keyconfig:
		//keyconfig();
		break;

		//case e_soundtest:
		//	soundtest();
		//	break;
	}
}
