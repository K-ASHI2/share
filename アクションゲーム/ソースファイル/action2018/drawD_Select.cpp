#pragma once
#include"DxLib.h"
#include"extern.h"
#include"function.h"

//��Փx�I���̕`��
void drawDifficultySelect() {

	DrawGraph(0, 0, img.title, TRUE);
	DrawRed(100, 100, "EASY", 0);
	DrawRed(100, 180, "NORMAL", 1);
	DrawRed(100, 260, "HARD", 2);
	DrawString(100, 500, "��Փx�̑I�������Ă�������", green);

	DrawGraph(60, 98 + cursor * 80, img.arrow, TRUE);
	DrawStringToHandle(400, 360, "�\���{�^�� �I��", red, Font[2]);
	DrawStringToHandle(400, 400, "A�EB �@�@�@����", red, Font[2]);
	DrawStringToHandle(400, 440, "X�EY �@�@�@�L�����Z��", red, Font[2]);
}
