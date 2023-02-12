#include"DxLib.h"
#include"extern.h"
#include"function.h"

//��Փx�I��
void DifficultySelect() {

	SelectWindow();
	//�L�����Z���̏���
	if (button[KEY_BOMB] == 1) {
		int c1, c2;
		switch (player.character) {
		case player.D_Magician_A: c1 = 0; c2 = 0; break;
		case player.D_Magician_B: c1 = 0; c2 = 1; break;
		case player.L_Magician_A: c1 = 1; c2 = 0; break;
		case player.L_Magician_B: c1 = 1; c2 = 1; break;
		}
		ChangeFlag(e_characterselect, c1, c2);
		efs(efs_back);
	}

	if (button[KEY_SHOT] == 1) {
		efs(efs_decision);
		switch (cursor) {
		case 0: difficulty = ed_easy; break;
		case 1: difficulty = ed_normal; break;
		case 2: difficulty = ed_hard; break;
		}
		WorldStage();	//�X�e�[�W�����݂̃��[���h��1�ڂ̃X�e�[�W�ɂ���
		init();
		ChangeFlag(e_gameplay);
	}
}

//��Փx�I����ʂ̕`��
void DrawDifficultySelect() {

	DrawGraph(0, 0, img.background_2, TRUE);
	DrawRed(100, 100, "EASY", 0);
	DrawRed(100, 150, "NORMAL", 1);
	DrawRed(100, 200, "HARD", 2);
}
