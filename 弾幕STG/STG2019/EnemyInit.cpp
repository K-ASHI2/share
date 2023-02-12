#include"DxLib.h"
#include"extern.h"
#include"function.h"

void init_e() {
	for (int i = 0; i < ENEMY; i++) {
		EnemyInit(i);
	}
	for (int i = 0; i < ENEMYBULLET; i++) {	//“G‚Ì’e‚ÌŽb’è“I‚È‰Šú‰»
		enemybullet[i].hp = 0;
		enemybullet[i].x = 0;
		enemybullet[i].y = 0;
		enemybullet[i].vx = 10;
		enemybullet[i].vy = 10;
		enemybullet[i].atk = 0;
		enemybullet[i].size = 0;
		enemybullet[i].kind = ebk_blue_S;
		enemybullet[i].bkind = 0;
		enemybullet[i].graze = 1;
		enemybullet[i].vanish = 0;
		enemybullet[i].color = ebc_null;
		enemybullet[i].t = 0;
		enemybullet[i].mutate = 0;
		enemybullet[i].ang = 0;
	}
	//“G‚ÌoŒ»‚Ì‰Šú‰»
	for (int i = 0; i < ENEMYEMERGE; i++) {
		enemyemerge[i].frame = -1;	//0‚¾‚ÆŠJŽn’¼Œã‚É“G‚ð¶¬‚µ‚Ä‚µ‚Ü‚¤
		enemyemerge[i].pattern = 0;
		enemyemerge[i].kind = 0;
		enemyemerge[i].x = 0;
		enemyemerge[i].y = 0;
		enemyemerge[i].v = 0;
		enemyemerge[i].hp = 0;
		enemyemerge[i].wait = 0;
		enemyemerge[i].bt = 0;
		enemyemerge[i].bkind = 0;
		enemyemerge[i].color = 0;
		enemyemerge[i].item = 0;
	}

	//ƒ{ƒX‚Ì‰Šú‰»
	//boss.x = 0;
	//boss.y = 0;
	//boss.size = 0;
	//boss.maxhp = 0;
	//boss.hp = 0;
	boss.x = G_W_LEFT + (G_W_RIGHT - G_W_LEFT) / 2;
	boss.y = 80;
	boss.t = 0;
	boss.size = 25;
	boss.maxhp = 0;
	boss.hp = boss.maxhp;
	boss.totalhp = 0;
	boss.maxtotalhp = 0;
	boss.time = -1;
	boss.maxtime = 0;
	boss.mode = 0;
	boss.appear = 0;
	boss.muteki = 0;
	boss.vanish = 0;
}

//“G‚Ì‰Šú‰»
void EnemyInit(int i) {
	enemy[i].x = 0;
	enemy[i].y = 0;
	enemy[i].vx = 0;
	enemy[i].vy = 0;
	enemy[i].v = 0;
	enemy[i].hp = 0;	//hp‚Ì‰Šú‰»
	enemy[i].pattern = -1;
	enemy[i].t = 0;
	enemy[i].ang = 0;	//Šp“x‚Ì‰Šú‰»
	enemy[i].size = 25;	//“G‚ÌƒTƒCƒY‚ÌŽb’è“I‚È‰Šú‰»
	enemy[i].bt = 0;
	enemy[i].bkind = 0;
	enemy[i].color = 0;
	enemy[i].item = 0;
	enemy[i].vanish = 0;
	enemy[i].vanish_kind = 0;
}
