#include"DxLib.h"
#include"extern.h"
#include"function.h"

//ゲームプレイ中のアップデート処理
void playUpdate() {

	//ゲームオーバーになってないならゲーム処理をする
	if (gameover_count == -1) {
		create_enemy();			//敵の生成
		blockmove();			//動く床の移動
		move();					//プレイヤーの移動
		enemymove();			//敵の移動
		create_enemybullet();	//敵の弾の生成
		move_enemybullet();		//敵の弾の移動
		moveFirebar();			//ファイアバーの回転
		move_background();
		attack();				//攻撃
								//ゲーム開始からの時間のカウント
		if (countTime < INT_MAX)
			countTime++;

		//無敵時間の減少
		if (player.muteki > 0)
			player.muteki--;

		//ゲームオーバーの判定
		if (player.y > 512 || player.life <= 0) {
			gameover_count = DAMEGED_EFFECT;
		}

		//ポーズボタンが押されたらポーズ画面にする
		if (button[KEY_PAUSE] == 1) {
			change_flag(e_pause);
		}
	}
	else if (gameover_count == 0) {
		change_flag(e_gameover);
	}
	else {
		gameover_count--;
	}
}
