#include"DxLib.h"
#include"extern.h"
#include"function.h"

//mapload�ϐ�����ǂݍ��ރe�L�X�g�t�@�C�����𐶐����Ԃ��֐�
//�t�@�C�����̗� mapload = 111�̎� : "map_e/1-1.txt"
char *mapToChar() {
	static char *r;	//���ۂɓǂݍ��ރt�@�C�����̐擪�̃|�C���^��ێ�����ϐ�
	char *c;		//�t�@�C����������Ă����|�C���^
	char d[2];		//itoa�֐����g���Ƃ��̒l��ێ�����֐�(�I�[�������܂߂Ĕz��̑傫����2�ɂ���)

	c = (char *)malloc(20);
	r = c;

	//easy���m�[�}���̃}�b�v���g��
	switch (mapload / 1000) {
	case 0: strcpy(c, "map_e/"); break;
	case 1: strcpy(c, "map_n/"); break;
	case 2: strcpy(c, "map_h/"); break;
	case 3: strcpy(c, "map_l/"); break;
	}

	//100�̈ʂ�char�^�ɕϊ����A���ɒǉ�
	itoa(mapload % 1000 / 100, d, 10);
	strcat(c, d);
	//-���Ԃɓ����
	strcat(c, "-");
	//10�̈ʂ�char�^�ɕϊ����A���ɒǉ�
	itoa(mapload % 100 / 10, d, 10);
	strcat(c, d);
	//-���Ԃɓ����
	strcat(c, "-");
	//1�̈ʂ�char�^�ɕϊ����A���ɒǉ�
	itoa(mapload % 10, d, 10);
	strcat(c, d);
	//.txt�����ɒǉ�����
	strcat(c, ".txt");
	return r;
}
