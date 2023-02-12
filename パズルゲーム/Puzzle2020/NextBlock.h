#pragma once
#include"enum.h"

//nextのブロックと操作中のブロック
class CNextBlock
{
private:
	//1つの色を持つ
	e_color color;
public:
	CNextBlock();
	~CNextBlock();
	e_color getColor();
	void setColor(e_color color);
};
