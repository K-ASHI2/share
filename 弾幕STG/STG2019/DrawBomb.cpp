#include"DxLib.h"
#include"extern.h"
#include"function.h"

//ボムのエフェクトの描画
void BombEffect() {

	double rate;	//画像の倍率
	switch(player.character){
	case player.D_Magician_A:
		DrawRotaGraph(G_W_CENTER_X, G_W_CENTER_Y, 1.25, 0, ani.starBomb[player.bomb_t - player.bomb_c], TRUE);
		break;
	case player.D_Magician_B:
		if (player.bomb_c > 240) {
			rate = 5.0 * (280 - player.bomb_c) / 40;
		}
		else if (player.bomb_c > 40) {
			rate = 5.0;
		}
		else {
			rate = 5.0 * player.bomb_c / 40;
		}
		DrawRotaGraph(player.bomb_x, player.bomb_y, rate, 0, img.blackhole, TRUE);
		break;
	case player.L_Magician_A:
		if (player.bomb_c < 60) {
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 156 * player.bomb_c / 60);
		}
		else {
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 156);
		}
		if (player.bomb_c > 300) {
			DrawRotaGraph(player.x, player.y - (638 * (360.0 - (double)player.bomb_c) / 60.0 / 2), 1.0 * (360.0 - (double)player.bomb_c) / 60.0, 0, img.bomb_laser, TRUE);
		}
		else {
			DrawRotaGraph(player.x, player.y - (638 / 2), 1, 0, img.bomb_laser, TRUE);
		}
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		break;
	case player.L_Magician_B: 
		rate = 15 * (90 - player.bomb_c) / 90.0;
		if (player.bomb_c < 30) {
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128 * player.bomb_c / 30);
		}
		else {
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
		}
		DrawRotaGraph(player.bomb_x, player.bomb_y, rate, 0, img.barrier, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		break;
	}
}
