#include"DxLib.h"
#include"extern.h"
#include"function.h"

//music�̔z��̓Y����
//�O������Ăяo���ƃo�O��̂ŗǂ��Ȃ����A��Ɨʂ����炷���߂ɗp���Ă���
static int mi;

//���y�̃��[�h
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
	ChangeVolumeSoundMem(255 * 60 / 100, music[1]);
}

//���y�̃Z�b�g
void SetMusic(char *FileName) {

	music[mi++] = LoadSoundMem(FileName);
}