#include"DxLib.h"
#include"extern.h"
#include"function.h"

//引数SoundHandleに対応した音楽を鳴らす
//PlayType : 1ならループし、それ以外ならループしない デフォルト引数 1
//TopPositionFlag : TRUEなら最初から、FALSEなら途中から再生する デフォルト引数 TRUE
void PlayMusic(int SoundHandle, int PlayType, int TopPositionFlag) {

	//今演奏中の曲と同じ曲を鳴らそうとしたら最初からにしない
	if (SoundHandle == p_music)
		return;

	//今演奏中の音楽を止める
	StopSoundMem(p_music);

	p_music = SoundHandle;

	//音楽を鳴らす
	PlaySoundMem(SoundHandle, PlayType, TopPositionFlag);

	//最初だけ鳴らす音は鳴らしたあとCheckMusicで終わっていたらplaysoundmemで続きを流す
}

//ステージを現在のワールドの1つ目のステージにする
void WorldStage() {

	switch (world) {
	case ew_1: stage = es_1_1; break;
	case ew_2: stage = es_2_1; break;
	case ew_3: stage = es_3_1; break;
	case ew_4: stage = es_4_1; break;
	case ew_extra: stage = es_e_1; break;
	}
}
