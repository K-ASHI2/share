#include"DxLib.h"
#include"extern.h"
#include"function.h"
#include"resource.h"

//�}�b�v���J���_�C�A���O�{�b�N�X
//����������0�A���s������-1��Ԃ�
int MapFileOpen(HWND hWnd, char **pass) {

	//�t�@�C�����J���ׂ̐ݒ�p�\����
	OPENFILENAME ofn;

	//�J�����t�@�C���̃p�X���c���Ă������߂�static�ɂ���
	//static�ɂ��Ȃ���pass�ɎQ�Ƃ�n���Ă����̊֐����I������烁�������J������Ă��܂�
	static char szFile[MAX_PATH] = "";

	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = hWnd;
	ofn.lpstrFilter = "�e�L�X�g �t�@�C�� (*.prn;*.txt;*.csv)\0*.prn;*.txt;*.csv\0"
		"���ׂẴt�@�C��(*.*)\0*.*\0\0";
	ofn.lpstrFile = szFile;
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrTitle = "�}�b�v�t�@�C���̑I��";
	ofn.lpstrDefExt = ".txt";

	//OFN_NOCHANGEDIR:�J�����g�f�B���N�g�������̈ʒu�ɖ߂�
	//�f�B���N�g����߂��Ȃ���fopen��LoadGraph�ȂǂŃt�@�C����������Ȃ��Ȃ��Ă��܂�
	ofn.Flags = OFN_NOCHANGEDIR;

	//�t�@�C���I�[�v���Ɏ��s������-1��Ԃ�
	if (GetOpenFileName(&ofn) == 0) {
		return -1;
	}
	else {
		*pass = szFile;
		return 0;
	}
}

//�}�b�v��ۑ�����_�C�A���O�{�b�N�X
//����������0�A���s������-1��Ԃ�
int MapFileSave(HWND hWnd, char **pass) {

	//�t�@�C�����J���ׂ̐ݒ�p�\����
	OPENFILENAME ofn;

	//�J�����t�@�C���̃p�X���c���Ă������߂�static�ɂ���
	//static�ɂ��Ȃ���pass�ɎQ�Ƃ�n���Ă����̊֐����I������烁�������J������Ă��܂�
	static char szFile[MAX_PATH] = "";

	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = hWnd;
	ofn.lpstrFilter = "�e�L�X�g �t�@�C�� (*.txt;*.csv;*.prn)\0*.txt;prn;*.csv\0"
		"���ׂẴt�@�C��(*.*)\0*.*\0\0";
	ofn.lpstrFile = szFile;
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrTitle = "�ۑ���̃t�@�C���̑I��";
	ofn.lpstrDefExt = ".txt";

	//OFN_NOCHANGEDIR:�J�����g�f�B���N�g�������̈ʒu�ɖ߂�
	//�f�B���N�g����߂��Ȃ���fopen��LoadGraph�ȂǂŃt�@�C����������Ȃ��Ȃ��Ă��܂�
	ofn.Flags = OFN_FILEMUSTEXIST | OFN_OVERWRITEPROMPT | OFN_NOCHANGEDIR;

	//�t�@�C���I�[�v���Ɏ��s������-1��Ԃ�
	if (GetSaveFileName(&ofn) == 0) {
		return -1;
	}
	else {
		*pass = szFile;
		return 0;
	}
}

//�t�@�C�����J���_�C�A���O�{�b�N�X
//int ImgFileOpen(HWND hWnd) {
//
//	//�t�@�C�����J���ׂ̐ݒ�p�\����
//	OPENFILENAME ofn;
//
//	//�����Ɏw��t�@�C���̐�΃p�X����������
//	char szFile[MAX_PATH];
//
//	//memset�֐��ŕϐ��E�z��̒��g��S��NULL�A\0��
//	memset(&ofn, NULL, sizeof(OPENFILENAME));
//	memset(szFile, '\0', sizeof(szFile));
//
//	//�������g�̃T�C�Y
//	ofn.lStructSize = sizeof(OPENFILENAME);
//	//�e�E�B���h�E�̃n���h��
//	ofn.hwndOwner = hWnd;
//	//�\��������t�@�C���̃t�B���^�����O
//	ofn.lpstrFilter = "PNG Files {*.png}\0*.png\0"
//		"JPEG Files {*.jpg}\0*.jpg\0"
//		"BITMAP Files {*.bmp}\0*.bmp\0\0";
//	//�p�X��������z��
//	ofn.lpstrFile = szFile;
//	//�p�X�̍ő啶����
//	ofn.nMaxFile = MAX_PATH;
//	//�t�@�C�����Ŋg���q���w�肳��Ȃ������ꍇ�ɒǉ����镶����
//	ofn.lpstrDefExt = ".png";
//	//�E�B���h�E�̖��O
//	ofn.lpstrTitle = "�摜�t�@�C���̑I��";
//
//	//OFN_NOCHANGEDIR:�J�����g�f�B���N�g�������̈ʒu�ɖ߂�
//	//�f�B���N�g����߂��Ȃ���fopen��LoadGraph�ȂǂŃt�@�C����������Ȃ��Ȃ��Ă��܂�
//	//OFN_HIDEREADONLY:�ǂݎ���p���B��
//	ofn.Flags = OFN_HIDEREADONLY | OFN_NOCHANGEDIR;
//
//	//�t�@�C���I�[�v���Ɏ��s������return
//	if (GetOpenFileName(&ofn) == 0) return -1;
//
//	//�t�@�C���ǂݍ���
//	img.enemy[0] = LoadGraph(szFile);
//	return 0;
//}
