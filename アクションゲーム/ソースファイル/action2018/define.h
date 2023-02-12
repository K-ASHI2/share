#pragma once
#pragma warning(disable : 4996)
//ウィンドウサイズの定数
#define WINDOW_WIDTH  800	//ゲーム画面のウィンドウの大きさ(横)
#define WINDOW_HEIGHT 480	//ゲーム画面のウィンドウの大きさ(縦)
#define WINDOW_WIDTH_2  800	//ウィンドウの大きさ(横)
#define WINDOW_HEIGHT_2 600	//ウィンドウの大きさ(縦)
//アクションゲームで使用する定数
#define PI 3.141592         //円周率
#define GRA 0.9				//落下の加速度
#define MAXSPEED_X 4.7		//横移動の最高速度
#define MAXSPEED_Y 14		//自由落下の最高速度
#define ACCELE_X 0.20		//横方向の加速度
#define CENTER 384			//マップの中央座標
#define HERO_SIZE_X 32		//主人公の大きさ(横)
#define HERO_SIZE_Y 64		//主人公の大きさ(縦)
#define ATTACK_SIZE_X 32	//攻撃の大きさ(横)
#define ATTACK_SIZE_Y 48	//攻撃の大きさ(縦)
#define WIDTH_SIZE 25		//スクロールの幅の最小サイズ(横)
#define MAX_WIDTH 180       //スクロールの幅の最大サイズ(横)
#define HEIGHT_SIZE 15		//スクロールの幅の最小サイズ(縦)
#define MAX_HEIGHT 180		//スクロールの幅の最大サイズ(縦)
#define BLOCK 32			//タイルの大きさ[px]
#define BULLET 10          //一つの敵が持つ弾の最大数(一つ一つの敵が持つのは無駄すぎるので直す)
//#define BULLET 200          //弾の最大出現数
#define COLOR 4             //色の数
#define MUSIC_MAX 100		//音楽の最大数
#define BACKGROUND_MAX 30	//背景の最大数
#define DAMEGED_EFFECT 100	//ゲームオーバー後のエフェクト時間
//ステージ作成で使用する定数
#define BACK_MAX 300		//バックアップの最大数

//ゲームパッドの入力
//PAD配列の対応している添え字を示す
#define PAD_DOWN	0
#define PAD_LEFT	1
#define PAD_RIGHT	2
#define PAD_UP		3
//裏のスイッチはDにする
#define PAD_X		4
#define PAD_A		5
#define PAD_B		6
#define PAD_Y		7
#define PAD_LB		8
#define PAD_RB		9
#define PAD_LT		10
#define PAD_RT		11
#define PAD_BACK	12
#define PAD_START	13
//他のゲームパッドの場合こちらを参照する
#define PAD_1		4
#define PAD_2		5
#define PAD_3		6
#define PAD_4		7
#define PAD_5		8
#define PAD_6		9
#define PAD_7		10
#define PAD_8		11
#define PAD_9		12
#define PAD_10		13
#define PAD_11		14
#define PAD_12		15
#define PAD_13		16
#define PAD_14		17
#define PAD_15		18
#define PAD_16		19
#define PAD_17		20
#define PAD_18		21
#define PAD_19		22
#define PAD_20		23
#define PAD_21		24
#define PAD_22		25
#define PAD_23		26
#define PAD_24		27
#define PAD_25		28
#define PAD_26		29
#define PAD_27		30
#define PAD_28		31
