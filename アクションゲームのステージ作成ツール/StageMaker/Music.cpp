#include"DxLib.h"
#include"extern.h"
#include"function.h"

//����m�ɑΉ��������y��炷
//loop : 1�Ȃ烋�[�v���A����ȊO�Ȃ烋�[�v���Ȃ� �f�t�H���g���� 1
void PlayMusic(int m, int loop) {

	//�����t���̋ȂƓ����Ȃ�炻���Ƃ�����ŏ�����ɂ��Ȃ�
	if (m == p_music)
		return;

	//�����t���̉��y���~�߂�
	StopSoundMem(p_music);

	p_music = m;

	//���y��炷
	if (loop == 1) {
		PlaySoundMem(m, DX_PLAYTYPE_LOOP);
	}
	else {
		PlaySoundMem(m, DX_PLAYTYPE_BACK);
	}
}

//�w�i�ɂ���Č��߂�ꂽ���y��炷
void PM_Number () {

	PlayMusic(music[music_n]);
}
