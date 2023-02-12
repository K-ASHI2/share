#include"DxLib.h"
#include"extern.h"
#include"function.h"

//ブロックの消滅
void CPlayer::vanishCheck()
{
	//横方向の削除チェックを行う
	sideCheck();

	//縦方向の削除チェックを行う
	verticalCheck();

	//削除する
	if (mode_flag == em_score_attack)
	{
		blockVanish();
	}
	else if(mode_flag == em_vs){
		blockVanishVs();
	}
}

//横方向の削除チェックを行う
void CPlayer::sideCheck()
{
	//一列ずつチェックしていく
	for (int j = 1; j <= FIELD_H; j++)
	{
		e_color countColor = ec_null;
		int count = 0;
		//揃ったブロックのうち一番連鎖数が多い物に合わせた連鎖数で消滅する
		int maxChain = 0;

		for (int i = 1; i <= FIELD_W; i++) {
			//消滅中でない色のついたブロックがある限りカウントする
			if (block[i][j].getColor() > 0 && block[i][j].getVanishCount() == 0)
			{
				//カウントしていない時
				//一つ目のブロックか何もない場所の次ならカウント中の色を設定する
				if (countColor == ec_null)
				{
					countColor = block[i][j].getColor();
					count = 1;
					maxChain = block[i][j].getChain();
				}
				//カウント中の色なら加算する
				else if (countColor == block[i][j].getColor())
				{
					count++;
					//より大きな連鎖数のブロックがあれば変える
					if (block[i][j].getChain() > maxChain)
					{
						maxChain = block[i][j].getChain();
					}
				}
				//カウント中の色以外の時
				else {
					//カウントが3以上ならカウントしたブロック全てに削除フラグを立てる
					if (count >= 3)
					{
						//今のブロックの一つ手前からn個が消えるブロックとなる
						for (int k = 1; k <= count; k++)
						{
							block[i - k][j].setVanishFlag(true);

							//消滅するブロックの連鎖数を最大の物に揃える
							//縦>横の連鎖数で同時に消えると連鎖数がずれるがほぼ起きないので無視(縦やってからもう一度チェックすればよい？)
							block[i - k][j].setChain(maxChain);
						}
					}
					//違う色が出たらその色にする
					countColor = block[i][j].getColor();
					count = 1;
					maxChain = block[i][j].getChain();
					//画面端が近くて消えないならbreakする
					if (i >= FIELD_W - 1)
					{
						break;
					}
				}
			}
			//ブロックがないならカウントを無くす
			else
			{
				if (count >= 1)
				{
					if (count >= 3)
					{
						for (int k = 1; k <= count; k++)
						{
							block[i - k][j].setVanishFlag(true);
							block[i - k][j].setChain(maxChain);
						}
					}
					countColor = ec_null;
					count = 0;
					maxChain = 0;
				}
				//画面端が近くて消えないならbreakする
				if (i >= FIELD_W - 2)
				{
					break;
				}
			}
		}
		//端に到達した時にブロックが揃っているなら削除フラグを立てる
		if (count >= 3)
		{
			for (int k = 0; k < count; k++)
			{
				block[FIELD_W - k][j].setVanishFlag(true);
				block[FIELD_W - k][j].setChain(maxChain);
			}
		}
	}
}

