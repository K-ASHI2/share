#pragma once
#include"enum.h"

class CSearchField
{
private:
	int x;
	int y;
	e_direction fd;	//�ŏ��Ɉړ���������
	int count;	//�T�����Ɉړ������}�X�ڂ̐�

public:
	CSearchField(int x, int y, e_direction fd, int count);
	~CSearchField();
	int getX();
	int getY();
	int getCount();
	e_direction get_fd();
};
