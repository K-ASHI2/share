#include"DxLib.h"
#include"extern.h"
#include"function.h"

//�{�X���o������t���[���ɂȂ������ʊO����o�Ă���
void CreateBoss() {

	boss.x = G_W_LEFT + (G_W_RIGHT - G_W_LEFT) / 2;
	boss.y = 0;
	boss.t = 0;
	boss.size = 25;
	boss.maxhp = 0;
	boss.hp = boss.maxhp;
	boss.totalhp = 0;
	boss.maxtotalhp = 0;
	if (boss.mode_p != 0) {
		//�X�e�[�W�J�n���̏�������1�𑫂��̂ł�����1������
		boss.mode = boss.mode_p - 1;
		boss.maxtotalhp = 1;
		boss.totalhp = 1;
	}
	else {
		boss.mode = 0;
	}
	boss.modechange = 1;

	boss_flag = eb_boss;
	boss.appear = 80;	//�{�X����ʏォ��hp���㏸�����o��������
	boss.muteki = 80;

	//�S�Ă̓G�ƓG�̒e������
	//���ŃG�t�F�N�g���o�������̂�hp���̃_���[�W��^����
	for (int i = 0; i < ENEMY; i++) {
		if (enemy[i].hp > 0) {
			EnemyDamaged(i, enemy[i].hp);
		}
	}
	for (int i = 0; i < ENEMYBULLET; i++) {
		if (enemybullet[i].hp > 0)
			RemoveBullet2(i);
	}

	//�X�e�[�W���{�X�ɕς��A���y��ς���
	if (stage == es_1_1) {
		stage = es_1_2;
	}
	else if (stage == es_2_1) {
		stage = es_2_2;
	}
	else if (stage == es_3_1) {
		stage = es_3_2;
	}
	else if (stage == es_4_1) {
		stage = es_4_2;
	}
	else if (stage == es_e_1) {
		stage = es_e_2;
	}
	StageMusic();
}

//�{�X�̏o��
void BossAppear() {

	if (boss.appear > 0) {
		if (boss.hp < boss.maxhp) {
			boss.hp += boss.maxhp / (80 / 2);
		}
		boss.y++;
		boss.appear--;
	}
}
