#include"DxLib.h"
#include"extern.h"
#include"function.h"
#include"math.h"

//ゲームプレイ中の描画
//背景→ボム→自機の弾→アイテム→自機→敵の弾→敵の順に描画する
void DrawPlay() {

	//背景の描画
	DrawBackGround();

	//ボムの描画
	if (player.bomb_c > 0) {
		BombEffect();
	}

	//敵などの消滅演出
	DrawVanished();

	//自機の弾の描画
	for (int i = 0; i < BULLET; i++) {
		//消滅が始まった弾は透明になって消える
		if (playerbullet[i].vanish > 0) {
			//レーザーは消滅を描画しない
			if (playerbullet[i].pbkind != 5 && playerbullet[i].pbkind != 12 && playerbullet[i].pbkind != 13 && playerbullet[i].pbkind != 14) {
				if (playerbullet[i].pbkind == 3) {
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, 32 * playerbullet[i].vanish / P_BULLET_BUNISH);
				}
				else if (playerbullet[i].pbkind == 9 || playerbullet[i].pbkind == 15) {
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, 116 * playerbullet[i].vanish / P_BULLET_BUNISH);
				}
				else if (playerbullet[i].pbkind == 0 || playerbullet[i].pbkind == -1 || playerbullet[i].pbkind == 6 || playerbullet[i].pbkind == 7 || playerbullet[i].pbkind == 8) {
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, 228 * playerbullet[i].vanish / P_BULLET_BUNISH);
				}
				else {
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128 * playerbullet[i].vanish / P_BULLET_BUNISH);
				}
				DrawRotaGraph((int)playerbullet[i].x, (int)playerbullet[i].y, 1, 0, playerbullet[i].img, TRUE);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			}
			playerbullet[i].vanish--;
		}
		//存在する弾とこのフレームで敵に当たって消滅する弾を描画する
		if (playerbullet[i].hp != 0) {
			if (playerbullet[i].pbkind == 3) {
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 32);
			}
			else if (playerbullet[i].pbkind == 9 || playerbullet[i].pbkind == 15) {
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 116);
			}
			else if (playerbullet[i].pbkind == 0 || playerbullet[i].pbkind == -1 || playerbullet[i].pbkind == 6 || playerbullet[i].pbkind == 7 || playerbullet[i].pbkind == 8) {
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 228);
			}
			else {
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
			}
			//レーザーは下を基準として描画する
			if (playerbullet[i].pbkind == 5 || playerbullet[i].pbkind == 12 || playerbullet[i].pbkind == 13 || playerbullet[i].pbkind == 14) {
				DrawGraph((int)playerbullet[i].x - (int)playerbullet[i].size, (int)playerbullet[i].y - 800, playerbullet[i].img, TRUE);
			}
			else {
				DrawRotaGraph((int)playerbullet[i].x, (int)playerbullet[i].y, 1, 0, playerbullet[i].img, TRUE);
			}
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
	}

	//自機
	//無敵時間中は点滅させながら描画する
	//無敵終了が近づいたら点滅をやめる
	if (player.muteki % 10 < 5 && player.muteki > 40) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 64);
	}
	switch (player.character) {
	case player.D_Magician_A: DrawRotaGraph((int)player.x, (int)player.y + 10, 1, 0, img.player1_1, TRUE); break;
	case player.D_Magician_B: DrawRotaGraph((int)player.x, (int)player.y + 10, 1, 0, img.player1_1, TRUE); break;
	case player.L_Magician_A: DrawRotaGraph((int)player.x, (int)player.y + 10, 1, 0, img.player2_1, TRUE); break;
	case player.L_Magician_B: DrawRotaGraph((int)player.x, (int)player.y + 10, 1, 0, img.player2_1, TRUE); break;
	}
	if (player.muteki % 10 < 5 && player.muteki > 40) {
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}

	//低速移動時の自機の判定(操作可能時のみ)
	if (player.slow_move == 1 && player.inope == 0) {
		//自機が赤いので判定の色を変える
		if (player.character == player.L_Magician_A || player.character == player.L_Magician_B) {
			DrawRotaGraph((int)player.x, (int)player.y, 1, 0, img.player_J2, TRUE);
		}
		else {
			DrawRotaGraph((int)player.x, (int)player.y, 1, 0, img.player_J1, TRUE);
		}
	}
	//被弾エフェクト
	if (player.d_effect > 0) {
		//一瞬だけ濃くなってから少しずつ透過していく
		if (player.d_effect < 40) {
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180 * player.d_effect / 30);
		}
		//最初から半透明で描画する
		else {
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
		}
		DrawRotaGraph((int)player.damaged_x, (int)player.damaged_y, sqrt((double)(DAMEGED_EFFECT - player.d_effect) / DAMEGED_EFFECT) * 1.5, 0, img.playerdamaged, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		player.d_effect--;
	}

	//アイテムの描画
	for (int i = 0; i < ITEM; i++) {
		if (item[i].hp > 0) {
			switch (item[i].kind) {
			case 0: break;
			case 1: DrawRotaGraph(item[i].x, item[i].y, 1, 0, img.score_item, TRUE); break;
			case 2: DrawRotaGraph(item[i].x, item[i].y, 1, 0, img.power_item, TRUE); break;
			case 3: DrawRotaGraph(item[i].x, item[i].y, 1, 0, img.power_item_L, TRUE); break;
			case 4: DrawRotaGraph(item[i].x, item[i].y, 1, 0, img.item, TRUE); break;
			}
		}
	}

	//敵の弾の描画
	for (int i = 0; i < ENEMYBULLET; i++) {
		if (enemybullet[i].hp != 0) {
			//弾の種類によって描画する弾を変える
			switch (enemybullet[i].kind) {
			case ebk_blue_S: DrawRotaGraph((int)enemybullet[i].x, (int)enemybullet[i].y, 1, 0, img.bluebullet_S, TRUE); break;
			case ebk_red_S: DrawRotaGraph((int)enemybullet[i].x, (int)enemybullet[i].y, 1, 0, img.redbullet_S, TRUE); break;
			case ebk_yellow_S: DrawRotaGraph((int)enemybullet[i].x, (int)enemybullet[i].y, 1, 0, img.yellowbullet_S, TRUE); break;
			case ebk_blue_M: DrawRotaGraph((int)enemybullet[i].x, (int)enemybullet[i].y, 1, 0, img.bluebullet_M, TRUE); break;
			case ebk_red_M: DrawRotaGraph((int)enemybullet[i].x, (int)enemybullet[i].y, 1, 0, img.redbullet_M, TRUE); break;
			case ebk_yellow_M: DrawRotaGraph((int)enemybullet[i].x, (int)enemybullet[i].y, 1, 0, img.yellowbullet_M, TRUE); break;
			case ebk_blue_L: DrawRotaGraph((int)enemybullet[i].x, (int)enemybullet[i].y, 1, 0, img.bluebullet_L, TRUE); break;
			case ebk_red_L: DrawRotaGraph((int)enemybullet[i].x, (int)enemybullet[i].y, 1, 0, img.redbullet_L, TRUE); break;
			case ebk_yellow_L: DrawRotaGraph((int)enemybullet[i].x, (int)enemybullet[i].y, 1, 0, img.yellowbullet_L, TRUE); break;
			case ebk_snow_S: DrawRotaGraph((int)enemybullet[i].x, (int)enemybullet[i].y, 1, PI * 2 * stageTimeCount / 180, img.snowbullet_S, TRUE); break;
			case ebk_snow_M: DrawRotaGraph((int)enemybullet[i].x, (int)enemybullet[i].y, 1, -PI * 2 * stageTimeCount / 180, img.snowbullet_M, TRUE); break;
			case ebk_fire_S: DrawRotaGraph((int)enemybullet[i].x, (int)enemybullet[i].y, 1, enemybullet[i].ang - PI / 2, img.firebullet_S, TRUE); break;
			case ebk_fire_M: DrawRotaGraph((int)enemybullet[i].x, (int)enemybullet[i].y, 1, 0, img.firebullet_M, TRUE); break;
			case ebk_thunder: DrawRotaGraph((int)enemybullet[i].x, (int)enemybullet[i].y, 1, enemybullet[i].ang + PI / 2, img.thunderbullet, TRUE); break;
			case ebk_star: DrawRotaGraph((int)enemybullet[i].x, (int)enemybullet[i].y, 1, PI * 2 * stageTimeCount / 180, img.star, TRUE); break;
			case ebk_star_red: DrawRotaGraph((int)enemybullet[i].x, (int)enemybullet[i].y, 1, PI * 2 * stageTimeCount / 180, img.star_red, TRUE); break;
			case ebk_star_blue: DrawRotaGraph((int)enemybullet[i].x, (int)enemybullet[i].y, 1, PI * 2 * stageTimeCount / 180, img.star_blue, TRUE); break;
			}
		}
	}

	//敵の描画
	for (int i = 0; i < ENEMY; i++) {
		if (enemy[i].hp != 0) {
			int TurnFlag = 0;
			//左に移動している敵は反転表示する
			if (enemy[i].vx < 0) {
				TurnFlag = 1;
			}
			switch(enemy[i].kind){
			case 0: DrawRotaGraph(enemy[i].x, enemy[i].y, 1, 0, img.ghost_S, TRUE, TurnFlag); break;
			case 1: DrawRotaGraph(enemy[i].x, enemy[i].y, 1, 0, img.redghost_S, TRUE, TurnFlag); break;
			case 2: DrawRotaGraph(enemy[i].x, enemy[i].y, 1, 0, img.blueghost_S, TRUE, TurnFlag); break;
			case 3: DrawRotaGraph(enemy[i].x, enemy[i].y, 1, 0, img.yellowghost_S, TRUE, TurnFlag); break;
			case 4: DrawRotaGraph(enemy[i].x, enemy[i].y, 2, 0, img.ghost_S, TRUE, TurnFlag); break;
			case 5: DrawRotaGraph(enemy[i].x, enemy[i].y, 2, 0, img.redghost_S, TRUE, TurnFlag); break;
			case 6: DrawRotaGraph(enemy[i].x, enemy[i].y, 2, 0, img.blueghost_S, TRUE, TurnFlag); break;
			case 7: DrawRotaGraph(enemy[i].x, enemy[i].y, 2, 0, img.yellowghost_S, TRUE, TurnFlag); break;
			}
		}
	}
	//ボスの描画
	if (boss.totalhp > 0 || (boss_flag == eb_boss && boss.mode == 0)) {
		DrawRotaGraph(boss.x, boss.y, 1, 0, img.boss_magician, TRUE);
	}

	//ゲームプレイ中の画面外の描画
	DrawPlayWindow();
}

