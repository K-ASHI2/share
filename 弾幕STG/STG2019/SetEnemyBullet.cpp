#include"DxLib.h"
#include"extern.h"
#include"function.h"

//�G�̑傫����^����ꂽ�G�̎�ނɉ����Đݒ肷��֐�
void SetEnemyBullet(int i, double x, double y, double vx, double vy, int bkind, double ang) {

	enemybullet[i].hp = 1;
	enemybullet[i].x = x;
	enemybullet[i].y = y;
	enemybullet[i].vx = vx;
	enemybullet[i].vy = vy;
	enemybullet[i].t = 0;
	enemybullet[i].graze = 1;
	enemybullet[i].bkind = bkind;
	enemybullet[i].ang = ang;
	efs(efs_bomb);
}
