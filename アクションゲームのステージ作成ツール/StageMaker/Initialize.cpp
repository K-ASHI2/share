#include"DxLib.h"
#include"extern.h"
#include"function.h"	//ステージ作成のみに使用する関数

void init_c() {	//ステージ作成の初期化

	//背景の位置の初期化
	stage_x = 0;
	stage_y = 0;

	sx = -1;	//最初はグリッドは選択されていない
	sy = -1;
	sx2 = 460;	//最初は動かすモード
	sy2 = 538;
	menu_b = 1;
	for (int i = 1; i <= 3; i++) {
		cs_page[i] = 1;
	}
	cs_map = -1;
	cs_map2 = 0;	//何もないので0
	mx2 = -1;
	my2 = -1;
	back_c = 0;	//最初は先頭から始める
	back_head = 0;	//バックアップデータの先頭
	back_top = 0;	//バックアップデータの最後尾

	//最大サイズに変えないとサイズ変更に対応できていない?
	for (int j = 0; j< height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			for (int h = 1; h < BACK_MAX; h++) {
				backup[h][i][j] = -1;		//全ての座標は最初は存在しない
			}
			backup[0][i][j] = map[i][j];	//一番最初は元々のマップ
		}
	}
	for (int i = 1; i < BACK_MAX; i++) {
		backup_w[i] = 0;
		backup_h[i] = 0;
	}
	backup_w[0] = width_size;
	backup_h[0] = height_size;

	//画面のサイズを拡大したとき増えた座標も初期化する必要がある
	//増やした時に初期化するように変える
	for (int j = 0; j < height_size; j++) {
		for (int i = width_size; i < MAX_WIDTH; i++) {
			map[i][j] = 0;
		}
	}
	scrollbar.x = 2 + 16;
	scrollbar.y = WINDOW_HEIGHT + 2;
	scrollbar.width = 128;
	scrollbar.height = 16;
	scrollbar.click = 0;

	scrollbar2.x = WINDOW_WIDTH + 2;
	scrollbar2.y = 2 + 16;
	scrollbar2.width = 16;
	scrollbar2.height = 128;
	scrollbar2.click = 0;

	//マウスの入力の初期化
	P_MouseL = 0;

	//音楽を背景に合わせて流す
	PM_Number();
}
