#include"DxLib.h"
#include"function.h"
#include"extern.h"

//キーボードとゲームパッドの入力の初期化
void init_key() {
	for (int i = 0; i < 256; i++) {
		Key[i] = 0;
	}
	for (int i = 0; i < 28; i++) {
		Pad[i] = 0;
	}

}

//ゲームパッドのキーコンフィグの初期化
//ゲームループ開始前とコンフィグのリセットで呼び出す
void init_key_p() {
	key_p[KEY_DOWN] = PAD_DOWN;
	key_p[KEY_LEFT] = PAD_LEFT;
	key_p[KEY_RIGHT] = PAD_RIGHT;
	key_p[KEY_UP] = PAD_UP;
	key_p[KEY_JUMP] = PAD_A;
	key_p[KEY_ATTACK] = PAD_X;
	key_p[KEY_PAUSE] = PAD_START;

	cPad[KEY_DOWN] = "PAD_DOWN";
	cPad[KEY_LEFT] = "PAD_LEFT";
	cPad[KEY_RIGHT] = "PAD_RIGHT";
	cPad[KEY_UP] = "PAD_UP";
	cPad[KEY_JUMP] = "PAD_A";
	cPad[KEY_ATTACK] = "PAD_X";
	cPad[KEY_PAUSE] = "PAD_START";
}
