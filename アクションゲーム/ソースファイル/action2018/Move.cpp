#include"Dxlib.h"
#include"extern.h"
#include"function.h"
#include<math.h>

void move() {

	//player.crouch = 0;//���Ⴊ��ł��邩�ǂ����̔���
	player.size_y = 64;

	if (player.mv > 0)
		player.mv = 0;

	player.vx = 0;				//���ړ����Z�b�g

	if (player.jfly != 0 && player.vy < MAXSPEED_Y) {	//�d��
		player.vy += GRA;
	}

	player.kabe_l = 0;		//�ǔ��胊�Z�b�g
	player.kabe_r = 0;

	/*if (button[KEY_DOWN] == 1) {	//���Ⴊ��
		player.crouch = 1;
		player.size_y = 32;
	}*/
	player.dire_m = 0;

	if (button[KEY_LEFT] >= 1 && player.attack == 0 && button[KEY_RIGHT] == 0) {		//�v���C���[�̍���������
		if (player.kabe_l == 0 && player.x > 0) {//�����ɕǂ��Ȃ��Ȃ��������
			if (!player.jfly) {//�n��ɂ��鎞
				if (player.vx2 > -ACCELE_X * 5.5)//�u���[�L�ƍŏ��̉���
					player.vx2 -= ACCELE_X * 5.5;
				else if (player.vx2 > -MAXSPEED_X * 0.25)
					player.vx2 -= ACCELE_X * 0.7;
				else if (player.vx2 > -MAXSPEED_X * 0.5)
					player.vx2 -= ACCELE_X * 0.6;
				else if (player.vx2 > -MAXSPEED_X * 0.75)
					player.vx2 -= ACCELE_X * 0.4;
				else if (player.vx2 > -MAXSPEED_X)//�ō����x�łȂ��Ȃ�
					player.vx2 -= ACCELE_X * 0.3;	//�v���C���[��-x�����ɉ�������
				else if (player.vx2 < -MAXSPEED_X)
					player.vx2 = -MAXSPEED_X;
			}
			else {//�󒆂ł͂��܂�������Ȃ�
				if (player.vx2 > 0)//�u���[�L
					player.vx2 -= ACCELE_X * 1.5;
				else if (player.vx2 > -ACCELE_X * 5.5)//�ŏ��̉����𑽂߂ɂ���
					player.vx2 = -ACCELE_X * 5.5;
				else if (player.vx2 > -MAXSPEED_X * 0.25)
					player.vx2 -= ACCELE_X * 0.7;
				else if (player.vx2 > -MAXSPEED_X * 0.5)
					player.vx2 -= ACCELE_X * 0.6;
				else if (player.vx2 > -MAXSPEED_X * 0.75)
					player.vx2 -= ACCELE_X * 0.4;
				else if (player.vx2 > -MAXSPEED_X)  //�ō����x�łȂ��Ȃ�
					player.vx2 -= ACCELE_X * 0.2;	//�v���C���[��-x�����ɉ�������
				else if (player.vx2 < -MAXSPEED_X)
					player.vx2 = -MAXSPEED_X;
			}
		}
		player.dire = 1;
		player.dire_m = 1;
	}

	//�v���C���[�̉E��������
	else if (button[KEY_RIGHT] >= 1 && player.attack == 0 && button[KEY_LEFT] == 0) {
		//�E���ɕǂ��Ȃ��Ȃ��������
		if (player.kabe_r == 0 && player.x + HERO_SIZE_X <= BLOCK * width_size) {
			//�n��ɂ��鎞
			if (!player.jfly) {
				if (player.vx2 < ACCELE_X * 5.5)	//�u���[�L�ƍŏ��̉���
					player.vx2 += ACCELE_X * 5.5;
				else if (player.vx2 < MAXSPEED_X * 0.25)
					player.vx2 += ACCELE_X * 0.7;
				else if (player.vx2 < MAXSPEED_X * 0.5)
					player.vx2 += ACCELE_X * 0.6;
				else if (player.vx2 < MAXSPEED_X * 0.75)
					player.vx2 += ACCELE_X * 0.4;
				else if (player.vx2 < MAXSPEED_X)	//�ō����x�łȂ��Ȃ�
					player.vx2 += ACCELE_X * 0.3;	//�v���C���[��x�����ɉ�������
				else if (player.vx2 > MAXSPEED_X)
					player.vx2 = MAXSPEED_X;
			}
			else {//�󒆂ł͂��܂�������Ȃ�
				if (player.vx2 < 0)//�u���[�L
					player.vx2 += ACCELE_X * 1.5;
				else if (player.vx2 < ACCELE_X * 5.5)	//�ŏ��̉����𑽂߂ɂ���
					player.vx2 = ACCELE_X * 5.5;
				else if (player.vx2 < MAXSPEED_X * 0.25)
					player.vx2 += ACCELE_X * 0.7;
				else if (player.vx2 < MAXSPEED_X * 0.5)
					player.vx2 += ACCELE_X * 0.6;
				else if (player.vx2 < MAXSPEED_X * 0.75)
					player.vx2 += ACCELE_X * 0.4;
				else if (player.vx2 < MAXSPEED_X)	//�ō����x�łȂ��Ȃ�
					player.vx2 += ACCELE_X * 0.2;	//�v���C���[��x�����ɉ�������
				else if (player.vx2 > MAXSPEED_X)
					player.vx2 = MAXSPEED_X;
			}
		}
		player.dire = 0;
		player.dire_m = 2;
	}

	/*�ړ����ĂȂ����̌���*/
	//�n��ɂ��鎞�̌���
	else if (!player.jfly) {
		//���x���������͑��x�𑽂����炷
		if (player.vx2 > 0.3)
			player.vx2 -= 0.3;
		else if (player.vx2 < -0.3)
			player.vx2 += 0.3;
		//���x���x�����͑��x���������炷
		else if (player.vx2 > 0)
			player.vx2 -= 0.1;
		else if (player.vx2 < 0)
			player.vx2 += 0.1;
	}

	//�󒆂��鎞�̌���
	else if (player.vx2 > 0.07) {
		player.vx2 -= 0.07;
	}
	else if (player.vx2 < -0.07) {
		player.vx2 += 0.07;
	}

	//���x�����ȉ��Ȃ瑬�x��0�ɂ���
	if (player.vx2 < 0.1 && player.vx2 > -0.1)
		player.vx2 = 0;

	//���x�ɉ����x�𑫂�
	player.vx += player.vx2;

	player.jp2 = 0;

	//�v���C���[�̃W�����v����
	if (player.jfly == 0 && button[KEY_JUMP] >= 2 && button[KEY_JUMP] <= 10 && countTime > 10) {	//10�t���[���̓��͗P�\�E�Q�[���J�n����ɔ�Ԃ̂�h�~
		player.jfly = 1;
		player.jp2 = 1;
		double vx3 = player.vx2;

		if (vx3 < 0) {
			vx3 *= -1;
		}

		//�v���C���[��y���x��ω�������
		player.vy = -(17 + (vx3 - MAXSPEED_X) * 0.4);
		
		PlaySoundMem(music.jump, DX_PLAYTYPE_BACK);
	}
	else if (player.jfly && button[KEY_JUMP] == 0 && player.vy < 0) {
		//�W�����v�̏㏸���ɃW�����v�{�^����������Ă��Ȃ����W�����v���~�߂�
		player.vy *= 0.85;
	}

	//if(keyState[KEY_INPUT_R])	{		//�f�o�b�O�p�W�����v
	//	player.vy = -5;
	//}

	player.jfly = 1;

	int k = 0;
	for (int j = 0; j < height_size; j++) {    //���̏�̉���
		for (int i = 0; i < width_size; i++) {
			if (enemy[i][j].species == 1 || enemy[i][j].species == 42 || enemy[i][j].species == 7) {
				if (judge_yuka((int)enemy[i][j].x, (int)enemy[i][j].y)) {
					player.jfly = 0;
					player.vx += enemy[i][j].vx;
					k = 1;
					break;	//2�̏��ɏd�Ȃ��Ă��鎞�ɕЕ������������Ȃ�
				}
			}
		}
		if (k == 1) {
			break;
		}
	}

	player.x += player.vx;

	//��ʂ̋����X�N���[��
	if (scroll_v > 0) {
		//�E�[�ɃX�N���[�������ǂ蒅���܂ł̓X�N���[������
		if (scroll_leftx < width_size * BLOCK - WINDOW_WIDTH) {
			scroll_leftx += scroll_v;
		}
		//��ʊO�ɏo�����ʓ��ɖ߂�
		if (player.x < scroll_leftx) {
			player.x = scroll_leftx;
			//player.vx2 = 0;
			player.vx = 0;
		}
		else if (player.x + player.size_x > scroll_leftx + WINDOW_WIDTH) {
			player.x = scroll_leftx + WINDOW_WIDTH - player.size_x;
			//player.vx2 = 0;
			player.vx = 0;
		}
	}

	//�c�ɓ������̉�����
	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			if (enemy[i][j].species == 7 || enemy[i][j].species == 38)
				if (enemy[i][j].x < player.x + HERO_SIZE_X && player.x < enemy[i][j].x + BLOCK && enemy[i][j].y - enemy[i][j].vy < player.y + HERO_SIZE_Y && player.y < enemy[i][j].y + BLOCK - enemy[i][j].vy) {
					//�v���C���[��1�t���[���O�̃u���b�N���d�Ȃ��Ă���
					if (player.vx >= 0) {
						player.x = enemy[i][j].x - HERO_SIZE_X;
					}
					else {
						player.x = enemy[i][j].x + BLOCK;
					}
					player.vx = 0;
					player.vx2 = 0;
				}
		}
	}

	//������ǂɂԂ��������ɕǂ̉��ɖ߂�
	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			if (kabe[i][j] == 1) {
				judge_h(i*BLOCK, j*BLOCK);
			}
		}
	}

	int a = 0;
	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			if (enemy[i][j].species == 1 || enemy[i][j].species == 42) {        //���ɓ������̉�����
				if (enemy[i][j].vx > 0) {//�����E�ɓ����Ă��鎞
					if (enemy[i][j].x < player.x + HERO_SIZE_X && player.x < enemy[i][j].x + BLOCK
						&& enemy[i][j].y < player.y + HERO_SIZE_Y && player.y < enemy[i][j].y + BLOCK) {
						//�v���C���[�����݂̃u���b�N�ɏd�Ȃ��Ă���
						//�E�Ɉړ����Ă��ău���b�N�̂ق����x���A�܂荶�����瓖��������
						if (player.vx > enemy[i][j].vx) {
							player.x = enemy[i][j].x - HERO_SIZE_X;
						}
						//����ȊO�Ȃ�E�Ɉړ�����
						else {
							player.x = enemy[i][j].x + BLOCK;
							if (player.vx2 <= 0)
								player.vx2 = 0;
							else
								player.vx2 = enemy[i][j].vx;
						}
						a = 1;
					}
				}
				//�������ɓ����Ă��鎞
				else if (enemy[i][j].x <= player.x + HERO_SIZE_X && player.x < enemy[i][j].x + BLOCK
					&& enemy[i][j].y < player.y + HERO_SIZE_Y && player.y < enemy[i][j].y + BLOCK) {
					//�v���C���[�����݂̃u���b�N�ɏd�Ȃ��Ă���
					//���ւ̈ړ����x���G��菬�����A�܂荶���ɂ��鎞
					if (player.vx >= enemy[i][j].vx) {
						player.x = enemy[i][j].x - HERO_SIZE_X;
						if (player.vx2 >= 0)
							player.vx2 = 0;
						else
							player.vx2 = enemy[i][j].vx;
					}
					//����ȊO�Ȃ�E�Ɉړ�����
					else {
						player.x = enemy[i][j].x + BLOCK;//1�t���[���O�̃u���b�N�̈ʒu�̉E�ɖ߂�
					}
					a = 1;
				}
			}
			if (a == 1)	//1�x������ł��炵���瑼�̉��ɓ������͖�������
				break;
		}
		if (a == 1)	//1�x������ł��炵���瑼�̉��ɓ������͖�������
			break;
	}

	//���ɓ������I�������̃Q�[���I�[�o�[����
	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			//�ǂɂ߂荞��ł�����Q�[���I�[�o�[
			if (kabe[i][j] == 1) {
				judge_death(i * BLOCK, j * BLOCK);
			}

			//1�t���[���O�̏c�ɓ������Əd�Ȃ�����Q�[���I�[�o�[
			if (enemy[i][j].species == 7) {
				judge_death3(enemy[i][j].x - enemy[i][j].vx, enemy[i][j].y - enemy[i][j].vy);
			}

			//���ɓ������Əd�Ȃ�����Q�[���I�[�o�[
			if (enemy[i][j].species == 1 || enemy[i][j].species == 42) {
				judge_death3(enemy[i][j].x, enemy[i][j].y);
			}
		}
	}

	//��ʊO�ɏo�Ă�����Q�[���I�[�o�[
	//�����X�N���[������ꍇ
	if (scroll_v > 0 /*&& scroll_leftx < width_size * BLOCK - WINDOW_WIDTH*/) {
		if (player.x < scroll_leftx || player.x + player.size_x > scroll_leftx + WINDOW_WIDTH) {
			player.life = 0;
		}
	}
	//�����X�N���[�����Ȃ��ꍇ
	else if (player.x < 0 || (player.x + HERO_SIZE_X) > width_size * BLOCK) {
		player.life = 0;
	}

	//���ړ��̃Q�[���I�[�o�[���肪�I��������_�ŃQ�[���I�[�o�[�Ȃ炻�̌�̏����͂��Ȃ�
	if (player.life == 0) {
		return;
	}

	a = 0;
	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			if (enemy[i][j].species == 7 || enemy[i][j].species == 38) {		//�c�ɓ������̏c����
				if ((enemy[i][j].x < player.x + HERO_SIZE_X && player.x < enemy[i][j].x + BLOCK) &&
					(enemy[i][j].y < player.y + player.vy + HERO_SIZE_Y && player.y + player.vy < enemy[i][j].y + BLOCK)) {
					//�������ɓ����Ă��鎞
					if (enemy[i][j].vy > 0) {
						//�v���C���[�����݂̃u���b�N�ɏd�Ȃ��Ă���
							//���Ɉړ����Ă��ău���b�N�̂ق����x���A�܂�㑤���瓖��������
						if (player.vy >= enemy[i][j].vy) {
							player.jfly = 0;
							player.y = enemy[i][j].y - HERO_SIZE_Y - enemy[i][j].vy;
							player.vy = enemy[i][j].vy;
						}
						//����ȊO�Ȃ牺�Ɉړ�����
						else {
							player.y = enemy[i][j].y + BLOCK;
							player.vy = enemy[i][j].vy;
						}
					}
					//������ɓ����Ă��鎞
					else {
						//�v���C���[�����݂̃u���b�N�ɏd�Ȃ��Ă���
						//��ւ̈ړ����x���G��菬�����A�܂�㑤�ɂ��鎞
						if (player.vy >= enemy[i][j].vy) {
							player.jfly = 0;
							player.y = enemy[i][j].y - HERO_SIZE_Y - enemy[i][j].vy;
							player.vy = enemy[i][j].vy;//�����x����������
						}
						//����ȊO�Ȃ牺�Ɉړ�����
						else {
							player.y = enemy[i][j].y + BLOCK;
							player.vy = 0;
						}
					}
				}
			}
			if (a == 1)//1�x������ł��炵���瑼�̏c�ɓ������͖�������
				break;
		}
		if (a == 1)//1�x������ł��炵���瑼�̏c�ɓ������͖�������
			break;
	}

	player.y += player.vy;

	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			if (kabe[i][j] == 1)
				judge_v(i*BLOCK, j*BLOCK);//�㉺����
			else if (kabe[i][j] == 2)
				judge_v2(i*BLOCK, j*BLOCK);
		}
	}

	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			if (enemy[i][j].species == 1 || enemy[i][j].species == 42) {     //���ɓ������̏c����
				if (enemy[i][j].x < player.x + HERO_SIZE_X && player.x < enemy[i][j].x + BLOCK && enemy[i][j].y < player.y + HERO_SIZE_Y && player.y < enemy[i][j].y + BLOCK) {
					//�v���C���[�ƃu���b�N���d�Ȃ��Ă���
					if (player.vy >= 0) {
						player.jfly = 0;
						player.y = enemy[i][j].y - HERO_SIZE_Y;
						player.vy = 0;
					}
					else {
						player.vy = 0;
						player.y = (enemy[i][j].y + BLOCK);
					}
				}
			}
		}
	}

	//�c�ɓ������I�������̔���
	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {

			//�ǂɂ߂荞��ł�����Q�[���I�[�o�[
			if (kabe[i][j] == 1) {
				judge_death(i*BLOCK, j*BLOCK);
			}

			//���蔲�����̏㑤�Ƌ��܂��Ă��邩�ǂ���
			if (kabe[i][j] == 2) {
				judge_death2(i*BLOCK, j*BLOCK);
			}

			//�������Əd�Ȃ�����Q�[���I�[�o�[
			if (enemy[i][j].species == 1 || enemy[i][j].species == 7 || enemy[i][j].species == 38 || enemy[i][j].species == 42) {
				judge_death3(enemy[i][j].x, enemy[i][j].y);
			}
		}
	}

	//1�t���[���O��y���W��ۑ�����
	player.by = player.y;

	for (int j = 0; j < height_size; j++) {      //�v���C���[�ƓG�̂����蔻��
		for (int i = 0; i < width_size; i++) {
			if (enemy[i][j].life > 0 && enemy[i][j].hantei == 1) {   //���݂��Ă��Ĕ��肪����Ȃ�
				if (enemy[i][j].species == 4 || enemy[i][j].species == 54) {
					if ((enemy[i][j].x < player.x + HERO_SIZE_X && player.x < enemy[i][j].x + enemy[i][j].size_x) &&
						(enemy[i][j].y < player.y + HERO_SIZE_Y && player.y < enemy[i][j].y + enemy[i][j].size_y)) {
						enemy[i][j].life = 0;
					}
				}
				//�G�̂����蔻��𔻒��������������
				else if ((enemy[i][j].x < player.x + HERO_SIZE_X - 3 && player.x + 3 < enemy[i][j].x + enemy[i][j].size_x) &&
					(enemy[i][j].y < player.y + HERO_SIZE_Y - 2 && player.y + 5 < enemy[i][j].y + enemy[i][j].size_y)) {
					if (enemy[i][j].species == 45) {
						PlaySoundMem(music.sw, DX_PLAYTYPE_BACK);
						sw = 1;
					}
					else if (enemy[i][j].species == 46) {
						PlaySoundMem(music.sw, DX_PLAYTYPE_BACK);
						sw = 0;
					}
					else if (enemy[i][j].species == 48) {
						gameover();
					}
					else if (player.muteki == 0) {
						PlaySoundMem(music.damage, DX_PLAYTYPE_BACK);
						player.life--;
						player.muteki = 100;   //���G�ɂ���
					}
				}
			}
			if (enemy[i][j].species == 4 && enemy[i][j].life == 0) {	//1�t���[���O�Ƀn�[�g��hp��0�ɂȂ��Ă����Ȃ�
				if (player.life < player.maxlife)
					player.life++;
				enemy[i][j].life = -1;
				efs(efs_recover);
			}
			if (enemy[i][j].species == 54 && enemy[i][j].life == 0) {	//1�t���[���O�Ƀn�[�g��hp��0�ɂȂ��Ă����Ȃ�
				player.life = player.maxlife;
				enemy[i][j].life = -1;
				efs(efs_recover);
			}

			//�e�̂����蔻��𔻒��������������
			for (int k = 0; k < BULLET; k++) {
				if ((enemybullet[i][j][k].x + 1 < player.x + HERO_SIZE_X - 3 && player.x + 3 < enemybullet[i][j][k].x + enemybullet[i][j][k].size_x - 1) &&
					(enemybullet[i][j][k].y + 1 < player.y + HERO_SIZE_Y - 2 && player.y + 5 < enemybullet[i][j][k].y + enemybullet[i][j][k].size_y - 1)) {
					if (enemybullet[i][j][k].life > 0) {
						if (player.muteki == 0) {
							PlaySoundMem(music.damage, DX_PLAYTYPE_BACK);
							player.life--;
							player.muteki = 100;   //���G�ɂ���
						}
					}
				}
			}

			//�X�C�b�`�ɐG�ꂽ��I���I�t����
			if (enemy[i][j].species == 45) {
				if (sw == 0)
					enemy[i][j].life = 1;
				else
					enemy[i][j].life = 0;
			}
			if (enemy[i][j].species == 46) {
				if (sw == 1)
					enemy[i][j].life = 1;
				else
					enemy[i][j].life = 0;
			}

			//�{�X���|�ꂽ������o������
			if (enemy[i][j].species == 50 && boss == 1) {
				enemy[i][j].life = 0;
			}
		}
	}

	double c, d;

	if (player.x <= CENTER) {//�v���C���[�����[�t�߂ɂ��鎞
		c = player.x;
		d = CENTER;
	}
	else if (player.x > width_size * BLOCK - (WINDOW_WIDTH - CENTER)) {//�v���C���[���E�[�t�߂ɂ��鎞
		c = -(width_size * BLOCK - WINDOW_WIDTH - player.x);
		d = width_size * BLOCK - (WINDOW_WIDTH - CENTER);
	}
	else {//�v���C���[�����̈ʒu���E�ɂ��鎞�`��̒��S���v���C���[�̍��W�ɂ���
		c = CENTER;
		d = player.x;
	}

	//�X�C�b�`�ɂ��ω�
	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			if (d - CENTER - 224 < enemy[i][j].x && d + WINDOW_WIDTH - CENTER > enemy[i][j].x) {

				//�ԃX�C�b�`�ŏo�鏰
				if (map[i][j] == 703) {
					if (sw == 1)
						kabe[i][j] = 1;
					else
						kabe[i][j] = 0;
				}

				//�΃X�C�b�`�ŏo�鏰
				if (map[i][j] == 704) {
					if (sw == 0)
						kabe[i][j] = 1;
					else
						kabe[i][j] = 0;
				}
			}
		}
	}

	judgeDoor();
}

//�v���C���[�L�����̍U��
void attack() {
	if (player.attack == 0) {
		if (button[KEY_ATTACK] == 1) {
			player.attack = 5;
			efs(efs_attack);
		}
	}
	else {
		player.attack--;
	}
}

//�w�i�𓮂����֐�
void move_background() {

	//x,y�����̑��x�������W�ɉ���,�w�i�̑傫���Ń��[�v������
	if (background[background_n].size_y != 0) {
		background2.y = (background2.y + background2.vy) % background[background_n].size_y;
	}
}

