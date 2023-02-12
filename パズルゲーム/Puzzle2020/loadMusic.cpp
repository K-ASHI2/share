#include"DxLib.h"
#include"extern.h"
#include"function.h"
#include"music.h"

//âπäyÇÃÉçÅ[Éh
void CMusic::loadMusic()
{
	menu = LoadSoundMem("music/1.wav");
	stage_1_1 = LoadSoundMem("music/1-1.wav");
	stage_1_2 = LoadSoundMem("music/1-2.wav");
	stage_2_2 = LoadSoundMem("music/2-2.wav");
	
	/*å¯â âπ*/
	draw = LoadSoundMem("music/draw.wav");
	vanish = LoadSoundMem("music/vanish.wav");
	pause = LoadSoundMem("music/pause.wav");
	select = LoadSoundMem("music/select.wav");
	back = LoadSoundMem("music/back.wav");
	decision = LoadSoundMem("music/decision.wav");
	result = LoadSoundMem("music/result.wav");
}
