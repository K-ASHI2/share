/*�X�e�[�W�쐬�݂̂ɗp����֐�*/
//�X�e�[�W�쐬���̃X�N���[���o�[�̈ړ�
void MoveScrollBar();
//���j���[�̕ύX
void CSChangeMenu();
//�֎~�����u���������Ă�����1��Ԃ��֐�
int ProhibitCheck();
//�}�b�v�̕ۑ�
void SaveMap();
//�}�b�v����O�̏�Ԃɖ߂�
void UndoMap();
//�}�b�v������̏�Ԃɖ߂�
void RedoMap();
//�I�𒆂̕���؂���
void TrimmingMap();
//�I�𒆂̕����R�s�[����
void CopyMap();
//�I�𒆂̕���\��t����
void PasteMap();
//�I�𒆂̕�����������
void DeleteMap();
//��ʃT�C�Y�̕ύX
bool ChangeMapSize(int x, int y, int width, int height);
//�}�b�v�̕ύX�̗�����ۑ�����
void BackUp();

//�ҏW�\�ȉ�ʓ��̕������߂ĕԂ�
int GetDrawWidth();
//�ҏW�\�ȉ�ʓ��̍��������߂ĕԂ�
int GetDrawHeight();

//�󂯎��������x��n���ڂ�f�̐����ɏ��������ĕԂ�
int FigureChange(int x, int n, int f);

/*�{�^������*/
//X���W,Y���W,�����̐�,�����̐�,�F �������ɍ����T�C�Y�̃{�^���𐶐�����
void DrawButton(int x, int y, int s, int n, unsigned int Color);
//�����̃{�^���̏��� ���W�Ɛ������󂯎�肻�̍��W�Ɛ�����\������
void DrawButton2(int x, int y, const char *c);
//���E�̃{�^���̏��� ���W�ƕ����Ɖ��Ԗڂ����󂯎�肻�̍��W�ƕ�����\������
void DrawButton3(int x, int y, const char *c, int b);
//�����`�̃{�^�������
int DrawButton4(int x, int y);
//�傫�����ςȃ{�^�������
int DrawButton4(int x, int y, int size_x, int size_y);
//���W�A�摜�A�������󂯎���ĕ`�悷��
void DrawCreate(int x, int y, int GrHandle, int d);
//�{�^����xy���W�A�����̐��A�����̐����󂯎�艟����Ă��Ȃ����0�A������Ă����1��Ԃ�
int JudgeMouse(int x, int y, int s, int n);
//�{�^����4�̒��_�̍��W���󂯎��A������Ă��Ȃ����0�A������Ă����1��Ԃ�
int JudgeMouse2(int x1, int y1, int x2, int y2);
//�{�^����xy���W�A�����̐��A�����̐����󂯎��}�E�X�̕ς���sx��sy�Ŕ��肷��
int JudgeMouse3(int x, int y, int s, int n);
//�{�^����xy���W�A�����̐��A�����̐����󂯎��1�t���[���O�̃}�E�X�̍��W�Ŕ��肷��
int JudgeMouse4(int x, int y, int s, int n);