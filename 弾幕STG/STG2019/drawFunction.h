/*�`��֌W�֐�*/
void Draw();
//�Q�[���v���C���̉�ʂ̕`��
void DrawPlay();
//�^�C�g����ʂ̕`��
void DrawTitle();
//�L�����N�^�[�I����ʂ̕`��
void DrawCharacterSelect();
//��Փx�I����ʂ̕`��
void DrawDifficultySelect();
//�v���N�e�B�X�̕`��
void DrawPractice();
//�e���v���N�e�B�X�̕`��
void DrawBulletPractice();
//�I�v�V�����̕`��
void DrawOption();
//�L�[�R���t�B�O�̕`��
void DrawKeyConfig();
//�|�[�Y��ʂ̕`��
void DrawPause();
//�N���A��ʂ̕`��
void DrawClear();
//�Q�[���I�[�o�[��ʂ̕`��
void DrawGameover();
//���ł��邱�Ƃ��m�肵�Ă���G��e�ɑ΂��ď��ŃG�t�F�N�g��`�悷��B
void DrawVanished();
//�w�i�̕`��
void DrawBackGround();
//�Q�[���v���C���̉�ʊO�̕`��
void DrawPlayWindow();
//�T�E���h�e�X�g�̕`��
void DrawSoundTest();
//HP�o�[�̕`��
void DrawHPBar();
//�����̃o�[�̕`��
void DrawElementBar();
//�G�̗̑͂ɉ�����HP�o�[�̐F��Ԃ��֐�
int GetHPColor(int hp, int maxhp);
//��������̕`��
void DrawEx();
//x���W,y���W,������A���Ԗڂ��������Ƃ��A�J�[�\���̈ʒu�������Ȃ�ԁA�Ⴄ�Ȃ獕�ŕ`�悷��֐�
void DrawRed(int x, int y, const char *String, int c);
//x���W,y���W,������A�c���ɉ��Ԗڂ��������Ƃ��A�J�[�\���̈ʒu�������Ȃ�ԁA�Ⴄ�Ȃ獕�ŕ`�悷��֐�
void DrawRed2(int x, int y, const char *String, int c, int c2);
//x���W,y���W,������A�c�ɉ��Ԗڂ��������Ƃ��A�J�[�\���̈ʒu�������Ȃ�C_Color��C_EdgeColor�A�Ⴄ�Ȃ�N_Color��N_EdgeColor�ŕ`�悷��֐�
void DrawColor(int x, int y, const char *String, int c, unsigned int N_Color, unsigned int C_Color, unsigned int N_EdgeColor = 0U, unsigned int C_EdgeColor = 0U);
