#include"DxLib.h"
#include"extern.h"
#include"function.h"

//musicの配列の添え字
//外部から呼び出すとバグるので良くないが、作業量を減らすために用いている
static int mi;

//ステージで使う音楽のロード
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
	ChangeVolumeSoundMem(255 * 60 / 100, s_music[1]);
}

//音楽のセット
void SetMusic(char *FileName) {

	s_music[mi++] = LoadSoundMem(FileName);
}

//音楽のロード
void Music() {

	//ステージで使う音楽のロード
	LoadMusic();

	//音楽
	music.menu = LoadSoundMem("music/メニュー 1.wav");		//タイトルなどのメニュー

	//効果音
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
	//音量の調節の初期化
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
