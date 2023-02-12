#include"DxLib.h"
#include"extern.h"
#include"function.h"

//クリア画面の表示
void clear() {
	if (button[KEY_JUMP] == 1) {	//決定ボタンが押されたら画面を変える
		//通常モード
		if (mapload % 1000 == 441)	//最後のステージならタイトル画面に戻る
			change_flag(e_title);
		else {
			//ステージ変更はフラグを変えてから行う
			//ここで変えると一瞬オールクリアが表示されてしまう
			change_flag(e_gameplay);
		}
	}
}
