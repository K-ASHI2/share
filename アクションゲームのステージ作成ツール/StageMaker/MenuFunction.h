/*���j���[�֐�*/

//�R�[���o�b�N
LRESULT CALLBACK MyWndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
//�}�b�v�t�@�C�����J���_�C�A���O�{�b�N�X
int MapFileOpen(HWND hWnd, char **pass);
//�}�b�v��ۑ�����_�C�A���O�{�b�N�X
int MapFileSave(HWND hWnd, char **pass);
//�摜�t�@�C�����J���_�C�A���O�{�b�N�X
int ImgFileOpen(HWND hWnd);

//�I����ʂ�ݒ肷�� n:���ڐ� c:�J�[�\���̈ʒu �f�t�H���g���� 0
void SetSelectWindow(int n, int c = 0);
//�I����ʂ�ݒ肷�� n:�c�̍��ڐ� n2:���̍��ڐ� c:�c�J�[�\���̈ʒu �f�t�H���g���� 0 c2:���J�[�\���̈ʒu �f�t�H���g���� 0
void SetSelectWindow_LR(int n,  int n2, int c = 0, int c2 = 0);
//�I����ʂ̑���
void SelectWindow();
//�I����ʂ̉�����
void SelectWindow_LR();	
//f:�t���O�̎�� c:�c�J�[�\���̈ʒu default 0  c2:���J�[�\���̈ʒu default 0
void ChangeFlag(enum e_flag f, int c = 0, int c2 = 0);
//�t�F�[�h�A�E�g��Ɏ��ۂɃt���O��ς��鎞�̏���������֐�
void ChangeFlag2(enum e_flag f, int c = 0, int c2 = 0);
//�|�[�Y
void Pause();
//�L�[���͂̍X�V
void UpdateKey();
//�t���O�ύX���̃t�F�[�h�A�E�g
void FadeOut();
//�t�F�[�h�C��
void FadeIn();
