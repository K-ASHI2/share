#include "Block.h"
#include "struct.h"

//コンストラクタ
CBlock::CBlock() {
	//init();
}

//デストラクタ
CBlock::~CBlock()
{
}

e_color CBlock::getColor()
{
	return color;
}

void CBlock::setColor(e_color color)
{
	this->color = color;
}

e_color CBlock::getDrawColor()
{
	return drawColor;
}

void CBlock::setDrawColor(e_color drawColor)
{
	this->drawColor = drawColor;
}

bool CBlock::getVanishFlag()
{
	return vanishFlag;
}

void CBlock::setVanishFlag(bool flag)
{
	this->vanishFlag = flag;
}

int CBlock::getVanishCount()
{
	return vanishCount;
}

void CBlock::setVanishCount(int vanishCount)
{
	this->vanishCount = vanishCount;
}

int CBlock::getDrawEffectCount()
{
	return drawEffectCount;
}

void CBlock::setDrawEffectCount(int drawEffectCount)
{
	this->drawEffectCount = drawEffectCount;
}

int CBlock::getX()
{
	return x;
}

int CBlock::getY()
{
	return y;
}

int CBlock::getChain()
{
	return chain;
}

void CBlock::setChain(int chain)
{
	this->chain = chain;
}

int CBlock::getChainTime()
{
	return chainTime;
}

void CBlock::setChainTime(int chainTime)
{
	this->chainTime = chainTime;
}

void CBlock::decrementChainTime()
{
	if (chainTime > 0)
	{
		chainTime--;
	}
}

void CBlock::init(int x, int y)
{
	this->x = x;
	this->y = y;
	color = ec_null;
	drawColor = ec_null;
	vanishCount = 0;
	vanishFlag = false;
	drawEffectCount = 0;
	chain = 0;
	chainTime = 0;
}

void CBlock::decrementVanishCount()
{
	vanishCount--;
}

void CBlock::decrementDrawEffectCount()
{
	drawEffectCount--;
}
