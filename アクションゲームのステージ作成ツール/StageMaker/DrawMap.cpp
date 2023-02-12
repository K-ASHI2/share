#include"DxLib.h"
#include"extern.h"
#include"function.h"	//�X�e�[�W�쐬�݂̂Ɏg�p����֐�

void DrawMap() {

	//�}�b�v�̕`��

	/**
	 * �c����ʓ��̂ݔ���ɂ���ׂ�
	 */
	int xmin, xmax;//�傫���G���`��ł���悤�ɕ`��̒[���ς��悤�ɂ���
	if ((stage_x / block_size) - 6 > 0)
		xmin = (stage_x / block_size) - 6;
	else
		xmin = 0;
	if ((stage_x / block_size) + WIDTH_SIZE + 4 < 0)
		xmax = (stage_x / block_size) - 4;
	else
		xmax = width_size;

	for (int j = 0; j < height_size; j++)
		for (int i = xmin; i < xmax; i++)
			if (i < width_size && i >= 0)
				if (i != sx || j != sy)
					DrawGraph(i * block_size - stage_x, j * block_size - stage_y, img.grid, TRUE);	//�O���b�h�̕\��
																				//�傫���G��u���b�N�ɃO���b�h���d�Ȃ�Ȃ��悤�ɂ��邽��
	//��x�ɉ�ʓ��ɕ\������镝�͈�񑽂�����
	for (int i = stage_x / block_size; i < (stage_x / block_size) + WIDTH_SIZE + 1; i++) {
		for (int j = 0; j < height_size; j++) {
			//���̕�����苷���͈͂Ń}�b�v���f
			if (i < width_size && i >= 0) {
				//�㉺�ɉ�ʊO�܂œ����G
				if (map[i][j] % 1000 == 7 || map[i][j] % 1000 == 506) {
					//�����ꏊ��\������
					//1���2�̈ȏ㑶�݂��Ă�1�x�������肷��΂悢
					DrawGraph(i * block_size - stage_x, 0, img.b_line, TRUE);
					break;
				}
			}
		}
	}

	//2��1��3��4�̏��ɉ�����`�悵�Ă���
	//���ɕ\�����������̂�\������
	for (int j = 0; j < height_size; j++) {
		for (int i = xmin; i < xmax; i++) {
			int cmap_x = i * block_size - stage_x;
			int cmap_y = j * block_size - stage_y;
			DrawMapThings2(cmap_x, cmap_y, map[i][j]);
		}
	}
	for (int j = 0; j < height_size; j++) {
		for (int i = xmin; i < xmax; i++) {
			int cmap_x = i * block_size - stage_x;
			int cmap_y = j * block_size - stage_y;
			DrawMapThings(cmap_x, cmap_y, map[i][j]);
		}
	}

	//��O�ɕ\�����������̂�\������
	for (int j = 0; j < height_size; j++) {
		for (int i = xmin; i < xmax; i++) {
			int cmap_x = i * block_size - stage_x;
			int cmap_y = j * block_size - stage_y;
			DrawMapThings3(cmap_x, cmap_y, map[i][j]);
		}
	}
	for (int j = 0; j < height_size; j++) {
		for (int i = xmin; i < xmax; i++) {
			int cmap_x = i * block_size - stage_x;
			int cmap_y = j * block_size - stage_y;
			DrawMapThings4(cmap_x, cmap_y, map[i][j]);
		}
	}

	//�傫�����̑I�𒆂̕��̔���
	//���������
	//for (int j = 0; j < height_size; j++) {
	//	for (int i = xmin; i < xmax; i++) {
	//		//�}�X����v���Ă���Ȃ画�肵�Ȃ�
	//		if (i == sx && j == sy) {
	//			continue;
	//		}
	//		int si = map_si[map[i][j] % 1000];

	//		//�傫���G�͓��������ƃX�e�[�^�X�ύX�̎��Ɏ�O�ɕ���������ΑS�̂ɔ������������
	//		//�ړ��̃{�^����������Ă��鎞�A�����Ȃ��ꏊ��I�������ꍇ�A�I�𒆂̃}�X���炸�炵���͈͂�T�����A���͈̔͂ɑ傫����������Ȃ画���ς���
	//		if ((sx >= i - select_thing[si].l_shift && sx <= i + select_thing[si].r_shift) && (sy >= j - select_thing[si].u_shift && sy <= j + select_thing[si].d_shift)
	//			&& ((JudgeMouse3(430, 538, 2, 0) && c_move == false) || menu_b == 4) && map[sx][sy] == 0) {
	//			sx = i;
	//			sy = j;
	//		}
	//	}
	//}

	//�I�𒆂̕��̃O���b�h�̕\��
	if (sx >= 0 && sy >= 0) {
		int cs_map3 = map[sx][sy] % 1000;
		if (grid_sizex5 != -1) {
			grid_sizex = grid_sizex5;
			grid_sizey = grid_sizey5;
			grid_sizex4 = grid_sizex6;
			grid_sizey4 = grid_sizey6;
		}
		else {
			grid_sizex = block_size;
			grid_sizey = block_size;
			grid_sizex4 = 0;
			grid_sizey4 = 0;
			if (cs_map3 == 27 || cs_map3 == 28)
				grid_sizex = block_size * 2;
			if (cs_map3 == 99 || cs_map3 >= 13 && cs_map3 <= 16 || cs_map3 == 22 || cs_map3 == 28 || cs_map3 == 29 || cs_map3 == 66)
				grid_sizey = block_size * 2;
			if (cs_map3 == 65 || cs_map3 == 67) {
				grid_sizex = block_size * 3;
				grid_sizey = block_size * 3;
			}
			if (cs_map3 == 30) {
				grid_sizex = block_size * 4;
				grid_sizey = block_size * 4;
				grid_sizex4 = block_size * 3;
				grid_sizey4 = block_size * 3;
			}
		}
		for (int j = stage_y / block_size; j < (stage_y / block_size) + HEIGHT_SIZE + 1; j++) {
			for (int i = (stage_x / block_size); i < (stage_x / block_size) + WIDTH_SIZE + 1; i++) {
				if (i < width_size && i >= 0)
					if (i == sx && j == sy) {
						int cmap_x = i * block_size - stage_x;
						int cmap_y = j * block_size - stage_y;
						DrawBox(cmap_x - 1 - grid_sizex4, cmap_y - grid_sizey4 - 1, cmap_x + grid_sizex + 1, cmap_y + grid_sizey + 1, GetColor(0, 0, 0), FALSE); //�I�����ꂽ�O���b�h�̕\��
						for (i = 0; i < 3; i++)
							DrawBox(cmap_x - grid_sizex4 - 2 - i, cmap_y - grid_sizey4 - 2 - i, cmap_x + grid_sizex + 2 + i, cmap_y + grid_sizey + 2 + i, GetColor(255, 0, 0), FALSE);
						DrawBox(cmap_x - grid_sizex4 - 5, cmap_y - grid_sizey4 - 5, cmap_x + grid_sizex + 5, cmap_y + grid_sizey + 5, GetColor(0, 0, 0), FALSE);
						break;
					}
			}
		}
	}
}

