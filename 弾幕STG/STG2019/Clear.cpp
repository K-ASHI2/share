#include"DxLib.h"
#include"extern.h"
#include"function.h"
#include"math.h"

//クリア画面
void Clear() {
	
	if (mode_flag == em_normal) {
		//決定ボタンが押されたらタイトル画面に戻る
		if ((button[KEY_SHOT] == 1 || button[KEY_PAUSE] == 1) && time > 120) {
			if (boss.mode_p != 0) {
				ChangeFlag(e_burragepractice, boss.mode_p - 1);
			}
			else {
				ChangeFlag(e_title);
			}
			efs(efs_decision);//決定の効果音
		}
	}
	else {
		if (time > 40) {
			SelectWindow(1);
			if (button[KEY_SHOT] == 1) {

				efs(efs_decision);
				switch (cursor) {
				case 0:
					ChangeFlag(e_burragepractice, boss.mode_p - 1);
					break;
				case 1:
					ChangeFlag(e_gameplay);
					init();
					break;
				case 2:
					ChangeFlag(e_title);
					break;
				}
			}
		}
	}
}

//クリア画面の描画
void DrawClear() {

	static int hiscore_flag = 0;
	SetDrawBright(128, 128, 128);
	DrawBackGround();	//背景の描画
	DrawPlay();		//ゲームプレイ中の描画
	SetDrawBright(255, 255, 255);

	if (mode_flag == em_normal) {
		DrawGraph(200, 150, img.clear_frame, FALSE);	//なぜかTRUEだと透過される
		DrawString(357, 180, "CLEAR", black);
		if (time == 0) {
			player.score += player.bomb * 100000;
			player.score += player.life * 1000000;
			//ハイスコアをファイルに書き込む関数
			if (player.score > hiscore) {
				hiscore = player.score;
				WriteHiscore();
				hiscore_flag = 1;
			}
			else {
				hiscore_flag = 0;
			}
		}
		else {
			if (time > 60) {
				if (player.score < 10) {
					DrawFormatString(296, 230, black, "%7d", player.score);
				}
				else if (player.score < 100) {
					DrawFormatString(311, 230, black, "%7d", player.score);
				}
				else if (player.score < 1000) {
					DrawFormatString(321, 230, black, "%7d", player.score);
				}
				else if (player.score < 10000) {
					DrawFormatString(331, 230, black, "%7d", player.score);
				}
				else {
					DrawFormatString(341, 230, black, "%7d", player.score);
				}
			}
			if (time > 120 && time % 60 < 40) {
				if (hiscore_flag == 1) {
					DrawStringToHandle(337, 290, "NEW RECORD!", red, Font[0]);
				}
				else {
					DrawStringToHandle(335, 290, "PUSH BUTTON", red, Font[0]);
				}
			}
		}
	}
	else {
		if (time > 30) {
			DrawGraph(200, 150, img.clear_frame, FALSE);
			DrawRed(307, 180, "BURRAGE SELECT", 0);
			DrawRed(347, 230, "RETRY", 1);
			DrawRed(347, 280, "TITLE", 2);
		}
	}
	time++;
}
