#include"define.h"
#include"structImage.h"
#include"structMusic.h"
#include"enum.h"

//プレイヤー関連の構造体
struct _player{
	double x,y;
	double vx,vy;
	int life;	//残機の数 LIFEに表示される残機数はlife-1
	int bomb;	//ボムの所持数
	int muteki;	//無敵時間のカウント
	int inope;	//操作不能かどうか 0: 操作可能 1: 操作不能 2:喰らいボムのみ受け付ける
	int bomb_c;	//ボム時間のカウントで0より大きいならボム時間中
	int bomb_t;	//自機ごとに最初から決まっているボムの時間
	int damaged;//被弾した後動けるようになるまでの時間
	int d_effect;	//被弾後のエフェクトのフレームカウント
	double damaged_x;	//被弾時のx座標
	double damaged_y;	//被弾時のy座標
	double power;
	double size;	//実際の判定の半径
	double grazeSize;	//自機の判定の外側のグレイズ判定のサイズ
	int graze;	//グレイズ回数
	int t;		//プレイヤーから弾を出す間隔のカウント
	int slow_move;	//低速移動なら1,高速なら0
	int bomb_x;	//ボムを撃った瞬間のx座標
	int bomb_y;	//ボムを撃った瞬間のy座標
	int snowGauge;		//雪のゲージ
	int thunderGauge;	//電気のゲージ
	int fireGauge;		//炎のゲージ
	bool snowMode;
	bool thunderMode;
	bool fireMode;
	int maxscore;
	long long score;	//得点(最大10桁なのでint型では足りない)
	enum e_character {
		D_Magician_A, D_Magician_B, L_Magician_A, L_Magician_B,
	};
	enum e_character character;
};

//敵関連の構造体
struct _enemy{
	double x,y;    
	double vx,vy;
	double v;		//移動速度
	double ang;
	double hp;			//現在のhp
	double size;
	int kind;		//敵の種類(外見)
	int pattern;	//行動パターン
	int t;			//敵の出現からの時間
	int wait;		//敵の出現からの待機時間
	int bt;		//敵の弾の発射している時間
	int bkind;	//弾幕の種類
	int color;	//弾の色
	int item;	//落とすアイテムの種類
	int vanish;	//消滅エフェクトのカウント
	int vanish_kind;	//消滅エフェクトの種類
};

//敵の出現情報の構造体
struct _enemyemerge {
	int frame;	//出現フレーム
	int pattern;//敵の行動パタ―ン
	int kind;	//敵の種類
	double x, y;//敵の初期座標
	double v;	//敵の速度(x,yはパターンで決まっている)
	double hp;		//敵のhp
	int wait;	//敵の弾発射までの待機時間
	int bt;		//敵の弾の発射している時間
	int bkind;	//弾幕の種類
	int color;	//弾の色
	int item;	//落とすアイテムの種類
};

//ボスの構造体
struct _boss {
	double x, y;
	//double vx, vy;
	double hp;			//現在のhp
	double maxhp;		//それぞれの攻撃のhpの最大値
	double totalhp;	//ボスのhpの合計の現在のhp
	double maxtotalhp;	//ボスの攻撃のhpの最大値の合計
	int time;
	int maxtime;
	int t;
	double size;
	int kind;	//敵の種類
	int mode;	//ボスの形態
	int mode_p;	//ボスのスペルプラクティスでの形態指定
	int modechange;	//ボスの形態変化のフラグ
	int appear;	//ボスの出現時のフレーム
	int muteki;	//ボスの無敵時間
	int vanish;	//消滅エフェクトのカウント
};

//弾関連の構造体
struct _bullet{
	double atk;
	double x, y;
	double vx, vy;
	int hp;		//hpが0の弾は存在しない弾、1の弾は存在する弾、-1の弾はそのフレームに消えることが確定している弾
	double size;
	int graze;	//グレイズをしていない弾なら1、グレイズした弾なら0
	enum eb_kind kind;	//敵の弾の外見
	int bkind;	//弾の動きの種類
	enum eb_color color;//敵の弾の色
	int move;	//動きの種類
	int vanish;	//消滅エフェクトのカウント
	int pbkind;	//自機の弾の種類
	int img;	//自機の弾の画像
	int t;	//弾の出現からの時間のカウント
	int mutate;	//弾が壁に当たって変化する種類(変わらないなら0)
	double ang;	//回転角(描画に用いる)
};

//アイテム関連の構造体
struct _item{
	double x, y;
	double vx, vy;
	int hp;
	double size;
	int kind;	//アイテムの種類
	int collect;	//上部回収時の自機に向かって引き寄せるフラグ
};

//背景の構造体
struct _background{
	double x,y;
	double vy;
	double size_x;
	double size_y;
	int img;	//現在描画すべき背景
};
