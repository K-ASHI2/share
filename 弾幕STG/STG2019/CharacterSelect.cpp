#include"DxLib.h"
#include"extern.h"
#include"function.h"

//キャラ選択画面
void CharacterSelect() {

	SelectWindow();
	SelectWindow_LR();
	if (button[KEY_BOMB] == 1) {//キャンセル
		ChangeFlag(cancel_flag, cancel_cursor);
		cancel_cursor = 0;
		efs(efs_back);
	}
	if (button[KEY_SHOT] == 1) {	//決定
		efs(efs_decision);
		switch (cursor_LR) {
		case 0: 
			switch (cursor) {
			case 0: player.character = player.D_Magician_A; break;
			case 1: player.character = player.L_Magician_A; break;
			case 2: ChangeFlag(e_title); break;
			}
			break;
		case 1:
			switch (cursor) {
			case 0: player.character = player.D_Magician_B; break;
			case 1: player.character = player.L_Magician_B; break;
			}
			break;
		}
		ChangeFlag(e_difficultyselect);
	}
}

//キャラクター選択画面の描画
void DrawCharacterSelect() {

	DrawGraph(0, 0, img.background_2, TRUE);
	DrawStringToHandle(320, 70, "PLAYER SELECT", black, Font[0]);
	DrawStringToHandle(80, 100, "Moon Magician", black, Font[0]);
	DrawString(100, 130, "あたり判定が小さい", black);

	DrawRed2(100, 160, "A　 ワイドショット", 0, 0);
	DrawRed2(100, 188, "ショット　クレセントカッター", 0, 0);
	DrawRed2(100, 213, "ボム　　スターダストエクスプロージョン", 0, 0);
	DrawRed2(100, 238, "ボム数　3", 0, 0);
	DrawRed2(100, 266, "攻撃範囲が広く扱いやすい", 0, 0);
	DrawRed2(100, 291, "ボムは全画面判定で威力はそこそこ", 0, 0);

	DrawRed2(420, 160, "B  　変則ワイドショット", 0, 1);
	DrawRed2(420, 188, "ショット　ニュームーンダークネス", 0, 1);
	DrawRed2(420, 213, "ボム　　　ブラックホール", 0, 1);
	DrawRed2(420, 238, "ボム数　4", 0, 1);
	DrawRed2(420, 266, "通常ショットが微妙だが属性ショットは強め", 0, 1);
	DrawRed2(420, 291, "ボムが多いので上手く使うとよい", 0, 1);

	DrawStringToHandle(80, 340, "Sun Magician", black, Font[0]);
	DrawString(100, 370, "移動速度が速い", black, Font[0]);

	DrawRed2(100, 400, "A　　高火力貫通レーザー", 1, 0);
	DrawRed2(100, 428, "ショット　サンシャインレイ", 1, 0);
	DrawRed2(100, 453, "ボム　　　ソーラースパーク", 1, 0);
	DrawRed2(100, 475, "ボム数　2", 1, 0);
	DrawRed2(100, 503, "攻撃範囲が狭いが高火力", 1, 0);
	DrawRed2(100, 528, "ボムも少ないが高火力", 1, 0);

	DrawRed2(420, 400, "B　　全方位ショット", 1, 1);
	DrawRed2(420, 428, "ショット　サンシャインブラスト", 1, 1);
	DrawRed2(420, 453, "ボム　　　アルティメットフラッシュ", 1, 1);
	DrawRed2(420, 475, "ボム数　5", 1, 1);
	DrawRed2(420, 503, "ボム数がとても多いがショットもボムも弱い", 1, 1);
	DrawRed2(420, 528, "密着して撃ち込むと強いが使いにくい", 1, 1);
}

