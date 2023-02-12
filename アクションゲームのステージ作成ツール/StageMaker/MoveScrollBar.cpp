#include"DxLib.h"
#include"extern.h"
#include"function.h"	//���ʂ̊֐�

//�X�e�[�W�쐬���̃X�N���[���o�[�̈ړ�
void MoveScrollBar() {

	int Wheel = GetMouseWheelRotVol();	//�z�C�[���̉�]�ʎ擾

	static int BAR_FRAME = 2;	//�X�N���[���o�[�̘g�̑傫��
	static int SCROLL_BUTTON = 16;	//�X�N���[���o�[�̒[�̃{�^���̑傫��
	static int FRAME_AND_BUTTON = BAR_FRAME + SCROLL_BUTTON;	//�t���[���ƃ{�^���̑傫���̘a

	//�X�N���[�����镝
	//��ʂ̕��̕��̓X�N���[�����Ȃ��̂ň���
	int cx2 = width_size * 32 - WINDOW_WIDTH;
	int cy2 = height_size * 32 - WINDOW_HEIGHT;

	//1�t���[���O�ɉ�����Ă���Ȃ�J�[�\���̈ړ������������ړ�������
	if (scrollbar.click == 1) {
		if (mx != mx2) {
			scrollbar.x += mx - mx2;
			stage_x = (scrollbar.x - FRAME_AND_BUTTON)* cx2 / (WINDOW_WIDTH - (FRAME_AND_BUTTON * 2 +  scrollbar.width));
		}
	}
	else if(scrollbar2.click == 1){
		if (my != my2) {
			scrollbar2.y += my - my2;
			stage_y = (scrollbar2.y - FRAME_AND_BUTTON) * cy2 / (WINDOW_HEIGHT - (FRAME_AND_BUTTON * 2 + scrollbar2.height));
		}
	}

	//���𓮂����Ă��鎞�͔������Ȃ��悤�ɂ���
	if (c_move == false) {
		//�}�E�X���N���b�N����Ă��邩�ǂ����̔���
		if (MouseL == 1) {
			//��
			//�o�[�̕���
			if (mx >= scrollbar.x && mx <= scrollbar.x + scrollbar.width && my >= scrollbar.y && my <= scrollbar.y + scrollbar.height) {
				scrollbar.click = 1;
			}
			//����ȊO�̕���
			//���̈ʒu�܂Ńo�[�ƃX�e�[�W�𓮂���
			else if (mx >= FRAME_AND_BUTTON && mx <= WINDOW_WIDTH - FRAME_AND_BUTTON && my >= scrollbar.y && my <= scrollbar.y + scrollbar.height) {
				scrollbar.click = 1;
				scrollbar.x = mx - scrollbar.width / 2;
				stage_x = (scrollbar.x - FRAME_AND_BUTTON) * cx2 / (WINDOW_WIDTH - (FRAME_AND_BUTTON * 2 + scrollbar.width));
			}
			//�c
			//�o�[�̕���
			if (mx >= scrollbar2.x && mx <= scrollbar2.x + scrollbar2.width && my >= scrollbar2.y && my <= scrollbar2.y + scrollbar2.height) {
				scrollbar2.click = 1;
			}
			//����ȊO�̕���
			//���̈ʒu�܂Ńo�[�ƃX�e�[�W�𓮂���
			else if (mx >= scrollbar2.x && mx <= scrollbar2.x + scrollbar2.width && my >= FRAME_AND_BUTTON && my <= WINDOW_HEIGHT - FRAME_AND_BUTTON) {
				scrollbar2.click = 1;
				scrollbar2.y = my - scrollbar2.height / 2;
				stage_y = (scrollbar2.y - FRAME_AND_BUTTON) * cy2 / (WINDOW_HEIGHT - (FRAME_AND_BUTTON * 2 + scrollbar2.height));
			}
		}
		//�}�E�X���N���b�N����Ȃ��Ȃ�����0�ɖ߂�
		else {
			if (scrollbar.click == 1) {
				scrollbar.click = 0;
			}
			else if (scrollbar2.click == 1) {
				scrollbar2.click = 0;
			}
		}
	}

	//�{�^���ɂ��X�N���[��
	//��
	if (JudgeMouse2(2, WINDOW_HEIGHT + 2, FRAME_AND_BUTTON, WINDOW_HEIGHT + FRAME_AND_BUTTON)) {
		stage_x -= 8;
	}
	//�E
	if (JudgeMouse2(WINDOW_WIDTH - FRAME_AND_BUTTON, WINDOW_HEIGHT + 2, WINDOW_WIDTH - 2, WINDOW_HEIGHT + FRAME_AND_BUTTON)) {
		stage_x += 8;
	}
	//��
	if (JudgeMouse2(WINDOW_WIDTH + 2, 2, WINDOW_WIDTH + FRAME_AND_BUTTON, FRAME_AND_BUTTON)) {
		stage_y -= 8;
	}
	//��
	if (JudgeMouse2(WINDOW_WIDTH + 2, WINDOW_HEIGHT - FRAME_AND_BUTTON, WINDOW_WIDTH + FRAME_AND_BUTTON, WINDOW_HEIGHT - 2)) {
		stage_y += 8;
	}

	//�X�N���[���o�[���}�E�X�ő��삵�Ă��Ȃ����̂݃L�[������\�ɂ���
	if(scrollbar.click == 0 && scrollbar2.click == 0) {
		//�E�[�ȊO�Ȃ�E�ɓ�����
		if (button[KEY_RIGHT] && stage_x < width_size * block_size - WINDOW_WIDTH)
			if (Key[KEY_INPUT_LCONTROL])	//C�������Ȃ��獶�E�ō����X�N���[��
				stage_x += 24;
			else
				stage_x += 8;
		/*else if (Wheel > 0)
			stage_x += 32;*/

		//���[�ȊO�Ȃ獶�ɓ�����
		if (button[KEY_LEFT] && stage_x > 0)
			if (Key[KEY_INPUT_LCONTROL])
				stage_x -= 24;
			else
				stage_x -= 8;
		/*else if (Wheel < 0)
			stage_x -= 32;*/

		//���[�ȊO�Ȃ牺�ɓ�����
		if (button[KEY_DOWN] && stage_y < height_size * block_size - WINDOW_HEIGHT)
			if (Key[KEY_INPUT_LCONTROL])	//C�������Ȃ��獶�E�ō����X�N���[��
				stage_y += 24;
			else
				stage_y += 8;
		/*else if (Wheel > 0)
		stage_x += 32;*/

		//��[�ȊO�Ȃ��ɓ�����
		if (button[KEY_UP] && stage_y > 0)
			if (Key[KEY_INPUT_LCONTROL])
				stage_y -= 16;
			else
				stage_y -= 8;
		/*else if (Wheel < 0)
		stage_x -= 32;*/
	}
	//�X�N���[���o�[�𑀍삵�Ă���Ȃ�o�[�ƈႤ�����̎�������Ă��Ă��X�N���[���o�[��ɂ���Ƃ���
	else {
		if (scrollbar.click == 1 && scrollbar2.click == 0) {
			my = my2;
		}
		else if (scrollbar.click == 0 && scrollbar2.click == 1) {
			mx = mx2;
		}
	}

	//��ʊO�ɏo�Ȃ��悤�ɂ���
	if (stage_x > width_size * block_size - GetDrawWidth())
		stage_x = width_size * block_size - GetDrawWidth();
	else if (stage_x < 0)
		stage_x = 0;
	if (stage_y > height_size * block_size - GetDrawHeight())
		stage_y = height_size * block_size - GetDrawHeight();
	else if (stage_y < 0)
		stage_y = 0;

	//�X�N���[���o�[�̍��W�����߂�
	//�X�N���[���o�[�̘g+�{�^���̑傫��+��ʂ̉���-(�X�N���[���o�[�̘g*2+�{�^���̑傫��*2+����) * �w�i�̍��W/�X�N���[���̕�
	if (cx2 != 0) {
		scrollbar.x = FRAME_AND_BUTTON + ((WINDOW_WIDTH - (FRAME_AND_BUTTON * 2 + scrollbar.width)) * stage_x / cx2);
	}
	if (cy2 != 0) {
		scrollbar2.y = FRAME_AND_BUTTON + ((WINDOW_HEIGHT - (FRAME_AND_BUTTON * 2 + scrollbar2.height)) * stage_y / cy2);
	}
}

//�ҏW�\�ȉ�ʓ��̕������߂ĕԂ�
int GetDrawWidth() {

	if (width_size * block_size < WINDOW_WIDTH) {
		return width_size * block_size;
	}
	else {
		return WINDOW_WIDTH;
	}
}

//�ҏW�\�ȉ�ʓ��̍��������߂ĕԂ�
int GetDrawHeight() {

	if (height_size * block_size < WINDOW_HEIGHT) {
		return height_size * block_size;
	}
	else {
		return WINDOW_HEIGHT;
	}
}
