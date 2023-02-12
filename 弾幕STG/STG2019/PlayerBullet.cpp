#include"DxLib.h"
#include"extern.h"
#include"function.h"

void MovePlayerBullet() {

	for (int i = 0; i<BULLET; i++) {
		//�~�T�C��
		if (playerbullet[i].pbkind == 1 && playerbullet[i].t < 70) {
			if (playerbullet[i].t < 10) {
				playerbullet[i].y += playerbullet[i].vy * 0.1;
				playerbullet[i].x += playerbullet[i].vx * 0.1;
			}
			else {
				playerbullet[i].y += playerbullet[i].vy * (0.1 + (double)playerbullet[i].t / 60.0);
				playerbullet[i].x += playerbullet[i].vx * (0.1 + (double)playerbullet[i].t / 60.0);
			}
		}
		else if (playerbullet[i].hp != 0) {
			playerbullet[i].y += playerbullet[i].vy;
			playerbullet[i].x += playerbullet[i].vx;
		}
		//��ʊO�ɏo���e������
		if (playerbullet[i].x - playerbullet[i].size > G_W_RIGHT ||
			playerbullet[i].x + playerbullet[i].size < G_W_LEFT ||
			playerbullet[i].y - playerbullet[i].size > G_W_LOWER ||
			playerbullet[i].y + playerbullet[i].size < G_W_UPPER)
		{
			playerbullet[i].hp = 0;
		}
		//�e�̏o������̃J�E���g�̑���
		playerbullet[i].t++;
	}
}
