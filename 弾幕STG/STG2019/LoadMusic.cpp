#include"DxLib.h"
#include"extern.h"
#include"function.h"

//音楽のロード
void LoadMusic() {

	music.menu = LoadSoundMem("music/menu.wav");
	music.stage_1_1 = LoadSoundMem("music/1-1.wav");
	music.stage_1_2 = LoadSoundMem("music/1-2.wav");
	music.stage_2_1 = LoadSoundMem("music/2-1.wav");
	music.stage_2_2 = LoadSoundMem("music/4-2.wav");
	music.stage_3_1 = LoadSoundMem("music/3-1.wav");
	music.stage_3_2 = LoadSoundMem("music/3-2.wav");
	music.stage_4_1 = LoadSoundMem("music/4-1.wav");
	music.stage_4_2 = LoadSoundMem("music/2-2.wav");
	music.stage_e_1 = LoadSoundMem("music/e-1.wav");
	music.stage_e_2 = LoadSoundMem("music/e-2.wav");
	
	/*効果音*/
	music.damage = LoadSoundMem("music/damage.wav");
	music.pause = LoadSoundMem("music/pause2.wav");
	music.clear = LoadSoundMem("music/clear.wav");
	music.bomb = LoadSoundMem("music/boss_shot.wav");
	music.fire = LoadSoundMem("music/fire.wav");
	music.select = LoadSoundMem("music/select.wav");
	music.gameover = LoadSoundMem("music/gameover.wav");
	music.recover = LoadSoundMem("music/recover.wav");
	music.back = LoadSoundMem("music/back.wav");
	music.decision = LoadSoundMem("music/decision.wav");
	music.result = LoadSoundMem("music/result.wav");
	music.p_bomb = LoadSoundMem("music/p_bomb.wav");
	music.boss_crush = LoadSoundMem("music/boss_crush.wav");

	//音量の調節の初期化
	ChangeVolumeSoundMem(255 * 70 / 100, music.bomb);

	//ループ位置をセットする
	//SetLoopPosSoundMem(20000, music.stage_1_1);

}
