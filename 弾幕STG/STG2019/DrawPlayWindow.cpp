#include"DxLib.h"
#include"extern.h"
#include"function.h"
#include"math.h"

void DrawPlayWindow() {
	//ゲームプレイ中の画面外の描画
	DrawGraph(0, 0, img.frame, TRUE);       //外枠

	//難易度の表示
	int color = white;	//難易度の色
	char *dif_c[8];		//難易度の文字列
	switch (difficulty) {
	case ed_easy: color = red; *dif_c = "EASY";  break;
	case ed_normal: color = greenblue; *dif_c = "NORMAL"; break;
	case ed_hard: color = liteblack; *dif_c = "HARD";  break;
	case ed_lunatic: color = silver; *dif_c = "LUNATIC"; break;
	}
	DrawStringToHandle(625, 15, *dif_c, color, Font[0]);	//難易度表示

	//ハイスコア
	DrawStringToHandle(535, 50, "HISCORE", black, Font[0]);
	//10桁のスコアを一けたずつ計算して表示する
	for (int i = 0; i < 10; i++) {
		int s = hiscore % (int)pow(10.0, (double)(i + 1));
		if (i > 0) {
			s /= (int)pow(10.0, (double)i);
		}
		DrawFormatStringToHandle(750 - 12 * i, 50, black, Font[0], "%d", s);
	}

	//スコア
	DrawStringToHandle(535, 80, "SCORE", black, Font[0]);
	//オーバーフロー対策
	if (player.score > 10000000000) {
		player.score = 9999999999;
	}
	//10桁のスコアを一けたずつ計算して表示する
	for (int i = 0; i < 10; i++) {
		long long s = player.score % (long long)pow(10.0, (double)(i + 1));
		if (i > 0) {
			s /= (int)pow(10.0, (double)i);
		}
		DrawFormatStringToHandle(750 - 12 * i, 80, black, Font[0], "%d", s);
	}

	//残機
	DrawStringToHandle(535, 120, "LIFE", black, Font[0]);
	for (int i = 0; i < player.life - 1; i++) {
		if (i >= 8) {
			break;
		}
		DrawGraph(595 + i * 22, 120, img.life, TRUE);
	}
	//ボム
	DrawStringToHandle(535, 150, "BOMB", black, Font[0]);
	for (int i = 0; i < player.bomb; i++) {
		if (i >= 8) {
			break;
		}
		DrawGraph(595 + i * 22, 150, img.bomb, TRUE);
	}

	//パワー
	DrawStringToHandle(535, 185, "POWER", black, Font[0]);
	DrawFormatStringToHandle(683, 185, black, Font[0], "%3.2f", player.power);
	//最高点
	DrawStringToHandle(535, 215, "ITEM SCORE", black, Font[0]);
	DrawFormatStringToHandle(650, 215, black, Font[0], "%7d", player.maxscore);
	//グレイズ
	DrawStringToHandle(535, 245, "GRAZE", black, Font[0]);
	DrawFormatStringToHandle(650, 245, black, Font[0], "%7d", player.graze);
	//HPバーの描画
	DrawHPBar();

	//属性のバーの描画
	DrawElementBar();

	//制限時間
	if (boss_flag == eb_boss && boss.time >= 0) {
		DrawFormatStringToHandle(475, 40, black, Font[0], "%2d", boss.time / 120);
	}

	//デバッグ用の数値
	//DrawFormatString(580, 360, black, "bomb_c  : %3d", player.bomb_c);
	//DrawFormatString(580, 390, black, "damaged : %3d", player.damaged);
	//DrawFormatString(580, 420, black, "item_k: %3d", item[0].kind);
	//DrawFormatString(580, 450, black, "sTCount  : %3d", stageTimeCount);
}

