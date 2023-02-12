#include "searchField.h"
#include "enum.h"

CSearchField::CSearchField(int x, int y, e_direction fd, int count)
{
	this->x = x;
	this->y = y;
	this->fd = fd;
	this->count = count;
}


CSearchField::~CSearchField()
{
}

int CSearchField::getX()
{
	return x;
}

int CSearchField::getY()
{
	return y;
}

int CSearchField::getCount()
{
	return count;
}

e_direction CSearchField::get_fd()
{
	return fd;
}
