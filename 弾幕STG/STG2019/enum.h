//���[�v�Ǘ��̃t���O
//��̑I����ʂɂ�����
//�Q�[���v���C���̃t���O�͕ʂɍ��
enum e_flag {
	e_title,
	e_characterselect,
	e_difficultyselect,
	e_gameplay,
	e_gameover,
	e_clear,
	e_pause,
	e_practice,
	e_burragepractice,
	e_option,
	e_keyconfig,
	e_soundtest,
};

//�e�̎��(�O��)
enum eb_kind {
	ebk_blue_S,		//���e
	ebk_red_S,		//�ԏ��e
	ebk_yellow_S,	//�����e
	ebk_blue_M,		//���e
	ebk_red_M,		//�Ԓ��e
	ebk_yellow_M,	//�����e
	ebk_blue_L,		//��e
	ebk_red_L,		//�ԑ�e
	ebk_yellow_L,	//����e
	ebk_snow_S,		//�Ꮼ�e
	ebk_snow_M,		//�ᒆ�e
	ebk_fire_S,		//�����e
	ebk_fire_M,		//�����e
	ebk_thunder,	//���e
	ebk_star,		//���e
	ebk_star_red,	//�Ԑ��e
	ebk_star_blue,	//���e
};

//�e�̐F(���Ŏ��Ɏg�p)
enum eb_color {
	ebc_blue,
	ebc_red,
	ebc_yellow,
	ebc_null,
};

//�A�C�e���̎��(�O��)
enum ei_kind {
	eik_power_S,	//��P
	eik_power_L,	//��P
	eik_power_F,	//�t���p���[�A�C�e��
	eik_score_S,	//���_�A�C�e��(��)
	eik_score,		//���_�A�C�e��
	eik_bomb,		//�{���A�C�e��
	eik_life,		//�G�N�X�e���h�A�C�e��
};

//��Փx�̃t���O
enum e_difficulty {
	ed_easy,
	ed_normal,
	ed_hard,
	ed_lunatic,
};

//�X�e�[�W
enum e_stage {
	es_title,	//�T�E���h�e�X�g�Ń^�C�g���Ȃ𗬂���悤�ɂ���
	es_1_1,
	es_1_2,
	es_2_1,
	es_2_2,
	es_3_1,
	es_3_2,
	es_4_1,
	es_4_2,
	es_e_1,
	es_e_2,
};

//���[���h
enum e_world {
	ew_1,
	ew_2,
	ew_3,
	ew_4,
	ew_extra,
};

enum e_bossflag {
	eb_way,		//����
	eb_boss,	//�{�X
};

//�Q�[�����[�h�̃t���O
enum e_mode {
	em_normal,		//�ʏ탂�[�h
	em_practice,	//�v���N�e�B�X
	em_burragepractice,	//�X�y���v���N�e�B�X
	em_end,			//�Q�[�����I������
};

//�t�F�[�h�A�E�g�̃t���O
enum e_fade {
	ef_normal,			//�ʏ탂�[�h
	ef_fadeOut,			//�t���O�ύX���̃t�F�[�h�A�E�g
	ef_fadeIn,			//�t�F�[�h�C��
};

//���ۂ̃Q�[���Ŏg���{�^��
//�L�[�{�[�h�ƃQ�[���p�b�h�̓��̗͂����ɑΉ����A
//�L�[�R���t�B�O�Őݒ��̓{�^�����ω�����
enum e_key {
	KEY_DOWN,
	KEY_LEFT,
	KEY_RIGHT,
	KEY_UP,
	KEY_SHOT,
	KEY_BOMB,
	KEY_SLOW,
	KEY_PAUSE,
};

//���ʉ�
enum e_effectSound {
	efs_shot,		//�U���̌��ʉ�
	efs_select,		//�I���̌��ʉ�
	efs_recover,	//�񕜂̌��ʉ�
	efs_bomb,		//��C���˂̌��ʉ�
	efs_p_bomb,		//��C���˂̌��ʉ�
	efs_back,		//�L�����Z���̌��ʉ�
	efs_result,
	efs_decision,	//����̌��ʉ�
	efs_damage,
	efs_boss_crush,
	efs_pause,
};
