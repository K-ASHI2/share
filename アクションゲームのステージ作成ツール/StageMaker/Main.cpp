#include"DxLib.h"
#include"grobal.h"
#include"function.h"
#include"resource.h"
#include"WinUser.h"

//ショートカットキーの追加
void AddShortCutKey();

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR ipCmdLine, int nShowCmd){

	hInst = hInstance;
	//block_size = 16;	//ブロックを小さくする用のテスト値

	//ウィンドウのタイトルを変更
	SetMainWindowText("STAGE MAKER");

	//ウィンドウモードに変更
	ChangeWindowMode(TRUE);

	//メニューのIDを読み込む
	LoadMenuResource(IDR_MENU1);

	//解像度とカラービット数を設定
	SetGraphMode(WINDOW_WIDTH_2, WINDOW_HEIGHT_2, 32);	

	//ウインドウサイズを可変にする
	SetWindowSizeChangeEnableFlag(TRUE) ;

	// 描画する文字列のサイズを設定
	SetFontSize(32) ;
	// 描画する文字列の太さを設定
    SetFontThickness(3) ;

	//二重起動の禁止
	SetDoubleStartValidFlag(TRUE);
	//
	//SetWindowStyleMode(7);

	//初期化に失敗したらやめる
	if (DxLib_Init() == -1) {
		return 0;
	}

	//メインウィンドウのハンドルを取得
	hMainWnd = GetMainWindowHandle();

	//64bitではGWL_WNDPROCではなくGWLP_WNDPROCを使う
	dxWndProc = (WNDPROC)GetWindowLongPtr(hMainWnd, GWLP_WNDPROC);

	//ウインドウプロシージャの呼出し
	//GetMainWindowHandle:メインウィンドウのウィンドウハンドルを返す関数
	//GWL_WNDPROC:ウィンドウプロシージャのアドレス
	//WinProc:コールバックの関数
	SetWindowLongPtr(hMainWnd, GWLP_WNDPROC, (LONG_PTR)MyWndProc);

	SetUseMenuFlag(TRUE);	// メニューを有効にする
	SetUseKeyAccelFlag(TRUE);	// キーボードアクセラレーターを使用する
	LoadMenuResource(IDR_MENU1);	// メニューをリソースから読み込む
	AddShortCutKey();	//ショートカットキーを追加する

	//画像のロード
	LoadImage();
	//アニメーションのロード
	LoadAnime();
	//音楽のロード
	LoadMusic();
	//背景のロード
	LoadBackground();
	//ステージに置く物の初期化
	LoadSelectThings();

	Font[0] = CreateFontToHandle("ＭＳ ゴシック", 20, 10, DX_FONTTYPE_NORMAL);           //"MSゴシック"の20pt,太さ10のフォントを作成
	Font[1] = CreateFontToHandle("Arial", 27, 10, DX_FONTTYPE_NORMAL);
	Font[2] = CreateFontToHandle("ＭＳ ゴシック", 30, 10, DX_FONTTYPE_NORMAL);

	//色の初期化
	//関数を呼び出すためdefineできないのでここで初期化する
	black = GetColor(0, 0, 0);		//黒
	green = GetColor(32, 130, 62);	//緑
	red = GetColor(212, 50, 52);	//赤
	litegreen = GetColor(0, 254, 0);//明るい緑
	redbutton = GetColor(255, 184, 211);
	bluebutton = GetColor(191, 223, 255);

	SetDrawScreen(DX_SCREEN_BACK);

	FontHandle = CreateFontToHandle(NULL,20,3);

	//ゲームパッドのキーコンフィグの初期化
	init_key_p();

	//ステージ選択のフラグにする(フェードアウトしない)
	ChangeFlag2(e_createStage);

	//デフォルトのステージを呼び出す
	NewMap();

	//ステージ作成の初期化
	//ステージ選択後にも行うように変更する
	init_c();

	/************************** ゲームループ *****************************/

	//フラグがem_endになるかescapeが押されたら終了する
	while (!ProcessMessage() && end_flag == false) {

		//フェードアウトするかどうか
		switch(fade_flag){
		case ef_fadeOut:
			FadeOut();
			break;
		case ef_fadeIn:
			FadeIn();
			break;
		case ef_normal:
			UpdateKey();	//キー入力の更新
			Update();		//ゲーム処理の更新
			break;
		}
		Draw();			//描画はフェードアウトに関わらず行う
	}

	/************************ ゲームループおわり ************************/

	//DXライブラリ使用の終了処理
	DxLib_End();
	
	//SOFTの終了
	return 0;

}

//ショートカットキーの追加
void AddShortCutKey() {

	//Dxlibを用いる場合ProcessMessageでループするため、この関数を用いなければならない
	//IDやメニューもDxlibの関数で追加することもできるがこのプログラムでは直接指定している
	AddKeyAccel_ID(IDM_NEWFILE, KEY_INPUT_N, 1, 0, 0);
	AddKeyAccel_ID(IDM_OPENFILE, KEY_INPUT_O, 1, 0, 0);
	AddKeyAccel_ID(IDM_SAVE, KEY_INPUT_S, 1, 0, 0);
	AddKeyAccel_ID(IDM_SAVEAS, KEY_INPUT_A, 1, 0, 0);
	AddKeyAccel_ID(IDM_END, KEY_INPUT_ESCAPE, 0, 0, 0);

	AddKeyAccel_ID(IDM_UNDO, KEY_INPUT_Z, 1, 0, 0);
	AddKeyAccel_ID(IDM_REDO, KEY_INPUT_Y, 1, 0, 0);
	AddKeyAccel_ID(IDM_TRIMMING, KEY_INPUT_X, 1, 0, 0);
	AddKeyAccel_ID(IDM_COPY, KEY_INPUT_C, 1, 0, 0);
	AddKeyAccel_ID(IDM_PASTE, KEY_INPUT_V, 1, 0, 0);

	//消去はDELとBACKSPACEの両方に対応させる
	AddKeyAccel_ID(IDM_DELETE, KEY_INPUT_DELETE, 0, 0, 0);
	AddKeyAccel_ID(IDM_DELETE, KEY_INPUT_BACK, 0, 0, 0);
}
