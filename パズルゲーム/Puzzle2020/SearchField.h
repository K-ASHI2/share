#pragma once
#include"enum.h"

class CSearchField
{
private:
	int x;
	int y;
	e_direction fd;	//最初に移動した向き
	int count;	//探索中に移動したマス目の数

public:
	CSearchField(int x, int y, e_direction fd, int count);
	~CSearchField();
	int getX();
	int getY();
	int getCount();
	e_direction get_fd();
};
