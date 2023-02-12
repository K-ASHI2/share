#include"DxLib.h"
#include"extern.h"
#include"function.h"
#include<math.h>
#include<cmath>

//“G‚Ì’e‚ğì‚éŠÖ”
void CreateEnemyBullet() {

	/*double ang;
	if (boss.mode == 2) {
		if (boss.hp != 0) {
			boss.t++;
			if (boss.t % 15 == 0) {
				int i = getEnemyBulletNumber();
				enemybullet[i].hp = 1;
				SetEBKind(ebk_blue_S, i);
				enemybullet[i].x = boss.x;
				enemybullet[i].y = boss.y + boss.size;
				ang = atan2((double)((player.y + player.size / 2) - (boss.y + boss.size)), (double)((player.x + player.size / 2) - boss.x));
				enemybullet[i].vx = cos(ang) * 2;
				enemybullet[i].vy = sin(ang) * 2;
			}
		}
	}
	*/
}

//¶¬‰Â”\‚È’e‚Ì”z—ñ‚Ì”Ô†‚ğæ“¾‚·‚éŠÖ”
int getEnemyBulletNumber() {

	//’e‚ª‘¶İ‚¹‚¸Á–Å‰‰o‚ªI‚í‚Á‚Ä‚¢‚é’e‚ğ‘I‚Ô
	for (int i = 0; i < ENEMYBULLET; i++) {
		if (enemybullet[i].hp == 0 && enemybullet[i].vanish == 0) {
			return i;
		}
	}
	return 0;
}
