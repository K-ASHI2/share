#include"extern.h"
#include"function.h"

//�S�ẴA�C�e���̏�����
void init_i() {

	for (int i = 0; i < ITEM;i++) {
		ItemInit(i);
	}
}

//�����Ƃ��Ď󂯎�����A�C�e��������������
void ItemInit(int i) {
	item[i].hp = 0;
	item[i].x = 0;
	item[i].y = 0;
	item[i].vx = 0;
	item[i].vy = 0;
	item[i].size = 20;
	item[i].collect = 0;
}
