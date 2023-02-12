#include"DxLib.h"
#include"function.h"
#include"extern.h"

void playerInit() {

	player.x = 32;		//プレイヤーの初期ｘ座標
	player.y = 384;		//プレイヤーの初期ｙ座標
	player.by = 0;
	player.vx = 0;
	player.vx2 = 0;
	player.vy = 0;
	player.size_x = 32;
	player.jfly = 1;
	//イージーは体力3、他は2
	if (mapload / 1000 == 0) {
		player.maxlife = 3;
	}
	else {
		player.maxlife = 2;
	}
	player.crouch = 0;	//しゃがみ、未使用
	player.jp2 = 0;
	player.muteki = 0;
	player.dire = 0;
	player.attack = 0;
	player.kabe_r = 0;
	player.kabe_l = 0;
	player.mv = 0;
	player.dire_m = 0;		//プレイヤーの向きを右向きにする
	player.footcount = 0;	//プレイヤーの足の動き
}