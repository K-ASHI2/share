#include"DxLib.h"
#include"function.h"
#include"extern.h"

void judgeDoor() {
	//���̔���
	//����̔��肵���瑼�̔��͔��肵�Ȃ��̂�return����
	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			if (player.jfly == 0 && button[KEY_UP] == 1) {
				if ((enemy[i][j].x < player.x + HERO_SIZE_X / 2 && player.x + HERO_SIZE_X / 2 < enemy[i][j].x + enemy[i][j].size_x) &&
					(enemy[i][j].y < player.y + HERO_SIZE_Y && player.y < enemy[i][j].y + enemy[i][j].size_y)) {
					switch (enemy[i][j].species) {
					case 8:	door(i, j);	return;			//�Ή�������̈ʒu�Ɉړ�����
					case 9:	door(i, j);	return;			//�Ή�������̈ʒu�Ɉړ�����
					case 10:door2(++mapload); return;	//���̃G���A�ֈړ�����
					case 11:change_flag(e_clear);					//�N���A��ʂɂ���
					case 50:
						if (enemy[i][j].life == 0) {	//�{�X��hp��0�ɂȂ�����N���A�̔����o��
							change_flag(e_clear);
							return;
						}
						break;
					}
				}
			}
		}
	}
}

void door(int dx, int dy) {

	door_fade_x = dx;
	door_fade_y = dy;
	fade_flag = ef_fadeOut_door;
}

void door_fade(int dx, int dy) {

	for (int j = 0; j< height_size; j++) {
		for (int i = 0; i<width_size; i++) {
			if (enemy[dx][dy].species == 8) {
				if (enemy[i][j].species == 9) {
					player.x = enemy[i][j].x;
					player.y = enemy[i][j].y;
					player.vx2 = 0;
					return;
				}
			}
			if (enemy[dx][dy].species == 9) {
				if (enemy[i][j].species == 8) {
					player.x = enemy[i][j].x;
					player.y = enemy[i][j].y;
					player.vx2 = 0;
					return;
				}
			}
		}
	}
}

void door2(int x) {

	door_fade_x = x;
	fade_flag = ef_fadeOut_door2;
}

void door_fade2(int x) {

	if (mapload != 0) {
		mapload = x;
	}
	ReadMap();	//�}�b�v�̃����[�h
	init();			//�ϐ��̏�����
	black_screen(70);
}
