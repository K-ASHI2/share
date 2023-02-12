#include"define.h"
#include"structPlayer.h"
#include"structEnemy.h"
#include"structImg.h"
#include"structMusic.h"
#include"enum.h"

//’e‚Ìstruct
struct S_bullet {
	double x, y;
	double vx, vy;
	double v;//is•ûŒü‚Éi‚Ş‘¬“x
	int life;    //life‚ª0‚È‚ç‰æ–Êã‚É‘¶İ‚µ‚Ä‚¢‚È‚¢A1‚È‚ç‘¶İ‚µ‚Ä‚¢‚é
	int atk;     //’e‚ÌUŒ‚—Í
	int size_x;
	int size_y;
	int species; //’e‚Ìí—Ş
	int rad_i;	 //’e‚Ì‰Šú‚ÌŒX‚«
	int rad_b;	 //’e‚Ì‰ñ“]Šp
	int rad_v;	 //’e‚ÌŠp‘¬“x
};

//“Ç‚İ‚Ü‚ê”wŒi‚Ìƒf[ƒ^(”z—ñ‚É“ü‚ê‚é)
struct S_background {
	int size_x;
	int size_y;
	int img;
};

//”wŒi‚ÌƒXƒe[ƒ^ƒX(Œ»İ‚ÌˆÊ’u‚â‘¬“x‚Ì‚İ‚Â)
struct S_background2 {
	int x, y;
	int vy;
};
