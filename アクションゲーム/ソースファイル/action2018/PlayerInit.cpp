#include"DxLib.h"
#include"function.h"
#include"extern.h"

void playerInit() {

	player.x = 32;		//�v���C���[�̏��������W
	player.y = 384;		//�v���C���[�̏��������W
	player.by = 0;
	player.vx = 0;
	player.vx2 = 0;
	player.vy = 0;
	player.size_x = 32;
	player.jfly = 1;
	//�C�[�W�[�̗͑�3�A����2
	if (mapload / 1000 == 0) {
		player.maxlife = 3;
	}
	else {
		player.maxlife = 2;
	}
	player.crouch = 0;	//���Ⴊ�݁A���g�p
	player.jp2 = 0;
	player.muteki = 0;
	player.dire = 0;
	player.attack = 0;
	player.kabe_r = 0;
	player.kabe_l = 0;
	player.mv = 0;
	player.dire_m = 0;		//�v���C���[�̌������E�����ɂ���
	player.footcount = 0;	//�v���C���[�̑��̓���
}