//縦方向の削除チェックを行う
void CPlayer::verticalCheck()
{
	//一列ずつチェックしていく
	for (int i = 1; i <= FIELD_W; i++)
	{
		e_color countColor = ec_null;
		int count = 0;
		//揃ったブロックのうち一番連鎖数が多い物に合わせた連鎖数で消滅する
		int maxChain = 0;

		for (int j = 1; j <= FIELD_H; j++)
		{
			//消滅中でない色のついたブロックがある限りカウントする
			if (block[i][j].getColor() > 0 && block[i][j].getVanishCount() == 0)
			{
				//カウントしていない時
				//一つ目のブロックか何もない場所の次ならカウント中の色を設定する
				if (countColor == ec_null)
				{
					countColor = block[i][j].getColor();
					count = 1;
					maxChain = block[i][j].getChain();
				}
				//カウント中の色なら加算する
				else if (countColor == block[i][j].getColor())
				{
					count++;
					//より大きな連鎖数のブロックがあれば変える
					if (block[i][j].getChain() > maxChain)
					{
						maxChain = block[i][j].getChain();
					}
				}
				//カウント中の色以外の時
				else {
					//カウントが3以上ならカウントしたブロック全てに削除フラグを立てる
					if (count >= 3)
					{
						//今のブロックの一つ手前からn個が消えるブロックとなる
						for (int k = 1; k <= count; k++)
						{
							block[i][j - k].setVanishFlag(true);

							//消滅するブロックの連鎖数を最大の物に揃える
							//縦>横の連鎖数で同時に消えると連鎖数がずれるがほぼ起きないので無視(縦やってからもう一度チェックすればよい？)
							block[i][j - k].setChain(maxChain);
						}
					}
					//違う色が出たらその色にする
					countColor = block[i][j].getColor();
					count = 1;
					maxChain = block[i][j].getChain();
					//画面端が近くて消えないならbreakする
					if (j >= FIELD_H - 1)
					{
						break;
					}
				}
			}
			//ブロックがないならカウントを無くす
			else
			{
				if (count >= 1)
				{
					if (count >= 3)
					{
						for (int k = 1; k <= count; k++)
						{
							block[i][j - k].setVanishFlag(true);
							block[i][j - k].setChain(maxChain);
						}
					}
					countColor = ec_null;
					count = 0;
					maxChain = 0;
				}
				//画面端が近くて消えないならbreakする
				if (j >= FIELD_H - 2)
				{
					break;
				}
			}
		}
		//端に到達した時にブロックが揃っているなら削除フラグを立てる
		if (count >= 3)
		{
			for (int k = 0; k < count; k++)
			{
				block[i][FIELD_H - k].setVanishFlag(true);
				block[i][FIELD_H - k].setChain(maxChain);
			}
		}
	}
}

//ブロックを削除する(スコアアタックモード)
void CPlayer::blockVanish()
{
	if (comboTime > 0)
	{
		comboTime--;
		if (comboTime == 0)
		{
			combo = 0;
		}
	}

	//一度に消えたブロックの数
	int count = 0;

	for (int j = 1; j <= FIELD_H; j++)
	{
		for (int i = 1; i <= FIELD_W; i++)
		{
			//ブロックの消滅中の処理
			if (block[i][j].getVanishCount() > 0)
			{
				block[i][j].decrementVanishCount();
				//ブロックが完全に消滅したら色を無くし、フラグを戻す
				if (block[i][j].getVanishCount() == 0)
				{
					block[i][j].setVanishFlag(false);
					block[i][j].setColor(ec_null);
				}
			}

			//消滅が決まっているブロックについて消滅時間をつける
			//消滅が決まった時に書いてもいいが、ここで行うと一応縦横同時に消えた時に処理回数は減る
			else if (block[i][j].getVanishFlag())
			{
				block[i][j].setVanishCount(VANISH_TIME);
				count++;
			}
		}
	}

	if (count > 0)
	{
		combo++;
		//1.5秒コンボ時間を継続させる
		//加算方式に変更してもいいかも
		comboTime = COMBO_TIME;

		double rate = 1.0;

		//コンボボーナス
		if (combo >= 2)
		{
			if (combo <= 6)
			{
				rate += 0.3;
			}
			else if (combo < 10)
			{
				rate += 0.2;
			}
			//コンボボーナスの限界
			else
			{
				rate += 0.0;
			}
		}

		//コンボが無い時に消える場合のスコア
		int baseScore = 0;

		if (count == 3)
		{
			baseScore = 1000;
		}
		else if (count == 4)
		{
			baseScore = 2000;
		}
		else if (count == 5)
		{
			baseScore = 4000;
		}
		else
		{
			baseScore = count * 1500;
		}
		score += (long long)(baseScore * rate);
		music.efs(efs_vanish);
	}
}

