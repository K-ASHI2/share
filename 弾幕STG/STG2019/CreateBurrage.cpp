#include"DxLib.h"
#include"extern.h"
#include"function.h"
#include"math.h"

//���@�ˑ�nway�e�����֐� k:�e�̎�� x:x���W y:y���W n:way�� a:�p�x v:���x m:�e�̕ω� bkind:�e�̎��
void Burrage_NWay(enum eb_kind k, double x, double y, int n, double a, double v, int m, int bkind) {

	double ang = atan2((double)((player.y + player.size / 2) - y), (double)(player.x + player.size / 2) - x);
	for (int j = 0; j < n; j++) {
		int i = getEnemyBulletNumber();
		SetEBKind(k, i);
		enemybullet[i].mutate = m;
		//�p�x���}�C�i�X�Ȃ�S���ʒe��nway�ō��
		if (a < 0) {
			double ang2 = ang - 2 * PI / n * j;
			SetEnemyBullet(i, x, y, cos(ang2) * v, sin(ang2) * v, bkind, ang2);
		}
		else {
			double ang2 = ang - a * (n - 1) / 2 + a * j;
			SetEnemyBullet(i, x, y, cos(ang2) * v, sin(ang2) * v, bkind, ang2);
		}
	}
}

//���@�ˑ����Ȃ�nway�e�����֐� k:�e�̎�� x:x���W y:y���W n:way�� a:�p�x v:���x m:�e�̕ω� bkind:�e�̎��
void Burrage_NWay2(enum eb_kind k, double x, double y, int n, double a, double v, int m, int bkind) {

	double ang = 2.0 * PI * (double)GetRand(360) / 360.0;
	for (int j = 0; j < n; j++) {
		int i = getEnemyBulletNumber();
		SetEBKind(k, i);
		enemybullet[i].mutate = m;
		//�p�x���}�C�i�X�Ȃ�S���ʒe��nway�ō��
		if (a < 0) {
			double ang2 = ang - 2 * PI / n * j;
			SetEnemyBullet(i, x, y, cos(ang2) * v, sin(ang2) * v, bkind, ang2);
		}
		else {
			double ang2 = ang - a * (n - 1) / 2 + a * j;
			SetEnemyBullet(i, x, y, cos(ang2) * v, sin(ang2) * v, bkind, ang2);
		}
		//�X�y��6�̂݉��e�̌������܂������ɖ߂�
		if (bkind == 1 || bkind == 2) {
			enemybullet[i].ang = PI / 2;
		}
	}
}

//�^���ɗ�����nway�e�����֐� k:�e�̎�� x:x���W y:y���W n:way�� a:�p�x v:���x m:�e�̕ω� bkind:�e�̎��
void Burrage_Fall(enum eb_kind k, double x, double y, int n, double a, double v, int m, int bkind) {

	double ang = PI / 2;
	for (int j = 0; j < n; j++) {
		int i = getEnemyBulletNumber();
		SetEBKind(k, i);
		enemybullet[i].mutate = m;
		//�p�x���}�C�i�X�Ȃ�Ȃ�S���ʒe��nway�ō��
		if (a < 0) {
			double ang2 = ang - 2 * PI / n * j;
			SetEnemyBullet(i, x, y, cos(ang2 - 2 * PI / n * j) * v, sin(ang2) * v, bkind, ang2);
		}
		else {
			double ang2 = ang - a * (n - 1) / 2 + a * j;
			SetEnemyBullet(i, x, y, cos(ang2) * v, sin(ang2) * v, bkind, ang2);
		}
	}
}
