#include"DxLib.h"
#include"extern.h"
#include"function.h"
#include<math.h>
#include<cmath>

//���@�̒e�����֐�
void CreatePlayerBullet() {

	if (button[KEY_SHOT] > 0 && player.inope == 0) {
		player.t++;

		//���ꂼ��̃V���b�g�ɂ���1�b�ɗ^����_���[�W�ʂ�\������

		//���C���V���b�g
		//30
		if (player.t % 10 == 1) {
			if (player.character == player.D_Magician_A || player.character == player.D_Magician_B) {
				CreatePlayerBullet2(5, 0, -11, player.x - 7, player.y - 10, 0);
				CreatePlayerBullet2(5, 0, -11, player.x + 7, player.y - 10, 0);
			}
			else {
				CreatePlayerBullet2(5, 0, -11, player.x - 7, player.y - 10, -1);
				CreatePlayerBullet2(5, 0, -11, player.x + 7, player.y - 10, -1);
			}
		}
		switch (player.character) {
		case player.D_Magician_A:
			//���C�h�V���b�g
			//45 + 5.2n (2hit�̂�) + 19.5 + 2.4n (3hit�Ȃ�ǉ�) + 30(���C���V���b�g)
			if (player.t % 40 == 1) {
				CreatePlayerBullet2(15.0 + (int)player.power * 1.3, 0, -7, player.x - 7, player.y - 10, 4);
				CreatePlayerBullet2(15.0 + (int)player.power * 1.3, 0, -7, player.x + 7, player.y - 10, 4);
				CreatePlayerBullet2(13.0 + (int)player.power * 1.2, -0.5, -7, player.x - 14, player.y - 10, 4);
				CreatePlayerBullet2(13.0 + (int)player.power * 1.2, 0.5, -7, player.x + 14, player.y - 10, 4);
				CreatePlayerBullet2(12.0 + (int)player.power * 1.2, -1.5, -7, player.x - 14, player.y - 10, 4);
				CreatePlayerBullet2(11.0 + (int)player.power * 1.2, 1.5, -7, player.x + 14, player.y - 10, 4);
				CreatePlayerBullet2(11.0 + (int)player.power * 1.1, -2.0, -7, player.x - 14, player.y - 10, 4);
				CreatePlayerBullet2(11.0 + (int)player.power * 1.1, 2.0, -7, player.x + 14, player.y - 10, 4);
			}
			//18(2hit), 25.75(3hit)
			if (player.snowMode) {
				if (player.t % 40 == 11) {
					CreatePlayerBullet2(18.0 + (int)player.power * 1.3, 0, -7, player.x - 7, player.y - 10, 6);
					CreatePlayerBullet2(18.0 + (int)player.power * 1.3, 0, -7, player.x + 7, player.y - 10, 6);
					CreatePlayerBullet2(16.0 + (int)player.power * 1.2, -0.5, -7, player.x - 14, player.y - 10, 6);
					CreatePlayerBullet2(16.0 + (int)player.power * 1.2, 0.5, -7, player.x + 14, player.y - 10, 6);
					CreatePlayerBullet2(15.0 + (int)player.power * 1.2, -1.5, -7, player.x - 14, player.y - 10, 6);
					CreatePlayerBullet2(15.0 + (int)player.power * 1.2, 1.5, -7, player.x + 14, player.y - 10, 6);
					CreatePlayerBullet2(14.0 + (int)player.power * 1.1, -2.0, -7, player.x - 14, player.y - 10, 6);
					CreatePlayerBullet2(14.0 + (int)player.power * 1.1, 2.0, -7, player.x + 14, player.y - 10, 6);
				}
			}
			if (player.fireMode) {
				if (player.t % 40 == 21) {
					CreatePlayerBullet2(18.0 + (int)player.power * 1.3, 0, -7, player.x - 7, player.y - 10, 7);
					CreatePlayerBullet2(18.0 + (int)player.power * 1.3, 0, -7, player.x + 7, player.y - 10, 7);
					CreatePlayerBullet2(16.0 + (int)player.power * 1.2, -0.5, -7, player.x - 14, player.y - 10, 7);
					CreatePlayerBullet2(16.0 + (int)player.power * 1.2, 0.5, -7, player.x + 14, player.y - 10, 7);
					CreatePlayerBullet2(15.0 + (int)player.power * 1.2, -1.5, -7, player.x - 14, player.y - 10, 7);
					CreatePlayerBullet2(15.0 + (int)player.power * 1.2, 1.5, -7, player.x + 14, player.y - 10, 7);
					CreatePlayerBullet2(14.0 + (int)player.power * 1.1, -2.0, -7, player.x - 14, player.y - 10, 7);
					CreatePlayerBullet2(14.0 + (int)player.power * 1.1, 2.0, -7, player.x + 14, player.y - 10, 7);
				}
			}
			if (player.thunderMode) {
				if (player.t % 40 == 31) {
					CreatePlayerBullet2(18.0 + (int)player.power * 1.3, 0, -7, player.x - 7, player.y - 10, 8);
					CreatePlayerBullet2(18.0 + (int)player.power * 1.3, 0, -7, player.x + 7, player.y - 10, 8);
					CreatePlayerBullet2(16.0 + (int)player.power * 1.2, -0.5, -7, player.x - 14, player.y - 10, 8);
					CreatePlayerBullet2(16.0 + (int)player.power * 1.2, 0.5, -7, player.x + 14, player.y - 10, 8);
					CreatePlayerBullet2(15.0 + (int)player.power * 1.2, -1.5, -7, player.x - 14, player.y - 10, 8);
					CreatePlayerBullet2(15.0 + (int)player.power * 1.2, 1.5, -7, player.x + 14, player.y - 10, 8);
					CreatePlayerBullet2(14.0 + (int)player.power * 1.1, -2.0, -7, player.x - 14, player.y - 10, 8);
					CreatePlayerBullet2(14.0 + (int)player.power * 1.1, 2.0, -7, player.x + 14, player.y - 10, 8);
				}
			}
			break;

		case player.D_Magician_B:
			//�~�T�C��
			//132 + 12n (3hit)
			//66 + 8n (2hit)
			if (player.t % 30 == 1) {
				//CreatePlayerBullet2(20.0 + (int)player.power * 8, 0, -3, player.x - 21, player.y - 10, 1);
				//CreatePlayerBullet2(20.0 + (int)player.power * 8, 0, -3, player.x + 21, player.y - 10, 1);
				CreatePlayerBullet2(22.0 + (int)player.power * 2, -0.3, -3, player.x - 49, player.y - 10, 1);
				CreatePlayerBullet2(22.0 + (int)player.power * 2, 0.3, -3, player.x + 49, player.y - 10, 1);
				CreatePlayerBullet2(22.0 + (int)player.power * 2, -0.5, -3, player.x - 51, player.y - 10, 1);
				CreatePlayerBullet2(22.0 + (int)player.power * 2, 0.5, -3, player.x + 51, player.y - 10, 1);
				CreatePlayerBullet2(22.0 + (int)player.power * 2, -0.7, -3, player.x - 53, player.y - 10, 1);
				CreatePlayerBullet2(22.0 + (int)player.power * 2, 0.7, -3, player.x + 53, player.y - 10, 1);
			}
			//�����V���b�g
			//96 (4hit) (+30�̃��C���V���b�g)
			//288 (4hit * 3) (+30�̃��C���V���b�g)
			if (player.snowMode) {
				static double atk = 12.0;
				if (player.t % 30 == 6) {
					CreatePlayerBullet2(atk, 0, -3, player.x - 10, player.y - 10, 9);
					CreatePlayerBullet2(atk, 0, -3, player.x + 10, player.y - 10, 9);
					CreatePlayerBullet2(atk, -0.2, -3, player.x - 13, player.y - 10, 9);
					CreatePlayerBullet2(atk, 0.2, -3, player.x + 13, player.y - 10, 9);
				}
			}
			if (player.fireMode) {
				static double atk = 12.0;
				if (player.t % 30 == 16) {
					CreatePlayerBullet2(atk, 0, -3, player.x - 10, player.y - 10, 10);
					CreatePlayerBullet2(atk, 0, -3, player.x + 10, player.y - 10, 10);
					CreatePlayerBullet2(atk, -0.2, -3, player.x - 13, player.y - 10, 10);
					CreatePlayerBullet2(atk, 0.2, -3, player.x + 13, player.y - 10, 10);
				}
			}
			if (player.thunderMode) {
				static double atk = 12.0;
				if (player.t % 30 == 26) {
					CreatePlayerBullet2(atk, 0, -3, player.x - 10, player.y - 10, 11);
					CreatePlayerBullet2(atk, 0, -3, player.x + 10, player.y - 10, 11);
					CreatePlayerBullet2(atk, -0.2, -3, player.x - 13, player.y - 10, 11);
					CreatePlayerBullet2(atk, 0.2, -3, player.x + 13, player.y - 10, 11);
				}
			}
			break;

		case player.L_Magician_A:
			//���[�U�[
			//72 + 12n (4hit) (+30�̃��C���V���b�g)
			CreatePlayerBullet2(0.3 + 0.05 * (int)player.power, 0, -800, player.x - 9, player.y - 10, 5);
			CreatePlayerBullet2(0.3 + 0.05 * (int)player.power, 0, -800, player.x + 9, player.y - 10, 5);
			CreatePlayerBullet2(0.3 + 0.05 * (int)player.power, 0, -800, player.x - 16, player.y - 10, 5);
			CreatePlayerBullet2(0.3 + 0.05 * (int)player.power, 0, -800, player.x + 16, player.y - 10, 5);
			if (player.snowMode) {
				CreatePlayerBullet2(0.16, 0, -800, player.x - 30, player.y - 10, 12);
				CreatePlayerBullet2(0.16, 0, -800, player.x + 30, player.y - 10, 12);
				CreatePlayerBullet2(0.16, 0, -800, player.x - 37, player.y - 10, 12);
				CreatePlayerBullet2(0.16, 0, -800, player.x + 37, player.y - 10, 12);
			}
			if (player.fireMode) {
				CreatePlayerBullet2(0.18, 0, -800, player.x - 4, player.y - 10, 13);
				CreatePlayerBullet2(0.18, 0, -800, player.x + 4, player.y - 10, 13);
				//CreatePlayerBullet2(0.4 + 0.05 * (int)player.power, 0, -800, player.x - 7, player.y - 10, 13);
				//CreatePlayerBullet2(0.4 + 0.05 * (int)player.power, 0, -800, player.x + 7, player.y - 10, 13);
			}
			if (player.thunderMode) {
				CreatePlayerBullet2(0.14, 0, -800, player.x - 21, player.y - 10, 14);
				CreatePlayerBullet2(0.14, 0, -800, player.x + 21, player.y - 10, 14);
				CreatePlayerBullet2(0.14, 0, -800, player.x - 26, player.y - 10, 14);
				CreatePlayerBullet2(0.14, 0, -800, player.x + 26, player.y - 10, 14);
			}
			break;

		case player.L_Magician_B:
			//�S����
			//�ʏ� 1�{ 50 + 10n (+30�̃��C���V���b�g)
			//�� 1�{ 150 (+30�̃��C���V���b�g)
			//�X�A�� 1�{ 200
			if (player.t % 6 == 1) {
				//�����V���b�g
				//�E��A�E�A�E���ɕX
				if (player.snowMode) {
					static double atk = 20.0;
					static double a = 60 * root2 / 2;
					CreatePlayerBullet2(atk, 7 * root2 / 2, -7 * root2 / 2, player.x + a, player.y - a, 15);
					CreatePlayerBullet2(atk, 7, 0, player.x + 60, player.y, 15);
					CreatePlayerBullet2(atk, 7 * root2 / 2, 7 * root2 / 2, player.x + a, player.y + a, 15);
				}
				else {
					static double a = 60 * root2 / 2;
					CreatePlayerBullet2(6.0 + player.power * 1.0, 7 * root2 / 2, -7 * root2 / 2, player.x + a, player.y - a, 3);
					CreatePlayerBullet2(6.0 + player.power * 1.0, 7, 0, player.x + 60, player.y, 3);
					CreatePlayerBullet2(6.0 + player.power * 1.0, 7 * root2 / 2, 7 * root2 / 2, player.x + a, player.y + a, 3);
				}
				//�㉺�ɉ�
				if (player.fireMode) {
					static double atk = 15.0;
					CreatePlayerBullet2(atk, 0, -7, player.x, player.y - 60, 16);
					CreatePlayerBullet2(atk, 0, 7, player.x, player.y + 60, 16);
				}
				else {
					CreatePlayerBullet2(6.0 + player.power * 1.0, 0, -7, player.x, player.y - 60, 3);
					CreatePlayerBullet2(6.0 + player.power * 1.0, 0, 7, player.x, player.y + 60, 3);
				}
				//����A���A�����ɗ�
				if (player.thunderMode) {
					static double atk = 20.0;
					static double a = 60 * root2 / 2;
					CreatePlayerBullet2(atk, -7 * root2 / 2, -7 * root2 / 2, player.x - a, player.y - a, 17);
					CreatePlayerBullet2(atk, -7, 0, player.x - 60, player.y, 17);
					CreatePlayerBullet2(atk, -7 * root2 / 2, 7 * root2 / 2, player.x - a, player.y + a, 17);
				}
				else {
					static double a = 60 * root2 / 2;
					CreatePlayerBullet2(6.0 + player.power * 1.0, -7 * root2 / 2, -7 * root2 / 2, player.x - a, player.y - a, 3);
					CreatePlayerBullet2(6.0 + player.power * 1.0, -7, 0, player.x - 60, player.y, 3);
					CreatePlayerBullet2(6.0 + player.power * 1.0, -7 * root2 / 2, 7 * root2 / 2, player.x - a, player.y + a, 3);
				}
			}

			break;
		}
		//�����V���b�g
		/*if (player.snowGauge > 0) {
			static int atk = 5;
			if (player.t % 7 == 1) {
				CreatePlayerBullet2(atk, -0.2, -4.0, player.x - 20, player.y - 10, 6);
				CreatePlayerBullet2(atk, 0.2, -4.0, player.x + 20, player.y - 10, 6);
			}
		}
		if (player.fireGauge > 0) {
			static int atk = 10;
			if (player.t % 29 == 1) {
				CreatePlayerBullet2(atk, -0, -11.0, player.x - 15, player.y - 10, 7);
				CreatePlayerBullet2(atk, 0, -11.0, player.x + 15, player.y - 10, 7);
			}
		}
		if (player.thunderGauge > 0) {
			static int atk = 5;
			if (player.t % 13 == 1) {
				CreatePlayerBullet2(atk, -0.25, -7, player.x - 27, player.y - 10, 8);
				CreatePlayerBullet2(atk, 0.25, -7, player.x + 27, player.y - 10, 8);
			}
		}*/
	}
}