/*
 * DrawRotaGraphは座標の位置を中心にし、その位置に画像を表示するが、画像のドットが偶数の時上手くできない。
 * 画像の中心はintであり、一つのドットを中心としている。ドットは0から始まるため、大きさ÷2の時実際の中心の右下が中心となってしまう。
 * 例えば、大きさ4*4の場合4/2=2で左から3番目、上から3番目が中心となってしまう。大きさ5*5の場合5/2=2で画像の中心が正しくなる。
 */

//消滅することが確定している敵や弾に対して消滅エフェクトを描画する。
void DrawVanished() {

	for (int i = 0; i < ENEMY; i++) {
		if (enemy[i].vanish > 0) {
			switch (enemy[i].vanish_kind) {
			case 0:	DrawRotaGraph(enemy[i].x, enemy[i].y, 1, 0, ani.EnemyVanish1[ENEMY_BUNISH - enemy[i].vanish], TRUE); break;
			case 1:	DrawRotaGraph(enemy[i].x, enemy[i].y, 1, 0, ani.EnemyVanish2[ENEMY_BUNISH - enemy[i].vanish], TRUE); break;
			case 2:	DrawRotaGraph(enemy[i].x, enemy[i].y, 1, 0, ani.EnemyVanish3[ENEMY_BUNISH - enemy[i].vanish], TRUE); break;
			case 3:	DrawRotaGraph(enemy[i].x, enemy[i].y, 1, 0, ani.EnemyVanish4[ENEMY_BUNISH - enemy[i].vanish], TRUE); break;
			case 4:	DrawRotaGraph(enemy[i].x, enemy[i].y, 1, 0, ani.EnemyVanish5[ENEMY_BUNISH - enemy[i].vanish], TRUE); break;
			}
			enemy[i].vanish--;
		}
	}
	for (int i = 0; i < ENEMYBULLET; i++) {
		if (enemybullet[i].vanish > 0) {
			switch (enemybullet[i].color) {
			case ebc_blue: DrawRotaGraph(enemybullet[i].x, enemybullet[i].y, 1, 0, ani.BlueBalletVanish[E_BULLET_BUNISH - enemybullet[i].vanish], TRUE); break;
			case ebc_red: DrawRotaGraph(enemybullet[i].x, enemybullet[i].y, 1, 0, ani.RedBalletVanish[E_BULLET_BUNISH - enemybullet[i].vanish], TRUE); break;
			case ebc_yellow: DrawRotaGraph(enemybullet[i].x, enemybullet[i].y, 1, 0, ani.YellowBalletVanish[E_BULLET_BUNISH - enemybullet[i].vanish], TRUE); break;
			case ebc_null: DrawRotaGraph(enemybullet[i].x, enemybullet[i].y, 1, 0, ani.BalletVanish[E_BULLET_BUNISH - enemybullet[i].vanish], TRUE); break;
			}
			enemybullet[i].vanish--;
		}
	}
	if (boss_flag == eb_boss) {
		if (boss.vanish > 0) {
			DrawRotaGraph(boss.x, boss.y, 3.0, 0, ani.EnemyVanish1[ENEMY_BUNISH - boss.vanish], TRUE);
			DrawRotaGraph(boss.x, boss.y, 3.0, 0, ani.EnemyVanish2[ENEMY_BUNISH - boss.vanish], TRUE);
			DrawRotaGraph(boss.x, boss.y, 3.0, 0, ani.EnemyVanish3[ENEMY_BUNISH - boss.vanish], TRUE);
			DrawRotaGraph(boss.x, boss.y, 3.0, 0, ani.EnemyVanish4[ENEMY_BUNISH - boss.vanish], TRUE);
			DrawRotaGraph(boss.x, boss.y, 3.0, 0, ani.EnemyVanish5[ENEMY_BUNISH - boss.vanish], TRUE);
			boss.vanish--;
		}
	}
}

//背景の描画
void DrawBackGround() {

	//ループさせるために2つ画像を表示する
	DrawGraph(background.x, background.y, background.img, FALSE);
	DrawGraph(background.x, background.y - background.size_y, background.img, FALSE);
}	

void MoveBackground() {

	//x,y方向の速度を現座標に加え,背景の大きさでループさせる
	background.y += background.vy;
	if (background.y > background.size_y)
		background.y -= background.size_y;
}
