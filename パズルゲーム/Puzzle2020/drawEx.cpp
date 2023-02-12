#include"DxLib.h"
#include"extern.h"
#include"function.h"

//��������̕\��
void CKeyPad::drawEx()
{
	const static int red = font.getRed();
	const static int font3 = font.getFont(3);
	const static int font4 = font.getFont(4);

	switch (menuWindow.getFlag())
	{
	case e_title:	//�^�C�g����ʂɂ̂ݑ傫��������`�悷��
		//����
		DrawStringToHandle(360, 420, "�ړ�", red, font4);
		DrawStringToHandle(360, 450, "����/�h��", red, font4);
		DrawStringToHandle(360, 480, "�߂�/�h���b�v", red, font4);
		DrawStringToHandle(360, 510, "�|�[�Y", red, font4);
		//�L�[�{�[�h�̑���
		DrawStringToHandle(505, 390, "�L�[�{�[�h", red, font4);
		DrawStringToHandle(505, 420, "�\���{�^��", red, font4);
		DrawStringToHandle(515, 450, "Z�{�^��", red, font4);	//�V���b�g
		DrawStringToHandle(515, 480, "X�{�^��", red, font4);	//�L�����Z��
		DrawStringToHandle(500, 510, "SPACE�{�^��", red, font4);	//�|�[�Y
																//�Q�[���p�b�h�̑���
		DrawStringToHandle(640, 390, "�Q�[���p�b�h�@", red, font4);
		DrawStringToHandle(645, 420, "�\���{�^��", red, font4);
		DrawFormatStringToHandle(645, 450, red, font4, "%s", cPad[KEY_SHOT]);	//�V���b�g
		DrawFormatStringToHandle(645, 480, red, font4, "%s", cPad[KEY_CANCEL]);	//�L�����Z��
		DrawFormatStringToHandle(645, 510, red, font4, "%s", cPad[KEY_PAUSE]);//�|�[�Y
		break;

	case e_gameplay:
	case e_pause:
	case e_start:
		//�ΐ탂�[�h�ł͕\�����Ȃ�
		if (mode_flag == em_vs)
		{
			break;
		}

		//�E���ɑ���������������\������

		//����
		DrawStringToHandle(530, 465, "�ړ�", red, font3);
		DrawStringToHandle(530, 490, "�h��", red, font3);
		DrawStringToHandle(530, 515, "�|�[�Y", red, font3);
		//�L�[�{�[�h�̑���
		DrawStringToHandle(597, 440, "�L�[�{�[�h", red, font3);
		DrawStringToHandle(597, 465, "�\���{�^��", red, font3);
		DrawStringToHandle(607, 490, "Z�{�^��", red, font3);	//�V���b�g
		DrawStringToHandle(593, 515, "SPACE�{�^��", red, font3);	//�|�[�Y
		//�Q�[���p�b�h�̑���
		DrawStringToHandle(692, 440, "�Q�[���p�b�h�@", red, font3);
		DrawStringToHandle(697, 465, "�\���{�^��", red, font3);
		DrawFormatStringToHandle(703, 490, red, font3, "%s", cPad[KEY_SHOT]);	//�V���b�g
		DrawFormatStringToHandle(703, 515, red, font3, "%s", cPad[KEY_PAUSE]);//�|�[�Y
		break;

	default:
		break;
	}
}
