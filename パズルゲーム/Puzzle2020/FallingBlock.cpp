#include "FallingBlock.h"
#include "DxLib.h"

CFallingBlock::CFallingBlock()
{
	init();
}

CFallingBlock::~CFallingBlock()
{
}

e_color CFallingBlock::getColor()
{
	return color;
}

void CFallingBlock::setColor(e_color color)
{
	this->color = color;
}

int CFallingBlock::getLine()
{
	return line;
}

void CFallingBlock::setLine(int line)
{
	this->line = line;
}

int CFallingBlock::getY()
{
	return y;
}

void CFallingBlock::setY(int y)
{
	this->y = y;
}

void CFallingBlock::addY(int vy)
{
	this->y += vy;
}

int CFallingBlock::getChain()
{
	return chain;
}

void CFallingBlock::setChain(int chain)
{
	this->chain = chain;
}

void CFallingBlock::init()
{
	color = ec_null;
	line = 0;
	y = INT_MAX;
	chain = 0;
}
