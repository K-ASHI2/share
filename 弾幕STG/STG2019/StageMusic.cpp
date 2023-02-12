#include"DxLib.h"
#include"extern.h"
#include"function.h"

//ステージに対応した音楽を鳴らす
void StageMusic() {

	switch (stage) {
	case es_1_1: PlayMusic(music.stage_1_1); break;
	case es_1_2: PlayMusic(music.stage_1_2); break;
	case es_2_1:PlayMusic(music.stage_2_1); break;
	case es_2_2:PlayMusic(music.stage_2_2); break;
	case es_3_1:PlayMusic(music.stage_3_1); break;
	case es_3_2:PlayMusic(music.stage_3_2); break;
	case es_4_1:PlayMusic(music.stage_4_1); break;
	case es_4_2:PlayMusic(music.stage_4_2); break;
	case es_e_1:PlayMusic(music.stage_e_1); break;
	case es_e_2:PlayMusic(music.stage_e_2); break;
	}
}
