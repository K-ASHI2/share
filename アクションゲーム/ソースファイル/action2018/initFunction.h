#pragma once

/*初期化関数*/
//マップ読み込み時の初期化
void init();
//マップの数字の初期化の個別処理
void init_map(int i, int j);
//backgroundの初期化
void init_b();
//hpの初期化
void init_l();
//敵の座標とライフと種類と敵の出現の初期化
void init_e(int i, int j, int l = 0, int s = -1, int a = 1);
//壁判定をしない敵の初期化
void init_j(int i, int j);
//大砲の初期化
void init_t(int i, int j, int l, int s);
//キーボードとゲームパッドの入力の初期化
void init_key();
//ゲームパッドのキーコンフィグの初期化
void init_key_p();
//プレイヤーの初期化
void playerInit();
//敵の初期化
void enemyInit();
