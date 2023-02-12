#pragma once
#include"struct.h"

WNDPROC dxWndProc;
//メインウィンドウのハンドル
HWND hMainWnd;
//インスタンスハンドル
HINSTANCE hInst;

//構造体の宣言
struct S_img img;
struct S_anime ani;
struct S_scrollbar scrollbar;
struct S_scrollbar scrollbar2;
struct S_SelectThing select_thing[MAX_THINGS];
struct S_background background[BACKGROUND_MAX];

int map[MAX_WIDTH][MAX_HEIGHT];
int backup[BACK_MAX][MAX_WIDTH][MAX_HEIGHT];//最近100回分の作業を保存する
int backup_w[BACK_MAX];	//backupのmapの幅
int backup_h[BACK_MAX];	//backupのmapの高さ
int back_c;	//backupの現在の作業位置
int music[MUSIC_MAX];
int FontHandle;
enum e_fade fade_flag;	//フェードアウトしているかどうかのフラグ
int bright = 255;	//画面の輝度
int sound;		//0なら音が鳴らない　1なら鳴る
int width_size = WIDTH_SIZE;	//ステージによってステージのサイズを変える
int height_size = HEIGHT_SIZE;
int Font[10];	//フォント(増やすなら配列にする)
int p_music = -1;//現在の演奏している曲
int stage_x;	//ステージのスクロールのx座標
int stage_y;	//ステージのスクロールのy座標
char *CurrentFile = "default.txt";
int param[64];	//ファイルで自由に指定できるパラメータ
int param_length;	//パラメータの数
int block_size = BLOCK;	//マス目の大きさ
int map_si[1000];	//マップ上の番号からselect_thingの配列の添え字への逆引き

//色の変数
unsigned int black;
unsigned int green;
unsigned int red;
unsigned int litegreen;
unsigned int redbutton;
unsigned int bluebutton;

//メニュー画面やキー操作の変数
enum e_flag flag = e_createStage;			//現在のフラグ
enum e_flag cancel_flag = e_createStage;	//キャンセルで戻る時のフラグ
bool end_flag = false;
char *cPad[8];//ゲームパッドの操作するボタンの文字列で操作説明に用いる
int cursor = 0;		//縦カーソルがどの位置にあるか
int cursor_LR = 0;	//横カーソルがどの位置にあるか
int N_o_i = 0;		//現在の選択画面の項目数
int N_o_i_LR = 0;	//現在の選択画面の項目数
int button[8];		//設定されたボタンの入力フレームカウント e_keyで設定されたenumの値を添え字にする
int key_p[8];		//キーコンフィグで設定されたゲームパッドのボタンを配列にゲームパッドの添え字で保存する e_keyで設定されたenumの値を添え字にする
int Key[256];
int Pad[28];		//ゲームパッドの入力フレームカウント

// change_flagはすぐに実行されないので引数を保存する
enum e_flag changeFlag_flag;
int changeFlag_cursor;
int changeFlag_cursor2;

//ステージ作成で使用する変数
int sx, sy;		//選択されているx、y座標を保存する(マップの左上基準のマス目単位)
int sx2, sy2;	//メニュー内の選択されているx、y座標を保存する(画面の左上基準)
int menu_b;		//ステージ作りのメニューのボタン
int cs_page[4];	//ステージ作りのメニューのページ
int cs_max_page[4];	//ステージ作りのメニューのページの最大値
int si_block;	//select_thingの配列の添え字のブロックの開始位置
int si_etc;		//select_thingの配列の添え字のその他の開始位置
int si_etc_end;	//select_thingの配列の添え字のその他の終了位置
int Mouse;		//マウスを参照する
int mx, my;		//マウスのx座標、y座標(画面の左上基準)
int mx2,my2;	//1フレーム前のマウスの座標(画面の左上基準)
int cs_map;		//選択された物のマップにおける数字
int cs_map2;	//動かす時に元の座標にあった数字
int P_MouseL;	//1フレーム前の左クリックの入力の有無
int MouseL;		//左クリックの入力の有無
int scroll_v;	//スクロールの速度 0ならスクロールしない
int music_n;		//音楽の番号
int background_n;	//背景の番号
bool c_move = false;	//動かし終わるまでバックアップはとらない:動かしているならtrue
int back_top;			//バックアップデータの最後尾
int back_head;			//バックアップデータの先頭
int grid_sizex = 32;	//座標より何ドット右側まで描画するか
int grid_sizey = 32;	//座標より何ドット下側まで描画するか
int grid_sizex4 = 0;	//座標より何ドット左側まで描画するか
int grid_sizey4 = 0;	//座標より何ドット下側まで描画するか
int grid_sizex5 = -1;	//動かしているものが座標より何ドット右側まで描画するか
int grid_sizey5 = -1;	//動かしているものが座標より何ドット下側まで描画するか
int grid_sizex6 = 0;	//動かしているものが座標より何ドット左側まで描画するか
int grid_sizey6 = 0;	//動かしているものが座標より何ドット下側まで描画するか
int mc = 0;				//コピーする物の番号
char *select_description[1000];	//選んでいる物の説明(配列の添え字はマップにおける数字)
