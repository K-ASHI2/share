#include"DxLib.h"
#include"function.h"
#include"extern.h"

//変数の初期化
void init(){

	init_key();	//キーボードとゲームパッドの入力の初期化
	playerInit();
	enemyInit();
	deg = 0;	//回転する物の角度の初期化
	//ファイアバーと回転する敵は初期位置が指定されていないので一度moveで位置を初期化する
	moveFirebar(); 
	sw = 0;	//スイッチをオフにする
	boss = 0;
	init_b();	//背景の初期化
	countTime = 0;	//ステージ開始からの経過時間
	scroll_leftx = 0;
	gameover_count = -1;
	enemymove();	//回転する敵だけ位置を修正する(バグ起こりそうだからよくない?)
}

//主人公のhpの初期化
void init_l(){
	player.life = player.maxlife;
}

//敵の座標とライフと種類と敵の出現の初期化
void init_e(int i, int j, int l, int s, int a) {
	//デフォルト引数 l = 0 s = -1 a = 1
	enemy[i][j].x = i * BLOCK;
	enemy[i][j].y = j * BLOCK;
	enemy[i][j].life = l;
	enemy[i][j].species = s;
	enemy[i][j].appear = a;
}

//背景の位置と速度の初期化
void init_b() {
	background2.x = 0;
	background2.y = 0;
	background2.vy = 10;
}

//縦横判定を無くす
void init_j(int i, int j) {
	enemy[i][j].jx = 0;
	enemy[i][j].jy = 0;
}

void init_t(int i, int j, int l, int s) {
	init_e(i, j, l, s);
	kabe[i][j] = 1;
	enemy[i][j].hantei = 0;
	enemy[i][j].muteki = 1;
	enemy[i][j].jx = 0;
	enemy[i][j].jy = 0;
	enemy[i][j].t = 60 + GetRand(90);
}
