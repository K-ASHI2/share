#include"struct.h"
#include"Player.h"
#include"Block.h"
#include"Music.h"
#include"MenuWindow.h"
#include"KeyPad.h"
#include"Font2.h"

extern CPlayer player1;
extern CPlayer player2;
extern CMusic music;
extern CMenuWindow menuWindow;
extern CKeyPad keyPad;
extern CFont2 font;
extern _img img;

/*�Q�[�������̕ϐ�*/
extern long long hiscore;	//�n�C�X�R�A
extern int timelimit;		//��������
extern int timeCount;	//�Q�[���J�n����̎��Ԃ̃J�E���g
extern int clear_count;		//�N���A����̎��Ԃ̃J�E���g
extern bool hiscore_flag;	//�n�C�X�R�A����������ǂ���
extern e_mode mode_flag;	//�Q�[�����[�h�̃t���O
extern int lastSelectedCPUMode;	//�Ō�ɑI��CPU�̋����̕ۑ�
extern e_padInputMode padInputMode;