//�e�̍U���́AXY���x�AXY���W�A��ނ��󂯎���Ēe������֐�
void CreatePlayerBullet2(double atk, double vx, double vy, double x, double y, int kind) {

	int i = getPlayerBulletNumber();
	playerbullet[i].hp = 1;
	playerbullet[i].atk = atk;
	playerbullet[i].vx = vx;
	playerbullet[i].vy = vy;
	playerbullet[i].x = x;
	playerbullet[i].y = y;
	playerbullet[i].pbkind = kind;
	switch (playerbullet[i].pbkind) {
	case 0: playerbullet[i].img = img.shot[0]; playerbullet[i].size = 3; break;
	case 1: playerbullet[i].img = img.black_missile; playerbullet[i].size = 16; break;
	case 2: playerbullet[i].img = img.shot[2]; playerbullet[i].size = 3; break;
	case 3: playerbullet[i].img = img.frush_bullet; playerbullet[i].size = 24; break;
	case 4: playerbullet[i].img = img.crescent_cutter; playerbullet[i].size = 16; break;
	case 5: playerbullet[i].img = img.laser_sun; playerbullet[i].size = 4; break;
	////�����e
	//case 6: playerbullet[i].img = img.p_snow_bullet; playerbullet[i].size = 7; break;
	//case 7: playerbullet[i].img = img.p_fire_bullet; playerbullet[i].size = 7; break;
	//case 8: playerbullet[i].img = img.p_thunder_bullet; playerbullet[i].size = 7; break;

	//�J�b�^�[�̑����e
	case 6: playerbullet[i].img = img.ice_cutter; playerbullet[i].size = 7; break;
	case 7: playerbullet[i].img = img.fire_cutter; playerbullet[i].size = 7; break;
	case 8: playerbullet[i].img = img.thunder_cutter; playerbullet[i].size = 7; break;
		//�u���b�N�z�[���̑����e 
	case 9: playerbullet[i].img = img.ice_missile; playerbullet[i].size = 16; break;
	case 10: playerbullet[i].img = img.fire_missile; playerbullet[i].size = 16; break;
	case 11: playerbullet[i].img = img.thunder_missile; playerbullet[i].size = 16; break;
		//���[�U�[�̑����e 
	case 12: playerbullet[i].img = img.laser_ice; playerbullet[i].size = 4; break;
	case 13: playerbullet[i].img = img.laser_fire; playerbullet[i].size = 4; break;
	case 14: playerbullet[i].img = img.laser_thunder; playerbullet[i].size = 4; break;

		//���z�̑����e 
	case 15: playerbullet[i].img = img.ice_frush_bullet; playerbullet[i].size = 24; break;
	case 16: playerbullet[i].img = img.fire_frush_bullet; playerbullet[i].size = 24; break;
	case 17: playerbullet[i].img = img.thunder_frush_bullet; playerbullet[i].size = 24; break;

	case -1: playerbullet[i].img = img.shot_red; playerbullet[i].size = 3; break;
	}
	playerbullet[i].t = 0;
}

//�����\�Ȏ��@�̒e�̔z��̔ԍ����擾����֐�
int getPlayerBulletNumber() {

	//���݂������ŉ��o���I����Ă���e����e�𐶐�����
	for (int i = 0; i < BULLET; i++) {
		if (playerbullet[i].hp == 0 && playerbullet[i].vanish == 0) {
			return i;
		}
	}
	return 0;
}