static int MAX_CHAIN_TIME = 20;

//対戦モードにおけるブロックの削除開始処理
void CPlayer::blockVanishVs()
{

	//連鎖が接地してすぐに起きなければ連鎖数をリセット
	for (int j = 1; j <= FIELD_H; j++)
	{
		for (int i = 1; i <= FIELD_W; i++)
		{
			if (block[i][j].getChainTime() > 0 && block[i][j].getVanishCount() == 0)
			{
				block[i][j].decrementChainTime();
				if (block[i][j].getChainTime() == 0)
				{
					block[i][j].setChain(0);
				}
			}
		}
	}

	//対戦モードでは消え終わった時に一度に消えたブロックの数を数える
	//消滅後に攻撃判定とスコアの判定を行いたいから
	int count = 0;

	//連鎖数ごとに消えたブロックの数を数える
	//0は使わず1～9で表し、9連鎖以上は9と同じ扱い(多分起きないし今のところ無視)
	int chainCount[10];
	for (int i = 1; i <= 9; i++)
	{
		chainCount[i] = 0;
	}

	for (int j = 1; j <= FIELD_H; j++)
	{
		for (int i = 1; i <= FIELD_W; i++)
		{
			//ブロックの消滅中の処理
			if (block[i][j].getVanishCount() > 0)
			{
				block[i][j].decrementVanishCount();
				//ブロックが完全に消滅したら色を無くし、フラグを戻す
				if (block[i][j].getVanishCount() == 0)
				{
					block[i][j].setVanishFlag(false);
					block[i][j].setColor(ec_null);
					count++;
					int c = block[i][j].getChain();
					if (c > 10)
					{
						c = 9;
					}
					chainCount[c]++;

					for (int k = j + 1; k <= FIELD_H; k++)
					{
						//ブロックが存在しないマスがあればそこで終わり
						if (block[i][k].getColor() == 0 || block[i][k].getVanishCount() > 0)
						{
							break;
						}
						//上のブロック全てに連鎖数を与える(1つ加算する)
						block[i][k].setChain(block[i][j].getChain() + 1);
					}
				}
			}

			//消滅が決まっているブロックについて消滅時間をつける
			//消滅が決まった時に書いてもいいが、ここで行うと一応縦横同時に消えた時に処理回数は減る
			else if (block[i][j].getVanishFlag())
			{
				block[i][j].setVanishCount(VANISH_TIME);

				//連鎖のカウントを増やし、連鎖の継続時間を設定(リセット)する
				//chainCount++;
				//chainTime = MAX_CHAIN_TIME;

			}
		}
	}

	if (count > 0)
	{

		//コンボが無い時に消える場合のスコアをまず設定する
		//消した個数 * 200 点
		int baseScore = count * 200;

		//4つを超えていたらその分は追加で500点
		if (count > 4)
		{
			baseScore += (count - 4) * 500;
		}

		int drop = 0;

		//4個以上消したら攻撃判定
		if (count >= 4)
		{
			//3を引いた数だけドロップ
			//drop = count - 3;
			drop += (count - 3) * 2;
			//addOpponentDropNotice(drop);
		}

		double rate = 1.0;

		for (int i = 1; i <= 9; i++)
		{
			switch (chainCount[i])
			{
			case 1: break;
			case 2: drop += 4; rate += 8.0; break;
			case 3: drop += 5; rate += 16.0; break;
			case 4: drop += 6; rate += 24.0; break;
			case 5: drop += 7; rate += 32.0; break;
			case 6: drop += 8; rate += 40.0; break;
			case 7: drop += 9; rate += 48.0; break;
			case 8: drop += 10; rate += 56.0; break;
			case 9: drop += 11; rate += 64.0; break;
			}
		}
		addOpponentDropNotice(drop);

		//連鎖ボーナス
		//if (chain >= 2)
		//{
		//	//コンボして消すと一つ追加で落とす
		//	int drop = 1;
		//	addOpponentDropNotice(drop);

		//	if (combo <= 6)
		//	{
		//		rate += 0.3;
		//	}
		//	else if (combo < 10)
		//	{
		//		rate += 0.2;
		//	}
		//	//コンボボーナスの限界
		//	else
		//	{
		//		rate += 0.0;
		//	}
		//}

		score += (long long)(baseScore * rate);
		music.efs(efs_vanish);
	}
}

