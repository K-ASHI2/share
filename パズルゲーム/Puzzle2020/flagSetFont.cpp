#include"DxLib.h"
#include"extern.h"
#include"function.h"

//�t���O���Ƃ̃t�H���g�����߂�
void flagSetFont()
{
	switch (menuWindow.getFlag())
	{
	case e_gameplay:
		SetFontSize(20);
		SetFontThickness(10);
		break;

	case e_pause:
		SetFontSize(32);
		SetFontThickness(3);
		break;

	default:
		SetFontSize(24);		// �`�悷�镶����̃T�C�Y��ݒ�
		SetFontThickness(2);	// �`�悷�镶����̑�����ݒ�
		break;
	}
}
