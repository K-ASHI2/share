#include"DxLib.h"
#include"extern.h"
#include"function.h"	//���ʂ̊֐�

//1�t���[���̏����I�����̃`�F�b�N
void EndCheck();

void CreateStage() {

	//1�t���[���O�̃}�E�X�̓��͂�ۑ�����
	mx2 = mx;
	my2 = my;
	//1�t���[���O�̍��N���b�N�̓��̗͂L����ۑ�����
	P_MouseL = MouseL;

	Mouse = GetMouseInput();	//�}�E�X�̓��͏�Ԏ擾
	GetMousePoint(&mx, &my);	//�}�E�X�̍��W�擾

	//���N���b�N�̓��̗͂L��
	if (Mouse & MOUSE_INPUT_LEFT)
		MouseL = 1;
	else
		MouseL = 0;

	//�X�N���[���o�[�̈ړ�
	MoveScrollBar();
	//���j���[�̕ύX
	CSChangeMenu();

	//���j���[���X�e�[�^�X�̎�������ɃO���b�h��\������
	//����ȊO�̎��͕\�����Ȃ��̂�-1�ɂ���
	if (menu_b != 4) {
		sx = -1;
		sy = -1;
	}

	if (MouseL == 1) { //�}�E�X�̍��{�^����������Ă�����
		if (mx > 0 && mx < GetDrawWidth()
			&& my > 0 && my < GetDrawHeight()) {	//�}�E�X�J�[�\������ʓ��ɂ���Ȃ�
			sx = (mx + stage_x) / block_size;	//�O���b�h�̍��W��ύX����
			sy = (my + stage_y) / block_size;
		}
	}

	//1�t���[���̏����I�����̃`�F�b�N
	EndCheck();
}

//1�t���[���̏����I�����̃`�F�b�N
void EndCheck() {

	//���𓮂����Ă���Œ��łȂ��Ȃ�
	if (c_move == false) {
		//�֎~�����u���������Ă�������Ƃɖ߂��A�����łȂ��Ȃ�o�b�N�A�b�v�����
		if (ProhibitCheck() == 1) {
			for (int j = 0; j < height_size; j++) {
				for (int i = 0; i < width_size; i++) {
					map[i][j] = backup[back_c][i][j];	//�}�b�v�̑S�Ă̍��W�����ɖ߂�
				}
			}
			if (stage_x > width_size * block_size - WINDOW_WIDTH)	//��ʃT�C�Y���ύX����Ă�����
				stage_x = width_size * block_size - WINDOW_WIDTH;	//�J�[�\�����E�[�ɂ���
		}
		else {
			BackUp();		//�o�b�N�A�b�v��ۑ�����
		}
	}
}
