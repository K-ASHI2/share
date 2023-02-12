#include"DxLib.h"
#include"extern.h"
#include"function.h"

//引数mに対応した音楽を鳴らす
//loop : 1ならループし、それ以外ならループしない デフォルト引数 1
void PlayMusic(int m, int loop) {

	//今演奏中の曲と同じ曲を鳴らそうとしたら最初からにしない
	if (m == p_music)
		return;

	//今演奏中の音楽を止める
	StopSoundMem(p_music);

	p_music = m;

	//音楽を鳴らす
	if (loop == 1) {
		PlaySoundMem(m, DX_PLAYTYPE_LOOP);
	}
	else {
		PlaySoundMem(m, DX_PLAYTYPE_BACK);
	}
}

//背景によって決められた音楽を鳴らす
void PM_Number () {

	PlayMusic(music[music_n]);
}
