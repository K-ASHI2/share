#include"DxLib.h"
#include"extern.h"
#include"function.h"
#include"block.h"

//�|�[�Y���
void CMenuWindow::pause()
{
	selectWindow(1);
	if (keyPad.getButton(KEY_CANCEL) == 1 || keyPad.getButton(KEY_PAUSE) == 1)
	{
		changeFlag(e_gameplay);
		PlaybackFlag = 1;
		music.efs(efs_back);
	}

	if (keyPad.getButton(KEY_SHOT) == 1)
	{
		music.efs(efs_decision);
		switch (cursor)
		{
		case 0:
			changeFlag(e_gameplay);
			//�|�[�Y��ʂ��烊�g���C�ȊO�Ŗ߂��Ă���ꍇ
			//�t�F�[�h�C����ɉ��y��r������Đ�����t���O��1�ɂ���
			PlaybackFlag = 1;
			break;
		case 1:
			//�����Ȃ��I�΂�Ă����Ȃ��悤�Ɏ~�߂��Ȃ��ŏ�����̍Đ���Ԃɂ���
			PlaySoundMem(music.getPlayingMusic(), DX_PLAYTYPE_LOOP, TRUE);

			//�ŏ�����ɂ���
			changeFlag(e_start);
			init();
			break;
		case 2: 
			changeFlag(e_title);
			break;
		}
	}
}

//�|�[�Y��ʂ̕`��
void CMenuWindow::drawPause()
{
	SetDrawBright(96, 96, 96);
	drawPlay();		//�Q�[���v���C���̕`��
	SetDrawBright(255, 255, 255);

	const static int silver = font.getSilver();
	const static int litegreen = font.getLiteGreen();
	drawColor(307, 180, "COUTINUE", 0, silver, litegreen);
	drawColor(337, 230, "RETRY", 1, silver, litegreen);
	drawColor(337, 280, "TITLE", 2, silver, litegreen);
}
