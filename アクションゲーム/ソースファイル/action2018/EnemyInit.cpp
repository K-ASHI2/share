#include"DxLib.h"
#include"function.h"
#include"extern.h"

void enemyInit() {
	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			kabe[i][j] = 0;
		}
	}
	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			for (int k = 0; k < BULLET; k++) {
				enemybullet[i][j][k].vx = 0;
				enemybullet[i][j][k].vy = 0;
				enemybullet[i][j][k].life = 0;
				enemybullet[i][j][k].atk = 1;
				enemybullet[i][j][k].size_x = 16;
				enemybullet[i][j][k].size_y = 16;
				enemybullet[i][j][k].rad_b = 0;
				enemybullet[i][j][k].rad_v = 0;
				enemybullet[i][j][k].v = 0;
				enemybullet[i][j][k].rad_i = 0;
			}
			enemy[i][j].jx = 1;       //�G�̕ǂɑ΂��鉡�����t����
			enemy[i][j].jy = 1;       //�G�̕ǂɑ΂���c�����t����
			enemy[i][j].rad = 0;      //�G�̉�]�p�̏�����
			enemy[i][j].m_rad = 0;
			enemy[i][j].drop = 0;     //�G�̃A�C�e���h���b�v���̏�����
			enemy[i][j].life = 0;
			enemy[i][j].hantei = 1;   //�G�̃v���C���[�ɑ΂��锻���t����
			enemy[i][j].muteki = 0;
			enemy[i][j].jfly = 0;
			enemy[i][j].jfly2 = 1;    //�J�n��1�t���[���O�͋󒆂ɂ������Ƃɂ���
			enemy[i][j].size_x = 32;  //�錾���Ȃ���ΓG�̉���32
			enemy[i][j].size_y = 32;  //�錾���Ȃ���ΓG�̏c��32
			enemy[i][j].t = 0;
			enemy[i][j].dire = 0;
			enemy[i][j].dire_x = 0;
			enemy[i][j].vx = 0;
			enemy[i][j].vy = 0;
			enemy[i][j].by = 0;
			enemy[i][j].countx = 0;
			enemy[i][j].county = 0;
			enemy[i][j].sin_v = 0;
			enemy[i][j].vanish = 0;
			enemy[i][j].vanish_x = 0;
			enemy[i][j].vanish_y = 0;
			enemy[i][j].v_flag = 0;
			enemy[i][j].m_count = 0;
			init_e(i, j, 0, 0, 0);//�G�ȊO�̕��̏�����
			init_map(i, j);

			if (map[i][j] >= 100) {	//vx��vy�ȊO�̐��l�𑬓x����p����ꍇ�Ɏg��
				if (enemy[i][j].vx != 0)	//0�Ȃ瑬�x�����݂��Ȃ��G
					enemy[i][j].vx = (map[i][j] % 10000) / 1000;
				if (enemy[i][j].vy != 0)
					enemy[i][j].vy = (map[i][j] % 10000) / 1000;
				enemy[i][j].m_rad = (map[i][j] % 10000) / 1000;
			}
			if (map[i][j] % 100000 / 10000 == 1) {
				enemy[i][j].vx *= -1;
				enemy[i][j].vy *= -1;
				enemy[i][j].dire = 1;//������ς���
			}
			//sin�g�̉���������Ƃ��̌��̑��x���}�b�v����ǂݍ��ނƂ���
			//�}�b�v����ǂݍ��ޑ�����0.5�{�����̑��x�Ƃ���Ƒ��x���ړ������ƂȂ�
			enemy[i][j].sin_v = (map[i][j] % 10000) / 1000 * 0.5;
			if (map[i][j] % 100000 / 10000 == 1)
				enemy[i][j].sin_v *= -1;
		}
	}
}
