#include"define.h"
#include"structPlayer.h"
#include"structEnemy.h"
#include"structImg.h"
#include"structMusic.h"
#include"enum.h"

//�e��struct
struct S_bullet {
	double x, y;
	double vx, vy;
	double v;//�i�s�����ɐi�ޑ��x
	int life;    //life��0�Ȃ��ʏ�ɑ��݂��Ă��Ȃ��A1�Ȃ瑶�݂��Ă���
	int atk;     //�e�̍U����
	int size_x;
	int size_y;
	int species; //�e�̎��
	int rad_i;	 //�e�̏����̌X��
	int rad_b;	 //�e�̉�]�p
	int rad_v;	 //�e�̊p���x
};

//�ǂݍ��܂�w�i�̃f�[�^(�z��ɓ����)
struct S_background {
	int size_x;
	int size_y;
	int img;
};

//�w�i�̃X�e�[�^�X(���݂̈ʒu�⑬�x�̂ݎ���)
struct S_background2 {
	int x, y;
	int vy;
};
