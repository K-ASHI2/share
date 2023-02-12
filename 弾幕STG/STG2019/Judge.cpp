#include"DxLib.h"
#include"extern.h"
#include"function.h"

//2つの円判定の物が重なっているか判定する
//重なってたら1、重なって無ければ0を返す
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

//レーザーの判定
int judge_laser(double x1, double y1, int size1, double x2, double y2, double size2) {
	
	if (x1 - size1 < x2 + size2 &&	//レーザーの左端の判定
		x1 + size1 > x2 - size2 &&  //レーザーの右端の判定
		y1 - 800 < y2 + size2 &&	//レーザーの上端の判定
		y1 > y2 - size2)			//レーザーの下端の判定
		{
		return 1;
	}
	else {
		return 0;
	}
}
