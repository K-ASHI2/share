#include"DxLib.h"
#include"extern.h"
#include"function.h"

void UpdateKey() {//キーとパッドが何フレーム押されていたか更新する

	char tmpKey[256];
	GetHitKeyStateAll(tmpKey);
	for (int i = 0; i < 256; i++) {
		if (tmpKey[i] != 0) {
			if (Key[i] != INT_MAX) {//int型の最大を超えないようにする
				Key[i]++;
			}
		}
		else {
			Key[i] = 0;
		}
	}
	int Pad1;
	Pad1 = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	for (int i = 0; i < 28; i++) {//入力状態は28ビットで表される
		if (Pad1 & (1 << i)) {//iビットずらす
			if (Pad[i] != INT_MAX) {//int型の最大を超えないようにする
				Pad[i]++;
			}
		}
		else {
			Pad[i] = 0;
		}
	}
	//ゲーム中で使用する7つのボタンのフレーム数を数える
	if (Key[KEY_INPUT_DOWN] || Pad[key_p[KEY_DOWN]]) {
		button[KEY_DOWN]++;
	}
	else {
		button[KEY_DOWN] = 0;
	}
	if (Key[KEY_INPUT_LEFT] || Pad[key_p[KEY_LEFT]]) {
		button[KEY_LEFT]++;
	}
	else {
		button[KEY_LEFT] = 0;
	}
	if (Key[KEY_INPUT_RIGHT] || Pad[key_p[KEY_RIGHT]]) {
		button[KEY_RIGHT]++;
	}
	else {
		button[KEY_RIGHT] = 0;
	}
	if (Key[KEY_INPUT_UP] || Pad[key_p[KEY_UP]]) {
		button[KEY_UP]++;
	}
	else {
		button[KEY_UP] = 0;
	}

	//キーコンフィグで変化するボタン
	if (Key[KEY_INPUT_Z] || Pad[key_p[KEY_JUMP]]) {
		button[KEY_JUMP]++;
	}
	else {
		button[KEY_JUMP] = 0;
	}
	if (Key[KEY_INPUT_X] || Pad[key_p[KEY_ATTACK]]) {
		button[KEY_ATTACK]++;
	}
	else {
		button[KEY_ATTACK] = 0;
	}
	if (Key[KEY_INPUT_SPACE] || Pad[key_p[KEY_PAUSE]]) {
		button[KEY_PAUSE]++;
	}
	else {
		button[KEY_PAUSE] = 0;
	}
}
