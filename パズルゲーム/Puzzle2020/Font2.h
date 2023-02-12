#pragma once
#include"DxLib.h"

class CFont2
{
private:
	int Font[8];
	int black = GetColor(32, 32, 32);
	int red = GetColor(212, 50, 52);
	int green = GetColor(32, 130, 62);
	int liteGreen = GetColor(0, 254, 0);
	int silver = GetColor(221, 224, 234);
	int white = GetColor(255, 255, 255);
public:
	CFont2();
	~CFont2();
	int getBlack();
	int getRed();
	int getGreen();
	int getLiteGreen();
	int getSilver();
	int getWhite();
	int getFont(int fontNumber);
	void init();
};
