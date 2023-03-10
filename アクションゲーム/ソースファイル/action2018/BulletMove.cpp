#include"Dxlib.h"
#include"extern.h"
#include"function.h"
#include<math.h>

//敵の弾を動かす関数
void move_enemybullet(){

	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			for (int k = 0; k<BULLET; k++) {
				if (enemybullet[i][j][k].life != 0) {
					if (enemy[i][j].species != 39 && enemy[i][j].species != 40) {
						//if (enemybullet[i][j][k].rad_v != 0) {
						//	if (enemybullet[i][j][k].rad_b >= enemybullet[i][j][k].rad_i + 90)//初期角度から一周した時
						//		enemybullet[i][j][k].rad_b = enemybullet[i][j][k].rad_i + enemybullet[i][j][k].rad_b % 360;
						//	enemybullet[i][j][k].rad_b += enemybullet[i][j][k].rad_v;//回転角の速度を足す
						//	enemybullet[i][j][k].vx = cos(enemybullet[i][j][k].rad_b  * PI / 180.0) * enemybullet[i][j][k].v;
						//	enemybullet[i][j][k].vy = sin(enemybullet[i][j][k].rad_b  * PI / 180.0) * enemybullet[i][j][k].v;
						//	if (enemybullet[i][j][k].rad_b > enemybullet[i][j][k].rad_i +45) {
						//		enemybullet[i][j][k].vy * -1;
						//	}
						//}

						//弾の移動
						enemybullet[i][j][k].x += enemybullet[i][j][k].vx;
						enemybullet[i][j][k].y += enemybullet[i][j][k].vy;

						//ステージ外に出た弾は消す
						if (enemybullet[i][j][k].x > width_size * BLOCK
							|| enemybullet[i][j][k].x < -enemybullet[i][j][k].size_x - BLOCK * 3
							|| enemybullet[i][j][k].y > height_size * BLOCK
							|| enemybullet[i][j][k].y < -enemybullet[i][j][k].size_y
							)
						{
							enemybullet[i][j][k].life = 0;
							enemybullet[i][j][k].rad_b = 0;
							enemybullet[i][j][k].rad_v = 0;
							enemybullet[i][j][k].v = 0;
							enemybullet[i][j][k].rad_i = 0;
						}
					}
				}
			}
		}
	}
}
