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
			//�O�̃t���[���ŏ��ł������@�̒e�̕`�������
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
			Bomb();	//�{����̏���
			PlayerDamaged();	//��e��̏���
			Stage();	//�X�e�[�W���Ƃ̌ŗL����
			BossAppear();

			//���G���Ԃ̌���
			if (player.muteki > 0) {
				player.muteki--;
			}

			//�������[�h���͎��R�ɃQ�[�W������
			if (player.snowMode) {
				player.snowGauge--;
			}
			if (player.thunderMode) {
				player.thunderGauge--;
			}
			if (player.fireMode) {
				player.fireGauge--;
			}

			//�Q�[�W���^���ɂȂ����烂�[�h��ς���;
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

			//�X�e�[�W�J�n����̎��Ԃ𑝉�����
			stageTimeCount++;

			//�n�C�X�R�A�̍X�V
			if (hiscore < player.score) {
				hiscore = player.score;
			}
			//�Q�[���I�[�o�[��ʂւ̈ڍs
			if(player.life == 0){
				ChangeFlag(e_gameover);
			}
			//�N���A��ʂւ̈ڍs
			else if (boss_flag == eb_boss && boss.mode != 0 && boss.totalhp == 0 && boss.vanish == 0) {
				ChangeFlag(e_clear);
			}
			//�|�[�Y�{�^���̏���
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
