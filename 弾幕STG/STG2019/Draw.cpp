#include"DxLib.h"
#include"extern.h"
#include"function.h"
#include"math.h"

void Draw() {
	ClearDrawScreen();  //画面に描画されているものを消す

	switch (flag) {
	case e_title:
		DrawTitle();
		break;

	case e_characterselect:
		DrawCharacterSelect();
		break;

	case e_difficultyselect:
		DrawDifficultySelect();
		break;

	case e_gameplay:
		DrawPlay();
		break;

	case e_gameover:
		DrawGameover();
		break;

	case e_clear:
		DrawClear();
		break;

	case e_pause:
		DrawPause();
		break;

	case e_practice:
		DrawPractice();
		break;   

	case e_burragepractice:
		DrawBulletPractice();
		break;

	case e_option:
		DrawOption();
		break;

	case e_keyconfig:
		DrawKeyConfig();
		break;
		
	case e_soundtest:
		DrawSoundTest();
		break;   //ポーズ画面
	}
	DrawEx();//操作説明の表示
	ScreenFlip();
}
