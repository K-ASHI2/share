#include"DxLib.h"
#include"extern.h"
#include"function.h"

void draw_background() {
	double x;

	if (scroll_v > 0) {
		x = (scroll_leftx + CENTER) / 3;
	}
	else {
		if (player.x <= CENTER) {//プレイヤーが左端付近にいる時
			x = CENTER / 3;
		}
		else if (player.x > width_size * BLOCK - (WINDOW_WIDTH - CENTER)) {//プレイヤーが右端付近にいる時
			x = (width_size * BLOCK - (WINDOW_WIDTH - CENTER)) / 3;
		}
		else {//プレイヤーが一定の位置より右にいる時描画の中心をプレイヤーの座標にする
			x = player.x / 3;
		}
	}

	for (int i = 0; i < 4; i++) {
		DrawGraph(-x + background[background_n].size_x * i, 0, background[background_n].img, TRUE);
	}
}
