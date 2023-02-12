#include "DxLib.h"
#include "extern.h"
#include "Music.h"

//ステージに対応した音楽を鳴らす
//現状では一ステージでランダム再生する仕様
void CMusic::stageMusic()
{
	//3曲からランダム再生する
	const int r = GetRand(2);
	switch (r)
	{
	case 0:	playMusic(stage_1_1); break;
	case 1:	playMusic(stage_1_2); break;
	case 2:	playMusic(stage_2_2); break;
	}
}
