#include"DxLib.h"
#include"extern.h"
#include"function.h"

//���@�ƓG���d�Ȃ��Ă��鎞�̔���
void judge_player_to_enemy() {

	for (int i = 0; i < ENEMY; i++) {
		if (enemy[i].hp != 0) {
			//��e����
			if (judge(player.x, player.y, player.size, enemy[i].x, enemy[i].y, enemy[i].size)) {
				PlayerDamage();
			}
		}
	}
}

//���@�ƃ{�X���d�Ȃ��Ă��鎞�̔���
void judge_player_to_boss() {

	if (boss.hp != 0) {
		//��e����
		if (judge(player.x, player.y, player.size, boss.x, boss.y, boss.size)) {
			PlayerDamage();
		}
	}
}

//�G�̒e�����@�ɓ����������̔���
void judge_enemybullet_to_player() {

	for (int i = 0; i < BULLET; i++) {
		if (enemybullet[i].hp) {
			//��e����(��e�����t���[�����O���C�Y�͂���)
			if (judge(player.x, player.y, player.size, enemybullet[i].x, enemybullet[i].y, enemybullet[i].size)) {
				RemoveBullet(i);
				PlayerDamage();
				Graze();
			}
			//�O���C�Y����
			else if (judge(player.x, player.y, player.size + player.grazeSize, enemybullet[i].x, enemybullet[i].y, enemybullet[i].size) && enemybullet[i].graze == 1) {
				enemybullet[i].graze = 0;

				//�O���C�Y�����e�ɑΉ����������Q�[�W��ǉ��Œ��߂�(��������)
				static int upgauge = 30;
				switch (enemybullet[i].color) {
				case ebc_blue: player.snowGauge += upgauge; break;
				case ebc_yellow: player.thunderGauge += upgauge; break;
				case ebc_red: player.fireGauge += upgauge; break;
				default: break;
				}

				//�O���C�Y�̃J�E���g�ƃX�R�A����
				//��̏������܂߂�����������₷������
				Graze();
			}
		}
	}
}

//�O���C�Y����
void Graze() {

	player.score += 1000;
	//�O���C�Y10�񂲂Ƃɍō��_��1000�_������
	//�����ł�10�_�������ɍō��_�̑����v�f���Ȃ��̂ő傫���ݒ�
	if (++player.graze % 10 == 0) {
		player.maxscore += 1000;
	}
}

//�v���C���[���A�C�e���ƐڐG���Ă��鎞�̔���
void judge_player_to_item() {

	static int size = 8;	//�A�C�e���ɑ΂��邠���蔻��̑傫��
	static int size2 = 50;	//�A�C�e���̒ᑬ����͈�
	for (int i = 0; i < ITEM; i++) {
		if (item[i].hp != 0) {
			//�A�C�e���ƃv���C���[���d�Ȃ��Ă�������ʂ𔭊�����
			//���@�̔�����傫���͈͂Ŕ��肷��
			if (judge(player.x, player.y, player.size, item[i].x, item[i].y, item[i].size + size) == 1){
				switch (item[i].kind) {	//�A�C�e���ɂ���Č��ʂ�ς���
				case 1: player.score += player.maxscore;
					break;
				case 2: player.power += 0.05;
					player.score += 10;
					break;
				case 3: player.power += 0.1;
					player.score += 100;
					break;
				case 4: player.power += 1.0;
					player.score += 1000;
					break;
				}
				item[i].hp = 0;
				if (player.power > 4.0) {
					player.power = 4.0;
				}
			}
			//�ᑬ�ړ����͉���t���O�̗����Ă��Ȃ��߂��̃A�C�e�����������
			else if (judge(player.x, player.y, player.size, item[i].x, item[i].y, item[i].size + size2) == 1 &&
				player.slow_move == 1 && item[i].collect == 0) {
				item[i].collect = 2;
			}
			//�ᑬ����͈̔͊O���ᑬ����߂���������߂�
			else if (item[i].collect == 2) {
				item[i].collect = 0;
				item[i].vx = 0;
				item[i].vy = 0;
			}
		}
	}
}

//��e����̏���
//��e��̋�炢�{�����莞�Ԃɂ���
void PlayerDamage() {

	if (player.muteki == 0 && player.damaged == 0) {
		//��炢�{���̎󂯕t�����Ԃ�8F
		player.damaged = 8 + DAMEGED;	//��炢�{�����莞�Ԃ̐ݒ� ���@���Ƃɕς�����ϐ��ɂ���
		player.inope = 2;				//��炢�{�����莞�Ԃɂ���
		//��e�������̌��ʉ���炷
		efs(efs_damage);
	}
}

//��e��̕�������
void PlayerDamaged() {

	if (player.damaged > 0) {
		player.damaged--;
		//��炢�{�����Ȃ������Ȃ��e�������s��
		if (player.damaged == DAMEGED) {
			player.d_effect = DAMEGED_EFFECT;
			player.damaged_x = player.x;
			player.damaged_y = player.y;
			player.x = G_W_LEFT + (G_W_RIGHT - G_W_LEFT) / 2;
			player.y = G_W_LOWER + 50;
			player.inope = 1;	//��e�������I���܂ő���s�\�ɂ���
			player.muteki = 450;
			player.life--;
			player.power -= 0.5;
			//�{���������Ă����珉�����܂ŉ�
			playerBombInit();
		}
		//��莞�Ԍ�ɉ�ʓ��̒e��S����
		else if (player.damaged == DAMEGED_APPEAR + 5) {
			for (int i = 0; i < BULLET; i++) {
				if (enemybullet[i].hp == 1) {
					RemoveBullet(i);
				}
			}
		}
		//�o�����Ԃ̃t���[���ȉ��ɂȂ������ʊO����o�����n�߂�
		else if (player.damaged < DAMEGED_APPEAR) {
			player.y -= 3;
		}
		//��e�������I�������瑀��\�ɂ���
		if (player.damaged == 0)
			player.inope = 0;
	}
}
