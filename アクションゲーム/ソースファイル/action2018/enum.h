//�Q�[�����[�v�̃t���O
enum e_flag {
	e_title,
	e_difficulty_select,
	e_stage_select,
	e_clear,
	e_gameplay,
	e_gameover,
	e_pause,
	e_keyconfig,
};

//�Q�[�����[�h�̃t���O
enum e_mode {
	em_normal,		//�ʏ탂�[�h
	em_end,			//�Q�[�����I������
};

//�t�F�[�h�A�E�g�̃t���O
enum e_fade {
	ef_normal,			//�ʏ탂�[�h
	ef_fadeOut,			//�t���O�ύX���̃t�F�[�h�A�E�g
	ef_fadeOut_door,	//���ړ����̃t�F�[�h�A�E�g
	ef_fadeOut_door2,	//���̉�ʂɐi�ރh�A�̃t�F�[�h�A�E�g
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
	KEY_JUMP,
	KEY_JUMP2,
	KEY_ATTACK,
	KEY_ATTACK2,
	KEY_PAUSE,
};

//���ʉ�
enum e_effectSound {
	efs_attack,		//�U���̌��ʉ�
	efs_select,		//�I���̌��ʉ�
	efs_recover,	//�񕜂̌��ʉ�
	efs_bomb,		//��C���˂̌��ʉ�
	efs_back,		//�L�����Z���̌��ʉ�
	efs_decision,	//����̌��ʉ�
	efs_shot,		//�G�̒e���o�����̉�
};

//�w�i
enum e_background {
	eb_sky,			//��
	eb_cave,		//���A
	eb_darkcave,	//�Â����A
	eb_darkcloud,	//�É_
	eb_line,		//���Ɛ��F�̃��C��
	eb_orange,		//�I�����W
	eb_check,		//�`�F�b�N
};
