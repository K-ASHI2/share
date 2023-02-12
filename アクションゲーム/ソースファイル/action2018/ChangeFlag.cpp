#include"DxLib.h"
#include"extern.h"
#include"function.h"
#include"math.h"

//�t���O��ς���֐�
//�t���O���ς�����������ɂ��鏈�������s����
//f:�t���O�̎�� c:�c�J�[�\���̈ʒu �f�t�H���g���� 0 c2:���J�[�\���̈ʒu �f�t�H���g���� 0
void change_flag(enum e_flag f, int c, int c2) {

	//�ŏ��̓t�F�[�h�A�E�g�݂̂��s���A���̌�change_flag2���Ăяo����ăt�F�[�h�C���ƃt���O�̕ύX���s��
	fade_flag = ef_fadeOut;
	changeFlag_flag = f;
	changeFlag_cursor = c;
	changeFlag_cursor2 = c2;

}

//�t�F�[�h�A�E�g��Ɏ��ۂɃt���O��ς���֐�
//f:�t���O�̎�� c:�c�J�[�\���̈ʒu �f�t�H���g���� 0 c2:���J�[�\���̈ʒu �f�t�H���g���� 0
void change_flag2(enum e_flag f, int c, int c2) {

	enum e_flag flag2 = flag;	//�ύX�O�̃t���O
	flag = f;
	switch (flag) {	//�t���O�̓��e���Ƃ̏��������s����
	case e_title:
		mode_flag = em_normal;
		PlayMusic(music.menu);
		set_select_window(2, c);
		break;

	case e_stage_select:

		//��Փx�I���ȊO����X�e�[�W�I���ɓ������猳�̃t���O��ۑ�����
		if (flag2 != e_difficulty_select) {
			cancel_flag = flag2;
		}

		PlayMusic(music.menu);
		set_select_window_LR(4, 4, c, c2);	//�c���ɓ�������I����ʂ̐ݒ�
		break;

	case e_difficulty_select:
		set_select_window(3, c);
		break;

	case e_gameplay:

		//�N���A��ʂ���Q�[���v���C��ʂɖ߂������ɃG���A��ς���
		if (flag2 == e_clear) {
			if (mapload % 1000 % 100 >= 40) {
				mapload = mapload / 100 * 100 + 111;//���̃��[���h��
			}
			else {
				mapload = mapload / 10 * 10 + 11;//���̃G���A��
			}
		}

		//�|�[�Y��ʂ���߂鎞�ȊO�̓X�e�[�W������������
		if (flag2 != e_pause) {
			ReadMap();
			PlayMusic(s_music[music_n]);	//���y���w�肳�ꂽ���y�ɂ���
			init();
			init_l();	//hp�̏�����
		}
		break;

	case e_clear:
		PlayMusic(music.clear, 0);
		break;

	case e_gameover:
		PlayMusic(music.gameover, 0);

		//�Q�[���I�[�o�[��ʂ������ɏ����Ȃ��悤�ɂ��邽�ߗ�O�I�ɂ����ŕ`�悷��
		ClearDrawScreen();
		DrawGraph(0, 0, img.gameover, TRUE);	//�Q�[���I�[�o�[��ʂ�`��
		ScreenFlip();
		break;

	case e_pause:
		PlaySoundMem(music.pause, DX_PLAYTYPE_BACK);	//efm�ɏC������
		set_select_window(3, c);
		break;

		/*case option:
		set_select_window(4, c);
		break;*/

	case e_keyconfig:
		set_select_window(6, c);
		break;

		/*case e_soundtest:
		set_select_window(10, c);
		break;*/
	}
}
