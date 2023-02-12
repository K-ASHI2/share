#include"DxLib.h"
#include"extern.h"
#include"function.h"

//ボスが出現するフレームになったら画面外から出てくる
void CreateBoss() {

	boss.x = G_W_LEFT + (G_W_RIGHT - G_W_LEFT) / 2;
	boss.y = 0;
	boss.t = 0;
	boss.size = 25;
	boss.maxhp = 0;
	boss.hp = boss.maxhp;
	boss.totalhp = 0;
	boss.maxtotalhp = 0;
	if (boss.mode_p != 0) {
		//ステージ開始時の初期化で1を足すのでここで1を引く
		boss.mode = boss.mode_p - 1;
		boss.maxtotalhp = 1;
		boss.totalhp = 1;
	}
	else {
		boss.mode = 0;
	}
	boss.modechange = 1;

	boss_flag = eb_boss;
	boss.appear = 80;	//ボスを画面上からhpを上昇させつつ出現させる
	boss.muteki = 80;

	//全ての敵と敵の弾を消す
	//消滅エフェクトを出したいのでhp分のダメージを与える
	for (int i = 0; i < ENEMY; i++) {
		if (enemy[i].hp > 0) {
			EnemyDamaged(i, enemy[i].hp);
		}
	}
	for (int i = 0; i < ENEMYBULLET; i++) {
		if (enemybullet[i].hp > 0)
			RemoveBullet2(i);
	}

	//ステージをボスに変え、音楽を変える
	if (stage == es_1_1) {
		stage = es_1_2;
	}
	else if (stage == es_2_1) {
		stage = es_2_2;
	}
	else if (stage == es_3_1) {
		stage = es_3_2;
	}
	else if (stage == es_4_1) {
		stage = es_4_2;
	}
	else if (stage == es_e_1) {
		stage = es_e_2;
	}
	StageMusic();
}

//ボスの出現
void BossAppear() {

	if (boss.appear > 0) {
		if (boss.hp < boss.maxhp) {
			boss.hp += boss.maxhp / (80 / 2);
		}
		boss.y++;
		boss.appear--;
	}
}
