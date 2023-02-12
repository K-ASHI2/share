#include"DxLib.h"
#include"extern.h"
#include"function.h"

//フラグごとのフォントを決める
void flagSetFont() {

	switch (flag) {
	case e_gameplay:
		SetFontSize(20);
		SetFontThickness(10);
		break;

	case e_characterselect:
		SetFontSize(16);
		SetFontThickness(5);
		break;

	case e_pause:
		SetFontSize(32);
		SetFontThickness(3);
		break;

	default:
		SetFontSize(24);		// 描画する文字列のサイズを設定
		SetFontThickness(2);	// 描画する文字列の太さを設定
		break;
	}
}
