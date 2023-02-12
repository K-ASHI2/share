#include"DxLib.h"
#include"extern.h"
#include"function.h"

void draw_background() {
	double x;

	if (scroll_v > 0) {
		x = (scroll_leftx + CENTER) / 3;
	}
	else {
		if (player.x <= CENTER) {//�v���C���[�����[�t�߂ɂ��鎞
			x = CENTER / 3;
		}
		else if (player.x > width_size * BLOCK - (WINDOW_WIDTH - CENTER)) {//�v���C���[���E�[�t�߂ɂ��鎞
			x = (width_size * BLOCK - (WINDOW_WIDTH - CENTER)) / 3;
		}
		else {//�v���C���[�����̈ʒu���E�ɂ��鎞�`��̒��S���v���C���[�̍��W�ɂ���
			x = player.x / 3;
		}
	}

	for (int i = 0; i < 4; i++) {
		DrawGraph(-x + background[background_n].size_x * i, 0, background[background_n].img, TRUE);
	}
}
