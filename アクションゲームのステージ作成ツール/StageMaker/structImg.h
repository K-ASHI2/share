#pragma once

//画像関連の構造体
struct S_img {
	int hito[30];
	int attack;
	int kabe;
	int block2;
	int through;
	int yuka[9];
	int block_gray;
	int block_wood;
	int goal;
	int enemy[36];
	int cloud_monster;
	int cloud_monster_blue;
	int meteor;
	int taihou[7];
	int bullet[6];
	int gameover;
	int title;
	int clear;
	int allclear;
	int background[BACKGROUND_MAX];
	int cloud;
	int null;
	int arrow;
	int toge;
	int togeblock;
	int togeblock2;
	int togeblock3;
	int togeblock4;
	int moveblock[8];
	int iceblock;
	int item;
	int item2;
	int max_item;
	int door[9];
	int fire;
	int setumei;
	int sw[3];
	int swb[4];
	int maguma;
	int boss[5];
	int scrollbar;
	int scrollbarV;
	int bar1;
	int bar2;
	int bar3;
	int barUP;
	int barDOWN;
	int barRIGHT;
	int white_frame;
	int cs_bg[5];//ステージ作りの画面の下の背景
	int grid;
	int grid2;
	int s_frame;
	int circle;
	int circle2;
	int circle3;
	int graysquare;
	int b_line;
	int linemove1;
	int linemove2;
	int linemove3;
	int linemove_up;
	int linemove_down;
	int firebar;

	int star;
	int star_red;
	int star_blue;

	/*敵*/
	int moon_enemy;
	int needle_enemy;
	int ghost_S;
	int redghost_S;
	int blueghost_S;
	int yellowghost_S;
	int fish;
	int boss_blue;
	int boss_magician;
	int boss_snake;
};

struct S_anime {
	int star_e[30];
	int convergence_r[30];
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
