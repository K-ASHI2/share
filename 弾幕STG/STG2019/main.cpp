#include"DxLib.h"
#include"grobal.h"
#include"function.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {

	//ウィンドウのタイトルを変更
	SetMainWindowText("Barrage Absorber");

	ChangeWindowMode(TRUE);
	SetWindowSizeChangeEnableFlag(TRUE);

	//解像度とカラービット数を設定
	SetGraphMode(WINDOW_WINDTH, WINDOW_HEIGHT, 32);

	//Releaseで起動する時は消す
	//SetWindowSizeExtendRate(1.5);

	//最大化ボタンを付ける
	SetWindowStyleMode(7);

	//初期化に失敗したらやめる
	if (DxLib_Init() != 0)
		return 0;

	SetDrawScreen(DX_SCREEN_BACK);

	//ゲームパッドのキーコンフィグの初期化
	init_key_p();

	//フォントの設定
	SetFont();

	Load();

	//難易度の初期化(難易度選択の代わり)
	//difficulty = ed_easy;
	difficulty = ed_normal;
	//difficulty = ed_hard;
	//difficulty = ed_lunatic;

	PlayMusic(music.menu);
	ChangeFlag2(e_title);
	while (!ProcessMessage() && mode_flag != em_end && !Key[KEY_INPUT_ESCAPE]) {

		//二重になっているので消して全体を直す
		UpdateKey();
		Update();
		Draw();

		if (count > 0)
			count--;
		//フェードアウトするかどうか
		switch (fade_flag) {
		case ef_fadeOut:
			FadeOut();
			break;
		case ef_fadeIn:
			FadeIn();
			break;
		case ef_normal:
			UpdateKey();	//キー入力の更新
			Update();		//ゲーム処理の更新
			//Draw();
			break;
		}
	}
	DxLib_End();
	return 0;
}
