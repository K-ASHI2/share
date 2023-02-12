#pragma once
#include"struct.h"

extern S_img img;
extern S_anime ani;	//�A�j���[�V������ۑ�����
extern S_music music;
extern S_player player;
extern S_enemy enemy[MAX_WIDTH][MAX_HEIGHT];
extern S_bullet enemybullet[MAX_WIDTH][MAX_HEIGHT][BULLET];  //�e��struct��G�̒e�p��
extern S_background background[BACKGROUND_MAX];
extern S_background2 background2;

extern int map[MAX_WIDTH][MAX_HEIGHT];	//��2�� ��� 1000�̈ʂ�100�̈� ����(x.y) 10000�̈� ����(1:�� 2:�E)
extern int s_music[MUSIC_MAX];	//�X�e�[�W�̉��y
extern int backup[BACK_MAX][MAX_WIDTH][MAX_HEIGHT];	//�ŋ�100�񕪂̍�Ƃ�ۑ�����
extern int backup_w[BACK_MAX];	//backup��map�̕�
extern int back_c;	//backup�̌��݂̍�ƈʒu
extern int mapload;
extern double deg;	//�p���x
extern int kabe[MAX_WIDTH][MAX_HEIGHT];
extern char keyState[256];
extern int FontHandle;
extern e_background back_g;
extern e_fade fade_flag;	//�t�F�[�h�A�E�g���Ă��邩�ǂ����̃t���O
extern int sw;
extern int boss; 
extern int countTime;	//�X�e�[�W�J�n����̎��Ԃ̃J�E���g
extern int bright;	//�P�x
extern int sound;
extern int width_size;
extern int height_size;
extern int scroll_v;	//�X�N���[���̑��x 0�Ȃ�
extern int scroll_leftx;	//�X�N���[���̍��[
extern int music_n;	//���y�̔ԍ�
extern int background_n;	//�w�i�̔ԍ�
extern int test;
extern int Font[10];
extern int p_music;	//���݂̉��t���Ă����
extern int gameover_count;	//�Q�[���I�[�o�[�ɂȂ��Ă���̃G�t�F�N�g�̃J�E���g

//�F�̕ϐ�
extern int black;
extern int green;
extern int red;
extern int litegreen;

//���j���[��ʂ�L�[����̕ϐ�
extern e_flag flag;			//���݂̃t���O
extern e_flag cancel_flag;		//�L�����Z���Ŗ߂鎞�̃t���O
extern e_mode mode_flag;	//�Q�[�����[�h�̃t���O
extern char *cPad[9];	//�Q�[���p�b�h�̑��삷��{�^���̕�����ő�������ɗp����
extern int cursor;		//�c�J�[�\�����ǂ̈ʒu�ɂ��邩
extern int cursor_LR;	//���J�[�\�����ǂ̈ʒu�ɂ��邩
extern int N_o_i;		//���݂̑I����ʂ̍��ڐ�
extern int N_o_i_LR;	//���݂̑I����ʂ̍��ڐ�
extern int button[9];	//�ݒ肳�ꂽ�{�^���̓��̓t���[���J�E���g e_key�Őݒ肳�ꂽenum�̒l��Y�����ɂ���
extern int key_p[9];	//�L�[�R���t�B�O�Őݒ肳�ꂽ�Q�[���p�b�h�̃{�^����z��ɃQ�[���p�b�h�̓Y�����ŕۑ����� e_key�Őݒ肳�ꂽenum�̒l��Y�����ɂ���
extern int Key[256];	//�L�[���͂̓��̓t���[���J�E���g
extern int Pad[28];		//�Q�[���p�b�h�̓��̓t���[���J�E���g

// change_flag�͂����Ɏ��s����Ȃ��̂ň�����ۑ�����
extern enum e_flag changeFlag_flag;
extern int changeFlag_cursor;
extern int changeFlag_cursor2;

//�h�A�̈ړ��͂����Ɏ��s����Ȃ��̂ňړ���̍��W��ۑ�����
extern int door_fade_x;
extern int door_fade_y;



