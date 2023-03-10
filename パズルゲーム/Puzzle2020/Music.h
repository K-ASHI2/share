#pragma once
#include "DxLib.h"
#include "enum.h"

class CMusic
{
private:
	//音楽
	int stage_1_1;
	int stage_1_2;
	int stage_2_2;
	int menu;

	//効果音
	int draw;
	int vanish;
	int pause;
	int select;
	int decision;
	int back;
	int result;

	//現在の演奏している曲
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
