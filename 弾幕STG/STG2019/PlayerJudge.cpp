#include"DxLib.h"
#include"extern.h"
#include"function.h"

//自機と敵が重なっている時の判定
void judge_player_to_enemy() {

	for (int i = 0; i < ENEMY; i++) {
		if (enemy[i].hp != 0) {
			//被弾判定
			if (judge(player.x, player.y, player.size, enemy[i].x, enemy[i].y, enemy[i].size)) {
				PlayerDamage();
			}
		}
	}
}

//自機とボスが重なっている時の判定
void judge_player_to_boss() {

	if (boss.hp != 0) {
		//被弾判定
		if (judge(player.x, player.y, player.size, boss.x, boss.y, boss.size)) {
			PlayerDamage();
		}
	}
}

//敵の弾が自機に当たった時の判定
void judge_enemybullet_to_player() {

	for (int i = 0; i < BULLET; i++) {
		if (enemybullet[i].hp) {
			//被弾判定(被弾したフレームもグレイズはする)
			if (judge(player.x, player.y, player.size, enemybullet[i].x, enemybullet[i].y, enemybullet[i].size)) {
				RemoveBullet(i);
				PlayerDamage();
				Graze();
			}
			//グレイズ判定
			else if (judge(player.x, player.y, player.size + player.grazeSize, enemybullet[i].x, enemybullet[i].y, enemybullet[i].size) && enemybullet[i].graze == 1) {
				enemybullet[i].graze = 0;

				//グレイズした弾に対応した属性ゲージを追加で貯める(持続延長)
				static int upgauge = 30;
				switch (enemybullet[i].color) {
				case ebc_blue: player.snowGauge += upgauge; break;
				case ebc_yellow: player.thunderGauge += upgauge; break;
				case ebc_red: player.fireGauge += upgauge; break;
				default: break;
				}

				//グレイズのカウントとスコア処理
				//上の処理も含めた方が分かりやすいかも
				Graze();
			}
		}
	}
}

//グレイズ処理
void Graze() {

	player.score += 1000;
	//グレイズ10回ごとに最高点が1000点増える
	//東方では10点だが他に最高点の増加要素がないので大きく設定
	if (++player.graze % 10 == 0) {
		player.maxscore += 1000;
	}
}

//プレイヤーがアイテムと接触している時の判定
void judge_player_to_item() {

	static int size = 8;	//アイテムに対するあたり判定の大きさ
	static int size2 = 50;	//アイテムの低速回収範囲
	for (int i = 0; i < ITEM; i++) {
		if (item[i].hp != 0) {
			//アイテムとプレイヤーが重なっていたら効果を発揮する
			//自機の判定より大きい範囲で判定する
			if (judge(player.x, player.y, player.size, item[i].x, item[i].y, item[i].size + size) == 1){
				switch (item[i].kind) {	//アイテムによって効果を変える
				case 1: player.score += player.maxscore;
					break;
				case 2: player.power += 0.05;
					player.score += 10;
					break;
				case 3: player.power += 0.1;
					player.score += 100;
					break;
				case 4: player.power += 1.0;
					player.score += 1000;
					break;
				}
				item[i].hp = 0;
				if (player.power > 4.0) {
					player.power = 4.0;
				}
			}
			//低速移動中は回収フラグの立っていない近くのアイテムを回収する
			else if (judge(player.x, player.y, player.size, item[i].x, item[i].y, item[i].size + size2) == 1 &&
				player.slow_move == 1 && item[i].collect == 0) {
				item[i].collect = 2;
			}
			//低速回収の範囲外か低速をやめたら回収をやめる
			else if (item[i].collect == 2) {
				item[i].collect = 0;
				item[i].vx = 0;
				item[i].vy = 0;
			}
		}
	}
}

//被弾直後の処理
//被弾後の喰らいボム判定時間にする
void PlayerDamage() {

	if (player.muteki == 0 && player.damaged == 0) {
		//喰らいボムの受け付け時間は8F
		player.damaged = 8 + DAMEGED;	//喰らいボム判定時間の設定 自機ごとに変えられる変数にする
		player.inope = 2;				//喰らいボム判定時間にする
		//被弾した時の効果音を鳴らす
		efs(efs_damage);
	}
}

//被弾後の復活処理
void PlayerDamaged() {

	if (player.damaged > 0) {
		player.damaged--;
		//喰らいボムしなかったなら被弾処理を行う
		if (player.damaged == DAMEGED) {
			player.d_effect = DAMEGED_EFFECT;
			player.damaged_x = player.x;
			player.damaged_y = player.y;
			player.x = G_W_LEFT + (G_W_RIGHT - G_W_LEFT) / 2;
			player.y = G_W_LOWER + 50;
			player.inope = 1;	//被弾処理が終わるまで操作不能にする
			player.muteki = 450;
			player.life--;
			player.power -= 0.5;
			//ボムが減っていたら初期数まで回復
			playerBombInit();
		}
		//一定時間後に画面内の弾を全消去
		else if (player.damaged == DAMEGED_APPEAR + 5) {
			for (int i = 0; i < BULLET; i++) {
				if (enemybullet[i].hp == 1) {
					RemoveBullet(i);
				}
			}
		}
		//出現時間のフレーム以下になったら画面外から出現し始める
		else if (player.damaged < DAMEGED_APPEAR) {
			player.y -= 3;
		}
		//被弾処理が終了したら操作可能にする
		if (player.damaged == 0)
			player.inope = 0;
	}
}
