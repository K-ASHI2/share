#include"DxLib.h"
#include"extern.h"
#include"function.h"	//ステージ作成のみに使用する関数

void DrawMap() {

	//マップの描画

	/**
	 * 縦も画面内のみ判定にするべき
	 */
	int xmin, xmax;//大きい敵も描画できるように描画の端が変わるようにする
	if ((stage_x / block_size) - 6 > 0)
		xmin = (stage_x / block_size) - 6;
	else
		xmin = 0;
	if ((stage_x / block_size) + WIDTH_SIZE + 4 < 0)
		xmax = (stage_x / block_size) - 4;
	else
		xmax = width_size;

	for (int j = 0; j < height_size; j++)
		for (int i = xmin; i < xmax; i++)
			if (i < width_size && i >= 0)
				if (i != sx || j != sy)
					DrawGraph(i * block_size - stage_x, j * block_size - stage_y, img.grid, TRUE);	//グリッドの表示
																				//大きい敵やブロックにグリッドが重ならないようにするため
	//一度に画面内に表示される幅は一列多くする
	for (int i = stage_x / block_size; i < (stage_x / block_size) + WIDTH_SIZE + 1; i++) {
		for (int j = 0; j < height_size; j++) {
			//横の部分より狭い範囲でマップ判断
			if (i < width_size && i >= 0) {
				//上下に画面外まで動く敵
				if (map[i][j] % 1000 == 7 || map[i][j] % 1000 == 506) {
					//動く場所を表示する
					//1列に2体以上存在しても1度だけ判定すればよい
					DrawGraph(i * block_size - stage_x, 0, img.b_line, TRUE);
					break;
				}
			}
		}
	}

	//2→1→3→4の順に奥から描画していく
	//奥に表示したいものを表示する
	for (int j = 0; j < height_size; j++) {
		for (int i = xmin; i < xmax; i++) {
			int cmap_x = i * block_size - stage_x;
			int cmap_y = j * block_size - stage_y;
			DrawMapThings2(cmap_x, cmap_y, map[i][j]);
		}
	}
	for (int j = 0; j < height_size; j++) {
		for (int i = xmin; i < xmax; i++) {
			int cmap_x = i * block_size - stage_x;
			int cmap_y = j * block_size - stage_y;
			DrawMapThings(cmap_x, cmap_y, map[i][j]);
		}
	}

	//手前に表示したいものを表示する
	for (int j = 0; j < height_size; j++) {
		for (int i = xmin; i < xmax; i++) {
			int cmap_x = i * block_size - stage_x;
			int cmap_y = j * block_size - stage_y;
			DrawMapThings3(cmap_x, cmap_y, map[i][j]);
		}
	}
	for (int j = 0; j < height_size; j++) {
		for (int i = xmin; i < xmax; i++) {
			int cmap_x = i * block_size - stage_x;
			int cmap_y = j * block_size - stage_y;
			DrawMapThings4(cmap_x, cmap_y, map[i][j]);
		}
	}

	//大きい物の選択中の物の判定
	//実装が難しい
	//for (int j = 0; j < height_size; j++) {
	//	for (int i = xmin; i < xmax; i++) {
	//		//マスが一致しているなら判定しない
	//		if (i == sx && j == sy) {
	//			continue;
	//		}
	//		int si = map_si[map[i][j] % 1000];

	//		//大きい敵は動かす時とステータス変更の時に手前に物が無ければ全体に判定を持たせる
	//		//移動のボタンが押されている時、何もない場所を選択した場合、選択中のマスからずらした範囲を探索し、その範囲に大きい物があるなら判定を変える
	//		if ((sx >= i - select_thing[si].l_shift && sx <= i + select_thing[si].r_shift) && (sy >= j - select_thing[si].u_shift && sy <= j + select_thing[si].d_shift)
	//			&& ((JudgeMouse3(430, 538, 2, 0) && c_move == false) || menu_b == 4) && map[sx][sy] == 0) {
	//			sx = i;
	//			sy = j;
	//		}
	//	}
	//}

	//選択中の物のグリッドの表示
	if (sx >= 0 && sy >= 0) {
		int cs_map3 = map[sx][sy] % 1000;
		if (grid_sizex5 != -1) {
			grid_sizex = grid_sizex5;
			grid_sizey = grid_sizey5;
			grid_sizex4 = grid_sizex6;
			grid_sizey4 = grid_sizey6;
		}
		else {
			grid_sizex = block_size;
			grid_sizey = block_size;
			grid_sizex4 = 0;
			grid_sizey4 = 0;
			if (cs_map3 == 27 || cs_map3 == 28)
				grid_sizex = block_size * 2;
			if (cs_map3 == 99 || cs_map3 >= 13 && cs_map3 <= 16 || cs_map3 == 22 || cs_map3 == 28 || cs_map3 == 29 || cs_map3 == 66)
				grid_sizey = block_size * 2;
			if (cs_map3 == 65 || cs_map3 == 67) {
				grid_sizex = block_size * 3;
				grid_sizey = block_size * 3;
			}
			if (cs_map3 == 30) {
				grid_sizex = block_size * 4;
				grid_sizey = block_size * 4;
				grid_sizex4 = block_size * 3;
				grid_sizey4 = block_size * 3;
			}
		}
		for (int j = stage_y / block_size; j < (stage_y / block_size) + HEIGHT_SIZE + 1; j++) {
			for (int i = (stage_x / block_size); i < (stage_x / block_size) + WIDTH_SIZE + 1; i++) {
				if (i < width_size && i >= 0)
					if (i == sx && j == sy) {
						int cmap_x = i * block_size - stage_x;
						int cmap_y = j * block_size - stage_y;
						DrawBox(cmap_x - 1 - grid_sizex4, cmap_y - grid_sizey4 - 1, cmap_x + grid_sizex + 1, cmap_y + grid_sizey + 1, GetColor(0, 0, 0), FALSE); //選択されたグリッドの表示
						for (i = 0; i < 3; i++)
							DrawBox(cmap_x - grid_sizex4 - 2 - i, cmap_y - grid_sizey4 - 2 - i, cmap_x + grid_sizex + 2 + i, cmap_y + grid_sizey + 2 + i, GetColor(255, 0, 0), FALSE);
						DrawBox(cmap_x - grid_sizex4 - 5, cmap_y - grid_sizey4 - 5, cmap_x + grid_sizex + 5, cmap_y + grid_sizey + 5, GetColor(0, 0, 0), FALSE);
						break;
					}
			}
		}
	}
}

