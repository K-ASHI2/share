#include"DxLib.h"
#include"extern.h"
#include"function.h"

//�`��̊֐�
void Draw() {

	//��ʃN���A
	ClearDrawScreen();

	switch (flag) {
	case e_createStage:		//�X�e�[�W�쐬���̉��
		DrawStage();
		break;
	}
	ScreenFlip();
}

void BlackScreen(int t) {//�w�肵�����Ԃ�����ʂ��؂�ւ�鎞�ɐ^���Âɂ���
	ClearDrawScreen();
	ScreenFlip();
	WaitTimer(t);
}
