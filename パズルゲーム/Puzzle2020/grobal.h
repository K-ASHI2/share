#include"struct.h"
#include"Player.h"
#include"Block.h"
#include"Music.h"
#include"MenuWindow.h"
#include"KeyPad.h"
#include"Font2.h"

class CPlayer player1;
class CPlayer player2;
class CMusic music;
class CMenuWindow menuWindow;
class CKeyPad keyPad;
class CFont2 font;
struct _img img;

/*�Q�[�������̕ϐ�*/
long long hiscore;	//�n�C�X�R�A
int timelimit;		//��������
int timeCount;	//�Q�[���J�n����̎��Ԃ̃J�E���g
int clear_count;	//�N���A����̎��Ԃ̃J�E���g
bool hiscore_flag;	//�n�C�X�R�A����������ǂ���
e_mode mode_flag;		//�Q�[�����[�h�̃t���O
int lastSelectedCPUMode = 0;	//�Ō�ɑI��CPU�̋����̕ۑ�
e_padInputMode padInputMode = epad_pad_pad;