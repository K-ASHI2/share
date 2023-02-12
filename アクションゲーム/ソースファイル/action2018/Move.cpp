#include"Dxlib.h"
#include"extern.h"
#include"function.h"
#include<math.h>

void move() {

	//player.crouch = 0;//しゃがんでいるかどうかの判定
	player.size_y = 64;

	if (player.mv > 0)
		player.mv = 0;

	player.vx = 0;				//横移動リセット

	if (player.jfly != 0 && player.vy < MAXSPEED_Y) {	//重力
		player.vy += GRA;
	}

	player.kabe_l = 0;		//壁判定リセット
	player.kabe_r = 0;

	/*if (button[KEY_DOWN] == 1) {	//しゃがみ
		player.crouch = 1;
		player.size_y = 32;
	}*/
	player.dire_m = 0;

	if (button[KEY_LEFT] >= 1 && player.attack == 0 && button[KEY_RIGHT] == 0) {		//プレイヤーの左向き操作
		if (player.kabe_l == 0 && player.x > 0) {//左側に壁がないなら加速する
			if (!player.jfly) {//地上にいる時
				if (player.vx2 > -ACCELE_X * 5.5)//ブレーキと最初の加速
					player.vx2 -= ACCELE_X * 5.5;
				else if (player.vx2 > -MAXSPEED_X * 0.25)
					player.vx2 -= ACCELE_X * 0.7;
				else if (player.vx2 > -MAXSPEED_X * 0.5)
					player.vx2 -= ACCELE_X * 0.6;
				else if (player.vx2 > -MAXSPEED_X * 0.75)
					player.vx2 -= ACCELE_X * 0.4;
				else if (player.vx2 > -MAXSPEED_X)//最高速度でないなら
					player.vx2 -= ACCELE_X * 0.3;	//プレイヤーを-x方向に加速する
				else if (player.vx2 < -MAXSPEED_X)
					player.vx2 = -MAXSPEED_X;
			}
			else {//空中ではあまり加速しない
				if (player.vx2 > 0)//ブレーキ
					player.vx2 -= ACCELE_X * 1.5;
				else if (player.vx2 > -ACCELE_X * 5.5)//最初の加速を多めにする
					player.vx2 = -ACCELE_X * 5.5;
				else if (player.vx2 > -MAXSPEED_X * 0.25)
					player.vx2 -= ACCELE_X * 0.7;
				else if (player.vx2 > -MAXSPEED_X * 0.5)
					player.vx2 -= ACCELE_X * 0.6;
				else if (player.vx2 > -MAXSPEED_X * 0.75)
					player.vx2 -= ACCELE_X * 0.4;
				else if (player.vx2 > -MAXSPEED_X)  //最高速度でないなら
					player.vx2 -= ACCELE_X * 0.2;	//プレイヤーを-x方向に加速する
				else if (player.vx2 < -MAXSPEED_X)
					player.vx2 = -MAXSPEED_X;
			}
		}
		player.dire = 1;
		player.dire_m = 1;
	}

	//プレイヤーの右向き操作
	else if (button[KEY_RIGHT] >= 1 && player.attack == 0 && button[KEY_LEFT] == 0) {
		//右側に壁がないなら加速する
		if (player.kabe_r == 0 && player.x + HERO_SIZE_X <= BLOCK * width_size) {
			//地上にいる時
			if (!player.jfly) {
				if (player.vx2 < ACCELE_X * 5.5)	//ブレーキと最初の加速
					player.vx2 += ACCELE_X * 5.5;
				else if (player.vx2 < MAXSPEED_X * 0.25)
					player.vx2 += ACCELE_X * 0.7;
				else if (player.vx2 < MAXSPEED_X * 0.5)
					player.vx2 += ACCELE_X * 0.6;
				else if (player.vx2 < MAXSPEED_X * 0.75)
					player.vx2 += ACCELE_X * 0.4;
				else if (player.vx2 < MAXSPEED_X)	//最高速度でないなら
					player.vx2 += ACCELE_X * 0.3;	//プレイヤーをx方向に加速する
				else if (player.vx2 > MAXSPEED_X)
					player.vx2 = MAXSPEED_X;
			}
			else {//空中ではあまり加速しない
				if (player.vx2 < 0)//ブレーキ
					player.vx2 += ACCELE_X * 1.5;
				else if (player.vx2 < ACCELE_X * 5.5)	//最初の加速を多めにする
					player.vx2 = ACCELE_X * 5.5;
				else if (player.vx2 < MAXSPEED_X * 0.25)
					player.vx2 += ACCELE_X * 0.7;
				else if (player.vx2 < MAXSPEED_X * 0.5)
					player.vx2 += ACCELE_X * 0.6;
				else if (player.vx2 < MAXSPEED_X * 0.75)
					player.vx2 += ACCELE_X * 0.4;
				else if (player.vx2 < MAXSPEED_X)	//最高速度でないなら
					player.vx2 += ACCELE_X * 0.2;	//プレイヤーをx方向に加速する
				else if (player.vx2 > MAXSPEED_X)
					player.vx2 = MAXSPEED_X;
			}
		}
		player.dire = 0;
		player.dire_m = 2;
	}

	/*移動してない時の減速*/
	//地上にいる時の減速
	else if (!player.jfly) {
		//速度が速い時は速度を多く減らす
		if (player.vx2 > 0.3)
			player.vx2 -= 0.3;
		else if (player.vx2 < -0.3)
			player.vx2 += 0.3;
		//速度が遅い時は速度を少し減らす
		else if (player.vx2 > 0)
			player.vx2 -= 0.1;
		else if (player.vx2 < 0)
			player.vx2 += 0.1;
	}

	//空中いる時の減速
	else if (player.vx2 > 0.07) {
		player.vx2 -= 0.07;
	}
	else if (player.vx2 < -0.07) {
		player.vx2 += 0.07;
	}

	//速度が一定以下なら速度を0にする
	if (player.vx2 < 0.1 && player.vx2 > -0.1)
		player.vx2 = 0;

	//速度に加速度を足す
	player.vx += player.vx2;

	player.jp2 = 0;

	//プレイヤーのジャンプ操作
	if (player.jfly == 0 && button[KEY_JUMP] >= 2 && button[KEY_JUMP] <= 10 && countTime > 10) {	//10フレームの入力猶予・ゲーム開始直後に飛ぶのを防止
		player.jfly = 1;
		player.jp2 = 1;
		double vx3 = player.vx2;

		if (vx3 < 0) {
			vx3 *= -1;
		}

		//プレイヤーのy速度を変化させる
		player.vy = -(17 + (vx3 - MAXSPEED_X) * 0.4);
		
		PlaySoundMem(music.jump, DX_PLAYTYPE_BACK);
	}
	else if (player.jfly && button[KEY_JUMP] == 0 && player.vy < 0) {
		//ジャンプの上昇中にジャンプボタンが押されていない時ジャンプを止める
		player.vy *= 0.85;
	}

	//if(keyState[KEY_INPUT_R])	{		//デバッグ用ジャンプ
	//	player.vy = -5;
	//}

	player.jfly = 1;

	int k = 0;
	for (int j = 0; j < height_size; j++) {    //床の上の加速
		for (int i = 0; i < width_size; i++) {
			if (enemy[i][j].species == 1 || enemy[i][j].species == 42 || enemy[i][j].species == 7) {
				if (judge_yuka((int)enemy[i][j].x, (int)enemy[i][j].y)) {
					player.jfly = 0;
					player.vx += enemy[i][j].vx;
					k = 1;
					break;	//2つの床に重なっている時に片方しか加速しない
				}
			}
		}
		if (k == 1) {
			break;
		}
	}

	player.x += player.vx;

	//画面の強制スクロール
	if (scroll_v > 0) {
		//右端にスクロールがたどり着くまではスクロールする
		if (scroll_leftx < width_size * BLOCK - WINDOW_WIDTH) {
			scroll_leftx += scroll_v;
		}
		//画面外に出たら画面内に戻す
		if (player.x < scroll_leftx) {
			player.x = scroll_leftx;
			//player.vx2 = 0;
			player.vx = 0;
		}
		else if (player.x + player.size_x > scroll_leftx + WINDOW_WIDTH) {
			player.x = scroll_leftx + WINDOW_WIDTH - player.size_x;
			//player.vx2 = 0;
			player.vx = 0;
		}
	}

	//縦に動く床の横判定
	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			if (enemy[i][j].species == 7 || enemy[i][j].species == 38)
				if (enemy[i][j].x < player.x + HERO_SIZE_X && player.x < enemy[i][j].x + BLOCK && enemy[i][j].y - enemy[i][j].vy < player.y + HERO_SIZE_Y && player.y < enemy[i][j].y + BLOCK - enemy[i][j].vy) {
					//プレイヤーと1フレーム前のブロックが重なっている
					if (player.vx >= 0) {
						player.x = enemy[i][j].x - HERO_SIZE_X;
					}
					else {
						player.x = enemy[i][j].x + BLOCK;
					}
					player.vx = 0;
					player.vx2 = 0;
				}
		}
	}

	//横から壁にぶつかった時に壁の横に戻す
	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			if (kabe[i][j] == 1) {
				judge_h(i*BLOCK, j*BLOCK);
			}
		}
	}

	int a = 0;
	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			if (enemy[i][j].species == 1 || enemy[i][j].species == 42) {        //横に動く床の横判定
				if (enemy[i][j].vx > 0) {//床が右に動いている時
					if (enemy[i][j].x < player.x + HERO_SIZE_X && player.x < enemy[i][j].x + BLOCK
						&& enemy[i][j].y < player.y + HERO_SIZE_Y && player.y < enemy[i][j].y + BLOCK) {
						//プレイヤーが現在のブロックに重なっている
						//右に移動していてブロックのほうが遅い、つまり左側から当たった時
						if (player.vx > enemy[i][j].vx) {
							player.x = enemy[i][j].x - HERO_SIZE_X;
						}
						//それ以外なら右に移動する
						else {
							player.x = enemy[i][j].x + BLOCK;
							if (player.vx2 <= 0)
								player.vx2 = 0;
							else
								player.vx2 = enemy[i][j].vx;
						}
						a = 1;
					}
				}
				//床が左に動いている時
				else if (enemy[i][j].x <= player.x + HERO_SIZE_X && player.x < enemy[i][j].x + BLOCK
					&& enemy[i][j].y < player.y + HERO_SIZE_Y && player.y < enemy[i][j].y + BLOCK) {
					//プレイヤーが現在のブロックに重なっている
					//左への移動速度が敵より小さい、つまり左側にいる時
					if (player.vx >= enemy[i][j].vx) {
						player.x = enemy[i][j].x - HERO_SIZE_X;
						if (player.vx2 >= 0)
							player.vx2 = 0;
						else
							player.vx2 = enemy[i][j].vx;
					}
					//それ以外なら右に移動する
					else {
						player.x = enemy[i][j].x + BLOCK;//1フレーム前のブロックの位置の右に戻す
					}
					a = 1;
				}
			}
			if (a == 1)	//1度床判定でずらしたら他の横に動く床は無視する
				break;
		}
		if (a == 1)	//1度床判定でずらしたら他の横に動く床は無視する
			break;
	}

	//横に動かし終わった後のゲームオーバー処理
	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			//壁にめり込んでいたらゲームオーバー
			if (kabe[i][j] == 1) {
				judge_death(i * BLOCK, j * BLOCK);
			}

			//1フレーム前の縦に動く床と重なったらゲームオーバー
			if (enemy[i][j].species == 7) {
				judge_death3(enemy[i][j].x - enemy[i][j].vx, enemy[i][j].y - enemy[i][j].vy);
			}

			//横に動く床と重なったらゲームオーバー
			if (enemy[i][j].species == 1 || enemy[i][j].species == 42) {
				judge_death3(enemy[i][j].x, enemy[i][j].y);
			}
		}
	}

	//画面外に出ていたらゲームオーバー
	//強制スクロールする場合
	if (scroll_v > 0 /*&& scroll_leftx < width_size * BLOCK - WINDOW_WIDTH*/) {
		if (player.x < scroll_leftx || player.x + player.size_x > scroll_leftx + WINDOW_WIDTH) {
			player.life = 0;
		}
	}
	//強制スクロールしない場合
	else if (player.x < 0 || (player.x + HERO_SIZE_X) > width_size * BLOCK) {
		player.life = 0;
	}

	//横移動のゲームオーバー判定が終わった時点でゲームオーバーならその後の処理はしない
	if (player.life == 0) {
		return;
	}

	a = 0;
	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			if (enemy[i][j].species == 7 || enemy[i][j].species == 38) {		//縦に動く床の縦判定
				if ((enemy[i][j].x < player.x + HERO_SIZE_X && player.x < enemy[i][j].x + BLOCK) &&
					(enemy[i][j].y < player.y + player.vy + HERO_SIZE_Y && player.y + player.vy < enemy[i][j].y + BLOCK)) {
					//床が下に動いている時
					if (enemy[i][j].vy > 0) {
						//プレイヤーが現在のブロックに重なっている
							//下に移動していてブロックのほうが遅い、つまり上側から当たった時
						if (player.vy >= enemy[i][j].vy) {
							player.jfly = 0;
							player.y = enemy[i][j].y - HERO_SIZE_Y - enemy[i][j].vy;
							player.vy = enemy[i][j].vy;
						}
						//それ以外なら下に移動する
						else {
							player.y = enemy[i][j].y + BLOCK;
							player.vy = enemy[i][j].vy;
						}
					}
					//床が上に動いている時
					else {
						//プレイヤーが現在のブロックに重なっている
						//上への移動速度が敵より小さい、つまり上側にいる時
						if (player.vy >= enemy[i][j].vy) {
							player.jfly = 0;
							player.y = enemy[i][j].y - HERO_SIZE_Y - enemy[i][j].vy;
							player.vy = enemy[i][j].vy;//加速度を持たせる
						}
						//それ以外なら下に移動する
						else {
							player.y = enemy[i][j].y + BLOCK;
							player.vy = 0;
						}
					}
				}
			}
			if (a == 1)//1度床判定でずらしたら他の縦に動く床は無視する
				break;
		}
		if (a == 1)//1度床判定でずらしたら他の縦に動く床は無視する
			break;
	}

	player.y += player.vy;

	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			if (kabe[i][j] == 1)
				judge_v(i*BLOCK, j*BLOCK);//上下判定
			else if (kabe[i][j] == 2)
				judge_v2(i*BLOCK, j*BLOCK);
		}
	}

	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			if (enemy[i][j].species == 1 || enemy[i][j].species == 42) {     //横に動く床の縦判定
				if (enemy[i][j].x < player.x + HERO_SIZE_X && player.x < enemy[i][j].x + BLOCK && enemy[i][j].y < player.y + HERO_SIZE_Y && player.y < enemy[i][j].y + BLOCK) {
					//プレイヤーとブロックが重なっている
					if (player.vy >= 0) {
						player.jfly = 0;
						player.y = enemy[i][j].y - HERO_SIZE_Y;
						player.vy = 0;
					}
					else {
						player.vy = 0;
						player.y = (enemy[i][j].y + BLOCK);
					}
				}
			}
		}
	}

	//縦に動かし終わった後の判定
	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {

			//壁にめり込んでいたらゲームオーバー
			if (kabe[i][j] == 1) {
				judge_death(i*BLOCK, j*BLOCK);
			}

			//すり抜け床の上側と挟まっているかどうか
			if (kabe[i][j] == 2) {
				judge_death2(i*BLOCK, j*BLOCK);
			}

			//動く床と重なったらゲームオーバー
			if (enemy[i][j].species == 1 || enemy[i][j].species == 7 || enemy[i][j].species == 38 || enemy[i][j].species == 42) {
				judge_death3(enemy[i][j].x, enemy[i][j].y);
			}
		}
	}

	//1フレーム前のy座標を保存する
	player.by = player.y;

	for (int j = 0; j < height_size; j++) {      //プレイヤーと敵のあたり判定
		for (int i = 0; i < width_size; i++) {
			if (enemy[i][j].life > 0 && enemy[i][j].hantei == 1) {   //存在していて判定があるなら
				if (enemy[i][j].species == 4 || enemy[i][j].species == 54) {
					if ((enemy[i][j].x < player.x + HERO_SIZE_X && player.x < enemy[i][j].x + enemy[i][j].size_x) &&
						(enemy[i][j].y < player.y + HERO_SIZE_Y && player.y < enemy[i][j].y + enemy[i][j].size_y)) {
						enemy[i][j].life = 0;
					}
				}
				//敵のあたり判定を判定を少し狭くする
				else if ((enemy[i][j].x < player.x + HERO_SIZE_X - 3 && player.x + 3 < enemy[i][j].x + enemy[i][j].size_x) &&
					(enemy[i][j].y < player.y + HERO_SIZE_Y - 2 && player.y + 5 < enemy[i][j].y + enemy[i][j].size_y)) {
					if (enemy[i][j].species == 45) {
						PlaySoundMem(music.sw, DX_PLAYTYPE_BACK);
						sw = 1;
					}
					else if (enemy[i][j].species == 46) {
						PlaySoundMem(music.sw, DX_PLAYTYPE_BACK);
						sw = 0;
					}
					else if (enemy[i][j].species == 48) {
						gameover();
					}
					else if (player.muteki == 0) {
						PlaySoundMem(music.damage, DX_PLAYTYPE_BACK);
						player.life--;
						player.muteki = 100;   //無敵にする
					}
				}
			}
			if (enemy[i][j].species == 4 && enemy[i][j].life == 0) {	//1フレーム前にハートのhpが0になっていたなら
				if (player.life < player.maxlife)
					player.life++;
				enemy[i][j].life = -1;
				efs(efs_recover);
			}
			if (enemy[i][j].species == 54 && enemy[i][j].life == 0) {	//1フレーム前にハートのhpが0になっていたなら
				player.life = player.maxlife;
				enemy[i][j].life = -1;
				efs(efs_recover);
			}

			//弾のあたり判定を判定を少し狭くする
			for (int k = 0; k < BULLET; k++) {
				if ((enemybullet[i][j][k].x + 1 < player.x + HERO_SIZE_X - 3 && player.x + 3 < enemybullet[i][j][k].x + enemybullet[i][j][k].size_x - 1) &&
					(enemybullet[i][j][k].y + 1 < player.y + HERO_SIZE_Y - 2 && player.y + 5 < enemybullet[i][j][k].y + enemybullet[i][j][k].size_y - 1)) {
					if (enemybullet[i][j][k].life > 0) {
						if (player.muteki == 0) {
							PlaySoundMem(music.damage, DX_PLAYTYPE_BACK);
							player.life--;
							player.muteki = 100;   //無敵にする
						}
					}
				}
			}

			//スイッチに触れたらオンオフする
			if (enemy[i][j].species == 45) {
				if (sw == 0)
					enemy[i][j].life = 1;
				else
					enemy[i][j].life = 0;
			}
			if (enemy[i][j].species == 46) {
				if (sw == 1)
					enemy[i][j].life = 1;
				else
					enemy[i][j].life = 0;
			}

			//ボスが倒れたら扉が出現する
			if (enemy[i][j].species == 50 && boss == 1) {
				enemy[i][j].life = 0;
			}
		}
	}

	double c, d;

	if (player.x <= CENTER) {//プレイヤーが左端付近にいる時
		c = player.x;
		d = CENTER;
	}
	else if (player.x > width_size * BLOCK - (WINDOW_WIDTH - CENTER)) {//プレイヤーが右端付近にいる時
		c = -(width_size * BLOCK - WINDOW_WIDTH - player.x);
		d = width_size * BLOCK - (WINDOW_WIDTH - CENTER);
	}
	else {//プレイヤーが一定の位置より右にいる時描画の中心をプレイヤーの座標にする
		c = CENTER;
		d = player.x;
	}

	//スイッチによる変化
	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			if (d - CENTER - 224 < enemy[i][j].x && d + WINDOW_WIDTH - CENTER > enemy[i][j].x) {

				//赤スイッチで出る床
				if (map[i][j] == 703) {
					if (sw == 1)
						kabe[i][j] = 1;
					else
						kabe[i][j] = 0;
				}

				//緑スイッチで出る床
				if (map[i][j] == 704) {
					if (sw == 0)
						kabe[i][j] = 1;
					else
						kabe[i][j] = 0;
				}
			}
		}
	}

	judgeDoor();
}

//プレイヤーキャラの攻撃
void attack() {
	if (player.attack == 0) {
		if (button[KEY_ATTACK] == 1) {
			player.attack = 5;
			efs(efs_attack);
		}
	}
	else {
		player.attack--;
	}
}

//背景を動かす関数
void move_background() {

	//x,y方向の速度を現座標に加え,背景の大きさでループさせる
	if (background[background_n].size_y != 0) {
		background2.y = (background2.y + background2.vy) % background[background_n].size_y;
	}
}

