#include"DxLib.h"
#include"extern.h"
#include"function.h"

//����SoundHandle�ɑΉ��������y��炷
//PlayType : 1�Ȃ烋�[�v���A����ȊO�Ȃ烋�[�v���Ȃ� �f�t�H���g���� 1
//TopPositionFlag : TRUE�Ȃ�ŏ�����AFALSE�Ȃ�r������Đ����� �f�t�H���g���� TRUE
void PlayMusic(int SoundHandle, int PlayType, int TopPositionFlag) {

	//�����t���̋ȂƓ����Ȃ�炻���Ƃ�����ŏ�����ɂ��Ȃ�
	if (SoundHandle == p_music)
		return;

	//�����t���̉��y���~�߂�
	StopSoundMem(p_music);

	p_music = SoundHandle;

	//���y��炷
	PlaySoundMem(SoundHandle, PlayType, TopPositionFlag);

	//�ŏ������炷���͖炵������CheckMusic�ŏI����Ă�����playsoundmem�ő����𗬂�
}

//�X�e�[�W�����݂̃��[���h��1�ڂ̃X�e�[�W�ɂ���
void WorldStage() {

	switch (world) {
	case ew_1: stage = es_1_1; break;
	case ew_2: stage = es_2_1; break;
	case ew_3: stage = es_3_1; break;
	case ew_4: stage = es_4_1; break;
	case ew_extra: stage = es_e_1; break;
	}
}
