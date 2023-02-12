#include"DxLib.h"
#include"function.h"
#include"extern.h"

void init_map(int i, int j) {//マップの数字の初期化の個別処理

	switch (map[i][j] % 1000) {
	case 0: break;	//何もない

	case 1:	//横に動いて落ちる敵
		init_e(i, j, 1, 6);
		enemy[i][j].vx = -2;
		enemy[i][j].appear = 0;
		break;

	case 2:	//穴の手前で方向転換する敵
		init_e(i, j, 1, 16, 0);
		enemy[i][j].vx = 2;
		enemy[i][j].jfly = 1;
		break;

	case 3:	//飛び跳ねる敵
		init_e(i, j, 1, 13, 0);
		enemy[i][j].vx = -2;
		break;

	case 4:	//横に往復する敵
		init_e(i, j, 1, 0);
		init_j(i, j);
		enemy[i][j].x = i * BLOCK;
		enemy[i][j].vx = -2;
		break;

	case 5: //縦に往復する敵
		init_e(i, j, 1, 5);
		init_j(i, j);
		enemy[i][j].vy = 2;
		break;

	case 6:	//円運動する敵
		init_e(i, j, 1, 15, 1);
		init_j(i, j);
		enemy[i][j].rad = 270;
		//enemy[i][j].rad = GetRand(360);
		break;

	case 7:	//上下に動き続けて画面外に出たら反対側から出てくる敵
		init_e(i, j, 1, 37);
		init_j(i, j);
		enemy[i][j].vy = 2;
		break;

	case 8:	//上下に揺れる敵
		init_e(i, j, 1, 41);
		init_j(i, j);
		{
			int a = GetRand(360);
			for (int k = 0; k < height_size; k++) {
				enemy[i][k].rad = a;
			}
		}
		enemy[i][j].size_x = 16;
		enemy[i][j].size_y = 16;
		enemy[i][j].vx = -2;
		break;

	case 9:	//壁で反射する敵
		init_e(i, j, 1, 14, 0);
		enemy[i][j].vx = 2;
		enemy[i][j].vy = 2;
		break;

	case 10: //主人公がジャンプすると飛ぶ敵
		init_e(i, j, 1, 56);
		enemy[i][j].vx = 2;
		enemy[i][j].appear = 0;
		break;

	case 11:	//主人公を追いかける敵
		init_e(i, j, 1, 43, 0);
		init_j(i, j);
		enemy[i][j].size_x = 16;
		enemy[i][j].size_y = 16;
		enemy[i][j].m_rad = 4;
		break;

	//case 12:	//ランダムに動きつつ主人公を追いかける敵
	//	init_e(i, j, 1, 44, 0);
	//	init_j(i, j);
	//	enemy[i][j].size_x = 16;
	//	enemy[i][j].size_y = 16;
	//	enemy[i][j].m_rad = 4;
	//	break;
		
	case 13:  //正面に弾を撃つ敵
		init_e(i, j, 1, 31);
		enemy[i][j].vx = -2;
		enemy[i][j].appear = 0;
		enemy[i][j].t = GetRand(20);
		break;

	case 14:	//縦に往復して自機狙いの弾を撃つ敵
		init_e(i, j, 1, 30);
		init_j(i, j);
		enemy[i][j].vy = 2;
		enemy[i][j].t = GetRand(20) + 40;
		break;

	case 15:	//縦に往復して正面に弾を撃つ敵
		init_e(i, j, 1, 32);
		init_j(i, j);
		enemy[i][j].vy = 2;
		enemy[i][j].t = GetRand(20) + 40;
		break;

	case 16:	//円運動して正面に弾を撃つ敵
		init_e(i, j, 1, 33, 1);
		init_j(i, j);
		enemy[i][j].t = GetRand(20);
		enemy[i][j].rad = 270;
		//enemy[i][j].rad = GetRand(360);
		break;

	case 17:	//主人公とX座標を合わせて自機外しの氷弾を撃つ敵
		init_e(i, j, 1, 57, 0);
		enemy[i][j].t = GetRand(20);
		enemy[i][j].rad = 40;
		break;

	case 18:	//主人公とX座標を合わせて雷を放つ敵
		init_e(i, j, 1, 58, 0);
		enemy[i][j].t = GetRand(5);
		enemy[i][j].rad = 40;
		break;

	case 100:	//止まっているトゲ 
		init_e(i, j, 1, 55);//他の敵と重ならない数値にしているだけ
		init_j(i, j);
		enemy[i][j].muteki = 1;
		break;
		
	case 101: init_e(i, j, 1, 2);
		init_j(i, j);
		enemy[i][j].muteki = 1;
		enemy[i][j].vx = 3;
		break;  //横に動くトゲ


	case 102: init_e(i, j, 1, 34);
		init_j(i, j);
		enemy[i][j].vy = 2;
		enemy[i][j].muteki = 1;
		break; //縦に動くトゲ

	case 103: init_e(i, j, 1, 35, 1);
		init_j(i, j);
		enemy[i][j].rad = 270;
		enemy[i][j].muteki = 1;
		break;  //円運動するトゲ

	//case 22: init_e(i, j, 1, 12);
	//	enemy[i][j].vx = -2;
	//	enemy[i][j].size_y = 64;
	//	enemy[i][j].appear = 0;
	//	break;  //縦長の敵
	//case 27: init_e(i, j, 1, 17, 0);
	//	enemy[i][j].vx = -2;
	//	enemy[i][j].size_x = 64;
	//	break;  //横長の敵
	//case 28: init_e(i, j, 1, 18, 0);
	//	enemy[i][j].vx = -2;
	//	enemy[i][j].size_x = 64;
	//	enemy[i][j].size_y = 64;
	//	//enemy[i][j].drop = 100;
	//	break;  //大きい敵
	//case 30: init_e(i, j, 1, 20);
	//	enemy[i][j].x = (i - 3) * BLOCK;
	//	enemy[i][j].y = (j - 3) * BLOCK;
	//	enemy[i][j].vx = -2;
	//	enemy[i][j].size_x = 224;
	//	enemy[i][j].size_y = 224;
	//	enemy[i][j].muteki = 1;
	//	break;  //224*224の敵

	case 301: kabe[i][j] = 1; break;	//壁
	case 302: kabe[i][j] = 1; break;	//壁
	case 303: kabe[i][j] = 1; break;	//壁
	case 304: kabe[i][j] = 1; break;	//壁
	case 305: kabe[i][j] = 1; break;	//壁
	case 306: kabe[i][j] = 1; break;	//壁
	case 307: kabe[i][j] = 1; break;	//床
	case 308: kabe[i][j] = 1; break;	//鉄のブロック
	case 309: kabe[i][j] = 1; break;	//木のブロック
	case 500: kabe[i][j] = 2; break; //すり抜け床
	case 501: kabe[i][j] = 1; break;  //トゲ
	case 502: init_e(i, j, 1, 3);
		init_j(i, j);
		kabe[i][j] = 1;
		enemy[i][j].hantei = 0;
		break;  //壊れる壁

	case 503: init_e(i, j, 1, 53);
		init_j(i, j);
		kabe[i][j] = 1;
		enemy[i][j].hantei = 0;
		enemy[i][j].muteki = 1;
		enemy[i][j].countx = -1;//乗るまでのカウントは固定
		if (map[i][j] >= 1000)
			enemy[i][j].county = (map[i][j] % 10000) / 1000 * 40 + 5;
		else
			enemy[i][j].county = 125;
		break;  //一定時間後に消えるブロック

	case 504: init_e(i, j, 1, 1);
		init_j(i, j);
		enemy[i][j].vx = 4;
		enemy[i][j].hantei = 0;
		enemy[i][j].muteki = 1;
		break;  //横に動く床

	case 505: init_e(i, j, 1, 7);
		init_j(i, j);
		enemy[i][j].hantei = 0;
		enemy[i][j].muteki = 1;
		enemy[i][j].vy = 2;
		break;  //縦に動く床

	case 506: init_e(i, j, 1, 38);
		init_j(i, j);
		enemy[i][j].hantei = 0;
		enemy[i][j].muteki = 1;
		enemy[i][j].vy = 2;
		break; //上下に動き続けて画面外に出たら反対側から出てくるブロック
	case 507: kabe[i][j] = 1; break;	//氷のブロック

	case 601: init_t(i, j, 1, 21); break;   //自機狙いの弾を撃つ大砲
	case 602: init_t(i, j, 1, 22); break;   //左にまっすぐ飛ぶ弾を撃つ大砲
	case 603: init_t(i, j, 1, 23); break;   //右にまっすぐ飛ぶ弾を撃つ大砲
	case 604: init_t(i, j, 1, 24); break;   //上にまっすぐ飛ぶ弾を撃つ大砲
	case 605: init_t(i, j, 1, 25); break;  //下にまっすぐ飛ぶ弾を撃つ大砲
	case 606: init_t(i, j, 1, 26); break;  //左上にまっすぐ飛ぶ弾を撃つ大砲
	case 607: init_t(i, j, 1, 27); break;  //右上にまっすぐ飛ぶ弾を撃つ大砲
	case 608: init_t(i, j, 1, 28); break;  //左下にまっすぐ飛ぶ弾を撃つ大砲
	case 609: init_t(i, j, 1, 29); break;  //右下にまっすぐ飛ぶ弾を撃つ大砲

	case 701: 
		init_e(i, j, 1, 45);
		enemy[i][j].muteki = 1;
		init_j(i, j);
		break;  //赤スイッチ

	case 702: init_e(i, j, 1, 46);
		enemy[i][j].muteki = 1;
		init_j(i, j);
		break;  //緑スイッチ
	case 703: break;	//赤スイッチで出る床
	case 704: break;	//緑スイッチで出る床

	case 705: init_e(i, j, 1, 39);
		kabe[i][j] = 1;
		enemy[i][j].hantei = 0;
		enemy[i][j].muteki = 1;
		enemy[i][j].rad = 0;
		for (int k = 0; k < 4; k++) {
			enemybullet[i][j][k].life = 1;
			enemybullet[i][j][k].atk = 1;
			enemybullet[i][j][k].size_x = 32;
			enemybullet[i][j][k].size_y = 32;
			enemybullet[i][j][k].species = 4;
		}
		enemybullet[i][j][0].x = i * BLOCK;
		enemybullet[i][j][0].y = j * BLOCK;
		break;  //時計回りに回るファイアバー

	case 706:  //メテオ
		enemy[i][j].species = 19;
		enemy[i][j].muteki = 1;
		enemy[i][j].t = GetRand(480);
		break;

	case 707: //星
		enemy[i][j].species = 59;
		enemy[i][j].muteki = 1;
		enemy[i][j].size_x = 7;
		enemy[i][j].size_y = 7;
		init_j(i, j);
		enemy[i][j].t = GetRand(20);
		break;
	
	case 708: //青星
		enemy[i][j].species = 60;
		enemy[i][j].muteki = 1;
		enemy[i][j].size_x = 7;
		enemy[i][j].size_y = 7;
		init_j(i, j);
		enemy[i][j].t = GetRand(20);
		break;

	case 709: //赤星
		enemy[i][j].species = 61;
		enemy[i][j].muteki = 1;
		enemy[i][j].size_x = 7;
		enemy[i][j].size_y = 7;
		init_j(i, j);
		enemy[i][j].t = GetRand(20);
		break;

	case 801: //ゴールの扉
		init_e(i, j, 1, 11);
		init_j(i, j);
		enemy[i][j].hantei = 0;
		enemy[i][j].muteki = 1;
		break;

		//ステージ作成機で未設定
	case 802: init_e(i, j, 1, 8);
		init_j(i, j);
		enemy[i][j].hantei = 0;
		enemy[i][j].muteki = 1;
		break;  //扉

	case 803: init_e(i, j, 1, 9);
		init_j(i, j);
		enemy[i][j].hantei = 0;
		enemy[i][j].muteki = 1;
		break;  //扉

	case 804: init_e(i, j, 1, 10);
		init_j(i, j);
		enemy[i][j].hantei = 0;
		enemy[i][j].muteki = 1;
		break;  //次のエリアに行く扉

	case 901:  init_e(i, j, 1, 4);
		enemy[i][j].jx = 0;
		break;  //アイテム

	case 902: init_e(i, j, 1, 54); break; //全快するハート

	//case 50: init_e(i, j, 1, 40);
	//	kabe[i][j] = 1;
	//	enemy[i][j].hantei = 0;
	//	enemy[i][j].rad = 0;
	//	for (int k = 0; k < 4; k++) {
	//		enemybullet[i][j][k].life = 1;
	//		enemybullet[i][j][k].atk = 1;
	//		enemybullet[i][j][k].size_x = 32;
	//		enemybullet[i][j][k].size_y = 32;
	//		enemybullet[i][j][k].species = 4;
	//	}
	//	enemybullet[i][j][0].x = i * BLOCK;
	//	enemybullet[i][j][0].y = j * BLOCK;
	//	break;  //反時計回りに回るファイアバー
	//case 52: init_e(i, j, 1, 42);
	//	init_j(i, j);
	//	enemy[i][j].vx = 4;
	//	enemy[i][j].hantei = 0;
	//	enemy[i][j].muteki = 1;
	//	break;  //横に遠くまで動く床
	//			//いらない
	//case 64: init_e(i, j, 1, 48);
	//	enemy[i][j].muteki = 1;
	//	enemy[i][j].size_x = 64;
	//	enemy[i][j].jx = 0;
	//	enemy[i][j].jy = 0;
	//	break;  //火の海

	case 251:	//ボス1
		if (mapload < 1000) {
			init_e(i, j, 3, 49, 0);
			enemy[i][j].vx = 1;
		}
		else if (mapload < 2000) {
			init_e(i, j, 4, 49, 0);
			enemy[i][j].vx = 2;
		}
		else if (mapload < 3000) {
			init_e(i, j, 5, 49, 0);
			enemy[i][j].vx = 2;
		}
		enemy[i][j].size_x = 96;
		enemy[i][j].size_y = 96;
		enemy[i][j].t = 0;
		break;

	case 252:	//ボス2
		if (mapload < 1000) {
			init_e(i, j, 3, 51, 0);
			enemy[i][j].vx = 1.5;
		}
		else if (mapload < 2000) {
			init_e(i, j, 4, 51, 0);
			enemy[i][j].vx = 2.0;
		}
		else if (mapload < 3000) {
			init_e(i, j, 6, 51, 0);
			enemy[i][j].vx = 2.5;
		}
		enemy[i][j].size_x = 96;
		enemy[i][j].size_y = 96;
		enemy[i][j].t = GetRand(120);
		break;

				//case 66: init_e(i, j, 1, 50);
				//	enemy[i][j].hantei = 0;
				//	enemy[i][j].muteki = 1;
				//	break;  //ボスを倒した時に出る次のステージに行く扉
				
	case 999: //プレイヤーの初期座標
		player.x = i * BLOCK;
		player.y = j * BLOCK;
		//向きを変える
		if (map[i][j] % 100000 / 10000 == 1) {
			player.dire = map[i][j] % 100000 / 10000;
		}
		break;
	}
}
