#include"DxLib.h"
#include"extern.h"
#include"function.h"

//�v���C���[�̕ǂ̍��E����
void judge_h(int blx, int bly) {

	//�v���C���[�ƃu���b�N���d�Ȃ��Ă�����ǂ̏㉺�ɖ߂�
	if (blx < (player.x + HERO_SIZE_X) && player.x < (blx + BLOCK) && bly < (player.y + HERO_SIZE_Y) && player.y < (bly + BLOCK)) {
		if (player.vx >= 0) {
			player.x = blx - HERO_SIZE_X;
		}
		else {
			player.x = blx + BLOCK;
		}
		player.vx2 = 0;	//�����x��0�ɂ���
	}
	//��ʊO�ɏo�Ȃ��悤�ɖ߂�
	if (player.x < 0)
		player.x = 0;
	else if (player.x > BLOCK * (width_size - 1))
		player.x = BLOCK * (width_size - 1);
}

//�v���C���[�̕ǂ̏㉺����
void judge_v(int blx, int bly) {

	//�v���C���[�ƃu���b�N���d�Ȃ��Ă�����ǂ̏㉺�ɖ߂�
	if (blx < (player.x + HERO_SIZE_X) && player.x < (blx + BLOCK) && bly <= (player.y + HERO_SIZE_Y) && player.y < (bly + BLOCK)) {
		if (player.vy >= 0) {
			player.jfly = 0;
			player.y = bly - HERO_SIZE_Y;
			player.vy = 0;
		}
		else {
			player.vy = 0;
			player.y = bly + BLOCK;
		}
		//�g�Q�̏��𓥂񂾂�_���[�W���󂯂�
		if (map[blx / BLOCK][bly / BLOCK] == 501 && player.muteki == 0) {
			if (judge_yuka(blx, bly) == 1) {
				player.life--;
				PlaySoundMem(music.damage, DX_PLAYTYPE_BACK);
				player.muteki = 100;
			}
		}
	}
}

//���蔲�����̔���
void judge_v2(int blx, int bly) {

	if (blx < (player.x + HERO_SIZE_X) && player.x < (blx + BLOCK) && bly <= (player.y + HERO_SIZE_Y) && player.y < bly) {
		//�v���C���[�ƃu���b�N���d�Ȃ��Ă���
		if (player.vy >= 0 && player.by + HERO_SIZE_Y <= bly) {
			player.jfly = 0;
			player.y = bly - HERO_SIZE_Y;
			player.vy = 0;
		}
	}
}

//���ɏ���Ă��邩�ǂ����̔���
int judge_yuka(int x, int y) {
	int a = 0;

	if ((player.y == y - HERO_SIZE_Y) && (x < player.x + HERO_SIZE_X && player.x < x + HERO_SIZE_X)) {
		a = 1;
	}
	return (a);
}