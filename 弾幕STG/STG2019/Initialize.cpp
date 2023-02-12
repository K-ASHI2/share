#include"extern.h"
#include"function.h"

//�X�e�[�W�J�n���̏�����
void init(){

	init_p();
	init_e();
	init_i();
	init_b();
	init_key();
	chap = 0;	//�`���v�^�[�����̃X�e�[�W�̍ŏ��ɂ���
	stageTimeCount = 0;	//�X�e�[�W�J�n���̎��Ԃ�0�ɂ���
	LoadEmerge();	//���݂̃X�e�[�W�̓G�̏o���������[�h����
	StageMusic();	//�X�e�[�W�̉��y��炷
	boss_flag = eb_way;
	time = 0;
}

void init_b() {

	switch (stage) {
	case es_1_1: background.vy = 1.5; background.size_y = 4500; background.img = img.background_1; break;
	case es_1_2: background.vy = 1.1; background.size_y = 4500;	background.img = img.background_1; break;
	case es_2_1: background.vy = 1.5; background.size_y = 4500;	background.img = img.background_2; break;
	case es_2_2: background.vy = 1.1; background.size_y = 4500; background.img = img.background_2; break;
	case es_3_1: background.vy = 1.5; background.size_y = 4500; background.img = img.background_3; break;
	case es_3_2: background.vy = 1.1; background.size_y = 4500; background.img = img.background_3; break;
	case es_4_1: background.vy = 2.0; background.size_y = 1500; background.img = img.background_4; break;
	case es_4_2: background.vy = 1.1; background.size_y = 1500; background.img = img.background_4; break;
	case es_e_1: background.vy = 1.3; background.size_y = 1600; background.img = img.background_e; break;
	case es_e_2: background.vy = 1.1; background.size_y = 1600; background.img = img.background_e; break;
	}
	background.x = G_W_LEFT;
	background.y = background.size_y;
	//background.vy = 1.5;	//���x���㏑�����Ă��܂��Ă���̂ł���Ȃ��͂�
	//�g���ĂȂ��ϐ�
	background.size_x = G_W_RIGHT - G_W_LEFT;
}

//�L�[�{�[�h�ƃQ�[���p�b�h�̓��͂̏�����
void init_key() {

	for (int i = 0; i < 256; i++) {
		Key[i] = 0;
	}
	for (int i = 0; i < 28; i++) {
		Pad[i] = 0;
	}
}

//�Q�[���p�b�h�̃L�[�R���t�B�O�̏�����
//�Q�[�����[�v�J�n�O�ƃR���t�B�O�̃��Z�b�g�ŌĂяo��
void init_key_p() {

	key_p[KEY_DOWN] = PAD_DOWN;
	key_p[KEY_LEFT] = PAD_LEFT;
	key_p[KEY_RIGHT] = PAD_RIGHT;
	key_p[KEY_UP] = PAD_UP;
	key_p[KEY_SHOT] = PAD_X;
	key_p[KEY_BOMB] = PAD_A;
	key_p[KEY_SLOW] = PAD_LB;
	key_p[KEY_PAUSE] = PAD_START;
	
	cPad[KEY_DOWN] = "PAD_DOWN";
	cPad[KEY_LEFT] = "PAD_LEFT";
	cPad[KEY_RIGHT] = "PAD_RIGHT";
	cPad[KEY_UP] = "PAD_UP";
	cPad[KEY_SHOT] = "PAD_X";
	cPad[KEY_BOMB] = "PAD_A";
	cPad[KEY_SLOW] = "PAD_LB";
	cPad[KEY_PAUSE] = "PAD_START";
}
