#pragma once
#include"struct.h"

extern WNDPROC dxWndProc;
//メインウィンドウのハンドル
extern HWND hMainWnd;
//インスタンスハンドル
extern HINSTANCE hInst;

extern S_img img;
extern S_anime ani;	//アニメーションを保存する
extern S_scrollbar scrollbar;
extern S_scrollbar scrollbar2;
extern S_SelectThing select_thing[MAX_THINGS];
extern S_background background[BACKGROUND_MAX];

extern int map[MAX_WIDTH][MAX_HEIGHT];			//下3桁 種類 1000の位 速さ(x.y) 10000の位 向き(1:左 2:右)
extern int backup[BACK_MAX][MAX_WIDTH][MAX_HEIGHT];//最近100回分の作業を保存する
extern int backup_w[BACK_MAX];	//backupのmapの幅
extern int backup_h[BACK_MAX];	//backupのmapの高さ
extern int back_c;	//backupの現在の作業位置
extern int FontHandle;
extern int music[MUSIC_MAX];
extern e_fade fade_flag;	//フェードアウトしているかどうかのフラグ
extern int bright;	//輝度
extern int sound;
extern int width_size;
extern int height_size;
extern int Font[10];
extern int p_music;	//現在の演奏している曲
extern int stage_x;	//ステージのスクロールのx座標
extern int stage_y;	//ステージのスクロールのy座標
extern char *CurrentFile;
extern int param[64];	//ファイルで自由に指定できるパラメータ
extern int param_length;	//パラメータの数
extern int block_size;	//マス目の大きさ
extern int map_si[MAX_THINGS];	//マップ上の番号からselect_thingの配列の添え字への逆引き

//色の変数
extern unsigned int black;
extern unsigned int green;
extern unsigned int red;
extern unsigned int litegreen;
extern unsigned int redbutton;
extern unsigned int bluebutton;

//メニュー画面やキー操作の変数
extern e_flag flag;			//現在のフラグ
extern e_flag cancel_flag;		//キャンセルで戻る時のフラグ
extern bool end_flag;
extern char *cPad[8];	//ゲームパッドの操作するボタンの文字列で操作説明に用いる
extern int cursor;		//縦カーソルがどの位置にあるか
extern int cursor_LR;	//横カーソルがどの位置にあるか
extern int N_o_i;		//現在の選択画面の項目数
extern int N_o_i_LR;	//現在の選択画面の項目数
extern int button[8];	//設定されたボタンの入力フレームカウント e_keyで設定されたenumの値を添え字にする
extern int key_p[8];	//キーコンフィグで設定されたゲームパッドのボタンを配列にゲームパッドの添え字で保存する e_keyで設定されたenumの値を添え字にする
extern int Key[256];	//キー入力の入力フレームカウント
extern int Pad[28];		//ゲームパッドの入力フレームカウント

// change_flagはすぐに実行されないので引数を保存する
extern enum e_flag changeFlag_flag;
extern int changeFlag_cursor;
extern int changeFlag_cursor2;

//ステージ作成で使用する変数
extern int sx, sy;		//選択されているx、y座標を保存する(マップの左上基準のマス目単位)
extern int sx2, sy2;	//メニュー内の選択されているx、y座標を保存する(画面の左上基準)
extern int menu_b;		//ステージ作りのメニューのボタン
extern int cs_page[4];	//ステージ作りのメニューのページ
extern int cs_max_page[4];	//ステージ作りのメニューのページの最大値
extern int si_block;	//select_thingの配列の添え字のブロックの開始位置
extern int si_etc;		//select_thingの配列の添え字のその他の開始位置
extern int si_etc_end;		//select_thingの配列の添え字のその他の終了位置
extern int Mouse;		//マウスを参照する
extern int mx, my;		//マウスのx座標、y座標(画面の左上基準)
extern int mx2, my2;	//1フレーム前のマウスの座標(画面の左上基準)
extern int cs_map;		//選択された物のマップにおける数字
extern int cs_map2;		//動かす時に元の座標にあった数字
extern int P_MouseL;	//1フレーム前の左クリックの入力の有無
extern int MouseL;		//左クリックの入力の有無
extern int scroll_v;	//スクロールの速度 0ならスクロールしない
extern int music_n;		//音楽の番号
extern int background_n;	//背景の番号
extern bool c_move;		//動かし終わるまでバックアップはとらない
extern int back_top;	//バックアップデータの最後尾
extern int back_head;	//バックアップデータの先頭
extern int grid_sizex;	//座標より何ドット右側まで描画するか
extern int grid_sizey;	//座標より何ドット下側まで描画するか
extern int grid_sizex4;	//座標より何ドット左側まで描画するか
extern int grid_sizey4;	//座標より何ドット下側まで描画するか
extern int grid_sizex5;	//動かしているものが座標より何ドット右側まで描画するか
extern int grid_sizey5;	//動かしているものが座標より何ドット下側まで描画するか
extern int grid_sizex6;	//動かしているものが座標より何ドット左側まで描画するか
extern int grid_sizey6;	//動かしているものが座標より何ドット下側まで描画するか
extern int mc;			//コピーする物の番号
extern char *select_description[1000];	//選んでいる物の説明(配列の添え字はマップにおける数字)
