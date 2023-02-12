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
	Font[0] = CreateFontToHandle("ＭＳ ゴシック", 20, 10, DX_FONTTYPE_NORMAL);	//"MSゴシック"の20pt,太さ10のフォントを作成
	Font[1] = CreateFontToHandle("Arial", 40, 10, DX_FONTTYPE_NORMAL);
	Font[2] = CreateFontToHandle("ＭＳ ゴシック", 30, 15, DX_FONTTYPE_NORMAL);
	Font[3] = CreateFontToHandle("ＭＳ ゴシック", 15, 10, DX_FONTTYPE_NORMAL);
	Font[4] = CreateFontToHandle("ＭＳ ゴシック", 18, 50, DX_FONTTYPE_NORMAL);
	Font[5] = CreateFontToHandle("ＭＳ ゴシック", 17, 7, DX_FONTTYPE_NORMAL);	//スコア用の小さいフォント
	Font[6] = CreateFontToHandle("メイリオ", 25, 12, DX_FONTTYPE_NORMAL);	//連鎖数の描画用フォント
	Font[7] = CreateFontToHandle("Arial", 80, 10, DX_FONTTYPE_NORMAL);
}
