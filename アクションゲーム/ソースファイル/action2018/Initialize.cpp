#include"DxLib.h"
#include"function.h"
#include"extern.h"

//�ϐ��̏�����
void init(){

	init_key();	//�L�[�{�[�h�ƃQ�[���p�b�h�̓��͂̏�����
	playerInit();
	enemyInit();
	deg = 0;	//��]���镨�̊p�x�̏�����
	//�t�@�C�A�o�[�Ɖ�]����G�͏����ʒu���w�肳��Ă��Ȃ��̂ň�xmove�ňʒu������������
	moveFirebar(); 
	sw = 0;	//�X�C�b�`���I�t�ɂ���
	boss = 0;
	init_b();	//�w�i�̏�����
	countTime = 0;	//�X�e�[�W�J�n����̌o�ߎ���
	scroll_leftx = 0;
	gameover_count = -1;
	enemymove();	//��]����G�����ʒu���C������(�o�O�N���肻��������悭�Ȃ�?)
}

//��l����hp�̏�����
void init_l(){
	player.life = player.maxlife;
}

//�G�̍��W�ƃ��C�t�Ǝ�ނƓG�̏o���̏�����
void init_e(int i, int j, int l, int s, int a) {
	//�f�t�H���g���� l = 0 s = -1 a = 1
	enemy[i][j].x = i * BLOCK;
	enemy[i][j].y = j * BLOCK;
	enemy[i][j].life = l;
	enemy[i][j].species = s;
	enemy[i][j].appear = a;
}

//�w�i�̈ʒu�Ƒ��x�̏�����
void init_b() {
	background2.x = 0;
	background2.y = 0;
	background2.vy = 10;
}

//�c������𖳂���
void init_j(int i, int j) {
	enemy[i][j].jx = 0;
	enemy[i][j].jy = 0;
}

void init_t(int i, int j, int l, int s) {
	init_e(i, j, l, s);
	kabe[i][j] = 1;
	enemy[i][j].hantei = 0;
	enemy[i][j].muteki = 1;
	enemy[i][j].jx = 0;
	enemy[i][j].jy = 0;
	enemy[i][j].t = 60 + GetRand(90);
}
