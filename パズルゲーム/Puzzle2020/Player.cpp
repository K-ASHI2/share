#include "Player.h"

CPlayer::CPlayer()
{
	//フィールドの隣接ブロックの参照の初期化
	for (int j = 1; j <= FIELD_H; j++)
	{
		for (int i = 1; i <= FIELD_W; i++)
		{
			//隣接ブロックの参照を決める
			//参照なので一度初期化するだけで良さそうなので後で直す
			if (j < FIELD_H)
			{
				field[i][j].setNeighborBlock(ed_up, &block[i][j + 1]);
			}
			//隣接ブロックが無い部分に関してはブロック自身を指すことで存在しないことを表す
			else
			{
				field[i][j].setNeighborBlock(ed_up, &block[i][j]);
			}

			if (i < FIELD_W)
			{
				field[i][j].setNeighborBlock(ed_right, &block[i + 1][j]);
			}
			else
			{
				field[i][j].setNeighborBlock(ed_right, &block[i][j]);
			}

			if (j > 1)
			{
				field[i][j].setNeighborBlock(ed_down, &block[i][j - 1]);
			}
			else
			{
				field[i][j].setNeighborBlock(ed_down, &block[i][j]);
			}

			if (i > 1)
			{
				field[i][j].setNeighborBlock(ed_left, &block[i - 1][j]);
			}
			else
			{
				field[i][j].setNeighborBlock(ed_left, &block[i][j]);
			}
		}
	}
}

CPlayer::~CPlayer()
{
}

int CPlayer::getP()
{
	return p;
}

int CPlayer::getX()
{
	return x;
}

int CPlayer::getY()
{
	return y;
}

int CPlayer::getLevel()
{
	return level;
}

int CPlayer::incrementLevel()
{
	//呼び出し側で上限を超えないようにしている
	return level++;
}

int CPlayer::subDropInterval(int sub)
{
	return dropInterval -= sub;
}

int CPlayer::getDropNotice()
{
	return dropNotice;
}

void CPlayer::setDropNotice(int dropNotice)
{
	this->dropNotice = dropNotice;
}

void CPlayer::addDropNotice(int dropNotice)
{
	this->dropNotice += dropNotice;
}

int CPlayer::getGameover()
{
	return gameover;
}

int CPlayer::getLoseCount(int line)
{
	return loseCount[line];
}

int CPlayer::getFieldLeft()
{
	return field_left;
}

int CPlayer::getFieldRight()
{
	return field_right;
}

int CPlayer::getFieldUpper()
{
	return field_upper;
}

int CPlayer::getFieldLower()
{
	return field_lower;
}


CNextBlock CPlayer::getNextBlock(int i)
{
	return nextBlock[i];
}

long long CPlayer::getScore()
{
	return score;
}

void CPlayer::setScore(long long score)
{
	this->score = score;
}

int CPlayer::getCombo()
{
	return combo;
}

int CPlayer::getComboTime()
{
	return comboTime;
}

//int CPlayer::getChainCount()
//{
//	return chainCount;
//}

CFallingBlock CPlayer::getFallingBlock(int i)
{
	return fallingBlock[i];
}

CBlock CPlayer::getBlock(int i, int j)
{
	return block[i][j];
}

CBlock * CPlayer::getBlock2(int i, int j)
{
	return &block[i][j];
}

CField CPlayer::getField(int i, int j)
{
	return field[i][j];
}

e_cpuMove CPlayer::getCpuMove()
{
	return cpuMove;
}

void CPlayer::setCpuMove(e_cpuMove cpuMove)
{
	this->cpuMove = cpuMove;
}

void CPlayer::setThinkingTime(int thinkingTime)
{
	this->thinkingTime = thinkingTime;
}
 