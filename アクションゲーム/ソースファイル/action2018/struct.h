#include"define.h"
#include"structPlayer.h"
#include"structEnemy.h"
#include"structImg.h"
#include"structMusic.h"
#include"enum.h"

//弾のstruct
struct S_bullet {
	double x, y;
	double vx, vy;
	double v;//進行方向に進む速度
	int life;    //lifeが0なら画面上に存在していない、1なら存在している
	int atk;     //弾の攻撃力
	int size_x;
	int size_y;
	int species; //弾の種類
	int rad_i;	 //弾の初期の傾き
	int rad_b;	 //弾の回転角
	int rad_v;	 //弾の角速度
};

//読み込まれ背景のデータ(配列に入れる)
struct S_background {
	int size_x;
	int size_y;
	int img;
};

//背景のステータス(現在の位置や速度のみ持つ)
struct S_background2 {
	int x, y;
	int vy;
};
