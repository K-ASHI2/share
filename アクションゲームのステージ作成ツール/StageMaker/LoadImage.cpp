#include"DxLib.h"
#include"extern.h"
#include"function.h"

//画像読み込み
void LoadImage() {

	img.hito[0] = LoadGraph("img/hito4.png");
	img.hito[1] = LoadGraph("img/hito1.png");
	img.hito[5] = LoadGraph("img/hito5.png");
	img.hito[6] = LoadGraph("img/hito6.png");
	img.hito[7] = LoadGraph("img/hito7.png");
	img.hito[8] = LoadGraph("img/hito8.png");
	img.hito[21] = LoadGraph("img/hito21.png");
	img.hito[22] = LoadGraph("img/hito22.png");
	img.hito[23] = LoadGraph("img/hito23.png");
	img.hito[24] = LoadGraph("img/hito24.png");
	img.attack = LoadGraph("img/attack2.png");//攻撃判定の画像(今は使ってない)
	img.kabe = LoadGraph("img/block1.png");
	img.block2 = LoadGraph("img/block2.png");
	img.yuka[0] = LoadGraph("img/yuka0.png");
	img.yuka[1] = LoadGraph("img/yuka1.png");
	img.yuka[2] = LoadGraph("img/yuka2.png");
	img.yuka[3] = LoadGraph("img/yuka3.png");
	img.yuka[4] = LoadGraph("img/yuka4.png");
	img.yuka[5] = LoadGraph("img/yuka5.png");
	img.yuka[6] = LoadGraph("img/yuka6.png");
	img.yuka[7] = LoadGraph("img/yuka7.png");
	img.yuka[8] = LoadGraph("img/yuka8.png");
	img.block_gray = LoadGraph("img/block_gray.png");
	img.block_wood = LoadGraph("img/block_wood.png");
	img.togeblock = LoadGraph("img/togeblock.png");
	img.togeblock2 = LoadGraph("img/togeblock2.png");
	img.togeblock3 = LoadGraph("img/togeblock3.png");
	img.togeblock4 = LoadGraph("img/togeblock4.png");
	img.iceblock = LoadGraph("img/iceblock.png");
	img.enemy[0] = LoadGraph("img/monster0.png");
	img.enemy[1] = LoadGraph("img/monster1.png");
	img.enemy[2] = LoadGraph("img/monster2.png");
	img.enemy[3] = LoadGraph("img/monster3.png");
	img.enemy[4] = LoadGraph("img/monster4.png");
	img.enemy[5] = LoadGraph("img/monster5.png");
	img.enemy[6] = LoadGraph("img/monster6.png");
	img.enemy[7] = LoadGraph("img/monster7.png");
	img.enemy[8] = LoadGraph("img/monster8.png");
	img.enemy[9] = LoadGraph("img/monster9.png");
	img.enemy[10] = LoadGraph("img/monster10.png");
	img.enemy[11] = LoadGraph("img/monster11.png");
	img.enemy[12] = LoadGraph("img/monster12.png");
	img.enemy[16] = LoadGraph("img/monster16.png");
	img.enemy[21] = LoadGraph("img/monster21.png");
	img.enemy[26] = LoadGraph("img/monster26.png");
	img.enemy[27] = LoadGraph("img/monster27.png");
	img.enemy[31] = LoadGraph("img/monster31.png");
	img.enemy[32] = LoadGraph("img/monster32.png");
	img.enemy[33] = LoadGraph("img/monster33.png");
	img.enemy[34] = LoadGraph("img/monster34.png");
	img.enemy[35] = LoadGraph("img/monster35.png");
	img.cloud_monster = LoadGraph("img/cloud_monster.png");
	img.cloud_monster_blue = LoadGraph("img/cloud_monster_blue.png");
	img.boss[0] = LoadGraph("img/boss.png");
	img.boss[1] = LoadGraph("img/boss11.png");
	img.boss[2] = LoadGraph("img/boss12.png");
	img.boss[3] = LoadGraph("img/boss13.png");
	img.boss[4] = LoadGraph("img/boss4.png");
	img.meteor = LoadGraph("img/meteor.png");
	img.fire = LoadGraph("img/fire.png");
	img.taihou[0] = LoadGraph("img/taihou.png");
	img.taihou[1] = LoadGraph("img/taihou1.png");
	img.taihou[2] = LoadGraph("img/taihou2.png");
	img.taihou[3] = LoadGraph("img/taihou3.png");
	img.taihou[4] = LoadGraph("img/taihou4.png");
	img.taihou[5] = LoadGraph("img/taihou5.png");
	img.taihou[6] = LoadGraph("img/taihou6.png");
	img.bullet[0] = LoadGraph("img/bullet0.png");
	img.bullet[1] = LoadGraph("img/bullet1.png");
	img.bullet[2] = LoadGraph("img/bullet2.png");
	img.bullet[3] = LoadGraph("img/bullet3.png");
	img.bullet[4] = LoadGraph("img/bullet4.png");
	img.bullet[5] = LoadGraph("img/bullet5.png");
	img.gameover = LoadGraph("img/gameover.png");
	img.title = LoadGraph("img/title.png");
	img.clear = LoadGraph("img/clear.png");
	img.allclear = LoadGraph("img/allclear.png");
	img.null = LoadGraph("img/null.png");
	img.arrow = LoadGraph("img/arrow.png");
	img.toge = LoadGraph("img/toge2.png");
	img.moveblock[0] = LoadGraph("img/vanish_block.png");
	img.moveblock[1] = LoadGraph("img/moveblock1.png");
	img.moveblock[2] = LoadGraph("img/moveblock2.png");
	img.moveblock[3] = LoadGraph("img/moveblock3.png");
	img.moveblock[4] = LoadGraph("img/moveblock4.png");
	img.moveblock[5] = LoadGraph("img/vanish_block.png");
	img.moveblock[6] = LoadGraph("img/moveblock6.png");
	img.moveblock[7] = LoadGraph("img/moveblock7.png");
	img.item = LoadGraph("img/item1.png");
	img.item2 = LoadGraph("img/item2.png");
	img.max_item = LoadGraph("img/itemF.png");
	img.door[0] = LoadGraph("img/door2.png");
	img.door[1] = LoadGraph("img/door.png");
	img.door[2] = LoadGraph("img/door3.png");
	img.door[3] = LoadGraph("img/door5.png");
	img.door[8] = LoadGraph("img/door8.png");
	img.setumei = LoadGraph("img/setumei.png");
	img.sw[0] = LoadGraph("img/sw0.png");
	img.sw[1] = LoadGraph("img/sw1.png");
	img.sw[2] = LoadGraph("img/sw2.png");
	img.swb[0] = LoadGraph("img/swblock.png");
	img.swb[1] = LoadGraph("img/swblock1.png");
	img.swb[2] = LoadGraph("img/swblock2.png");
	img.swb[3] = LoadGraph("img/swblock3.png");
	img.maguma = LoadGraph("img/maguma.png");

	//ステージ作成にのみ用いる画像
	img.scrollbar = LoadGraph("img/scrollbar.png");
	img.scrollbarV = LoadGraph("img/scrollbarV.png");
	img.bar1 = LoadGraph("img/bar1.png");
	img.bar2 = LoadGraph("img/bar2.png");
	img.bar3 = LoadGraph("img/bar3.png");
	img.barUP = LoadGraph("img/scrollbarUP.png");
	img.barDOWN = LoadGraph("img/scrollbarDOWN.png");
	img.barRIGHT = LoadGraph("img/scrollbarRIGHT.png");

	img.white_frame = LoadGraph("img/white_frame.png");
	img.cs_bg[0] = LoadGraph("img/cs_bg.png");
	img.cs_bg[1] = LoadGraph("img/cs_bg2.png");
	img.cs_bg[2] = LoadGraph("img/cs_bg3.png");
	img.cs_bg[3] = LoadGraph("img/cs_bg4.png");
	img.cs_bg[4] = LoadGraph("img/cs_bg5.png");
	img.grid = LoadGraph("img/grid.png");
	img.grid2 = LoadGraph("img/grid2.png");
	img.through = LoadGraph("img/throughblock.png");
	img.s_frame = LoadGraph("img/s_frame.png");
	img.circle = LoadGraph("img/circle.png");
	img.circle2 = LoadGraph("img/circle2.png");
	img.circle3 = LoadGraph("img/circle3.png");
	img.graysquare = LoadGraph("img/graysquare.png");
	img.b_line = LoadGraph("img/blue_line2.png");
	img.linemove1 = LoadGraph("img/linemove1.png");
	img.linemove2 = LoadGraph("img/linemove2.png");
	img.linemove3 = LoadGraph("img/linemove3.png");
	img.linemove_up = LoadGraph("img/linemove_up.png");
	img.linemove_down = LoadGraph("img/linemove_down.png");
	img.firebar = LoadGraph("img/firebar.png");

	img.star = LoadGraph("img/bullet/star_bullet.png");
	img.star_red = LoadGraph("img/bullet/star_bullet_red.png");
	img.star_blue = LoadGraph("img/bullet/star_bullet_blue.png");

	/*敵*/
	img.moon_enemy = LoadGraph("img/enemy/moon_enemy.png");
	img.needle_enemy = LoadGraph("img/enemy/needle_enemy.png");
	img.ghost_S = LoadGraph("img/enemy/ghost_S.png");
	img.redghost_S = LoadGraph("img/enemy/redghost_S.png");
	img.yellowghost_S = LoadGraph("img/enemy/yellowghost_S.png");
	img.blueghost_S = LoadGraph("img/enemy/blueghost_S.png");
	img.fish = LoadGraph("img/enemy/fish.png");
	img.boss_blue = LoadGraph("img/enemy/boss_blue.png");
	img.boss_magician = LoadGraph("img/enemy/boss_magician.png");
	img.boss_snake = LoadGraph("img/enemy/boss_snake.png");
}