//属性のバーの描画
void DrawElementBar() {

	static int x = 628;
	static int gf = 3;	//外枠の幅
	static int gaugeX = 160, gaugeY = 20;	//ゲージの幅

	static int gx = gaugeX - gf * 2, gy = 20 - gf * 2;	//ゲージの中身の幅

	//属性ゲージの最大値
	//static int MAX_ELEMENT = 1000;

	{
		static int y1 = 359;	//ゲージのx座標、y座標
		//現在の攻撃のHPバー
		DrawStringToHandle(x - 68, y1 + 1, "ICE", black, Font[0]);

		//HPバーの中の背景
		static int hx1 = x + gf, hy1 = y1 + gf, hx2 = x + gf + gx, hy2 = y1 + gf + gy;
		DrawBox(hx1, hy1, hx2, hy2, GetColor(144, 144, 144), TRUE);

		//HPバーの外枠の描画
		DrawGraph(x, y1, img.HPbar, TRUE);

		//HPのゲージを表示する
		int hb = gx * player.snowGauge / MAX_ELEMENT;

		DrawBox(hx1, hy1, hx1 + hb, hy2, GetColor(84, 255, 255), TRUE);
	}

	/*サンダーゲージ*/

	{
		static int y1 = 389;

		//現在の攻撃のHPバー
		DrawStringToHandle(x - 90, y1 + 1, "THUNDER", black, Font[0]);

		//HPバーの中の背景
		static int hx1 = x + gf, hy1 = y1 + gf, hx2 = x + gf + gx, hy2 = y1 + gf + gy;
		DrawBox(hx1, hy1, hx2, hy2, GetColor(144, 144, 144), TRUE);

		//HPバーの外枠の描画
		DrawGraph(x, y1, img.HPbar, TRUE);

		//HPのゲージを表示する
		int hb = gx * player.thunderGauge / MAX_ELEMENT;

		DrawBox(hx1, hy1, hx1 + hb, hy2, GetColor(255, 255, 56), TRUE);
	}

	/*ファイアゲージ*/

	{
		static int y1 = 419;

		//現在の攻撃のHPバー
		DrawStringToHandle(x - 70, y1 + 1, "FIRE", black, Font[0]);

		//HPバーの中の背景
		static int hx1 = x + gf, hy1 = y1 + gf, hx2 = x + gf + gx, hy2 = y1 + gf + gy;
		DrawBox(hx1, hy1, hx2, hy2, GetColor(144, 144, 144), TRUE);

		//HPバーの外枠の描画
		DrawGraph(x, y1, img.HPbar, TRUE);

		//HPのゲージを表示する
		int hb = gx * player.fireGauge / MAX_ELEMENT;

		DrawBox(hx1, hy1, hx1 + hb, hy2, GetColor(255, 80, 0), TRUE);
	}
}

//HPバーの描画
void DrawHPBar() {
	static int x = 628, y1 = 279, y2 = 309;	//ゲージのx座標、y座標
	static int gf = 3;	//外枠の幅
	static int gaugeX = 160, gaugeY = 20;	//ゲージの幅

	static int gx = gaugeX - gf * 2, gy = 20 - gf * 2;	//ゲージの中身の幅

	//現在の攻撃のHPバー
	DrawStringToHandle(x - 88, y1 + 1, "MODE HP", black, Font[0]);

	//HPバーの中の背景
	static int hx1 = x + gf, hy1 = y1 + gf, hx2 = x + gf + gx, hy2 = y1 + gf + gy;
	DrawBox(hx1, hy1, hx2, hy2, GetColor(144, 144, 144), TRUE);

	//HPバーの外枠の描画
	DrawGraph(x, y1, img.HPbar, TRUE);

	//HPのゲージを表示する
	int hb = 0;
	//0で割らないようにする
	if (boss.maxhp != 0) {
		hb = gx * boss.hp / boss.maxhp;
	}
	//ボスのHPがある間はゲージが0にならないようにする
	if (hb == 0 && boss.hp > 0) {
		hb = 1;
	}
	DrawBox(hx1, hy1, hx1 + hb, hy2, GetHPColor((int)boss.hp, (int)boss.maxhp), TRUE);


	//合計のHPバー
	DrawStringToHandle(x - 93, y2 + 1, "TOTAL HP", black, Font[0]);
	static int tx1 = x + gf, ty1 = y2 + gf, tx2 = x + gf + gx, ty2 = y2 + gf + gy;
	DrawBox(tx1, ty1, tx2, ty2, GetColor(144, 144, 144), TRUE);	//HPバーの中の背景
	DrawGraph(x, y2, img.HPbar, TRUE);	//HPバーの外枠の描画

	//合計HPのゲージを表示する
	int hb2 = 0;
	if (boss.maxtotalhp != 0) {
		hb2 = gx * boss.totalhp / boss.maxtotalhp;
	}
	DrawBox(tx1, ty1, tx1 + hb2, ty2, GetColor(127, 191, 255), TRUE);
	//ボスのHPがある間はゲージが0にならないようにする
	if (hb == 0 && boss.hp > 0) {
		hb = 1;
	}
}

//敵の体力に応じたHPバーの色を返す関数
int GetHPColor(int hp, int maxhp) {

	int Red, Green, Blue;

	//0で割ることを回避
	if (maxhp == 0) {
		return 0;
	}
	//hp半分で区切るので変化量も半分となる
	//hpが半分以上の時(緑→黄色)
	if (hp >= maxhp / 2) {
		Red = 355 - 243 * hp / maxhp;
		Green = 255;
		Blue = 112;
	}
	//hpが半分未満の時(黄色→赤)
	else {
		Red = 255;
		Green = 510 * hp / maxhp;
		Blue = 224 * hp / maxhp;
	}
	return GetColor(Red, Green, Blue);
}
