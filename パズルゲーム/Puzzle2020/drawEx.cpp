#include"DxLib.h"
#include"extern.h"
#include"function.h"

//操作説明の表示
void CKeyPad::drawEx()
{
	const static int red = font.getRed();
	const static int font3 = font.getFont(3);
	const static int font4 = font.getFont(4);

	switch (menuWindow.getFlag())
	{
	case e_title:	//タイトル画面にのみ大きく説明を描画する
		//操作
		DrawStringToHandle(360, 420, "移動", red, font4);
		DrawStringToHandle(360, 450, "決定/塗る", red, font4);
		DrawStringToHandle(360, 480, "戻る/ドロップ", red, font4);
		DrawStringToHandle(360, 510, "ポーズ", red, font4);
		//キーボードの操作
		DrawStringToHandle(505, 390, "キーボード", red, font4);
		DrawStringToHandle(505, 420, "十字ボタン", red, font4);
		DrawStringToHandle(515, 450, "Zボタン", red, font4);	//ショット
		DrawStringToHandle(515, 480, "Xボタン", red, font4);	//キャンセル
		DrawStringToHandle(500, 510, "SPACEボタン", red, font4);	//ポーズ
																//ゲームパッドの操作
		DrawStringToHandle(640, 390, "ゲームパッド　", red, font4);
		DrawStringToHandle(645, 420, "十字ボタン", red, font4);
		DrawFormatStringToHandle(645, 450, red, font4, "%s", cPad[KEY_SHOT]);	//ショット
		DrawFormatStringToHandle(645, 480, red, font4, "%s", cPad[KEY_CANCEL]);	//キャンセル
		DrawFormatStringToHandle(645, 510, red, font4, "%s", cPad[KEY_PAUSE]);//ポーズ
		break;

	case e_gameplay:
	case e_pause:
	case e_start:
		//対戦モードでは表示しない
		if (mode_flag == em_vs)
		{
			break;
		}

		//右下に操作説明を小さく表示する

		//操作
		DrawStringToHandle(530, 465, "移動", red, font3);
		DrawStringToHandle(530, 490, "塗る", red, font3);
		DrawStringToHandle(530, 515, "ポーズ", red, font3);
		//キーボードの操作
		DrawStringToHandle(597, 440, "キーボード", red, font3);
		DrawStringToHandle(597, 465, "十字ボタン", red, font3);
		DrawStringToHandle(607, 490, "Zボタン", red, font3);	//ショット
		DrawStringToHandle(593, 515, "SPACEボタン", red, font3);	//ポーズ
		//ゲームパッドの操作
		DrawStringToHandle(692, 440, "ゲームパッド　", red, font3);
		DrawStringToHandle(697, 465, "十字ボタン", red, font3);
		DrawFormatStringToHandle(703, 490, red, font3, "%s", cPad[KEY_SHOT]);	//ショット
		DrawFormatStringToHandle(703, 515, red, font3, "%s", cPad[KEY_PAUSE]);//ポーズ
		break;

	default:
		break;
	}
}
