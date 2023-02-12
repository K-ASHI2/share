#include"DxLib.h"
#include"extern.h"
#include"function.h"

//画像をロードする関数
void LoadImage() {
	//プレイヤー関連の画像
	img.player1_1 = LoadGraph("img/player/player1-1.png");
	img.player1_2 = LoadGraph("img/player/player1-2.png");
	img.player2_1 = LoadGraph("img/player/player2-1.png");
	img.player2_2 = LoadGraph("img/player/player2-2.png");
	img.player_J1 = LoadGraph("img/player/playerJ1.png");
	img.player_J2 = LoadGraph("img/player/playerJ2.png");
	img.shot[0] = LoadGraph("img/player/shot.png");
	img.shot_red = LoadGraph("img/player/shot_red.png");
	img.shot[1] = LoadGraph("img/player/shot1.png");
	img.shot[2] = LoadGraph("img/player/shot2.png");
	img.shot[3] = LoadGraph("img/player/shot3.png");
	img.shot[4] = LoadGraph("img/player/shot4.png");
	img.crescent_cutter = LoadGraph("img/player/crescent_cutter.png");
	img.frush_bullet = LoadGraph("img/player/frush_bullet.png");
	img.playerdamaged = LoadGraph("img/player/playerdamaged.png");
	img.laser_red = LoadGraph("img/player/laser_red.png");
	img.laser_sun = LoadGraph("img/player/laser_sun.png");
	img.ice_cutter = LoadGraph("img/player/ice_cutter.png");
	img.fire_cutter = LoadGraph("img/player/fire_cutter.png");
	img.thunder_cutter = LoadGraph("img/player/thunder_cutter.png");
	img.ice_missile = LoadGraph("img/player/ice_missile.png");
	img.fire_missile = LoadGraph("img/player/fire_missile.png");
	img.thunder_missile = LoadGraph("img/player/thunder_missile.png");
	img.laser_ice = LoadGraph("img/player/laser_ice.png");
	img.laser_fire = LoadGraph("img/player/laser_fire.png");
	img.laser_thunder = LoadGraph("img/player/laser_thunder.png");
	img.ice_frush_bullet = LoadGraph("img/player/ice_frush_bullet.png");
	img.fire_frush_bullet = LoadGraph("img/player/fire_frush_bullet.png");
	img.thunder_frush_bullet = LoadGraph("img/player/thunder_frush_bullet.png");
	img.black_missile = LoadGraph("img/player/black_missile.png");
	img.p_snow_bullet = LoadGraph("img/player/p_snow_bullet.png");
	img.p_fire_bullet = LoadGraph("img/player/p_fire_bullet.png");
	img.p_thunder_bullet = LoadGraph("img/player/p_thunder_bullet.png");
	img.blackhole = LoadGraph("img/player/blackhole.png");
	img.bomb_laser = LoadGraph("img/player/bomb_laser.png");
	img.barrier = LoadGraph("img/player/barrier.png");
	
	//アイテム関連の画像
	img.item = LoadGraph("img/item/item.png");
	img.score_item = LoadGraph("img/item/score_item.png");
	img.power_item = LoadGraph("img/item/power_item.png");
	img.power_item_L = LoadGraph("img/item/power_item_L.png");
	//メニュー関連の画像
	img.clear_frame = LoadGraph("img/menu/clear_frame.png");
	img.pause_frame = LoadGraph("img/menu/pause_frame.png");
	img.gameover = LoadGraph("img/menu/gameover.png");
	img.title = LoadGraph("img/menu/title.png");
	img.arrow = LoadGraph("img/menu/arrow.png");		//選択肢の矢印の画像
	img.life = LoadGraph("img/menu/life.png");			//残機の画像
	img.bomb = LoadGraph("img/menu/bomb.png");			//ボムの数の星
	img.frame = LoadGraph("img/menu/frame.png");
	img.HPbar = LoadGraph("img/menu/HPbar.png");

	/*弾*/
	//小弾
	img.bluebullet_S = LoadGraph("img/bullet/blue_bullet_S.png");
	img.redbullet_S = LoadGraph("img/bullet/red_bullet_S.png");
	img.yellowbullet_S = LoadGraph("img/bullet/yellow_bullet_S.png");
	//中弾
	img.bluebullet_M = LoadGraph("img/bullet/blue_bullet_M.png");
	img.redbullet_M = LoadGraph("img/bullet/red_bullet_M.png");
	img.yellowbullet_M = LoadGraph("img/bullet/yellow_bullet_M.png");
	//大弾
	img.bluebullet_L = LoadGraph("img/bullet/blue_bullet_L.png");
	img.redbullet_L = LoadGraph("img/bullet/red_bullet_L.png");
	img.yellowbullet_L = LoadGraph("img/bullet/yellow_bullet_L.png");
	//その他
	img.snowbullet_S = LoadGraph("img/bullet/snow_bullet_S.png");
	img.snowbullet_M = LoadGraph("img/bullet/snow_bullet_M.png");
	img.firebullet_S = LoadGraph("img/bullet/fire_bullet_S.png");
	img.firebullet_M = LoadGraph("img/bullet/fire_bullet_M.png");
	img.thunderbullet = LoadGraph("img/bullet/thunder_bullet.png");
	img.star = LoadGraph("img/bullet/star_bullet.png");
	img.star_red = LoadGraph("img/bullet/star_bullet_red.png");
	img.star_blue = LoadGraph("img/bullet/star_bullet_blue.png");

	/*敵*/
	img.ghost_S = LoadGraph("img/enemy/ghost_S.png");
	img.redghost_S = LoadGraph("img/enemy/redghost_S.png");
	img.yellowghost_S = LoadGraph("img/enemy/yellowghost_S.png");
	img.blueghost_S = LoadGraph("img/enemy/blueghost_S.png");
	img.boss_magician = LoadGraph("img/enemy/boss_magician.png");
	img.boss_snake = LoadGraph("img/enemy/boss_snake.png");

	//背景
	img.background_1 = LoadGraph("img/background/b_cloud.png");
	img.background_2 = LoadGraph("img/background/b_snow.png");
	img.background_3 = LoadGraph("img/background/b_darkcloud.png");
	img.background_4 = LoadGraph("img/background/b_darkcave.png");
	img.background_e = LoadGraph("img/background/b_check.png");
	img.background_firecloud = LoadGraph("img/background/b_firecloud2.png");
}

//ロード
void Load(){ 

	//画像のロード
	LoadImage();

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

	//音楽のロード
	LoadMusic();

	//ハイスコアのロード
	LoadHiscore();
}
