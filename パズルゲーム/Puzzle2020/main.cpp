#include"DxLib.h"
#include"grobal.h"
#include"function.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	//�E�B���h�E�̃^�C�g����ύX
	SetMainWindowText("Draw&Drop Twins");

	ChangeWindowMode(TRUE);
	SetWindowSizeChangeEnableFlag(TRUE);

	//�𑜓x�ƃJ���[�r�b�g����ݒ�
	SetGraphMode(WINDOW_WINDTH, WINDOW_HEIGHT, 32);

	//�ő剻�{�^����t����
	SetWindowStyleMode(7);

	//�������Ɏ��s�������߂�
	if (DxLib_Init() != 0)
		return 0;

	SetDrawScreen(DX_SCREEN_BACK);

	//�Q�[���p�b�h�̃L�[�R���t�B�O�̏�����
	keyPad.init();

	//�L�[���͂̏�����
	keyPad.init_key();

	//�t�H���g�̐ݒ�
	font.init();

	load();

	music.playMenu();
	menuWindow.changeFlag2(e_title);

	//2P�̑I����ʂ��������Ȃ̂ł����Ŏw�肵�Ă���(��Œ���)
	player2.setCpuMove(ec_search);

	while (!ProcessMessage() && mode_flag != em_end && !keyPad.getKey(KEY_INPUT_ESCAPE))
	{
		//�t�F�[�h�A�E�g���邩�ǂ���
		switch (menuWindow.getFadeFlag())
		{
		case ef_fadeOut:
			menuWindow.fadeOut();
			break;
		case ef_fadeIn:
			menuWindow.fadeIn();
			break;
		case ef_normal:
			keyPad.updateKey();	//�L�[���͂̍X�V
			update();		//�Q�[�������̍X�V
			break;
		}

		draw();
	}

	DxLib_End();
	return 0;
}
