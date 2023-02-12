#pragma once
#include"struct.h"

extern S_img img;
extern S_anime ani;	//アニメーションを保存する
extern S_music music;
extern S_player player;
extern S_enemy enemy[MAX_WIDTH][MAX_HEIGHT];
extern S_bullet enemybullet[MAX_WIDTH][MAX_HEIGHT][BULLET];  //弾のstructを敵の弾用に
extern S_background background[BACKGROUND_MAX];
extern S_background2 background2;

extern int map[MAX_WIDTH][MAX_HEIGHT];	//下2桁 種類 1000の位と100の位 速さ(x.y) 10000の位 向き(1:左 2:右)
extern int s_music[MUSIC_MAX];	//ステージの音楽
extern int backup[BACK_MAX][MAX_WIDTH][MAX_HEIGHT];	//最近100回分の作業を保存する
extern int backup_w[BACK_MAX];	//backupのmapの幅
extern int back_c;	//backupの現在の作業位置
extern int mapload;
extern double deg;	//角速度
extern int kabe[MAX_WIDTH][MAX_HEIGHT];
extern char keyState[256];
extern int FontHandle;
extern e_background back_g;
extern e_fade fade_flag;	//フェードアウトしているかどうかのフラグ
extern int sw;
extern int boss; 
extern int countTime;	//ステージ開始からの時間のカウント
extern int bright;	//輝度
extern int sound;
extern int width_size;
extern int height_size;
extern int scroll_v;	//スクロールの速度 0なら
extern int scroll_leftx;	//スクロールの左端
extern int music_n;	//音楽の番号
extern int background_n;	//背景の番号
extern int test;
extern int Font[10];
extern int p_music;	//現在の演奏している曲
extern int gameover_count;	//ゲームオーバーになってからのエフェクトのカウント

//色の変数
extern int black;
extern int green;
extern int red;
extern int litegreen;

//メニュー画面やキー操作の変数
extern e_flag flag;			//現在のフラグ
extern e_flag cancel_flag;		//キャンセルで戻る時のフラグ
extern e_mode mode_flag;	//ゲームモードのフラグ
extern char *cPad[9];	//ゲームパッドの操作するボタンの文字列で操作説明に用いる
extern int cursor;		//縦カーソルがどの位置にあるか
extern int cursor_LR;	//横カーソルがどの位置にあるか
extern int N_o_i;		//現在の選択画面の項目数
extern int N_o_i_LR;	//現在の選択画面の項目数
extern int button[9];	//設定されたボタンの入力フレームカウント e_keyで設定されたenumの値を添え字にする
extern int key_p[9];	//キーコンフィグで設定されたゲームパッドのボタンを配列にゲームパッドの添え字で保存する e_keyで設定されたenumの値を添え字にする
extern int Key[256];	//キー入力の入力フレームカウント
extern int Pad[28];		//ゲームパッドの入力フレームカウント

// change_flagはすぐに実行されないので引数を保存する
extern enum e_flag changeFlag_flag;
extern int changeFlag_cursor;
extern int changeFlag_cursor2;

//ドアの移動はすぐに実行されないので移動先の座標を保存する
extern int door_fade_x;
extern int door_fade_y;



