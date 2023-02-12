#include "define.h"
#include "Field.h"

CField::CField()
{
}

CField::~CField()
{
}

CBlock CField::getNeighborBlock(int d)
{
	//4方向以外ならエラー
	if (d < 0 || d > 4)
	{

	}
	return *neighborBlock[d];
}


void CField::setNeighborBlock(int d, CBlock *block)
{
	//4方向以外ならエラー
	if (d < 0 || d > 4)
	{

	}
	neighborBlock[d] = block;
}
