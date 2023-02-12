#include"DxLib.h"
#include"grobal.h"
#include"function.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {

	//�E�B���h�E�̃^�C�g����ύX
	SetMainWindowText("Barrage Absorber");

	ChangeWindowMode(TRUE);
	SetWindowSizeChangeEnableFlag(TRUE);

	//�𑜓x�ƃJ���[�r�b�g����ݒ�
	SetGraphMode(WINDOW_WINDTH, WINDOW_HEIGHT, 32);

	//Release�ŋN�����鎞�͏���
	//SetWindowSizeExtendRate(1.5);

	//�ő剻�{�^����t����
	SetWindowStyleMode(7);

	//�������Ɏ��s�������߂�
	if (DxLib_Init() != 0)
		return 0;

	SetDrawScreen(DX_SCREEN_BACK);

	//�Q�[���p�b�h�̃L�[�R���t�B�O�̏�����
	init_key_p();

	//�t�H���g�̐ݒ�
	SetFont();

	Load();

	//��Փx�̏�����(��Փx�I���̑���)
	//difficulty = ed_easy;
	difficulty = ed_normal;
	//difficulty = ed_hard;
	//difficulty = ed_lunatic;

	PlayMusic(music.menu);
	ChangeFlag2(e_title);
	while (!ProcessMessage() && mode_flag != em_end && !Key[KEY_INPUT_ESCAPE]) {

		//��d�ɂȂ��Ă���̂ŏ����đS�̂𒼂�
		UpdateKey();
		Update();
		Draw();

		if (count > 0)
			count--;
		//�t�F�[�h�A�E�g���邩�ǂ���
		switch (fade_flag) {
		case ef_fadeOut:
			FadeOut();
			break;
		case ef_fadeIn:
			FadeIn();
			break;
		case ef_normal:
			UpdateKey();	//�L�[���͂̍X�V
			Update();		//�Q�[�������̍X�V
			//Draw();
			break;
		}
	}
	DxLib_End();
	return 0;
}
