#include"Dxlib.h"
#include"extern.h"
#include"function.h"
#include<math.h>

//敵キャラの移動
void enemymove(void) {
	double center, rad, ang;

	//角速度を増やす
	deg += 2;

	//現在の画面の中央を求める
	if (scroll_v > 0) {
		center = scroll_leftx + CENTER;
	}
	else {
		if (player.x >= CENTER) {
			center = player.x;
		}
		else {
			center = CENTER;
		}
		if (player.x > width_size * BLOCK - (WINDOW_WIDTH - CENTER)) {
			center = width_size * BLOCK - (WINDOW_WIDTH - CENTER);
		}
	}
	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			if (enemy[i][j].life != 0) {
				//画面内に入ったら敵は動きだす
				if (i * BLOCK <= center + WINDOW_WIDTH - CENTER && i * BLOCK + enemy[i][j].size_x >= center - CENTER) {
					enemy[i][j].appear = 1;
				}
				if (enemy[i][j].jfly != 0) {
					if (enemy[i][j].species == 16 && enemy[i][j].jfly2 == 0) {//崖の端で反転する敵の判定
						enemy[i][j].vx = enemy[i][j].vx * -1;
					}
					else if (enemy[i][j].vy < MAXSPEED_Y)
						enemy[i][j].vy += GRA;
					enemy[i][j].jfly2 = 1;
				}
				else
					enemy[i][j].jfly2 = 0;
			}
		}
	}
	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			if (enemy[i][j].life != 0) {
				if (enemy[i][j].species != 1 && enemy[i][j].species != 7 && enemy[i][j].species != 42 && enemy[i][j].species != 53 && enemy[i][j].appear == 1) {
					if (enemy[i][j].vx >= 0)		//敵が右向き
						enemy[i][j].dire_x = 0;
					else							//敵が左向き
						enemy[i][j].dire_x = 1;
					if (enemy[i][j].vy >= 0) 		//敵が上向き
						enemy[i][j].dire_y = 0;
					else							//敵が下向き
						enemy[i][j].dire_y = 1;
					enemy[i][j].countx++;
					if (enemy[i][j].m_count == 0)
						enemy[i][j].county++;
				}
				switch (enemy[i][j].species) {
				case -2:enemy[i][j].jfly = 1; break;
				case 0: sin_move(i, j); break;
				case 2: sin_move(i, j); break;
				case 4: enemy[i][j].jfly = 1; break;
				case 5: sin_move_y(i, j); break;
				case 6: enemy[i][j].jfly = 1; break;
				case 7: break;
				case 8: break;
				case 9: break;
				case 10:break;
				case 11:break;
				case 12:enemy[i][j].jfly = 1; break;
				case 13:
					if (enemy[i][j].county >= 70 && enemy[i][j].jfly == 0) {
						enemy[i][j].vy = -15;
						enemy[i][j].county = 0;
					}
					enemy[i][j].jfly = 1;
					break;
				case 14: break;
				case 15:
					if (enemy[i][j].dire == 0) {
						rad = (enemy[i][j].rad + deg) * PI / 180.0 * (0.6 + enemy[i][j].m_rad / 10);
						enemy[i][j].x = i * BLOCK + 64 * cos(rad);
						enemy[i][j].y = j * BLOCK + 64 * sin(rad);
					}
					else {
						rad = (enemy[i][j].rad - deg) * PI / 180.0 * (0.6 + enemy[i][j].m_rad / 10);
						enemy[i][j].x = i * BLOCK + 64 * cos(rad);
						enemy[i][j].y = j * BLOCK + 64 * sin(rad);
					}
					break;
				case 16:enemy[i][j].jfly = 1; break;
				case 17:enemy[i][j].jfly = 1; break;
				case 18:enemy[i][j].jfly = 1; break;
				case 19: break;
				case 20:enemy[i][j].jfly = 1; break;
				case 30: sin_move_y(i, j); break;
				case 31:enemy[i][j].jfly = 1; break;
				case 32: sin_move_y(i, j); break;
				case 33:
					if (enemy[i][j].dire == 0) {
						rad = (enemy[i][j].rad + deg) * PI / 180.0 * (0.6 + enemy[i][j].m_rad / 10);
						enemy[i][j].x = i * BLOCK + 64 * cos(rad);
						enemy[i][j].y = j * BLOCK + 64 * sin(rad);
					}
					else {
						rad = (enemy[i][j].rad - deg) * PI / 180.0 * (0.6 + enemy[i][j].m_rad / 10);
						enemy[i][j].x = i * BLOCK + 64 * cos(rad);
						enemy[i][j].y = j * BLOCK + 64 * sin(rad);
					}
					break;
				case 34: sin_move_y(i, j); break;
				case 35:
					if (enemy[i][j].dire == 0) {
						rad = (enemy[i][j].rad + deg  * (0.6 + enemy[i][j].m_rad / 10)) * PI / 180.0;
						enemy[i][j].x = i * BLOCK + 64 * cos(rad);
						enemy[i][j].y = j * BLOCK + 64 * sin(rad);
					}
					else {
						rad = (enemy[i][j].rad - deg  * (0.6 + enemy[i][j].m_rad / 10)) * PI / 180.0;
						enemy[i][j].x = i * BLOCK + 64 * cos(rad);
						enemy[i][j].y = j * BLOCK + 64 * sin(rad);
					}
					break;
				case 36:
					rad = (enemy[i][j].rad - deg) * PI / 180.0 * (0.6 + enemy[i][j].m_rad / 10);
					enemy[i][j].x = i * BLOCK + 64 * cos(rad);
					enemy[i][j].y = j * BLOCK + 64 * sin(rad);
					break;
				case 43:	//主人公を追いかける敵
					ang = atan2((double)((player.y + HERO_SIZE_Y / 2) - (enemy[i][j].y + enemy[i][j].size_y * 0.25)), (double)((player.x + HERO_SIZE_X / 4) - (enemy[i][j].x + enemy[i][j].size_x * 0.25)));
					enemy[i][j].vx = cos(ang) * enemy[i][j].m_rad * 0.25;
					enemy[i][j].vy = sin(ang) * enemy[i][j].m_rad * 0.25;
					break;

				case 47:enemy[i][j].jfly = 1; break;
				case 48:
					/*enemy[i][j].vx = -1;
					if (enemy[i][j].countx >= -32) {
						enemy[i][j].x = i * BLOCK;
						enemy[i][j].countx = 0;
					}*/
					break;
				case 49:enemy[i][j].jfly = 1; break;
				case 51:
					if (enemy[i][j].vy == 0 && enemy[i][j].y > BLOCK * 10)
						enemy[i][j].county++;
					if (enemy[i][j].jfly == 0) {
						int ejp;//敵がジャンプする間隔
						if (mapload < 1000)
							ejp = 400;
						else if (mapload < 2000)
							ejp = 400;
						else
							ejp = 300;
						int d_life;//減ったhp量
						if (mapload < 1000)
							d_life = 3 - enemy[i][j].life;
						else if (mapload < 2000)
							d_life = 4 - enemy[i][j].life;
						else if (mapload < 3000)
							d_life = 6 - enemy[i][j].life;
						else if (mapload < 4000)
							d_life = 7 - enemy[i][j].life;
						if (enemy[i][j].county >= ejp && enemy[i][j].y > BLOCK * 10) {
							if (d_life <= 2)
								enemy[i][j].vy = -23;
							else
								enemy[i][j].vy = -18 - GetRand(5);
							enemy[i][j].county = 0;
						}
						if (d_life >= 4 && enemy[i][j].v_flag == 0) {
							enemy[i][j].vx *= 2;
							enemy[i][j].v_flag = 1;
						}
					}
					enemy[i][j].jfly = 1;
					if (enemy[i][j].m_count > 0)
						enemy[i][j].m_count--;
					break;
				case 52:
					if (enemy[i][j].countx >= 90) {
						enemy[i][j].vx *= -1;
						enemy[i][j].countx = 0;
					}
					break;
				case 53://消える床の着地判定
					if (enemy[i][j].life > 0 && enemy[i][j].countx < 0) {
						if ((i * BLOCK < player.x + HERO_SIZE_X && player.x - HERO_SIZE_X < i * BLOCK) &&
							(j * BLOCK == player.y + HERO_SIZE_Y)) {
							enemy[i][j].countx = 0;
						}
					}
					break;
				case 54: enemy[i][j].jfly = 1; break;
				case 56:
					if (player.jp2 == 1 && enemy[i][j].jfly == 0)
						enemy[i][j].vy -= 15;
					enemy[i][j].jfly = 1;
					break;

				case 57:	//青い雲
					if (enemy[i][j].rad > 30) {
						if (enemy[i][j].x < player.x)
							if (enemy[i][j].x < player.x - BLOCK * 6)
								enemy[i][j].vx = enemy[i][j].m_rad * 2;
							else if (enemy[i][j].x < player.x - BLOCK * 4)
								enemy[i][j].vx = enemy[i][j].m_rad;
							else
								enemy[i][j].vx = enemy[i][j].m_rad * 0.5;
						else if (enemy[i][j].x > player.x)
							if (enemy[i][j].x > player.x + BLOCK * 6)
								enemy[i][j].vx = -enemy[i][j].m_rad * 2;
							else if (enemy[i][j].x > player.x + BLOCK * 4)
								enemy[i][j].vx = -enemy[i][j].m_rad;
							else
								enemy[i][j].vx = -enemy[i][j].m_rad * 0.5;
							enemy[i][j].rad = 0;
					}
					else
						enemy[i][j].rad++;
					break;

				case 58:	//黒い雲
					if (enemy[i][j].rad > 30) {
						if (enemy[i][j].x < player.x)
							if (enemy[i][j].x < player.x - BLOCK * 6)
								enemy[i][j].vx = enemy[i][j].m_rad * 2;
							else if (enemy[i][j].x < player.x - BLOCK * 4)
								enemy[i][j].vx = enemy[i][j].m_rad;
							else
								enemy[i][j].vx = enemy[i][j].m_rad * 0.5;
						else if (enemy[i][j].x > player.x)
							if (enemy[i][j].x > player.x + BLOCK * 6)
								enemy[i][j].vx = -enemy[i][j].m_rad * 2;
							else if (enemy[i][j].x > player.x + BLOCK * 4)
								enemy[i][j].vx = -enemy[i][j].m_rad;
							else
								enemy[i][j].vx = -enemy[i][j].m_rad * 0.5;
							enemy[i][j].rad = 0;
					}
					else
						enemy[i][j].rad++;
					break;
				}
			}
			//hp0でも動かす敵
			switch (enemy[i][j].species) {
			case 37:	//上下に動き続けて画面外に出たら反対側から出てくる敵
				if (enemy[i][j].vy > 0) {
					if (enemy[i][j].y >= BLOCK * (height_size + 2)) {
						enemy[i][j].life = 1;
						enemy[i][j].y = -enemy[i][j].size_y;
					}
				}
				else if (enemy[i][j].y < -enemy[i][j].size_y) {
					enemy[i][j].life = 1;
					enemy[i][j].y = BLOCK * (height_size + 2);
				}
				break;
			case 38:	//上下に動き続けて画面外に出たら反対側から出てくるブロック
				if (enemy[i][j].vy > 0) {
					if (enemy[i][j].y >= BLOCK * (height_size + 2)) {
						enemy[i][j].life = 1;
						enemy[i][j].y = -enemy[i][j].size_y;
					}
				}
				else if (enemy[i][j].y < -enemy[i][j].size_y) {
					enemy[i][j].life = 1;
					enemy[i][j].y = BLOCK * (height_size + 2);
				}
				break;
			case 41://上下に揺れる敵
				if (enemy[i][j].x < -enemy[i][j].size_x) {//画面左の外に出たら右端に戻す
					enemy[i][j].life = 1;
					enemy[i][j].x = BLOCK * width_size;
				}
				else if (enemy[i][j].x > BLOCK * width_size) {//画面右の外に出たら左端に戻す
					enemy[i][j].life = 1;
					enemy[i][j].x = -enemy[i][j].size_x;
				}
				enemy[i][j].y = j * BLOCK + cos(enemy[i][j].x / 40 + enemy[i][j].rad) * 64;
				break;
			}
		}
	}
	for (int j = 0; j < height_size; j++)
		for (int i = 0; i < width_size; i++)
			if (kabe[i][j] == 1) {
				judge_eh(i*BLOCK, j*BLOCK);//壁に横から当たったら反転する
			}
	for (int j = 0; j < height_size; j++)
		for (int i = 0; i < width_size; i++)
			if (enemy[i][j].species != 1 && enemy[i][j].species != 7 && enemy[i][j].species != 42)//動く床は除く
				if (enemy[i][j].appear == 1 && enemy[i][j].m_count == 0)
					enemy[i][j].x += enemy[i][j].vx;		//敵のｘ座標に速度を加算する

	for (int j = 0; j < height_size; j++)
		for (int i = 0; i < width_size; i++)
			if (enemy[i][j].appear == 1)
				if (kabe[i][j] == 1)
					judge_eh2(i*BLOCK, j*BLOCK);			//壁に横から重なったら壁の横にずらす

	for (int j = 0; j < height_size; j++)
		for (int i = 0; i < width_size; i++)
			if (kabe[i][j] == 1)
				judge_ev2(i*BLOCK, j*BLOCK);
			else if (kabe[i][j] == 2)
				judge_ev4(i*BLOCK, j*BLOCK);

	for (int j = 0; j < height_size; j++)
		for (int i = 0; i < width_size; i++)
			if (enemy[i][j].species != 1 && enemy[i][j].species != 7 && enemy[i][j].species != 38 && enemy[i][j].species != 42)
				if (enemy[i][j].appear == 1)
					enemy[i][j].y += enemy[i][j].vy;		//敵のｙ座標に速度を加算する

	for (int j = 0; j < height_size; j++)
		for (int i = 0; i < width_size; i++)
			if (kabe[i][j] == 1)
				judge_ev(i*BLOCK, j*BLOCK);
			else if (kabe[i][j] == 2)
				judge_ev3(i*BLOCK, j*BLOCK);//すり抜け床の判定

	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			if (enemy[i][j].appear == 1) {
				if (kabe[i][j] == 1) {
					judge_eh2(i*BLOCK, j*BLOCK);			//壁に縦から重なったら壁の上下にずらす
					judge_ev(i*BLOCK, j*BLOCK);
				}
			}
		}
	}

	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			enemy[i][j].by = enemy[i][j].y;
		}
	}

	//攻撃判定
	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			if (player.attack) {
				if ((player.dire == 0 && (enemy[i][j].x < player.x + HERO_SIZE_X + ATTACK_SIZE_X && player.x + ATTACK_SIZE_X < enemy[i][j].x + enemy[i][j].size_x) &&
					(enemy[i][j].y < player.y + ATTACK_SIZE_Y && player.y < enemy[i][j].y + enemy[i][j].size_y)) ||			//右を向いていた時の処理
					(player.dire == 1 && (enemy[i][j].x < player.x + HERO_SIZE_X - ATTACK_SIZE_X && player.x - ATTACK_SIZE_X < enemy[i][j].x + enemy[i][j].size_x) &&
						(enemy[i][j].y < player.y + ATTACK_SIZE_Y && player.y < enemy[i][j].y + enemy[i][j].size_y))) {				//左を向いていた時の処理
					if (enemy[i][j].muteki == 0 && enemy[i][j].life != 0) {
						if (enemy[i][j].species != 4 || enemy[i][j].species != 54) {//アイテムは攻撃しても消えない
							enemy[i][j].life--;
							if (enemy[i][j].life == 0) {
								enemy[i][j].vanish = 1;
								enemy[i][j].vanish_x = enemy[i][j].x + (enemy[i][j].size_x - 32) / 2;
								enemy[i][j].vanish_y = enemy[i][j].y + (enemy[i][j].size_y - 32) / 2;
							}
							PlaySoundMem(music.attack2, DX_PLAYTYPE_BACK);
							if (enemy[i][j].species == 49 || enemy[i][j].species == 51)
								enemy[i][j].muteki = 120;
							if (enemy[i][j].life == 0 && GetRand(100) < enemy[i][j].drop) {//アイテムのドロップ
								enemy[i][j].species = 4;
								enemy[i][j].x += (enemy[i][j].size_x - 32) * 0.5;//敵の中心にアイテムが出るようにする
								enemy[i][j].vx = 0;
								enemy[i][j].vy = 0;
								enemy[i][j].hantei = 1;
								enemy[i][j].life = 1;
								enemy[i][j].size_x = 32;
								enemy[i][j].size_y = 32;
							}
						}
					}
				}
			}

			//壊れる壁
			if (enemy[i][j].species == 3 && enemy[i][j].life <= 0) {
				kabe[i][j] = 0;
			}

			//ボスの無敵減少
			if (enemy[i][j].species == 49 || enemy[i][j].species == 51) {
				if (enemy[i][j].muteki > 0) {
					enemy[i][j].muteki--;
				}
				if (enemy[i][j].life == 0) {
					boss = 1;
				}
			}
		}
	}
}

void sin_move(int i, int j) {

	enemy[i][j].rad += 0.03125;

	//PIまでの移動距離とPIから2PIまでの移動距離を同じにする
	if (enemy[i][j].rad >= PI && enemy[i][j].rad < PI + 0.03125) {
		enemy[i][j].rad = PI;
	}
	if (enemy[i][j].rad >= 2 * PI) {
		enemy[i][j].rad = 0;
	}

	enemy[i][j].vx = enemy[i][j].sin_v * sin(enemy[i][j].rad);
}

void sin_move_y(int i, int j) {

	enemy[i][j].rad += 0.03125;

	//PIまでの移動距離とPIから2PIまでの移動距離を同じにする
	if (enemy[i][j].rad >= PI && enemy[i][j].rad < PI + 0.03125) {
		enemy[i][j].rad = PI;
	}
	if (enemy[i][j].rad >= 2 * PI) {
		enemy[i][j].rad = 0;
	}

	enemy[i][j].vy = enemy[i][j].sin_v * sin(enemy[i][j].rad);
}
