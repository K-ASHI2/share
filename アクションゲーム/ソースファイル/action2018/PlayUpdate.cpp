#include"DxLib.h"
#include"extern.h"
#include"function.h"

//�Q�[���v���C���̃A�b�v�f�[�g����
void playUpdate() {

	//�Q�[���I�[�o�[�ɂȂ��ĂȂ��Ȃ�Q�[������������
	if (gameover_count == -1) {
		create_enemy();			//�G�̐���
		blockmove();			//�������̈ړ�
		move();					//�v���C���[�̈ړ�
		enemymove();			//�G�̈ړ�
		create_enemybullet();	//�G�̒e�̐���
		move_enemybullet();		//�G�̒e�̈ړ�
		moveFirebar();			//�t�@�C�A�o�[�̉�]
		move_background();
		attack();				//�U��
								//�Q�[���J�n����̎��Ԃ̃J�E���g
		if (countTime < INT_MAX)
			countTime++;

		//���G���Ԃ̌���
		if (player.muteki > 0)
			player.muteki--;

		//�Q�[���I�[�o�[�̔���
		if (player.y > 512 || player.life <= 0) {
			gameover_count = DAMEGED_EFFECT;
		}

		//�|�[�Y�{�^���������ꂽ��|�[�Y��ʂɂ���
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
