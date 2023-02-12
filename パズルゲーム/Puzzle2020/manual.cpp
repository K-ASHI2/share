#include"DxLib.h"
#include"extern.h"
#include"function.h"

//����
void CMenuWindow::manual()
{
	selectWindow();

	//�L�����Z��
	if (keyPad.getButton(KEY_CANCEL) == 1)
	{
		cursor = N_o_i - 1;	//�J�[�\������ԉ��ɂ���
		music.efs(efs_back);
	}

	//����
	if (keyPad.getButton(KEY_SHOT) == 1)
	{
		if (cursor == N_o_i - 1)
		{
			changeFlag(e_title);
			music.efs(efs_decision);
		}
	}
}

//�L�[�R���t�B�O�̕`��
void CMenuWindow::drawManual()
{
	const static int green = font.getGreen();
	const static int font0 = font.getFont(0);
	DrawGraph(0, 0, img.title, TRUE);
	drawRed(100, 100, "����ɂ���", 0);
	drawRed(100, 150, "�u���b�N�̗���", 1);
	drawRed(100, 200, "���x���ɂ���", 2);
	drawRed(100, 250, "�A���ƃX�R�A", 3);
	drawRed(100, 300, "�����߂̃R�c", 4);
	drawRed(100, 350, "�^�C�g���ɖ߂�", 5);
	
	switch (cursor) {
	case 0:
		DrawStringToHandle(320, 60, "�㉺���E�ňړ����܂��B", green, font0);
		DrawStringToHandle(320, 90, "�h��{�^���������ƃJ�[�\���̐F��h��A", green, font0);
		DrawStringToHandle(320, 120, "NEXT�̉��̐F���J�[�\���̐F�ƂȂ�B", green, font0);
		DrawStringToHandle(320, 150, "NEXT��5�A���ŏo�Ȃ��F�������", green, font0);
		DrawStringToHandle(320, 180, "���̐F�����Ɋm��ŏo������B", green, font0);
		DrawStringToHandle(320, 210, "�h���b�v�{�^���������ƐF�u���b�N��", green, font0);
		DrawStringToHandle(320, 240, "�蓮�ŗ����ł���B", green, font0);
		DrawStringToHandle(320, 270, "�h���b�v�{�^���̗����ł́A���̃u���b�N", green, font0);
		DrawStringToHandle(320, 300, "�����܂ł̎��Ԃ̓��Z�b�g�����B", green, font0);
		DrawStringToHandle(320, 330, "���u���b�N�͓h�邱�Ƃ͂ł��邪�A", green, font0);
		DrawStringToHandle(320, 360, "���̂܂܂ł͑����Ă������Ȃ��B", green, font0);
		DrawStringToHandle(320, 390, "�h���Ă���r���̃u���b�N��", green, font0);
		DrawStringToHandle(320, 420, "���Œ��̃u���b�N�͗������Ȃ��B", green, font0);
		break;

	case 1:
		DrawStringToHandle(320, 60, "�u���b�N�����Ԋu�̓��x���������قǒZ���Ȃ�B", green, font0);
		DrawStringToHandle(320, 90, "�F�u���b�N��6��S�āA����4��݂̂�", green, font0);
		DrawStringToHandle(320, 120, "2�ʂ�Ō��݂ɗ�������B", green, font0);
		DrawStringToHandle(320, 150, "�����z�u�A��ʊO���痎������u���b�N��", green, font0);
		DrawStringToHandle(320, 180, "������ɑ���Ȃ��z�u�ŏo������B", green, font0);
		DrawStringToHandle(320, 210, "���u���b�N�͐F�u���b�N�̗�����1/4�̍��Ԃ�", green, font0);
		DrawStringToHandle(320, 240, "�U�����c���Ă���Ȃ��񕪂�����������B", green, font0);
		DrawStringToHandle(320, 270, "���u���b�N�͈�񕪂�6����x�ɗ��Ƃ��Ȃ�", green, font0);
		DrawStringToHandle(320, 300, "����A�Ⴂ���D�悵�ė�����B", green, font0);
		DrawStringToHandle(320, 330, "��ʊO�Ƀu���b�N���u����Ă���", green, font0);
		DrawStringToHandle(320, 360, "0.5�b�o�Ɣs�k�ƂȂ�B", green, font0);
		break;
	case 2:
		DrawStringToHandle(320, 60, "���x���͍ő�99�܂ŏオ��B", green, font0);
		DrawStringToHandle(320, 90, "�X�R�A��10���҂����ɑ���v���C���[��", green, font0);
		DrawStringToHandle(320, 120, "���x������オ��B", green, font0);
		DrawStringToHandle(320, 150, "���x��50�܂ł̓��x������オ�閈��2/60�b�A", green, font0);
		DrawStringToHandle(320, 180, "���x��51�`99�̓��x������オ�閈��1/60�b", green, font0);
		DrawStringToHandle(320, 210, "�u���b�N�̗����Ԋu�̎��Ԃ��Z���Ȃ�B", green, font0);
		break;
	case 3:
		DrawStringToHandle(320, 60, "�u���b�N�������ƁA200�_�����Z�����B", green, font0);
		DrawStringToHandle(320, 90, "4�ȏ㓯���ɏ����ƁA(�������� - 3)�~2��", green, font0);
		DrawStringToHandle(320, 120, "���u���b�N��������B", green, font0);
		DrawStringToHandle(320, 150, "4�ȏ�����������̃X�R�A��1�ɂ�", green, font0);
		DrawStringToHandle(320, 180, "500�_������ɉ��Z�����B", green, font0);
		DrawStringToHandle(320, 210, "�u���b�N�����������A��ɏ���Ă���u���b�N", green, font0);
		DrawStringToHandle(320, 240, "�S�Ă��A���ΏۂƂȂ�B", green, font0);
		DrawStringToHandle(320, 270, "�A������ƁA�����X�R�A�̊l���Ɣ��u���b�N��", green, font0);
		DrawStringToHandle(320, 300, "���邱�Ƃ��ł���B", green, font0);
		DrawStringToHandle(320, 330, "���u���b�N�̐���2�A���ȏ�̎��A", green, font0);
		DrawStringToHandle(320, 360, "�A���� + 2��������B", green, font0);
		DrawStringToHandle(320, 390, "���������ɂ�链�_�̍��v��", green, font0);
		DrawStringToHandle(320, 420, "(�A���� - 1)�~8�̔{����������B", green, font0);
		break;
	case 4:
		DrawStringToHandle(320, 60, "��������", green, font0);
		DrawStringToHandle(320, 90, "���ԐԐ�", green, font0);
		DrawStringToHandle(320, 120, "��̂悤�ɓh��A�Ԃ�������3�A���܂ł�", green, font0);
		DrawStringToHandle(320, 150, "�ȒP�ɑg�߂�B", green, font0);
		DrawStringToHandle(320, 180, "4�A���ȏ�Ȃ�c�ɘA�����Ȃ���K�v������B", green, font0);
		DrawStringToHandle(320, 210, "�܂��A���Œ��̃u���b�N�̏�̃u���b�N��", green, font0);
		DrawStringToHandle(320, 240, "�����n�߂�O�Ȃ牽�x���h���̂ŁA", green, font0);
		DrawStringToHandle(320, 270, "�A���𖳗���Ȃ��邱�Ƃ��ł���B", green, font0);
		DrawStringToHandle(320, 300, "3�A����1��A4�A����2��A2�A���Ɠ�������", green, font0);
		DrawStringToHandle(320, 330, "1���1��ȏ㑗���B", green, font0);
		DrawStringToHandle(320, 360, "���ȏ㑗��ƍ�����ɂ������̂�", green, font0);
		DrawStringToHandle(320, 390, "�����W�Q�ƂȂ�B", green, font0);
		DrawStringToHandle(320, 420, "�[�̗�͏����ɂ����̂ŁA", green, font0);
		DrawStringToHandle(320, 450, "������x�ӎ�����Ɨǂ������B", green, font0);
		break;
	case 5: break;
	}


}
