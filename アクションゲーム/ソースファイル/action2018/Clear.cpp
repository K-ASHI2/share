#include"DxLib.h"
#include"extern.h"
#include"function.h"

//�N���A��ʂ̕\��
void clear() {
	if (button[KEY_JUMP] == 1) {	//����{�^���������ꂽ���ʂ�ς���
		//�ʏ탂�[�h
		if (mapload % 1000 == 441)	//�Ō�̃X�e�[�W�Ȃ�^�C�g����ʂɖ߂�
			change_flag(e_title);
		else {
			//�X�e�[�W�ύX�̓t���O��ς��Ă���s��
			//�����ŕς���ƈ�u�I�[���N���A���\������Ă��܂�
			change_flag(e_gameplay);
		}
	}
}
