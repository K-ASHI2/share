#include"DxLib.h"
#include"extern.h"
#include"function.h"

//�t�F�[�h�A�E�g
void CMenuWindow::fadeOut()
{
	bright -= 32;
	if (bright <= 0)
	{
		bright = 0;
		changeFlag2(changeFlag_flag, changeFlag_cursor, changeFlag_cursor2);
		fadeFlag = ef_fadeIn;
	}
	SetDrawBright(bright, bright, bright);
}

//�t�F�[�h�C��
void CMenuWindow::fadeIn()
{
	bright += 32;
	if (bright >= 256)
	{
		bright = 256;
		fadeFlag = ef_normal;
		//���f�������y������A�ĊJ����Ȃ�
		if (PlaybackFlag == 1)
		{
			//�~�߂Ă����Ȃ�r������Đ�����
			PlaySoundMem(music.getPlayingMusic(), DX_PLAYTYPE_LOOP, FALSE);
			PlaybackFlag = 0;
		}

		//���f�����Ȃ��ŏ����痬���Ȃ�
		else if (PlaybackFlag == 2)
		{
			//�~�߂Ă����Ȃ��ŏ�����Đ�����
			PlaySoundMem(music.getPlayingMusic(), DX_PLAYTYPE_LOOP, TRUE);
			PlaybackFlag = 0;
		}
	}
	SetDrawBright(bright, bright, bright);
}
