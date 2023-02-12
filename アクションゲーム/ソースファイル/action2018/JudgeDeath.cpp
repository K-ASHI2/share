#include"DxLib.h"
#include"extern.h"
#include"function.h"

//壁に重なっていたらゲームオーバー
void judge_death(int blx, int bly) {
	if (blx < (player.x + HERO_SIZE_X) && player.x < (blx + BLOCK) && bly < (player.y + HERO_SIZE_Y) && player.y < (bly + BLOCK)) {
		player.life = 0;
	}
}

//すり抜け床に重なっていたらゲームオーバー
//未実装
void judge_death2(int blx, int bly) {
	if (blx < (player.x + HERO_SIZE_X) && player.x < (blx + BLOCK) && bly < (player.y + HERO_SIZE_Y) && player.y < (bly + BLOCK) && player.by < bly) {
		//player.life = 0;
	}
}

//動く床と重なっていたらゲームオーバー
void judge_death3(double ex, double ey) {
	if (ex < player.x + HERO_SIZE_X &&  player.x < ex + BLOCK && ey < player.y + HERO_SIZE_Y && player.y < ey + BLOCK) {
		player.life = 0;
	}
}
