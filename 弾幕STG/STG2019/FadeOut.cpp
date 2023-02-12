#include"DxLib.h"
#include"extern.h"
#include"function.h"

//フェードアウト
void FadeOut() {

	bright -= 32;
	if (bright <= 0) {
		bright = 0;
		ChangeFlag2(changeFlag_flag, changeFlag_cursor, changeFlag_cursor2);
		fade_flag = ef_fadeIn;
	}
	SetDrawBright(bright, bright, bright);
}

//フェードイン
void FadeIn() {

	bright += 32;
	if (bright >= 256) {
		bright = 256;
		fade_flag = ef_normal;
		//中断した音楽があり、再開するなら
		if (PlaybackFlag == 1) {
			//止めていた曲を途中から再生する
			PlaySoundMem(p_music, DX_PLAYTYPE_LOOP, FALSE);
			PlaybackFlag = 0;
		}
		//中断した曲を最初から流すなら
		else if (PlaybackFlag == 2) {
			//止めていた曲を最初から再生する
			PlaySoundMem(p_music, DX_PLAYTYPE_LOOP, TRUE);
			PlaybackFlag = 0;
		}
	}
	SetDrawBright(bright, bright, bright);
}
