#include"struct.h"
#include"DxLib.h"
struct _player player;
struct _enemy enemy[ENEMY];
struct _enemyemerge enemyemerge[ENEMYEMERGE];
struct _boss boss;
struct _bullet playerbullet[BULLET];
struct _bullet enemybullet[ENEMYBULLET];
struct _item item[ITEM];
struct _background background;
struct _music music;
struct _img img;
struct _anime ani;
enum e_flag flag;
enum e_flag cancel_flag = e_title;	//�L�����Z���Ŗ߂鎞�̃t���O
enum e_difficulty difficulty;
enum e_stage stage;		//�X�e�[�W
enum e_world world;		//���[���h
enum e_bossflag boss_flag;
enum e_mode mode_flag;	//�Q�[�����[�h�̃t���O
enum e_fade fade_flag;	//�t�F�[�h�A�E�g���Ă��邩�ǂ����̃t���O
enum e_key ekey;	//�Q�[�����Ŏg�p�����{�^���̐������錾����

/*�Q�[�������̕ϐ�*/
int chap;			//�`���v�^�[�����Ԗڂ�
int p_music = -1;	//���݂̉��t���Ă����
long long hiscore;		//�n�C�X�R�A
int stageTimeCount;		//�X�e�[�W�J�n����̎���(���̎��Ԃɉ����ēG���o��)
int PlaybackFlag = 0;	//�|�[�Y��ʂ���߂�����̍Đ�����1,����ȊO��0
int draw_ex = 1;	//��������̕`��̃I���I�t�ŃI�v�V��������ύX��
int window_mode = 0;	//�E�B���h�E���[�h�Ȃ�0,�t���X�N���[�����[�h�Ȃ�1
int time;	//�N���A����̎��Ԃ̃J�E���g

/*�t�H���g*/
int Font[5];
int black = GetColor(32, 32, 32);
int darkblack = GetColor(0, 0, 0);
int liteblack = GetColor(44, 44, 44);
int red = GetColor(212, 50, 52);
int greenblue = GetColor(31, 255, 255);
int green = GetColor(32, 130, 62);
int litegreen = GetColor(0, 254, 0);
int silver = GetColor(221, 224, 234);
int white = GetColor(255, 255, 255);

/*�t�F�[�h�A�E�g�p�̕ϐ�*/
int bright = 255;	//��ʂ̋P�x

/*change_flag�͂����Ɏ��s����Ȃ��̂ň�����ۑ�����*/
enum e_flag changeFlag_flag;
int changeFlag_cursor;
int changeFlag_cursor2;

/*���j���[��ʂ̕ϐ�*/
int cursor = 0;		//�c�J�[�\�����ǂ̈ʒu�ɂ��邩
int cursor_LR = 0;	//���J�[�\�����ǂ̈ʒu�ɂ��邩
int cancel_cursor = 0;	//�L�����Z���Ŗ߂鎞�̃J�[�\���̈ʒu
int N_o_i = 0;		//���݂̑I����ʂ̍��ڐ�
int N_o_i_LR = 0;	//���݂̑I����ʂ̍��ڐ�
int count = 0;		//�J�[�\�����͂̑҂����Ԃ̃J�E���g

/*�L�[����̕ϐ�*/
int button[8];		//�ݒ肳�ꂽ�{�^���̓��̓t���[���J�E���g e_key�Őݒ肳�ꂽenum�̒l��Y�����ɂ���
int key_p[8];		//�L�[�R���t�B�O�Őݒ肳�ꂽ�Q�[���p�b�h�̃{�^����z��ɃQ�[���p�b�h�̓Y�����ŕۑ����� e_key�Őݒ肳�ꂽenum�̒l��Y�����ɂ���
int Key[256];		//�L�[���͂̓��̓t���[���J�E���g
int Pad[28];		//�Q�[���p�b�h�̓��̓t���[���J�E���g
char *cPad[8];		//�Q�[���p�b�h�̑��삷��{�^���̕�����ő�������ɗp����
