#include"DxLib.h"
#include"extern.h"
#include"function.h"

void CPlayer::update()
{
	//プレイヤーの移動
	movePlayer();

	//ブロックの消滅
	vanishCheck();

	//落下後のフィールドを求めなおす
	resultFieldInit();

	//ブロックの自然落下状態への移行
	blockFall();

	//スコアアタックモード
	if (mode_flag == em_score_attack)
	{
		//一定時間毎に一段を落とす
		if (dropCount == dropInterval)
		{
			dropBlock(1);
			dropCount = 0;
		}
		else
		{
			dropCount++;
		}

		//ハイスコアの更新
		//更新したらクリア画面で参照できるようにフラグを立てる
		if (hiscore < score)
		{
			hiscore = score;
			hiscore_flag = true;
		}

		//クリア画面への移行
		if (timelimit == 0)
		{
			menuWindow.changeFlag(e_clear);
		}
		else {
			//制限時間を減らす
			timelimit--;

			//ポーズボタンの処理
			if (keyPad.getButton(KEY_PAUSE) == 1)
			{
				menuWindow.changeFlag(e_pause);
			}
		}
	}

	//対戦モード
	else if (mode_flag == em_vs)
	{

		//一定時間毎に一段を落とす
		if (dropCount >= dropInterval)
		{
			//中央のみに落とすのを2～3回に1回入れる1
			if (nextDropMode == endm_normal)
			{
				dropBlock(1);
				nextDropMode = endm_center;
			}
			else if (nextDropMode == endm_center)
			{
				//中央4マスのみにドロップする
				dropCenter();
				nextDropMode = endm_normal;
			}
			dropCount = 0;
		}

		//ブロックが落下した直後でなく攻撃があれば処理する
		//1/4の時間毎に判定し、落とす
		//dropIntervalが4で割り切れない場合、予告を落とした直後に色ブロックの落下になるので直前は落下させない
		//else if (dropCount > 10 && dropNotice > 0) {
		else if (dropCount % (dropInterval / 4) == 0 && dropCount < dropInterval - 10 && dropNotice > 0) {

			//予告の個数分を落とす
			dropWhite();

			//連続で落ちて重なるのを避ける
			/*if (dropCount > dropInterval - 10)
			{
				dropCount = dropInterval - 10;
			}*/
		}

		dropCount++;

		////連鎖中の時、空中に連鎖するブロックが存在せず、消滅中のブロックも存在しないならカウントを減少
		//if (chainTime > 0)
		//{
		//	bool decrement = true;
		//	//全ての落下中のブロックを落下させる
		//	for (int k = 0; k <= FIELD_W * FIELD_H; k++)
		//	{
		//		//一つでも連鎖できるブロックがあれば終了
		//		if (fallingBlock[k].getChain())
		//		{
		//			decrement = false;
		//			break;
		//		}
		//	}
		//	if (decrement)
		//	{
		//		for (int i = 1; i <= FIELD_W; i++)
		//		{
		//			for (int j = 1; j <= FIELD_H; j++)
		//			{
		//				//一つでも消滅中のブロックがあれば終了
		//				if (block[i][j].getVanishFlag())
		//				{
		//					decrement = false;
		//					break;
		//				}
		//			}
		//			if (!decrement)
		//			{
		//				break;
		//			}
		//		}
		//		if (decrement)
		//		{
		//			chainTime--;
		//			//連鎖時間が切れたらリセット
		//			if (chainTime == 0)
		//			{
		//				chainCount = 0;
		//			}
		//		}
		//	}

		//}

		//一番上(画面外)の段に一定時間存在したらゲームオーバーにする
		//画面外に乗ってから少しだけ時間の猶予を与える
		for (int i = 1; i <= FIELD_W; i++)
		{
			if (block[i][FIELD_H].getColor() != ec_null)
			{
				loseCount[i]++;
				if (loseCount[i] == LOSE_LIMIT)
				{
					gameover = true;
					break;
				}
			}
			else {
				if (loseCount[i] > 0)
				{
					loseCount[i]--;
				}
			}
		}

		//リザルト画面への移行
		//1Pと2Pが同時に敗北すると2回呼び出されるので問題ありそうなら直す
		if (gameover)
		{
			menuWindow.changeFlag(e_win);
		}
		else
		{
			//ポーズボタンの処理
			if (keyPad.getButton(KEY_PAUSE) == 1)
			{
				menuWindow.changeFlag(e_pause);
			}
		}
	}
}
