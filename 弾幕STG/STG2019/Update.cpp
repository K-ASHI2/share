#include"DxLib.h"
#include"extern.h"
#include"function.h"

void Update(){
	switch(flag){
		case e_title:
			Title();
			break;

		case e_characterselect:
			CharacterSelect();
			break;

		case e_difficultyselect:
			DifficultySelect();
			break;

		case e_gameplay:
			//前のフレームで消滅した自機の弾の描画を消す
			for (int i = 0; i < BULLET; i++) {
				if (playerbullet[i].hp == -1) {
					playerbullet[i].hp = 0;
				}
			}
			MovePlayer();
			MoveEnemy();
			MovePlayerBullet();
			MoveEnemyBullet();
			MoveItem();
			MoveBackground();
			CreatePlayerBullet();
			CreateEnemy();
			CreateEnemyBullet();
			judge_player_to_enemy();
			judge_playerbullet_to_enemy();
		    judge_enemybullet_to_player();
			judge_player_to_item();
			if (boss_flag == eb_boss) {
				judge_player_to_boss();
				judge_playerbullet_to_boss();
			}
			Bomb();	//ボム後の処理
			PlayerDamaged();	//被弾後の処理
			Stage();	//ステージごとの固有処理
			BossAppear();

			//無敵時間の減少
			if (player.muteki > 0) {
				player.muteki--;
			}

			//属性モード中は自然にゲージが減る
			if (player.snowMode) {
				player.snowGauge--;
			}
			if (player.thunderMode) {
				player.thunderGauge--;
			}
			if (player.fireMode) {
				player.fireGauge--;
			}

			//ゲージ満タンになったらモードを変える;
			if (player.snowGauge >= MAX_ELEMENT) {
				player.snowGauge = MAX_ELEMENT;
				player.snowMode = true;
			}

			if (player.thunderGauge >= MAX_ELEMENT) {
				player.thunderGauge = MAX_ELEMENT;
				player.thunderMode = true;
			}

			if (player.fireGauge >= MAX_ELEMENT) {
				player.fireGauge = MAX_ELEMENT;
				player.fireMode = true;
			}

			if (player.snowGauge == 0) {
				player.snowMode = false;
			}

			if (player.thunderGauge == 0) {
				player.thunderMode = false;
			}

			if (player.fireGauge == 0) {
				player.fireMode = false;
			}

			//ステージ開始からの時間を増加する
			stageTimeCount++;

			//ハイスコアの更新
			if (hiscore < player.score) {
				hiscore = player.score;
			}
			//ゲームオーバー画面への移行
			if(player.life == 0){
				ChangeFlag(e_gameover);
			}
			//クリア画面への移行
			else if (boss_flag == eb_boss && boss.mode != 0 && boss.totalhp == 0 && boss.vanish == 0) {
				ChangeFlag(e_clear);
			}
			//ポーズボタンの処理
			else if (button[KEY_PAUSE] == 1) {
				ChangeFlag(e_pause);
			}
			break;

		case e_gameover:
			GameOver();
			break;

		case e_clear:
			Clear();
			break;

		case e_pause:
			Pause();
			break;

		case e_practice:
			Practice();
			break;

		case e_burragepractice:
			BurragePractice();
			break;

		case e_option:
			Option();
			break;

		case e_keyconfig:
			KeyConfig();
			break;

		case e_soundtest:
			SoundTest();
			break;
	}
}
