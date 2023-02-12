#include"define.h"

//‰æ‘œ‚Ì\‘¢‘Ì
struct _img {
	int player1_1;
	int player1_2;
	int player2_1;
	int player2_2;
	int player_J1;
	int player_J2;
	int shot[10];
	int shot_red;
	int crescent_cutter;
	int frush_bullet;
	int laser_red;
	int laser_sun;
	int ice_cutter;
	int fire_cutter;
	int thunder_cutter;
	int ice_missile;
	int fire_missile;
	int thunder_missile;
	int laser_ice;
	int laser_fire;
	int laser_thunder;
	int ice_frush_bullet;
	int fire_frush_bullet;
	int thunder_frush_bullet;
	int black_missile;
	int p_snow_bullet;
	int p_fire_bullet;
	int p_thunder_bullet;
	int blackhole;
	int bomb_laser;
	int barrier;

	int item;
	int score_item;
	int power_item;
	int power_item_L;

	int gameover;
	int clear;
	int clear_frame;
	int pause_frame;
	int title;
	int background_1;
	int background_2;
	int background_3;
	int background_4;
	int background_e;
	int background_firecloud;
	int arrow;
	int frame;
	int life;
	int bomb;
	int HPbar;
	int playerdamaged;


	/*’e*/
	//¬’e
	//int greenbullet;
	int bluebullet_S;
	int redbullet_S;
	int yellowbullet_S;
	//’†’e
	int bluebullet_M;
	int redbullet_M;
	int yellowbullet_M;
	//‘å’e
	int bluebullet_L;
	int redbullet_L;
	int yellowbullet_L;
	//‚»‚Ì‘¼
	int snowbullet_S;		//á’e
	int snowbullet_M;		//á’e
	int firebullet_S;		//‰Š’e
	int firebullet_M;		//‰Š’e
	int thunderbullet;	//—‹’e
	int star;
	int star_red;
	int star_blue;

	/*“G*/
	int ghost_S;
	int redghost_S;
	int blueghost_S;
	int yellowghost_S;
	int boss_magician;
	int boss_snake;
};

//ƒAƒjƒ[ƒVƒ‡ƒ“‚Ì\‘¢‘Ì
struct _anime {
	int starBomb[180];
	int BalletVanish[30];
	int RedBalletVanish[30];
	int BlueBalletVanish[30];
	int YellowBalletVanish[30];
	int EnemyVanish1[30];
	int EnemyVanish2[30];
	int EnemyVanish3[30];
	int EnemyVanish4[30];
	int EnemyVanish5[30];
	int playerdamaged[80];
};
