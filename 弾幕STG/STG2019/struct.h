#include"define.h"
#include"structImage.h"
#include"structMusic.h"
#include"enum.h"

//�v���C���[�֘A�̍\����
struct _player{
	double x,y;
	double vx,vy;
	int life;	//�c�@�̐� LIFE�ɕ\�������c�@����life-1
	int bomb;	//�{���̏�����
	int muteki;	//���G���Ԃ̃J�E���g
	int inope;	//����s�\���ǂ��� 0: ����\ 1: ����s�\ 2:��炢�{���̂ݎ󂯕t����
	int bomb_c;	//�{�����Ԃ̃J�E���g��0���傫���Ȃ�{�����Ԓ�
	int bomb_t;	//���@���Ƃɍŏ����猈�܂��Ă���{���̎���
	int damaged;//��e�����㓮����悤�ɂȂ�܂ł̎���
	int d_effect;	//��e��̃G�t�F�N�g�̃t���[���J�E���g
	double damaged_x;	//��e����x���W
	double damaged_y;	//��e����y���W
	double power;
	double size;	//���ۂ̔���̔��a
	double grazeSize;	//���@�̔���̊O���̃O���C�Y����̃T�C�Y
	int graze;	//�O���C�Y��
	int t;		//�v���C���[����e���o���Ԋu�̃J�E���g
	int slow_move;	//�ᑬ�ړ��Ȃ�1,�����Ȃ�0
	int bomb_x;	//�{�����������u�Ԃ�x���W
	int bomb_y;	//�{�����������u�Ԃ�y���W
	int snowGauge;		//��̃Q�[�W
	int thunderGauge;	//�d�C�̃Q�[�W
	int fireGauge;		//���̃Q�[�W
	bool snowMode;
	bool thunderMode;
	bool fireMode;
	int maxscore;
	long long score;	//���_(�ő�10���Ȃ̂�int�^�ł͑���Ȃ�)
	enum e_character {
		D_Magician_A, D_Magician_B, L_Magician_A, L_Magician_B,
	};
	enum e_character character;
};

//�G�֘A�̍\����
struct _enemy{
	double x,y;    
	double vx,vy;
	double v;		//�ړ����x
	double ang;
	double hp;			//���݂�hp
	double size;
	int kind;		//�G�̎��(�O��)
	int pattern;	//�s���p�^�[��
	int t;			//�G�̏o������̎���
	int wait;		//�G�̏o������̑ҋ@����
	int bt;		//�G�̒e�̔��˂��Ă��鎞��
	int bkind;	//�e���̎��
	int color;	//�e�̐F
	int item;	//���Ƃ��A�C�e���̎��
	int vanish;	//���ŃG�t�F�N�g�̃J�E���g
	int vanish_kind;	//���ŃG�t�F�N�g�̎��
};

//�G�̏o�����̍\����
struct _enemyemerge {
	int frame;	//�o���t���[��
	int pattern;//�G�̍s���p�^�\��
	int kind;	//�G�̎��
	double x, y;//�G�̏������W
	double v;	//�G�̑��x(x,y�̓p�^�[���Ō��܂��Ă���)
	double hp;		//�G��hp
	int wait;	//�G�̒e���˂܂ł̑ҋ@����
	int bt;		//�G�̒e�̔��˂��Ă��鎞��
	int bkind;	//�e���̎��
	int color;	//�e�̐F
	int item;	//���Ƃ��A�C�e���̎��
};

//�{�X�̍\����
struct _boss {
	double x, y;
	//double vx, vy;
	double hp;			//���݂�hp
	double maxhp;		//���ꂼ��̍U����hp�̍ő�l
	double totalhp;	//�{�X��hp�̍��v�̌��݂�hp
	double maxtotalhp;	//�{�X�̍U����hp�̍ő�l�̍��v
	int time;
	int maxtime;
	int t;
	double size;
	int kind;	//�G�̎��
	int mode;	//�{�X�̌`��
	int mode_p;	//�{�X�̃X�y���v���N�e�B�X�ł̌`�Ԏw��
	int modechange;	//�{�X�̌`�ԕω��̃t���O
	int appear;	//�{�X�̏o�����̃t���[��
	int muteki;	//�{�X�̖��G����
	int vanish;	//���ŃG�t�F�N�g�̃J�E���g
};

//�e�֘A�̍\����
struct _bullet{
	double atk;
	double x, y;
	double vx, vy;
	int hp;		//hp��0�̒e�͑��݂��Ȃ��e�A1�̒e�͑��݂���e�A-1�̒e�͂��̃t���[���ɏ����邱�Ƃ��m�肵�Ă���e
	double size;
	int graze;	//�O���C�Y�����Ă��Ȃ��e�Ȃ�1�A�O���C�Y�����e�Ȃ�0
	enum eb_kind kind;	//�G�̒e�̊O��
	int bkind;	//�e�̓����̎��
	enum eb_color color;//�G�̒e�̐F
	int move;	//�����̎��
	int vanish;	//���ŃG�t�F�N�g�̃J�E���g
	int pbkind;	//���@�̒e�̎��
	int img;	//���@�̒e�̉摜
	int t;	//�e�̏o������̎��Ԃ̃J�E���g
	int mutate;	//�e���ǂɓ������ĕω�������(�ς��Ȃ��Ȃ�0)
	double ang;	//��]�p(�`��ɗp����)
};

//�A�C�e���֘A�̍\����
struct _item{
	double x, y;
	double vx, vy;
	int hp;
	double size;
	int kind;	//�A�C�e���̎��
	int collect;	//�㕔������̎��@�Ɍ������Ĉ����񂹂�t���O
};

//�w�i�̍\����
struct _background{
	double x,y;
	double vy;
	double size_x;
	double size_y;
	int img;	//���ݕ`�悷�ׂ��w�i
};
