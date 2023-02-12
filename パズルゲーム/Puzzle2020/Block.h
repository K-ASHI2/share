#pragma once
#include"enum.h"
#include <bitset>

//フィールド上に存在するブロック
//フィールドに接地して存在するブロックの情報を持つ

class CBlock
{
private:
	int x, y;	//どの位置に存在するブロックか
	e_color color;	//何色を持っているか
	e_color drawColor;	//エフェクトの途中まで来たら塗られる色を保持する
	bool vanishFlag;	//ブロックが消えるかどうか(ブロックの削除中のみ持つ)
	int vanishCount;	//ブロックが消えてから落下するまでのカウント
	int drawEffectCount;	//色を塗っているエフェクトの表示時間
	int chain;	//ブロックの連鎖数
	int chainTime;	//ブロックの連鎖数を保持する時間(落下して数フレームのみ保持する)
	
public:
	CBlock();
	~CBlock();
	e_color getColor();
	void setColor(e_color color);
	e_color getDrawColor();
	void setDrawColor(e_color drawColor);
	bool getVanishFlag();
	void setVanishFlag(bool flag);
	int getVanishCount();
	void setVanishCount(int vanishCount);
	int getDrawEffectCount();
	void setDrawEffectCount(int drawEffectCount);
	int getX();
	int getY();
	int getChain();
	void setChain(int chain);
	int getChainTime();
	void setChainTime(int chainTime);
	void decrementChainTime();
	void init(int x, int y);
	void decrementVanishCount();
	void decrementDrawEffectCount();
};
