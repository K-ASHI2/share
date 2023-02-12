#include"DxLib.h"
#include"extern.h"
#include"function.h"

void Bomb() {

	if (player.bomb_c > 0) {

		if (player.bomb_c == player.bomb_t) {
			//�{�����������u�Ԃɑ��݂���A�C�e�����������
			for (int i = 0; i < ITEM; i++) {
				if (item[i].hp != 0) {
					item[i].collect = 1;
				}
			}
			efs(efs_p_bomb);
		}

		//�{���̒e�̏���
		double size;
		switch (player.character) {
		case player.D_Magician_A:
			//�X�[�p�[�m���@
			//��ʑS�̂̓G�Ƀ_���[�W
			//2.5 * 120 = 300
			if (player.bomb_c < 120) {
				for (int i = 0; i < ENEMY; i++) {
					if (enemy[i].hp > 0) {
						EnemyDamaged(i, 2.5);
					}
				}
				//�{�X�Ƀ_���[�W
				BossDamaged(2.5);
			}

			//��莞�Ԍォ���ʓ��̒e��S����
			if (player.bomb_c < 60) {
				for (int i = 0; i < BULLET; i++) {
					if (enemybullet[i].hp > 0) {
						RemoveBullet(i);
					}
				}
			}
			break;

		case player.D_Magician_B:
			//�u���b�N�z�[��
			//1.0 * 280 = 280
			if (player.bomb_c > 240) {
				size = 5.0 * (240 - player.bomb_c) / 40;
			}
			else if (player.bomb_c > 40) {
				size = 5.0;
			}
			else {
				size = 5.0 * player.bomb_c / 40;
			}
			for (int i = 0; i < ENEMY; i++) {
				if (enemy[i].hp > 0) {
					if (judge(player.bomb_x, player.bomb_y, 50 * size, enemy[i].x, enemy[i].y, enemy[i].size) == 1) {
						EnemyDamaged(i, 1.0);
					}
				}
			}
			if (judge(player.bomb_x, player.bomb_y, 50 * size, boss.x, boss.y, boss.size) == 1) {
				BossDamaged(1.0);
			}
			for (int i = 0; i < BULLET; i++) {
				if (enemybullet[i].hp > 0) {
					if (judge(player.bomb_x, player.bomb_y, 50 * size, enemybullet[i].x, enemybullet[i].y, enemybullet[i].size) == 1) {
						RemoveBullet(i);
					}
				}
			}
			break;

		case player.L_Magician_A:
			//�\�[���[�X�p�[�N
			//1.8 * 300 = 540
			//���@�̑O���̉�160�͈̔͂ɔ����t����
			if (player.bomb_c < 300) {
				for (int i = 0; i < ENEMY; i++) {
					if (enemy[i].hp > 0 && enemy[i].x > player.x - 160 && enemy[i].x < player.x + 160 && enemy[i].y < player.y + player.size) {
						EnemyDamaged(i, 1.8);
					}
				}
			}
			if (boss.hp > 0 && boss.x > player.x - 160 && boss.x < player.x + 160 && boss.y < player.y + player.size) {
				//�{�X�Ƀ_���[�W
				BossDamaged(1.8);
			}

			for (int i = 0; i < BULLET; i++) {
				if (enemybullet[i].hp > 0) {
					if (enemybullet[i].x > player.x - 160 && enemybullet[i].x < player.x + 160 && enemybullet[i].y < player.y + player.size) {
						RemoveBullet(i);
					}
				}
			}
			break;
		case player.L_Magician_B:
			//�r�b�N�o��
			//��ʑS�̂̓G�Ƀ_���[�W
			//0.5 * 60 = 30
			if (player.bomb_c < 60) {
				for (int i = 0; i < ENEMY; i++) {
					if (enemy[i].hp > 0) {
						EnemyDamaged(i, 0.2);
					}
				}
				//�{�X�Ƀ_���[�W
				BossDamaged(0.5);

				//��ʓ��̒e��S����
				for (int i = 0; i < BULLET; i++) {
					if (enemybullet[i].hp > 0) {
						RemoveBullet(i);
					}
				}
			}
			break;
		}
		player.bomb_c--;
	}
}