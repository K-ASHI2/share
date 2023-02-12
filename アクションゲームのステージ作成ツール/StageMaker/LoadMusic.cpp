#include"DxLib.h"
#include"extern.h"
#include"function.h"

//musicの配列の添え字
//外部から呼び出すとバグるので良くないが、作業量を減らすために用いている
static int mi;

//音楽のロード
void LoadMusic() {
	
	mi = 0;
	SetMusic("music/newmusic/草原.wav");
	SetMusic("music/newmusic/洞窟.wav");
	SetMusic("music/newmusic/森.wav");
	SetMusic("music/newmusic/城.wav");
	SetMusic("music/newmusic/ボス戦前.wav");
	SetMusic("music/newmusic/廃墟.wav");
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

	SetMusic("music/ステージ1.wav");	//1-1
	SetMusic("music/stage7.wav");		//1-2
	SetMusic("music/stage1.wav");		//1-4,3-4
	SetMusic("music/ステージ4.wav");	//ボス戦
	SetMusic("music/ステージ2.wav");	//3-2,4-1

	//音量の調節の初期化
	ChangeVolumeSoundMem(255 * 60 / 100, music[1]);
}

//音楽のセット
void SetMusic(char *FileName) {

	music[mi++] = LoadSoundMem(FileName);
}