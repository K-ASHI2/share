#include"DxLib.h"
#include"extern.h"
#include"Music.h"

void CMusic::playMusic(int SoundHandle, int PlayType, int TopPositionFlag)
{
	//�����t���̋ȂƓ����Ȃ�炻���Ƃ�����ŏ�����ɂ��Ȃ�
	if (SoundHandle == playingMusic)
		return;

	//�����t���̉��y���~�߂�
	StopSoundMem(playingMusic);

	playingMusic = SoundHandle;

	//���y��炷
	PlaySoundMem(SoundHandle, PlayType, TopPositionFlag);

	//�ŏ������炷���͖炵������CheckMusic�ŏI����Ă�����playsoundmem�ő����𗬂�
}

//���j���[��ʂ̋Ȃ𗬂�
void CMusic::playMenu()
{
	playMusic(menu);
}
