#pragma once
#include "enum.h"

class CMenuWindow
{
private:
	/*change_flag�͂����Ɏ��s����Ȃ��̂ň�����ۑ�����*/
	enum e_flag changeFlag_flag;
	int changeFlag_cursor;
	int changeFlag_cursor2;
	int cursor = 0;		//�c�J�[�\�����ǂ̈ʒu�ɂ��邩
	int cursor_LR = 0;	//���J�[�\�����ǂ̈ʒu�ɂ��邩
	int cancel_cursor = 0;	//�L�����Z���Ŗ߂鎞�̃J�[�\���̈ʒu
	int N_o_i = 0;		//���݂̑I����ʂ̏c�̍��ڐ�(number of item)
	int N_o_i_LR = 0;	//���݂̑I����ʂ̉��̍��ڐ�
	int cursor_count = 0;		//�J�[�\�����͂̑҂����Ԃ̃J�E���g
	int bright = 255;	//��ʂ̋P�x
	int PlaybackFlag = 0;	//�|�[�Y��ʂ���߂�����̍Đ�����1,����ȊO��0
	enum e_flag flag;
	enum e_flag cancelFlag = e_title;	//�L�����Z���Ŗ߂鎞�̃t���O
	enum e_fade fadeFlag;		//�t�F�[�h�A�E�g���Ă��邩�ǂ����̃t���O
	int stageStartCount = 0;	//�Q�[���J�n�O�̃J�E���g
	bool stageStartFlag = false;	//�J�E���g�J�n���Ă��邩�ǂ���

public:
	CMenuWindow();
	~CMenuWindow();
	int getFlag();
	enum e_fade getFadeFlag();
	void changeFlag(e_flag f, int c = 0, int c2 = 0);
	void changeFlag2(e_flag f, int c = 0, int c2 = 0);
	void setSelectWindow(int n, int c = 0);
	void setSelectWindow_LR(int n, int n2, int c = 0, int c2 = 0);
	void selectWindow(int mode = 0);
	void selectWindow_LR();
	void keyConfig();
	void drawKeyConfig();
	void manual();
	void drawManual();
	void pause();
	void drawPause();
	void clear();
	void drawClear();
	void win();
	void drawWin();
	void start();
	void drawStart();
	void title();
	void drawTitle();
	void moveMenu();
	void drawMoveMenu();
	void operationMenu();
	void drawOperationMenu();
	void drawRed(int x, int y, const char * String, int c);
	void drawRed2(int x, int y, const char * String, int c, int c2);
	//x���W,y���W,������A�c�ɉ��Ԗڂ��������Ƃ��A�J�[�\���̈ʒu�������Ȃ�C_Color��C_EdgeColor�A�Ⴄ�Ȃ�N_Color��N_EdgeColor�ŕ`�悷��֐�
	void drawColor(int x, int y, const char *String, int c, unsigned int N_Color, unsigned int C_Color, unsigned int N_EdgeColor = 0U, unsigned int C_EdgeColor = 0U);
	void fadeOut();
	void fadeIn();
};

