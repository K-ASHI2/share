#include"DxLib.h"
#include"extern.h"
#include"function.h"

//���@�̒e���G�ɓ����������̔���

void judge_playerbullet_to_enemy() {

	for (int i = 0; i < ENEMY; i++) {
		if (enemy[i].hp > 0) {
			for (int k = 0; k < BULLET; k++) {
				if (playerbullet[k].hp != 0) {
					//���[�U�[�̔���
					if (playerbullet[k].pbkind == 5 || playerbullet[k].pbkind == 12 || playerbullet[k].pbkind == 13 || playerbullet[k].pbkind == 14) {
						if (judge_laser(playerbullet[k].x, playerbullet[k].y, playerbullet[k].size, enemy[i].x, enemy[i].y, enemy[i].size) == 1) {
							PlayerBulletHitEnemy(i, k);
						}
					}
					//�G�ɒe�������锻��͓G�̃T�C�Y�̌����ڒʂ�͈̔�
					else if (judge(playerbullet[k].x, playerbullet[k].y, playerbullet[k].size, enemy[i].x, enemy[i].y, enemy[i].size)){
						PlayerBulletHitEnemy(i, k);
					}
				}
			}
		}
	}
}

//���@�̒e���{�X�ɓ����������̔���
void judge_playerbullet_to_boss() {

	if (boss.muteki == 0) {
		if (boss.hp > 0) {
			for (int k = 0; k < BULLET; k++) {
				if (playerbullet[k].hp != 0) {
					//���[�U�[�̔���
					if (playerbullet[k].pbkind == 5 || playerbullet[k].pbkind == 12 || playerbullet[k].pbkind == 13 || playerbullet[k].pbkind == 14) {
						if (judge_laser(playerbullet[k].x, playerbullet[k].y, playerbullet[k].size, boss.x, boss.y, boss.size) == 1) {
							PlayerBulletHitBoss(k);
						}
					}
					if (judge(playerbullet[k].x, playerbullet[k].y, playerbullet[k].size, boss.x, boss.y, boss.size)) {
						PlayerBulletHitBoss(k);
					}
				}
			}
		}
	}
	else {
		boss.muteki--;
	}
}

//�G���G�ɒe�𓖂Ă����̏��� e:�G pb ���@�̒e
void PlayerBulletHitEnemy(int e, int pb) {

	EnemyDamaged(e, playerbullet[pb].atk);
	playerbullet[pb].hp = -1;	//�e�𔻒肾������
	playerbullet[pb].vanish = P_BULLET_BUNISH;
	player.score += 1;	//�������ݓ_
}

//�{�X�ɒe�𓖂Ă����̏��� pb ���@�̒e
void PlayerBulletHitBoss(int pb) {

	BossDamaged(playerbullet[pb].atk);
	playerbullet[pb].hp = -1;	//�e�𔻒肾������
	playerbullet[pb].vanish = P_BULLET_BUNISH;
	player.score += 100;	//�������ݓ_
}

//�G���G���_���[�W���󂯂鎞�̏���
void EnemyDamaged(int e, double d) {

	if (enemy[e].hp > 0) {
		enemy[e].hp -= d;
		if (enemy[e].hp < 0) {
			enemy[e].hp = 0;
		}
		if (enemy[e].hp == 0) {
			enemy[e].vanish = ENEMY_BUNISH;
			//�G�ɑΉ������A�C�e�����o��
			CreateItem(enemy[e].x, enemy[e].y, enemy[e].item);
		}
	}
}

//�{�X���_���[�W���󂯂鎞�̏���
void BossDamaged(double d) {

	double d2 = d;

	//�{���o���A
	if (player.bomb_c > 0) {
		if (boss.mode == 7) {
			switch (difficulty) {
			case ed_easy: d2 *= 1.0; break;
			case ed_normal: d2 *= 0.7; break;
			case ed_hard: d2 *= 0.7; break;
			}
		}
		else if (boss.mode == 9) {
			switch (difficulty) {
			case ed_easy: d2 *= 1.0; break;
			case ed_normal: d2 *= 0.7; break;
			case ed_hard: d2 *= 0.5; break;
			}
		}
		else {
			switch (difficulty) {
			case ed_easy: d2 *= 1.0; break;
			case ed_normal: d2 *= 1.0; break;
			case ed_hard: d2 *= 0.8; break;
			}
		}
	}
	if (boss.totalhp > 0) {
		boss.hp -= d2;
		if (boss.hp < 0) {
			boss.hp = 0;
		}
		boss.totalhp -= d2;
		if (boss.totalhp < 0) {
			boss.totalhp = 0;
		}
		if (boss.totalhp == 0) {
			boss.vanish = ENEMY_BUNISH;
			efs(efs_boss_crush);
		}
	}
}

//�{���Ȃǎ��@�̍s���œG�̒e�������鎞�̏���
void RemoveBullet(int eb) {

	enemybullet[eb].hp = 0;
	enemybullet[eb].vanish = E_BULLET_BUNISH;

	int upgauge = 20;

	switch (difficulty) {
	case ed_easy: upgauge = 60; break;
	case ed_normal: upgauge = 30; break;
	case ed_hard: upgauge = 10; break;
	}

	//�e�������ɑ����Q�[�W�𒙂߂�
	switch (enemybullet[eb].color) {
	case ebc_blue: player.snowGauge += upgauge; break;
	case ebc_yellow: player.thunderGauge += upgauge; break;
	case ebc_red: player.fireGauge += upgauge; break;
	default: break;
	}
}

//�{�X�̌`�ԕω��œG�̒e�������鎞�̏���
void RemoveBullet2(int eb) {

	enemybullet[eb].hp = 0;
	enemybullet[eb].vanish = E_BULLET_BUNISH;

	int upgauge = 0;

	switch (difficulty) {
	case ed_easy: upgauge = 30; break;
	case ed_normal: upgauge = 15; break;
	case ed_hard: upgauge = 5; break;
	}

	//�e�������ɑ����Q�[�W�𒙂߂�
	switch (enemybullet[eb].color) {
	case ebc_blue: player.snowGauge += upgauge; break;
	case ebc_yellow: player.thunderGauge += upgauge; break;
	case ebc_red: player.fireGauge += upgauge; break;
	default: break;
	}
}
