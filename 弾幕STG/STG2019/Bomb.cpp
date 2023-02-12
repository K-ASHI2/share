#include"DxLib.h"
#include"extern.h"
#include"function.h"

void Bomb() {

	if (player.bomb_c > 0) {

		if (player.bomb_c == player.bomb_t) {
			//ボムを撃った瞬間に存在するアイテムを回収する
			for (int i = 0; i < ITEM; i++) {
				if (item[i].hp != 0) {
					item[i].collect = 1;
				}
			}
			efs(efs_p_bomb);
		}

		//ボムの弾の処理
		double size;
		switch (player.character) {
		case player.D_Magician_A:
			//スーパーノヴァ
			//画面全体の敵にダメージ
			//2.5 * 120 = 300
			if (player.bomb_c < 120) {
				for (int i = 0; i < ENEMY; i++) {
					if (enemy[i].hp > 0) {
						EnemyDamaged(i, 2.5);
					}
				}
				//ボスにダメージ
				BossDamaged(2.5);
			}

			//一定時間後から画面内の弾を全消去
			if (player.bomb_c < 60) {
				for (int i = 0; i < BULLET; i++) {
					if (enemybullet[i].hp > 0) {
						RemoveBullet(i);
					}
				}
			}
			break;

		case player.D_Magician_B:
			//ブラックホール
			//1.0 * 280 = 280
			if (player.bomb_c > 240) {
				size = 5.0 * (240 - player.bomb_c) / 40;
			}
			else if (player.bomb_c > 40) {
				size = 5.0;
			}
			else {
				size = 5.0 * player.bomb_c / 40;
			}
			for (int i = 0; i < ENEMY; i++) {
				if (enemy[i].hp > 0) {
					if (judge(player.bomb_x, player.bomb_y, 50 * size, enemy[i].x, enemy[i].y, enemy[i].size) == 1) {
						EnemyDamaged(i, 1.0);
					}
				}
			}
			if (judge(player.bomb_x, player.bomb_y, 50 * size, boss.x, boss.y, boss.size) == 1) {
				BossDamaged(1.0);
			}
			for (int i = 0; i < BULLET; i++) {
				if (enemybullet[i].hp > 0) {
					if (judge(player.bomb_x, player.bomb_y, 50 * size, enemybullet[i].x, enemybullet[i].y, enemybullet[i].size) == 1) {
						RemoveBullet(i);
					}
				}
			}
			break;

		case player.L_Magician_A:
			//ソーラースパーク
			//1.8 * 300 = 540
			//自機の前方の横160の範囲に判定を付ける
			if (player.bomb_c < 300) {
				for (int i = 0; i < ENEMY; i++) {
					if (enemy[i].hp > 0 && enemy[i].x > player.x - 160 && enemy[i].x < player.x + 160 && enemy[i].y < player.y + player.size) {
						EnemyDamaged(i, 1.8);
					}
				}
			}
			if (boss.hp > 0 && boss.x > player.x - 160 && boss.x < player.x + 160 && boss.y < player.y + player.size) {
				//ボスにダメージ
				BossDamaged(1.8);
			}

			for (int i = 0; i < BULLET; i++) {
				if (enemybullet[i].hp > 0) {
					if (enemybullet[i].x > player.x - 160 && enemybullet[i].x < player.x + 160 && enemybullet[i].y < player.y + player.size) {
						RemoveBullet(i);
					}
				}
			}
			break;
		case player.L_Magician_B:
			//ビックバン
			//画面全体の敵にダメージ
			//0.5 * 60 = 30
			if (player.bomb_c < 60) {
				for (int i = 0; i < ENEMY; i++) {
					if (enemy[i].hp > 0) {
						EnemyDamaged(i, 0.2);
					}
				}
				//ボスにダメージ
				BossDamaged(0.5);

				//画面内の弾を全消去
				for (int i = 0; i < BULLET; i++) {
					if (enemybullet[i].hp > 0) {
						RemoveBullet(i);
					}
				}
			}
			break;
		}
		player.bomb_c--;
	}
}