#include"DxLib.h"
#include"extern.h"
#include"function.h"

//敵の壁に対する上下判定
void judge_ev(int blx, int bly) {

	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			if (enemy[i][j].jy == 1) {
				if (enemy[i][j].life > 0) {
					if (enemy[i][j].species != 14) {
						if (enemy[i][j].species == 16) {//床の端で反転する敵を半分床からはみ出たら反転するようにする
							if (enemy[i][j].vx > 0 && blx < (enemy[i][j].x + enemy[i][j].size_x) && enemy[i][j].x + enemy[i][j].size_x * 0.5 < (blx + BLOCK)
								&& bly <= (enemy[i][j].y + enemy[i][j].size_y) && enemy[i][j].y < (bly + BLOCK)
								|| enemy[i][j].vx <= 0 && blx < (enemy[i][j].x + enemy[i][j].size_x * 0.5) && enemy[i][j].x < (blx + BLOCK)
								&& bly <= (enemy[i][j].y + enemy[i][j].size_y) && enemy[i][j].y < (bly + BLOCK)) {
								enemy[i][j].vy = 0;
								enemy[i][j].jfly = 0;
								enemy[i][j].y = bly - enemy[i][j].size_y;
							}
						}
						else {
							//床の表面では座標をずらさない
							if (blx < (enemy[i][j].x + enemy[i][j].size_x) && enemy[i][j].x < (blx + BLOCK) && bly < (enemy[i][j].y + enemy[i][j].size_y) && enemy[i][j].y < (bly + BLOCK)) {
								if (enemy[i][j].vy >= 0) {
									enemy[i][j].vy = 0;
									enemy[i][j].y = bly - enemy[i][j].size_y;
								}
								else {
									enemy[i][j].y = bly + BLOCK;
									enemy[i][j].vy = 0;
								}
							}
							//床の表面以外
							else if (blx < (enemy[i][j].x + enemy[i][j].size_x) && enemy[i][j].x < (blx + BLOCK) && bly <= (enemy[i][j].y + enemy[i][j].size_y) && enemy[i][j].y < (bly + BLOCK)) {
								if (enemy[i][j].vy >= 0) {
									enemy[i][j].vy = 0;
									enemy[i][j].jfly = 0;
									if (enemy[i][j].species == 19) {
										enemy[i][j].species = -2;  //メテオは炎になる
										enemy[i][j].size_y = 32;
										enemy[i][j].t = 0;
									}
									enemy[i][j].y = bly - enemy[i][j].size_y;//炎も床のすぐ上に出るようにする
								}
								else {
									enemy[i][j].vy = 0;
									enemy[i][j].y = bly + BLOCK;
								}
							}
						}
					}
				}
			}
		}
	}
}

//敵の壁に対する上下反射判定
void judge_ev2(int blx, int bly) {

	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			if (enemy[i][j].species == 14) {
				if (enemy[i][j].life > 0)
					if (enemy[i][j].vy > 0) {
						if (blx < enemy[i][j].x + enemy[i][j].size_x && enemy[i][j].x - BLOCK < blx && bly <= enemy[i][j].y + enemy[i][j].size_y && enemy[i][j].y - BLOCK + enemy[i][j].vy <= bly)
							enemy[i][j].vy = enemy[i][j].vy * -1;
					}
					else {
						if (blx < enemy[i][j].x + enemy[i][j].size_x && enemy[i][j].x - BLOCK < blx && bly <= enemy[i][j].y + enemy[i][j].size_y + enemy[i][j].vy && enemy[i][j].y - BLOCK <= bly)
							enemy[i][j].vy = enemy[i][j].vy * -1;
					}
			}
		}
	}
}

//敵のすり抜け床の判定
void judge_ev3(int blx, int bly) {

	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			if (enemy[i][j].jy == 1) {
				if (enemy[i][j].species != 14) {
					if (enemy[i][j].life > 0) {
						if (blx < enemy[i][j].x + enemy[i][j].size_x && enemy[i][j].x < blx + BLOCK && bly <= enemy[i][j].y + enemy[i][j].size_y && enemy[i][j].y <= bly) {
							//敵とブロックが重なっている
							if (enemy[i][j].vy >= 0 && enemy[i][j].by + enemy[i][j].size_y <= bly) {
								enemy[i][j].jfly = 0;
								enemy[i][j].vy = 0;
								if (enemy[i][j].species == 19) {
									enemy[i][j].species = -2;  //メテオは炎になる
									enemy[i][j].size_y = 32;
									enemy[i][j].t = 0;
								}
								enemy[i][j].y = bly - enemy[i][j].size_y;
							}
						}
					}
				}
			}
		}
	}
}

void judge_ev4(int blx, int bly) {//敵のすり抜け床の反射判定

	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			if (enemy[i][j].species == 14) {
				if (enemy[i][j].life > 0)
					if (enemy[i][j].vy > 0) {
						if (blx < enemy[i][j].x + enemy[i][j].size_x && enemy[i][j].x - BLOCK < blx && bly <= enemy[i][j].y + enemy[i][j].size_y && enemy[i][j].y - BLOCK + enemy[i][j].vy <= bly)
							enemy[i][j].vy = enemy[i][j].vy * -1;
					}
			}
		}
	}
}

//敵の壁に対する左右判定1 : 壁に当たったら反転する
void judge_eh(int blx, int bly) {

	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			if (enemy[i][j].species != 44)
				if (enemy[i][j].jx == 1) {
					if (enemy[i][j].life > 0) {
						if (enemy[i][j].vx > 0) {
							if (blx <= (enemy[i][j].x + enemy[i][j].size_x) && enemy[i][j].x - BLOCK + enemy[i][j].vx < blx && bly < (enemy[i][j].y + enemy[i][j].size_y) && enemy[i][j].y - BLOCK < bly) {	//右方向
								enemy[i][j].vx = enemy[i][j].vx * -1;
								//enemy[i][j].countx = 300;
							}
						}
						else if (enemy[i][j].vx < 0) {
							if (blx - enemy[i][j].vx <= (enemy[i][j].x + enemy[i][j].size_x) && enemy[i][j].x - BLOCK <= blx && bly < (enemy[i][j].y + enemy[i][j].size_y) && enemy[i][j].y - BLOCK < bly) {	//左方向
								enemy[i][j].vx = enemy[i][j].vx * -1;
								//enemy[i][j].countx = 0;
							}

						}
					}
				}
		}
	}
}

//敵の壁に対する左右判定2 : 壁に横から重なったら壁の横にずらす
void judge_eh2(int blx, int bly) {
	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			if (enemy[i][j].jx == 1) {
				if (enemy[i][j].life > 0) {
					if (blx < (enemy[i][j].x + enemy[i][j].size_x) && enemy[i][j].x - BLOCK < blx && bly < (enemy[i][j].y + enemy[i][j].size_y) && enemy[i][j].y - BLOCK < bly) {
						//敵とブロックが重なっている
						if (enemy[i][j].vx > 0) {
							enemy[i][j].x = blx - enemy[i][j].size_x;
						}
						else
							enemy[i][j].x = blx + BLOCK;
					}
				}
			}
		}
	}
}
