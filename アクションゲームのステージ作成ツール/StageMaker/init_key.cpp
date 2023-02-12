#include"DxLib.h"
#include"function.h"
#include"extern.h"

//�L�[�{�[�h�ƃQ�[���p�b�h�̓��͂̏�����
void init_key() {
	for (int i = 0; i < 256; i++) {
		Key[i] = 0;
	}
	for (int i = 0; i < 28; i++) {
		Pad[i] = 0;
	}

}

//�Q�[���p�b�h�̃L�[�R���t�B�O�̏�����
//�Q�[�����[�v�J�n�O�ƃR���t�B�O�̃��Z�b�g�ŌĂяo��
void init_key_p() {
	key_p[KEY_DOWN] = PAD_DOWN;
	key_p[KEY_LEFT] = PAD_LEFT;
	key_p[KEY_RIGHT] = PAD_RIGHT;
	key_p[KEY_UP] = PAD_UP;
	key_p[KEY_JUMP] = PAD_A;
	key_p[KEY_ATTACK] = PAD_X;
	key_p[KEY_PAUSE] = PAD_START;

	cPad[KEY_DOWN] = "PAD_DOWN";
	cPad[KEY_LEFT] = "PAD_LEFT";
	cPad[KEY_RIGHT] = "PAD_RIGHT";
	cPad[KEY_UP] = "PAD_UP";
	cPad[KEY_JUMP] = "PAD_A";
	cPad[KEY_ATTACK] = "PAD_X";
	cPad[KEY_PAUSE] = "PAD_START";
}
