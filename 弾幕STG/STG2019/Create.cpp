#include"DxLib.h"
#include"extern.h"
#include"function.h"
#include<math.h>
#include<cmath>

//敵を作る関数
void CreateEnemy() {

	//iとjのミスに気を付ける
	//敵の出現リストの添え字がi、敵の配列の添え字がj

	for (int i = 0; i < ENEMYEMERGE; i++) {
		//敵が出現するフレームになったら敵を生成する
		if (enemyemerge[i].frame == stageTimeCount) {
			int j = getEnemyNumber();	//生成可能な敵の配列の番号を取得する
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

			//敵の種類ごとに大きさを決定する
			SetEKind(i, j);
		}
	}
	//switch(chap){
	//case 0:
	//	break;
	//case 99:
	//	//このままだと画面外からも敵が出る
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

//生成可能な敵の配列の番号を取得する関数
int getEnemyNumber() {

	//弾が存在せず消滅演出が終わっている敵を選ぶ
	for (int i = 0; i < ENEMY; i++) {
		if (enemy[i].hp == 0 && enemy[i].vanish == 0) {
			return i;
		}
	}
	return 0;
}

//アイテムを作る関数
//xy座標、大きさ、種類を受け取ってアイテムを生成する
void CreateItem(int x,int y,int kind){

	//kindが0の敵の場合、アイテムを落とさない敵
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
			//アイテムによって大きさを変える
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
