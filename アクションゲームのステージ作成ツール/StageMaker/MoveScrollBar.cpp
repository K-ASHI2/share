#include"DxLib.h"
#include"extern.h"
#include"function.h"	//共通の関数

//ステージ作成時のスクロールバーの移動
void MoveScrollBar() {

	int Wheel = GetMouseWheelRotVol();	//ホイールの回転量取得

	static int BAR_FRAME = 2;	//スクロールバーの枠の大きさ
	static int SCROLL_BUTTON = 16;	//スクロールバーの端のボタンの大きさ
	static int FRAME_AND_BUTTON = BAR_FRAME + SCROLL_BUTTON;	//フレームとボタンの大きさの和

	//スクロールする幅
	//画面の幅の分はスクロールしないので引く
	int cx2 = width_size * 32 - WINDOW_WIDTH;
	int cy2 = height_size * 32 - WINDOW_HEIGHT;

	//1フレーム前に押されているならカーソルの移動した分だけ移動させる
	if (scrollbar.click == 1) {
		if (mx != mx2) {
			scrollbar.x += mx - mx2;
			stage_x = (scrollbar.x - FRAME_AND_BUTTON)* cx2 / (WINDOW_WIDTH - (FRAME_AND_BUTTON * 2 +  scrollbar.width));
		}
	}
	else if(scrollbar2.click == 1){
		if (my != my2) {
			scrollbar2.y += my - my2;
			stage_y = (scrollbar2.y - FRAME_AND_BUTTON) * cy2 / (WINDOW_HEIGHT - (FRAME_AND_BUTTON * 2 + scrollbar2.height));
		}
	}

	//物を動かしている時は反応しないようにする
	if (c_move == false) {
		//マウスがクリックされているかどうかの判定
		if (MouseL == 1) {
			//横
			//バーの部分
			if (mx >= scrollbar.x && mx <= scrollbar.x + scrollbar.width && my >= scrollbar.y && my <= scrollbar.y + scrollbar.height) {
				scrollbar.click = 1;
			}
			//それ以外の部分
			//その位置までバーとステージを動かす
			else if (mx >= FRAME_AND_BUTTON && mx <= WINDOW_WIDTH - FRAME_AND_BUTTON && my >= scrollbar.y && my <= scrollbar.y + scrollbar.height) {
				scrollbar.click = 1;
				scrollbar.x = mx - scrollbar.width / 2;
				stage_x = (scrollbar.x - FRAME_AND_BUTTON) * cx2 / (WINDOW_WIDTH - (FRAME_AND_BUTTON * 2 + scrollbar.width));
			}
			//縦
			//バーの部分
			if (mx >= scrollbar2.x && mx <= scrollbar2.x + scrollbar2.width && my >= scrollbar2.y && my <= scrollbar2.y + scrollbar2.height) {
				scrollbar2.click = 1;
			}
			//それ以外の部分
			//その位置までバーとステージを動かす
			else if (mx >= scrollbar2.x && mx <= scrollbar2.x + scrollbar2.width && my >= FRAME_AND_BUTTON && my <= WINDOW_HEIGHT - FRAME_AND_BUTTON) {
				scrollbar2.click = 1;
				scrollbar2.y = my - scrollbar2.height / 2;
				stage_y = (scrollbar2.y - FRAME_AND_BUTTON) * cy2 / (WINDOW_HEIGHT - (FRAME_AND_BUTTON * 2 + scrollbar2.height));
			}
		}
		//マウスがクリックされなくなったら0に戻す
		else {
			if (scrollbar.click == 1) {
				scrollbar.click = 0;
			}
			else if (scrollbar2.click == 1) {
				scrollbar2.click = 0;
			}
		}
	}

	//ボタンによるスクロール
	//左
	if (JudgeMouse2(2, WINDOW_HEIGHT + 2, FRAME_AND_BUTTON, WINDOW_HEIGHT + FRAME_AND_BUTTON)) {
		stage_x -= 8;
	}
	//右
	if (JudgeMouse2(WINDOW_WIDTH - FRAME_AND_BUTTON, WINDOW_HEIGHT + 2, WINDOW_WIDTH - 2, WINDOW_HEIGHT + FRAME_AND_BUTTON)) {
		stage_x += 8;
	}
	//上
	if (JudgeMouse2(WINDOW_WIDTH + 2, 2, WINDOW_WIDTH + FRAME_AND_BUTTON, FRAME_AND_BUTTON)) {
		stage_y -= 8;
	}
	//下
	if (JudgeMouse2(WINDOW_WIDTH + 2, WINDOW_HEIGHT - FRAME_AND_BUTTON, WINDOW_WIDTH + FRAME_AND_BUTTON, WINDOW_HEIGHT - 2)) {
		stage_y += 8;
	}

	//スクロールバーをマウスで操作していない時のみキー操作を可能にする
	if(scrollbar.click == 0 && scrollbar2.click == 0) {
		//右端以外なら右に動かす
		if (button[KEY_RIGHT] && stage_x < width_size * block_size - WINDOW_WIDTH)
			if (Key[KEY_INPUT_LCONTROL])	//Cを押しながら左右で高速スクロール
				stage_x += 24;
			else
				stage_x += 8;
		/*else if (Wheel > 0)
			stage_x += 32;*/

		//左端以外なら左に動かす
		if (button[KEY_LEFT] && stage_x > 0)
			if (Key[KEY_INPUT_LCONTROL])
				stage_x -= 24;
			else
				stage_x -= 8;
		/*else if (Wheel < 0)
			stage_x -= 32;*/

		//下端以外なら下に動かす
		if (button[KEY_DOWN] && stage_y < height_size * block_size - WINDOW_HEIGHT)
			if (Key[KEY_INPUT_LCONTROL])	//Cを押しながら左右で高速スクロール
				stage_y += 24;
			else
				stage_y += 8;
		/*else if (Wheel > 0)
		stage_x += 32;*/

		//上端以外なら上に動かす
		if (button[KEY_UP] && stage_y > 0)
			if (Key[KEY_INPUT_LCONTROL])
				stage_y -= 16;
			else
				stage_y -= 8;
		/*else if (Wheel < 0)
		stage_x -= 32;*/
	}
	//スクロールバーを操作しているならバーと違う向きの軸がずれていてもスクロールバー上にあるとする
	else {
		if (scrollbar.click == 1 && scrollbar2.click == 0) {
			my = my2;
		}
		else if (scrollbar.click == 0 && scrollbar2.click == 1) {
			mx = mx2;
		}
	}

	//画面外に出ないようにする
	if (stage_x > width_size * block_size - GetDrawWidth())
		stage_x = width_size * block_size - GetDrawWidth();
	else if (stage_x < 0)
		stage_x = 0;
	if (stage_y > height_size * block_size - GetDrawHeight())
		stage_y = height_size * block_size - GetDrawHeight();
	else if (stage_y < 0)
		stage_y = 0;

	//スクロールバーの座標を求める
	//スクロールバーの枠+ボタンの大きさ+画面の横幅-(スクロールバーの枠*2+ボタンの大きさ*2+横幅) * 背景の座標/スクロールの幅
	if (cx2 != 0) {
		scrollbar.x = FRAME_AND_BUTTON + ((WINDOW_WIDTH - (FRAME_AND_BUTTON * 2 + scrollbar.width)) * stage_x / cx2);
	}
	if (cy2 != 0) {
		scrollbar2.y = FRAME_AND_BUTTON + ((WINDOW_HEIGHT - (FRAME_AND_BUTTON * 2 + scrollbar2.height)) * stage_y / cy2);
	}
}

//編集可能な画面内の幅を求めて返す
int GetDrawWidth() {

	if (width_size * block_size < WINDOW_WIDTH) {
		return width_size * block_size;
	}
	else {
		return WINDOW_WIDTH;
	}
}

//編集可能な画面内の高さを求めて返す
int GetDrawHeight() {

	if (height_size * block_size < WINDOW_HEIGHT) {
		return height_size * block_size;
	}
	else {
		return WINDOW_HEIGHT;
	}
}
