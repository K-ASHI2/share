#include"DxLib.h"
#include"extern.h"
#include"function.h"

//�G�̕ǂɑ΂���㉺����
void judge_ev(int blx, int bly) {

	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			if (enemy[i][j].jy == 1) {
				if (enemy[i][j].life > 0) {
					if (enemy[i][j].species != 14) {
						if (enemy[i][j].species == 16) {//���̒[�Ŕ��]����G�𔼕�������͂ݏo���甽�]����悤�ɂ���
							if (enemy[i][j].vx > 0 && blx < (enemy[i][j].x + enemy[i][j].size_x) && enemy[i][j].x + enemy[i][j].size_x * 0.5 < (blx + BLOCK)
								&& bly <= (enemy[i][j].y + enemy[i][j].size_y) && enemy[i][j].y < (bly + BLOCK)
								|| enemy[i][j].vx <= 0 && blx < (enemy[i][j].x + enemy[i][j].size_x * 0.5) && enemy[i][j].x < (blx + BLOCK)
								&& bly <= (enemy[i][j].y + enemy[i][j].size_y) && enemy[i][j].y < (bly + BLOCK)) {
								enemy[i][j].vy = 0;
								enemy[i][j].jfly = 0;
								enemy[i][j].y = bly - enemy[i][j].size_y;
							}
						}
						else {
							//���̕\�ʂł͍��W�����炳�Ȃ�
							if (blx < (enemy[i][j].x + enemy[i][j].size_x) && enemy[i][j].x < (blx + BLOCK) && bly < (enemy[i][j].y + enemy[i][j].size_y) && enemy[i][j].y < (bly + BLOCK)) {
								if (enemy[i][j].vy >= 0) {
									enemy[i][j].vy = 0;
									enemy[i][j].y = bly - enemy[i][j].size_y;
								}
								else {
									enemy[i][j].y = bly + BLOCK;
									enemy[i][j].vy = 0;
								}
							}
							//���̕\�ʈȊO
							else if (blx < (enemy[i][j].x + enemy[i][j].size_x) && enemy[i][j].x < (blx + BLOCK) && bly <= (enemy[i][j].y + enemy[i][j].size_y) && enemy[i][j].y < (bly + BLOCK)) {
								if (enemy[i][j].vy >= 0) {
									enemy[i][j].vy = 0;
									enemy[i][j].jfly = 0;
									if (enemy[i][j].species == 19) {
										enemy[i][j].species = -2;  //���e�I�͉��ɂȂ�
										enemy[i][j].size_y = 32;
										enemy[i][j].t = 0;
									}
									enemy[i][j].y = bly - enemy[i][j].size_y;//�������̂�����ɏo��悤�ɂ���
								}
								else {
									enemy[i][j].vy = 0;
									enemy[i][j].y = bly + BLOCK;
								}
							}
						}
					}
				}
			}
		}
	}
}

//�G�̕ǂɑ΂���㉺���˔���
void judge_ev2(int blx, int bly) {

	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			if (enemy[i][j].species == 14) {
				if (enemy[i][j].life > 0)
					if (enemy[i][j].vy > 0) {
						if (blx < enemy[i][j].x + enemy[i][j].size_x && enemy[i][j].x - BLOCK < blx && bly <= enemy[i][j].y + enemy[i][j].size_y && enemy[i][j].y - BLOCK + enemy[i][j].vy <= bly)
							enemy[i][j].vy = enemy[i][j].vy * -1;
					}
					else {
						if (blx < enemy[i][j].x + enemy[i][j].size_x && enemy[i][j].x - BLOCK < blx && bly <= enemy[i][j].y + enemy[i][j].size_y + enemy[i][j].vy && enemy[i][j].y - BLOCK <= bly)
							enemy[i][j].vy = enemy[i][j].vy * -1;
					}
			}
		}
	}
}

//�G�̂��蔲�����̔���
void judge_ev3(int blx, int bly) {

	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			if (enemy[i][j].jy == 1) {
				if (enemy[i][j].species != 14) {
					if (enemy[i][j].life > 0) {
						if (blx < enemy[i][j].x + enemy[i][j].size_x && enemy[i][j].x < blx + BLOCK && bly <= enemy[i][j].y + enemy[i][j].size_y && enemy[i][j].y <= bly) {
							//�G�ƃu���b�N���d�Ȃ��Ă���
							if (enemy[i][j].vy >= 0 && enemy[i][j].by + enemy[i][j].size_y <= bly) {
								enemy[i][j].jfly = 0;
								enemy[i][j].vy = 0;
								if (enemy[i][j].species == 19) {
									enemy[i][j].species = -2;  //���e�I�͉��ɂȂ�
									enemy[i][j].size_y = 32;
									enemy[i][j].t = 0;
								}
								enemy[i][j].y = bly - enemy[i][j].size_y;
							}
						}
					}
				}
			}
		}
	}
}

void judge_ev4(int blx, int bly) {//�G�̂��蔲�����̔��˔���

	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			if (enemy[i][j].species == 14) {
				if (enemy[i][j].life > 0)
					if (enemy[i][j].vy > 0) {
						if (blx < enemy[i][j].x + enemy[i][j].size_x && enemy[i][j].x - BLOCK < blx && bly <= enemy[i][j].y + enemy[i][j].size_y && enemy[i][j].y - BLOCK + enemy[i][j].vy <= bly)
							enemy[i][j].vy = enemy[i][j].vy * -1;
					}
			}
		}
	}
}

//�G�̕ǂɑ΂��鍶�E����1 : �ǂɓ��������甽�]����
void judge_eh(int blx, int bly) {

	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			if (enemy[i][j].species != 44)
				if (enemy[i][j].jx == 1) {
					if (enemy[i][j].life > 0) {
						if (enemy[i][j].vx > 0) {
							if (blx <= (enemy[i][j].x + enemy[i][j].size_x) && enemy[i][j].x - BLOCK + enemy[i][j].vx < blx && bly < (enemy[i][j].y + enemy[i][j].size_y) && enemy[i][j].y - BLOCK < bly) {	//�E����
								enemy[i][j].vx = enemy[i][j].vx * -1;
								//enemy[i][j].countx = 300;
							}
						}
						else if (enemy[i][j].vx < 0) {
							if (blx - enemy[i][j].vx <= (enemy[i][j].x + enemy[i][j].size_x) && enemy[i][j].x - BLOCK <= blx && bly < (enemy[i][j].y + enemy[i][j].size_y) && enemy[i][j].y - BLOCK < bly) {	//������
								enemy[i][j].vx = enemy[i][j].vx * -1;
								//enemy[i][j].countx = 0;
							}

						}
					}
				}
		}
	}
}

//�G�̕ǂɑ΂��鍶�E����2 : �ǂɉ�����d�Ȃ�����ǂ̉��ɂ��炷
void judge_eh2(int blx, int bly) {
	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			if (enemy[i][j].jx == 1) {
				if (enemy[i][j].life > 0) {
					if (blx < (enemy[i][j].x + enemy[i][j].size_x) && enemy[i][j].x - BLOCK < blx && bly < (enemy[i][j].y + enemy[i][j].size_y) && enemy[i][j].y - BLOCK < bly) {
						//�G�ƃu���b�N���d�Ȃ��Ă���
						if (enemy[i][j].vx > 0) {
							enemy[i][j].x = blx - enemy[i][j].size_x;
						}
						else
							enemy[i][j].x = blx + BLOCK;
					}
				}
			}
		}
	}
}
