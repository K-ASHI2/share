#include"extern.h"
#include"function.h"
#include <vector>

//ステージ開始時の初期化
void init(){

	if (mode_flag == em_score_attack)
	{
		player1.init(e_1p);
		timelimit = (60 + 1) * 60 - 1;	//時間制限を60秒にする
	}
	else
	{
		timeCount = 0;
		player1.init(e_1p);
		player2.init(e_2p);
	}
	keyPad.init_key();

	//クリア画面のテスト用
	//timelimit = 1 * 60;

	music.stageMusic();	//ステージに対応した音楽を鳴らす
	clear_count = 0;
	hiscore_flag = false;
}
