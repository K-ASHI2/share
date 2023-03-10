#include"DxLib.h"
#include"extern.h"
#include"function.h"
#include"math.h"

//自機依存nway弾を作る関数 k:弾の種類 x:x座標 y:y座標 n:way数 a:角度 v:速度 m:弾の変化 bkind:弾の種類
void Burrage_NWay(enum eb_kind k, double x, double y, int n, double a, double v, int m, int bkind) {

	double ang = atan2((double)((player.y + player.size / 2) - y), (double)(player.x + player.size / 2) - x);
	for (int j = 0; j < n; j++) {
		int i = getEnemyBulletNumber();
		SetEBKind(k, i);
		enemybullet[i].mutate = m;
		//角度がマイナスなら全方位弾をnwayで作る
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

//自機依存しないnway弾を作る関数 k:弾の種類 x:x座標 y:y座標 n:way数 a:角度 v:速度 m:弾の変化 bkind:弾の種類
void Burrage_NWay2(enum eb_kind k, double x, double y, int n, double a, double v, int m, int bkind) {

	double ang = 2.0 * PI * (double)GetRand(360) / 360.0;
	for (int j = 0; j < n; j++) {
		int i = getEnemyBulletNumber();
		SetEBKind(k, i);
		enemybullet[i].mutate = m;
		//角度がマイナスなら全方位弾をnwayで作る
		if (a < 0) {
			double ang2 = ang - 2 * PI / n * j;
			SetEnemyBullet(i, x, y, cos(ang2) * v, sin(ang2) * v, bkind, ang2);
		}
		else {
			double ang2 = ang - a * (n - 1) / 2 + a * j;
			SetEnemyBullet(i, x, y, cos(ang2) * v, sin(ang2) * v, bkind, ang2);
		}
		//スペル6のみ炎弾の向きをまっすぐに戻す
		if (bkind == 1 || bkind == 2) {
			enemybullet[i].ang = PI / 2;
		}
	}
}

//真下に落ちるnway弾を作る関数 k:弾の種類 x:x座標 y:y座標 n:way数 a:角度 v:速度 m:弾の変化 bkind:弾の種類
void Burrage_Fall(enum eb_kind k, double x, double y, int n, double a, double v, int m, int bkind) {

	double ang = PI / 2;
	for (int j = 0; j < n; j++) {
		int i = getEnemyBulletNumber();
		SetEBKind(k, i);
		enemybullet[i].mutate = m;
		//角度がマイナスならなら全方位弾をnwayで作る
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
