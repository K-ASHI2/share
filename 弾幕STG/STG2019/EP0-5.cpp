#include"DxLib.h"
#include"extern.h"
#include"function.h"
#include"math.h"

void EnemyPattern0(int i) {

	if (enemy[i].t == 0) {
		enemy[i].vy = 2;
	}
	else if (enemy[i].t == 60) {
		enemy[i].vy = 0;
	}
	else if (enemy[i].t == 60 + enemy[i].wait) {
		double ang = atan2((double)((player.y + player.size / 2) - enemy[i].y), (double)((player.x + player.size / 2) - enemy[i].x));
		enemy[i].vx = cos(ang) * enemy[i].v;
		enemy[i].vy = sin(ang) * enemy[i].v;
	}
}

void EnemyPattern1(int i) {

	if (enemy[i].t == 0) {
		enemy[i].vy = 2;
	}
	else if (enemy[i].t == 60) {
		enemy[i].vy = 0;
	}
	else if (enemy[i].t >= 60 + enemy[i].wait) {
		enemy[i].vy = -2;
		enemy[i].ang += 0.03125;
		if (enemy[i].ang >= PI && enemy[i].ang < PI + 0.03125) {
			enemy[i].ang = PI;	//PI‚Ü‚Å‚ÌˆÚ“®‹——£‚ÆPI‚©‚ç2PI‚Ü‚Å‚ÌˆÚ“®‹——£‚ð“¯‚¶‚É‚·‚é
		}
		if (enemy[i].ang >= 2 * PI) {
			enemy[i].ang = 0;
		}
		enemy[i].vx = 3 * sin(enemy[i].ang);
	}
}

void EnemyPattern2(int i) {

	if (enemy[i].t == 0) {
		enemy[i].vy = 2;
	}
	else if (enemy[i].t == 60) {
		enemy[i].vy = 0;
	}
	else if (enemy[i].t == 60 + enemy[i].wait) {
		enemy[i].vy = -2;
	}
}

void EnemyPattern3(int i) {

	if (enemy[i].t == 0) {
		enemy[i].vy = 2;
	}
	else if (enemy[i].t == 60) {
		enemy[i].vy = 0;
	}
	else if (enemy[i].t == 60 + enemy[i].wait) {
		enemy[i].vy = -2;
	}
}

void EnemyPattern4(int i) {

	if (enemy[i].t == 0) {
		enemy[i].vy = 2;
	}
	else if (enemy[i].t == 60) {
		enemy[i].vy = 0;
	}
	else if (enemy[i].t == 60 + enemy[i].wait) {
		enemy[i].vy = -2;
	}
}
