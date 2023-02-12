#pragma once
//ループ管理のフラグ
//一つの選択画面につき一つ作る
//ゲームプレイ中のフラグは別に作る
enum e_flag
{
	e_title,
	e_movemenu,
	e_operationmenu,
	e_start,
	e_gameplay,
	e_clear,
	e_win,
	e_pause,
	e_keyconfig,
	e_manual,
};

enum e_color
{
	//ec_black = -2,
	ec_white = -1,
	ec_null,
	ec_blue,
	ec_red,
	ec_green,
	ec_yellow,
	ec_purple,
};

//ゲームモードのフラグ
enum e_mode
{
	em_score_attack,	//スコアアタックモード
	em_vs,	//対戦モード
	em_end,			//ゲームを終了する
};

//フェードアウトのフラグ
enum e_fade
{
	ef_normal,			//通常モード
	ef_fadeOut,			//フラグ変更時のフェードアウト
	ef_fadeIn,			//フェードイン
};

//実際のゲームで使うボタン
//キーボードとゲームパッドの入力の両方に対応し、
//キーコンフィグで設定後はボタンが変化する
//ここのボタン数を変えた時は参照がずれるので必ずキーコンフィグも直す
enum e_key
{
	KEY_DOWN,
	KEY_LEFT,
	KEY_RIGHT,
	KEY_UP,
	KEY_SHOT,
	KEY_CANCEL,
	KEY_PAUSE,
};

//効果音
enum e_effectSound
{
	efs_draw,
	efs_vanish,
	efs_select,		//選択の効果音
	efs_back,		//キャンセルの効果音
	efs_result,
	efs_decision,	//決定の効果音
	efs_pause,
};

//向き(0:上 1:右 2:下 3:左 4:今の場所 5:無し)
enum e_direction
{
	ed_up,
	ed_right,
	ed_down,
	ed_left,
	ed_noMove,
	ed_null,
};

//操作方法
enum e_cpuMove
{
	ec_player,
	ec_random,
	ec_move_random,
	ec_search,
	ec_strong,
};

//
enum e_player
{
	e_1p,
	e_2p,
};

//次の落下での色ブロックの落下方法
enum e_nextDropMode
{
	endm_normal,
	endm_center,
};

//
enum e_padInputMode
{
	epad_pad_pad,
	epad_keyboard_pad,
};
