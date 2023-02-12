#include"DxLib.h"
#include"extern.h"
#include"function.h"

//�t�F�[�h�A�E�g
void fadeOut() {
	bright -= 32;
	if (bright <= 0) {
		bright = 0;
		change_flag2(changeFlag_flag, changeFlag_cursor, changeFlag_cursor2);
		fade_flag = ef_fadeIn;
	}
	SetDrawBright(bright, bright, bright);
}

//�h�A�ړ����̃t�F�[�h�A�E�g
void fadeOut_door() {
	bright -= 32;
	if (bright <= 0) {
		bright = 0;
		door_fade(door_fade_x, door_fade_y);
		fade_flag = ef_fadeIn;
	}
	SetDrawBright(bright, bright, bright);
}

//�h�A�ړ����̃t�F�[�h�A�E�g
void fadeOut_door2() {
	bright -= 32;
	if (bright <= 0) {
		bright = 0;
		door_fade2(door_fade_x);
		fade_flag = ef_fadeIn;
	}
	SetDrawBright(bright, bright, bright);
}

//�t�F�[�h�C��
void fadeIn() {
	bright += 32;
	if (bright >= 256) {
		bright = 256;
		fade_flag = ef_normal;
	}
	SetDrawBright(bright, bright, bright);
}
