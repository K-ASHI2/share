/*���j���[�֐�*/
//�I����ʂ�ݒ肷�� n:���ڐ� c:�J�[�\���̈ʒu �f�t�H���g���� 0
void SetSelectWindow(int n, int c = 0);
//�I����ʂ�ݒ肷�� n:�c�̍��ڐ� n2:���̍��ڐ� c:�c�J�[�\���̈ʒu c2:���J�[�\���̈ʒu
void SetSelectWindow_LR(int n, int n2, int c = 0, int c2 = 0);
//�I����ʂ̏c���� mode:1�Ȃ牟�������Ĉړ����Ȃ� �f�t�H���g���� 0
void SelectWindow(int mode = 0);	
//�I����ʂ̉�����
void SelectWindow_LR();
//�^�C�g�����
void Title();
//�L�����I�����
void CharacterSelect();
//��Փx�I��
void DifficultySelect();
//�|�[�Y���
void Pause();
//�Q�[���I�[�o�[���
void GameOver();
//�N���A���
void Clear();
//�v���N�e�B�X
void Practice();
//�e���v���N�e�B�X
void BurragePractice();
//�I�v�V����
void Option();
//�L�[�R���t�B�O
void KeyConfig();
//�T�E���h�e�X�g
void SoundTest();
//f:�t���O�̎�� c:�c�J�[�\���̈ʒu default 0  c2:���J�[�\���̈ʒu default 0
void ChangeFlag(enum e_flag f, int c = 0, int c2 = 0);
//�t�F�[�h�A�E�g��Ɏ��ۂɃt���O��ς��鎞�̏���������֐�
void ChangeFlag2(enum e_flag f, int c = 0, int c2 = 0);
//�t���O���Ƃ̃t�H���g�����߂�
void flagSetFont();


