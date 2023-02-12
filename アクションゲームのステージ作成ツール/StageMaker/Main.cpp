#include"DxLib.h"
#include"grobal.h"
#include"function.h"
#include"resource.h"
#include"WinUser.h"

//�V���[�g�J�b�g�L�[�̒ǉ�
void AddShortCutKey();

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR ipCmdLine, int nShowCmd){

	hInst = hInstance;
	//block_size = 16;	//�u���b�N������������p�̃e�X�g�l

	//�E�B���h�E�̃^�C�g����ύX
	SetMainWindowText("STAGE MAKER");

	//�E�B���h�E���[�h�ɕύX
	ChangeWindowMode(TRUE);

	//���j���[��ID��ǂݍ���
	LoadMenuResource(IDR_MENU1);

	//�𑜓x�ƃJ���[�r�b�g����ݒ�
	SetGraphMode(WINDOW_WIDTH_2, WINDOW_HEIGHT_2, 32);	

	//�E�C���h�E�T�C�Y���ςɂ���
	SetWindowSizeChangeEnableFlag(TRUE) ;

	// �`�悷�镶����̃T�C�Y��ݒ�
	SetFontSize(32) ;
	// �`�悷�镶����̑�����ݒ�
    SetFontThickness(3) ;

	//��d�N���̋֎~
	SetDoubleStartValidFlag(TRUE);
	//
	//SetWindowStyleMode(7);

	//�������Ɏ��s�������߂�
	if (DxLib_Init() == -1) {
		return 0;
	}

	//���C���E�B���h�E�̃n���h�����擾
	hMainWnd = GetMainWindowHandle();

	//64bit�ł�GWL_WNDPROC�ł͂Ȃ�GWLP_WNDPROC���g��
	dxWndProc = (WNDPROC)GetWindowLongPtr(hMainWnd, GWLP_WNDPROC);

	//�E�C���h�E�v���V�[�W���̌ďo��
	//GetMainWindowHandle:���C���E�B���h�E�̃E�B���h�E�n���h����Ԃ��֐�
	//GWL_WNDPROC:�E�B���h�E�v���V�[�W���̃A�h���X
	//WinProc:�R�[���o�b�N�̊֐�
	SetWindowLongPtr(hMainWnd, GWLP_WNDPROC, (LONG_PTR)MyWndProc);

	SetUseMenuFlag(TRUE);	// ���j���[��L���ɂ���
	SetUseKeyAccelFlag(TRUE);	// �L�[�{�[�h�A�N�Z�����[�^�[���g�p����
	LoadMenuResource(IDR_MENU1);	// ���j���[�����\�[�X����ǂݍ���
	AddShortCutKey();	//�V���[�g�J�b�g�L�[��ǉ�����

	//�摜�̃��[�h
	LoadImage();
	//�A�j���[�V�����̃��[�h
	LoadAnime();
	//���y�̃��[�h
	LoadMusic();
	//�w�i�̃��[�h
	LoadBackground();
	//�X�e�[�W�ɒu�����̏�����
	LoadSelectThings();

	Font[0] = CreateFontToHandle("�l�r �S�V�b�N", 20, 10, DX_FONTTYPE_NORMAL);           //"MS�S�V�b�N"��20pt,����10�̃t�H���g���쐬
	Font[1] = CreateFontToHandle("Arial", 27, 10, DX_FONTTYPE_NORMAL);
	Font[2] = CreateFontToHandle("�l�r �S�V�b�N", 30, 10, DX_FONTTYPE_NORMAL);

	//�F�̏�����
	//�֐����Ăяo������define�ł��Ȃ��̂ł����ŏ���������
	black = GetColor(0, 0, 0);		//��
	green = GetColor(32, 130, 62);	//��
	red = GetColor(212, 50, 52);	//��
	litegreen = GetColor(0, 254, 0);//���邢��
	redbutton = GetColor(255, 184, 211);
	bluebutton = GetColor(191, 223, 255);

	SetDrawScreen(DX_SCREEN_BACK);

	FontHandle = CreateFontToHandle(NULL,20,3);

	//�Q�[���p�b�h�̃L�[�R���t�B�O�̏�����
	init_key_p();

	//�X�e�[�W�I���̃t���O�ɂ���(�t�F�[�h�A�E�g���Ȃ�)
	ChangeFlag2(e_createStage);

	//�f�t�H���g�̃X�e�[�W���Ăяo��
	NewMap();

	//�X�e�[�W�쐬�̏�����
	//�X�e�[�W�I����ɂ��s���悤�ɕύX����
	init_c();

	/************************** �Q�[�����[�v *****************************/

	//�t���O��em_end�ɂȂ邩escape�������ꂽ��I������
	while (!ProcessMessage() && end_flag == false) {

		//�t�F�[�h�A�E�g���邩�ǂ���
		switch(fade_flag){
		case ef_fadeOut:
			FadeOut();
			break;
		case ef_fadeIn:
			FadeIn();
			break;
		case ef_normal:
			UpdateKey();	//�L�[���͂̍X�V
			Update();		//�Q�[�������̍X�V
			break;
		}
		Draw();			//�`��̓t�F�[�h�A�E�g�Ɋւ�炸�s��
	}

	/************************ �Q�[�����[�v����� ************************/

	//DX���C�u�����g�p�̏I������
	DxLib_End();
	
	//SOFT�̏I��
	return 0;

}

//�V���[�g�J�b�g�L�[�̒ǉ�
void AddShortCutKey() {

	//Dxlib��p����ꍇProcessMessage�Ń��[�v���邽�߁A���̊֐���p���Ȃ���΂Ȃ�Ȃ�
	//ID�⃁�j���[��Dxlib�̊֐��Œǉ����邱�Ƃ��ł��邪���̃v���O�����ł͒��ڎw�肵�Ă���
	AddKeyAccel_ID(IDM_NEWFILE, KEY_INPUT_N, 1, 0, 0);
	AddKeyAccel_ID(IDM_OPENFILE, KEY_INPUT_O, 1, 0, 0);
	AddKeyAccel_ID(IDM_SAVE, KEY_INPUT_S, 1, 0, 0);
	AddKeyAccel_ID(IDM_SAVEAS, KEY_INPUT_A, 1, 0, 0);
	AddKeyAccel_ID(IDM_END, KEY_INPUT_ESCAPE, 0, 0, 0);

	AddKeyAccel_ID(IDM_UNDO, KEY_INPUT_Z, 1, 0, 0);
	AddKeyAccel_ID(IDM_REDO, KEY_INPUT_Y, 1, 0, 0);
	AddKeyAccel_ID(IDM_TRIMMING, KEY_INPUT_X, 1, 0, 0);
	AddKeyAccel_ID(IDM_COPY, KEY_INPUT_C, 1, 0, 0);
	AddKeyAccel_ID(IDM_PASTE, KEY_INPUT_V, 1, 0, 0);

	//������DEL��BACKSPACE�̗����ɑΉ�������
	AddKeyAccel_ID(IDM_DELETE, KEY_INPUT_DELETE, 0, 0, 0);
	AddKeyAccel_ID(IDM_DELETE, KEY_INPUT_BACK, 0, 0, 0);
}
