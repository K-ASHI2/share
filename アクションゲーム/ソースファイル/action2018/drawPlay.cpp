#include"DxLib.h"
#include"extern.h"
#include"function.h"
#include"math.h"

void drawPlay() {

	double c;	//画面の中でプレイヤーのいる位置
	double d;	//画面の中心

	//DrawFormatStringToHandle(20, 20, black, Font[0], "gameover_count:%d", gameover_count);
	//DrawFormatStringToHandle(20, 40, black, Font[0], "scroll_v:%d", scroll_v);
	//DrawFormatStringToHandle(20, 60, black, Font[0], "player.x + player.size_x:%d", (int)player.x + player.size_x);
	//DrawFormatStringToHandle(20, 80, black, Font[0], "scroll_leftx + WINDOW_WIDTH:%d", scroll_leftx + WINDOW_WIDTH);

	//強制スクロールする時は画面の中心をスクロールに合わせる
	if (scroll_v > 0) {
		c = player.x - scroll_leftx;
		d = scroll_leftx + CENTER;
	}
	else {
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
	}

	for (int i = ((int)d / BLOCK) - 14; i < ((int)d / BLOCK) + 14; i++) {
		for (int j = 0; j < height_size; j++) {
			if (i + 3 >= 0 && i - 3 < width_size) {				//横の部分より狭い範囲でマップ判断
				if (map[i][j] % 1000 == 6 || map[i][j] % 1000 == 16 || map[i][j] % 1000 == 103) {//円運動する敵
					DrawGraph(i*BLOCK - (int)player.x +(int)c- 2 * BLOCK, j * BLOCK - 2 * BLOCK, img.circle3, TRUE);//動く場所を表示する
				}
			}
		}
	}

	for (int i = ((int)d / BLOCK) - 12; i < ((int)d / BLOCK) + 14; i++) {
		for (int j = 0; j < height_size; j++) {
			if (i >= 0 && i < width_size) {				//横の部分より狭い範囲でマップ判断
				if (map[i][j] % 1000 == 7 || map[i][j] % 1000 == 506) {//上下に画面外まで動く敵
					DrawGraph(i*BLOCK - (int)player.x +(int)c, 0, img.b_line, TRUE);//動く場所を表示する
					break;//1列につき1度だけ判定すればよい
				}
			}
		}
	}

	//マップチップからの描画
	for (int j = 0; j < height_size; j++) {
		for (int i = (d / BLOCK) - 12; i < (d / BLOCK) + 14; i++) {
			if (i < width_size && i >= 0) {				//横の部分より狭い範囲でマップ判断
				int d = 0;		//向き
				if (map[i][j] >= 10000) {
					d = map[i][j] % 100000 / 10000;
				}

				switch (map[i][j] % 1000) {
				case 0:	break;
				case 100:	DrawGraph(i * BLOCK - (int)player.x + (int)c, j * BLOCK, img.togeblock4, TRUE); break;	//止まっているトゲ
				case 301:		DrawGraph2(i * BLOCK - (int)player.x + (int)c, j * BLOCK, img.yuka[1], d); break;	//床
				case 302:		DrawGraph2(i * BLOCK - (int)player.x + (int)c, j * BLOCK, img.yuka[2], d); break;	//床
				case 303:		DrawGraph2(i * BLOCK - (int)player.x + (int)c, j * BLOCK, img.yuka[3], d); break;	//床
				case 304:		DrawGraph2(i * BLOCK - (int)player.x + (int)c, j * BLOCK, img.yuka[4], d); break;	//床
				case 305:		DrawGraph2(i * BLOCK - (int)player.x + (int)c, j * BLOCK, img.yuka[0], d); break;	//床
				case 306:		DrawGraph2(i * BLOCK - (int)player.x + (int)c, j * BLOCK, img.yuka[8], d); break;	//床
				case 307:		DrawGraph2(i * BLOCK - (int)player.x + (int)c, j * BLOCK, img.kabe, d); break;	//壁
				case 308:		DrawGraph2(i * BLOCK - (int)player.x + (int)c, j * BLOCK, img.block_gray, d); break;
				case 309:		DrawGraph2(i * BLOCK - (int)player.x + (int)c, j * BLOCK, img.block_wood, d); break;
				case 500:		DrawGraph2(i * BLOCK - (int)player.x + (int)c, j * BLOCK, img.through, d); break;
				case 501:		DrawGraph2(i * BLOCK - (int)player.x + (int)c, j * BLOCK, img.toge, d); break;   //トゲ
				case 502:    
					if (enemy[i][j].life == 1)
					DrawGraph(i * BLOCK - (int)player.x + (int)c, j * BLOCK, img.block2, TRUE);
					break;  //壊れる壁

				case 503:
					if (enemy[i][j].life > 0) {
						DrawGraph(i * BLOCK - (int)player.x + (int)c, j * BLOCK, img.moveblock[0], TRUE);
						char dc[2];//カウントの数字で描画する
						itoa(enemy[i][j].county / 40, dc, 10);
						DrawStringToHandle(i * BLOCK - (int)player.x + (int)c + 8, j * BLOCK + 3, dc, GetColor(255, 0, 0), Font[1]);
					}
					break;

				case 507:	DrawGraph2(i * BLOCK - (int)player.x + (int)c, j * BLOCK, img.iceblock, d); break;

				case 601:    DrawGraph(i * BLOCK - (int)player.x + (int)c, j * BLOCK, img.taihou[2], TRUE); break;
				case 602:    DrawGraph(i * BLOCK - (int)player.x + (int)c, j * BLOCK, img.taihou[1], TRUE); break;
				case 603:    DrawTurnGraph(i * BLOCK - (int)player.x + (int)c, j * BLOCK, img.taihou[1], TRUE); break;
				case 604:    DrawGraph(i * BLOCK - (int)player.x + (int)c, j * BLOCK, img.taihou[4], TRUE); break;
				case 605:    DrawGraph(i * BLOCK - (int)player.x + (int)c, j * BLOCK, img.taihou[3], TRUE); break;
				case 606:    DrawGraph(i * BLOCK - (int)player.x + (int)c, j * BLOCK, img.taihou[5], TRUE); break;
				case 607:    DrawTurnGraph(i * BLOCK - (int)player.x + (int)c, j * BLOCK, img.taihou[5], TRUE); break;
				case 608:    DrawGraph(i * BLOCK - (int)player.x + (int)c, j * BLOCK, img.taihou[6], TRUE); break;
				case 609:    DrawTurnGraph(i * BLOCK - (int)player.x + (int)c, j * BLOCK, img.taihou[6], TRUE); break;

				case 701:    //赤スイッチ
					if (sw == 0)
						DrawGraph(i * BLOCK - (int)player.x + (int)c, j * BLOCK, img.sw[0], TRUE);
					else
						DrawGraph(i * BLOCK - (int)player.x + (int)c, j * BLOCK, img.sw[2], TRUE);
					break;
				case 702:    //緑スイッチ
					if (sw == 1)
						DrawGraph(i * BLOCK - (int)player.x + (int)c, j * BLOCK, img.sw[1], TRUE);
					else
						DrawGraph(i * BLOCK - (int)player.x + (int)c, j * BLOCK, img.sw[2], TRUE);
					break;
				case 703:	//赤スイッチで出る床
					if (sw == 1)
						DrawGraph(i * BLOCK - (int)player.x + (int)c, j * BLOCK, img.swb[0], TRUE);
					else
						DrawGraph(i * BLOCK - (int)player.x + (int)c, j * BLOCK, img.swb[2], TRUE);
					break;
				case 704:	//緑スイッチで出る床
					if (sw == 0)
						DrawGraph(i * BLOCK - (int)player.x + (int)c, j * BLOCK, img.swb[1], TRUE);
					else
						DrawGraph(i * BLOCK - (int)player.x + (int)c, j * BLOCK, img.swb[3], TRUE);
					break;
				case 705:    DrawGraph2(i * BLOCK - (int)player.x + (int)c, j * BLOCK, img.kabe, d); break;	//ファイアバーの中心

				case 801:    DrawGraph(i * BLOCK - (int)player.x + (int)c, j * BLOCK - 32, img.door[8], TRUE); break;

				//case 13:    DrawGraph(i * BLOCK - (int)player.x + (int)c, j * BLOCK, img.door[1], TRUE); break;
				//case 14:    DrawGraph(i * BLOCK - (int)player.x + (int)c, j * BLOCK, img.door[1], TRUE); break;
				//case 15:    DrawGraph(i * BLOCK - (int)player.x + (int)c, j * BLOCK, img.door[2], TRUE); break;
				/*case 66:	if (enemy[i][j].life == 0)
					DrawGraph(i * BLOCK - (int)player.x + (int)c, j * BLOCK - 32, img.door[8], TRUE); break;*/
				//default:	DrawGraph(i * BLOCK - (int)player.x + (int)c, j * BLOCK, img.null, TRUE); break;	//null
				}
			}
			else if (j == 14)
				DrawGraph(i * BLOCK - (int)player.x + (int)c, j * BLOCK, img.yuka[1], TRUE);						//最下段は床を描画
		}
	}

	int Pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	//大きい敵は一番奥に描画する
	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			if (d - CENTER - 224 < enemy[i][j].x && d + WINDOW_WIDTH - CENTER > enemy[i][j].x) {
				if (enemy[i][j].life > 0 && enemy[i][j].species == 20) {
					if (enemy[i][j].dire_x == 0) {
						DrawGraph((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y, img.enemy[27], TRUE);
					}
					else {
						DrawTurnGraph((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y, img.enemy[27], TRUE);
					}
				}
			}
		}
	}

	for (int j = 0; j < height_size; j++) {//動く床は奥に表示する
		for (int i = 0; i < width_size; i++) {
			if (d - CENTER - 160 < enemy[i][j].x && d + WINDOW_WIDTH - CENTER > enemy[i][j].x) {
				if (enemy[i][j].life > 0) {			//敵の描画
					if (enemy[i][j].species == 1) {
						DrawGraph((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y, img.moveblock[4], TRUE);   //横に動く床の描画
					}
				}
			}
		}
	}

	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			if (d - CENTER - 224 < enemy[i][j].x && d + WINDOW_WIDTH - CENTER > enemy[i][j].x) {
				if (enemy[i][j].life > 0) {			//敵の描画
					switch (enemy[i][j].species) {
					case -2:	DrawGraph((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y, img.fire, TRUE);   //炎の描画
						break;
					case 0:	
						DrawGraph2((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y, img.enemy[1], enemy[i][j].dire_x);
						/*if (enemy[i][j].dire_x == 0)
						DrawGraph((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y, img.enemy[1], TRUE);
							else
								DrawTurnGraph((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y, img.enemy[1], TRUE);*/
						break;
					case 1: break;
					case 2:	DrawGraph((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y, img.togeblock2, TRUE);
						break;
					case 3: break;
					case 4: DrawGraph((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y, img.item, TRUE); break;	//アイテムの描画
					case 5:
						if (player.x > enemy[i][j].x)
							DrawGraph((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y, img.enemy[3], TRUE);
						else
							DrawTurnGraph((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y, img.enemy[3], TRUE);
						break;
					case 6: DrawGraph2((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y, img.enemy[2], enemy[i][j].dire_x); break;
					case 7: DrawGraph((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y, img.moveblock[7], TRUE); break;	//縦に動く床の描画
					case 8: break;
					case 9: break;
					case 10:break;
					case 11:break;
					case 12: DrawGraph2((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y, img.enemy[11], enemy[i][j].dire_x); break;
					case 13: DrawGraph2((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y, img.enemy[4], enemy[i][j].dire_x); break;
					case 14: DrawGraph2((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y, img.enemy[5], enemy[i][j].dire_x); break;
					case 15:
						if (player.x > (int)enemy[i][j].x)
							DrawGraph((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y, img.enemy[6], TRUE);
						else
							DrawTurnGraph((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y, img.enemy[6], TRUE);
						break;
					case 16: DrawGraph2((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y, img.enemy[7], enemy[i][j].dire_x); break;
					case 17: DrawGraph2((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y, img.enemy[16], enemy[i][j].dire_x); break;
					case 18: DrawGraph2((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y, img.enemy[21], enemy[i][j].dire_x); break;
					case 19: DrawGraph((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y, img.meteor, TRUE); break;
					case 20: break;
					case 30:
						if (player.x > enemy[i][j].x)
							DrawGraph((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y, img.enemy[35], TRUE);
						 else
							 DrawTurnGraph((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y, img.enemy[35], TRUE);
						break;
					case 31: DrawGraph2((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y, img.enemy[32], enemy[i][j].dire_x); break;
					case 32:
						if (player.x > enemy[i][j].x)
							DrawGraph((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y, img.enemy[33], TRUE);
						else
							DrawTurnGraph((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y, img.enemy[33], TRUE);
						break;
					case 33:
						if (player.x > enemy[i][j].x)
							DrawGraph((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y, img.enemy[34], TRUE);
						else
							DrawTurnGraph((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y, img.enemy[34], TRUE);
						break;
					case 34: DrawGraph((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y, img.togeblock3, TRUE);
						break;
					case 35: DrawGraph((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y, img.togeblock, TRUE);
						break;
					case 36: DrawGraph((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y, img.togeblock, TRUE);
						break;
					case 37:
						if (enemy[i][j].vy < 0)
							DrawGraph((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y, img.fish, TRUE);
						else
							DrawTurnGraph((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y, img.fish2, TRUE);
						/*if (player.x > enemy[i][j].x)
							DrawGraph((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y, img.enemy[8], TRUE);
						else
							DrawTurnGraph((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y, img.enemy[8], TRUE);*/
						break;
					case 38: DrawGraph((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y, img.moveblock[6], TRUE); break;
					case 41:
						DrawRotaGraph((int)enemy[i][j].x - (int)player.x + (int)c + 8, enemy[i][j].y - 8 + BLOCK / 2, 1.0, 0, img.redghost_S, TRUE);
						/*if (enemy[i][j].vx > 0)
							DrawGraph((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y, img.enemy[9], TRUE);
						else
							DrawTurnGraph((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y, img.enemy[9], TRUE);*/
						break;
					case 42: DrawGraph((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y, img.moveblock[4], TRUE);	break; //横に動く床の描画

					case 43:
						if (player.x > enemy[i][j].x)
							DrawRotaGraph((int)enemy[i][j].x - (int)player.x + (int)c + 8, enemy[i][j].y - 8 + BLOCK / 2, 1.0, 0, img.ghost_S, TRUE, 1);
						else
							DrawRotaGraph((int)enemy[i][j].x - (int)player.x + (int)c + 8, enemy[i][j].y - 8 + BLOCK / 2, 1.0, 0, img.ghost_S, TRUE);
						break;

					/*case 44:
						if (player.x > enemy[i][j].x)
							DrawRotaGraph((int)enemy[i][j].x - (int)player.x + (int)c + 8, enemy[i][j].y - 8 + BLOCK / 2, 1.0, 0, img.blueghost_S, TRUE, 1);
						else
							DrawRotaGraph((int)enemy[i][j].x - (int)player.x + (int)c + 8, enemy[i][j].y - 8 + BLOCK / 2, 1.0, 0, img.blueghost_S, TRUE);
						break;*/

					case 45: break; //スイッチ
					case 46: break; //スイッチ

					case 47: DrawGraph2((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y, img.enemy[2], enemy[i][j].dire_x); break;
						break;
					case 48: DrawGraph((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y, img.maguma, TRUE); break;
					case 49:
						if (enemy[i][j].muteki == 0) {
							if (enemy[i][j].dire_x == 0)
								DrawGraph((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y - 32, img.boss[1], TRUE);//大砲の大きさ32を引く
							else
								DrawTurnGraph((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y - 32, img.boss[1], TRUE);
						}
						else {
							if (enemy[i][j].muteki % 5 == 1)
									DrawGraph2((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y - 32, img.boss[4], enemy[i][j].dire_x);
								else
									DrawGraph2((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y - 32, img.boss[1], enemy[i][j].dire_x);
						}
						break;
					case 50: break;
					case 51:
						if (enemy[i][j].muteki == 0) {
							if (enemy[i][j].dire_x == 0)
								DrawGraph((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y - 32, img.boss[3], TRUE);
							else
								DrawTurnGraph((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y - 32, img.boss[3], TRUE);
						}
						else {
							if (enemy[i][j].muteki % 5 == 1)
								DrawGraph2((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y - 32, img.boss[4], enemy[i][j].dire_x);
							else
								DrawGraph2((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y - 32, img.boss[3], enemy[i][j].dire_x);
						}
						break;
					case 52: DrawGraph2((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y, img.enemy[1], enemy[i][j].dire_x); break;
					case 53: break;
					case 54: DrawGraph((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y, img.max_item, TRUE); break;
					case 55: break;
					case 56: DrawGraph2((int)enemy[i][j].x - (int)player.x + (int)c, enemy[i][j].y, img.enemy[12], enemy[i][j].dire_x); break;

					case 57:	//青い雲
						DrawRotaGraph((int)enemy[i][j].x - (int)player.x + (int)c + BLOCK / 2, enemy[i][j].y - 10 + BLOCK / 2, 1.0, 0, img.cloud_monster_blue, TRUE);
						break;

					case 58:	//雲
						DrawRotaGraph((int)enemy[i][j].x - (int)player.x + (int)c + BLOCK / 2, enemy[i][j].y - 10 + BLOCK / 2, 1.0, 0, img.cloud_monster, TRUE);
						break;
					case 59:	//星
						DrawRotaGraph((int)enemy[i][j].x - (int)player.x + (int)c + 13, enemy[i][j].y + 13, 1.0, PI * 2 * countTime / 70, img.star, TRUE);
						break;
					case 60:	//青い星
						DrawRotaGraph((int)enemy[i][j].x - (int)player.x + (int)c + 13, enemy[i][j].y + 13, 1.0, PI * 2 * countTime / 50, img.star_blue, TRUE);
						break;
					case 61:	//赤い星
						DrawRotaGraph((int)enemy[i][j].x - (int)player.x + (int)c + 13, enemy[i][j].y + 13, 1.0, PI * 2 * countTime / 60, img.star_red, TRUE);
						break;
					}
				}
			}
		}
	}

	//時間が無駄になりすぎ
	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			for (int k = 0; k < BULLET; k++) {      //敵の弾の描画
				if (enemybullet[i][j][k].life == 1) {
					switch (enemybullet[i][j][k].species) {
					case 0:
						DrawGraph(enemybullet[i][j][k].x - (int)player.x + (int)c, enemybullet[i][j][k].y, img.bullet[0], TRUE); break;
					case 1:
						DrawGraph(enemybullet[i][j][k].x - (int)player.x + (int)c, enemybullet[i][j][k].y, img.bullet[1], TRUE); break;
					case 2:
						DrawGraph(enemybullet[i][j][k].x - (int)player.x + (int)c, enemybullet[i][j][k].y, img.bullet[2], TRUE); break;
					case 3:
						DrawGraph(enemybullet[i][j][k].x - (int)player.x + (int)c, enemybullet[i][j][k].y, img.bullet[3], TRUE); break;
					case 4:
						DrawGraph(enemybullet[i][j][k].x - (int)player.x + (int)c, enemybullet[i][j][k].y, img.bullet[4], TRUE); break;
					case 5:
						DrawGraph(enemybullet[i][j][k].x - (int)player.x + (int)c, enemybullet[i][j][k].y, img.bullet[5], TRUE); break;
					case 6:
						DrawRotaGraph(enemybullet[i][j][k].x + enemybullet[i][j][k].size_x / 2 - (int)player.x + (int)c, enemybullet[i][j][k].y, 1.0, PI * 2 * countTime / 60, img.snowbullet_M, TRUE); break;
					case 7:
						DrawRotaGraph(enemybullet[i][j][k].x + enemybullet[i][j][k].size_x / 2 - (int)player.x + (int)c, enemybullet[i][j][k].y, 1.0, 0, img.thunderbullet, TRUE); break;
					}
				}
			}
		}
	}

	if (gameover_count >= 0) {
		if (gameover_count - 50 > 0) {
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 120 * (gameover_count - 60) / DAMEGED_EFFECT);
		}
		else {
			//表示しない
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0);
		}
	}
	else {
		player.footcount++;
	}
	if (player.attack == 0) {
		if (player.dire == 0) {	//主人公の描画
			if (player.footcount % 20 >= 10 && player.dire_m == 2)
				if (player.muteki == 0)
					DrawGraph(c, player.y, img.hito[5], TRUE);		//右向き
				else if (player.muteki % 5 != 0 && player.muteki % 5 != 1)
					DrawGraph(c, player.y, img.hito[5], TRUE);		//右向き無敵
				else
					DrawGraph(c, player.y, img.hito[7], TRUE);		//右向き無敵
			else
				if (player.muteki == 0)
					DrawGraph(c, player.y, img.hito[6], TRUE);		//右向き
				else if (player.muteki % 5 != 0 && player.muteki % 5 != 1)
					DrawGraph(c, player.y, img.hito[6], TRUE);		//右向き無敵
				else
					DrawGraph(c, player.y, img.hito[8], TRUE);		//右向き無敵
		}
		else {
			if (player.footcount % 20 >= 10 && player.dire_m == 1)
				if (player.muteki == 0)
					DrawTurnGraph(c - 32, player.y, img.hito[5], TRUE);		//右向き
				else if (player.muteki % 5 != 0 && player.muteki % 5 != 1)
					DrawTurnGraph(c - 32, player.y, img.hito[5], TRUE);		//右向き無敵
				else
					DrawTurnGraph(c - 32, player.y, img.hito[7], TRUE);		//右向き無敵
			else
				if (player.muteki == 0)
					DrawTurnGraph(c - 32, player.y, img.hito[6], TRUE);		//左向き
				else if (player.muteki % 5 != 0 && player.muteki % 5 != 1)
					DrawTurnGraph(c - 32, player.y, img.hito[6], TRUE);		//左向き無敵
				else
					DrawTurnGraph(c - 32, player.y, img.hito[8], TRUE);		//左向き無敵
		}
	}

	if (player.attack > 0) {	//攻撃の描画
		if (player.attack > 3) {
			if (player.dire == 0)
				DrawGraph(c, player.y, img.hito[21], TRUE);
			else
				DrawTurnGraph(c - ATTACK_SIZE_X, player.y, img.hito[21], TRUE);
		}
		if (player.attack > 2 && player.attack <= 3) {
			if (player.dire == 0)
				DrawGraph(c, player.y, img.hito[22], TRUE);
			else
				DrawTurnGraph(c - ATTACK_SIZE_X, player.y, img.hito[22], TRUE);
		}
		if (player.attack > 1 && player.attack <= 2) {
			if (player.dire == 0)
				DrawGraph(c, player.y, img.hito[23], TRUE);
			else
				DrawTurnGraph(c - ATTACK_SIZE_X, player.y, img.hito[23], TRUE);
		}
		if (player.attack > 0 && player.attack <= 1) {
			if (player.dire == 0)
				DrawGraph(c, player.y, img.hito[24], TRUE);
			else
				DrawTurnGraph(c - ATTACK_SIZE_X, player.y, img.hito[24], TRUE);
		}
	}
	//被弾エフェクト
	if (gameover_count >= 0) {
		//一瞬だけ濃くなってから少しずつ透過していく
		if (gameover_count < 40) {
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180 * gameover_count / 30);
		}
		//最初から半透明で描画する
		else {
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
		}
		DrawRotaGraph((int)c, (int)player.y, sqrt((double)(DAMEGED_EFFECT - gameover_count) / DAMEGED_EFFECT) * 1.5, 0, img.playerdamaged, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}

	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			//倒したフレームから30フレームエフェクトが出る
			if (enemy[i][j].vanish >= 1 && enemy[i][j].vanish <= 30) {
				if (enemy[i][j].species == 53)
					DrawGraph(enemy[i][j].vanish_x - (int)player.x + (int)c, enemy[i][j].vanish_y, ani.convergence_r[enemy[i][j].vanish - 1], TRUE);
				else
					DrawGraph(enemy[i][j].vanish_x - (int)player.x +(int)c - 32, enemy[i][j].vanish_y - 32, ani.star_e[enemy[i][j].vanish - 1], TRUE); //倒した時のアニメーション
				if (enemy[i][j].vanish <= 30)
					enemy[i][j].vanish++;
			}
		}
	}

	int white = GetColor(255, 255, 255), black = GetColor(0, 0, 0);

	DrawGraph(0, 480, img.setumei, TRUE);  //操作説明の描画
	DrawGraph(170, 550, img.item, TRUE);//hpの描画

	if (player.life >= 2)
		DrawGraph(210, 550, img.item, TRUE);
	else
		DrawGraph(210, 550, img.item2, TRUE);

	if (player.maxlife == 3) {
		if (player.life >= 3)
			DrawGraph(250, 550, img.item, TRUE);
		else
			DrawGraph(250, 550, img.item2, TRUE);
	}

	//DrawFormatString(30,500,black,"ステージ");
	DrawFormatString(90, 500, black, "%d-%d", mapload % 1000 / 100, mapload % 1000 % 100 / 10);
	switch (mapload / 1000) {
	case 0: DrawFormatString(180, 500, black, "EASY"); break;
	case 1: DrawFormatString(180, 500, black, "NORMAL"); break;
	case 2: DrawFormatString(180, 500, black, "HARD"); break;
	//case 3:	DrawFormatString(180, 500, black, "HARDEST"); break;
	//case 4:	DrawFormatString(180, 500, black, "CREATE"); break;
	}

	DrawFormatString(70, 550, black, "LIFE");
	/*DrawStringToHandle(420, 490, "十字ボタンの左右 移動", black, FontHandle);
	DrawStringToHandle(420, 510, "A・B ジャンプ", black, FontHandle);
	DrawStringToHandle(420, 530, "X・Y 攻撃", black, FontHandle);
	DrawStringToHandle(420, 550, "START ポーズ", black, FontHandle);
	DrawStringToHandle(420, 570, "十字ボタンの上 扉に入る", black, FontHandle);*/

	//操作
	DrawStringToHandle(450, 490, "操作説明", black, Font[4]);
	DrawStringToHandle(450, 512, "移動/扉に入る(上)", black, Font[4]);
	DrawStringToHandle(450, 534, "ジャンプ", black, Font[4]);
	DrawStringToHandle(450, 556, "攻撃", black, Font[4]);
	DrawStringToHandle(450, 578, "ポーズ", black, Font[4]);
	
	//キーボードの操作
	DrawStringToHandle(565, 490, "キーボード", black, Font[4]);
	DrawStringToHandle(565, 512, "十字ボタン", black, Font[4]);
	DrawStringToHandle(575, 534, "Zボタン", black, Font[4]);
	DrawStringToHandle(575, 556, "Xボタン", black, Font[4]);
	DrawStringToHandle(563, 578, "SPACEボタン", black, Font[4]);
	
	//ゲームパッドの操作
	DrawStringToHandle(652, 490, "ゲームパッド　", black, Font[4]);
	DrawStringToHandle(657, 512, "十字ボタン", black, Font[4]);
	DrawFormatStringToHandle(645, 534, black, Font[4], "Xボタン・Yボタン");
	DrawFormatStringToHandle(645, 556, black, Font[4], "Aボタン・Bボタン");
	DrawFormatStringToHandle(657, 578, black, Font[4], "STARTボタン");


	////デバッグ用の変数描画
	//DrawFormatString(450,20,white,"X :%4d",player.x);
	//DrawFormatString(550,20,white,"Y :%4d",player.y);
	//DrawFormatString(450,40,black,"VX2:%4f",player.vx2);
	//DrawFormatString(550,40, black,"VY:%4d",player.vy);
	//DrawFormatString(550,60,black,"右壁:%4d",player.kabe_r);
	//DrawFormatString(550,90,black,"左壁:%4d",player.kabe_l);
	//if(player.dire){
	//	DrawString(450,80,"左向き",white) ;
	//}
	//else{
	//	DrawString(450,80,"右向き",white) ;
	//}
	//if(player.jfly){
	//	DrawString(550,80,"空中",white) ;
	//}
	//else{
	//	DrawString(550,80,"着地",white) ;
	//}
	//if(player.attack){
	//	DrawString(450,100,"攻撃",white) ;
	//}
	//else{DrawString(450,100,"通常",white) ;
	//	
	//}
	//DrawFormatString(550,100,black,"life:%4d",player.life) ;
	//DrawFormatString(450,120,white,"無敵:%4d",player.muteki) ;
	//DrawFormatString(450, 20, black, "テスト:%4d", test);

}

//座標、画像、向きを受け取って描画する dが1なら左、2なら右
void DrawGraph2(int x, int y, int GrHandle, int d) {

	if (d == 1) {
		DrawTurnGraph(x, y, GrHandle, TRUE);
	}
	else {
		DrawGraph(x, y, GrHandle, TRUE);
	}
}
