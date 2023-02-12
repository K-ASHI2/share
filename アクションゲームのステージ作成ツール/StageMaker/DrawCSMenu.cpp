#include"DxLib.h"
#include"extern.h"
#include"function.h"	//���ʂ̊֐�

//���j���[�̕`��
void DrawCSMenu() {

	DrawFormatStringToHandle(20, 20, black, Font[0], "map[sx][sy]:%d", map[sx][sy]);
	DrawFormatStringToHandle(20, 40, black, Font[0], "si:%d", map_si[map[sx][sy] % 1000]);
	DrawFormatStringToHandle(20, 60, black, Font[0], "scroll_v:%d", scroll_v);

	//���j���[�̏���
	//�I�����ꂽ���j���[�ɂ���ĕ\�����ς��
	if (menu_b < 4) {
		int si;
		int end;
		switch (menu_b) {
		case 1:
			si = 0;
			end = si_block;
			break;
		case 2:
			si = si_block;
			end = si_etc;
			break;
		case 3:
			si = si_etc;
			end = si_etc_end;
			break;
		}

		for (int j = 0; j < 2; j++) {
			for (int i = 0; i < 10; i++) {

				//���̔ԍ�
				int sn = si + i + 10 * j + (cs_page[menu_b] - 1) * 20;

				//�\������̂͑I�����ꂽ���j���[�̕������ɂ���
				//�I�����ꂽ���j���[�̕��̃{�^����S�č��I������for����S��������
				if (sn >= end) {
					j = 2;
					break;
				}

				int x = 20 + i * 40;
				int y = 530 + j * 34;

				//�{�^���̕`��Ɣ��菈��
				if (DrawButton4(x, y) == 1) {
					cs_map = select_thing[sn].number;
				}

				//�u�����̕`��
				DrawSelectThing(x, y, select_thing[sn].GrHandle, select_thing[sn].turn);
			}
		}

		{
			//���؂�ւ��{�^��
			static int x = 440, y = 570;
			if (JudgeMouse(x, y, 0, 1) == 1) {//�{�^����������Ă����
				DrawButton(x, y, 0, 1, redbutton);
			}
			else {
				if (JudgeMouse4(x, y, 0, 1) && !(Mouse & MOUSE_INPUT_LEFT)) { //1�t���[���O�Ƀ{�^����������Ă��č����N���b�N���Ă��Ȃ��Ȃ�
					cs_map = -1;
					map[sx][sy] = 0;
					sx2 = -1;	//���j���[���̑I������Ă���x�Ay���W��ۑ�����
					sy2 = -1;
					if (cs_page[menu_b] > 1) {
						cs_page[menu_b]--;
					}
					//�ŏ��ƍŌ�̃y�[�W�Ń��[�v������
					else {
						cs_page[menu_b] = cs_max_page[menu_b];
					}
				}
				DrawButton(x, y, 0, 1, bluebutton);	//����1���̕������傤�ǂ���
			}
			DrawStringToHandle(x, y, "<", black, Font[0]);
		}
		{
			//�E�؂�ւ��{�^��
			static int x = 480, y = 570;
			if (JudgeMouse(x, y, 0, 1) == 1) {//�{�^����������Ă����
				DrawButton(x, y, 0, 1, redbutton);
			}
			else {
				//1�t���[���O�Ƀ{�^����������Ă��č����N���b�N���Ă��Ȃ��Ȃ�
				if (JudgeMouse4(x, y, 0, 1) && !(Mouse & MOUSE_INPUT_LEFT)) {
					cs_map = -1;
					map[sx][sy] = 0;
					sx2 = -1;	//���j���[���̑I������Ă���x�Ay���W��ۑ�����
					sy2 = -1;
					//�y�[�W��؂�ւ�
					if (cs_page[menu_b] < cs_max_page[menu_b]) {
						cs_page[menu_b]++;
					}
					//�ŏ��ƍŌ�̃y�[�W�Ń��[�v������
					else {
						cs_page[menu_b] = 1;
					}
				}
				DrawButton(x, y, 0, 1, bluebutton);	//����1���̕������傤�ǂ���
			}
			DrawStringToHandle(x, y, ">", black, Font[0]);
		}
		DrawFormatStringToHandle(433, 540, black, Font[0], "PAGE:%d", cs_page[menu_b]);

		if (cs_map > 0 && sx >= 0 && sy >= 0) {
			map[sx][sy] = cs_map;
		}

		//���������I������Ă��鎞�Ȃ������`�悷��
		if (cs_map > 0) {
			DrawStringToHandle(600, 503, select_description[cs_map % 1000], GetColor(0, 0, 0), Font[0]);
		}

		//�����{�^��
		static int x = 530, y = 570;
		if (JudgeMouse(x, y, 2, 0) == 1) {//�{�^����������Ă����
			sx2 = mx;//���j���[���̑I������Ă���x�Ay���W��ۑ�����
			sy2 = my;
		}
		if (JudgeMouse3(x, y, 2, 0)) {
			DrawButton(x, y, 2, 0, redbutton);
			if (sx >= 0 && sy >= 0) {
				map[sx][sy] = 0;	//��������
			}
		}
		else {
			DrawButton(x, y, 2, 0, bluebutton);
		}
		DrawStringToHandle(x, y, "����", black, Font[0]);

		//�������{�^��
		static int x2 = 530, y2 = 538;
		if (JudgeMouse(x2, y2, 2, 0) == 1) {//�{�^�����N���b�N���Ă��鎞
			sx2 = mx;//���j���[���̑I������Ă���x�Ay���W��ۑ�����
			sy2 = my;
			cs_map = 0;//cs_map���ݒ肳��Ă���ƃ}�b�v�ɒu���Ă��܂�
		}
		else {
			grid_sizex5 = -1;
			grid_sizey5 = -1;
			grid_sizex6 = 0;
			grid_sizey6 = 0;
		}
		if (JudgeMouse3(x2, y2, 2, 0)) {//�{�^����������Ă��鎞
			DrawButton(x2, y2, 2, 0, redbutton);

			//�������Ă��镨��\������
			//��ʓ����N���b�N���Ă��鎞�̂�
			if (sx >= stage_x / block_size && sx < GetDrawWidth() + (stage_x + block_size - 1) / block_size
				&& sy >= stage_y / block_size && sy < GetDrawHeight() + (stage_y + block_size - 1) / block_size) {
				//�}�b�v�ɕ����������͍s��Ȃ�
				if (map[sx][sy] != 0) {
					if (cs_map2 == 0) {
						cs_map2 = map[sx][sy];
						map[sx][sy] = 0;
						c_move = true;//�o�b�N�A�b�v���Ȃ�
					}
				}
				grid_sizex5 = grid_sizex;
				grid_sizey5 = grid_sizey;
				grid_sizex6 = grid_sizex4;
				grid_sizey6 = grid_sizey4;
				DrawMapThings2(mx - block_size / 2, my - block_size / 2, cs_map2);
				DrawMapThings(mx - block_size / 2, my - block_size / 2, cs_map2);//�G�̑傫���ɂ���ĕς���
				DrawMapThings3(mx - block_size / 2, my - block_size / 2, cs_map2);
			}
			//�������Ă���r���Ń}�E�X��������Ȃ��Ȃ�����
			else if (cs_map2 != 0 && MouseL == 0) {
				//��ʓ��ɂ���Ȃ�u��
				if (mx2 >= 0 && mx2 < GetDrawWidth()
					&& my2 >= 0 && my2 < GetDrawHeight())
				{
					map[(mx2 + stage_x) / block_size][(my2 + stage_y) / block_size] = cs_map2;
				}
				cs_map2 = 0;
				c_move = false;		//�o�b�N�A�b�v����悤�ɖ߂�
			}
		}
		else
			DrawButton(x2, y2, 2, 0, bluebutton);
		DrawStringToHandle(x2, y2, "�ړ�", black, Font[0]);
	}

	//�X�e�[�^�X
	else if (menu_b == 4) {
		DrawStringToHandle(10, 538, "����", GetColor(0, 0, 0), Font[0]);
		int m = map[sx][sy] % 1000;		//�㉺�ɓ����G�͏㉺�ƕ\������
		if (m == 10 || m == 12 || m == 40 || m == 42 || m == 44 || m == 47 || m == 48) {
			DrawButton3(100, 538, "��", 1);
			DrawButton3(200, 538, "��", 2);
		}
		else {
			DrawButton3(100, 538, "��", 1);
			DrawButton3(200, 538, "�E", 2);
		}
		if (m == 69)
			DrawStringToHandle(10, 572, "����", GetColor(0, 0, 0), Font[0]);
		else
			DrawStringToHandle(10, 572, "���x", GetColor(0, 0, 0), Font[0]);

		if (map[sx][sy] % 1000 == 24) {
			DrawButton2(100, 572, "1");
			DrawButton2(140, 572, "2");
			DrawButton2(180, 572, "4");
			DrawButton2(220, 572, "8");
		}
		else {
			DrawButton2(100, 572, "1");
			DrawButton2(140, 572, "2");
			DrawButton2(180, 572, "3");
			DrawButton2(220, 572, "4");
			DrawButton2(260, 572, "5");
			DrawButton2(300, 572, "6");
			DrawButton2(340, 572, "7");
		}

		//�X�N���[�����x�̃{�^��
		{
			//�����{�^��
			static int x = 440, y = 570;
			if (JudgeMouse(x, y, 0, 1) == 1) {//�{�^����������Ă����
				DrawButton(x, y, 0, 1, redbutton);
			}
			else {
				if (JudgeMouse4(x, y, 0, 1) && !(Mouse & MOUSE_INPUT_LEFT)) { //1�t���[���O�Ƀ{�^����������Ă��č����N���b�N���Ă��Ȃ��Ȃ�
					cs_map = -1;
					map[sx][sy] = 0;
					//���j���[���̑I������Ă���x�Ay���W��ۑ�����
					sx2 = -1;
					sy2 = -1;
					//����
					if (scroll_v > 0) {
						scroll_v--;
					}
				}
				DrawButton(x, y, 0, 1, bluebutton);	//����1���̕������傤�ǂ���
			}
			DrawStringToHandle(x, y, "<", black, Font[0]);
		}
		{
			//�����{�^��
			static int x = 480, y = 570;
			if (JudgeMouse(x, y, 0, 1) == 1) {//�{�^����������Ă����
				DrawButton(x, y, 0, 1, redbutton);
			}
			else {
				//1�t���[���O�Ƀ{�^����������Ă��č����N���b�N���Ă��Ȃ��Ȃ�
				if (JudgeMouse4(x, y, 0, 1) && !(Mouse & MOUSE_INPUT_LEFT)) {
					cs_map = -1;
					map[sx][sy] = 0;
					//���j���[���̑I������Ă���x�Ay���W��ۑ�����
					sx2 = -1;
					sy2 = -1;
					//����
					if (scroll_v < 9) {
						scroll_v++;
					}
				}
				DrawButton(x, y, 0, 1, bluebutton);	//����1���̕������傤�ǂ���
			}
			DrawStringToHandle(x, y, ">", black, Font[0]);
		}
		DrawFormatStringToHandle(433, 540, black, Font[0], "���x:%d", scroll_v);

		//�w�i�̃{�^��
		{
			static int x = 540, y = 570;
			if (JudgeMouse(x, y, 0, 1) == 1) {
				DrawButton(x, y, 0, 1, redbutton);
			}
			else {
				if (JudgeMouse4(x, y, 0, 1) && !(Mouse & MOUSE_INPUT_LEFT)) {
					cs_map = -1;
					map[sx][sy] = 0;
					sx2 = -1;
					sy2 = -1;
					if (background_n > 0) {
						background_n--;
					}
				}
				DrawButton(x, y, 0, 1, bluebutton);
			}
			DrawStringToHandle(x, y, "<", black, Font[0]);
		}
		{
			static int x = 580, y = 570;
			if (JudgeMouse(x, y, 0, 1) == 1) {
				DrawButton(x, y, 0, 1, redbutton);
			}
			else {
				if (JudgeMouse4(x, y, 0, 1) && !(Mouse & MOUSE_INPUT_LEFT)) {
					cs_map = -1;
					map[sx][sy] = 0;
					sx2 = -1;
					sy2 = -1;
					if (background_n < 20) {
						background_n++;
					}
				}
				DrawButton(x, y, 0, 1, bluebutton);
			}
			DrawStringToHandle(x, y, ">", black, Font[0]);
		}
		DrawFormatStringToHandle(533, 540, black, Font[0], "�w�i:%d", background_n);

		//���y�̃{�^��
		{
			static int x = 640, y = 570;
			if (JudgeMouse(x, y, 0, 1) == 1) {
				DrawButton(x, y, 0, 1, redbutton);
			}
			else {
				if (JudgeMouse4(x, y, 0, 1) && !(Mouse & MOUSE_INPUT_LEFT)) {
					cs_map = -1;
					map[sx][sy] = 0;
					sx2 = -1;
					sy2 = -1;
					if (music_n > 0) {
						music_n--;
						PM_Number();
					}
				}
				DrawButton(x, y, 0, 1, bluebutton);
			}
			DrawStringToHandle(x, y, "<", black, Font[0]);
		}
		{
			static int x = 680, y = 570;
			if (JudgeMouse(x, y, 0, 1) == 1) {
				DrawButton(x, y, 0, 1, redbutton);
			}
			else {
				if (JudgeMouse4(x, y, 0, 1) && !(Mouse & MOUSE_INPUT_LEFT)) {
					cs_map = -1;
					map[sx][sy] = 0;
					sx2 = -1;
					sy2 = -1;
					if (music_n < 20) {
						music_n++;
						PM_Number();
					}
				}
				DrawButton(x, y, 0, 1, bluebutton);
			}
			DrawStringToHandle(x, y, ">", black, Font[0]);
		}

		DrawFormatStringToHandle(633, 540, black, Font[0], "���y:%d", music_n);
	}
}

//���W�A�摜(+���߃t���O)���󂯎���Ēu�����̉摜��`�悷��
void DrawSelectThing(int x1, int y1, int GrHandle, bool turn, int TransFlag) {

	static int size = 28;

	if (turn) {
		DrawTurnSelectThing(x1, y1, GrHandle, TransFlag);
	}
	else {
		int size2 = 2 + (32 - size) / 2;
		DrawExtendGraph(x1 + size2, y1 + size2, x1 + size, y1 + size, GrHandle, TRUE);
	}
}

void DrawSelectThing(int x1, int y1, int GrHandle) {
	DrawSelectThing(x1, y1, GrHandle, TRUE);
}

//���W�A�摜(+���߃t���O)���󂯎���Ēu�����̉摜�𔽓]���ĕ`�悷��
void DrawTurnSelectThing(int x1, int y1, int GrHandle, int TransFlag) {
	static int size = 28;
	int size2 = 2 + (32 - size) / 2;
	DrawExtendGraph(x1 + size, y1 + size2, x1 + size2, y1 + size, GrHandle, TRUE);
}