#include"struct.h"

extern _player player;						//���@��struct���C���X�^���X���@�@
extern _enemy enemy[ENEMY];				//�G��struct��
extern _enemyemerge enemyemerge[ENEMYEMERGE]; 
extern _boss boss;
extern _bullet playerbullet[BULLET];		//�e��struct�����@�̒e�p��
extern _bullet enemybullet[ENEMYBULLET];	//�e��struct��G�̒e�p��
extern _item item[ITEM];					//�A�C�e����struct��
extern _background background;				//�w�i��struct��
extern _img img;							//�摜��struct��
extern _anime ani;	//�A�j���[�V������ۑ�����
extern _music music;

extern e_flag flag;
extern e_flag cancel_flag;		//�L�����Z���Ŗ߂鎞�̃t���O
extern e_difficulty difficulty;
extern e_stage stage;	//�X�e�[�W
extern e_world world;		//���[���h
extern e_bossflag boss_flag;
extern e_mode mode_flag;	//�Q�[�����[�h�̃t���O
extern e_fade fade_flag;	//�t�F�[�h�A�E�g���Ă��邩�ǂ����̃t���O
extern e_key ekey;		//�Q�[�����Ŏg�p�����{�^���̐������錾����

/*define�̐��l�ɂ���ĕϓ�����萔*/
static int G_W_CENTER_X = (G_W_LEFT + G_W_RIGHT) / 2;	//��ʂ̒�����X���W
static int G_W_CENTER_Y = (G_W_UPPER + G_W_LOWER) / 2;	//��ʂ̒�����Y���W

/*�Q�[�������̕ϐ�*/
extern int chap;	//�`���v�^�[�����Ԗڂ�
extern int p_music;	//���݂̉��t���Ă����
extern long long hiscore;		//�n�C�X�R�A
extern int stageTimeCount;		//�X�e�[�W�J�n����̎���(���̎��Ԃɉ����ēG���o��)
extern int PlaybackFlag;		//�|�[�Y��ʂ���߂�����̍Đ�����1,����ȊO��0
extern int draw_ex;	//��������̕`��̃I���I�t�ŃI�v�V��������ύX��
extern int window_mode;	//�E�B���h�E���[�h�Ȃ�0,�t���X�N���[�����[�h�Ȃ�1
extern int time;	//�N���A����̎��Ԃ̃J�E���g

/*�t�H���g*/
extern int Font[5];
extern int black;
extern int darkblack;
extern int liteblack;
extern int red;
extern int greenblue;
extern int green;
extern int litegreen;
extern int silver;
extern int white;

/*�t�F�[�h�A�E�g�p�̕ϐ�*/
extern int bright;	//�P�x

/*change_flag�͂����Ɏ��s����Ȃ��̂ň�����ۑ�����*/
extern e_flag changeFlag_flag;
extern int changeFlag_cursor;
extern int changeFlag_cursor2;

/*���j���[��ʂ̕ϐ�*/
extern int cursor;		//�c�J�[�\�����ǂ̈ʒu�ɂ��邩
extern int cursor_LR;	//���J�[�\�����ǂ̈ʒu�ɂ��邩
extern int cancel_cursor;	//�L�����Z���Ŗ߂鎞�̃J�[�\���̈ʒu
extern int N_o_i;		//���݂̑I����ʂ̍��ڐ�
extern int N_o_i_LR;	//���݂̑I����ʂ̍��ڐ�
extern int count;		//�J�[�\�����͂̑҂����Ԃ̃J�E���g

/*�L�[����̕ϐ�*/
extern int button[8];	//�ݒ肳�ꂽ�{�^���̓��̓t���[���J�E���g e_key�Őݒ肳�ꂽenum�̒l��Y�����ɂ���
extern int key_p[8];	//�L�[�R���t�B�O�Őݒ肳�ꂽ�Q�[���p�b�h�̃{�^����z��ɃQ�[���p�b�h�̓Y�����ŕۑ����� e_key�Őݒ肳�ꂽenum�̒l��Y�����ɂ���
extern int Key[256];	//�L�[���͂̓��̓t���[���J�E���g
extern int Pad[28];		//�Q�[���p�b�h�̓��̓t���[���J�E���g
extern char *cPad[8];	//�Q�[���p�b�h�̑��삷��{�^���̕�����ő�������ɗp����
