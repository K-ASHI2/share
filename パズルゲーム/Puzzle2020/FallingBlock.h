#pragma once
#include "enum.h"

//�������ŋ󒆂ɑ��݂���u���b�N
class CFallingBlock
{
private:
	e_color color;	//���F�������Ă��邩(ec_null�Ȃ�u���b�N�����݂����󂢂Ă���)
	int line;	//�ǂ̗�ɂ��邩(i�Ŏ�������)
	int y;	//y���W(���ǂ̍����ɂ��邩)
	int chain;	//���A�����Ă���u���b�N��(��ʊO���痎�������u���b�N��0)

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