//�}�b�v�̒l���󂯎���ĕ`�悷��֐�
void DrawMapThings(int x, int y, int mapc) {
	
	//����
	int d = 0;
	if (mapc >= 10000)
		d = mapc % 100000 / 10000;

	int si = map_si[mapc % 1000];

	//�����Ȃ��ꏊ�ȊO�͐ݒ肳��Ă��Ȃ��ꏊ��null�ɂ���
	if (si == -1) {
		DrawGraph(x, y, img.null, TRUE);
	}
	else if (mapc != 0 && select_thing[si].drawflag) {
		//turn�Ŕ��]�����܂��Ă���Ȃ�D�悷��
		if (select_thing[si].turn) {
			DrawCreate(x, y, select_thing[si].GrHandle, 1);
		}
		else {
			DrawCreate(x, y, select_thing[si].GrHandle, d);
		}
	}

	//�ʂɐݒ肵������
	switch (mapc % 1000) {
		//�܂��u�����ɐݒ肵�ĂȂ���
	/*case 13:	DrawGraph(x, y, img.door[1], TRUE); break;
	case 14:	DrawGraph(x, y, img.door[1], TRUE); break;
	case 15:	DrawGraph(x, y, img.door[2], TRUE); break;*/
		//�~�^�����镨�̒��S���W
	case 6:	DrawGraph(x, y, img.graysquare, TRUE); break;
	case 16:	DrawGraph(x, y, img.graysquare, TRUE); break;
	case 103:	DrawGraph(x, y, img.graysquare, TRUE); break;
		//�t�@�C�A�o�[�̒��S
	case 705:	DrawCreate(x, y, img.kabe, d); break;

		//�ړ��������������邩��ʂɐݒ肵�Ă����u���b�N?
		//�����ڂ�ς��ĐV���ɐݒ肷��ׂ��Ȃ̂ł���Ȃ��͂�
	//case 52:	DrawGraph(x, y, img.moveblock[4], TRUE); break;	//���ɉ����܂œ�����

	//�����鏰�̃J�E���g�̐����̕`��
	case 69:
		char dc[2];
		if (mapc >= 100)
			itoa((mapc % 10000) / 1000, dc, 10);
		DrawStringToHandle(x + 8, y + 3, dc, GetColor(255, 0, 0), Font[1]);
		break;

		//�v���C���[�̏������W�̕`��
	case 999:
		if (d == 1)
			DrawTurnGraph(x - 32, y, img.hito[6], TRUE);
		else
			DrawGraph(x, y, img.hito[6], TRUE);
		break;
	}
}

