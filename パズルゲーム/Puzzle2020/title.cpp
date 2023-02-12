#include"DxLib.h"
#include"extern.h"
#include"function.h"

void CMenuWindow::title()
{
	selectWindow();

	//キャンセル
	if (keyPad.getButton(KEY_CANCEL) == 1)
	{
		cursor = N_o_i - 1;	//カーソルを一番下にする
		music.efs(efs_back);
	}

	//決定
	if (keyPad.getButton(KEY_SHOT) == 1)
	{	
		music.efs(efs_decision);
		switch (cursor)
		{
		case 0://cpu対戦モード
			mode_flag = em_vs;	//ゲームモードを通常スタートに戻す
			cancel_cursor = 0;
			init();
			player1.setCpuMove(ec_player);
			changeFlag(e_movemenu, lastSelectedCPUMode);
			break;
		case 1:	//対人戦モード
			mode_flag = em_vs;	//ゲームモードを通常スタートに戻す
			cancel_cursor = 1;
			init();
			player1.setCpuMove(ec_player);
			player2.setCpuMove(ec_player);
			changeFlag(e_operationmenu);
			break;
		case 2://コンボアタック
			mode_flag = em_score_attack;	//ゲームモードを通常スタートに戻す
			cancel_cursor = 2;
			init();
			changeFlag(e_start);
			break;
		case 3://マニュアル
			changeFlag(e_manual);
			cancel_cursor = 3;
			break;
		case 4: //キーコンフィグ
			changeFlag(e_keyconfig);
			cancel_cursor = 4; 
			break;
		case 5:	mode_flag = em_end; break;		//ゲーム終了
		//case 0://ゲームスタート
		//	mode_flag = em_score_attack;	//ゲームモードを通常スタートに戻す
		//	cancel_cursor = 0;
		//	init();
		//	changeFlag(e_movemenu);
		//	break;
		//case 1:	//対戦モード
		//	mode_flag = em_vs;	//ゲームモードを通常スタートに戻す
		//	cancel_cursor = 1;
		//	init();
		//	changeFlag(e_movemenu);
		//	break;	//キーコンフィグ
		//case 2: changeFlag(e_keyconfig); break;	//キーコンフィグ
		//case 3:	mode_flag = em_end; break;		//ゲーム終了
		}
	}
}

//タイトル画面の描画
void CMenuWindow::drawTitle()
{
	const static int green = font.getGreen();
	const static int font0 = font.getFont(0);
	DrawGraph(0, 0, img.title, TRUE);
	drawRed(100, 100, "VS CPU", 0);
	drawRed(100, 150, "VS PLAYER", 1);
	drawRed(100, 200, "COMBO ATTACK MODE", 2);
	drawRed(100, 250, "MANUAL", 3);
	drawRed(100, 300, "KEYCONFIG", 4);
	drawRed(100, 350, "EXIT", 5);
	//drawRed(100, 100, "GAME START", 0);
	//drawRed(100, 150, "VS START", 1);
	//drawRed(100, 200, "KEYCONFIG", 2);
	//drawRed(100, 250, "EXIT", 3);


	//選択中の項目に関する説明
	switch (cursor) {
	case 0: DrawString(100, 550, "CPUと対戦します", green);
		DrawStringToHandle(320, 60, "カーソルを動かしてブロックを塗り、", green, font0);
		DrawStringToHandle(320, 90, "3つ以上縦横に色を揃えると消えます。", green, font0);
		DrawStringToHandle(320, 120, "塗るボタンを押すとカーソルの色が塗られます。", green, font0);
		DrawStringToHandle(320, 150, "一定時間毎にブロックが落下してきます。", green, font0);
		DrawStringToHandle(320, 180, "ブロックの消滅による落下で色が揃った場合、", green, font0);
		DrawStringToHandle(320, 210, "連鎖となり、連鎖数に応じて強い攻撃ができます。", green, font0);
		DrawStringToHandle(320, 240, "また、4つ以上で消しても攻撃することができます。", green, font0);
		DrawStringToHandle(320, 270, "攻撃すると相手の場に白のブロックが降ります。", green, font0);
		DrawStringToHandle(320, 300, "白のブロックは揃っても消えませんが、塗れます。", green, font0);
		DrawStringToHandle(320, 330, "画面外に到達するとゲームオーバーです。", green, font0);
		DrawStringToHandle(320, 360, "より詳しい説明はMANUALで見ることができます。", green, font0);
		break;

	case 1: DrawString(100, 550, "プレイヤー2人で対戦します", green);
		DrawStringToHandle(320, 60, "カーソルを動かしてブロックを塗り、", green, font0);
		DrawStringToHandle(320, 90, "3つ以上縦横に色を揃えると消えます。", green, font0);
		DrawStringToHandle(320, 120, "塗るボタンを押すとカーソルの色が塗られます。", green, font0);
		DrawStringToHandle(320, 150, "一定時間毎にブロックが落下してきます。", green, font0);
		DrawStringToHandle(320, 180, "ブロックの消滅による落下で色が揃った場合、", green, font0);
		DrawStringToHandle(320, 210, "連鎖となり、連鎖数に応じて強い攻撃ができます。", green, font0);
		DrawStringToHandle(320, 240, "また、4つ以上で消しても攻撃することができます。", green, font0);
		DrawStringToHandle(320, 270, "攻撃すると相手の場に白のブロックが降ります。", green, font0);
		DrawStringToHandle(320, 300, "白のブロックは揃っても消えませんが、塗れます。", green, font0);
		DrawStringToHandle(320, 330, "画面外に到達するとゲームオーバーです。", green, font0);
		DrawStringToHandle(320, 360, "より詳しい説明はMANUALで見ることができます。", green, font0); 
		break;
	case 2: DrawString(100, 550, "一分間でなるべくコンボを繋ぐモード", green);
		DrawStringToHandle(320, 60, "カーソルを動かしてブロックを塗り、", green, font0);
		DrawStringToHandle(320, 90, "3つ以上縦横に色を揃えると消えます。", green, font0);
		DrawStringToHandle(320, 120, "塗るボタンを押すとカーソルの色が塗られます。", green, font0);
		DrawStringToHandle(320, 150, "ブロックを消してから1.5秒以内に消すと", green, font0);
		DrawStringToHandle(320, 180, "コンボがつながります。(連鎖はありません)", green, font0);
		DrawStringToHandle(320, 210, "コンボが多いほどスコアが多く入ります。", green, font0);
		DrawStringToHandle(320, 240, "制限時間の1分が経つと終了となります。", green, font0);
		DrawStringToHandle(320, 270, "制限時間内により多くのスコアを稼ぎましょう。", green, font0);
		break;
	case 3: DrawString(100, 550, "ルールの詳細説明", green);
		DrawStringToHandle(320, 60, "対戦モードの詳細な遊び方や、", green, font0);
		DrawStringToHandle(320, 90, "具体的な数値について見ることができます。", green, font0);
		break;
	case 4: DrawString(100, 550, "コントローラのボタン設定", green);
		DrawStringToHandle(320, 60, "ゲームパッドを使用する時の", green, font0);
		DrawStringToHandle(320, 90, "ボタン配置の設定ができます。", green, font0);
		DrawStringToHandle(320, 120, "1Pも2Pも同じボタン配置となります。", green, font0);
		break;
	case 5: DrawString(100, 550, "ゲームをやめる", green); break;
	}
}
