#include "NextBlock.h"
#include"enum.h"

CNextBlock::CNextBlock()
{
}

CNextBlock::~CNextBlock()
{
}

e_color CNextBlock::getColor()
{
	return color;
}

void CNextBlock::setColor(e_color color)
{
	this->color = color;
}
