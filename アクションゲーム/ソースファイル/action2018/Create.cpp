#include"DxLib.h"
#include"extern.h"
#include"function.h"
#include<math.h>

void create_enemybullet()
{
	double c, d;
	double ang;  //自機と敵の角度を格納する変数

	if (scroll_v > 0) {
		c = player.x - scroll_leftx;
		d = scroll_leftx + CENTER;
	}
	else {
		if (player.x >= CENTER) {
			c = CENTER;
			d = player.x;
		}
		else {
			c = player.x;
			d = CENTER;
		}
		if (player.x > width_size * BLOCK - (WINDOW_WIDTH - CENTER)) {
			c = -(width_size * BLOCK - WINDOW_WIDTH - player.x);
			d = width_size * BLOCK - (WINDOW_WIDTH - CENTER);
		}
	}
	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			if (enemy[i][j].life > 0) {
				//全ての敵に対して行っていて、動くブロックにも行うので無駄
				if (d - CENTER <= enemy[i][j].x + enemy[i][j].size_x && d + WINDOW_WIDTH - CENTER >= enemy[i][j].x) {
					//ボス
					if (enemy[i][j].species == 21 && boss == 0) {
						enemy[i][j].t++;
						if (enemy[i][j].t % 120 == 0) {
							enemy[i][j].t = GetRand(30);
							for (int k = 0; k < BULLET; k++) {
								if (enemybullet[i][j][k].life == 0) {
									enemybullet[i][j][k].life = 1;
									enemybullet[i][j][k].species = 0;
									enemybullet[i][j][k].x = enemy[i][j].x + enemy[i][j].size_x * 0.25;
									enemybullet[i][j][k].y = enemy[i][j].y + enemy[i][j].size_y * 0.25;
									ang = atan2((double)((player.y + HERO_SIZE_Y / 2) - (enemy[i][j].y + enemy[i][j].size_y * 1.25)), (double)((player.x + HERO_SIZE_X / 4) - (enemy[i][j].x + enemy[i][j].size_x * 0.25)));
									enemybullet[i][j][k].vx = cos(ang) * 4;
									enemybullet[i][j][k].vy = sin(ang) * 4;
									efs(efs_bomb);
									break;
								}
							}
						}
					}
					//大砲
					if (enemy[i][j].species >= 22 && enemy[i][j].species <= 29) {
						enemy[i][j].t++;
						if (enemy[i][j].t % 150 == 0) {
							enemy[i][j].t = GetRand(30);
							for (int k = 0; k < BULLET; k++) {
								if (enemybullet[i][j][k].life == 0) {
									enemybullet[i][j][k].life = 1;
									enemybullet[i][j][k].species = 1;
									if (enemy[i][j].species == 22) {
										enemybullet[i][j][k].x = enemy[i][j].x;
										enemybullet[i][j][k].y = enemy[i][j].y + enemy[i][j].size_y * 0.25;
										enemybullet[i][j][k].vx = -3.5;
										enemybullet[i][j][k].vy = 0;
									}
									if (enemy[i][j].species == 23) {
										enemybullet[i][j][k].x = enemy[i][j].x + enemy[i][j].size_x * 0.75;
										enemybullet[i][j][k].y = enemy[i][j].y + enemy[i][j].size_y * 0.25;
										enemybullet[i][j][k].vx = 3.5;
										enemybullet[i][j][k].vy = 0;
									}
									if (enemy[i][j].species == 24) {
										enemybullet[i][j][k].x = enemy[i][j].x + enemy[i][j].size_x * 0.25;
										enemybullet[i][j][k].y = enemy[i][j].y + enemy[i][j].size_y * 0.00;
										enemybullet[i][j][k].vx = 0;
										enemybullet[i][j][k].vy = -3.5;
									}
									if (enemy[i][j].species == 25) {
										enemybullet[i][j][k].x = enemy[i][j].x + enemy[i][j].size_x * 0.25;
										enemybullet[i][j][k].y = enemy[i][j].y + enemy[i][j].size_y * 0.75;
										enemybullet[i][j][k].vx = 0;
										enemybullet[i][j][k].vy = 3.5;
									}
									if (enemy[i][j].species == 26) {
										enemybullet[i][j][k].x = enemy[i][j].x;
										enemybullet[i][j][k].y = enemy[i][j].y;
										enemybullet[i][j][k].vx = -2;
										enemybullet[i][j][k].vy = -2;
									}
									if (enemy[i][j].species == 27) {
										enemybullet[i][j][k].x = enemy[i][j].x + enemy[i][j].size_x * 0.50;
										enemybullet[i][j][k].y = enemy[i][j].y;
										enemybullet[i][j][k].vx = 2;
										enemybullet[i][j][k].vy = -2;
									}
									if (enemy[i][j].species == 28) {
										enemybullet[i][j][k].x = enemy[i][j].x;
										enemybullet[i][j][k].y = enemy[i][j].y + enemy[i][j].size_y * 0.50;
										enemybullet[i][j][k].vx = -2;
										enemybullet[i][j][k].vy = 2;
									}
									if (enemy[i][j].species == 29) {
										enemybullet[i][j][k].x = enemy[i][j].x + enemy[i][j].size_x * 0.50;
										enemybullet[i][j][k].y = enemy[i][j].y + enemy[i][j].size_y * 0.50;
										enemybullet[i][j][k].vx = 2;
										enemybullet[i][j][k].vy = 2;
									}
									efs(efs_bomb);
									break;
								}
							}
						}
					}
					if (enemy[i][j].species == 30) {
						enemy[i][j].t++;
						if (enemy[i][j].t % 120 == 0) {
							enemy[i][j].t = GetRand(30);
							for (int k = 0; k < BULLET; k++) {
								if (enemybullet[i][j][k].life == 0) {
									enemybullet[i][j][k].life = 1;
									enemybullet[i][j][k].species = 0;
									if (player.x > enemy[i][j].x)
										enemybullet[i][j][k].x = enemy[i][j].x + enemy[i][j].size_x * 0.50;
									else {
										enemybullet[i][j][k].x = enemy[i][j].x;
									}
									enemybullet[i][j][k].y = enemy[i][j].y + enemy[i][j].size_y * 0.35;
									if (enemy[i][j].species == 30) {
										ang = atan2((double)((player.y + HERO_SIZE_Y / 2) - (enemy[i][j].y + enemy[i][j].size_y * 1.25)), (double)((player.x + HERO_SIZE_X / 4) - (enemy[i][j].x + enemy[i][j].size_x * 0.25)));
										enemybullet[i][j][k].vx = cos(ang) * 4;
										enemybullet[i][j][k].vy = sin(ang) * 4;
									}
									efs(efs_bomb);
									break;
								}
							}
						}
					}
					if (enemy[i][j].species == 31) {
						enemy[i][j].t++;
						if (enemy[i][j].t % 120 == 0) {
							enemy[i][j].t = GetRand(30);
							for (int k = 0; k < BULLET; k++) {
								if (enemybullet[i][j][k].life == 0) {
									enemybullet[i][j][k].life = 1;
									enemybullet[i][j][k].species = 2;
									if (enemy[i][j].vx > 0) {
										enemybullet[i][j][k].x = enemy[i][j].x + enemy[i][j].size_x * 0.50;
										enemybullet[i][j][k].vx = 2.5 + enemy[i][j].vx;
									}
									else {
										enemybullet[i][j][k].x = enemy[i][j].x;
										enemybullet[i][j][k].vx = -2.5 + enemy[i][j].vx;
									}
									enemybullet[i][j][k].y = enemy[i][j].y + enemy[i][j].size_y * 0.35;
									efs(efs_bomb);
									break;
								}
							}
						}
					}
					if (enemy[i][j].species == 32 || enemy[i][j].species == 33) {
						enemy[i][j].t++;
						if (enemy[i][j].t % 120 == 0) {
							enemy[i][j].t = GetRand(30);
							for (int k = 0; k < BULLET; k++) {
								if (enemybullet[i][j][k].life == 0) {
									enemybullet[i][j][k].life = 1;
									enemybullet[i][j][k].species = 2;
									if (player.x > enemy[i][j].x) {
										enemybullet[i][j][k].x = enemy[i][j].x + enemy[i][j].size_x * 0.50;
										enemybullet[i][j][k].vx = 3.5 + enemy[i][j].vx;
									}
									else {
										enemybullet[i][j][k].x = enemy[i][j].x;
										enemybullet[i][j][k].vx = -3.5;
									}
									enemybullet[i][j][k].y = enemy[i][j].y + enemy[i][j].size_y * 0.35 + enemy[i][j].vy * 2;
									efs(efs_bomb);
									break;
								}
							}
						}
					}
					//x座標を合わせる敵
					if (enemy[i][j].species == 57) {
						enemy[i][j].t++;
						if (enemy[i][j].t % 150 == 0) {
							enemy[i][j].t = GetRand(30);
							for (int k = 0; k < BULLET - 3; k++) {
								if (enemybullet[i][j][k].life == 0) {//4つ弾を作る
									ang = atan2((double)((player.y + HERO_SIZE_Y / 2) - (enemy[i][j].y + enemy[i][j].size_y * 0.25)), (double)((player.x + HERO_SIZE_X / 4) - (enemy[i][j].x + enemy[i][j].size_x * 0.25)));
									enemybullet[i][j][k].life = 1;
									enemybullet[i][j][k].species = 6;
									enemybullet[i][j][k].x = enemy[i][j].x + enemy[i][j].size_x * 0.25;
									enemybullet[i][j][k].y = enemy[i][j].y + enemy[i][j].size_y * 0.25;
									enemybullet[i][j][k].vx = 2;
									enemybullet[i][j][k].vy = 4;
									k++;
									enemybullet[i][j][k].life = 1;
									enemybullet[i][j][k].species = 6;
									enemybullet[i][j][k].x = enemy[i][j].x + enemy[i][j].size_x * 0.25;
									enemybullet[i][j][k].y = enemy[i][j].y + enemy[i][j].size_y * 0.25;
									enemybullet[i][j][k].vx = -2;
									enemybullet[i][j][k].vy = 4;
									k++;
									enemybullet[i][j][k].life = 1;
									enemybullet[i][j][k].species = 6;
									enemybullet[i][j][k].x = enemy[i][j].x + enemy[i][j].size_x * 0.25;
									enemybullet[i][j][k].y = enemy[i][j].y + enemy[i][j].size_y * 0.25;
									enemybullet[i][j][k].vx = 6;
									enemybullet[i][j][k].vy = 4;
									k++;
									enemybullet[i][j][k].life = 1;
									enemybullet[i][j][k].species = 6;
									enemybullet[i][j][k].x = enemy[i][j].x + enemy[i][j].size_x * 0.25;
									enemybullet[i][j][k].y = enemy[i][j].y + enemy[i][j].size_y * 0.25;
									enemybullet[i][j][k].vx = -6;
									enemybullet[i][j][k].vy = 4;
									efs(efs_shot);
									break;
								}
							}
						}
					}

					//黒い雲
					if (enemy[i][j].species == 58) {
						enemy[i][j].t++;
						if (enemy[i][j].t % 30 == 0) {
							enemy[i][j].t = GetRand(3);
							for (int k = 0; k < BULLET; k++) {
								if (enemybullet[i][j][k].life == 0) {
									enemybullet[i][j][k].life = 1;
									enemybullet[i][j][k].species = 7;
									enemybullet[i][j][k].x = enemy[i][j].x + enemy[i][j].size_x * 0.5;
									enemybullet[i][j][k].y = enemy[i][j].y + enemy[i][j].size_y;
									enemybullet[i][j][k].vx = 0;
									enemybullet[i][j][k].vy = 3;
									efs(efs_shot);
									break;
								}
							}
						}
					}

					if (enemy[i][j].species == 49) {
						enemy[i][j].t++;
						if (enemy[i][j].t % 120 == 0) {
							enemy[i][j].t = 0;
							for (int k = 0; k < BULLET; k++) {
								if (enemybullet[i][j][k].life == 0) {
									enemybullet[i][j][k].life = 1;
									enemybullet[i][j][k].species = 2;
									if (enemy[i][j].dire_x == 0) {
										enemybullet[i][j][k].x = enemy[i][j].x + enemy[i][j].size_x * 0.60 + 3;
										enemybullet[i][j][k].vx = 6.0;
										enemybullet[i][j][k].vy = 0;
									}
									else {
										enemybullet[i][j][k].x = enemy[i][j].x + 8;
										enemybullet[i][j][k].vx = -6.0;
										enemybullet[i][j][k].vy = 0;
									}
									enemybullet[i][j][k].y = enemy[i][j].y + enemy[i][j].size_y * 0 + enemy[i][j].vy * 2 - 10;
									break;
								}
							}
							for (int k = 0; k < BULLET; k++) {
								if (enemybullet[i][j][k].life == 0) {
									enemybullet[i][j][k].life = 1;
									enemybullet[i][j][k].species = 3;
									if (enemy[i][j].dire_x == 0) {
										enemybullet[i][j][k].x = enemy[i][j].x + enemy[i][j].size_x * 0.60 + 3;
										enemybullet[i][j][k].vx = 4.0;
										enemybullet[i][j][k].vy = 2.0;
									}
									else {
										enemybullet[i][j][k].x = enemy[i][j].x + 8;
										enemybullet[i][j][k].vx = -4.0;
										enemybullet[i][j][k].vy = 2.0;
									}
									enemybullet[i][j][k].y = enemy[i][j].y + enemy[i][j].size_y * 0 + enemy[i][j].vy * 2 - 10;
									break;
								}
							}
							for (int k = 0; k < BULLET; k++) {
								if (enemybullet[i][j][k].life == 0) {
									enemybullet[i][j][k].life = 1;
									enemybullet[i][j][k].species = 3;
									if (enemy[i][j].dire_x == 0) {
										enemybullet[i][j][k].x = enemy[i][j].x + enemy[i][j].size_x * 0.60 + 3;
										enemybullet[i][j][k].vx = 4.0;
										enemybullet[i][j][k].vy = -2.0;
									}
									else {
										enemybullet[i][j][k].x = enemy[i][j].x + 8;
										enemybullet[i][j][k].vx = -4.0;
										enemybullet[i][j][k].vy = -2.0;
									}
									enemybullet[i][j][k].y = enemy[i][j].y + enemy[i][j].size_y * 0 + enemy[i][j].vy * 2 - 10;
									break;
								}
							}
							efs(efs_bomb);
						}
					}
					if (enemy[i][j].species == 51) {
						int d_life;//減ったhp量
						if (mapload < 1000)
							d_life = 4 - enemy[i][j].life;
						else if (mapload < 2000)
							d_life = 5 - enemy[i][j].life;
						else if (mapload < 3000)
							d_life = 6 - enemy[i][j].life;
						else if (mapload < 4000)
							d_life = 7 - enemy[i][j].life;
						enemy[i][j].t++;
						if (enemy[i][j].t % 300 == 0) {
							enemy[i][j].m_count = 30;
						}
						if (enemy[i][j].t % 300 == 0) {
							enemy[i][j].t = 0;
							for (int k = 0; k < BULLET; k++) {
								if (enemybullet[i][j][k].life == 0) {
									enemybullet[i][j][k].life = 1;
									enemybullet[i][j][k].species = 2;
									if (enemy[i][j].dire_x == 0) {
										enemybullet[i][j][k].x = enemy[i][j].x + enemy[i][j].size_x * 0.60 + 3;
										enemybullet[i][j][k].vx = 6.0;
										enemybullet[i][j][k].vy = 0;
									}
									else {
										enemybullet[i][j][k].x = enemy[i][j].x + 8;
										enemybullet[i][j][k].vx = -6.0;
										enemybullet[i][j][k].vy = 0;
									}
									enemybullet[i][j][k].y = enemy[i][j].y + enemy[i][j].size_y * 0 + enemy[i][j].vy * 2 - 10;
									efs(efs_bomb);
									break;
								}
							}
							if (d_life >= 4) {
								for (int k = 0; k < BULLET; k++) {
									if (enemybullet[i][j][k].life == 0) {
										enemybullet[i][j][k].life = 1;
										enemybullet[i][j][k].species = 3;
										if (enemy[i][j].dire_x == 0) {
											enemybullet[i][j][k].x = enemy[i][j].x + enemy[i][j].size_x * 0.60 + 3;
											enemybullet[i][j][k].vx = 4.0;
											enemybullet[i][j][k].vy = 4.0;
										}
										else {
											enemybullet[i][j][k].x = enemy[i][j].x + 8;
											enemybullet[i][j][k].vx = -4.0;
											enemybullet[i][j][k].vy = 4.0;
										}
										enemybullet[i][j][k].y = enemy[i][j].y + enemy[i][j].size_y * 0 + enemy[i][j].vy * 2 - 10;
										break;
									}
								}
								for (int k = 0; k < BULLET; k++) {
									if (enemybullet[i][j][k].life == 0) {
										enemybullet[i][j][k].life = 1;
										enemybullet[i][j][k].species = 3;
										if (enemy[i][j].dire_x == 0) {
											enemybullet[i][j][k].x = enemy[i][j].x + enemy[i][j].size_x * 0.60 + 3;
											enemybullet[i][j][k].vx = 4.0;
											enemybullet[i][j][k].vy = -4.0;
										}
										else {
											enemybullet[i][j][k].x = enemy[i][j].x + 8;
											enemybullet[i][j][k].vx = -4.0;
											enemybullet[i][j][k].vy = -4.0;
										}
										enemybullet[i][j][k].y = enemy[i][j].y + enemy[i][j].size_y * 0 + enemy[i][j].vy * 2 - 10;
										break;
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

void create_enemy() {
	double c, d;

	if (player.x >= CENTER) {
		c = CENTER;
		d = player.x;
	}
	else {
		c = player.x;
		d = CENTER;
	}
	if (player.x > width_size * BLOCK - (WINDOW_WIDTH - CENTER)) {
		c = -(width_size * BLOCK - WINDOW_WIDTH - player.x);
		d = width_size * BLOCK - (WINDOW_WIDTH - CENTER);
	}
	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i<width_size; i++) {
			if (enemy[i][j].species == 19) {
				if (enemy[i][j].life == 0) {
					enemy[i][j].t++;//メテオのカウントを増やす
					if (enemy[i][j].t == 470) {
						enemy[i][j].life = 1;
						enemy[i][j].x = i * BLOCK;
						enemy[i][j].y = -(BLOCK * 2);
						enemy[i][j].size_y = 64;
						enemy[i][j].vy = 4 + GetRand(20) / 10;
						//enemy[i][j].vy = enemy[i][j].m_rad;
						if (d - CENTER <= enemy[i][j].x + enemy[i][j].size_x && d + WINDOW_WIDTH - CENTER >= enemy[i][j].x)
							PlaySoundMem(music.fire, DX_PLAYTYPE_BACK);
					}
				}
				if (enemy[i][j].species == 19 && enemy[i][j].y > WINDOW_HEIGHT) {
					enemy[i][j].life = 0;
					enemy[i][j].t = GetRand(450);
					enemy[i][j].vy = 0;
					enemy[i][j].y = WINDOW_HEIGHT;
				}
			}
			if (enemy[i][j].species == -2) {
				enemy[i][j].t++;
				if (enemy[i][j].t == 60) {
					enemy[i][j].life = 0;
					enemy[i][j].species = 19;
					enemy[i][j].t = GetRand(450);
				}
			}

			if (enemy[i][j].species == 59 || enemy[i][j].species == 60 || enemy[i][j].species == 61) {
				if (enemy[i][j].life == 0) {
					enemy[i][j].t++;//星のカウントを増やす
					if (enemy[i][j].t >= 100) {
						enemy[i][j].life = 1;
						enemy[i][j].x = i * BLOCK;
						enemy[i][j].y = -(BLOCK * 2);
						if (enemy[i][j].species == 59) {
							enemy[i][j].vx = -1.5 + GetRand(30) / 10;
						}
						else if (enemy[i][j].species == 60) {
							enemy[i][j].vx = -2.0 + GetRand(40) / 10;
						}
						else if (enemy[i][j].species == 61) {
							enemy[i][j].vx = -2.25 + GetRand(45) / 10;
						}
						enemy[i][j].vy = 4 + GetRand(20) / 10;
						//enemy[i][j].vy = enemy[i][j].m_rad;
						if (d - CENTER <= enemy[i][j].x + enemy[i][j].size_x && d + WINDOW_WIDTH - CENTER >= enemy[i][j].x)
							PlaySoundMem(music.fire, DX_PLAYTYPE_BACK);
					}
				}
				if (enemy[i][j].y > WINDOW_HEIGHT) {
					enemy[i][j].life = 0;
					enemy[i][j].t = GetRand(30);
					enemy[i][j].vy = 0;
					enemy[i][j].y = WINDOW_HEIGHT;
				}
			}
		}
	}
}