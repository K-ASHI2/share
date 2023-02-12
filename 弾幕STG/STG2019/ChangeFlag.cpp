#include"DxLib.h"
#include"extern.h"
#include"function.h"

//�t���O��ς���֐�
//�t���O���ς�����������ɂ��鏈�������s����
//f:�t���O�̎�� c:�c�J�[�\���̈ʒu �f�t�H���g���� 0 c2:���J�[�\���̈ʒu �f�t�H���g���� 0
void ChangeFlag(enum e_flag f, int c, int c2) {

	//�ŏ��̓t�F�[�h�A�E�g�݂̂��s���A���̌�change_flag2���Ăяo����ăt�F�[�h�C���ƃt���O�̕ύX���s��
	changeFlag_flag = f;
	changeFlag_cursor = c;
	changeFlag_cursor2 = c2;

	//�|�[�Y��ʂ���߂鎞
	if (f == e_gameplay && flag == e_pause) {
		//�~�߂Ă����Ȃ�r������Đ�����
		PlaySoundMem(p_music, DX_PLAYTYPE_LOOP, FALSE);
		PlaybackFlag = 0;
	}

	//�t���O�ɂ���Ă̓t�F�[�h�A�E�g���Ȃ��Ńt���O��ς���
	//�N���A��ʁA�Q�[���I�[�o�[��ʁA�|�[�Y���(�o���藼��)�A
	if (f != e_clear && f != e_gameover && f != e_pause && (f != e_gameplay || flag != e_pause)) {
		fade_flag = ef_fadeOut;
	}
	else {
		ChangeFlag2(changeFlag_flag, changeFlag_cursor, changeFlag_cursor2);
	}
}

//�t�F�[�h�A�E�g��Ɏ��ۂɃt���O��ς��鎞�̏���������֐�
//f:�t���O�̎�� c:�c�J�[�\���̈ʒu �f�t�H���g���� 0 c2:���J�[�\���̈ʒu �f�t�H���g���� 0
void ChangeFlag2(enum e_flag f, int c, int c2) {

	enum e_flag flag2 = flag;	//�ύX�O�̃t���O
	flag = f;
	flagSetFont();	//�t���O���Ƃ̃t�H���g�����߂�

	//�t���O�̓��e���Ƃ̏��������s����
	switch (flag) {
	case e_title:
		SetSelectWindow(4, c);
		switch (flag2) {
		case e_characterselect:
			if (world == ew_extra) {
				cursor = 1;
			}
			else {
				cursor = 0;
			}
			break;
		//case e_practice: cursor = 2; break;
		case e_burragepractice: cursor = 1; break;
		//case e_option: cursor = 4; break;
		//case e_keyconfig: cursor = 2; break;
		case e_soundtest: cursor = 2; break;
		}
		PlayMusic(music.menu);
		break;

	case e_characterselect:
		if (flag2 != e_difficultyselect) {
			cancel_flag = flag2;	//�L�����Z���Ŗ߂��ʂ�ۑ�����
		}
		SetSelectWindow_LR(2, 2, c, c2);
		PlayMusic(music.menu);
		break;

	case e_difficultyselect:
		SetSelectWindow(3, 1);
		PlayMusic(music.menu);
		break;

	case e_gameplay:
		//SetSelectWindow(6, c);
		break;

	case e_clear:
		PlayMusic(music.result, DX_PLAYTYPE_BACK);
		SetSelectWindow(3, 0);
		time = 0;
		break;

	case e_gameover:
		PlayMusic(music.result, DX_PLAYTYPE_BACK);
		SetSelectWindow(3, 0);
		time = 0;
		break;

	case e_pause:
		//�|�[�Y�̌��ʉ���炷
		efs(efs_pause);

		SetSelectWindow(3, c);

		//���y�̒��f
		StopSoundMem(p_music);
		break;

	case e_practice:
		Practice();
		SetSelectWindow(4, c);
		PlayMusic(music.menu);
		break;

	case e_burragepractice:
		BurragePractice();
		SetSelectWindow(9, c);
		PlayMusic(music.menu);
		break;

	case e_option:
		SetSelectWindow(4, c);
		break;

	case e_keyconfig:
		SetSelectWindow(6, c);
		break;

	case e_soundtest:
		SetSelectWindow_LR(7, 2, c, c2);
		break;
	}
}
