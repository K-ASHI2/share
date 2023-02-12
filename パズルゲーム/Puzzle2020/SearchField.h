#pragma once
#include"enum.h"

class CSearchField
{
private:
	int x;
	int y;
	e_direction fd;	//Å‰‚ÉˆÚ“®‚µ‚½Œü‚«
	int count;	//’Tõ’†‚ÉˆÚ“®‚µ‚½ƒ}ƒX–Ú‚Ì”

public:
	CSearchField(int x, int y, e_direction fd, int count);
	~CSearchField();
	int getX();
	int getY();
	int getCount();
	e_direction get_fd();
};
