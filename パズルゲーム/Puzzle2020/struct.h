#pragma once
#include"define.h"

//�摜�̍\����
struct _img {
	int clear_frame;
	int win_frame;
	int title;
	int frame;
	int HPbar;
	int HPbar2;
	int comboFrame;
	//int nextFrame;
	int nextFrame1;
	int nextFrame2;

	/*�J�[�\��*/
	int blockCursor;
	int blueCursor;
	int redCursor;
	int greenCursor;
	int yellowCursor;
	int purpleCursor;

	/*�u���b�N*/
	int blueblock;
	int redblock;
	int greenblock;
	int yellowblock;
	int purpleblock;
	int whiteblock;
	int backBlock;

	int cross;

	/*�G�t�F�N�g*/
	int starBomb[180];
	int BalletVanish[30];
	int RedBalletVanish[30];
	int BlueBalletVanish[30];
	int YellowBalletVanish[30];
	int GreenBalletVanish[30];
	int EnemyVanish1[30];
	int EnemyVanish2[30];
	int EnemyVanish3[30];
	int EnemyVanish4[30];
	int EnemyVanish5[30];
	int playerdamaged[80];
};
