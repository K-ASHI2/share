#include"DxLib.h"
#include"extern.h"
#include"function.h"
#include"math.h"

//�G�̈ړ�
void MoveEnemy() {

	for (int i = 0; i<ENEMY; i++) {
		if (enemy[i].hp != 0) {
			EnemyPattern(i);	//�G�̍s���p�^�[�����Ƃ̈ړ�
			//enemy[i].x += cos(enemy[i].ang) * enemy[i].v;
			//enemy[i].y += sin(enemy[i].ang) * enemy[i].v;
			enemy[i].x += enemy[i].vx;
			enemy[i].y += enemy[i].vy;
			enemy[i].t++;
			//��ʊO��菭���O�ɏo���G�͏��ł���
			if (enemy[i].x < G_W_LEFT - 50 || enemy[i].x > G_W_RIGHT + 50
				|| enemy[i].y < G_W_UPPER - 50 || enemy[i].y > G_W_LOWER + 20) {
				enemy[i].hp = 0;
			}
		}
	}
}

void EnemyPattern(int i) {

	switch (enemy[i].pattern) {
	case 0: EnemyPattern0(i); break;
	case 1: EnemyPattern1(i); break;
	case 2: EnemyPattern2(i); break;
	case 3: EnemyPattern3(i); break;
	case 4: EnemyPattern4(i); break;
	}
}
