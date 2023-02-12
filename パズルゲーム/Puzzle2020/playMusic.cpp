#include"DxLib.h"
#include"extern.h"
#include"Music.h"

void CMusic::playMusic(int SoundHandle, int PlayType, int TopPositionFlag)
{
	//今演奏中の曲と同じ曲を鳴らそうとしたら最初からにしない
	if (SoundHandle == playingMusic)
		return;

	//今演奏中の音楽を止める
	StopSoundMem(playingMusic);

	playingMusic = SoundHandle;

	//音楽を鳴らす
	PlaySoundMem(SoundHandle, PlayType, TopPositionFlag);

	//最初だけ鳴らす音は鳴らしたあとCheckMusicで終わっていたらplaysoundmemで続きを流す
}

//メニュー画面の曲を流す
void CMusic::playMenu()
{
	playMusic(menu);
}
