#include "Font2.h"

CFont2::CFont2()
{
}

CFont2::~CFont2()
{
}

int CFont2::getBlack()
{
	return black;
}

int CFont2::getRed()
{
	return red;
}

int CFont2::getGreen()
{
	return green;
}

int CFont2::getLiteGreen()
{
	return liteGreen;
}

int CFont2::getSilver()
{
	return silver;
}

int CFont2::getWhite()
{
	return white;
}

int CFont2::getFont(int fontNumber)
{
	return Font[fontNumber];
}

void CFont2::init()
{
	Font[0] = CreateFontToHandle("�l�r �S�V�b�N", 20, 10, DX_FONTTYPE_NORMAL);	//"MS�S�V�b�N"��20pt,����10�̃t�H���g���쐬
	Font[1] = CreateFontToHandle("Arial", 40, 10, DX_FONTTYPE_NORMAL);
	Font[2] = CreateFontToHandle("�l�r �S�V�b�N", 30, 15, DX_FONTTYPE_NORMAL);
	Font[3] = CreateFontToHandle("�l�r �S�V�b�N", 15, 10, DX_FONTTYPE_NORMAL);
	Font[4] = CreateFontToHandle("�l�r �S�V�b�N", 18, 50, DX_FONTTYPE_NORMAL);
	Font[5] = CreateFontToHandle("�l�r �S�V�b�N", 17, 7, DX_FONTTYPE_NORMAL);	//�X�R�A�p�̏������t�H���g
	Font[6] = CreateFontToHandle("���C���I", 25, 12, DX_FONTTYPE_NORMAL);	//�A�����̕`��p�t�H���g
	Font[7] = CreateFontToHandle("Arial", 80, 10, DX_FONTTYPE_NORMAL);
}
