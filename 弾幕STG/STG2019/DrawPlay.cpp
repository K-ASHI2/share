#include"DxLib.h"
#include"extern.h"
#include"function.h"
#include"math.h"

//�Q�[���v���C���̕`��
//�w�i���{�������@�̒e���A�C�e�������@���G�̒e���G�̏��ɕ`�悷��
void DrawPlay() {

	//�w�i�̕`��
	DrawBackGround();

	//�{���̕`��
	if (player.bomb_c > 0) {
		BombEffect();
	}

	//�G�Ȃǂ̏��ŉ��o
	DrawVanished();

	//���@�̒e�̕`��
	for (int i = 0; i < BULLET; i++) {
		//���ł��n�܂����e�͓����ɂȂ��ď�����
		if (playerbullet[i].vanish > 0) {
			//���[�U�[�͏��ł�`�悵�Ȃ�
			if (playerbullet[i].pbkind != 5 && playerbullet[i].pbkind != 12 && playerbullet[i].pbkind != 13 && playerbullet[i].pbkind != 14) {
				if (playerbullet[i].pbkind == 3) {
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, 32 * playerbullet[i].vanish / P_BULLET_BUNISH);
				}
				else if (playerbullet[i].pbkind == 9 || playerbullet[i].pbkind == 15) {
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, 116 * playerbullet[i].vanish / P_BULLET_BUNISH);
				}
				else if (playerbullet[i].pbkind == 0 || playerbullet[i].pbkind == -1 || playerbullet[i].pbkind == 6 || playerbullet[i].pbkind == 7 || playerbullet[i].pbkind == 8) {
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, 228 * playerbullet[i].vanish / P_BULLET_BUNISH);
				}
				else {
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128 * playerbullet[i].vanish / P_BULLET_BUNISH);
				}
				DrawRotaGraph((int)playerbullet[i].x, (int)playerbullet[i].y, 1, 0, playerbullet[i].img, TRUE);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			}
			playerbullet[i].vanish--;
		}
		//���݂���e�Ƃ��̃t���[���œG�ɓ������ď��ł���e��`�悷��
		if (playerbullet[i].hp != 0) {
			if (playerbullet[i].pbkind == 3) {
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 32);
			}
			else if (playerbullet[i].pbkind == 9 || playerbullet[i].pbkind == 15) {
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 116);
			}
			else if (playerbullet[i].pbkind == 0 || playerbullet[i].pbkind == -1 || playerbullet[i].pbkind == 6 || playerbullet[i].pbkind == 7 || playerbullet[i].pbkind == 8) {
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 228);
			}
			else {
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
			}
			//���[�U�[�͉�����Ƃ��ĕ`�悷��
			if (playerbullet[i].pbkind == 5 || playerbullet[i].pbkind == 12 || playerbullet[i].pbkind == 13 || playerbullet[i].pbkind == 14) {
				DrawGraph((int)playerbullet[i].x - (int)playerbullet[i].size, (int)playerbullet[i].y - 800, playerbullet[i].img, TRUE);
			}
			else {
				DrawRotaGraph((int)playerbullet[i].x, (int)playerbullet[i].y, 1, 0, playerbullet[i].img, TRUE);
			}
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
	}

	//���@
	//���G���Ԓ��͓_�ł����Ȃ���`�悷��
	//���G�I�����߂Â�����_�ł���߂�
	if (player.muteki % 10 < 5 && player.muteki > 40) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 64);
	}
	switch (player.character) {
	case player.D_Magician_A: DrawRotaGraph((int)player.x, (int)player.y + 10, 1, 0, img.player1_1, TRUE); break;
	case player.D_Magician_B: DrawRotaGraph((int)player.x, (int)player.y + 10, 1, 0, img.player1_1, TRUE); break;
	case player.L_Magician_A: DrawRotaGraph((int)player.x, (int)player.y + 10, 1, 0, img.player2_1, TRUE); break;
	case player.L_Magician_B: DrawRotaGraph((int)player.x, (int)player.y + 10, 1, 0, img.player2_1, TRUE); break;
	}
	if (player.muteki % 10 < 5 && player.muteki > 40) {
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}

	//�ᑬ�ړ����̎��@�̔���(����\���̂�)
	if (player.slow_move == 1 && player.inope == 0) {
		//���@���Ԃ��̂Ŕ���̐F��ς���
		if (player.character == player.L_Magician_A || player.character == player.L_Magician_B) {
			DrawRotaGraph((int)player.x, (int)player.y, 1, 0, img.player_J2, TRUE);
		}
		else {
			DrawRotaGraph((int)player.x, (int)player.y, 1, 0, img.player_J1, TRUE);
		}
	}
	//��e�G�t�F�N�g
	if (player.d_effect > 0) {
		//��u�����Z���Ȃ��Ă��班�������߂��Ă���
		if (player.d_effect < 40) {
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180 * player.d_effect / 30);
		}
		//�ŏ����甼�����ŕ`�悷��
		else {
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
		}
		DrawRotaGraph((int)player.damaged_x, (int)player.damaged_y, sqrt((double)(DAMEGED_EFFECT - player.d_effect) / DAMEGED_EFFECT) * 1.5, 0, img.playerdamaged, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		player.d_effect--;
	}

	//�A�C�e���̕`��
	for (int i = 0; i < ITEM; i++) {
		if (item[i].hp > 0) {
			switch (item[i].kind) {
			case 0: break;
			case 1: DrawRotaGraph(item[i].x, item[i].y, 1, 0, img.score_item, TRUE); break;
			case 2: DrawRotaGraph(item[i].x, item[i].y, 1, 0, img.power_item, TRUE); break;
			case 3: DrawRotaGraph(item[i].x, item[i].y, 1, 0, img.power_item_L, TRUE); break;
			case 4: DrawRotaGraph(item[i].x, item[i].y, 1, 0, img.item, TRUE); break;
			}
		}
	}

	//�G�̒e�̕`��
	for (int i = 0; i < ENEMYBULLET; i++) {
		if (enemybullet[i].hp != 0) {
			//�e�̎�ނɂ���ĕ`�悷��e��ς���
			switch (enemybullet[i].kind) {
			case ebk_blue_S: DrawRotaGraph((int)enemybullet[i].x, (int)enemybullet[i].y, 1, 0, img.bluebullet_S, TRUE); break;
			case ebk_red_S: DrawRotaGraph((int)enemybullet[i].x, (int)enemybullet[i].y, 1, 0, img.redbullet_S, TRUE); break;
			case ebk_yellow_S: DrawRotaGraph((int)enemybullet[i].x, (int)enemybullet[i].y, 1, 0, img.yellowbullet_S, TRUE); break;
			case ebk_blue_M: DrawRotaGraph((int)enemybullet[i].x, (int)enemybullet[i].y, 1, 0, img.bluebullet_M, TRUE); break;
			case ebk_red_M: DrawRotaGraph((int)enemybullet[i].x, (int)enemybullet[i].y, 1, 0, img.redbullet_M, TRUE); break;
			case ebk_yellow_M: DrawRotaGraph((int)enemybullet[i].x, (int)enemybullet[i].y, 1, 0, img.yellowbullet_M, TRUE); break;
			case ebk_blue_L: DrawRotaGraph((int)enemybullet[i].x, (int)enemybullet[i].y, 1, 0, img.bluebullet_L, TRUE); break;
			case ebk_red_L: DrawRotaGraph((int)enemybullet[i].x, (int)enemybullet[i].y, 1, 0, img.redbullet_L, TRUE); break;
			case ebk_yellow_L: DrawRotaGraph((int)enemybullet[i].x, (int)enemybullet[i].y, 1, 0, img.yellowbullet_L, TRUE); break;
			case ebk_snow_S: DrawRotaGraph((int)enemybullet[i].x, (int)enemybullet[i].y, 1, PI * 2 * stageTimeCount / 180, img.snowbullet_S, TRUE); break;
			case ebk_snow_M: DrawRotaGraph((int)enemybullet[i].x, (int)enemybullet[i].y, 1, -PI * 2 * stageTimeCount / 180, img.snowbullet_M, TRUE); break;
			case ebk_fire_S: DrawRotaGraph((int)enemybullet[i].x, (int)enemybullet[i].y, 1, enemybullet[i].ang - PI / 2, img.firebullet_S, TRUE); break;
			case ebk_fire_M: DrawRotaGraph((int)enemybullet[i].x, (int)enemybullet[i].y, 1, 0, img.firebullet_M, TRUE); break;
			case ebk_thunder: DrawRotaGraph((int)enemybullet[i].x, (int)enemybullet[i].y, 1, enemybullet[i].ang + PI / 2, img.thunderbullet, TRUE); break;
			case ebk_star: DrawRotaGraph((int)enemybullet[i].x, (int)enemybullet[i].y, 1, PI * 2 * stageTimeCount / 180, img.star, TRUE); break;
			case ebk_star_red: DrawRotaGraph((int)enemybullet[i].x, (int)enemybullet[i].y, 1, PI * 2 * stageTimeCount / 180, img.star_red, TRUE); break;
			case ebk_star_blue: DrawRotaGraph((int)enemybullet[i].x, (int)enemybullet[i].y, 1, PI * 2 * stageTimeCount / 180, img.star_blue, TRUE); break;
			}
		}
	}

	//�G�̕`��
	for (int i = 0; i < ENEMY; i++) {
		if (enemy[i].hp != 0) {
			int TurnFlag = 0;
			//���Ɉړ����Ă���G�͔��]�\������
			if (enemy[i].vx < 0) {
				TurnFlag = 1;
			}
			switch(enemy[i].kind){
			case 0: DrawRotaGraph(enemy[i].x, enemy[i].y, 1, 0, img.ghost_S, TRUE, TurnFlag); break;
			case 1: DrawRotaGraph(enemy[i].x, enemy[i].y, 1, 0, img.redghost_S, TRUE, TurnFlag); break;
			case 2: DrawRotaGraph(enemy[i].x, enemy[i].y, 1, 0, img.blueghost_S, TRUE, TurnFlag); break;
			case 3: DrawRotaGraph(enemy[i].x, enemy[i].y, 1, 0, img.yellowghost_S, TRUE, TurnFlag); break;
			case 4: DrawRotaGraph(enemy[i].x, enemy[i].y, 2, 0, img.ghost_S, TRUE, TurnFlag); break;
			case 5: DrawRotaGraph(enemy[i].x, enemy[i].y, 2, 0, img.redghost_S, TRUE, TurnFlag); break;
			case 6: DrawRotaGraph(enemy[i].x, enemy[i].y, 2, 0, img.blueghost_S, TRUE, TurnFlag); break;
			case 7: DrawRotaGraph(enemy[i].x, enemy[i].y, 2, 0, img.yellowghost_S, TRUE, TurnFlag); break;
			}
		}
	}
	//�{�X�̕`��
	if (boss.totalhp > 0 || (boss_flag == eb_boss && boss.mode == 0)) {
		DrawRotaGraph(boss.x, boss.y, 1, 0, img.boss_magician, TRUE);
	}

	//�Q�[���v���C���̉�ʊO�̕`��
	DrawPlayWindow();
}

