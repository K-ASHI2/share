#include"DxLib.h"
#include"extern.h"
#include"function.h"

//�t���O��ς���֐�
//�t���O���ς�����������ɂ��鏈�������s����
//f:�t���O�̎�� c:�c�J�[�\���̈ʒu �f�t�H���g���� 0 c2:���J�[�\���̈ʒu �f�t�H���g���� 0
void CMenuWindow::changeFlag(e_flag f, int c, int c2)
{
	//�ŏ��̓t�F�[�h�A�E�g�݂̂��s���A���̌�change_flag2���Ăяo����ăt�F�[�h�C���ƃt���O�̕ύX���s��
	changeFlag_flag = f;
	changeFlag_cursor = c;
	changeFlag_cursor2 = c2;

	//�|�[�Y��ʂ���߂鎞
	if (f == e_gameplay && flag == e_pause)
	{
		//�~�߂Ă����Ȃ�r������Đ�����
		PlaySoundMem(music.getPlayingMusic(), DX_PLAYTYPE_LOOP, FALSE);
		PlaybackFlag = 0;
	}

	//�t���O�ɂ���Ă̓t�F�[�h�A�E�g���Ȃ��Ńt���O��ς���
	//�N���A��ʁA�|�[�Y���(�o���藼��)�A�Q�[���J�n��(�o���藼��)
	if (f != e_clear && f != e_pause && f != e_start && (f != e_gameplay || flag != e_pause || flag != e_start))
	{
		fadeFlag = ef_fadeOut;
	}
	else
	{
		changeFlag2(changeFlag_flag, changeFlag_cursor, changeFlag_cursor2);
	}
}

//�t�F�[�h�A�E�g��Ɏ��ۂɃt���O��ς��鎞�̏���������֐�
//f:�t���O�̎�� c:�c�J�[�\���̈ʒu �f�t�H���g���� 0 c2:���J�[�\���̈ʒu �f�t�H���g���� 0
void CMenuWindow::changeFlag2(enum e_flag f, int c, int c2)
{
	const e_flag flag2 = flag;	//�ύX�O�̃t���O
	flag = f;
	flagSetFont();	//�t���O���Ƃ̃t�H���g�����߂�

	//�t���O�̓��e���Ƃ̃t���O�ύX���̏��������s����
	switch (flag)
	{
	case e_title:
		setSelectWindow(6, c);
		cursor = cancel_cursor;
		/*switch (flag2)
		{
		case e_keyconfig: cursor = 2; break;
		}*/
		music.playMenu();
		break;

	case e_movemenu:
		setSelectWindow(5, c);
		break;

	case e_operationmenu:
		setSelectWindow(3, c);
		break;

	case e_start:
		stageStartCount = 175;
		stageStartFlag = false;
		break;

	case e_gameplay:
		break;

	case e_clear:
		StopSoundMem(music.getPlayingMusic());
		music.efs(efs_result);
		clear_count = 0;
		//�n�C�X�R�A���X�V���Ă�����L�^����
		if (hiscore_flag)
		{
			writeHiscore();
		}
		break;

	case e_win:
		StopSoundMem(music.getPlayingMusic());
		music.efs(efs_result);
		clear_count = 0;
		break;

	case e_pause:
		//�|�[�Y�̌��ʉ���炷
		music.efs(efs_pause);

		setSelectWindow(3, c);

		//���y�̒��f
		StopSoundMem(music.getPlayingMusic());
		break;

	case e_keyconfig:
		setSelectWindow(5, c);
		break;

	case e_manual:
		setSelectWindow(6, c);
		break;
	}
}
