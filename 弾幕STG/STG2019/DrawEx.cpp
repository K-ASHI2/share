#include"DxLib.h"
#include"extern.h"
#include"function.h"

//��������̕\��
void DrawEx() {

	//����������I���̎��̂ݕ\������
	if (draw_ex == 1) {
		switch (flag) {
		case e_title:	//�^�C�g����ʂɂ̂ݑ傫��������`�悷��
			//����
			DrawStringToHandle(360, 430, "�ړ�", red, Font[4]);
			DrawStringToHandle(360, 460, "����/�V���b�g", red, Font[4]);
			DrawStringToHandle(360, 490, "�L�����Z��/�{��", red, Font[4]);
			DrawStringToHandle(360, 520, "�ᑬ�ړ�", red, Font[4]);
			DrawStringToHandle(360, 550, "�|�[�Y", red, Font[4]);
			//�L�[�{�[�h�̑���
			DrawStringToHandle(505, 400, "�L�[�{�[�h", red, Font[4]);
			DrawStringToHandle(505, 430, "�\���{�^��", red, Font[4]);
			DrawStringToHandle(515, 460, "Z�{�^��", red, Font[4]);	//�V���b�g
			DrawStringToHandle(515, 490, "X�{�^��", red, Font[4]);	//�{��
			DrawStringToHandle(500, 520, "SHIFT�{�^��", red, Font[4]);	//�ᑬ
			DrawStringToHandle(500, 550, "SPACE�{�^��", red, Font[4]);	//�|�[�Y
																	//�Q�[���p�b�h�̑���
			DrawStringToHandle(640, 400, "�Q�[���p�b�h�@", red, Font[4]);
			DrawStringToHandle(645, 430, "�\���{�^��", red, Font[4]);
			DrawFormatStringToHandle(645, 460, red, Font[4], "%s", cPad[KEY_SHOT]);	//�V���b�g
			DrawFormatStringToHandle(645, 490, red, Font[4], "%s", cPad[KEY_BOMB]);	//�{��
			DrawFormatStringToHandle(645, 520, red, Font[4], "%s", cPad[KEY_SLOW]);	//�ᑬ
			DrawFormatStringToHandle(645, 550, red, Font[4], "%s", cPad[KEY_PAUSE]);//�|�[�Y
			break;

		case e_gameplay:
			//�E���ɑ���������������\������

			//����
			DrawStringToHandle(530, 465, "�ړ�", red, Font[3]);
			DrawStringToHandle(530, 490, "�V���b�g", red, Font[3]);
			DrawStringToHandle(530, 515, "�{��", red, Font[3]);
			DrawStringToHandle(530, 540, "�ᑬ", red, Font[3]);
			DrawStringToHandle(530, 565, "�|�[�Y", red, Font[3]);
			//�L�[�{�[�h�̑���
			DrawStringToHandle(597, 440, "�L�[�{�[�h", red, Font[3]);
			DrawStringToHandle(597, 465, "�\���{�^��", red, Font[3]);
			DrawStringToHandle(607, 490, "Z�{�^��", red, Font[3]);	//�V���b�g
			DrawStringToHandle(607, 515, "X�{�^��", red, Font[3]);	//�{��
			DrawStringToHandle(593, 540, "SHIFT�{�^��", red, Font[3]);	//�{��
			DrawStringToHandle(593, 565, "SPACE�{�^��", red, Font[3]);	//�|�[�Y
			//�Q�[���p�b�h�̑���
			DrawStringToHandle(692, 440, "�Q�[���p�b�h�@", red, Font[3]);
			DrawStringToHandle(697, 465, "�\���{�^��", red, Font[3]);
			DrawFormatStringToHandle(703, 490, red, Font[3], "%s", cPad[KEY_SHOT]);	//�V���b�g
			DrawFormatStringToHandle(703, 515, red, Font[3], "%s", cPad[KEY_BOMB]);	//�{��
			DrawFormatStringToHandle(703, 540, red, Font[3], "%s", cPad[KEY_SLOW]);	//�ᑬ
			DrawFormatStringToHandle(703, 565, red, Font[3], "%s", cPad[KEY_PAUSE]);//�|�[�Y
			break;

		default:
			////�^�C�g���ƃQ�[���v���C���ȊO
			////�Q�[���v���C����菭�����̉E���ɑ���������������\������
			////����
			//DrawStringToHandle(520, 465, "�ړ�", red, Font[3]);
			//DrawStringToHandle(520, 490, "�V���b�g", red, Font[3]);
			//DrawStringToHandle(520, 515, "�{��", red, Font[3]);
			//DrawStringToHandle(520, 540, "�ᑬ", red, Font[3]);
			//DrawStringToHandle(520, 565, "�|�[�Y", red, Font[3]);
			////�L�[�{�[�h�̑���
			//DrawStringToHandle(587, 440, "�L�[�{�[�h", red, Font[3]);
			//DrawStringToHandle(587, 465, "�\���{�^��", red, Font[3]);
			//DrawStringToHandle(597, 490, "Z�{�^��", red, Font[3]);	//�V���b�g
			//DrawStringToHandle(597, 515, "X�{�^��", red, Font[3]);	//�{��
			//DrawStringToHandle(583, 540, "SHIFT�{�^��", red, Font[3]);	//�{��
			//DrawStringToHandle(583, 565, "SPACE�{�^��", red, Font[3]);	//�|�[�Y
			//														//�Q�[���p�b�h�̑���
			//DrawStringToHandle(682, 440, "�Q�[���p�b�h�@", red, Font[3]);
			//DrawStringToHandle(687, 465, "�\���{�^��", red, Font[3]);
			//DrawFormatStringToHandle(693, 490, red, Font[3], "%s", cPad[KEY_SHOT]);	//�V���b�g
			//DrawFormatStringToHandle(693, 515, red, Font[3], "%s", cPad[KEY_BOMB]);	//�{��
			//DrawFormatStringToHandle(693, 540, red, Font[3], "%s", cPad[KEY_SLOW]);	//�ᑬ
			//DrawFormatStringToHandle(693, 565, red, Font[3], "%s", cPad[KEY_PAUSE]);//�|�[�Y
			break;
		}
	}
}
