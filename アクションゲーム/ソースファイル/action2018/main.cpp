#include"DxLib.h"
#include"grobal.h"
#include"function.h"

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR ipCmdLine, int nShowCmd){

	//ウィンドウのタイトルを変更
	SetMainWindowText("ROUND MONSTERS 3");

	//ウィンドウモードに変更
	ChangeWindowMode(TRUE);

	//解像度とカラービット数を設定
	SetGraphMode(WINDOW_WIDTH_2, WINDOW_HEIGHT_2, 32);

	//SetWindowSizeExtendRate(1.5);

	SetWindowSizeChangeEnableFlag(TRUE) ;

	// 描画する文字列のサイズを設定
	SetFontSize(32) ;
	// 描画する文字列の太さを設定
    SetFontThickness(3) ;

	//初期化に失敗したらやめる
	if (DxLib_Init() != 0)
		return 0;

	//画像のロード
	image();
	//アニメーションのロード
	anime();
	//音楽のロード
	Music();
	//背景のロード
	LoadBackground();

	Font[0] = CreateFontToHandle("ＭＳ ゴシック", 20, 10, DX_FONTTYPE_NORMAL);           //"MSゴシック"の20pt,太さ10のフォントを作成
	Font[1] = CreateFontToHandle("Arial", 27, 10, DX_FONTTYPE_NORMAL);
	Font[2] = CreateFontToHandle("ＭＳ ゴシック", 30, 10, DX_FONTTYPE_NORMAL);
	Font[4] = CreateFontToHandle("ＭＳ ゴシック", 12, 6, DX_FONTTYPE_NORMAL);
	//色の初期化
	//関数を呼び出すためdefineできないのでここで初期化する
	black = GetColor(0, 0, 0);		//黒
	green = GetColor(32, 130, 62);	//緑
	red = GetColor(212, 50, 52);	//赤
	litegreen = GetColor(0, 254, 0);//明るい緑

	SetDrawScreen(DX_SCREEN_BACK);

	FontHandle = CreateFontToHandle(NULL,20,3);
	//ゲームパッドのキーコンフィグの初期化
	init_key_p();
	//タイトル画面のフラグにする(フェードアウトしない)
	change_flag2(e_title);

	
	/************************** ゲームループ *****************************/

	//フラグがem_endになるかescapeが押されたら終了する
	while (!ProcessMessage() && mode_flag != em_end && !Key[KEY_INPUT_ESCAPE]) {

		//フェードアウトするかどうか
		switch(fade_flag){
		case ef_fadeOut:
			fadeOut();
			break;
		case ef_fadeOut_door:
			fadeOut_door();
			break;
		case ef_fadeOut_door2:
			fadeOut_door2();
			break;
		case ef_fadeIn:
			fadeIn();
			break;
		case ef_normal:
			updateKey();	//キー入力の更新
			update();		//ゲーム処理の更新
			break;
		}

		//描画はフェードアウトに関わらず行う
		draw();
	}

	/************************ ゲームループおわり ************************/

	//DXライブラリ使用の終了処理
	DxLib_End();
	
	//SOFTの終了
	return 0;

}
