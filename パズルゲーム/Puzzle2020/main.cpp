#include"DxLib.h"
#include"grobal.h"
#include"function.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	//ウィンドウのタイトルを変更
	SetMainWindowText("Draw&Drop Twins");

	ChangeWindowMode(TRUE);
	SetWindowSizeChangeEnableFlag(TRUE);

	//解像度とカラービット数を設定
	SetGraphMode(WINDOW_WINDTH, WINDOW_HEIGHT, 32);

	//最大化ボタンを付ける
	SetWindowStyleMode(7);

	//初期化に失敗したらやめる
	if (DxLib_Init() != 0)
		return 0;

	SetDrawScreen(DX_SCREEN_BACK);

	//ゲームパッドのキーコンフィグの初期化
	keyPad.init();

	//キー入力の初期化
	keyPad.init_key();

	//フォントの設定
	font.init();

	load();

	music.playMenu();
	menuWindow.changeFlag2(e_title);

	//2Pの選択画面が未実装なのでここで指定している(後で直す)
	player2.setCpuMove(ec_search);

	while (!ProcessMessage() && mode_flag != em_end && !keyPad.getKey(KEY_INPUT_ESCAPE))
	{
		//フェードアウトするかどうか
		switch (menuWindow.getFadeFlag())
		{
		case ef_fadeOut:
			menuWindow.fadeOut();
			break;
		case ef_fadeIn:
			menuWindow.fadeIn();
			break;
		case ef_normal:
			keyPad.updateKey();	//キー入力の更新
			update();		//ゲーム処理の更新
			break;
		}

		draw();
	}

	DxLib_End();
	return 0;
}
