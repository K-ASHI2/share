#pragma once
#include"struct.h"

WNDPROC dxWndProc;
//���C���E�B���h�E�̃n���h��
HWND hMainWnd;
//�C���X�^���X�n���h��
HINSTANCE hInst;

//�\���̂̐錾
struct S_img img;
struct S_anime ani;
struct S_scrollbar scrollbar;
struct S_scrollbar scrollbar2;
struct S_SelectThing select_thing[MAX_THINGS];
struct S_background background[BACKGROUND_MAX];

int map[MAX_WIDTH][MAX_HEIGHT];
int backup[BACK_MAX][MAX_WIDTH][MAX_HEIGHT];//�ŋ�100�񕪂̍�Ƃ�ۑ�����
int backup_w[BACK_MAX];	//backup��map�̕�
int backup_h[BACK_MAX];	//backup��map�̍���
int back_c;	//backup�̌��݂̍�ƈʒu
int music[MUSIC_MAX];
int FontHandle;
enum e_fade fade_flag;	//�t�F�[�h�A�E�g���Ă��邩�ǂ����̃t���O
int bright = 255;	//��ʂ̋P�x
int sound;		//0�Ȃ特����Ȃ��@1�Ȃ��
int width_size = WIDTH_SIZE;	//�X�e�[�W�ɂ���ăX�e�[�W�̃T�C�Y��ς���
int height_size = HEIGHT_SIZE;
int Font[10];	//�t�H���g(���₷�Ȃ�z��ɂ���)
int p_music = -1;//���݂̉��t���Ă����
int stage_x;	//�X�e�[�W�̃X�N���[����x���W
int stage_y;	//�X�e�[�W�̃X�N���[����y���W
char *CurrentFile = "default.txt";
int param[64];	//�t�@�C���Ŏ��R�Ɏw��ł���p�����[�^
int param_length;	//�p�����[�^�̐�
int block_size = BLOCK;	//�}�X�ڂ̑傫��
int map_si[1000];	//�}�b�v��̔ԍ�����select_thing�̔z��̓Y�����ւ̋t����

//�F�̕ϐ�
unsigned int black;
unsigned int green;
unsigned int red;
unsigned int litegreen;
unsigned int redbutton;
unsigned int bluebutton;

//���j���[��ʂ�L�[����̕ϐ�
enum e_flag flag = e_createStage;			//���݂̃t���O
enum e_flag cancel_flag = e_createStage;	//�L�����Z���Ŗ߂鎞�̃t���O
bool end_flag = false;
char *cPad[8];//�Q�[���p�b�h�̑��삷��{�^���̕�����ő�������ɗp����
int cursor = 0;		//�c�J�[�\�����ǂ̈ʒu�ɂ��邩
int cursor_LR = 0;	//���J�[�\�����ǂ̈ʒu�ɂ��邩
int N_o_i = 0;		//���݂̑I����ʂ̍��ڐ�
int N_o_i_LR = 0;	//���݂̑I����ʂ̍��ڐ�
int button[8];		//�ݒ肳�ꂽ�{�^���̓��̓t���[���J�E���g e_key�Őݒ肳�ꂽenum�̒l��Y�����ɂ���
int key_p[8];		//�L�[�R���t�B�O�Őݒ肳�ꂽ�Q�[���p�b�h�̃{�^����z��ɃQ�[���p�b�h�̓Y�����ŕۑ����� e_key�Őݒ肳�ꂽenum�̒l��Y�����ɂ���
int Key[256];
int Pad[28];		//�Q�[���p�b�h�̓��̓t���[���J�E���g

// change_flag�͂����Ɏ��s����Ȃ��̂ň�����ۑ�����
enum e_flag changeFlag_flag;
int changeFlag_cursor;
int changeFlag_cursor2;

//�X�e�[�W�쐬�Ŏg�p����ϐ�
int sx, sy;		//�I������Ă���x�Ay���W��ۑ�����(�}�b�v�̍����̃}�X�ڒP��)
int sx2, sy2;	//���j���[���̑I������Ă���x�Ay���W��ۑ�����(��ʂ̍���)
int menu_b;		//�X�e�[�W���̃��j���[�̃{�^��
int cs_page[4];	//�X�e�[�W���̃��j���[�̃y�[�W
int cs_max_page[4];	//�X�e�[�W���̃��j���[�̃y�[�W�̍ő�l
int si_block;	//select_thing�̔z��̓Y�����̃u���b�N�̊J�n�ʒu
int si_etc;		//select_thing�̔z��̓Y�����̂��̑��̊J�n�ʒu
int si_etc_end;	//select_thing�̔z��̓Y�����̂��̑��̏I���ʒu
int Mouse;		//�}�E�X���Q�Ƃ���
int mx, my;		//�}�E�X��x���W�Ay���W(��ʂ̍���)
int mx2,my2;	//1�t���[���O�̃}�E�X�̍��W(��ʂ̍���)
int cs_map;		//�I�����ꂽ���̃}�b�v�ɂ����鐔��
int cs_map2;	//���������Ɍ��̍��W�ɂ���������
int P_MouseL;	//1�t���[���O�̍��N���b�N�̓��̗͂L��
int MouseL;		//���N���b�N�̓��̗͂L��
int scroll_v;	//�X�N���[���̑��x 0�Ȃ�X�N���[�����Ȃ�
int music_n;		//���y�̔ԍ�
int background_n;	//�w�i�̔ԍ�
bool c_move = false;	//�������I���܂Ńo�b�N�A�b�v�͂Ƃ�Ȃ�:�������Ă���Ȃ�true
int back_top;			//�o�b�N�A�b�v�f�[�^�̍Ō��
int back_head;			//�o�b�N�A�b�v�f�[�^�̐擪
int grid_sizex = 32;	//���W��艽�h�b�g�E���܂ŕ`�悷�邩
int grid_sizey = 32;	//���W��艽�h�b�g�����܂ŕ`�悷�邩
int grid_sizex4 = 0;	//���W��艽�h�b�g�����܂ŕ`�悷�邩
int grid_sizey4 = 0;	//���W��艽�h�b�g�����܂ŕ`�悷�邩
int grid_sizex5 = -1;	//�������Ă�����̂����W��艽�h�b�g�E���܂ŕ`�悷�邩
int grid_sizey5 = -1;	//�������Ă�����̂����W��艽�h�b�g�����܂ŕ`�悷�邩
int grid_sizex6 = 0;	//�������Ă�����̂����W��艽�h�b�g�����܂ŕ`�悷�邩
int grid_sizey6 = 0;	//�������Ă�����̂����W��艽�h�b�g�����܂ŕ`�悷�邩
int mc = 0;				//�R�s�[���镨�̔ԍ�
char *select_description[1000];	//�I��ł��镨�̐���(�z��̓Y�����̓}�b�v�ɂ����鐔��)
