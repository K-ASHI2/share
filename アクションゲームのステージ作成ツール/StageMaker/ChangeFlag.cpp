#include"DxLib.h"
#include"extern.h"
#include"function.h"

//�t���O��ς���֐�
//�t���O���ς�����������ɂ��鏈�������s����
//f:�t���O�̎�� c:�c�J�[�\���̈ʒu �f�t�H���g���� 0 c2:���J�[�\���̈ʒu �f�t�H���g���� 0
void ChangeFlag(enum e_flag f, int c, int c2) {

	//�ŏ��̓t�F�[�h�A�E�g�݂̂��s���A���̌�change_flag2���Ăяo����ăt�F�[�h�C���ƃt���O�̕ύX���s��
	fade_flag = ef_fadeOut;
	changeFlag_flag = f;
	changeFlag_cursor = c;
	changeFlag_cursor2 = c2;
}

//�t�F�[�h�A�E�g��Ɏ��ۂɃt���O��ς���֐�
//f:�t���O�̎�� c:�c�J�[�\���̈ʒu �f�t�H���g���� 0 c2:���J�[�\���̈ʒu �f�t�H���g���� 0
void ChangeFlag2(enum e_flag f, int c, int c2) {

	enum e_flag flag2 = flag;	//�ύX�O�̃t���O
	flag = f;
	//�t���O�̓��e���Ƃ̏��������s����
	switch (flag) {
	case e_createStage:
		PM_Number();	//�w�i�ɍ��������y��炷
		break;
	}
}
