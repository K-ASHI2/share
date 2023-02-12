#pragma once
//���[�v�Ǘ��̃t���O
//��̑I����ʂɂ�����
//�Q�[���v���C���̃t���O�͕ʂɍ��
enum e_flag
{
	e_title,
	e_movemenu,
	e_operationmenu,
	e_start,
	e_gameplay,
	e_clear,
	e_win,
	e_pause,
	e_keyconfig,
	e_manual,
};

enum e_color
{
	//ec_black = -2,
	ec_white = -1,
	ec_null,
	ec_blue,
	ec_red,
	ec_green,
	ec_yellow,
	ec_purple,
};

//�Q�[�����[�h�̃t���O
enum e_mode
{
	em_score_attack,	//�X�R�A�A�^�b�N���[�h
	em_vs,	//�ΐ탂�[�h
	em_end,			//�Q�[�����I������
};

//�t�F�[�h�A�E�g�̃t���O
enum e_fade
{
	ef_normal,			//�ʏ탂�[�h
	ef_fadeOut,			//�t���O�ύX���̃t�F�[�h�A�E�g
	ef_fadeIn,			//�t�F�[�h�C��
};

//���ۂ̃Q�[���Ŏg���{�^��
//�L�[�{�[�h�ƃQ�[���p�b�h�̓��̗͂����ɑΉ����A
//�L�[�R���t�B�O�Őݒ��̓{�^�����ω�����
//�����̃{�^������ς������͎Q�Ƃ������̂ŕK���L�[�R���t�B�O������
enum e_key
{
	KEY_DOWN,
	KEY_LEFT,
	KEY_RIGHT,
	KEY_UP,
	KEY_SHOT,
	KEY_CANCEL,
	KEY_PAUSE,
};

//���ʉ�
enum e_effectSound
{
	efs_draw,
	efs_vanish,
	efs_select,		//�I���̌��ʉ�
	efs_back,		//�L�����Z���̌��ʉ�
	efs_result,
	efs_decision,	//����̌��ʉ�
	efs_pause,
};

//����(0:�� 1:�E 2:�� 3:�� 4:���̏ꏊ 5:����)
enum e_direction
{
	ed_up,
	ed_right,
	ed_down,
	ed_left,
	ed_noMove,
	ed_null,
};

//������@
enum e_cpuMove
{
	ec_player,
	ec_random,
	ec_move_random,
	ec_search,
	ec_strong,
};

//
enum e_player
{
	e_1p,
	e_2p,
};

//���̗����ł̐F�u���b�N�̗������@
enum e_nextDropMode
{
	endm_normal,
	endm_center,
};

//
enum e_padInputMode
{
	epad_pad_pad,
	epad_keyboard_pad,
};
