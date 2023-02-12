#include"DxLib.h"
#include"grobal.h"
#include"function.h"

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR ipCmdLine, int nShowCmd){

	//�E�B���h�E�̃^�C�g����ύX
	SetMainWindowText("ROUND MONSTERS 3");

	//�E�B���h�E���[�h�ɕύX
	ChangeWindowMode(TRUE);

	//�𑜓x�ƃJ���[�r�b�g����ݒ�
	SetGraphMode(WINDOW_WIDTH_2, WINDOW_HEIGHT_2, 32);

	//SetWindowSizeExtendRate(1.5);

	SetWindowSizeChangeEnableFlag(TRUE) ;

	// �`�悷�镶����̃T�C�Y��ݒ�
	SetFontSize(32) ;
	// �`�悷�镶����̑�����ݒ�
    SetFontThickness(3) ;

	//�������Ɏ��s�������߂�
	if (DxLib_Init() != 0)
		return 0;

	//�摜�̃��[�h
	image();
	//�A�j���[�V�����̃��[�h
	anime();
	//���y�̃��[�h
	Music();
	//�w�i�̃��[�h
	LoadBackground();

	Font[0] = CreateFontToHandle("�l�r �S�V�b�N", 20, 10, DX_FONTTYPE_NORMAL);           //"MS�S�V�b�N"��20pt,����10�̃t�H���g���쐬
	Font[1] = CreateFontToHandle("Arial", 27, 10, DX_FONTTYPE_NORMAL);
	Font[2] = CreateFontToHandle("�l�r �S�V�b�N", 30, 10, DX_FONTTYPE_NORMAL);
	Font[4] = CreateFontToHandle("�l�r �S�V�b�N", 12, 6, DX_FONTTYPE_NORMAL);
	//�F�̏�����
	//�֐����Ăяo������define�ł��Ȃ��̂ł����ŏ���������
	black = GetColor(0, 0, 0);		//��
	green = GetColor(32, 130, 62);	//��
	red = GetColor(212, 50, 52);	//��
	litegreen = GetColor(0, 254, 0);//���邢��

	SetDrawScreen(DX_SCREEN_BACK);

	FontHandle = CreateFontToHandle(NULL,20,3);
	//�Q�[���p�b�h�̃L�[�R���t�B�O�̏�����
	init_key_p();
	//�^�C�g����ʂ̃t���O�ɂ���(�t�F�[�h�A�E�g���Ȃ�)
	change_flag2(e_title);

	
	/************************** �Q�[�����[�v *****************************/

	//�t���O��em_end�ɂȂ邩escape�������ꂽ��I������
	while (!ProcessMessage() && mode_flag != em_end && !Key[KEY_INPUT_ESCAPE]) {

		//�t�F�[�h�A�E�g���邩�ǂ���
		switch(fade_flag){
		case ef_fadeOut:
			fadeOut();
			break;
		case ef_fadeOut_door:
			fadeOut_door();
			break;
		case ef_fadeOut_door2:
			fadeOut_door2();
			break;
		case ef_fadeIn:
			fadeIn();
			break;
		case ef_normal:
			updateKey();	//�L�[���͂̍X�V
			update();		//�Q�[�������̍X�V
			break;
		}

		//�`��̓t�F�[�h�A�E�g�Ɋւ�炸�s��
		draw();
	}

	/************************ �Q�[�����[�v����� ************************/

	//DX���C�u�����g�p�̏I������
	DxLib_End();
	
	//SOFT�̏I��
	return 0;

}
