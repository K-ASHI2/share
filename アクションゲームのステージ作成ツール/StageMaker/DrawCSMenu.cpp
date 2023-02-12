#include"DxLib.h"
#include"extern.h"
#include"function.h"	//共通の関数

//メニューの描画
void DrawCSMenu() {

	DrawFormatStringToHandle(20, 20, black, Font[0], "map[sx][sy]:%d", map[sx][sy]);
	DrawFormatStringToHandle(20, 40, black, Font[0], "si:%d", map_si[map[sx][sy] % 1000]);
	DrawFormatStringToHandle(20, 60, black, Font[0], "scroll_v:%d", scroll_v);

	//メニューの処理
	//選択されたメニューによって表示が変わる
	if (menu_b < 4) {
		int si;
		int end;
		switch (menu_b) {
		case 1:
			si = 0;
			end = si_block;
			break;
		case 2:
			si = si_block;
			end = si_etc;
			break;
		case 3:
			si = si_etc;
			end = si_etc_end;
			break;
		}

		for (int j = 0; j < 2; j++) {
			for (int i = 0; i < 10; i++) {

				//物の番号
				int sn = si + i + 10 * j + (cs_page[menu_b] - 1) * 20;

				//表示するのは選択されたメニューの物だけにする
				//選択されたメニューの物のボタンを全て作り終えたらfor文を全部抜ける
				if (sn >= end) {
					j = 2;
					break;
				}

				int x = 20 + i * 40;
				int y = 530 + j * 34;

				//ボタンの描画と判定処理
				if (DrawButton4(x, y) == 1) {
					cs_map = select_thing[sn].number;
				}

				//置く物の描画
				DrawSelectThing(x, y, select_thing[sn].GrHandle, select_thing[sn].turn);
			}
		}

		{
			//左切り替えボタン
			static int x = 440, y = 570;
			if (JudgeMouse(x, y, 0, 1) == 1) {//ボタンが押されていれば
				DrawButton(x, y, 0, 1, redbutton);
			}
			else {
				if (JudgeMouse4(x, y, 0, 1) && !(Mouse & MOUSE_INPUT_LEFT)) { //1フレーム前にボタンが押されていて今左クリックしていないなら
					cs_map = -1;
					map[sx][sy] = 0;
					sx2 = -1;	//メニュー内の選択されているx、y座標を保存する
					sy2 = -1;
					if (cs_page[menu_b] > 1) {
						cs_page[menu_b]--;
					}
					//最初と最後のページでループさせる
					else {
						cs_page[menu_b] = cs_max_page[menu_b];
					}
				}
				DrawButton(x, y, 0, 1, bluebutton);	//数字1桁の幅がちょうどいい
			}
			DrawStringToHandle(x, y, "<", black, Font[0]);
		}
		{
			//右切り替えボタン
			static int x = 480, y = 570;
			if (JudgeMouse(x, y, 0, 1) == 1) {//ボタンが押されていれば
				DrawButton(x, y, 0, 1, redbutton);
			}
			else {
				//1フレーム前にボタンが押されていて今左クリックしていないなら
				if (JudgeMouse4(x, y, 0, 1) && !(Mouse & MOUSE_INPUT_LEFT)) {
					cs_map = -1;
					map[sx][sy] = 0;
					sx2 = -1;	//メニュー内の選択されているx、y座標を保存する
					sy2 = -1;
					//ページを切り替え
					if (cs_page[menu_b] < cs_max_page[menu_b]) {
						cs_page[menu_b]++;
					}
					//最初と最後のページでループさせる
					else {
						cs_page[menu_b] = 1;
					}
				}
				DrawButton(x, y, 0, 1, bluebutton);	//数字1桁の幅がちょうどいい
			}
			DrawStringToHandle(x, y, ">", black, Font[0]);
		}
		DrawFormatStringToHandle(433, 540, black, Font[0], "PAGE:%d", cs_page[menu_b]);

		if (cs_map > 0 && sx >= 0 && sy >= 0) {
			map[sx][sy] = cs_map;
		}

		//何か物が選択されている時なら説明を描画する
		if (cs_map > 0) {
			DrawStringToHandle(600, 503, select_description[cs_map % 1000], GetColor(0, 0, 0), Font[0]);
		}

		//消すボタン
		static int x = 530, y = 570;
		if (JudgeMouse(x, y, 2, 0) == 1) {//ボタンが押されていれば
			sx2 = mx;//メニュー内の選択されているx、y座標を保存する
			sy2 = my;
		}
		if (JudgeMouse3(x, y, 2, 0)) {
			DrawButton(x, y, 2, 0, redbutton);
			if (sx >= 0 && sy >= 0) {
				map[sx][sy] = 0;	//物を消す
			}
		}
		else {
			DrawButton(x, y, 2, 0, bluebutton);
		}
		DrawStringToHandle(x, y, "消去", black, Font[0]);

		//動かすボタン
		static int x2 = 530, y2 = 538;
		if (JudgeMouse(x2, y2, 2, 0) == 1) {//ボタンをクリックしている時
			sx2 = mx;//メニュー内の選択されているx、y座標を保存する
			sy2 = my;
			cs_map = 0;//cs_mapが設定されているとマップに置いてしまう
		}
		else {
			grid_sizex5 = -1;
			grid_sizey5 = -1;
			grid_sizex6 = 0;
			grid_sizey6 = 0;
		}
		if (JudgeMouse3(x2, y2, 2, 0)) {//ボタンが押されている時
			DrawButton(x2, y2, 2, 0, redbutton);

			//動かしている物を表示する
			//画面内をクリックしている時のみ
			if (sx >= stage_x / block_size && sx < GetDrawWidth() + (stage_x + block_size - 1) / block_size
				&& sy >= stage_y / block_size && sy < GetDrawHeight() + (stage_y + block_size - 1) / block_size) {
				//マップに物が無い時は行わない
				if (map[sx][sy] != 0) {
					if (cs_map2 == 0) {
						cs_map2 = map[sx][sy];
						map[sx][sy] = 0;
						c_move = true;//バックアップしない
					}
				}
				grid_sizex5 = grid_sizex;
				grid_sizey5 = grid_sizey;
				grid_sizex6 = grid_sizex4;
				grid_sizey6 = grid_sizey4;
				DrawMapThings2(mx - block_size / 2, my - block_size / 2, cs_map2);
				DrawMapThings(mx - block_size / 2, my - block_size / 2, cs_map2);//敵の大きさによって変える
				DrawMapThings3(mx - block_size / 2, my - block_size / 2, cs_map2);
			}
			//動かしている途中でマウスが押されなくなったら
			else if (cs_map2 != 0 && MouseL == 0) {
				//画面内にあるなら置く
				if (mx2 >= 0 && mx2 < GetDrawWidth()
					&& my2 >= 0 && my2 < GetDrawHeight())
				{
					map[(mx2 + stage_x) / block_size][(my2 + stage_y) / block_size] = cs_map2;
				}
				cs_map2 = 0;
				c_move = false;		//バックアップするように戻す
			}
		}
		else
			DrawButton(x2, y2, 2, 0, bluebutton);
		DrawStringToHandle(x2, y2, "移動", black, Font[0]);
	}

	//ステータス
	else if (menu_b == 4) {
		DrawStringToHandle(10, 538, "向き", GetColor(0, 0, 0), Font[0]);
		int m = map[sx][sy] % 1000;		//上下に動く敵は上下と表示する
		if (m == 10 || m == 12 || m == 40 || m == 42 || m == 44 || m == 47 || m == 48) {
			DrawButton3(100, 538, "上", 1);
			DrawButton3(200, 538, "下", 2);
		}
		else {
			DrawButton3(100, 538, "左", 1);
			DrawButton3(200, 538, "右", 2);
		}
		if (m == 69)
			DrawStringToHandle(10, 572, "時間", GetColor(0, 0, 0), Font[0]);
		else
			DrawStringToHandle(10, 572, "速度", GetColor(0, 0, 0), Font[0]);

		if (map[sx][sy] % 1000 == 24) {
			DrawButton2(100, 572, "1");
			DrawButton2(140, 572, "2");
			DrawButton2(180, 572, "4");
			DrawButton2(220, 572, "8");
		}
		else {
			DrawButton2(100, 572, "1");
			DrawButton2(140, 572, "2");
			DrawButton2(180, 572, "3");
			DrawButton2(220, 572, "4");
			DrawButton2(260, 572, "5");
			DrawButton2(300, 572, "6");
			DrawButton2(340, 572, "7");
		}

		//スクロール速度のボタン
		{
			//減速ボタン
			static int x = 440, y = 570;
			if (JudgeMouse(x, y, 0, 1) == 1) {//ボタンが押されていれば
				DrawButton(x, y, 0, 1, redbutton);
			}
			else {
				if (JudgeMouse4(x, y, 0, 1) && !(Mouse & MOUSE_INPUT_LEFT)) { //1フレーム前にボタンが押されていて今左クリックしていないなら
					cs_map = -1;
					map[sx][sy] = 0;
					//メニュー内の選択されているx、y座標を保存する
					sx2 = -1;
					sy2 = -1;
					//減速
					if (scroll_v > 0) {
						scroll_v--;
					}
				}
				DrawButton(x, y, 0, 1, bluebutton);	//数字1桁の幅がちょうどいい
			}
			DrawStringToHandle(x, y, "<", black, Font[0]);
		}
		{
			//加速ボタン
			static int x = 480, y = 570;
			if (JudgeMouse(x, y, 0, 1) == 1) {//ボタンが押されていれば
				DrawButton(x, y, 0, 1, redbutton);
			}
			else {
				//1フレーム前にボタンが押されていて今左クリックしていないなら
				if (JudgeMouse4(x, y, 0, 1) && !(Mouse & MOUSE_INPUT_LEFT)) {
					cs_map = -1;
					map[sx][sy] = 0;
					//メニュー内の選択されているx、y座標を保存する
					sx2 = -1;
					sy2 = -1;
					//加速
					if (scroll_v < 9) {
						scroll_v++;
					}
				}
				DrawButton(x, y, 0, 1, bluebutton);	//数字1桁の幅がちょうどいい
			}
			DrawStringToHandle(x, y, ">", black, Font[0]);
		}
		DrawFormatStringToHandle(433, 540, black, Font[0], "速度:%d", scroll_v);

		//背景のボタン
		{
			static int x = 540, y = 570;
			if (JudgeMouse(x, y, 0, 1) == 1) {
				DrawButton(x, y, 0, 1, redbutton);
			}
			else {
				if (JudgeMouse4(x, y, 0, 1) && !(Mouse & MOUSE_INPUT_LEFT)) {
					cs_map = -1;
					map[sx][sy] = 0;
					sx2 = -1;
					sy2 = -1;
					if (background_n > 0) {
						background_n--;
					}
				}
				DrawButton(x, y, 0, 1, bluebutton);
			}
			DrawStringToHandle(x, y, "<", black, Font[0]);
		}
		{
			static int x = 580, y = 570;
			if (JudgeMouse(x, y, 0, 1) == 1) {
				DrawButton(x, y, 0, 1, redbutton);
			}
			else {
				if (JudgeMouse4(x, y, 0, 1) && !(Mouse & MOUSE_INPUT_LEFT)) {
					cs_map = -1;
					map[sx][sy] = 0;
					sx2 = -1;
					sy2 = -1;
					if (background_n < 20) {
						background_n++;
					}
				}
				DrawButton(x, y, 0, 1, bluebutton);
			}
			DrawStringToHandle(x, y, ">", black, Font[0]);
		}
		DrawFormatStringToHandle(533, 540, black, Font[0], "背景:%d", background_n);

		//音楽のボタン
		{
			static int x = 640, y = 570;
			if (JudgeMouse(x, y, 0, 1) == 1) {
				DrawButton(x, y, 0, 1, redbutton);
			}
			else {
				if (JudgeMouse4(x, y, 0, 1) && !(Mouse & MOUSE_INPUT_LEFT)) {
					cs_map = -1;
					map[sx][sy] = 0;
					sx2 = -1;
					sy2 = -1;
					if (music_n > 0) {
						music_n--;
						PM_Number();
					}
				}
				DrawButton(x, y, 0, 1, bluebutton);
			}
			DrawStringToHandle(x, y, "<", black, Font[0]);
		}
		{
			static int x = 680, y = 570;
			if (JudgeMouse(x, y, 0, 1) == 1) {
				DrawButton(x, y, 0, 1, redbutton);
			}
			else {
				if (JudgeMouse4(x, y, 0, 1) && !(Mouse & MOUSE_INPUT_LEFT)) {
					cs_map = -1;
					map[sx][sy] = 0;
					sx2 = -1;
					sy2 = -1;
					if (music_n < 20) {
						music_n++;
						PM_Number();
					}
				}
				DrawButton(x, y, 0, 1, bluebutton);
			}
			DrawStringToHandle(x, y, ">", black, Font[0]);
		}

		DrawFormatStringToHandle(633, 540, black, Font[0], "音楽:%d", music_n);
	}
}

//座標、画像(+透過フラグ)を受け取って置く物の画像を描画する
void DrawSelectThing(int x1, int y1, int GrHandle, bool turn, int TransFlag) {

	static int size = 28;

	if (turn) {
		DrawTurnSelectThing(x1, y1, GrHandle, TransFlag);
	}
	else {
		int size2 = 2 + (32 - size) / 2;
		DrawExtendGraph(x1 + size2, y1 + size2, x1 + size, y1 + size, GrHandle, TRUE);
	}
}

void DrawSelectThing(int x1, int y1, int GrHandle) {
	DrawSelectThing(x1, y1, GrHandle, TRUE);
}

//座標、画像(+透過フラグ)を受け取って置く物の画像を反転して描画する
void DrawTurnSelectThing(int x1, int y1, int GrHandle, int TransFlag) {
	static int size = 28;
	int size2 = 2 + (32 - size) / 2;
	DrawExtendGraph(x1 + size, y1 + size2, x1 + size2, y1 + size, GrHandle, TRUE);
}