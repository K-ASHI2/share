#pragma warning(disable : 4996)
#define WINDOW_WINDTH 800	//縦横比 4:3
#define WINDOW_HEIGHT 600
#define G_W_LEFT 40			//この座標より左は画面外
#define G_W_RIGHT 519		//この座標より右は画面外
#define G_W_UPPER 88		//この座標より上は画面外
#define G_W_LOWER 581		//この座標より下は画面外
#define G_W_LEFT_2 510		//この座標より上は画面外
#define G_W_RIGHT_2 949		//この座標より下は画面外
#define FIELD_W	6			//フィールドの幅
#define FIELD_H	13			//フィールドの高さ、画面外の一段も含む
#define BLOCK_SIZE 40		//ブロックの大きさ
#define COUNT 14			//メニュー画面の入力の待ち時間
#define NEXT_N 3			//NEXTの数+1
#define VANISH_TIME 20		//ブロックが揃ってから消滅までの時間
#define COMBO_TIME 90		//コンボ継続時間(フレーム)
#define MAX_COMBO_TIME  90	//コンボ継続の最大時間
#define DRAW_EFFECT_TIME 30	//色を塗った時のエフェクトの表示時間
#define LOSE_LIMIT	30		//画面外にブロックが乗ってから敗北までの時間

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
