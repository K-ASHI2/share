#pragma once

//�G�֘A�̍\����
struct S_enemy
{
	double x, y;		//�G��X,Y���W
	double vx, vy;		//�G��X,Y�������̑��x
	double by;			//1�t���[���O��y���W
	double rad;			//�G�̊p�x
	double m_rad;		//�}�b�v����̊p�x�̑��x�ݒ�
	int life;			//�G�̗̑�
	int species;		//�G�̎��
	int appear;			//�G�̏o��
	int size_x, size_y;	//�G�̑傫��
	int countx, county;	//�G�̓����ۂ̃J�E���g
	int dire;			//�X�e�[�W�̃}�b�v����ǂݍ��񂾌���	
	int dire_x;			//�G�̌����Ă������	0:�E/1:��
	int dire_y;			//�G�̌����Ă������	0:��/1:��
	int hantei;			//���肪���邩�ǂ���
	int muteki;			//���G���ǂ����@�@�@�@0:�ʏ�/1:���G
	int jfly;			//�󒆂ɂ��邩�ǂ����̔��ʁ@0:���n/1:����ȊO
	int jfly2;			//1�t���[���O�ɋ󒆂ɂ������ǂ���
	int t;				//���̓G������Ă���̃t���[�������i�[���郁���o
	int jx;				//�����肷�邩�ǂ���
	int jy;				//�c���肷�邩�ǂ���
	int drop;			//�A�C�e���𗎂Ƃ��m��
	double sin_v;		//sin�g�̉��������鎞�̌��ƂȂ鑬�x
	int vanish;			//���ł̃G�t�F�N�g�̃t���O
	double vanish_x;		//���ł�������x���W
	double vanish_y;		//���ł�������y���W
	int v_flag;			//�{�X��hp�����������̉����̃t���O
	int m_count;		//�{�X�̓������~�܂��Ă��鎞�Ԃ̃J�E���g
};