#include"DxLib.h"
#include"extern.h"
#include"function.h"

//描画の関数
void Draw() {

	//画面クリア
	ClearDrawScreen();

	switch (flag) {
	case e_createStage:		//ステージ作成中の画面
		DrawStage();
		break;
	}
	ScreenFlip();
}

void BlackScreen(int t) {//指定した時間だけ画面が切り替わる時に真っ暗にする
	ClearDrawScreen();
	ScreenFlip();
	WaitTimer(t);
}
