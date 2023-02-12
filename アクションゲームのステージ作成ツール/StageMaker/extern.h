#pragma once
#include"struct.h"

extern WNDPROC dxWndProc;
//���C���E�B���h�E�̃n���h��
extern HWND hMainWnd;
//�C���X�^���X�n���h��
extern HINSTANCE hInst;

extern S_img img;
extern S_anime ani;	//�A�j���[�V������ۑ�����
extern S_scrollbar scrollbar;
extern S_scrollbar scrollbar2;
extern S_SelectThing select_thing[MAX_THINGS];
extern S_background background[BACKGROUND_MAX];

extern int map[MAX_WIDTH][MAX_HEIGHT];			//��3�� ��� 1000�̈� ����(x.y) 10000�̈� ����(1:�� 2:�E)
extern int backup[BACK_MAX][MAX_WIDTH][MAX_HEIGHT];//�ŋ�100�񕪂̍�Ƃ�ۑ�����
extern int backup_w[BACK_MAX];	//backup��map�̕�
extern int backup_h[BACK_MAX];	//backup��map�̍���
extern int back_c;	//backup�̌��݂̍�ƈʒu
extern int FontHandle;
extern int music[MUSIC_MAX];
extern e_fade fade_flag;	//�t�F�[�h�A�E�g���Ă��邩�ǂ����̃t���O
extern int bright;	//�P�x
extern int sound;
extern int width_size;
extern int height_size;
extern int Font[10];
extern int p_music;	//���݂̉��t���Ă����
extern int stage_x;	//�X�e�[�W�̃X�N���[����x���W
extern int stage_y;	//�X�e�[�W�̃X�N���[����y���W
extern char *CurrentFile;
extern int param[64];	//�t�@�C���Ŏ��R�Ɏw��ł���p�����[�^
extern int param_length;	//�p�����[�^�̐�
extern int block_size;	//�}�X�ڂ̑傫��
extern int map_si[MAX_THINGS];	//�}�b�v��̔ԍ�����select_thing�̔z��̓Y�����ւ̋t����

//�F�̕ϐ�
extern unsigned int black;
extern unsigned int green;
extern unsigned int red;
extern unsigned int litegreen;
extern unsigned int redbutton;
extern unsigned int bluebutton;

//���j���[��ʂ�L�[����̕ϐ�
extern e_flag flag;			//���݂̃t���O
extern e_flag cancel_flag;		//�L�����Z���Ŗ߂鎞�̃t���O
extern bool end_flag;
extern char *cPad[8];	//�Q�[���p�b�h�̑��삷��{�^���̕�����ő�������ɗp����
extern int cursor;		//�c�J�[�\�����ǂ̈ʒu�ɂ��邩
extern int cursor_LR;	//���J�[�\�����ǂ̈ʒu�ɂ��邩
extern int N_o_i;		//���݂̑I����ʂ̍��ڐ�
extern int N_o_i_LR;	//���݂̑I����ʂ̍��ڐ�
extern int button[8];	//�ݒ肳�ꂽ�{�^���̓��̓t���[���J�E���g e_key�Őݒ肳�ꂽenum�̒l��Y�����ɂ���
extern int key_p[8];	//�L�[�R���t�B�O�Őݒ肳�ꂽ�Q�[���p�b�h�̃{�^����z��ɃQ�[���p�b�h�̓Y�����ŕۑ����� e_key�Őݒ肳�ꂽenum�̒l��Y�����ɂ���
extern int Key[256];	//�L�[���͂̓��̓t���[���J�E���g
extern int Pad[28];		//�Q�[���p�b�h�̓��̓t���[���J�E���g

// change_flag�͂����Ɏ��s����Ȃ��̂ň�����ۑ�����
extern enum e_flag changeFlag_flag;
extern int changeFlag_cursor;
extern int changeFlag_cursor2;

//�X�e�[�W�쐬�Ŏg�p����ϐ�
extern int sx, sy;		//�I������Ă���x�Ay���W��ۑ�����(�}�b�v�̍����̃}�X�ڒP��)
extern int sx2, sy2;	//���j���[���̑I������Ă���x�Ay���W��ۑ�����(��ʂ̍���)
extern int menu_b;		//�X�e�[�W���̃��j���[�̃{�^��
extern int cs_page[4];	//�X�e�[�W���̃��j���[�̃y�[�W
extern int cs_max_page[4];	//�X�e�[�W���̃��j���[�̃y�[�W�̍ő�l
extern int si_block;	//select_thing�̔z��̓Y�����̃u���b�N�̊J�n�ʒu
extern int si_etc;		//select_thing�̔z��̓Y�����̂��̑��̊J�n�ʒu
extern int si_etc_end;		//select_thing�̔z��̓Y�����̂��̑��̏I���ʒu
extern int Mouse;		//�}�E�X���Q�Ƃ���
extern int mx, my;		//�}�E�X��x���W�Ay���W(��ʂ̍���)
extern int mx2, my2;	//1�t���[���O�̃}�E�X�̍��W(��ʂ̍���)
extern int cs_map;		//�I�����ꂽ���̃}�b�v�ɂ����鐔��
extern int cs_map2;		//���������Ɍ��̍��W�ɂ���������
extern int P_MouseL;	//1�t���[���O�̍��N���b�N�̓��̗͂L��
extern int MouseL;		//���N���b�N�̓��̗͂L��
extern int scroll_v;	//�X�N���[���̑��x 0�Ȃ�X�N���[�����Ȃ�
extern int music_n;		//���y�̔ԍ�
extern int background_n;	//�w�i�̔ԍ�
extern bool c_move;		//�������I���܂Ńo�b�N�A�b�v�͂Ƃ�Ȃ�
extern int back_top;	//�o�b�N�A�b�v�f�[�^�̍Ō��
extern int back_head;	//�o�b�N�A�b�v�f�[�^�̐擪
extern int grid_sizex;	//���W��艽�h�b�g�E���܂ŕ`�悷�邩
extern int grid_sizey;	//���W��艽�h�b�g�����܂ŕ`�悷�邩
extern int grid_sizex4;	//���W��艽�h�b�g�����܂ŕ`�悷�邩
extern int grid_sizey4;	//���W��艽�h�b�g�����܂ŕ`�悷�邩
extern int grid_sizex5;	//�������Ă�����̂����W��艽�h�b�g�E���܂ŕ`�悷�邩
extern int grid_sizey5;	//�������Ă�����̂����W��艽�h�b�g�����܂ŕ`�悷�邩
extern int grid_sizex6;	//�������Ă�����̂����W��艽�h�b�g�����܂ŕ`�悷�邩
extern int grid_sizey6;	//�������Ă�����̂����W��艽�h�b�g�����܂ŕ`�悷�邩
extern int mc;			//�R�s�[���镨�̔ԍ�
extern char *select_description[1000];	//�I��ł��镨�̐���(�z��̓Y�����̓}�b�v�ɂ����鐔��)
