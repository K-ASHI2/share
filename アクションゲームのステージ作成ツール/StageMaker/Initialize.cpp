#include"DxLib.h"
#include"extern.h"
#include"function.h"	//�X�e�[�W�쐬�݂̂Ɏg�p����֐�

void init_c() {	//�X�e�[�W�쐬�̏�����

	//�w�i�̈ʒu�̏�����
	stage_x = 0;
	stage_y = 0;

	sx = -1;	//�ŏ��̓O���b�h�͑I������Ă��Ȃ�
	sy = -1;
	sx2 = 460;	//�ŏ��͓��������[�h
	sy2 = 538;
	menu_b = 1;
	for (int i = 1; i <= 3; i++) {
		cs_page[i] = 1;
	}
	cs_map = -1;
	cs_map2 = 0;	//�����Ȃ��̂�0
	mx2 = -1;
	my2 = -1;
	back_c = 0;	//�ŏ��͐擪����n�߂�
	back_head = 0;	//�o�b�N�A�b�v�f�[�^�̐擪
	back_top = 0;	//�o�b�N�A�b�v�f�[�^�̍Ō��

	//�ő�T�C�Y�ɕς��Ȃ��ƃT�C�Y�ύX�ɑΉ��ł��Ă��Ȃ�?
	for (int j = 0; j< height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			for (int h = 1; h < BACK_MAX; h++) {
				backup[h][i][j] = -1;		//�S�Ă̍��W�͍ŏ��͑��݂��Ȃ�
			}
			backup[0][i][j] = map[i][j];	//��ԍŏ��͌��X�̃}�b�v
		}
	}
	for (int i = 1; i < BACK_MAX; i++) {
		backup_w[i] = 0;
		backup_h[i] = 0;
	}
	backup_w[0] = width_size;
	backup_h[0] = height_size;

	//��ʂ̃T�C�Y���g�債���Ƃ����������W������������K�v������
	//���₵�����ɏ���������悤�ɕς���
	for (int j = 0; j < height_size; j++) {
		for (int i = width_size; i < MAX_WIDTH; i++) {
			map[i][j] = 0;
		}
	}
	scrollbar.x = 2 + 16;
	scrollbar.y = WINDOW_HEIGHT + 2;
	scrollbar.width = 128;
	scrollbar.height = 16;
	scrollbar.click = 0;

	scrollbar2.x = WINDOW_WIDTH + 2;
	scrollbar2.y = 2 + 16;
	scrollbar2.width = 16;
	scrollbar2.height = 128;
	scrollbar2.click = 0;

	//�}�E�X�̓��͂̏�����
	P_MouseL = 0;

	//���y��w�i�ɍ��킹�ė���
	PM_Number();
}
