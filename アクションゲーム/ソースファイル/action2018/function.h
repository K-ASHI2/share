#include"drawFunction.h"
#include"gameFunction.h"
#include"initFunction.h"
#include"judgeFunction.h"
#include"menuFunction.h"

/*�ǂݍ��݊֐�*/
//�}�b�v��ǂݍ��ފ֐�
void ReadMap();
//mapload�ϐ�����ǂݍ��ރe�L�X�g�t�@�C�����𐶐����Ԃ��֐�
char *mapToChar();
//�摜�̃��[�h
void image();
//�A�j���[�V�����̃��[�h
void anime();
//���y�̃��[�h
void LoadMusic();
//���y�̃Z�b�g
void SetMusic(char *FileName);
//���y�̃��[�h
void Music();
//�w�i�̃��[�h
void LoadBackground();
//�w�i�̃Z�b�g
void SetBackground(const TCHAR *FileName, int size_x, int size_y);

/*���y��炷�֐�*/
//����m�ɑΉ��������y��炷 loop : 1�Ȃ烋�[�v���A����ȊO�Ȃ烋�[�v���Ȃ�
void PlayMusic(int m, int loop = 1);
//����e�ɑΉ��������ʉ���炷
void efs(enum e_effectSound e);

/*�X�V�֐�*/
//�Q�[�������̍X�V
void update();
//�Q�[���v���C���̃A�b�v�f�[�g����
void playUpdate();
