#include"DxLib.h"
#include"extern.h"
#include"function.h"

//2�̉~����̕����d�Ȃ��Ă��邩���肷��
//�d�Ȃ��Ă���1�A�d�Ȃ��Ė������0��Ԃ�
int judge(double x1, double y1, int size1, double x2, double y2, double size2) {
	int x, y, size;
	x = x2 - x1;
	y = y2 - y1;
	size = size1 + size2;
	if (x * x + y * y < size * size)
		return 1;
	else
		return 0;
}

//���[�U�[�̔���
int judge_laser(double x1, double y1, int size1, double x2, double y2, double size2) {
	
	if (x1 - size1 < x2 + size2 &&	//���[�U�[�̍��[�̔���
		x1 + size1 > x2 - size2 &&  //���[�U�[�̉E�[�̔���
		y1 - 800 < y2 + size2 &&	//���[�U�[�̏�[�̔���
		y1 > y2 - size2)			//���[�U�[�̉��[�̔���
		{
		return 1;
	}
	else {
		return 0;
	}
}
