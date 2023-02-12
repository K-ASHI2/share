#include "KeyPad.h"
#include "define.h"
#include "enum.h"

CKeyPad::CKeyPad()
{
}

CKeyPad::~CKeyPad()
{
}

int CKeyPad::getButton(int key)
{
	return button[key];
}

int CKeyPad::getButton1P(int key)
{
	return button1P[key];
}

int CKeyPad::getButton2P(int key)
{
	return button2P[key];
}

//キーボードの入力を直接受け取る(enumにあてはめてない方)
int CKeyPad::getKey(int keyInput)
{
	return Key[keyInput];
}

int CKeyPad::getPad(int padInput)
{
	return Pad[padInput];
}

char* CKeyPad::getCPad(int key)
{
	return cPad[key];
}

//カーソルの位置のボタンのキーコンフィグを変更する
void CKeyPad::setKeyConfig(int cursor)
{
	//十字キー以外のボタンに対して設定する
	for (int i = 4; i <= 15; i++)
	{
		if (Pad[i] == 1)
		{
			int button = cursor + 4;
			int k = key_p[cursor + 4];	//元々のボタンを保存する
			key_p[cursor + 4] = i;
			switch (key_p[cursor + 4])
			{
			case PAD_A:		cPad[button] = "PAD_A";			break;
			case PAD_B:		cPad[button] = "PAD_B";			break;
			case PAD_X:		cPad[button] = "PAD_X";			break;
			case PAD_Y:		cPad[button] = "PAD_Y";			break;
			case PAD_LB:	cPad[button] = "PAD_LB";		break;
			case PAD_RB:	cPad[button] = "PAD_RB";		break;
			case PAD_LT:	cPad[button] = "PAD_LT";		break;
			case PAD_RT:	cPad[button] = "PAD_RT";		break;
			case PAD_BACK:	cPad[button] = "PAD_BACK";		break;
			case PAD_START: cPad[button] = "PAD_START";		break;
			default:		cPad[button] = "使用できません"; break;
			}

			//すでに他のボタンとして使われていたなら入れ替える
			for (int j = 4; j <= 7; j++)
			{
				if (key_p[j] == i && j != button)
				{
					key_p[j] = k;
					switch (key_p[j])
					{
					case PAD_A:		cPad[j] = "PAD_A";			break;
					case PAD_B:		cPad[j] = "PAD_B";			break;
					case PAD_X:		cPad[j] = "PAD_X";			break;
					case PAD_Y:		cPad[j] = "PAD_Y";			break;
					case PAD_LB:	cPad[j] = "PAD_LB";			break;
					case PAD_RB:	cPad[j] = "PAD_RB";			break;
					case PAD_LT:	cPad[j] = "PAD_LT";			break;
					case PAD_RT:	cPad[j] = "PAD_RT";			break;
					case PAD_BACK:	cPad[j] = "PAD_BACK";		break;
					case PAD_START: cPad[j] = "PAD_START";		break;
					default:		cPad[j] = "使用できません"; break;
					}
					break;
				}
			}
			break;
		}
	}
}

//キーボードとゲームパッドの入力の初期化
void CKeyPad::init_key() {

	for (int i = 0; i < 256; i++) {
		Key[i] = 0;
	}

	for (int i = 0; i < 28; i++) {
		Pad[i] = 0;
	}
}

//ゲームパッドのキーコンフィグの初期化
//ゲームループ開始前とコンフィグのリセットで呼び出す
void CKeyPad::init()
{
	key_p[KEY_DOWN] = PAD_DOWN;
	key_p[KEY_LEFT] = PAD_LEFT;
	key_p[KEY_RIGHT] = PAD_RIGHT;
	key_p[KEY_UP] = PAD_UP;
	key_p[KEY_SHOT] = PAD_B;
	key_p[KEY_CANCEL] = PAD_A;
	key_p[KEY_PAUSE] = PAD_START;

	cPad[KEY_DOWN] = "PAD_DOWN";
	cPad[KEY_LEFT] = "PAD_LEFT";
	cPad[KEY_RIGHT] = "PAD_RIGHT";
	cPad[KEY_UP] = "PAD_UP";
	cPad[KEY_SHOT] = "PAD_B";
	cPad[KEY_CANCEL] = "PAD_A";
	cPad[KEY_PAUSE] = "PAD_START";
}
