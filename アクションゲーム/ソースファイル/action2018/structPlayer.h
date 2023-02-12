#pragma once

//プレイヤー関連の構造体
struct S_player
{
	double x, y;		//主人公のX,Y座標
	double by;		//1フレーム前のy座標
	double vx, vy;	//主人公のX,Y軸方向の速度
	double vx2;		//主人公の加速中の速度
	int life;       //主人公の体力
	int maxlife;       //主人公の体力の最大値
	int muteki;     //無敵かどうか　　　　　　　0:通常/1:無敵
	int jfly;		//飛んでいるかどうかの判別　0:着地/1:それ以外
	int crouch;     //しゃがんでいるかどうか
	int jp2;        //今のフレームでジャンプしていたら1、していなければ0
	int dire;		//主人公の向いている方向	0:右/1:左
	int dire_m;		//主人公が動いているかどうか 0:止まっている 1:左に動いている 2:右に動いている
	int attack;		//攻撃中かどうかの判別		0:通常/1:攻撃中
	int kabe_r;		//右方向に壁があるかどうかの判定
	int kabe_l;		//左方向に壁があるかどうかの判定
	int mv;         //動く床に乗っているかどうか
	int size_x;     //主人公の幅
	int size_y;     //主人公の高さ
	int footcount;	//主人公の足
};
