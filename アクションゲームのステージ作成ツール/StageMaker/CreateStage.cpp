#include"DxLib.h"
#include"extern.h"
#include"function.h"	//共通の関数

//1フレームの処理終了時のチェック
void EndCheck();

void CreateStage() {

	//1フレーム前のマウスの入力を保存する
	mx2 = mx;
	my2 = my;
	//1フレーム前の左クリックの入力の有無を保存する
	P_MouseL = MouseL;

	Mouse = GetMouseInput();	//マウスの入力状態取得
	GetMousePoint(&mx, &my);	//マウスの座標取得

	//左クリックの入力の有無
	if (Mouse & MOUSE_INPUT_LEFT)
		MouseL = 1;
	else
		MouseL = 0;

	//スクロールバーの移動
	MoveScrollBar();
	//メニューの変更
	CSChangeMenu();

	//メニューがステータスの時だけ常にグリッドを表示する
	//それ以外の時は表示しないので-1にする
	if (menu_b != 4) {
		sx = -1;
		sy = -1;
	}

	if (MouseL == 1) { //マウスの左ボタンが押されていたら
		if (mx > 0 && mx < GetDrawWidth()
			&& my > 0 && my < GetDrawHeight()) {	//マウスカーソルが画面内にあるなら
			sx = (mx + stage_x) / block_size;	//グリッドの座標を変更する
			sy = (my + stage_y) / block_size;
		}
	}

	//1フレームの処理終了時のチェック
	EndCheck();
}

//1フレームの処理終了時のチェック
void EndCheck() {

	//物を動かしている最中でないなら
	if (c_move == false) {
		//禁止される置き方をしていたらもとに戻し、そうでないならバックアップを取る
		if (ProhibitCheck() == 1) {
			for (int j = 0; j < height_size; j++) {
				for (int i = 0; i < width_size; i++) {
					map[i][j] = backup[back_c][i][j];	//マップの全ての座標を元に戻す
				}
			}
			if (stage_x > width_size * block_size - WINDOW_WIDTH)	//画面サイズが変更されていたら
				stage_x = width_size * block_size - WINDOW_WIDTH;	//カーソルを右端にする
		}
		else {
			BackUp();		//バックアップを保存する
		}
	}
}
