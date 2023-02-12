#include"DxLib.h"
#include"extern.h"
#include"function.h"

//“G‚Ì’e‚ÌˆÚ“®
void MoveEnemyBullet() {

	for (int i = 0; i < ENEMYBULLET; i++) {
		if (enemybullet[i].hp != 0) {
			enemybullet[i].t++;
			switch (enemybullet[i].bkind) {
			case 0:	//•’Ê‚Ì“®‚«‚ð‚·‚é’e
				enemybullet[i].x += enemybullet[i].vx;
				enemybullet[i].y += enemybullet[i].vy;
				break;
			case 1:
				if (enemybullet[i].t >= 80) {
					enemybullet[i].vx += 0.05;
					enemybullet[i].vy += 0.1;
				}
				enemybullet[i].x += enemybullet[i].vx;
				enemybullet[i].y += enemybullet[i].vy;
				break;
			case 2:
				if (enemybullet[i].t >= 80) {
					enemybullet[i].vx -= 0.05;
					enemybullet[i].vy += 0.1;
				}
				enemybullet[i].x += enemybullet[i].vx;
				enemybullet[i].y += enemybullet[i].vy;
				break;
			}
			//‰½‚©‚É‚Ô‚Â‚©‚Á‚½‚ç•Ï‰»‚·‚é’e
			if (enemybullet[i].mutate != 0) {
				int x = enemybullet[i].x;
				int y = enemybullet[i].y;
				if (enemybullet[i].x > G_W_RIGHT) {
					x = G_W_RIGHT;
					if (enemybullet[i].mutate == 3) {
						Burrage_Fall(ebk_blue_S, x, y, 2, PI / 6, 0.5 + GetRand(10) / 10.0);
					}
				}
				if (enemybullet[i].x < G_W_LEFT) {
					x = G_W_LEFT;
					if (enemybullet[i].mutate == 3) {
						Burrage_Fall(ebk_blue_S, x, y, 2, PI / 6, 0.5 + GetRand(10) / 10.0);
					}
				}
				if (enemybullet[i].y > G_W_LOWER) {
					y = G_W_LOWER;
				}
				if (enemybullet[i].y < G_W_UPPER) {
					y = G_W_UPPER;
					if (enemybullet[i].mutate == 3) {
						Burrage_Fall(ebk_blue_S, x, y, 2, PI / 6, 0.5 + GetRand(10) / 10.0);
					}
				}
				if (enemybullet[i].x >= G_W_RIGHT ||
					enemybullet[i].x <= G_W_LEFT ||
					enemybullet[i].y >= G_W_LOWER ||
					enemybullet[i].y <= G_W_UPPER)
				{
					if (enemybullet[i].mutate == 4) {
						SetEBKind(ebk_snow_S, i);
						if (enemybullet[i].x >= G_W_RIGHT || enemybullet[i].x <= G_W_LEFT) {
							enemybullet[i].vx *= -1;
						}
						if (enemybullet[i].y >= G_W_LOWER || enemybullet[i].y <= G_W_UPPER) {
							enemybullet[i].vy *= -1;
						}
						enemybullet[i].mutate = 3;
					}
					else {
						//á’e‚ÍãˆÈŠO‚É‚Ô‚Â‚©‚Á‚½‚ç‚½‚¾‚Ì’e‚É•Ï‚¦‚é‚Ì‚Åhp‚ð0‚É‚µ‚È‚¢
						//‰Š’e‚Í”½ŽË‚µ‚ÄÔ’e‚É•Ï‰»‚·‚é‚Ì‚Åhp‚ð0‚É‚µ‚È‚¢
						if (enemybullet[i].mutate != 2 && enemybullet[i].mutate != 3) {
							enemybullet[i].hp = 0;
						}
						switch (enemybullet[i].mutate) {
						case 1: Burrage_NWay(ebk_yellow_S, x, y, 1, 0, 1.0); break;
						case 2:
							SetEBKind(ebk_red_S, i);
							if (enemybullet[i].x >= G_W_RIGHT || enemybullet[i].x <= G_W_LEFT) {
								enemybullet[i].vx *= -1;
							}
							if (enemybullet[i].y >= G_W_LOWER || enemybullet[i].y <= G_W_UPPER) {
								enemybullet[i].vy *= -1;
							}
							break;
						case 3: break;
						}
						enemybullet[i].mutate = 0;
					}
				}
			}
			else {
				//‰æ–ÊŠO‚Éo‚½’e‚ÌÁ‹Ž
				//‰æ–ÊŠO‚Éo‚Ä‚·‚®Á‚¦‚È‚¢‚æ‚¤‚É‚·‚é
				if (enemybullet[i].x - enemybullet[i].size > G_W_RIGHT + 200 ||
					enemybullet[i].x + enemybullet[i].size < G_W_LEFT - 200 ||
					enemybullet[i].y - enemybullet[i].size > G_W_LOWER + 200 ||
					enemybullet[i].y + enemybullet[i].size < G_W_UPPER - 200)
				{
					enemybullet[i].hp = 0;
				}
			}
		}
	}
}