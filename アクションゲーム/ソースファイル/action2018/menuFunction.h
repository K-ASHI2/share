/*���j���[�֐�*/
//�I����ʂ�ݒ肷�� n:���ڐ� c:�J�[�\���̈ʒu �f�t�H���g���� 0
void set_select_window(int n, int c = 0);
//�I����ʂ�ݒ肷�� n:�c�̍��ڐ� n2:���̍��ڐ� c:�c�J�[�\���̈ʒu �f�t�H���g���� 0 c2:���J�[�\���̈ʒu �f�t�H���g���� 0
void set_select_window_LR(int n,  int n2, int c = 0, int c2 = 0);
//�I����ʂ̑���
void select_window();
//�I����ʂ̉�����
void select_window_LR();	
//f:�t���O�̎�� c:�c�J�[�\���̈ʒu default 0  c2:���J�[�\���̈ʒu default 0
void change_flag(enum e_flag f, int c = 0, int c2 = 0);
//�t�F�[�h�A�E�g��Ɏ��ۂɃt���O��ς��鎞�̏���������֐�
void change_flag2(enum e_flag f, int c = 0, int c2 = 0);
//�^�C�g����ʂ̃��j���[
void title();	
//�Q�[���I�[�o�[���
void gameover();
//�N���A���
void clear();
//�X�e�[�W�I�����
void stage_select();
//��Փx�I�����
void difficulty_select();
//�|�[�Y���
void pause();
//�X�e�[�W����̃|�[�Y
void createPause();
//�L�[���͂̍X�V
void updateKey();
//�t���O�ύX���̃t�F�[�h�A�E�g
void fadeOut();
//�h�A�̈ړ��̃t�F�[�h�A�E�g
void fadeOut_door();
//���̉�ʂɐi�ރh�A�̃t�F�[�h�A�E�g
void fadeOut_door2();
//�t�F�[�h�C��
void fadeIn();
