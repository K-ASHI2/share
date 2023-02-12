#pragma once
#include"struct.h"

//�\���̂̐錾
struct S_img img;
struct S_anime ani;
struct S_music music;
struct S_player player;
struct S_enemy enemy[MAX_WIDTH][MAX_HEIGHT];
struct S_bullet enemybullet[MAX_WIDTH][MAX_HEIGHT][BULLET];  //�e��struct��G�̒e�p��
struct S_background background[BACKGROUND_MAX];
struct S_background2 background2;

int map[MAX_WIDTH][MAX_HEIGHT];
int s_music[MUSIC_MAX];	//�X�e�[�W�̉��y
int mapload;
double deg = 0;		//�p���x
int kabe[MAX_WIDTH][MAX_HEIGHT]; //1�Ȃ��
char keyState[256];
int FontHandle;
enum e_background back_g;
enum e_fade fade_flag;	//�t�F�[�h�A�E�g���Ă��邩�ǂ����̃t���O
int sw;			//�X�C�b�`�̃I���I�t
int boss;		//�{�X��|����1
int countTime;	//�X�e�[�W�J�n����̎��Ԃ̃J�E���g
int bright = 255;	//��ʂ̋P�x
int sound;		//0�Ȃ特����Ȃ��@1�Ȃ��
int width_size = WIDTH_SIZE;	//�X�e�[�W�ɂ���ăX�e�[�W�̃T�C�Y��ς���
int height_size = HEIGHT_SIZE;
int scroll_v;	//�X�N���[���̑��x 0�Ȃ�X�N���[�����Ȃ�
int scroll_leftx;	//�X�N���[���̍��[
int music_n;		//���y�̔ԍ�
int background_n;	//�w�i�̔ԍ�
int test = 0;	//�e�X�g�p�̕ϐ�
int Font[10];	//�t�H���g(���₷�Ȃ�z��ɂ���)
int p_music = -1;//���݂̉��t���Ă����
int gameover_count;	//�Q�[���I�[�o�[�ɂȂ��Ă���̃G�t�F�N�g�̃J�E���g

//�F�̕ϐ�
int black;
int green;
int red;
int litegreen;

//���j���[��ʂ�L�[����̕ϐ�
enum e_flag flag = e_title;			//���݂̃t���O
enum e_flag cancel_flag = e_title;	//�L�����Z���Ŗ߂鎞�̃t���O
enum e_mode mode_flag = em_normal;	//�Q�[�����[�h�̃t���O
char *cPad[9];//�Q�[���p�b�h�̑��삷��{�^���̕�����ő�������ɗp����
int cursor = 0;		//�c�J�[�\�����ǂ̈ʒu�ɂ��邩
int cursor_LR = 0;	//���J�[�\�����ǂ̈ʒu�ɂ��邩
int N_o_i = 0;		//���݂̑I����ʂ̍��ڐ�
int N_o_i_LR = 0;	//���݂̑I����ʂ̍��ڐ�
int button[9];		//�ݒ肳�ꂽ�{�^���̓��̓t���[���J�E���g e_key�Őݒ肳�ꂽenum�̒l��Y�����ɂ���
int key_p[9];		//�L�[�R���t�B�O�Őݒ肳�ꂽ�Q�[���p�b�h�̃{�^����z��ɃQ�[���p�b�h�̓Y�����ŕۑ����� e_key�Őݒ肳�ꂽenum�̒l��Y�����ɂ���
int Key[256];
int Pad[28];		//�Q�[���p�b�h�̓��̓t���[���J�E���g

// change_flag�͂����Ɏ��s����Ȃ��̂ň�����ۑ�����
enum e_flag changeFlag_flag;
int changeFlag_cursor;
int changeFlag_cursor2;

//�h�A�̈ړ��͂����Ɏ��s����Ȃ��̂ňړ���̍��W��ۑ�����
int door_fade_x;
int door_fade_y;
