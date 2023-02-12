#include"DxLib.h"
#include"function.h"
#include"extern.h"

void judgeDoor() {
	//扉の判定
	//一つ扉の判定したら他の扉は判定しないのでreturnする
	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			if (player.jfly == 0 && button[KEY_UP] == 1) {
				if ((enemy[i][j].x < player.x + HERO_SIZE_X / 2 && player.x + HERO_SIZE_X / 2 < enemy[i][j].x + enemy[i][j].size_x) &&
					(enemy[i][j].y < player.y + HERO_SIZE_Y && player.y < enemy[i][j].y + enemy[i][j].size_y)) {
					switch (enemy[i][j].species) {
					case 8:	door(i, j);	return;			//対応する扉の位置に移動する
					case 9:	door(i, j);	return;			//対応する扉の位置に移動する
					case 10:door2(++mapload); return;	//次のエリアへ移動する
					case 11:change_flag(e_clear);					//クリア画面にする
					case 50:
						if (enemy[i][j].life == 0) {	//ボスのhpが0になったらクリアの扉が出る
							change_flag(e_clear);
							return;
						}
						break;
					}
				}
			}
		}
	}
}

void door(int dx, int dy) {

	door_fade_x = dx;
	door_fade_y = dy;
	fade_flag = ef_fadeOut_door;
}

void door_fade(int dx, int dy) {

	for (int j = 0; j< height_size; j++) {
		for (int i = 0; i<width_size; i++) {
			if (enemy[dx][dy].species == 8) {
				if (enemy[i][j].species == 9) {
					player.x = enemy[i][j].x;
					player.y = enemy[i][j].y;
					player.vx2 = 0;
					return;
				}
			}
			if (enemy[dx][dy].species == 9) {
				if (enemy[i][j].species == 8) {
					player.x = enemy[i][j].x;
					player.y = enemy[i][j].y;
					player.vx2 = 0;
					return;
				}
			}
		}
	}
}

void door2(int x) {

	door_fade_x = x;
	fade_flag = ef_fadeOut_door2;
}

void door_fade2(int x) {

	if (mapload != 0) {
		mapload = x;
	}
	ReadMap();	//マップのリロード
	init();			//変数の初期化
	black_screen(70);
}
