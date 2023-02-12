#include"DxLib.h"
#include"extern.h"
#include"function.h"

//操作説明の表示
void DrawEx() {

	//操作説明がオンの時のみ表示する
	if (draw_ex == 1) {
		switch (flag) {
		case e_title:	//タイトル画面にのみ大きく説明を描画する
			//操作
			DrawStringToHandle(360, 430, "移動", red, Font[4]);
			DrawStringToHandle(360, 460, "決定/ショット", red, Font[4]);
			DrawStringToHandle(360, 490, "キャンセル/ボム", red, Font[4]);
			DrawStringToHandle(360, 520, "低速移動", red, Font[4]);
			DrawStringToHandle(360, 550, "ポーズ", red, Font[4]);
			//キーボードの操作
			DrawStringToHandle(505, 400, "キーボード", red, Font[4]);
			DrawStringToHandle(505, 430, "十字ボタン", red, Font[4]);
			DrawStringToHandle(515, 460, "Zボタン", red, Font[4]);	//ショット
			DrawStringToHandle(515, 490, "Xボタン", red, Font[4]);	//ボム
			DrawStringToHandle(500, 520, "SHIFTボタン", red, Font[4]);	//低速
			DrawStringToHandle(500, 550, "SPACEボタン", red, Font[4]);	//ポーズ
																	//ゲームパッドの操作
			DrawStringToHandle(640, 400, "ゲームパッド　", red, Font[4]);
			DrawStringToHandle(645, 430, "十字ボタン", red, Font[4]);
			DrawFormatStringToHandle(645, 460, red, Font[4], "%s", cPad[KEY_SHOT]);	//ショット
			DrawFormatStringToHandle(645, 490, red, Font[4], "%s", cPad[KEY_BOMB]);	//ボム
			DrawFormatStringToHandle(645, 520, red, Font[4], "%s", cPad[KEY_SLOW]);	//低速
			DrawFormatStringToHandle(645, 550, red, Font[4], "%s", cPad[KEY_PAUSE]);//ポーズ
			break;

		case e_gameplay:
			//右下に操作説明を小さく表示する

			//操作
			DrawStringToHandle(530, 465, "移動", red, Font[3]);
			DrawStringToHandle(530, 490, "ショット", red, Font[3]);
			DrawStringToHandle(530, 515, "ボム", red, Font[3]);
			DrawStringToHandle(530, 540, "低速", red, Font[3]);
			DrawStringToHandle(530, 565, "ポーズ", red, Font[3]);
			//キーボードの操作
			DrawStringToHandle(597, 440, "キーボード", red, Font[3]);
			DrawStringToHandle(597, 465, "十字ボタン", red, Font[3]);
			DrawStringToHandle(607, 490, "Zボタン", red, Font[3]);	//ショット
			DrawStringToHandle(607, 515, "Xボタン", red, Font[3]);	//ボム
			DrawStringToHandle(593, 540, "SHIFTボタン", red, Font[3]);	//ボム
			DrawStringToHandle(593, 565, "SPACEボタン", red, Font[3]);	//ポーズ
			//ゲームパッドの操作
			DrawStringToHandle(692, 440, "ゲームパッド　", red, Font[3]);
			DrawStringToHandle(697, 465, "十字ボタン", red, Font[3]);
			DrawFormatStringToHandle(703, 490, red, Font[3], "%s", cPad[KEY_SHOT]);	//ショット
			DrawFormatStringToHandle(703, 515, red, Font[3], "%s", cPad[KEY_BOMB]);	//ボム
			DrawFormatStringToHandle(703, 540, red, Font[3], "%s", cPad[KEY_SLOW]);	//低速
			DrawFormatStringToHandle(703, 565, red, Font[3], "%s", cPad[KEY_PAUSE]);//ポーズ
			break;

		default:
			////タイトルとゲームプレイ中以外
			////ゲームプレイ中より少し左の右下に操作説明を小さく表示する
			////操作
			//DrawStringToHandle(520, 465, "移動", red, Font[3]);
			//DrawStringToHandle(520, 490, "ショット", red, Font[3]);
			//DrawStringToHandle(520, 515, "ボム", red, Font[3]);
			//DrawStringToHandle(520, 540, "低速", red, Font[3]);
			//DrawStringToHandle(520, 565, "ポーズ", red, Font[3]);
			////キーボードの操作
			//DrawStringToHandle(587, 440, "キーボード", red, Font[3]);
			//DrawStringToHandle(587, 465, "十字ボタン", red, Font[3]);
			//DrawStringToHandle(597, 490, "Zボタン", red, Font[3]);	//ショット
			//DrawStringToHandle(597, 515, "Xボタン", red, Font[3]);	//ボム
			//DrawStringToHandle(583, 540, "SHIFTボタン", red, Font[3]);	//ボム
			//DrawStringToHandle(583, 565, "SPACEボタン", red, Font[3]);	//ポーズ
			//														//ゲームパッドの操作
			//DrawStringToHandle(682, 440, "ゲームパッド　", red, Font[3]);
			//DrawStringToHandle(687, 465, "十字ボタン", red, Font[3]);
			//DrawFormatStringToHandle(693, 490, red, Font[3], "%s", cPad[KEY_SHOT]);	//ショット
			//DrawFormatStringToHandle(693, 515, red, Font[3], "%s", cPad[KEY_BOMB]);	//ボム
			//DrawFormatStringToHandle(693, 540, red, Font[3], "%s", cPad[KEY_SLOW]);	//低速
			//DrawFormatStringToHandle(693, 565, red, Font[3], "%s", cPad[KEY_PAUSE]);//ポーズ
			break;
		}
	}
}
