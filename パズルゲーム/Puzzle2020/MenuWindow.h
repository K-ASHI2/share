#pragma once
#include "enum.h"

class CMenuWindow
{
private:
	/*change_flagはすぐに実行されないので引数を保存する*/
	enum e_flag changeFlag_flag;
	int changeFlag_cursor;
	int changeFlag_cursor2;
	int cursor = 0;		//縦カーソルがどの位置にあるか
	int cursor_LR = 0;	//横カーソルがどの位置にあるか
	int cancel_cursor = 0;	//キャンセルで戻る時のカーソルの位置
	int N_o_i = 0;		//現在の選択画面の縦の項目数(number of item)
	int N_o_i_LR = 0;	//現在の選択画面の横の項目数
	int cursor_count = 0;		//カーソル入力の待ち時間のカウント
	int bright = 255;	//画面の輝度
	int PlaybackFlag = 0;	//ポーズ画面から戻った後の再生時は1,それ以外は0
	enum e_flag flag;
	enum e_flag cancelFlag = e_title;	//キャンセルで戻る時のフラグ
	enum e_fade fadeFlag;		//フェードアウトしているかどうかのフラグ
	int stageStartCount = 0;	//ゲーム開始前のカウント
	bool stageStartFlag = false;	//カウント開始しているかどうか

public:
	CMenuWindow();
	~CMenuWindow();
	int getFlag();
	enum e_fade getFadeFlag();
	void changeFlag(e_flag f, int c = 0, int c2 = 0);
	void changeFlag2(e_flag f, int c = 0, int c2 = 0);
	void setSelectWindow(int n, int c = 0);
	void setSelectWindow_LR(int n, int n2, int c = 0, int c2 = 0);
	void selectWindow(int mode = 0);
	void selectWindow_LR();
	void keyConfig();
	void drawKeyConfig();
	void manual();
	void drawManual();
	void pause();
	void drawPause();
	void clear();
	void drawClear();
	void win();
	void drawWin();
	void start();
	void drawStart();
	void title();
	void drawTitle();
	void moveMenu();
	void drawMoveMenu();
	void operationMenu();
	void drawOperationMenu();
	void drawRed(int x, int y, const char * String, int c);
	void drawRed2(int x, int y, const char * String, int c, int c2);
	//x座標,y座標,文字列、縦に何番目かを引数とし、カーソルの位置が同じならC_ColorとC_EdgeColor、違うならN_ColorとN_EdgeColorで描画する関数
	void drawColor(int x, int y, const char *String, int c, unsigned int N_Color, unsigned int C_Color, unsigned int N_EdgeColor = 0U, unsigned int C_EdgeColor = 0U);
	void fadeOut();
	void fadeIn();
};

