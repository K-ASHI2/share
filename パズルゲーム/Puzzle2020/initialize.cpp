#include"extern.h"
#include"function.h"
#include <vector>

//�X�e�[�W�J�n���̏�����
void init(){

	if (mode_flag == em_score_attack)
	{
		player1.init(e_1p);
		timelimit = (60 + 1) * 60 - 1;	//���Ԑ�����60�b�ɂ���
	}
	else
	{
		timeCount = 0;
		player1.init(e_1p);
		player2.init(e_2p);
	}
	keyPad.init_key();

	//�N���A��ʂ̃e�X�g�p
	//timelimit = 1 * 60;

	music.stageMusic();	//�X�e�[�W�ɑΉ��������y��炷
	clear_count = 0;
	hiscore_flag = false;
}
