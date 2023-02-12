#include"DxLib.h"
#include"extern.h"
#include"function.h"
#include<math.h>
#include<cmath>

//É{ÉXÇÃíeÇçÏÇÈä÷êî
void CreateBossBulletExtra() {

	double ang;
	if (boss.mode == 2) {
		if (boss.hp != 0) {
			boss.t++;
			if (boss.t % 15 == 0) {
				int i = getEnemyBulletNumber();
				enemybullet[i].hp = 1;
				if (boss.t % 2 == 0) {
					SetEBKind(ebk_yellow_S, i);
				}
				else {
					SetEBKind(ebk_blue_S, i);
				}
				enemybullet[i].x = boss.x;
				enemybullet[i].y = boss.y + boss.size;
				ang = atan2((double)((player.y + player.size / 2) - (boss.y + boss.size)), (double)((player.x + player.size / 2) - boss.x));
				enemybullet[i].vx = cos(ang) * 2;
				enemybullet[i].vy = sin(ang) * 2;
			}
		}
	}
	//double ang;
	//for (int i = 0; i < ENEMY; i++) {
	//	if (enemy[i].kind == -1) {
	//		if (enemy[i].hp != 0) {
	//			enemy[i].t++;
	//			if (enemy[i].t % 15 == 0) {
	//				for (int j = 0; j < ENEMYBULLET; j++) {
	//					if (enemybullet[j].hp == 0) {
	//						enemybullet[j].hp = 1;
	//						enemybullet[j].x = enemy[i].x;
	//						enemybullet[j].y = enemy[i].y + enemy[i].size;
	//						ang = atan2((double)((player.y + player.size / 2) - (enemy[i].y + enemy[i].size)), (double)((player.x + player.size / 2) - enemy[i].x));
	//						enemybullet[j].vx = cos(ang) * 8;
	//						enemybullet[j].vy = sin(ang) * 8;
	//						break;
	//					}
	//				}
	//			}
	//		}
	//	}
	//}
}
