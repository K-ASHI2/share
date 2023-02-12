#pragma once
#include"struct.h"

//構造体の宣言
struct S_img img;
struct S_anime ani;
struct S_music music;
struct S_player player;
struct S_enemy enemy[MAX_WIDTH][MAX_HEIGHT];
struct S_bullet enemybullet[MAX_WIDTH][MAX_HEIGHT][BULLET];  //弾のstructを敵の弾用に
struct S_background background[BACKGROUND_MAX];
struct S_background2 background2;

int map[MAX_WIDTH][MAX_HEIGHT];
int s_music[MUSIC_MAX];	//ステージの音楽
int mapload;
double deg = 0;		//角速度
int kabe[MAX_WIDTH][MAX_HEIGHT]; //1なら壁
char keyState[256];
int FontHandle;
enum e_background back_g;
enum e_fade fade_flag;	//フェードアウトしているかどうかのフラグ
int sw;			//スイッチのオンオフ
int boss;		//ボスを倒すと1
int countTime;	//ステージ開始からの時間のカウント
int bright = 255;	//画面の輝度
int sound;		//0なら音が鳴らない　1なら鳴る
int width_size = WIDTH_SIZE;	//ステージによってステージのサイズを変える
int height_size = HEIGHT_SIZE;
int scroll_v;	//スクロールの速度 0ならスクロールしない
int scroll_leftx;	//スクロールの左端
int music_n;		//音楽の番号
int background_n;	//背景の番号
int test = 0;	//テスト用の変数
int Font[10];	//フォント(増やすなら配列にする)
int p_music = -1;//現在の演奏している曲
int gameover_count;	//ゲームオーバーになってからのエフェクトのカウント

//色の変数
int black;
int green;
int red;
int litegreen;

//メニュー画面やキー操作の変数
enum e_flag flag = e_title;			//現在のフラグ
enum e_flag cancel_flag = e_title;	//キャンセルで戻る時のフラグ
enum e_mode mode_flag = em_normal;	//ゲームモードのフラグ
char *cPad[9];//ゲームパッドの操作するボタンの文字列で操作説明に用いる
int cursor = 0;		//縦カーソルがどの位置にあるか
int cursor_LR = 0;	//横カーソルがどの位置にあるか
int N_o_i = 0;		//現在の選択画面の項目数
int N_o_i_LR = 0;	//現在の選択画面の項目数
int button[9];		//設定されたボタンの入力フレームカウント e_keyで設定されたenumの値を添え字にする
int key_p[9];		//キーコンフィグで設定されたゲームパッドのボタンを配列にゲームパッドの添え字で保存する e_keyで設定されたenumの値を添え字にする
int Key[256];
int Pad[28];		//ゲームパッドの入力フレームカウント

// change_flagはすぐに実行されないので引数を保存する
enum e_flag changeFlag_flag;
int changeFlag_cursor;
int changeFlag_cursor2;

//ドアの移動はすぐに実行されないので移動先の座標を保存する
int door_fade_x;
int door_fade_y;
