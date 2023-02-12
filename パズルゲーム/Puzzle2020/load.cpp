#include"DxLib.h"
#include"extern.h"
#include"function.h"

//���[�h
void load()
{
	SetDXArchiveKeyString("DrDrT");
	//�摜�̃��[�h
	loadImage();

	//���y�̃��[�h
	music.loadMusic();

	//�n�C�X�R�A�̃��[�h
	loadHiscore();
}

//�摜�����[�h����֐�
void loadImage()
{	
	//���j���[�֘A�̉摜
	img.clear_frame = LoadGraph("img/menu/clear_frame.png");
	img.win_frame = LoadGraph("img/menu/win_frame.png");
	img.title = LoadGraph("img/menu/title.png");
	img.frame = LoadGraph("img/menu/frame.png");
	img.HPbar = LoadGraph("img/menu/HPbar.png");
	img.HPbar2 = LoadGraph("img/menu/HPbar2.png");
	img.comboFrame = LoadGraph("img/menu/comboFrame.png");

	/*�u���b�N*/
	img.blockCursor = LoadGraph("img/block/blockCursor.png");
	img.blueCursor = LoadGraph("img/block/blueCursor.png");
	img.redCursor = LoadGraph("img/block/redCursor.png");
	img.greenCursor = LoadGraph("img/block/greenCursor.png");
	img.yellowCursor = LoadGraph("img/block/yellowCursor.png");
	img.purpleCursor = LoadGraph("img/block/purpleCursor.png");
	//img.nextFrame = LoadGraph("img/block/nextFrame.png");
	img.nextFrame1 = LoadGraph("img/block/nextFrame1.png");
	img.nextFrame2 = LoadGraph("img/block/nextFrame2.png");
	img.blueblock = LoadGraph("img/block/blueblock.png");
	img.redblock = LoadGraph("img/block/redblock.png");
	img.greenblock = LoadGraph("img/block/greenblock.png");
	img.yellowblock = LoadGraph("img/block/yellowblock.png");
	img.purpleblock = LoadGraph("img/block/purpleblock.png");
	img.whiteblock = LoadGraph("img/block/whiteblock.png");
	img.backBlock = LoadGraph("img/block/backBlock.png");

	img.cross = LoadGraph("img/block/cross.png");

	LoadDivGraph("img/effect/starBomb.png", 180, 13, 14, 511, 511, img.starBomb);
	LoadDivGraph("img/effect/bulletvanish.png", 30, 5, 6, 64, 64, img.BalletVanish);
	LoadDivGraph("img/effect/redbulletvanish.png", 30, 5, 6, 64, 64, img.RedBalletVanish);
	LoadDivGraph("img/effect/bluebulletvanish.png", 30, 5, 6, 64, 64, img.BlueBalletVanish);
	LoadDivGraph("img/effect/yellowbulletvanish.png", 30, 5, 6, 64, 64, img.YellowBalletVanish);
	LoadDivGraph("img/effect/greenbulletvanish.png", 30, 5, 6, 64, 64, img.GreenBalletVanish);
	LoadDivGraph("img/effect/enemyvanish1.png", 30, 5, 6, 80, 80, img.EnemyVanish1);
	LoadDivGraph("img/effect/enemyvanish2.png", 30, 5, 6, 80, 80, img.EnemyVanish2);
	LoadDivGraph("img/effect/enemyvanish3.png", 30, 5, 6, 80, 80, img.EnemyVanish3);
	LoadDivGraph("img/effect/enemyvanish4.png", 30, 5, 6, 80, 80, img.EnemyVanish4);
	LoadDivGraph("img/effect/enemyvanish5.png", 30, 5, 6, 80, 80, img.EnemyVanish5);
	LoadDivGraph("img/effect/playerdameged.png", 80, 8, 10, 128, 128, img.playerdamaged);
}
