#include"DxLib.h"
#include"extern.h"
#include"function.h"

//�t�F�[�h�A�E�g
void FadeOut() {
	bright -= 32;
	if (bright <= 0) {
		bright = 0;
		ChangeFlag2(changeFlag_flag, changeFlag_cursor, changeFlag_cursor2);
		fade_flag = ef_fadeIn;
	}
	SetDrawBright(bright, bright, bright);
}

//�t�F�[�h�C��
void FadeIn() {
	bright += 32;
	if (bright >= 256) {
		bright = 256;
		fade_flag = ef_normal;
	}
	SetDrawBright(bright, bright, bright);
}
