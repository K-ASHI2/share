#include"DxLib.h"
#include"extern.h"
#include"function.h"

//自機の弾が敵に当たった時の判定

void judge_playerbullet_to_enemy() {

	for (int i = 0; i < ENEMY; i++) {
		if (enemy[i].hp > 0) {
			for (int k = 0; k < BULLET; k++) {
				if (playerbullet[k].hp != 0) {
					//レーザーの判定
					if (playerbullet[k].pbkind == 5 || playerbullet[k].pbkind == 12 || playerbullet[k].pbkind == 13 || playerbullet[k].pbkind == 14) {
						if (judge_laser(playerbullet[k].x, playerbullet[k].y, playerbullet[k].size, enemy[i].x, enemy[i].y, enemy[i].size) == 1) {
							PlayerBulletHitEnemy(i, k);
						}
					}
					//敵に弾が当たる判定は敵のサイズの見た目通りの範囲
					else if (judge(playerbullet[k].x, playerbullet[k].y, playerbullet[k].size, enemy[i].x, enemy[i].y, enemy[i].size)){
						PlayerBulletHitEnemy(i, k);
					}
				}
			}
		}
	}
}

//自機の弾がボスに当たった時の判定
void judge_playerbullet_to_boss() {

	if (boss.muteki == 0) {
		if (boss.hp > 0) {
			for (int k = 0; k < BULLET; k++) {
				if (playerbullet[k].hp != 0) {
					//レーザーの判定
					if (playerbullet[k].pbkind == 5 || playerbullet[k].pbkind == 12 || playerbullet[k].pbkind == 13 || playerbullet[k].pbkind == 14) {
						if (judge_laser(playerbullet[k].x, playerbullet[k].y, playerbullet[k].size, boss.x, boss.y, boss.size) == 1) {
							PlayerBulletHitBoss(k);
						}
					}
					if (judge(playerbullet[k].x, playerbullet[k].y, playerbullet[k].size, boss.x, boss.y, boss.size)) {
						PlayerBulletHitBoss(k);
					}
				}
			}
		}
	}
	else {
		boss.muteki--;
	}
}

//雑魚敵に弾を当てた時の処理 e:敵 pb 自機の弾
void PlayerBulletHitEnemy(int e, int pb) {

	EnemyDamaged(e, playerbullet[pb].atk);
	playerbullet[pb].hp = -1;	//弾を判定だけ消す
	playerbullet[pb].vanish = P_BULLET_BUNISH;
	player.score += 1;	//撃ち込み点
}

//ボスに弾を当てた時の処理 pb 自機の弾
void PlayerBulletHitBoss(int pb) {

	BossDamaged(playerbullet[pb].atk);
	playerbullet[pb].hp = -1;	//弾を判定だけ消す
	playerbullet[pb].vanish = P_BULLET_BUNISH;
	player.score += 100;	//撃ち込み点
}

//雑魚敵がダメージを受ける時の処理
void EnemyDamaged(int e, double d) {

	if (enemy[e].hp > 0) {
		enemy[e].hp -= d;
		if (enemy[e].hp < 0) {
			enemy[e].hp = 0;
		}
		if (enemy[e].hp == 0) {
			enemy[e].vanish = ENEMY_BUNISH;
			//敵に対応したアイテムを出す
			CreateItem(enemy[e].x, enemy[e].y, enemy[e].item);
		}
	}
}

//ボスがダメージを受ける時の処理
void BossDamaged(double d) {

	double d2 = d;

	//ボムバリア
	if (player.bomb_c > 0) {
		if (boss.mode == 7) {
			switch (difficulty) {
			case ed_easy: d2 *= 1.0; break;
			case ed_normal: d2 *= 0.7; break;
			case ed_hard: d2 *= 0.7; break;
			}
		}
		else if (boss.mode == 9) {
			switch (difficulty) {
			case ed_easy: d2 *= 1.0; break;
			case ed_normal: d2 *= 0.7; break;
			case ed_hard: d2 *= 0.5; break;
			}
		}
		else {
			switch (difficulty) {
			case ed_easy: d2 *= 1.0; break;
			case ed_normal: d2 *= 1.0; break;
			case ed_hard: d2 *= 0.8; break;
			}
		}
	}
	if (boss.totalhp > 0) {
		boss.hp -= d2;
		if (boss.hp < 0) {
			boss.hp = 0;
		}
		boss.totalhp -= d2;
		if (boss.totalhp < 0) {
			boss.totalhp = 0;
		}
		if (boss.totalhp == 0) {
			boss.vanish = ENEMY_BUNISH;
			efs(efs_boss_crush);
		}
	}
}

//ボムなど自機の行動で敵の弾が消える時の処理
void RemoveBullet(int eb) {

	enemybullet[eb].hp = 0;
	enemybullet[eb].vanish = E_BULLET_BUNISH;

	int upgauge = 20;

	switch (difficulty) {
	case ed_easy: upgauge = 60; break;
	case ed_normal: upgauge = 30; break;
	case ed_hard: upgauge = 10; break;
	}

	//弾消し時に属性ゲージを貯める
	switch (enemybullet[eb].color) {
	case ebc_blue: player.snowGauge += upgauge; break;
	case ebc_yellow: player.thunderGauge += upgauge; break;
	case ebc_red: player.fireGauge += upgauge; break;
	default: break;
	}
}

//ボスの形態変化で敵の弾が消える時の処理
void RemoveBullet2(int eb) {

	enemybullet[eb].hp = 0;
	enemybullet[eb].vanish = E_BULLET_BUNISH;

	int upgauge = 0;

	switch (difficulty) {
	case ed_easy: upgauge = 30; break;
	case ed_normal: upgauge = 15; break;
	case ed_hard: upgauge = 5; break;
	}

	//弾消し時に属性ゲージを貯める
	switch (enemybullet[eb].color) {
	case ebc_blue: player.snowGauge += upgauge; break;
	case ebc_yellow: player.thunderGauge += upgauge; break;
	case ebc_red: player.fireGauge += upgauge; break;
	default: break;
	}
}
