#pragma warning(disable : 4996)
#define WINDOW_WINDTH 800	//縦横比 4:3
#define WINDOW_HEIGHT 600
#define G_W_LEFT 40			//この座標より左は画面外(横480縦560)
#define G_W_RIGHT 519		//この座標より右は画面外
#define G_W_UPPER 20		//この座標より上は画面外
#define G_W_LOWER 579		//この座標より下は画面外
#define ITEM_GET_BORDER 150	//上部回収のライン
#define PHHV 3.75			//速いキャラの高速移動の速度(画面サイズが3/4なので5*3/4)
#define PHLV 3.375			//遅いキャラの高速移動の速度(画面サイズが3/4なので4.5*3/4)
#define PLV 1.5				//低速移動の速度
#define ENEMY 200			//敵の出現の限界数
#define ENEMYEMERGE	500		//敵の出現情報の最大値
#define ITEM 200			//アイテムの出現の限界数
#define BULLET 500			//自分の弾の出現の限界数
#define ENEMYBULLET 3000	//敵の弾の出現の限界数
#define COUNT 14			//入力の待ち時間
#define DAMEGED	60			//被弾後の処理時間
#define DAMEGED_APPEAR 30	//被弾後の出現時間
#define DAMEGED_EFFECT 100	//被弾後のエフェクト時間
#define FIRST_LIFE 7		//残機の初期数
#define FIRST_BOMB 2		//ボムの初期数
#define PLAYER_SIZE 5		//見かけ上の判定の円の半径
#define GRAZESIZE 40		//グレイズ判定のサイズ
#define ENEMYAPPEAR 80		//敵の出現にかかるフレーム
#define ENEMY_BUNISH 30		//敵の消滅にかかるフレーム
#define P_BULLET_BUNISH 7	//自機の弾の消滅にかかるフレーム
#define E_BULLET_BUNISH 30	//敵の弾の消滅にかかるフレーム
#define MAX_ELEMENT 960	//属性ゲージの最大値
#define root2 1.4142135		//ルート2の近似(斜め移動の時の計算に使う)
#define PI 3.141592			//円周率

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
