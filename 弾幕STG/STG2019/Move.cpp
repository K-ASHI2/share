#include"DxLib.h"
#include"extern.h"
#include"function.h"
#include"math.h"

void MovePlayer() {

	//��炢�{��
	if (player.inope == 2) {
		if (button[KEY_BOMB] == 1 && player.bomb_c == 0 && player.bomb > 0) {
			player.bomb--;
			player.bomb_c = player.bomb_t;
			player.muteki = player.bomb_t + 60;
			player.bomb_x = player.x;
			player.bomb_y = player.y;
			player.inope = 0;	//����\�ɂ���
			player.damaged = 0;	//��e��Ԃ��猳�ɖ߂�
		}
	}

	//��e�Ȃǈړ��s�\���Ԃ͓����Ȃ��悤�ɂ���
	if (player.inope != 0) {
		return;
	}

	int k = 0;	//2�����ȏ㉟����Ă����烋�[�g2�̑��x�œ���
	double pv;	//�v���C���[�̑��x(�����ƒᑬ�ƃL�����ŕϓ�����)

	if (button[KEY_BOMB] == 1 && player.bomb_c == 0 && player.bomb > 0) {	//�{��
		player.bomb--;	//�{���̏���
		player.bomb_c = player.bomb_t;	//�{���̕`��E���莞��
		player.muteki = player.bomb_t + 60;	//�{���̖��G����
		player.bomb_x = player.x;
		player.bomb_y = player.y;
	}
	if (button[KEY_SLOW] > 0) {	//�ᑬ�ړ���
		pv = PLV;
		player.slow_move = 1;
	}
	else {	//�����ړ�
		if (player.character == player.L_Magician_A || player.character == player.L_Magician_B) {
			pv = PHHV;
		}
		else {
			pv = PHLV;
		}
		player.slow_move = 0;
	}
	if (player.character == player.L_Magician_A && player.bomb_c > 0) {
		pv /= 5.0;
	}
	if (button[KEY_RIGHT] > 0) {
		player.vx = pv;
		k++;
	}
	if (button[KEY_LEFT] > 0) {
		player.vx -= pv;
		k++;
	}
	if (button[KEY_DOWN] > 0) {
		player.vy = pv;
		k++;
	}
	if (button[KEY_UP] > 0) {
		player.vy -= pv;
		k++;
	}

	//2�̃{�^���������ɉ�����Ă��鎞�������[�g2����1�̑��x�ɂ���
	if (k == 2) {
		player.vx *= (root2 * 0.5);
		player.vy *= (root2 * 0.5);
	}

	//���x�̉��Z
	player.x += player.vx;
	player.y += player.vy;

	//�����x��0�ɖ߂�
	player.vx = 0;
	player.vy = 0;

	//��ʊO�ɏo�Ȃ��悤�ɂ���
	if(player.x < G_W_LEFT + PLAYER_SIZE * 2)
		player.x = G_W_LEFT + PLAYER_SIZE * 2;
	if(player.x  > G_W_RIGHT - PLAYER_SIZE * 2)
		player.x = G_W_RIGHT - PLAYER_SIZE * 2;
	if(player.y < G_W_UPPER + PLAYER_SIZE * 2)
		player.y = G_W_UPPER + PLAYER_SIZE * 2;
	if(player.y > G_W_LOWER - PLAYER_SIZE)
		player.y = G_W_LOWER - PLAYER_SIZE;
}

//�A�C�e���̈ړ�
void MoveItem(){

	//�㕔���
	//�㕔����̃��C������ɂ���Ȃ�A�C�e����������[�h�ɂ���
	if (player.y < ITEM_GET_BORDER) {
		for (int i = 0; i < ITEM; i++) {
			if (item[i].hp != 0) {
				item[i].collect = 1;
			}
		}
	}
	for(int i = 0;i < ITEM;i++){
		if(item[i].hp){
			//�㕔������̃A�C�e���͎��@�Ɍ������Ĉړ�����
			if (item[i].collect == 1) {
				double ang = atan2((double)((player.y + player.size / 2) - item[i].y), (double)((player.x + player.size / 2) - item[i].x));
				item[i].vx = cos(ang) * 7;
				item[i].vy = sin(ang) * 7;
			}
			//�ᑬ�ړ����͂������������
			else if (item[i].collect == 2) {
				double ang = atan2((double)((player.y + player.size / 2) - item[i].y), (double)((player.x + player.size / 2) - item[i].x));
				item[i].vx = cos(ang) * 4;
				item[i].vy = sin(ang) * 4;
			}
			else {
				item[i].vy += 0.3;
				if (item[i].vy > 2) {
					item[i].vy = 2;
				}
			}
			item[i].x += item[i].vx;
			item[i].y += item[i].vy;
			if(item[i].y >600){
				item[i].hp = 0;
			}
		}
	}
}
