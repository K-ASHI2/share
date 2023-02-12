#pragma once

//敵関連の構造体
struct S_enemy
{
	double x, y;		//敵のX,Y座標
	double vx, vy;		//敵のX,Y軸方向の速度
	double by;			//1フレーム前のy座標
	double rad;			//敵の角度
	double m_rad;		//マップからの角度の速度設定
	int life;			//敵の体力
	int species;		//敵の種類
	int appear;			//敵の出現
	int size_x, size_y;	//敵の大きさ
	int countx, county;	//敵の動く際のカウント
	int dire;			//ステージのマップから読み込んだ向き	
	int dire_x;			//敵の向いている方向	0:右/1:左
	int dire_y;			//敵の向いている方向	0:上/1:下
	int hantei;			//判定があるかどうか
	int muteki;			//無敵かどうか　　　　0:通常/1:無敵
	int jfly;			//空中にいるかどうかの判別　0:着地/1:それ以外
	int jfly2;			//1フレーム前に空中にいたかどうか
	int t;				//その敵が作られてからのフレーム数を格納するメンバ
	int jx;				//横判定するかどうか
	int jy;				//縦判定するかどうか
	int drop;			//アイテムを落とす確率
	double sin_v;		//sin波の加速をする時の元となる速度
	int vanish;			//消滅のエフェクトのフラグ
	double vanish_x;		//消滅した時のx座標
	double vanish_y;		//消滅した時のy座標
	int v_flag;			//ボスのhpが減った時の加速のフラグ
	int m_count;		//ボスの動きが止まっている時間のカウント
};