//�}�b�v�̉��ɕ`�悵�������̂�`�悷��
void DrawMapThings2(int x, int y, int map) {
	int d = 0;
	if (map >= 10000)
		d = map % 100000 / 10000;
	int m = map % 1000;
	//�~�^�����镨�̓����͈͂̕`��
	if (m == 6 || m == 16 || m == 103) {
		DrawCreate(x - block_size * 2, y - block_size * 2, img.circle3, d);
		DrawCreate(x - block_size * 2, y - block_size * 2, img.circle, d);
	}
	//�t�@�C�A�o�[�̓����͈͂̕`��
	else if (m == 49) {
		DrawCreate(x - block_size * 3, y - block_size * 3, img.circle2, d);	
	}
	//�傫���G�̕`��
	/*else if (m == 30)
		DrawCreate(x - block_size * 3, y - block_size * 3, img.enemy[27], d);*/
	//���ɉ������镨
	else if (m == 4 || m == 101 || m == 504) {
		int v = 0;
		if (map >= 1000)
			v = (map % 10000) / 1000;
		int x1 = x;
		if (d == 1)		//���ɓ����ꍇ���S�̂����Ɉړ����������炷
			x1 -= v * block_size;
		DrawTurnGraph(x1, y, img.linemove1, TRUE);
		int i = 0;
		for (i = 1; i < v; i++)
			DrawGraph(x1 + i * block_size, y, img.linemove2, TRUE);
		DrawGraph(x1 + i * block_size, y, img.linemove1, TRUE);
	}
	//�c�ɉ������镨
	else if (m == 5 || m == 14 || m == 15 || m == 102 || m == 505) {
		int v = 0;
		if (map >= 1000)
			v = (map % 10000) / 1000;
		int y1 = y;
		if (d == 1)		//��ɓ����ꍇ���S�̂���Ɉړ����������炷
			y1 -= v * block_size;
		DrawGraph(x, y1, img.linemove_up, TRUE);
		int i = 0;
		for (i = 1; i < v; i++)
			DrawGraph(x, y1 + i * block_size, img.linemove3, TRUE);
		DrawGraph(x,
			y1 + i * block_size, img.linemove_down, TRUE);
	}
	//��ʊO�܂ŏ㉺�ɓ������̖��
	if (m == 7 || m == 506) {
		if (d == 1)
			DrawGraph(x, y - block_size, img.linemove_up, TRUE);
		else
			DrawGraph(x, y + block_size, img.linemove_down, TRUE);
	}
}

//�}�b�v�̎�O�ɕ`�悵�������̂�`�悷��
void DrawMapThings3(int x, int y, int map) {

	int d = 0;

	if (map >= 10000) {
		d = map % 100000 / 10000;
	}

	int m = map % 1000;
	int si = map_si[map % 1000];

	//�~�^������G�̓G�{�̂̕`��
	if (m == 6 || m == 16 || m == 103) {
		DrawCreate(x, y - block_size * 2, select_thing[si].GrHandle, d);
	}

	//�t�@�C�A�o�[�̒e�̕`��
	else if (m == 705) {
		for (int i = 0; i < 4; i++) {
			DrawGraph(x, y - i * block_size, img.bullet[4], TRUE);
		}
	}
}

//�}�b�v�̈�Ԏ�O�ɕ`�悵�������̂�`�悷��
void DrawMapThings4(int x, int y, int map) {
	int d = 0;
	if (map >= 10000)
		d = map % 100000 / 10000;
}

//���W�A�摜�A�������󂯎���ĕ`�悷�� d��1�Ȃ獶�A2�Ȃ�E
void DrawCreate(int x, int y, int GrHandle, int d) {
	if (d == 1) {
		DrawTurnGraph(x, y, GrHandle, TRUE);
	}
	else {
		DrawGraph(x, y, GrHandle, TRUE);
	}
}

//���̂܂܎g���Əc�����u���b�N�Ɠ����T�C�Y�̕��ɂ����g���Ȃ�
//���W�A�摜(+���߃t���O)���󂯎���ĕ`�悷��
void MapDrawExtendGraph(int x1, int y1, int GrHandle, int TransFlag) {
	DrawExtendGraph(x1, y1, x1 + block_size, y1 + block_size, GrHandle, TRUE);
}

void MapDrawExtendGraph(int x1, int y1, int GrHandle) {
	MapDrawExtendGraph(x1, y1, GrHandle, TRUE);
}