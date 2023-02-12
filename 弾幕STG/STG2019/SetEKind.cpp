#include"DxLib.h"
#include"extern.h"
#include"function.h"

//�G�̑傫����^����ꂽ�G�̎�ނɉ����Đݒ肷��֐�
void SetEKind(int i, int j) {

	//�G�̎�ނ��Ƃɑ傫�������肷��
	switch (enemyemerge[i].kind) {
	case 0:	enemy[j].size = 16; break;
	case 1:	enemy[j].size = 10; break;
	case 2:	enemy[j].size = 10; break;
	case 3:	enemy[j].size = 10; break;
	case 4:	enemy[j].size = 20; break;
	case 5:	enemy[j].size = 20; break;
	case 6:	enemy[j].size = 20; break;
	case 7:	enemy[j].size = 20; break;
	}
}

//�e�̊O���Ƒ傫���ƐF��^����ꂽ�����ɉ����Đݒ肷��֐�
void SetEBKind(enum eb_kind k, int i) {

	enemybullet[i].kind = k;
	switch (k) {
	case ebk_blue_S: enemybullet[i].size = 5; enemybullet[i].color = ebc_blue; break;
	case ebk_red_S: enemybullet[i].size = 5; enemybullet[i].color = ebc_red; break;
	case ebk_yellow_S: enemybullet[i].size = 5; enemybullet[i].color = ebc_yellow; break;
	case ebk_blue_M: enemybullet[i].size = 7.5; enemybullet[i].color = ebc_blue; break;
	case ebk_red_M: enemybullet[i].size = 7.5; enemybullet[i].color = ebc_red; break;
	case ebk_yellow_M: enemybullet[i].size = 7.5; enemybullet[i].color = ebc_yellow; break;
	case ebk_blue_L: enemybullet[i].size = 15; enemybullet[i].color = ebc_blue; break;
	case ebk_red_L: enemybullet[i].size = 15; enemybullet[i].color = ebc_red; break;
	case ebk_yellow_L: enemybullet[i].size = 15; enemybullet[i].color = ebc_yellow; break;
	case ebk_snow_S: enemybullet[i].size = 6; enemybullet[i].color = ebc_blue; break;
	case ebk_snow_M: enemybullet[i].size = 12; enemybullet[i].color = ebc_blue; break;
	case ebk_fire_S: enemybullet[i].size = 7; enemybullet[i].color = ebc_red; break;
	case ebk_fire_M: enemybullet[i].size = 5; enemybullet[i].color = ebc_red; break;
	case ebk_thunder: enemybullet[i].size = 9; enemybullet[i].color = ebc_yellow; break;
	case ebk_star: enemybullet[i].size = 5; enemybullet[i].color = ebc_yellow; break;
	case ebk_star_red: enemybullet[i].size = 5; enemybullet[i].color = ebc_red; break;
	case ebk_star_blue: enemybullet[i].size = 5; enemybullet[i].color = ebc_blue; break;
	}
}