void LoadAnime() {
	LoadDivGraph("ani/star.png", 30, 5, 6, 96, 96, ani.star_e);
	LoadDivGraph("ani/convergence_r2.png", 30, 5, 6, 32, 32, ani.convergence_r);
	//アニメーションのロード
	LoadDivGraph("ani/starBomb.png", 180, 13, 14, 511, 511, ani.starBomb);
	LoadDivGraph("ani/bulletvanish.png", 30, 5, 6, 64, 64, ani.BalletVanish);
	LoadDivGraph("ani/redbulletvanish.png", 30, 5, 6, 64, 64, ani.RedBalletVanish);
	LoadDivGraph("ani/bluebulletvanish.png", 30, 5, 6, 64, 64, ani.BlueBalletVanish);
	LoadDivGraph("ani/yellowbulletvanish.png", 30, 5, 6, 64, 64, ani.YellowBalletVanish);
	LoadDivGraph("ani/enemyvanish1.png", 30, 5, 6, 80, 80, ani.EnemyVanish1);
	LoadDivGraph("ani/enemyvanish2.png", 30, 5, 6, 80, 80, ani.EnemyVanish2);
	LoadDivGraph("ani/enemyvanish3.png", 30, 5, 6, 80, 80, ani.EnemyVanish3);
	LoadDivGraph("ani/enemyvanish4.png", 30, 5, 6, 80, 80, ani.EnemyVanish4);
	LoadDivGraph("ani/enemyvanish5.png", 30, 5, 6, 80, 80, ani.EnemyVanish5);
	LoadDivGraph("ani/playerdameged.png", 80, 8, 10, 128, 128, ani.playerdamaged);
}
