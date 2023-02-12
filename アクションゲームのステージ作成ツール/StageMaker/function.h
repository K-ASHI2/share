#include"DrawFunction.h"
#include"InitFunction.h"
#include"MenuFunction.h"
#include"csFunction.h"

/*�ǂݍ��݊֐�*/
//�}�b�v�`�b�v�ǂݍ���
//_FileName:�ǂݍ��ރ}�b�v�t�@�C���̃p�X
void ReadMap(const char *_FileName);
//�������w�肵�Ȃ��ꍇCurrentFile���p�X�Ƃ���
void ReadMap();
//�Â��o�[�W�����̃}�b�v�ǂݍ���
void ReadSimpleMap(const char *_FileName);
//�V�K�쐬
void NewMap();
//�}�b�v�`�b�v�ɏ������ފ֐�
void WriteMap();
//�摜�̃��[�h
void LoadImage();
//�A�j���[�V�����̃��[�h
void LoadAnime();
//���y�̃��[�h
void LoadMusic();
//���y�̃Z�b�g
void SetMusic(char *FileName);
//�w�i�̃��[�h
void LoadBackground();
//�w�i�̃Z�b�g
void SetBackground(const TCHAR *FileName, int size_x, int size_y);
//�X�e�[�W�ɒu�����̏�����
void LoadSelectThings();
//select_thing�̃Z�b�g(�����t���ALoadSelectThings����ȊO�̌ďo���֎~)
void SetSelectThing(int number, int GrHandle, char *description, bool turn = false, bool drawflag = true);
//select_thing�̃Z�b�g(LoadSelectThings����ȊO�̌ďo���֎~)
void SetSelectThing(int number, int GrHandle, bool turn = false, bool drawflag = true);
//select_thing�̃Z�b�g(�ԍ��w�肠��)
void SetSelectThing2(int i, int number, int GrHandle, bool turn = false, bool drawflag = true);
//�ʏ��蔻��̑傫�������炷�ꍇ�̐ݒ�
void SetSelectShift(int i, int l_shift, int r_shift, int u_shift, int d_shift);

/*���y��炷�֐�*/
//����m�ɑΉ��������y��炷 loop : 1�Ȃ烋�[�v���A����ȊO�Ȃ烋�[�v���Ȃ�
void PlayMusic(int m, int loop = 1);
//�ݒ肵�������̉��y��炷
void PM_Number();
//����e�ɑΉ��������ʉ���炷
//void EffectSound(enum e_effectSound e);

/*�X�V�֐�*/
//�Q�[�������̍X�V
void Update();
//�X�e�[�W�쐬���̃Q�[������
void CreateStage();


