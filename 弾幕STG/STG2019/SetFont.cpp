#include"DxLib.h"
#include"extern.h"
#include"function.h"

//�t�H���g�̐ݒ�
void SetFont() {
	Font[0] = CreateFontToHandle("�l�r �S�V�b�N", 20, 10, DX_FONTTYPE_NORMAL);		//"MS�S�V�b�N"��20pt,����10�̃t�H���g���쐬
	//Font[1] = CreateFontToHandle("Arial", 27, 10, DX_FONTTYPE_NORMAL);
	//Font[2] = CreateFontToHandle("�l�r �S�V�b�N", 30, 10, DX_FONTTYPE_NORMAL);
	Font[3] = CreateFontToHandle("�l�r �S�V�b�N", 15, 10, DX_FONTTYPE_NORMAL);
	Font[4] = CreateFontToHandle("�l�r �S�V�b�N", 18, 50, DX_FONTTYPE_NORMAL);
	//Font[4] = CreateFontToHandle("�l�r �S�V�b�N", 20, 10, DX_FONTTYPE_NORMAL);	//�Ⴄ�O���̕��������
}
