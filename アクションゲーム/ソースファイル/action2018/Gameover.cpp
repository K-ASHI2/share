#include"DxLib.h"
#include"extern.h"
#include"function.h"

//�Q�[���I�[�o�[��ʂ̕\��
void gameover() {

	if (button[KEY_JUMP] == 1) {	//����{�^���������ꂽ��Q�[���v���C��ʂɖ߂�
		change_flag(e_gameplay);
	}
}
