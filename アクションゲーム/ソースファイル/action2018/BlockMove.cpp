#include"Dxlib.h"
#include"extern.h"
#include"function.h"
#include<math.h>

void blockmove() {

	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			if (enemy[i][j].life != 0) {
				if (enemy[i][j].species == 53) {
					if (enemy[i][j].countx >= 0) {
						enemy[i][j].county--;
						if (enemy[i][j].county <= 0) {
							enemy[i][j].life = 0;
							kabe[i][j] = 0;
							enemy[i][j].countx = -1;
							enemy[i][j].vanish = 1;
							enemy[i][j].vanish_x = enemy[i][j].x;
							enemy[i][j].vanish_y = enemy[i][j].y;
						}
					}
				}
				if (enemy[i][j].species == 1 || enemy[i][j].species == 7 || enemy[i][j].species == 42) {
					enemy[i][j].countx++;
					enemy[i][j].county++;
				}
			}
		}
	}
	for (int j = 0; j< height_size; j++) {
		for (int i = 0; i< width_size; i++) {
			if (enemy[i][j].species == 1)
				sin_move(i, j);
			if (enemy[i][j].species == 42) {
				if (enemy[i][j].countx >= 113) {
					enemy[i][j].vx *= -1;
					enemy[i][j].countx = 0;
				}
			}
			if (enemy[i][j].species == 7) {
				sin_move_y(i, j);
			}
		}
	}
	for (int j = 0; j< height_size; j++) {
		for (int i = 0; i< width_size; i++) {
			if (enemy[i][j].species == 1 || enemy[i][j].species == 7 || enemy[i][j].species == 38 || enemy[i][j].species == 42) {
				enemy[i][j].x += enemy[i][j].vx;		//“®‚­°‚Ì‚˜À•W‚É‘¬“x‚ð‰ÁŽZ‚·‚é
				enemy[i][j].y += enemy[i][j].vy;		//“®‚­°‚Ì‚™À•W‚É‘¬“x‚ð‰ÁŽZ‚·‚é
			}
		}
	}
}
