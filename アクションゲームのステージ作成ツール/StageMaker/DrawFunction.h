/*�`��֐�*/
//1�t���[�����̕`��
void Draw();
//�X�e�[�W�̕`��
void DrawStage();
//�w�i�̕`��
void DrawBackground();
//�w�肵�����Ԃ�����ʂ��؂�ւ�鎞�ɐ^���Âɂ���
void BlackScreen(int t);
//x���W,y���W,������A���Ԗڂ��������Ƃ��A�J�[�\���̈ʒu�������Ȃ�ԁA�Ⴄ�Ȃ獕�ŕ`�悷��֐�
void DrawRed(int x, int y, const TCHAR *String, int c);
//x���W,y���W,������A�c���ɉ��Ԗڂ��������Ƃ��A�J�[�\���̈ʒu�������Ȃ�ԁA�Ⴄ�Ȃ獕�ŕ`�悷��֐�
void DrawRed2(int x, int y, const TCHAR *String, int c, int c2);

//���j���[�̕`��
void DrawCSMenu();
//�X�e�[�W�쐬�̃}�b�v�̕`��
void DrawMap();
//�}�b�v�̒l���󂯎���ĕ\������
void DrawMapThings(int x, int y, int map);
//�}�b�v�̉��ɕ`�悵�������̂�`�悷��
void DrawMapThings2(int x, int y, int map);
//�}�b�v�̎�O�ɕ`�悵�������̂�`�悷��
void DrawMapThings3(int x, int y, int map);
//�}�b�v�̂���Ɏ�O�ɕ`�悵�������̂�`�悷��
void DrawMapThings4(int x, int y, int map);
//���W�A�摜���󂯎���ĕ`�悷��
void MapDrawExtendGraph(int x1, int y1, int GrHandle, int TransFlag);
//���W�A�摜�A���߃t���O���󂯎���ĕ`�悷��
void MapDrawExtendGraph(int x1, int y1, int GrHandle);
//���W�A�摜�Ɠ��߃t���O���󂯎���Ēu�����̉摜��`�悷��
void DrawSelectThing(int x1, int y1, int GrHandle, bool turn, int TransFlag = TRUE);
//���W�A�摜���󂯎���Ēu�����̉摜��`�悷��
void DrawSelectThing(int x1, int y1, int GrHandle);
//���W�A�摜(�A���߃t���O)���󂯎���Ēu�����̉摜�𔽓]���ĕ`�悷��
void DrawTurnSelectThing(int x1, int y1, int GrHandle, int TransFlag = TRUE);
