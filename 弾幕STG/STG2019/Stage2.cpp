#include"DxLib.h"
#include"extern.h"
#include"function.h"

//2��
void Stage2() {

	if (stageTimeCount == 0) {
		CreateBoss();
	}
	if (boss_flag == eb_boss) {
		//�{�X��hp���Ȃ��Ȃ邩�A���������ꂽ����̃��[�h�Ȃ�`�Ԃ�ς���
		if (boss.hp == 0 || boss.mode == 0) {
			//�{�X�̌`�Ԃ��ς�鎞�̏���
			if (boss.modechange != 0) {
				//�{�X�̌`�Ԃ��ς��u�Ԃɒe������
				if (boss.modechange == 1) {

					//�S�Ă̓G�ƓG�̒e������
					//���ŃG�t�F�N�g���o�������̂�hp���̃_���[�W��^����
					for (int i = 0; i < ENEMY; i++) {
						if (enemy[i].hp > 0) {
							EnemyDamaged(i, enemy[i].hp);
						}
					}

					//�ŏ��ƃX�y���v���N�e�B�X�ȊO�Ń{�X��hp��0�ɂ�����A�C�e�����o��
					if (boss.mode != 0 && boss.mode_p == 0 && boss.time != 0) {

						int item = 2;

						//�p���[���ő�Ȃ�p���[�A�C�e�������_�A�C�e���ɕς���
						if (player.power == 4.0) {
							item = 1;
						}

						static int r = 15;
						CreateItem(boss.x, boss.y - r, item);
						CreateItem(boss.x + r * root2 / 2, boss.y - r * root2 / 2, 1);
						CreateItem(boss.x + r, boss.y, item);
						CreateItem(boss.x + r * root2 / 2, boss.y + r * root2 / 2, 1);
						CreateItem(boss.x, boss.y + r, item);
						CreateItem(boss.x - r * root2 / 2, boss.y + r * root2 / 2, 1);
						CreateItem(boss.x - r, boss.y, item);
						CreateItem(boss.x - r * root2 / 2, boss.y - r * root2 / 2, 1);

						static int r1 = 30;
						CreateItem(boss.x, boss.y - r1, item);
						CreateItem(boss.x + r1 * root2 / 2, boss.y - r1 * root2 / 2, 1);
						CreateItem(boss.x + r1, boss.y, item);
						CreateItem(boss.x + r1 * root2 / 2, boss.y + r1 * root2 / 2, 1);
						CreateItem(boss.x, boss.y + r1, item);
						CreateItem(boss.x - r1 * root2 / 2, boss.y + r1 * root2 / 2, 1);
						CreateItem(boss.x - r1, boss.y, item);
						CreateItem(boss.x - r1 * root2 / 2, boss.y - r1 * root2 / 2, 1);

						static int r2 = 45;
						CreateItem(boss.x, boss.y - r2, item);
						CreateItem(boss.x + r2 * root2 / 2, boss.y - r2 * root2 / 2, 1);
						CreateItem(boss.x + r2, boss.y, item);
						CreateItem(boss.x + r2 * root2 / 2, boss.y + r2 * root2 / 2, 1);
						CreateItem(boss.x, boss.y + r2, item);
						CreateItem(boss.x - r2 * root2 / 2, boss.y + r2 * root2 / 2, 1);
						CreateItem(boss.x - r2, boss.y, item);
						CreateItem(boss.x - r2 * root2 / 2, boss.y - r2 * root2 / 2, 1);

						static int r3 = 60;
						CreateItem(boss.x, boss.y - r3, item);
						CreateItem(boss.x + r3 * root2 / 2, boss.y - r3 * root2 / 2, 1);
						CreateItem(boss.x + r3, boss.y, item);
						CreateItem(boss.x + r3 * root2 / 2, boss.y + r3 * root2 / 2, 1);
						CreateItem(boss.x, boss.y + r3, item);
						CreateItem(boss.x - r3 * root2 / 2, boss.y + r3 * root2 / 2, 1);
						CreateItem(boss.x - r3, boss.y, item);
						CreateItem(boss.x - r3 * root2 / 2, boss.y - r3 * root2 / 2, 1);
					}

					//���Ԃ̕`������̍U���܂ňꎞ�I�ɏ���
					boss.time = -1;
				}
				//���[�h�ύX���͒e������������
				for (int i = 0; i < ENEMYBULLET; i++) {
					if (enemybullet[i].hp > 0) {
						RemoveBullet2(i);
					}
				}
				boss.modechange++;
				//120�t���[���̊Ԓe���o���Ȃ�
				if (boss.modechange == 120) {
					boss.modechange = 0;
				}
			}
			else {
				boss.mode++;
				boss.modechange = 1;

				//���Ԃ�0�ɖ߂�
				boss.t = 0;

				//�ύX��̃��[�h�ɂ����hp������������
				switch (boss.mode) {
				case 1:
					boss.maxtotalhp = 41000;
					boss.totalhp = boss.maxtotalhp;
					boss.maxhp = 3000;
					boss.hp = boss.maxhp;
					boss.maxtime = 30 * 120;
					break;
				case 2:
					boss.maxhp = 4500;
					boss.hp = boss.maxhp;
					boss.maxtime = 35 * 120;
					boss.time = boss.maxtime;
					break;
				case 3:
					boss.maxhp = 3500;
					boss.hp = boss.maxhp;
					boss.maxtime = 30 * 120;
					boss.time = boss.maxtime;
					break;
				case 4:
					boss.maxhp = 4500;
					boss.hp = boss.maxhp;
					boss.maxtime = 35 * 120;
					boss.time = boss.maxtime;
					break;
				case 5:
					boss.maxhp = 3500;
					boss.hp = boss.maxhp;
					boss.maxtime = 30 * 120;
					boss.time = boss.maxtime;
					break;
				case 6:
					boss.maxhp = 2500;
					boss.hp = boss.maxhp;
					boss.maxtime = 50 * 120;
					boss.time = boss.maxtime;
					break;
				case 7:
					boss.maxhp = 5500;
					boss.hp = boss.maxhp;
					boss.maxtime = 50 * 120;
					boss.time = boss.maxtime;
					break;
				case 8:
					boss.maxhp = 4000;
					boss.hp = boss.maxhp;
					boss.maxtime = 30 * 120;
					boss.time = boss.maxtime;
					break;
				case 9:
					boss.maxhp = 10000;
					boss.hp = boss.maxhp;
					boss.maxtime = 99 * 120;
					boss.time = boss.maxtime;
					break;
				}
				boss.time = boss.maxtime;

				//�X�y���v���N�e�B�X
				if (boss.mode_p != 0) {
					boss.maxtotalhp = boss.maxhp;
					boss.totalhp = boss.hp;
				}
			}
		}
		else {
			CreateBossBullet2();
			if (boss.time > 0) {
				boss.time--;
			}
			else if (boss.mode != 0 && boss.time == 0) {
				boss.totalhp -= boss.hp;
				boss.hp = 0;
			}
		}
	}
}
