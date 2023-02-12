#include"DxLib.h"
#include"extern.h"
#include"function.h"

//background�̔z��̓Y����
//�O������Ăяo���ƃo�O��̂ŗǂ��Ȃ����A��Ɨʂ����炷���߂ɗp���Ă���
static int bi;

//�w�i�̃��[�h
void LoadBackground() {

	bi = 0;
	SetBackground("img/cloud.png", 1500, 0);
	SetBackground("img/b_cave.png", 1500, 0);
	SetBackground("img/b_darkcave.png", 1500, 0);
	SetBackground("img/b_check.png", 1600, 0);
	SetBackground("img/darkcloud.png", 1600, 0);
	SetBackground("img/b_purple.png", 1600, 0);
	SetBackground("img/b_firecloud.png", 1500, 0);
	SetBackground("img/b_cloud.png", 1500, 0);
	SetBackground("img/b_snow.png", 1500, 0);
	SetBackground("img/b_red.png", 1500, 0);
	SetBackground("img/b_darkcheck.png", 1600, 0);

	for (int i = bi; i < BACKGROUND_MAX; i++) {
		SetBackground("img/b_yuki.png", 1500, bi);
	}
}

//�w�i�̃Z�b�g
void SetBackground(const TCHAR *FileName, int size_x, int size_y) {

	background[bi].size_x = size_x;
	background[bi].size_y = size_y;
	background[bi].img = LoadGraph(FileName);
	bi++;
}
