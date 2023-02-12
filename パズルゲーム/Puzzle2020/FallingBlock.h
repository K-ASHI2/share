#pragma once
#include "enum.h"

//落下中で空中に存在するブロック
class CFallingBlock
{
private:
	e_color color;	//何色を持っているか(ec_nullならブロックが存在せず空いている)
	int line;	//どの列にあるか(iで示される方)
	int y;	//y座標(今どの高さにいるか)
	int chain;	//何連鎖しているブロックか(画面外から落下したブロックは0)

public:
	CFallingBlock();
	~CFallingBlock();
	e_color getColor();
	void setColor(e_color color);
	int getLine();
	void setLine(int line);
	int getY();
	void setY(int y);
	void addY(int vy);
	int getChain();
	void setChain(int chain);
	void init();
};
