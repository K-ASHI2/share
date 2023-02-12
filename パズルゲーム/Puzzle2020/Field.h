#pragma once
#include"Block.h"

class CField
{
private:
	CBlock *neighborBlock[4];

public:
	CField();
	~CField();
	CBlock getNeighborBlock(int d);
	void setNeighborBlock(int d, CBlock *block);
};