void CPlayer::addOpponentDropNotice(int dropNotice)
{
	if (this->p == e_1p)
	{
		player2.addDropNotice(dropNotice);
	}
	else if (this->p == e_2p)
	{
		player1.addDropNotice(dropNotice);
	}
}


//x,yの位置にブロックを撃った時、そのブロックによって消滅が起こるかどうか
bool CPlayer::shotVanishCheck(int x, int y)
{
	e_color thisColor = nextBlock[0].getColor();

	//ブロックが存在しないマスか塗っている途中のマスならばfalseを返す
	if (block[x][y].getColor() == ec_null || block[x][y].getDrawEffectCount() > 0) {
		return false;
	}
	
	//左右の判定
	if (x > 1)
	{
		if (block[x - 1][y].getColor() == thisColor && block[x - 1][y].getDrawEffectCount() == 0)
		{
			//左二つと同じ色
			if (x > 2)
			{
				if (block[x - 2][y].getColor() == thisColor && block[x - 2][y].getDrawEffectCount() == 0)
				{
					return true;
				}
			}

			//左右と同じ色
			if (x < FIELD_W)
			{
				if (block[x + 1][y].getColor() == thisColor && block[x + 1][y].getDrawEffectCount() == 0)
				{
					return true;
				}
			}
		}
	}

	//右二つと同じ色
	if (x < FIELD_W - 1)
	{
		if (block[x + 1][y].getColor() == thisColor && block[x + 1][y].getDrawEffectCount() == 0
			&& block[x + 2][y].getColor() == thisColor && block[x + 2][y].getDrawEffectCount() == 0)
		{
			return true;
		}
	}

	//上下の判定
	if (y > 1)
	{
		if (block[x][y - 1].getColor() == thisColor && block[x][y - 1].getDrawEffectCount() == 0)
		{
			//下二つと同じ色
			if (y > 2)
			{
				if (block[x][y - 2].getColor() == thisColor && block[x][y - 2].getDrawEffectCount() == 0)
				{
					return true;
				}
			}

			//上下と同じ色
			if (y < FIELD_H)
			{
				if (block[x][y + 1].getColor() == thisColor && block[x][y + 1].getDrawEffectCount() == 0)
				{
					return true;
				}
			}
		}
	}

	//上二つと同じ色
	if (y < FIELD_H - 1)
	{
		if (block[x][y + 1].getColor() == thisColor && block[x][y + 1].getDrawEffectCount() == 0
			&& block[x][y + 2].getColor() == thisColor && block[x][y + 2].getDrawEffectCount() == 0)
		{
			return true;
		}
	}

	return false;
}

//x,yの位置とその右のマスの横2マスにブロックを撃った時、そのブロックによって消滅が起こるかどうか
bool CPlayer::shotVanishCheckTwin(int x, int y)
{
	e_color thisColor = nextBlock[0].getColor();

	//塗れないマスがあれば、もう片方のマスのみを塗った時のチェックをすればよい
	if (!drawableCheck(x, y)) {
		return shotVanishCheck(x + 1, y);
	}
	else if (!drawableCheck(x + 1, y)) {
		return shotVanishCheck(x, y);
	}

	//左右の判定
	if (x > 1)
	{
		//左と同じ色
		if (block[x - 1][y].getColor() == thisColor && block[x - 1][y].getDrawEffectCount() == 0)
		{
			return true;
		}
	}

	//右と同じ色
	if (x < FIELD_W - 1)
	{
		if (block[x + 2][y].getColor() == thisColor && block[x + 2][y].getDrawEffectCount() == 0)
		{
			return true;
		}
	}

	//上下の判定
	if (y > 1)
	{
		if (block[x][y - 1].getColor() == thisColor && block[x][y - 1].getDrawEffectCount() == 0)
		{
			//下二つと同じ色
			if (y > 2)
			{
				if (block[x][y - 2].getColor() == thisColor && block[x][y - 2].getDrawEffectCount() == 0)
				{
					return true;
				}
			}

			//上下と同じ色
			if (y < FIELD_H)
			{
				if (block[x][y + 1].getColor() == thisColor && block[x][y + 1].getDrawEffectCount() == 0)
				{
					return true;
				}
			}
		}
	}

	//上二つと同じ色
	if (y < FIELD_H - 1)
	{
		if (block[x][y + 1].getColor() == thisColor && block[x][y + 1].getDrawEffectCount() == 0
			&& block[x][y + 2].getColor() == thisColor && block[x][y + 2].getDrawEffectCount() == 0)
		{
			return true;
		}
	}

	return false;
}

