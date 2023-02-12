#include"extern.h"
#include"function.h"

void init_p() {

	player.x = G_W_LEFT + (G_W_RIGHT - G_W_LEFT) / 2;
	player.y = G_W_LOWER - 20;
	player.vx = 0;
	player.vy = 0;
	if (boss.mode_p == 0) {
		switch (difficulty) {
		case ed_easy: player.life = FIRST_LIFE; break;
		case ed_normal: player.life = FIRST_LIFE; break;
		case ed_hard: player.life = FIRST_LIFE; break;
		}
		player.bomb = 0;
		playerBombInit();
	}
	else {
		player.life = 1;
		player.bomb = 0;
	}
	player.muteki = 0;
	player.inope = 0;
	player.bomb_c = 0;
	player.damaged = 0;
	player.power = 3.0;
	player.size = 4;	//判定の半径の大きさ
	//player.grazeSize = GRAZESIZE;
	//グレイズの大きさを大きめに取る
	player.grazeSize = GRAZESIZE;
	player.graze = 0;
	player.t = 0;
	player.score = 0;
	//得点アイテムの最高点
	switch (difficulty) {
	case ed_easy: player.maxscore = 10000; break;
	case ed_normal: player.maxscore = 20000; break;
	case ed_hard: player.maxscore = 50000; break;
	}
	player.d_effect = 0;
	player.damaged_x = 0;
	player.damaged_y = 0;
	player.slow_move = 0;
	player.bomb_x = 0;
	player.bomb_y = 0;

	player.snowGauge = 0;		//雪のゲージ
	player.thunderGauge = 0;	//電気のゲージ
	player.fireGauge = 0;		//炎のゲージ

	player.snowMode = false;
	player.thunderMode = false;
	player.fireMode = false;

	//主人公ごとに変更する能力
	switch (player.character) {
	case player.D_Magician_A:
		player.bomb_t = 180;
		player.size = 3.5;
		break;
	case player.D_Magician_B:
		player.bomb_t = 280;
		player.size = 3.5;
		break;
	case player.L_Magician_A:
		player.bomb_t = 360;
		break;
	case player.L_Magician_B:
		player.bomb_t = 90;
		break;
	}

	for (int i = 0; i < BULLET; i++) {
		playerbullet[i].hp = 0;
		playerbullet[i].x = 0;
		playerbullet[i].y = 0;
		playerbullet[i].vx = 0;
		playerbullet[i].vy = 0;
		playerbullet[i].atk = 0;
		playerbullet[i].size = 16;
		playerbullet[i].vanish = 0;
		playerbullet[i].pbkind = 0;
		playerbullet[i].t = 0;
	}
}

//プレイヤーのボム数の初期化
void playerBombInit() {


	static int firstBomb = 0;
	//機体によってボム数を変える
	switch (player.character) {
	case player.D_Magician_A:
		firstBomb = 3;
		break;
	case player.D_Magician_B:
		firstBomb = 4;
		break;
	case player.L_Magician_A:
		firstBomb = 2;
		break;
	case player.L_Magician_B:
		firstBomb = 5;
		break;
	}

	if (player.bomb < firstBomb) {
		player.bomb = firstBomb;
	}
}