/*
 * DrawRotaGraph�͍��W�̈ʒu�𒆐S�ɂ��A���̈ʒu�ɉ摜��\�����邪�A�摜�̃h�b�g�������̎���肭�ł��Ȃ��B
 * �摜�̒��S��int�ł���A��̃h�b�g�𒆐S�Ƃ��Ă���B�h�b�g��0����n�܂邽�߁A�傫����2�̎����ۂ̒��S�̉E�������S�ƂȂ��Ă��܂��B
 * �Ⴆ�΁A�傫��4*4�̏ꍇ4/2=2�ō�����3�ԖځA�ォ��3�Ԗڂ����S�ƂȂ��Ă��܂��B�傫��5*5�̏ꍇ5/2=2�ŉ摜�̒��S���������Ȃ�B
 */

//���ł��邱�Ƃ��m�肵�Ă���G��e�ɑ΂��ď��ŃG�t�F�N�g��`�悷��B
void DrawVanished() {

	for (int i = 0; i < ENEMY; i++) {
		if (enemy[i].vanish > 0) {
			switch (enemy[i].vanish_kind) {
			case 0:	DrawRotaGraph(enemy[i].x, enemy[i].y, 1, 0, ani.EnemyVanish1[ENEMY_BUNISH - enemy[i].vanish], TRUE); break;
			case 1:	DrawRotaGraph(enemy[i].x, enemy[i].y, 1, 0, ani.EnemyVanish2[ENEMY_BUNISH - enemy[i].vanish], TRUE); break;
			case 2:	DrawRotaGraph(enemy[i].x, enemy[i].y, 1, 0, ani.EnemyVanish3[ENEMY_BUNISH - enemy[i].vanish], TRUE); break;
			case 3:	DrawRotaGraph(enemy[i].x, enemy[i].y, 1, 0, ani.EnemyVanish4[ENEMY_BUNISH - enemy[i].vanish], TRUE); break;
			case 4:	DrawRotaGraph(enemy[i].x, enemy[i].y, 1, 0, ani.EnemyVanish5[ENEMY_BUNISH - enemy[i].vanish], TRUE); break;
			}
			enemy[i].vanish--;
		}
	}
	for (int i = 0; i < ENEMYBULLET; i++) {
		if (enemybullet[i].vanish > 0) {
			switch (enemybullet[i].color) {
			case ebc_blue: DrawRotaGraph(enemybullet[i].x, enemybullet[i].y, 1, 0, ani.BlueBalletVanish[E_BULLET_BUNISH - enemybullet[i].vanish], TRUE); break;
			case ebc_red: DrawRotaGraph(enemybullet[i].x, enemybullet[i].y, 1, 0, ani.RedBalletVanish[E_BULLET_BUNISH - enemybullet[i].vanish], TRUE); break;
			case ebc_yellow: DrawRotaGraph(enemybullet[i].x, enemybullet[i].y, 1, 0, ani.YellowBalletVanish[E_BULLET_BUNISH - enemybullet[i].vanish], TRUE); break;
			case ebc_null: DrawRotaGraph(enemybullet[i].x, enemybullet[i].y, 1, 0, ani.BalletVanish[E_BULLET_BUNISH - enemybullet[i].vanish], TRUE); break;
			}
			enemybullet[i].vanish--;
		}
	}
	if (boss_flag == eb_boss) {
		if (boss.vanish > 0) {
			DrawRotaGraph(boss.x, boss.y, 3.0, 0, ani.EnemyVanish1[ENEMY_BUNISH - boss.vanish], TRUE);
			DrawRotaGraph(boss.x, boss.y, 3.0, 0, ani.EnemyVanish2[ENEMY_BUNISH - boss.vanish], TRUE);
			DrawRotaGraph(boss.x, boss.y, 3.0, 0, ani.EnemyVanish3[ENEMY_BUNISH - boss.vanish], TRUE);
			DrawRotaGraph(boss.x, boss.y, 3.0, 0, ani.EnemyVanish4[ENEMY_BUNISH - boss.vanish], TRUE);
			DrawRotaGraph(boss.x, boss.y, 3.0, 0, ani.EnemyVanish5[ENEMY_BUNISH - boss.vanish], TRUE);
			boss.vanish--;
		}
	}
}

//�w�i�̕`��
void DrawBackGround() {

	//���[�v�����邽�߂�2�摜��\������
	DrawGraph(background.x, background.y, background.img, FALSE);
	DrawGraph(background.x, background.y - background.size_y, background.img, FALSE);
}	

void MoveBackground() {

	//x,y�����̑��x�������W�ɉ���,�w�i�̑傫���Ń��[�v������
	background.y += background.vy;
	if (background.y > background.size_y)
		background.y -= background.size_y;
}
