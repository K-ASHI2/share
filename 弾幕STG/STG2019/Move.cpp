#include"DxLib.h"
#include"extern.h"
#include"function.h"
#include"math.h"

void MovePlayer() {

	//喰らいボム
	if (player.inope == 2) {
		if (button[KEY_BOMB] == 1 && player.bomb_c == 0 && player.bomb > 0) {
			player.bomb--;
			player.bomb_c = player.bomb_t;
			player.muteki = player.bomb_t + 60;
			player.bomb_x = player.x;
			player.bomb_y = player.y;
			player.inope = 0;	//操作可能にする
			player.damaged = 0;	//被弾状態から元に戻す
		}
	}

	//被弾など移動不能時間は動けないようにする
	if (player.inope != 0) {
		return;
	}

	int k = 0;	//2方向以上押されていたらルート2の速度で動く
	double pv;	//プレイヤーの速度(高速と低速とキャラで変動する)

	if (button[KEY_BOMB] == 1 && player.bomb_c == 0 && player.bomb > 0) {	//ボム
		player.bomb--;	//ボムの消費
		player.bomb_c = player.bomb_t;	//ボムの描画・判定時間
		player.muteki = player.bomb_t + 60;	//ボムの無敵時間
		player.bomb_x = player.x;
		player.bomb_y = player.y;
	}
	if (button[KEY_SLOW] > 0) {	//低速移動時
		pv = PLV;
		player.slow_move = 1;
	}
	else {	//高速移動
		if (player.character == player.L_Magician_A || player.character == player.L_Magician_B) {
			pv = PHHV;
		}
		else {
			pv = PHLV;
		}
		player.slow_move = 0;
	}
	if (player.character == player.L_Magician_A && player.bomb_c > 0) {
		pv /= 5.0;
	}
	if (button[KEY_RIGHT] > 0) {
		player.vx = pv;
		k++;
	}
	if (button[KEY_LEFT] > 0) {
		player.vx -= pv;
		k++;
	}
	if (button[KEY_DOWN] > 0) {
		player.vy = pv;
		k++;
	}
	if (button[KEY_UP] > 0) {
		player.vy -= pv;
		k++;
	}

	//2つのボタンが同時に押されている時だけルート2分の1の速度にする
	if (k == 2) {
		player.vx *= (root2 * 0.5);
		player.vy *= (root2 * 0.5);
	}

	//速度の加算
	player.x += player.vx;
	player.y += player.vy;

	//加速度を0に戻す
	player.vx = 0;
	player.vy = 0;

	//画面外に出ないようにする
	if(player.x < G_W_LEFT + PLAYER_SIZE * 2)
		player.x = G_W_LEFT + PLAYER_SIZE * 2;
	if(player.x  > G_W_RIGHT - PLAYER_SIZE * 2)
		player.x = G_W_RIGHT - PLAYER_SIZE * 2;
	if(player.y < G_W_UPPER + PLAYER_SIZE * 2)
		player.y = G_W_UPPER + PLAYER_SIZE * 2;
	if(player.y > G_W_LOWER - PLAYER_SIZE)
		player.y = G_W_LOWER - PLAYER_SIZE;
}

//アイテムの移動
void MoveItem(){

	//上部回収
	//上部回収のラインより上にいるならアイテムを回収モードにする
	if (player.y < ITEM_GET_BORDER) {
		for (int i = 0; i < ITEM; i++) {
			if (item[i].hp != 0) {
				item[i].collect = 1;
			}
		}
	}
	for(int i = 0;i < ITEM;i++){
		if(item[i].hp){
			//上部回収中のアイテムは自機に向かって移動する
			if (item[i].collect == 1) {
				double ang = atan2((double)((player.y + player.size / 2) - item[i].y), (double)((player.x + player.size / 2) - item[i].x));
				item[i].vx = cos(ang) * 7;
				item[i].vy = sin(ang) * 7;
			}
			//低速移動中はゆっくり回収する
			else if (item[i].collect == 2) {
				double ang = atan2((double)((player.y + player.size / 2) - item[i].y), (double)((player.x + player.size / 2) - item[i].x));
				item[i].vx = cos(ang) * 4;
				item[i].vy = sin(ang) * 4;
			}
			else {
				item[i].vy += 0.3;
				if (item[i].vy > 2) {
					item[i].vy = 2;
				}
			}
			item[i].x += item[i].vx;
			item[i].y += item[i].vy;
			if(item[i].y >600){
				item[i].hp = 0;
			}
		}
	}
}