//x,yの座標に塗った時に2マス色が揃うかどうか
bool CPlayer::shotAlignCheck(int x, int y)
{
	e_color thisColor = nextBlock[0].getColor();

	//塗れないマスならfalseを返す
	if (!drawableCheck(x, y)) {
		return false;
	}

	//左と同じ色
	if (x > 1)
	{
		if (block[x - 1][y].getColor() == thisColor && block[x - 1][y].getDrawEffectCount() == 0)
		{
			return true;
		}
	}

	//右と同じ色
	if (x < FIELD_W - 1)
	{
		if (block[x + 1][y].getColor() == thisColor && block[x + 1][y].getDrawEffectCount() == 0)
		{
			return true;
		}
	}

	//下と同じ色
	if (y > 1)
	{
		if (block[x][y - 1].getColor() == thisColor && block[x][y - 1].getDrawEffectCount() == 0)
		{
			return true;
		}
	}

	//上と同じ色
	if (y < FIELD_H - 1)
	{
		if (block[x][y + 1].getColor() == thisColor && block[x][y + 1].getDrawEffectCount() == 0)
		{
			return true;
		}
	}

	return false;
}

//x,yの座標が2マス色が揃っている
bool CPlayer::alignCheck(int x, int y)
{
	e_color thisColor = block[x][y].getColor();

	//ブロックが存在しないマスか塗っている途中のマスならばfalseを返す
	if (thisColor == ec_null || block[x][y].getDrawEffectCount() > 0) {
		return false;
	}

	//左と同じ色
	if (x > 1)
	{
		if (block[x - 1][y].getColor() == thisColor && block[x - 1][y].getDrawEffectCount() == 0)
		{
			return true;
		}
	}

	//右と同じ色
	if (x < FIELD_W - 1)
	{
		if (block[x + 1][y].getColor() == thisColor && block[x + 1][y].getDrawEffectCount() == 0)
		{
			return true;
		}
	}

	//下と同じ色
	if (y > 1)
	{
		if (block[x][y - 1].getColor() == thisColor && block[x][y - 1].getDrawEffectCount() == 0)
		{
			return true;
		}
	}

	//上と同じ色
	if (y < FIELD_H - 1)
	{
		if (block[x][y + 1].getColor() == thisColor && block[x][y + 1].getDrawEffectCount() == 0)
		{
			return true;
		}
	}

	return false;
}

//x,yの座標1マスに塗れるかどうかのチェック
bool CPlayer::drawableCheck(int x, int y)
{
	//色が無いか、消滅中のブロックなら塗れない
	if (block[x][y].getColor() == ec_null || block[x][y].getDrawEffectCount() > 0) {
		return false;
	}
	else
	{
		return true;
	}
}

//x,yの座標とその右の横2マスに塗れるかどうかのチェック
bool CPlayer::drawableCheckTwin(int x, int y)
{
	//どちらかのマスが塗れればtrueを返す
	if (drawableCheck(x, y) || drawableCheck(x + 1, y)) {
		return true;
	}
	else
	{
		return false;
	}
}
