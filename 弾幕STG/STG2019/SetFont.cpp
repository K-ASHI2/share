#include"DxLib.h"
#include"extern.h"
#include"function.h"

//フォントの設定
void SetFont() {
	Font[0] = CreateFontToHandle("ＭＳ ゴシック", 20, 10, DX_FONTTYPE_NORMAL);		//"MSゴシック"の20pt,太さ10のフォントを作成
	//Font[1] = CreateFontToHandle("Arial", 27, 10, DX_FONTTYPE_NORMAL);
	//Font[2] = CreateFontToHandle("ＭＳ ゴシック", 30, 10, DX_FONTTYPE_NORMAL);
	Font[3] = CreateFontToHandle("ＭＳ ゴシック", 15, 10, DX_FONTTYPE_NORMAL);
	Font[4] = CreateFontToHandle("ＭＳ ゴシック", 18, 50, DX_FONTTYPE_NORMAL);
	//Font[4] = CreateFontToHandle("ＭＳ ゴシック", 20, 10, DX_FONTTYPE_NORMAL);	//違う外見の文字を作る
}
