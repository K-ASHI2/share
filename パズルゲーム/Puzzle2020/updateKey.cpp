#include"DxLib.h"
#include"extern.h"
#include"function.h"

//�L�[�ƃp�b�h�����t���[��������Ă������X�V����
void CKeyPad::updateKey()
{
	char tmpKey[256];
	GetHitKeyStateAll(tmpKey);
	for (int i = 0; i < 256; i++)
	{
		if (tmpKey[i] != 0)
		{
			//int�^�̍ő�𒴂��Ȃ��悤�ɂ���
			if (Key[i] != INT_MAX)
			{
				Key[i]++;
			}
		}
		else
		{
			Key[i] = 0;
		}
	}

	int inputPad1 = GetJoypadInputState(DX_INPUT_PAD1);

	//���͏�Ԃ�28�r�b�g�ŕ\�����
	for (int i = 0; i < 28; i++)
	{
		//i�r�b�g���炷
		if (inputPad1 & (1 << i))
		{
			if (Pad[i] != INT_MAX)
			{
				Pad[i]++;
			}
		}
		else {
			Pad[i] = 0;
		}
	}

	//2�ڂ̃p�b�h�ɂ��Ă����l�ɍs��
	int inputPad2 = GetJoypadInputState(DX_INPUT_PAD2);
	for (int i = 0; i < 28; i++)
	{
		if (inputPad2 & (1 << i))
		{
			if (Pad2[i] != INT_MAX)
			{
				Pad2[i]++;
			}
		}
		else {
			Pad2[i] = 0;
		}
	}

	//�Q�[�����Ŏg�p����7�̃{�^���̃t���[�����𐔂���
	if (Key[KEY_INPUT_DOWN] || Pad[key_p[KEY_DOWN]])
	{
		button[KEY_DOWN]++;
	}
	else {
		button[KEY_DOWN] = 0;
	}
	if (Key[KEY_INPUT_LEFT] || Pad[key_p[KEY_LEFT]])
	{
		button[KEY_LEFT]++;
	}
	else {
		button[KEY_LEFT] = 0;
	}
	if (Key[KEY_INPUT_RIGHT] || Pad[key_p[KEY_RIGHT]])
	{
		button[KEY_RIGHT]++;
	}
	else {
		button[KEY_RIGHT] = 0;
	}
	if (Key[KEY_INPUT_UP] || Pad[key_p[KEY_UP]])
	{
		button[KEY_UP]++;
	}
	else {
		button[KEY_UP] = 0;
	}

	//�L�[�R���t�B�O�ŕω�����{�^��
	if (Key[KEY_INPUT_Z] || Pad[key_p[KEY_SHOT]])
	{
		button[KEY_SHOT]++;
	}
	else {
		button[KEY_SHOT] = 0;
	}
	if (Key[KEY_INPUT_X] || Pad[key_p[KEY_CANCEL]])
	{
		button[KEY_CANCEL]++;
	}
	else {
		button[KEY_CANCEL] = 0;
	}
	if (Key[KEY_INPUT_SPACE] || Pad[key_p[KEY_PAUSE]])
	{
		button[KEY_PAUSE]++;
	}
	else
	{
		button[KEY_PAUSE] = 0;
	}

	//�ΐ탂�[�h���͂��̃��[�h�ɍ��킹�����͂�p����
	if (padInputMode == epad_pad_pad)
	{
		//1P�̃Q�[���p�b�h
		if (Pad[key_p[KEY_DOWN]])
		{
			button1P[KEY_DOWN]++;
		}
		else {
			button1P[KEY_DOWN] = 0;
		}
		if (Pad[key_p[KEY_LEFT]])
		{
			button1P[KEY_LEFT]++;
		}
		else {
			button1P[KEY_LEFT] = 0;
		}
		if (Pad[key_p[KEY_RIGHT]])
		{
			button1P[KEY_RIGHT]++;
		}
		else {
			button1P[KEY_RIGHT] = 0;
		}
		if (Pad[key_p[KEY_UP]])
		{
			button1P[KEY_UP]++;
		}
		else {
			button1P[KEY_UP] = 0;
		}

		//�L�[�R���t�B�O�ŕω�����{�^��
		if (Pad[key_p[KEY_SHOT]])
		{
			button1P[KEY_SHOT]++;
		}
		else {
			button1P[KEY_SHOT] = 0;
		}
		if (Pad[key_p[KEY_CANCEL]])
		{
			button1P[KEY_CANCEL]++;
		}
		else {
			button1P[KEY_CANCEL] = 0;
		}
		if (Pad[key_p[KEY_PAUSE]])
		{
			button1P[KEY_PAUSE]++;
		}
		else
		{
			button1P[KEY_PAUSE] = 0;
		}



		//2P�̃Q�[���p�b�h
		if (Pad2[key_p[KEY_DOWN]])
		{
			button2P[KEY_DOWN]++;
		}
		else {
			button2P[KEY_DOWN] = 0;
		}
		if (Pad2[key_p[KEY_LEFT]])
		{
			button2P[KEY_LEFT]++;
		}
		else {
			button2P[KEY_LEFT] = 0;
		}
		if (Pad2[key_p[KEY_RIGHT]])
		{
			button2P[KEY_RIGHT]++;
		}
		else {
			button2P[KEY_RIGHT] = 0;
		}
		if (Pad2[key_p[KEY_UP]])
		{
			button2P[KEY_UP]++;
		}
		else {
			button2P[KEY_UP] = 0;
		}

		//�L�[�R���t�B�O�ŕω�����{�^��
		if (Pad2[key_p[KEY_SHOT]])
		{
			button2P[KEY_SHOT]++;
		}
		else {
			button2P[KEY_SHOT] = 0;
		}
		if (Pad2[key_p[KEY_CANCEL]])
		{
			button2P[KEY_CANCEL]++;
		}
		else {
			button2P[KEY_CANCEL] = 0;
		}
		if (Pad2[key_p[KEY_PAUSE]])
		{
			button2P[KEY_PAUSE]++;
		}
		else
		{
			button2P[KEY_PAUSE] = 0;
		}
	}
	else if(padInputMode == epad_keyboard_pad) {
		//1P�̃L�[�{�[�h
		if (Key[KEY_INPUT_DOWN])
		{
			button1P[KEY_DOWN]++;
		}
		else {
			button1P[KEY_DOWN] = 0;
		}
		if (Key[KEY_INPUT_LEFT])
		{
			button1P[KEY_LEFT]++;
		}
		else {
			button1P[KEY_LEFT] = 0;
		}
		if (Key[KEY_INPUT_RIGHT])
		{
			button1P[KEY_RIGHT]++;
		}
		else {
			button1P[KEY_RIGHT] = 0;
		}
		if (Key[KEY_INPUT_UP])
		{
			button1P[KEY_UP]++;
		}
		else {
			button1P[KEY_UP] = 0;
		}
		if (Key[KEY_INPUT_Z])
		{
			button1P[KEY_SHOT]++;
		}
		else {
			button1P[KEY_SHOT] = 0;
		}
		if (Key[KEY_INPUT_X])
		{
			button1P[KEY_CANCEL]++;
		}
		else {
			button1P[KEY_CANCEL] = 0;
		}
		if (Key[KEY_INPUT_SPACE])
		{
			button1P[KEY_PAUSE]++;
		}
		else
		{
			button1P[KEY_PAUSE] = 0;
		}



		//2P�̃Q�[���p�b�h
		if (Pad[key_p[KEY_DOWN]])
		{
			button2P[KEY_DOWN]++;
		}
		else {
			button2P[KEY_DOWN] = 0;
		}
		if (Pad[key_p[KEY_LEFT]])
		{
			button2P[KEY_LEFT]++;
		}
		else {
			button2P[KEY_LEFT] = 0;
		}
		if (Pad[key_p[KEY_RIGHT]])
		{
			button2P[KEY_RIGHT]++;
		}
		else {
			button2P[KEY_RIGHT] = 0;
		}
		if (Pad[key_p[KEY_UP]])
		{
			button2P[KEY_UP]++;
		}
		else {
			button2P[KEY_UP] = 0;
		}

		//�L�[�R���t�B�O�ŕω�����{�^��
		if (Pad[key_p[KEY_SHOT]])
		{
			button2P[KEY_SHOT]++;
		}
		else {
			button2P[KEY_SHOT] = 0;
		}
		if (Pad[key_p[KEY_CANCEL]])
		{
			button2P[KEY_CANCEL]++;
		}
		else {
			button2P[KEY_CANCEL] = 0;
		}
		if (Pad[key_p[KEY_PAUSE]])
		{
			button2P[KEY_PAUSE]++;
		}
		else
		{
			button2P[KEY_PAUSE] = 0;
		}
	}
}