//マップの値を受け取って描画する関数
void DrawMapThings(int x, int y, int mapc) {
	
	//向き
	int d = 0;
	if (mapc >= 10000)
		d = mapc % 100000 / 10000;

	int si = map_si[mapc % 1000];

	//何もない場所以外は設定されていない場所をnullにする
	if (si == -1) {
		DrawGraph(x, y, img.null, TRUE);
	}
	else if (mapc != 0 && select_thing[si].drawflag) {
		//turnで反転が決まっているなら優先する
		if (select_thing[si].turn) {
			DrawCreate(x, y, select_thing[si].GrHandle, 1);
		}
		else {
			DrawCreate(x, y, select_thing[si].GrHandle, d);
		}
	}

	//個別に設定した処理
	switch (mapc % 1000) {
		//まだ置く物に設定してない扉
	/*case 13:	DrawGraph(x, y, img.door[1], TRUE); break;
	case 14:	DrawGraph(x, y, img.door[1], TRUE); break;
	case 15:	DrawGraph(x, y, img.door[2], TRUE); break;*/
		//円運動する物の中心座標
	case 6:	DrawGraph(x, y, img.graysquare, TRUE); break;
	case 16:	DrawGraph(x, y, img.graysquare, TRUE); break;
	case 103:	DrawGraph(x, y, img.graysquare, TRUE); break;
		//ファイアバーの中心
	case 705:	DrawCreate(x, y, img.kabe, d); break;

		//移動距離が長すぎるから別に設定していたブロック?
		//見た目を変えて新たに設定するべきなのでいらないはず
	//case 52:	DrawGraph(x, y, img.moveblock[4], TRUE); break;	//横に遠くまで動く床

	//消える床のカウントの数字の描画
	case 69:
		char dc[2];
		if (mapc >= 100)
			itoa((mapc % 10000) / 1000, dc, 10);
		DrawStringToHandle(x + 8, y + 3, dc, GetColor(255, 0, 0), Font[1]);
		break;

		//プレイヤーの初期座標の描画
	case 999:
		if (d == 1)
			DrawTurnGraph(x - 32, y, img.hito[6], TRUE);
		else
			DrawGraph(x, y, img.hito[6], TRUE);
		break;
	}
}

