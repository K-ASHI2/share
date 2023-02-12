#include"DxLib.h"
#include"function.h"
#include"extern.h"

void init_map(int i, int j) {//�}�b�v�̐����̏������̌ʏ���

	switch (map[i][j] % 1000) {
	case 0: break;	//�����Ȃ�

	case 1:	//���ɓ����ė�����G
		init_e(i, j, 1, 6);
		enemy[i][j].vx = -2;
		enemy[i][j].appear = 0;
		break;

	case 2:	//���̎�O�ŕ����]������G
		init_e(i, j, 1, 16, 0);
		enemy[i][j].vx = 2;
		enemy[i][j].jfly = 1;
		break;

	case 3:	//��ђ��˂�G
		init_e(i, j, 1, 13, 0);
		enemy[i][j].vx = -2;
		break;

	case 4:	//���ɉ�������G
		init_e(i, j, 1, 0);
		init_j(i, j);
		enemy[i][j].x = i * BLOCK;
		enemy[i][j].vx = -2;
		break;

	case 5: //�c�ɉ�������G
		init_e(i, j, 1, 5);
		init_j(i, j);
		enemy[i][j].vy = 2;
		break;

	case 6:	//�~�^������G
		init_e(i, j, 1, 15, 1);
		init_j(i, j);
		enemy[i][j].rad = 270;
		//enemy[i][j].rad = GetRand(360);
		break;

	case 7:	//�㉺�ɓ��������ĉ�ʊO�ɏo���甽�Α�����o�Ă���G
		init_e(i, j, 1, 37);
		init_j(i, j);
		enemy[i][j].vy = 2;
		break;

	case 8:	//�㉺�ɗh���G
		init_e(i, j, 1, 41);
		init_j(i, j);
		{
			int a = GetRand(360);
			for (int k = 0; k < height_size; k++) {
				enemy[i][k].rad = a;
			}
		}
		enemy[i][j].size_x = 16;
		enemy[i][j].size_y = 16;
		enemy[i][j].vx = -2;
		break;

	case 9:	//�ǂŔ��˂���G
		init_e(i, j, 1, 14, 0);
		enemy[i][j].vx = 2;
		enemy[i][j].vy = 2;
		break;

	case 10: //��l�����W�����v����Ɣ�ԓG
		init_e(i, j, 1, 56);
		enemy[i][j].vx = 2;
		enemy[i][j].appear = 0;
		break;

	case 11:	//��l����ǂ�������G
		init_e(i, j, 1, 43, 0);
		init_j(i, j);
		enemy[i][j].size_x = 16;
		enemy[i][j].size_y = 16;
		enemy[i][j].m_rad = 4;
		break;

	//case 12:	//�����_���ɓ�����l����ǂ�������G
	//	init_e(i, j, 1, 44, 0);
	//	init_j(i, j);
	//	enemy[i][j].size_x = 16;
	//	enemy[i][j].size_y = 16;
	//	enemy[i][j].m_rad = 4;
	//	break;
		
	case 13:  //���ʂɒe�����G
		init_e(i, j, 1, 31);
		enemy[i][j].vx = -2;
		enemy[i][j].appear = 0;
		enemy[i][j].t = GetRand(20);
		break;

	case 14:	//�c�ɉ������Ď��@�_���̒e�����G
		init_e(i, j, 1, 30);
		init_j(i, j);
		enemy[i][j].vy = 2;
		enemy[i][j].t = GetRand(20) + 40;
		break;

	case 15:	//�c�ɉ������Đ��ʂɒe�����G
		init_e(i, j, 1, 32);
		init_j(i, j);
		enemy[i][j].vy = 2;
		enemy[i][j].t = GetRand(20) + 40;
		break;

	case 16:	//�~�^�����Đ��ʂɒe�����G
		init_e(i, j, 1, 33, 1);
		init_j(i, j);
		enemy[i][j].t = GetRand(20);
		enemy[i][j].rad = 270;
		//enemy[i][j].rad = GetRand(360);
		break;

	case 17:	//��l����X���W�����킹�Ď��@�O���̕X�e�����G
		init_e(i, j, 1, 57, 0);
		enemy[i][j].t = GetRand(20);
		enemy[i][j].rad = 40;
		break;

	case 18:	//��l����X���W�����킹�ė�����G
		init_e(i, j, 1, 58, 0);
		enemy[i][j].t = GetRand(5);
		enemy[i][j].rad = 40;
		break;

	case 100:	//�~�܂��Ă���g�Q 
		init_e(i, j, 1, 55);//���̓G�Əd�Ȃ�Ȃ����l�ɂ��Ă��邾��
		init_j(i, j);
		enemy[i][j].muteki = 1;
		break;
		
	case 101: init_e(i, j, 1, 2);
		init_j(i, j);
		enemy[i][j].muteki = 1;
		enemy[i][j].vx = 3;
		break;  //���ɓ����g�Q


	case 102: init_e(i, j, 1, 34);
		init_j(i, j);
		enemy[i][j].vy = 2;
		enemy[i][j].muteki = 1;
		break; //�c�ɓ����g�Q

	case 103: init_e(i, j, 1, 35, 1);
		init_j(i, j);
		enemy[i][j].rad = 270;
		enemy[i][j].muteki = 1;
		break;  //�~�^������g�Q

	//case 22: init_e(i, j, 1, 12);
	//	enemy[i][j].vx = -2;
	//	enemy[i][j].size_y = 64;
	//	enemy[i][j].appear = 0;
	//	break;  //�c���̓G
	//case 27: init_e(i, j, 1, 17, 0);
	//	enemy[i][j].vx = -2;
	//	enemy[i][j].size_x = 64;
	//	break;  //�����̓G
	//case 28: init_e(i, j, 1, 18, 0);
	//	enemy[i][j].vx = -2;
	//	enemy[i][j].size_x = 64;
	//	enemy[i][j].size_y = 64;
	//	//enemy[i][j].drop = 100;
	//	break;  //�傫���G
	//case 30: init_e(i, j, 1, 20);
	//	enemy[i][j].x = (i - 3) * BLOCK;
	//	enemy[i][j].y = (j - 3) * BLOCK;
	//	enemy[i][j].vx = -2;
	//	enemy[i][j].size_x = 224;
	//	enemy[i][j].size_y = 224;
	//	enemy[i][j].muteki = 1;
	//	break;  //224*224�̓G

	case 301: kabe[i][j] = 1; break;	//��
	case 302: kabe[i][j] = 1; break;	//��
	case 303: kabe[i][j] = 1; break;	//��
	case 304: kabe[i][j] = 1; break;	//��
	case 305: kabe[i][j] = 1; break;	//��
	case 306: kabe[i][j] = 1; break;	//��
	case 307: kabe[i][j] = 1; break;	//��
	case 308: kabe[i][j] = 1; break;	//�S�̃u���b�N
	case 309: kabe[i][j] = 1; break;	//�؂̃u���b�N
	case 500: kabe[i][j] = 2; break; //���蔲����
	case 501: kabe[i][j] = 1; break;  //�g�Q
	case 502: init_e(i, j, 1, 3);
		init_j(i, j);
		kabe[i][j] = 1;
		enemy[i][j].hantei = 0;
		break;  //�����

	case 503: init_e(i, j, 1, 53);
		init_j(i, j);
		kabe[i][j] = 1;
		enemy[i][j].hantei = 0;
		enemy[i][j].muteki = 1;
		enemy[i][j].countx = -1;//���܂ł̃J�E���g�͌Œ�
		if (map[i][j] >= 1000)
			enemy[i][j].county = (map[i][j] % 10000) / 1000 * 40 + 5;
		else
			enemy[i][j].county = 125;
		break;  //��莞�Ԍ�ɏ�����u���b�N

	case 504: init_e(i, j, 1, 1);
		init_j(i, j);
		enemy[i][j].vx = 4;
		enemy[i][j].hantei = 0;
		enemy[i][j].muteki = 1;
		break;  //���ɓ�����

	case 505: init_e(i, j, 1, 7);
		init_j(i, j);
		enemy[i][j].hantei = 0;
		enemy[i][j].muteki = 1;
		enemy[i][j].vy = 2;
		break;  //�c�ɓ�����

	case 506: init_e(i, j, 1, 38);
		init_j(i, j);
		enemy[i][j].hantei = 0;
		enemy[i][j].muteki = 1;
		enemy[i][j].vy = 2;
		break; //�㉺�ɓ��������ĉ�ʊO�ɏo���甽�Α�����o�Ă���u���b�N
	case 507: kabe[i][j] = 1; break;	//�X�̃u���b�N

	case 601: init_t(i, j, 1, 21); break;   //���@�_���̒e������C
	case 602: init_t(i, j, 1, 22); break;   //���ɂ܂�������Ԓe������C
	case 603: init_t(i, j, 1, 23); break;   //�E�ɂ܂�������Ԓe������C
	case 604: init_t(i, j, 1, 24); break;   //��ɂ܂�������Ԓe������C
	case 605: init_t(i, j, 1, 25); break;  //���ɂ܂�������Ԓe������C
	case 606: init_t(i, j, 1, 26); break;  //����ɂ܂�������Ԓe������C
	case 607: init_t(i, j, 1, 27); break;  //�E��ɂ܂�������Ԓe������C
	case 608: init_t(i, j, 1, 28); break;  //�����ɂ܂�������Ԓe������C
	case 609: init_t(i, j, 1, 29); break;  //�E���ɂ܂�������Ԓe������C

	case 701: 
		init_e(i, j, 1, 45);
		enemy[i][j].muteki = 1;
		init_j(i, j);
		break;  //�ԃX�C�b�`

	case 702: init_e(i, j, 1, 46);
		enemy[i][j].muteki = 1;
		init_j(i, j);
		break;  //�΃X�C�b�`
	case 703: break;	//�ԃX�C�b�`�ŏo�鏰
	case 704: break;	//�΃X�C�b�`�ŏo�鏰

	case 705: init_e(i, j, 1, 39);
		kabe[i][j] = 1;
		enemy[i][j].hantei = 0;
		enemy[i][j].muteki = 1;
		enemy[i][j].rad = 0;
		for (int k = 0; k < 4; k++) {
			enemybullet[i][j][k].life = 1;
			enemybullet[i][j][k].atk = 1;
			enemybullet[i][j][k].size_x = 32;
			enemybullet[i][j][k].size_y = 32;
			enemybullet[i][j][k].species = 4;
		}
		enemybullet[i][j][0].x = i * BLOCK;
		enemybullet[i][j][0].y = j * BLOCK;
		break;  //���v���ɉ��t�@�C�A�o�[

	case 706:  //���e�I
		enemy[i][j].species = 19;
		enemy[i][j].muteki = 1;
		enemy[i][j].t = GetRand(480);
		break;

	case 707: //��
		enemy[i][j].species = 59;
		enemy[i][j].muteki = 1;
		enemy[i][j].size_x = 7;
		enemy[i][j].size_y = 7;
		init_j(i, j);
		enemy[i][j].t = GetRand(20);
		break;
	
	case 708: //��
		enemy[i][j].species = 60;
		enemy[i][j].muteki = 1;
		enemy[i][j].size_x = 7;
		enemy[i][j].size_y = 7;
		init_j(i, j);
		enemy[i][j].t = GetRand(20);
		break;

	case 709: //�Ԑ�
		enemy[i][j].species = 61;
		enemy[i][j].muteki = 1;
		enemy[i][j].size_x = 7;
		enemy[i][j].size_y = 7;
		init_j(i, j);
		enemy[i][j].t = GetRand(20);
		break;

	case 801: //�S�[���̔�
		init_e(i, j, 1, 11);
		init_j(i, j);
		enemy[i][j].hantei = 0;
		enemy[i][j].muteki = 1;
		break;

		//�X�e�[�W�쐬�@�Ŗ��ݒ�
	case 802: init_e(i, j, 1, 8);
		init_j(i, j);
		enemy[i][j].hantei = 0;
		enemy[i][j].muteki = 1;
		break;  //��

	case 803: init_e(i, j, 1, 9);
		init_j(i, j);
		enemy[i][j].hantei = 0;
		enemy[i][j].muteki = 1;
		break;  //��

	case 804: init_e(i, j, 1, 10);
		init_j(i, j);
		enemy[i][j].hantei = 0;
		enemy[i][j].muteki = 1;
		break;  //���̃G���A�ɍs����

	case 901:  init_e(i, j, 1, 4);
		enemy[i][j].jx = 0;
		break;  //�A�C�e��

	case 902: init_e(i, j, 1, 54); break; //�S������n�[�g

	//case 50: init_e(i, j, 1, 40);
	//	kabe[i][j] = 1;
	//	enemy[i][j].hantei = 0;
	//	enemy[i][j].rad = 0;
	//	for (int k = 0; k < 4; k++) {
	//		enemybullet[i][j][k].life = 1;
	//		enemybullet[i][j][k].atk = 1;
	//		enemybullet[i][j][k].size_x = 32;
	//		enemybullet[i][j][k].size_y = 32;
	//		enemybullet[i][j][k].species = 4;
	//	}
	//	enemybullet[i][j][0].x = i * BLOCK;
	//	enemybullet[i][j][0].y = j * BLOCK;
	//	break;  //�����v���ɉ��t�@�C�A�o�[
	//case 52: init_e(i, j, 1, 42);
	//	init_j(i, j);
	//	enemy[i][j].vx = 4;
	//	enemy[i][j].hantei = 0;
	//	enemy[i][j].muteki = 1;
	//	break;  //���ɉ����܂œ�����
	//			//����Ȃ�
	//case 64: init_e(i, j, 1, 48);
	//	enemy[i][j].muteki = 1;
	//	enemy[i][j].size_x = 64;
	//	enemy[i][j].jx = 0;
	//	enemy[i][j].jy = 0;
	//	break;  //�΂̊C

	case 251:	//�{�X1
		if (mapload < 1000) {
			init_e(i, j, 3, 49, 0);
			enemy[i][j].vx = 1;
		}
		else if (mapload < 2000) {
			init_e(i, j, 4, 49, 0);
			enemy[i][j].vx = 2;
		}
		else if (mapload < 3000) {
			init_e(i, j, 5, 49, 0);
			enemy[i][j].vx = 2;
		}
		enemy[i][j].size_x = 96;
		enemy[i][j].size_y = 96;
		enemy[i][j].t = 0;
		break;

	case 252:	//�{�X2
		if (mapload < 1000) {
			init_e(i, j, 3, 51, 0);
			enemy[i][j].vx = 1.5;
		}
		else if (mapload < 2000) {
			init_e(i, j, 4, 51, 0);
			enemy[i][j].vx = 2.0;
		}
		else if (mapload < 3000) {
			init_e(i, j, 6, 51, 0);
			enemy[i][j].vx = 2.5;
		}
		enemy[i][j].size_x = 96;
		enemy[i][j].size_y = 96;
		enemy[i][j].t = GetRand(120);
		break;

				//case 66: init_e(i, j, 1, 50);
				//	enemy[i][j].hantei = 0;
				//	enemy[i][j].muteki = 1;
				//	break;  //�{�X��|�������ɏo�鎟�̃X�e�[�W�ɍs����
				
	case 999: //�v���C���[�̏������W
		player.x = i * BLOCK;
		player.y = j * BLOCK;
		//������ς���
		if (map[i][j] % 100000 / 10000 == 1) {
			player.dire = map[i][j] % 100000 / 10000;
		}
		break;
	}
}
