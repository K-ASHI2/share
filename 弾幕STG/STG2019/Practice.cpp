#include"DxLib.h"
#include"extern.h"
#include"function.h"

//�v���N�e�B�X
void Practice() {

	SelectWindow();	//�c�J�[�\���̈ړ�

	if (button[KEY_BOMB] == 1) {
		ChangeFlag(e_title);
	}
	if (button[KEY_SHOT] == 1) {//����
								//efm(5);//����̌��ʉ�
		switch (cursor) {
		case 0:	//1��
			world = ew_1;
			break;
		case 1:	//2��
			world = ew_2;
			break;
		case 2:	//3��
			world = ew_3;
			break;
		case 3:	//4��
			world = ew_4;
			break;
		}
		ChangeFlag(e_characterselect);
	}
}

//�v���N�e�B�X�̕`��
void DrawPractice() {
	
	DrawGraph(0, 0, img.background_2, TRUE);
	DrawRed(100, 100, "STAGE1", 0);
	DrawRed(100, 150, "STAGE2", 1);
	DrawRed(100, 200, "STAGE3", 2);
	DrawRed(100, 250, "STAGE4", 3);
	//DrawGraph(60, 98 + cursor * 50, img.arrow, TRUE);    //���̕`��
}