//マップの奥に描画したいものを描画する
void DrawMapThings2(int x, int y, int map) {
	int d = 0;
	if (map >= 10000)
		d = map % 100000 / 10000;
	int m = map % 1000;
	//円運動する物の動く範囲の描画
	if (m == 6 || m == 16 || m == 103) {
		DrawCreate(x - block_size * 2, y - block_size * 2, img.circle3, d);
		DrawCreate(x - block_size * 2, y - block_size * 2, img.circle, d);
	}
	//ファイアバーの動く範囲の描画
	else if (m == 49) {
		DrawCreate(x - block_size * 3, y - block_size * 3, img.circle2, d);	
	}
	//大きい敵の描画
	/*else if (m == 30)
		DrawCreate(x - block_size * 3, y - block_size * 3, img.enemy[27], d);*/
	//横に往復する物
	else if (m == 4 || m == 101 || m == 504) {
		int v = 0;
		if (map >= 1000)
			v = (map % 10000) / 1000;
		int x1 = x;
		if (d == 1)		//左に動く場合矢印全体を左に移動距離分ずらす
			x1 -= v * block_size;
		DrawTurnGraph(x1, y, img.linemove1, TRUE);
		int i = 0;
		for (i = 1; i < v; i++)
			DrawGraph(x1 + i * block_size, y, img.linemove2, TRUE);
		DrawGraph(x1 + i * block_size, y, img.linemove1, TRUE);
	}
	//縦に往復する物
	else if (m == 5 || m == 14 || m == 15 || m == 102 || m == 505) {
		int v = 0;
		if (map >= 1000)
			v = (map % 10000) / 1000;
		int y1 = y;
		if (d == 1)		//上に動く場合矢印全体を上に移動距離分ずらす
			y1 -= v * block_size;
		DrawGraph(x, y1, img.linemove_up, TRUE);
		int i = 0;
		for (i = 1; i < v; i++)
			DrawGraph(x, y1 + i * block_size, img.linemove3, TRUE);
		DrawGraph(x,
			y1 + i * block_size, img.linemove_down, TRUE);
	}
	//画面外まで上下に動く物の矢印
	if (m == 7 || m == 506) {
		if (d == 1)
			DrawGraph(x, y - block_size, img.linemove_up, TRUE);
		else
			DrawGraph(x, y + block_size, img.linemove_down, TRUE);
	}
}

//マップの手前に描画したいものを描画する
void DrawMapThings3(int x, int y, int map) {

	int d = 0;

	if (map >= 10000) {
		d = map % 100000 / 10000;
	}

	int m = map % 1000;
	int si = map_si[map % 1000];

	//円運動する敵の敵本体の描画
	if (m == 6 || m == 16 || m == 103) {
		DrawCreate(x, y - block_size * 2, select_thing[si].GrHandle, d);
	}

	//ファイアバーの弾の描画
	else if (m == 705) {
		for (int i = 0; i < 4; i++) {
			DrawGraph(x, y - i * block_size, img.bullet[4], TRUE);
		}
	}
}

//マップの一番手前に描画したいものを描画する
void DrawMapThings4(int x, int y, int map) {
	int d = 0;
	if (map >= 10000)
		d = map % 100000 / 10000;
}

//座標、画像、向きを受け取って描画する dが1なら左、2なら右
void DrawCreate(int x, int y, int GrHandle, int d) {
	if (d == 1) {
		DrawTurnGraph(x, y, GrHandle, TRUE);
	}
	else {
		DrawGraph(x, y, GrHandle, TRUE);
	}
}

//このまま使うと縦横がブロックと同じサイズの物にしか使えない
//座標、画像(+透過フラグ)を受け取って描画する
void MapDrawExtendGraph(int x1, int y1, int GrHandle, int TransFlag) {
	DrawExtendGraph(x1, y1, x1 + block_size, y1 + block_size, GrHandle, TRUE);
}

void MapDrawExtendGraph(int x1, int y1, int GrHandle) {
	MapDrawExtendGraph(x1, y1, GrHandle, TRUE);
}