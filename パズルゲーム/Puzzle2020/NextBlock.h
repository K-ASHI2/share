#pragma once
#include"enum.h"

//next�̃u���b�N�Ƒ��쒆�̃u���b�N
class CNextBlock
{
private:
	//1�̐F������
	e_color color;
public:
	CNextBlock();
	~CNextBlock();
	e_color getColor();
	void setColor(e_color color);
};
