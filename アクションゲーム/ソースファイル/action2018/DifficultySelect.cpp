#include"DxLib.h"
#include"extern.h"
#include"function.h"

void difficulty_select() {	// 0:easy  1:normal  2:hard  -1:�L�����Z��

	select_window();
	//�L�����Z���̏���
	if (button[KEY_ATTACK] == 1 || button[KEY_PAUSE] == 1) {
		//mapload�̒l����X�e�[�W�I����ʂőI�����ꂽ�X�e�[�W�̃J�[�\���̈ʒu���߂�
		change_flag(e_stage_select, (mapload - 1) / 100 - 1, (mapload - 1) % 100 / 10 - 1);
	}

	if (button[KEY_JUMP] == 1) {
		efs(efs_decision);
		mapload += cursor * 1000;	//��Փx��ݒ肷��
		change_flag(e_gameplay);
	}
}
