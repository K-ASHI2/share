#pragma once

//�v���C���[�֘A�̍\����
struct S_player
{
	double x, y;		//��l����X,Y���W
	double by;		//1�t���[���O��y���W
	double vx, vy;	//��l����X,Y�������̑��x
	double vx2;		//��l���̉������̑��x
	int life;       //��l���̗̑�
	int maxlife;       //��l���̗̑͂̍ő�l
	int muteki;     //���G���ǂ����@�@�@�@�@�@�@0:�ʏ�/1:���G
	int jfly;		//���ł��邩�ǂ����̔��ʁ@0:���n/1:����ȊO
	int crouch;     //���Ⴊ��ł��邩�ǂ���
	int jp2;        //���̃t���[���ŃW�����v���Ă�����1�A���Ă��Ȃ����0
	int dire;		//��l���̌����Ă������	0:�E/1:��
	int dire_m;		//��l���������Ă��邩�ǂ��� 0:�~�܂��Ă��� 1:���ɓ����Ă��� 2:�E�ɓ����Ă���
	int attack;		//�U�������ǂ����̔���		0:�ʏ�/1:�U����
	int kabe_r;		//�E�����ɕǂ����邩�ǂ����̔���
	int kabe_l;		//�������ɕǂ����邩�ǂ����̔���
	int mv;         //�������ɏ���Ă��邩�ǂ���
	int size_x;     //��l���̕�
	int size_y;     //��l���̍���
	int footcount;	//��l���̑�
};
