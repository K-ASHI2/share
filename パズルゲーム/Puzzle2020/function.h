#include"DxLib.h"
#include<vector>

/*�Q�[�������֐�*/
//�����̍X�V
void update();
//�n�C�X�R�A���t�@�C������ǂݍ��ފ֐�
void loadHiscore();
//�n�C�X�R�A���t�@�C���ɏ������ފ֐�
void writeHiscore();
//�Z�[�u�f�[�^��������΍쐬����֐�
void createSaveFile();

/*�������֐�*/
//���[�h����֐�
void load();
//�摜�����[�h����֐�
void loadImage();
//�������֐��̓����
void init();
//�t���O���Ƃ̃t�H���g�����߂�
void flagSetFont();

/*�`��֌W�֐�*/
void draw();
//�Q�[���v���C���̉�ʂ̕`��
void drawPlay();
//�w�i�̕`��
void drawBackGround(CPlayer player);
//�J�[�\���̕`��
void drawCursor(CPlayer player);
//�t�B�[���h��̃u���b�N�̕`��
void drawFieldBlock(CPlayer player);
//�Q�[���v���C���̉�ʊO�̕`��
void drawPlayWindow();
//�ΐ탂�[�h�̃Q�[���v���C���̉�ʊO�̕`��
void drawVsWindow();
//���x���̐��l�̕`��
void drawLevel(int x, int y, CPlayer player);
//�R���{�̐��l�̕`��
void drawCombo(int x, int y, CPlayer player);
//�A�����̕`��
//void drawChain(int x, int y, CPlayer player);
//�ΐ탂�[�h�̃R���{�̐��l�̕`��
void drawVsCombo(int x, int y, CPlayer player);
//NEXT�̕`��
void drawNext();
//�R���{���Ԃ̃o�[
void drawComboCountBar();
//�ΐ탂�[�h�̃R���{���Ԃ̃o�[
void drawComboCountBarVS();
//�G�̗̑͂ɉ�����HP�o�[�̐F��Ԃ��֐�
int GetHPColor(int hp, int maxhp);
//�����̐F�ɑΉ������u���b�N�̉摜��Ԃ�
int getBlockImg(e_color color);
//�����̐F�ɑΉ������J�[�\���̉摜��Ԃ�
int getCursorImg(e_color color);
