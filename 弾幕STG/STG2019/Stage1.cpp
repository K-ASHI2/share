#include"DxLib.h"
#include"extern.h"
#include"function.h"

//1��
void Stage1() {

	if (stageTimeCount == 10000) {
		CreateBoss();
	}
	if (boss_flag == eb_boss) {
		//�{�X��hp���Ȃ��Ȃ邩�A���������ꂽ����̃��[�h�Ȃ�`�Ԃ�ς���
		if (boss.hp == 0 || boss.mode == 0) {
			boss.mode++;
			//�ύX��̃��[�h�ɂ����hp������������
			switch (boss.mode) {
			case 1:
				boss.maxtotalhp = 4000;
				boss.totalhp = boss.maxtotalhp;
				boss.maxhp = 1000;
				boss.hp = boss.maxhp;
				break;
			case 2: boss.maxhp = 2000;
				boss.hp = boss.maxhp;
				break;
			case 3: boss.maxhp = 1000;
				boss.hp = boss.maxhp;
				break;
			}
		}
	}
}

//�X�e�[�W�ɂ����L�̓���
void Stage() {

	switch (world) {
	case ew_1: Stage1(); break;
	case ew_2: Stage2(); break;
	case ew_3: Stage3(); break;
	case ew_4: Stage4(); break;
	case ew_extra: StageExtra(); break;
	}
}
