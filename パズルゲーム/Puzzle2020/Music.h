#pragma once
#include "DxLib.h"
#include "enum.h"

class CMusic
{
private:
	//���y
	int stage_1_1;
	int stage_1_2;
	int stage_2_2;
	int menu;

	//���ʉ�
	int draw;
	int vanish;
	int pause;
	int select;
	int decision;
	int back;
	int result;

	//���݂̉��t���Ă����
	int playingMusic = -1;

public:
	CMusic();
	~CMusic();
	int getPlayingMusic();
	void efs(e_effectSound e);
	void playMusic(int SoundHandle, int PlayType = DX_PLAYTYPE_LOOP, int TopPositionFlag = TRUE);
	void stageMusic();
	void playMenu();
	void loadMusic();
};
