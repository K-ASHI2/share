#include"DxLib.h"
#include"extern.h"
#include"function.h"

void Title() {

	SelectWindow();
	if (button[KEY_BOMB] == 1) {	//キャンセル
		cursor = N_o_i - 1;	//カーソルを一番下にする
		efs(efs_back);
	}
	if (button[KEY_SHOT] == 1) {//決定
		efs(efs_decision);
		switch (cursor) {
		case 0://ゲームスタート
			mode_flag = em_normal;	//ゲームモードを通常スタートに戻す
			cancel_cursor = 0;
			ChangeFlag(e_characterselect);
			boss.mode_p = 0;
			world = ew_2;
			break;
		//case 1: //エクストラ
		//	cancel_cursor = 1;
		//	ChangeFlag(e_characterselect);
		//	world = ew_extra;
		//	break;
		//case 2: ChangeFlag(e_practice); break;	//プラクティス
		case 1: 
			mode_flag = em_burragepractice;
			ChangeFlag(e_burragepractice);
			break;	//弾幕プラクティス
		//case 4: ChangeFlag(e_option); break;	//オプション
		case 2: ChangeFlag(e_keyconfig); break;	//キーコンフィグ
		//case 3: ChangeFlag(e_soundtest); break;	//サウンドテスト
		case 3:	mode_flag = em_end; break;		//ゲーム終了
		}
	}
}

//タイトル画面の描画
void DrawTitle() {
	DrawGraph(0, 0, img.background_2, TRUE);
	DrawRed(100, 100, "GAME START", 0);
	//DrawRed(100, 150, "EXTRA START", 1);
	//DrawRed(100, 200, "PRACTICE", 2);
	DrawRed(100, 150, "BURRAGE PRACTICE", 1);
	//DrawRed(100, 300, "OPTION", 4);
	DrawRed(100, 200, "KEYCONFIG", 2);
	//DrawRed(100, 250, "SOUNDTEST", 3);
	DrawRed(100, 250, "EXIT", 3);
	//DrawGraph(60, 98 + cursor * 50, img.arrow, TRUE);    //矢印の描画


	DrawStringToHandle(340, 60, "敵の攻撃を避けつつショットを撃ち、", green, Font[0]);
	DrawStringToHandle(340, 90, "hpを0にしたらクリアです。", green, Font[0]);
	DrawStringToHandle(340, 120, "敵の攻撃はhpを減らすと変化していきます。", green, Font[0]);
	DrawStringToHandle(340, 150, "ボムを撃つと無敵になり強い攻撃ができるが、", green, Font[0]);
	DrawStringToHandle(340, 180, "被弾するまでの回数制限があります。", green, Font[0]);
	DrawStringToHandle(340, 230, "敵の弾を消すか弾に近づくと、", green, Font[0]);
	DrawStringToHandle(340, 260, "弾の属性(色)に対応したゲージが溜まります。", green, Font[0]);
	DrawStringToHandle(340, 290, "ゲージが満タンになると減少して0になるまで", green, Font[0]);
	DrawStringToHandle(340, 320, "強いショットが撃てます。", green, Font[0]);
}
