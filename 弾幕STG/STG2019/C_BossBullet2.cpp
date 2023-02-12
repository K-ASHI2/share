#include"DxLib.h"
#include"extern.h"
#include"function.h"
#include<math.h>
#include<cmath>

//ボスの弾を作る関数
void CreateBossBullet2() {

	double ang;

	switch (difficulty) {
	case ed_easy:
		switch (boss.mode) {
		case 1:
			if (boss.hp != 0) {
				boss.t++;
				if (boss.t % 40 == 0) {
					int i = getEnemyBulletNumber();
					enemybullet[i].hp = 1;
					SetEBKind(ebk_snow_S, i);
					enemybullet[i].mutate = 3;
					ang = PI * 1.5 * (boss.t / 10 % 60) / 60.0;
					SetEnemyBullet(i, boss.x, boss.y, cos(ang) * 1.5, sin(ang) * 1.5);
				}
			}
			break;
		case 2:
			if (boss.hp != 0) {
				boss.t++;
				if (boss.t % 600 == 0) {
					Burrage_NWay(ebk_snow_M, G_W_LEFT + GetRand(480), boss.y, 3, -1, 2.0, 4);
				}
				else if (boss.t % 200 == 0) {
					Burrage_Fall(ebk_snow_M, G_W_LEFT + GetRand(480), boss.y, 3, -1, 2.0, 4);
				}
			}
			break;
		case 3:
			if (boss.hp != 0) {
				boss.t++;
				if (boss.t % 40 == 0) {
					int i = getEnemyBulletNumber();
					enemybullet[i].hp = 1;
					SetEBKind(ebk_thunder, i);
					enemybullet[i].mutate = 1;
					ang = PI * 1.5 * (boss.t / 10 % 60) / 60.0;
					SetEnemyBullet(i, boss.x, boss.y, cos(ang) * 1.5, sin(ang) * 1.5, 0, ang);
				}
			}
			break;
		case 4:
			//電気と水
			if (boss.hp != 0) {
				boss.t++;
				if (boss.t % 240 == 0) {
					Burrage_Fall(ebk_thunder, G_W_LEFT + GetRand(480), boss.y, 1, 0, 2.0, 1);
				}
				if (boss.t % 40 == 5) {
					Burrage_Fall(ebk_blue_S, G_W_LEFT + GetRand(480), boss.y, 1, 0, 1.5, 0);
				}
			}
			break;
		case 5:
			if (boss.hp != 0) {
				boss.t++;
				if (boss.t % 40 == 0) {
					int i = getEnemyBulletNumber();
					enemybullet[i].hp = 1;
					SetEBKind(ebk_fire_S, i);
					enemybullet[i].mutate = 2;
					ang = PI * 1.5 * (boss.t / 10 % 60) / 60.0;
					SetEnemyBullet(i, boss.x, boss.y, cos(ang) * 1.5, sin(ang) * 1.5, 0, ang);
				}
			}
			break;

		case 6:
			if (boss.hp != 0) {
				boss.t++;
				if (boss.t % 1200 <= 400) {
					if (boss.t % 100 == 0) {
						Burrage_NWay2(ebk_fire_S, boss.x, boss.y, 5, -1, 2.0, 0, 1);
					}
				}
				else if (boss.t % 1200 >= 600 && boss.t % 1200 <= 1000) {
					if (boss.t % 100 == 0) {
						Burrage_NWay2(ebk_fire_S, boss.x, boss.y, 5, -1, 2.0, 0, 2);
					}
				}
			}
			break;
		case 7:
			if (boss.hp != 0) {
				boss.t++;
				if (boss.t % 180 == 0) {
					int i = getEnemyBulletNumber();
					enemybullet[i].hp = 1;
					SetEBKind(ebk_fire_S, i);
					enemybullet[i].mutate = 2;
					ang = PI * 2.0 * (boss.t / 10 % 120) / 120.0;
					SetEnemyBullet(i, boss.x, boss.y, cos(ang) * 2.0, sin(ang) * 2.0, 0, ang);
				}
				if (boss.t % 180 == 60) {
					int i = getEnemyBulletNumber();
					enemybullet[i].hp = 1;
					SetEBKind(ebk_thunder, i);
					enemybullet[i].mutate = 1;
					ang = PI * 2.0 * (boss.t / 10 % 60) / 60.0;
					SetEnemyBullet(i, boss.x, boss.y, cos(ang) * 2.0, sin(ang) * 2.0, 0, ang);
				}
				if (boss.t % 180 == 120) {
					int i = getEnemyBulletNumber();
					enemybullet[i].hp = 1;
					SetEBKind(ebk_snow_S, i);
					enemybullet[i].mutate = 3;
					ang = -1 * PI * 2.0 * (boss.t / 10 % 60) / 60.0;
					SetEnemyBullet(i, boss.x, boss.y, cos(ang) * 2.0, sin(ang) * 2.0);
				}
			}
			break;

		case 8:
			if (boss.hp != 0) {
				boss.t++;
				if (boss.t % 60 == 0) {
					Burrage_NWay(ebk_star, boss.x, boss.y, 18, -1, 2.0);
				}
				if (boss.t % 47 == 0) {
					Burrage_NWay(ebk_star_red, boss.x - 160, boss.y + 20, 6, PI / 6.0, 1.0);
					Burrage_NWay(ebk_star_blue, boss.x + 160, boss.y + 20, 6, PI / 6.0, 1.0);
				}
			}
			break;
		case 9:
			if (boss.hp != 0) {
				boss.t++;
				if (boss.t % 31 == 0) {
					Burrage_Fall(ebk_star_red, G_W_LEFT + GetRand(480), boss.y, 2, 0, 1.2);
				}
				if (boss.t % 110 == 0) {
					Burrage_Fall(ebk_star_blue, G_W_LEFT + GetRand(480), GetRand(40), 3, PI / 12.0, 2.5);
					Burrage_Fall(ebk_star_blue, G_W_LEFT + GetRand(480), GetRand(40), 3, PI / 12.0, 2.5);
				}
				if (boss.t % 125 == 0) {
					Burrage_Fall(ebk_star, G_W_LEFT + GetRand(480), GetRand(40), 3, PI / 8.0, 1.5);
					Burrage_Fall(ebk_star, G_W_LEFT + GetRand(480), GetRand(40), 3, PI / 8.0, 1.5);
				}
			}
			break;
		}
		break;
	case ed_normal:
		switch (boss.mode) {
		case 1:
			if (boss.hp != 0) {
				boss.t++;
				if (boss.t % 20 == 0) {
					int i = getEnemyBulletNumber();
					enemybullet[i].hp = 1;
					SetEBKind(ebk_snow_S, i);
					enemybullet[i].mutate = 3;
					ang = PI * 2.5 * (boss.t / 10 % 60) / 40.0;
					SetEnemyBullet(i, boss.x, boss.y, cos(ang) * 1.5, sin(ang) * 1.5);
				}
			}
			break;
		case 2:
			if (boss.hp != 0) {
				boss.t++;
				if (boss.t % 480 == 0 || boss.t % 480 == 160) {
					Burrage_Fall(ebk_snow_M, G_W_LEFT + GetRand(480), boss.y, 5, -1, 2.0, 4);
				}
				if (boss.t % 480 == 320) {
					Burrage_NWay(ebk_snow_M, G_W_LEFT + GetRand(480), boss.y, 5, -1, 2.0, 4);
				}
			}
			break;
		case 3:
			if (boss.hp != 0) {
				boss.t++;
				if (boss.t % 30 == 0) {
					int i = getEnemyBulletNumber();
					enemybullet[i].hp = 1;
					SetEBKind(ebk_thunder, i);
					enemybullet[i].mutate = 1;
					ang = PI * 2.5 * (boss.t / 10 % 60) / 40.0;
					SetEnemyBullet(i, boss.x, boss.y, cos(ang) * 1.5, sin(ang) * 1.5, 0, ang);
				}
			}
			break;
		case 4:
			//電気と水
			if (boss.hp != 0) {
				boss.t++;
				if (boss.t % 110 == 0) {
					Burrage_Fall(ebk_thunder, G_W_LEFT + GetRand(480), boss.y, 1, 0, 1.5, 1);
				}
				if (boss.t % 30 == 10) {
					Burrage_Fall(ebk_blue_S, G_W_LEFT + GetRand(480), boss.y, 1, 0, 1.5, 0);
				}
			}
			break;
		case 5:
			if (boss.hp != 0) {
				boss.t++;
				if (boss.t % 30 == 0) {
					int i = getEnemyBulletNumber();
					enemybullet[i].hp = 1;
					SetEBKind(ebk_fire_S, i);
					enemybullet[i].mutate = 2;
					ang = PI * 2.5 * (boss.t / 10 % 60) / 40.0;
					SetEnemyBullet(i, boss.x, boss.y, cos(ang) * 1.5, sin(ang) * 1.5, 0, ang);
				}
			}
			break;

		case 6:
			if (boss.hp != 0) {
				boss.t++;
				if (boss.t % 1200 <= 400) {
					if (boss.t % 100 == 0) {
						Burrage_NWay2(ebk_fire_S, boss.x, boss.y, 8, -1, 2.0, 0, 1);
					}
				}
				else if (boss.t % 1200 >= 600 && boss.t % 1200 <= 1000) {
					if (boss.t % 100 == 0) {
						Burrage_NWay2(ebk_fire_S, boss.x, boss.y, 8, -1, 2.0, 0, 2);
					}
				}
			}
			break;
		case 7:
			if (boss.hp != 0) {
				boss.t++;
				if (boss.t % 60 == 0) {
					int i = getEnemyBulletNumber();
					enemybullet[i].hp = 1;
					SetEBKind(ebk_fire_S, i);
					enemybullet[i].mutate = 2;
					ang = PI * 2.0 * (boss.t / 10 % 120) / 120.0;
					SetEnemyBullet(i, boss.x, boss.y, cos(ang) * 2.0, sin(ang) * 2.0, 0, ang);
				}
				if (boss.t % 60 == 20) {
					int i = getEnemyBulletNumber();
					enemybullet[i].hp = 1;
					SetEBKind(ebk_thunder, i);
					enemybullet[i].mutate = 1;
					ang = PI * 2.0 * (boss.t / 10 % 60) / 60.0;
					SetEnemyBullet(i, boss.x, boss.y, cos(ang) * 2.0, sin(ang) * 2.0, 0, ang);
				}
				if (boss.t % 60 == 40) {
					int i = getEnemyBulletNumber();
					enemybullet[i].hp = 1;
					SetEBKind(ebk_snow_S, i);
					enemybullet[i].mutate = 3;
					ang = -1 * PI * 2.0 * (boss.t / 10 % 60) / 60.0;
					SetEnemyBullet(i, boss.x, boss.y, cos(ang) * 2.0, sin(ang) * 2.0);
				}
			}
			break;

		case 8:
			if (boss.hp != 0) {
				boss.t++;
				if (boss.t % 35 == 0) {
					Burrage_NWay(ebk_star, boss.x, boss.y, 18, -1, 1.2);
				}
				if (boss.t % 35 == 0) {
					Burrage_NWay(ebk_star_red, boss.x - 160, boss.y + 20, 8, PI / 10.0, 1.2);
					Burrage_NWay(ebk_star_blue, boss.x + 160, boss.y + 20, 8, PI / 10.0, 1.2);
				}
			}
			break;

		case 9:
			if (boss.hp != 0) {
				boss.t++;
				if (boss.t % 17 == 0) {
					Burrage_Fall(ebk_star_red, G_W_LEFT + GetRand(480), boss.y, 1, 0, 2.5);
				}
				if (boss.t % 79 == 0) {
					Burrage_Fall(ebk_star_blue, G_W_LEFT + GetRand(480), GetRand(40), 3, PI / 12.0, 2.5);
					Burrage_Fall(ebk_star_blue, G_W_LEFT + GetRand(480), GetRand(40), 3, PI / 12.0, 2.5);
				}
				if (boss.t % 71 == 0) {
					Burrage_Fall(ebk_star, G_W_LEFT + GetRand(480), GetRand(40), 3, PI / 18.0, 2.0);
					Burrage_Fall(ebk_star, G_W_LEFT + GetRand(480), GetRand(40), 3, PI / 18.0, 2.0);
				}
			}
			break;
		}
		break;

	case ed_hard:
		switch (boss.mode) {
		case 1:
			if (boss.hp != 0) {
				boss.t++;
				if (boss.t % 10 == 0) {
					int i = getEnemyBulletNumber();
					enemybullet[i].hp = 1;
					SetEBKind(ebk_snow_S, i);
					enemybullet[i].mutate = 3;
					ang = PI * 2.0 * (boss.t / 10 % 60) / 60.0;
					SetEnemyBullet(i, boss.x, boss.y, cos(ang) * 3.0, sin(ang) * 3.0);
				}
			}
			break;
		case 2:
			if (boss.hp != 0) {
				boss.t++;
				if (boss.t % 80 == 0) {
					Burrage_Fall(ebk_snow_M, G_W_LEFT + GetRand(480), boss.y, 6, -1, 2.0, 4);
				}
				if (boss.t % 240 == 120) {
					Burrage_NWay(ebk_snow_M, G_W_LEFT + GetRand(480), boss.y, 6, -1, 2.0, 4);
				}
			}
			break;
		case 3:
			if (boss.hp != 0) {
				boss.t++;
				if (boss.t % 10 == 0) {
					int i = getEnemyBulletNumber();
					enemybullet[i].hp = 1;
					SetEBKind(ebk_thunder, i);
					enemybullet[i].mutate = 1;
					ang = PI * 2.0 * (boss.t / 10 % 60) / 60.0;
					SetEnemyBullet(i, boss.x, boss.y, cos(ang) * 3.0, sin(ang) * 3.0, 0, ang);
				}
			}
			break;
		case 4:
			//電気と水
			if (boss.hp != 0) {
				boss.t++;
				if (boss.t % 60 == 0) {
					Burrage_Fall(ebk_thunder, G_W_LEFT + GetRand(480), boss.y, 1, 0, 2.0, 1);
				}
				if (boss.t % 10 == 5) {
					Burrage_Fall(ebk_blue_S, G_W_LEFT + GetRand(480), boss.y, 1, 0, 2.0, 0);
				}
			}
			break;
		case 5:
			if (boss.hp != 0) {
				boss.t++;
				if (boss.t % 10 == 0) {
					int i = getEnemyBulletNumber();
					enemybullet[i].hp = 1;
					SetEBKind(ebk_fire_S, i);
					enemybullet[i].mutate = 2;
					ang = PI * 2.0 * (boss.t / 10 % 60) / 60.0;
					SetEnemyBullet(i, boss.x, boss.y, cos(ang) * 3.0, sin(ang) * 3.0, 0, ang);
				}
			}
			break;

		case 6:
			if (boss.hp != 0) {
				boss.t++;
				if (boss.t % 1200 <= 400) {
					if (boss.t % 1200 == 400) {
						Burrage_NWay2(ebk_fire_S, boss.x, boss.y, 15, -1, 2.0, 0, 2);
					}
					else if (boss.t % 80 == 0) {
						Burrage_NWay2(ebk_fire_S, boss.x, boss.y, 15, -1, 2.0, 0, 1);
					}
				}
				else if (boss.t % 1200 >= 600 && boss.t % 1200 <= 1000) {
					if (boss.t % 1200 == 1000) {
						Burrage_NWay2(ebk_fire_S, boss.x, boss.y, 15, -1, 2.0, 0, 1);
					}
					else if (boss.t % 80 == 0) {
						Burrage_NWay2(ebk_fire_S, boss.x, boss.y, 15, -1, 2.0, 0, 2);
					}
				}
			}
			break;
		case 7:
			if (boss.hp != 0) {
				boss.t++;
				if (boss.t % 30 == 0) {
					int i = getEnemyBulletNumber();
					enemybullet[i].hp = 1;
					SetEBKind(ebk_fire_S, i);
					enemybullet[i].mutate = 2;
					ang = PI * 2.0 * (boss.t / 10 % 120) / 120.0;
					SetEnemyBullet(i, boss.x, boss.y, cos(ang) * 3.0, sin(ang) * 3.0, 0, ang);
				}
				if (boss.t % 30 == 10) {
					int i = getEnemyBulletNumber();
					enemybullet[i].hp = 1;
					SetEBKind(ebk_thunder, i);
					enemybullet[i].mutate = 1;
					ang = PI * 2.0 * (boss.t / 10 % 60) / 60.0;
					SetEnemyBullet(i, boss.x, boss.y, cos(ang) * 3.0, sin(ang) * 3.0, 0, ang);
				}
				if (boss.t % 30 == 20) {
					int i = getEnemyBulletNumber();
					enemybullet[i].hp = 1;
					SetEBKind(ebk_snow_S, i);
					enemybullet[i].mutate = 3;
					ang = -1 * PI * 2.0 * (boss.t / 10 % 60) / 60.0;
					SetEnemyBullet(i, boss.x, boss.y, cos(ang) * 3.0, sin(ang) * 3.0);
				}
			}
			break;


		case 8:
			if (boss.hp != 0) {
				boss.t++;
				if (boss.t % 20 == 0) {
					Burrage_NWay(ebk_star, boss.x, boss.y, 21, -1, 2.0);
				}
				if (boss.t % 7 == 0) {
					Burrage_NWay(ebk_star_blue, boss.x + 40, boss.y, 4, PI / 12.0, 2.0);
					Burrage_NWay(ebk_star_blue, boss.x - 40, boss.y, 4, PI / 12.0, 2.0);
				}
				if (boss.t % 11 == 0) {
					Burrage_NWay(ebk_star_red, boss.x - 160, boss.y + 20, 4, PI / 12.0, 2.0);
					Burrage_NWay(ebk_star_red, boss.x + 160, boss.y + 20, 4, PI / 12.0, 2.0);
				}
			}
			break;
		case 9:
			if (boss.hp != 0) {
				boss.t++;
				if (boss.t % 15 == 0) {
					Burrage_Fall(ebk_star_red, G_W_LEFT + GetRand(480), boss.y, 1, 0, 2.5);
				}
				if (boss.t % 80 == 0) {
					Burrage_Fall(ebk_star_blue, G_W_LEFT + GetRand(480), GetRand(40), 3, PI / 12.0, 4.0);
					Burrage_Fall(ebk_star_blue, G_W_LEFT + GetRand(480), GetRand(40), 3, PI / 12.0, 4.0);
				}
				if (boss.t % 65 == 0) {
					Burrage_Fall(ebk_star, G_W_LEFT + GetRand(480), GetRand(40), 4, PI / 12.0, 2.0);
					Burrage_Fall(ebk_star, G_W_LEFT + GetRand(480), GetRand(40), 4, PI / 12.0, 2.0);
				}
			}
			break;
		}
		break;
	}
}
