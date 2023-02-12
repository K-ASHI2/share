#include"DxLib.h"
#include"extern.h"
#include"function.h"
#include<math.h>
#include<cmath>

//�G�����֐�
void CreateEnemy() {

	//i��j�̃~�X�ɋC��t����
	//�G�̏o�����X�g�̓Y������i�A�G�̔z��̓Y������j

	for (int i = 0; i < ENEMYEMERGE; i++) {
		//�G���o������t���[���ɂȂ�����G�𐶐�����
		if (enemyemerge[i].frame == stageTimeCount) {
			int j = getEnemyNumber();	//�����\�ȓG�̔z��̔ԍ����擾����
			EnemyInit(j);
			enemy[j].hp = 10/*enemyemerge[i].hp*/;
			enemy[j].pattern = enemyemerge[i].pattern;
			enemy[j].kind = enemyemerge[i].kind;
			enemy[j].x = enemyemerge[i].x;
			enemy[j].y = enemyemerge[i].y;
			enemy[j].v = enemyemerge[i].v;
			enemy[j].wait = enemyemerge[i].wait;
			enemy[j].bt = enemyemerge[i].bt;
			enemy[j].bkind = enemyemerge[i].bkind;
			enemy[j].color = enemyemerge[i].color;
			enemy[j].item = enemyemerge[i].item;
			enemy[j].vanish_kind = GetRand(5);

			//�G�̎�ނ��Ƃɑ傫�������肷��
			SetEKind(i, j);
		}
	}
	//switch(chap){
	//case 0:
	//	break;
	//case 99:
	//	//���̂܂܂��Ɖ�ʊO������G���o��
	//	if(GetRand(30)==0){
	//		for(int i=0;i<ENEMY;i++){
	//			if(enemy[i].hp==0){
	//				enemy[i].hp=3;
	//				enemy[i].t=0;
	//				enemy[i].x = WINDOW_WINDTH/4+GetRand(WINDOW_WINDTH/2);
	//				enemy[i].y = -enemy[i].size;
	//				if(enemy[i].x < WINDOW_WINDTH/2){     
	//					enemy[i].vx = GetRand(5);
	//				}
	//				else{
	//					enemy[i].vx = -GetRand(5);
	//				}
	//				enemy[i].vy=5+GetRand(5);
	//				break;
	//			}
	//		}
	//	}
	//	break;
	//}
}

//�����\�ȓG�̔z��̔ԍ����擾����֐�
int getEnemyNumber() {

	//�e�����݂������ŉ��o���I����Ă���G��I��
	for (int i = 0; i < ENEMY; i++) {
		if (enemy[i].hp == 0 && enemy[i].vanish == 0) {
			return i;
		}
	}
	return 0;
}

//�A�C�e�������֐�
//xy���W�A�傫���A��ނ��󂯎���ăA�C�e���𐶐�����
void CreateItem(int x,int y,int kind){

	//kind��0�̓G�̏ꍇ�A�A�C�e���𗎂Ƃ��Ȃ��G
	if (kind == 0) {
		return;
	}
	for(int i = 0;i < ITEM;i++){
		if(item[i].hp == 0){
			ItemInit(i);
			item[i].hp = 1;
			item[i].x = x;
			item[i].y = y;
			item[i].vx = 0;
			item[i].vy = -5;
			item[i].kind = kind;
			//�A�C�e���ɂ���đ傫����ς���
			switch (item[i].kind) {
			case 1: item[i].size = 8; break;
			case 2: item[i].size = 8; break;
			case 3: item[i].size = 15; break;
			case 4: item[i].size = 8; break;
			}
			break;
		}
	}
}
