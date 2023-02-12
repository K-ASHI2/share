#include"Dxlib.h"
#include"extern.h"
#include"function.h"
#include<math.h>

//�G�L�����̈ړ�
void enemymove(void) {
	double center, rad, ang;

	//�p���x�𑝂₷
	deg += 2;

	//���݂̉�ʂ̒��������߂�
	if (scroll_v > 0) {
		center = scroll_leftx + CENTER;
	}
	else {
		if (player.x >= CENTER) {
			center = player.x;
		}
		else {
			center = CENTER;
		}
		if (player.x > width_size * BLOCK - (WINDOW_WIDTH - CENTER)) {
			center = width_size * BLOCK - (WINDOW_WIDTH - CENTER);
		}
	}
	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			if (enemy[i][j].life != 0) {
				//��ʓ��ɓ�������G�͓�������
				if (i * BLOCK <= center + WINDOW_WIDTH - CENTER && i * BLOCK + enemy[i][j].size_x >= center - CENTER) {
					enemy[i][j].appear = 1;
				}
				if (enemy[i][j].jfly != 0) {
					if (enemy[i][j].species == 16 && enemy[i][j].jfly2 == 0) {//�R�̒[�Ŕ��]����G�̔���
						enemy[i][j].vx = enemy[i][j].vx * -1;
					}
					else if (enemy[i][j].vy < MAXSPEED_Y)
						enemy[i][j].vy += GRA;
					enemy[i][j].jfly2 = 1;
				}
				else
					enemy[i][j].jfly2 = 0;
			}
		}
	}
	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			if (enemy[i][j].life != 0) {
				if (enemy[i][j].species != 1 && enemy[i][j].species != 7 && enemy[i][j].species != 42 && enemy[i][j].species != 53 && enemy[i][j].appear == 1) {
					if (enemy[i][j].vx >= 0)		//�G���E����
						enemy[i][j].dire_x = 0;
					else							//�G��������
						enemy[i][j].dire_x = 1;
					if (enemy[i][j].vy >= 0) 		//�G�������
						enemy[i][j].dire_y = 0;
					else							//�G��������
						enemy[i][j].dire_y = 1;
					enemy[i][j].countx++;
					if (enemy[i][j].m_count == 0)
						enemy[i][j].county++;
				}
				switch (enemy[i][j].species) {
				case -2:enemy[i][j].jfly = 1; break;
				case 0: sin_move(i, j); break;
				case 2: sin_move(i, j); break;
				case 4: enemy[i][j].jfly = 1; break;
				case 5: sin_move_y(i, j); break;
				case 6: enemy[i][j].jfly = 1; break;
				case 7: break;
				case 8: break;
				case 9: break;
				case 10:break;
				case 11:break;
				case 12:enemy[i][j].jfly = 1; break;
				case 13:
					if (enemy[i][j].county >= 70 && enemy[i][j].jfly == 0) {
						enemy[i][j].vy = -15;
						enemy[i][j].county = 0;
					}
					enemy[i][j].jfly = 1;
					break;
				case 14: break;
				case 15:
					if (enemy[i][j].dire == 0) {
						rad = (enemy[i][j].rad + deg) * PI / 180.0 * (0.6 + enemy[i][j].m_rad / 10);
						enemy[i][j].x = i * BLOCK + 64 * cos(rad);
						enemy[i][j].y = j * BLOCK + 64 * sin(rad);
					}
					else {
						rad = (enemy[i][j].rad - deg) * PI / 180.0 * (0.6 + enemy[i][j].m_rad / 10);
						enemy[i][j].x = i * BLOCK + 64 * cos(rad);
						enemy[i][j].y = j * BLOCK + 64 * sin(rad);
					}
					break;
				case 16:enemy[i][j].jfly = 1; break;
				case 17:enemy[i][j].jfly = 1; break;
				case 18:enemy[i][j].jfly = 1; break;
				case 19: break;
				case 20:enemy[i][j].jfly = 1; break;
				case 30: sin_move_y(i, j); break;
				case 31:enemy[i][j].jfly = 1; break;
				case 32: sin_move_y(i, j); break;
				case 33:
					if (enemy[i][j].dire == 0) {
						rad = (enemy[i][j].rad + deg) * PI / 180.0 * (0.6 + enemy[i][j].m_rad / 10);
						enemy[i][j].x = i * BLOCK + 64 * cos(rad);
						enemy[i][j].y = j * BLOCK + 64 * sin(rad);
					}
					else {
						rad = (enemy[i][j].rad - deg) * PI / 180.0 * (0.6 + enemy[i][j].m_rad / 10);
						enemy[i][j].x = i * BLOCK + 64 * cos(rad);
						enemy[i][j].y = j * BLOCK + 64 * sin(rad);
					}
					break;
				case 34: sin_move_y(i, j); break;
				case 35:
					if (enemy[i][j].dire == 0) {
						rad = (enemy[i][j].rad + deg  * (0.6 + enemy[i][j].m_rad / 10)) * PI / 180.0;
						enemy[i][j].x = i * BLOCK + 64 * cos(rad);
						enemy[i][j].y = j * BLOCK + 64 * sin(rad);
					}
					else {
						rad = (enemy[i][j].rad - deg  * (0.6 + enemy[i][j].m_rad / 10)) * PI / 180.0;
						enemy[i][j].x = i * BLOCK + 64 * cos(rad);
						enemy[i][j].y = j * BLOCK + 64 * sin(rad);
					}
					break;
				case 36:
					rad = (enemy[i][j].rad - deg) * PI / 180.0 * (0.6 + enemy[i][j].m_rad / 10);
					enemy[i][j].x = i * BLOCK + 64 * cos(rad);
					enemy[i][j].y = j * BLOCK + 64 * sin(rad);
					break;
				case 43:	//��l����ǂ�������G
					ang = atan2((double)((player.y + HERO_SIZE_Y / 2) - (enemy[i][j].y + enemy[i][j].size_y * 0.25)), (double)((player.x + HERO_SIZE_X / 4) - (enemy[i][j].x + enemy[i][j].size_x * 0.25)));
					enemy[i][j].vx = cos(ang) * enemy[i][j].m_rad * 0.25;
					enemy[i][j].vy = sin(ang) * enemy[i][j].m_rad * 0.25;
					break;

				case 47:enemy[i][j].jfly = 1; break;
				case 48:
					/*enemy[i][j].vx = -1;
					if (enemy[i][j].countx >= -32) {
						enemy[i][j].x = i * BLOCK;
						enemy[i][j].countx = 0;
					}*/
					break;
				case 49:enemy[i][j].jfly = 1; break;
				case 51:
					if (enemy[i][j].vy == 0 && enemy[i][j].y > BLOCK * 10)
						enemy[i][j].county++;
					if (enemy[i][j].jfly == 0) {
						int ejp;//�G���W�����v����Ԋu
						if (mapload < 1000)
							ejp = 400;
						else if (mapload < 2000)
							ejp = 400;
						else
							ejp = 300;
						int d_life;//������hp��
						if (mapload < 1000)
							d_life = 3 - enemy[i][j].life;
						else if (mapload < 2000)
							d_life = 4 - enemy[i][j].life;
						else if (mapload < 3000)
							d_life = 6 - enemy[i][j].life;
						else if (mapload < 4000)
							d_life = 7 - enemy[i][j].life;
						if (enemy[i][j].county >= ejp && enemy[i][j].y > BLOCK * 10) {
							if (d_life <= 2)
								enemy[i][j].vy = -23;
							else
								enemy[i][j].vy = -18 - GetRand(5);
							enemy[i][j].county = 0;
						}
						if (d_life >= 4 && enemy[i][j].v_flag == 0) {
							enemy[i][j].vx *= 2;
							enemy[i][j].v_flag = 1;
						}
					}
					enemy[i][j].jfly = 1;
					if (enemy[i][j].m_count > 0)
						enemy[i][j].m_count--;
					break;
				case 52:
					if (enemy[i][j].countx >= 90) {
						enemy[i][j].vx *= -1;
						enemy[i][j].countx = 0;
					}
					break;
				case 53://�����鏰�̒��n����
					if (enemy[i][j].life > 0 && enemy[i][j].countx < 0) {
						if ((i * BLOCK < player.x + HERO_SIZE_X && player.x - HERO_SIZE_X < i * BLOCK) &&
							(j * BLOCK == player.y + HERO_SIZE_Y)) {
							enemy[i][j].countx = 0;
						}
					}
					break;
				case 54: enemy[i][j].jfly = 1; break;
				case 56:
					if (player.jp2 == 1 && enemy[i][j].jfly == 0)
						enemy[i][j].vy -= 15;
					enemy[i][j].jfly = 1;
					break;

				case 57:	//���_
					if (enemy[i][j].rad > 30) {
						if (enemy[i][j].x < player.x)
							if (enemy[i][j].x < player.x - BLOCK * 6)
								enemy[i][j].vx = enemy[i][j].m_rad * 2;
							else if (enemy[i][j].x < player.x - BLOCK * 4)
								enemy[i][j].vx = enemy[i][j].m_rad;
							else
								enemy[i][j].vx = enemy[i][j].m_rad * 0.5;
						else if (enemy[i][j].x > player.x)
							if (enemy[i][j].x > player.x + BLOCK * 6)
								enemy[i][j].vx = -enemy[i][j].m_rad * 2;
							else if (enemy[i][j].x > player.x + BLOCK * 4)
								enemy[i][j].vx = -enemy[i][j].m_rad;
							else
								enemy[i][j].vx = -enemy[i][j].m_rad * 0.5;
							enemy[i][j].rad = 0;
					}
					else
						enemy[i][j].rad++;
					break;

				case 58:	//�����_
					if (enemy[i][j].rad > 30) {
						if (enemy[i][j].x < player.x)
							if (enemy[i][j].x < player.x - BLOCK * 6)
								enemy[i][j].vx = enemy[i][j].m_rad * 2;
							else if (enemy[i][j].x < player.x - BLOCK * 4)
								enemy[i][j].vx = enemy[i][j].m_rad;
							else
								enemy[i][j].vx = enemy[i][j].m_rad * 0.5;
						else if (enemy[i][j].x > player.x)
							if (enemy[i][j].x > player.x + BLOCK * 6)
								enemy[i][j].vx = -enemy[i][j].m_rad * 2;
							else if (enemy[i][j].x > player.x + BLOCK * 4)
								enemy[i][j].vx = -enemy[i][j].m_rad;
							else
								enemy[i][j].vx = -enemy[i][j].m_rad * 0.5;
							enemy[i][j].rad = 0;
					}
					else
						enemy[i][j].rad++;
					break;
				}
			}
			//hp0�ł��������G
			switch (enemy[i][j].species) {
			case 37:	//�㉺�ɓ��������ĉ�ʊO�ɏo���甽�Α�����o�Ă���G
				if (enemy[i][j].vy > 0) {
					if (enemy[i][j].y >= BLOCK * (height_size + 2)) {
						enemy[i][j].life = 1;
						enemy[i][j].y = -enemy[i][j].size_y;
					}
				}
				else if (enemy[i][j].y < -enemy[i][j].size_y) {
					enemy[i][j].life = 1;
					enemy[i][j].y = BLOCK * (height_size + 2);
				}
				break;
			case 38:	//�㉺�ɓ��������ĉ�ʊO�ɏo���甽�Α�����o�Ă���u���b�N
				if (enemy[i][j].vy > 0) {
					if (enemy[i][j].y >= BLOCK * (height_size + 2)) {
						enemy[i][j].life = 1;
						enemy[i][j].y = -enemy[i][j].size_y;
					}
				}
				else if (enemy[i][j].y < -enemy[i][j].size_y) {
					enemy[i][j].life = 1;
					enemy[i][j].y = BLOCK * (height_size + 2);
				}
				break;
			case 41://�㉺�ɗh���G
				if (enemy[i][j].x < -enemy[i][j].size_x) {//��ʍ��̊O�ɏo����E�[�ɖ߂�
					enemy[i][j].life = 1;
					enemy[i][j].x = BLOCK * width_size;
				}
				else if (enemy[i][j].x > BLOCK * width_size) {//��ʉE�̊O�ɏo���獶�[�ɖ߂�
					enemy[i][j].life = 1;
					enemy[i][j].x = -enemy[i][j].size_x;
				}
				enemy[i][j].y = j * BLOCK + cos(enemy[i][j].x / 40 + enemy[i][j].rad) * 64;
				break;
			}
		}
	}
	for (int j = 0; j < height_size; j++)
		for (int i = 0; i < width_size; i++)
			if (kabe[i][j] == 1) {
				judge_eh(i*BLOCK, j*BLOCK);//�ǂɉ����瓖�������甽�]����
			}
	for (int j = 0; j < height_size; j++)
		for (int i = 0; i < width_size; i++)
			if (enemy[i][j].species != 1 && enemy[i][j].species != 7 && enemy[i][j].species != 42)//�������͏���
				if (enemy[i][j].appear == 1 && enemy[i][j].m_count == 0)
					enemy[i][j].x += enemy[i][j].vx;		//�G�̂����W�ɑ��x�����Z����

	for (int j = 0; j < height_size; j++)
		for (int i = 0; i < width_size; i++)
			if (enemy[i][j].appear == 1)
				if (kabe[i][j] == 1)
					judge_eh2(i*BLOCK, j*BLOCK);			//�ǂɉ�����d�Ȃ�����ǂ̉��ɂ��炷

	for (int j = 0; j < height_size; j++)
		for (int i = 0; i < width_size; i++)
			if (kabe[i][j] == 1)
				judge_ev2(i*BLOCK, j*BLOCK);
			else if (kabe[i][j] == 2)
				judge_ev4(i*BLOCK, j*BLOCK);

	for (int j = 0; j < height_size; j++)
		for (int i = 0; i < width_size; i++)
			if (enemy[i][j].species != 1 && enemy[i][j].species != 7 && enemy[i][j].species != 38 && enemy[i][j].species != 42)
				if (enemy[i][j].appear == 1)
					enemy[i][j].y += enemy[i][j].vy;		//�G�̂����W�ɑ��x�����Z����

	for (int j = 0; j < height_size; j++)
		for (int i = 0; i < width_size; i++)
			if (kabe[i][j] == 1)
				judge_ev(i*BLOCK, j*BLOCK);
			else if (kabe[i][j] == 2)
				judge_ev3(i*BLOCK, j*BLOCK);//���蔲�����̔���

	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			if (enemy[i][j].appear == 1) {
				if (kabe[i][j] == 1) {
					judge_eh2(i*BLOCK, j*BLOCK);			//�ǂɏc����d�Ȃ�����ǂ̏㉺�ɂ��炷
					judge_ev(i*BLOCK, j*BLOCK);
				}
			}
		}
	}

	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			enemy[i][j].by = enemy[i][j].y;
		}
	}

	//�U������
	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			if (player.attack) {
				if ((player.dire == 0 && (enemy[i][j].x < player.x + HERO_SIZE_X + ATTACK_SIZE_X && player.x + ATTACK_SIZE_X < enemy[i][j].x + enemy[i][j].size_x) &&
					(enemy[i][j].y < player.y + ATTACK_SIZE_Y && player.y < enemy[i][j].y + enemy[i][j].size_y)) ||			//�E�������Ă������̏���
					(player.dire == 1 && (enemy[i][j].x < player.x + HERO_SIZE_X - ATTACK_SIZE_X && player.x - ATTACK_SIZE_X < enemy[i][j].x + enemy[i][j].size_x) &&
						(enemy[i][j].y < player.y + ATTACK_SIZE_Y && player.y < enemy[i][j].y + enemy[i][j].size_y))) {				//���������Ă������̏���
					if (enemy[i][j].muteki == 0 && enemy[i][j].life != 0) {
						if (enemy[i][j].species != 4 || enemy[i][j].species != 54) {//�A�C�e���͍U�����Ă������Ȃ�
							enemy[i][j].life--;
							if (enemy[i][j].life == 0) {
								enemy[i][j].vanish = 1;
								enemy[i][j].vanish_x = enemy[i][j].x + (enemy[i][j].size_x - 32) / 2;
								enemy[i][j].vanish_y = enemy[i][j].y + (enemy[i][j].size_y - 32) / 2;
							}
							PlaySoundMem(music.attack2, DX_PLAYTYPE_BACK);
							if (enemy[i][j].species == 49 || enemy[i][j].species == 51)
								enemy[i][j].muteki = 120;
							if (enemy[i][j].life == 0 && GetRand(100) < enemy[i][j].drop) {//�A�C�e���̃h���b�v
								enemy[i][j].species = 4;
								enemy[i][j].x += (enemy[i][j].size_x - 32) * 0.5;//�G�̒��S�ɃA�C�e�����o��悤�ɂ���
								enemy[i][j].vx = 0;
								enemy[i][j].vy = 0;
								enemy[i][j].hantei = 1;
								enemy[i][j].life = 1;
								enemy[i][j].size_x = 32;
								enemy[i][j].size_y = 32;
							}
						}
					}
				}
			}

			//�����
			if (enemy[i][j].species == 3 && enemy[i][j].life <= 0) {
				kabe[i][j] = 0;
			}

			//�{�X�̖��G����
			if (enemy[i][j].species == 49 || enemy[i][j].species == 51) {
				if (enemy[i][j].muteki > 0) {
					enemy[i][j].muteki--;
				}
				if (enemy[i][j].life == 0) {
					boss = 1;
				}
			}
		}
	}
}

void sin_move(int i, int j) {

	enemy[i][j].rad += 0.03125;

	//PI�܂ł̈ړ�������PI����2PI�܂ł̈ړ������𓯂��ɂ���
	if (enemy[i][j].rad >= PI && enemy[i][j].rad < PI + 0.03125) {
		enemy[i][j].rad = PI;
	}
	if (enemy[i][j].rad >= 2 * PI) {
		enemy[i][j].rad = 0;
	}

	enemy[i][j].vx = enemy[i][j].sin_v * sin(enemy[i][j].rad);
}

void sin_move_y(int i, int j) {

	enemy[i][j].rad += 0.03125;

	//PI�܂ł̈ړ�������PI����2PI�܂ł̈ړ������𓯂��ɂ���
	if (enemy[i][j].rad >= PI && enemy[i][j].rad < PI + 0.03125) {
		enemy[i][j].rad = PI;
	}
	if (enemy[i][j].rad >= 2 * PI) {
		enemy[i][j].rad = 0;
	}

	enemy[i][j].vy = enemy[i][j].sin_v * sin(enemy[i][j].rad);
}
