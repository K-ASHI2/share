#include"DxLib.h"
#include"extern.h"
#include"function.h"

//music�̔z��̓Y����
//�O������Ăяo���ƃo�O��̂ŗǂ��Ȃ����A��Ɨʂ����炷���߂ɗp���Ă���
static int mi;

//�X�e�[�W�Ŏg�����y�̃��[�h
void LoadMusic() {

	mi = 0;
	SetMusic("music/newmusic/����.wav");
	SetMusic("music/newmusic/���A.wav");
	SetMusic("music/newmusic/�X.wav");
	SetMusic("music/newmusic/��.wav");
	SetMusic("music/newmusic/�{�X��O.wav");
	SetMusic("music/newmusic/�p��.wav");
	SetMusic("music/newmusic/1-3(arranged).wav");
	SetMusic("music/newmusic/3-2(arranged).wav");
	SetMusic("music/newmusic/1-1.wav");
	SetMusic("music/newmusic/1-2.wav");
	SetMusic("music/newmusic/2-1-1.wav");
	SetMusic("music/newmusic/2-1-2.wav");
	SetMusic("music/newmusic/2-1-3.wav");
	SetMusic("music/newmusic/2-2.wav");
	SetMusic("music/newmusic/3-1.wav");
	SetMusic("music/newmusic/3-2.wav");
	SetMusic("music/newmusic/4-1.wav");
	SetMusic("music/newmusic/ex.wav");

	SetMusic("music/�X�e�[�W1.wav");	//1-1
	SetMusic("music/stage7.wav");		//1-2
	SetMusic("music/stage1.wav");		//1-4,3-4
	SetMusic("music/�X�e�[�W4.wav");	//�{�X��
	SetMusic("music/�X�e�[�W2.wav");	//3-2,4-1

										//���ʂ̒��߂̏�����
	ChangeVolumeSoundMem(255 * 60 / 100, s_music[1]);
}

//���y�̃Z�b�g
void SetMusic(char *FileName) {

	s_music[mi++] = LoadSoundMem(FileName);
}

//���y�̃��[�h
void Music() {

	//�X�e�[�W�Ŏg�����y�̃��[�h
	LoadMusic();

	//���y
	music.menu = LoadSoundMem("music/���j���[ 1.wav");		//�^�C�g���Ȃǂ̃��j���[

	//���ʉ�
	music.attack = LoadSoundMem("music/sward.wav");
	music.attack2 = LoadSoundMem("music/sward2.wav");
	music.damage = LoadSoundMem("music/damage.wav");
	music.pause = LoadSoundMem("music/pause2.wav");
	music.jump = LoadSoundMem("music/jump.wav");
	music.clear = LoadSoundMem("music/clear.wav");
	music.bomb = LoadSoundMem("music/bomb.wav");
	music.fire = LoadSoundMem("music/fire.wav");
	music.select = LoadSoundMem("music/select.wav");
	music.gameover = LoadSoundMem("music/gameover.wav");
	music.recover = LoadSoundMem("music/recover.wav");
	music.back = LoadSoundMem("music/back.wav");
	music.decision = LoadSoundMem("music/decision.wav");
	music.sw = LoadSoundMem("music/sw.wav");
	music.shot = LoadSoundMem("music/boss_shot.wav");
	//���ʂ̒��߂̏�����
	ChangeVolumeSoundMem(255 * 90 / 100, music.attack);
	ChangeVolumeSoundMem(255 * 90 / 100, music.attack2);
	ChangeVolumeSoundMem(255 * 60 / 100, music.pause);
	ChangeVolumeSoundMem(255 * 60 / 100, music.jump);
	ChangeVolumeSoundMem(255 * 60 / 100, music.bomb);
	ChangeVolumeSoundMem(255 * 50 / 100, music.fire);
	ChangeVolumeSoundMem(255 * 50 / 100, music.select);
	ChangeVolumeSoundMem(255 * 60 / 100, music.recover);
	ChangeVolumeSoundMem(255 * 60 / 100, music.decision);
	ChangeVolumeSoundMem(255 * 60 / 100, music.sw);
}
