#include"DxLib.h"
#include"extern.h"
#include"function.h"

void Pause() {

	SelectWindow(1);
	if (button[KEY_BOMB] == 1 || button[KEY_PAUSE] == 1) {
		ChangeFlag(e_gameplay);
		PlaybackFlag = 1;
		efs(efs_back);
	}
	if (button[KEY_SHOT] == 1) {
		efs(efs_decision);
		switch (cursor) {
		case 0:
			ChangeFlag(e_gameplay);
			//�|�[�Y��ʂ��烊�g���C�ȊO�Ŗ߂��Ă���ꍇ
			//�t�F�[�h�C����ɉ��y��r������Đ�����t���O��1�ɂ���
			PlaybackFlag = 1;
			break;
		case 1:
			//�ŏ�����ɂ��� �`���v�^�[���ŏ��ɖ߂�
			ChangeFlag(e_gameplay);
			init();
			//�|�[�Y��ʂ��烊�g���C�Ŗ߂��Ă���ꍇ
			//�t�F�[�h�C����ɉ��y���ŏ�����Đ�����t���O��1�ɂ���
			PlaybackFlag = 2;
			break;
		case 2: 
			ChangeFlag(e_title);
			break;
		}
	}
}

//�|�[�Y��ʂ̕`��
void DrawPause() {

	SetDrawBright(128, 128, 128);
	DrawBackGround();	//�w�i�̕`��
	DrawPlay();		//�Q�[���v���C���̕`��
	SetDrawBright(255, 255, 255);

	//DrawGraph(200, 150, img.pause_frame, FALSE);
	DrawColor(307, 180, "COUTINUE", 0, black, white);
	DrawColor(337, 230, "RETRY", 1, black, white);
	DrawColor(337, 280, "TITLE", 2, black, white);
	//DrawGraph(60, 98 + cursor * 80, img.arrow, TRUE);    //���̕`��
}
