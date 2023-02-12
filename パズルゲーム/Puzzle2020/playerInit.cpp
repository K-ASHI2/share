#include"DxLib.h"
#include"extern.h"

void CPlayer::init(e_player p)
{
	this->p = p;
	x = 3;
	t = 0;
	shot_t = 0;
	score = 0;
	combo = 0;
	color_n = 4;
	level = 1;
	dropNotice = 0;
	gameover = false;
	comboTime = 0;
	dropCount = 0;
	nextDropMode = endm_normal;
	fallingBlockInit();
	nextInit();
	resultFieldClear();

	for (int i = 1; i <= color_n; i++)
	{
		notAppearCount[i] = 0;
	}

	//プレイヤー操作なら思考時間のディレイを0にする
	if (cpuMove == ec_player)
	{
		thinkingTime = 0;
	}

	for (int i = 1; i <= FIELD_W; i++)
	{
		loseCount[i] = 0;
	}

	if (mode_flag == em_score_attack)
	{
		y = 6;
		dropInterval = 60;
	}
	else if (mode_flag == em_vs)
	{
		y = 3;
		//要調整
		//攻撃で落ちる量が増えるので最初は遅めでも良さそう
		dropInterval = 240;
	}

	if (p == e_1p)
	{
		fieldInit();
		field_left = G_W_LEFT;
		field_right = G_W_RIGHT;
		field_upper = G_W_UPPER;
		field_lower = G_W_LOWER;

	}
	else if (p == e_2p)
	{
		//2Pは1Pと同じ初期フィールドにする
		fieldClear();
		fieldCopy(player1);
		field_left = G_W_LEFT_2;
		field_right = G_W_RIGHT_2;
		field_upper = G_W_UPPER;
		field_lower = G_W_LOWER;
	}
}

//フィールドを空にする
void CPlayer::fieldClear()
{
	for (int j = 1; j <= FIELD_H; j++)
	{
		for (int i = 1; i <= FIELD_W; i++)
		{
			block[i][j].setColor(ec_null);
			block[i][j].setDrawColor(ec_null);
			block[i][j].setVanishFlag(false);
			block[i][j].setVanishCount(0);
			block[i][j].setDrawEffectCount(0);
			block[i][j].setChain(0);
			block[i][j].setChainTime(0);
		}
	}
}

//フィールドの初期化
void CPlayer::fieldInit()
{
	//最初にフィールドを空にする
	//全部空にするのは時間の無駄だが、計算量が少ないので無視する
	fieldClear();

	//フィールドに積み上げる初期の高さ
	//スコアアタックでは画面全体、対戦では半分
	int height = FIELD_H - 1;
	if (mode_flag == em_vs)
	{
		height = 6;
	}

	for (int j = 1; j <= height; j++)
	{
		for (int i = 1; i <= FIELD_W; i++)
		{
			block[i][j].init(i, j);

			//c++の仕様では配列の要素数に変数を入れる場合ポインタを使わなければならない
			//メモリ確保はバグが発生するのでvectorを使う
			std::vector<bool> usable(color_n + 1);

			//全ての色を最初は使用可能にする
			for (int k = 1; k <= color_n; k++)
			{
				usable[k] = true;
			}

			//周りのブロックと同じ色にならないようにする
			//後で置く部分は調べなくてよい
			if (i > 1)
			{
				usable[(int)block[i - 1][j].getColor()] = false;
			}
			if (j > 1)
			{
				usable[(int)block[i][j - 1].getColor()] = false;
			}

			int usable_n = 0;

			for (int k = 1; k <= color_n; k++)
			{
				if (usable[k])
				{
					usable_n++;
				}
			}

			std::vector<e_color> usableColor(usable_n);

			int l = 0;

			for (int k = 1; k <= color_n; k++)
			{
				if (usable[k])
				{
					usableColor[l++] = (e_color)k;
				}
			}

			//printfDx("%s%d\n", "sizeof(usableColor) : ", sizeof(usableColor));

			block[i][j].setColor(getRandomUsableColor(usableColor, usable_n));
		}
	}
}

//指定されたプレイヤーのフィールドをコピーする
void CPlayer::fieldCopy(CPlayer player)
{
	for (int j = 1; j <= FIELD_H; j++)
	{
		for (int i = 1; i <= FIELD_W; i++)
		{
			block[i][j].init(i, j);
			block[i][j].setColor(player.getBlock(i, j).getColor());
		}
	}
}

//使用可能と指定された色の中からランダムで色を返す
e_color CPlayer::getRandomUsableColor(const std::vector<e_color> &usable, int n)
{
	const int rand = GetRand(n - 1);
	return usable[rand];
}

//プレイヤーが使用する色の中からランダムで色を取得する
e_color CPlayer::getRandomColor()
{
	return (e_color)(GetRand(color_n - 1) + 1);
}

//落下中のブロックの初期化
void CPlayer::fallingBlockInit()
{
	for (int k = 0; k < FIELD_H * FIELD_W; k++)
	{
		fallingBlock[k].init();
	}
}

//落下後のフィールドを空にする
void CPlayer::resultFieldClear()
{
	for (int j = 1; j <= FIELD_H; j++)
	{
		for (int i = 1; i <= FIELD_W; i++)
		{
			resultField[i][j] = ec_null;
		}
	}
}

//落下後のフィールドを求めなおす
void CPlayer::resultFieldInit()
{
	//落下中のブロックが落ちた後の状態を初期化し、新たに求める
	resultFieldClear();

	//フィールドに存在するブロックをまず入れておく
	for (int j = 1; j <= FIELD_H; j++)
	{
		for (int i = 1; i <= FIELD_W; i++)
		{
			resultField[i][j] = block[i][j].getColor();
		}
	}

	//落下中のブロックに対し、落下先の状態にする
	//まずソートし、高さが低い順にする
	quickSort(fallingBlock, FIELD_H * FIELD_W);

	for (int k = 0; k < FIELD_H * FIELD_W; k++)
	{
		//ソートされて後ろに空の要素があるので見つけたら終わりにする
		if (fallingBlock[k].getY() == INT_MAX)
		{
			break;
		}

		//ブロックを落下後の状態に保存する
		const int i = fallingBlock[k].getLine();
		const int h = getHighestResultBlock(i);
		resultField[i][h + 1] = fallingBlock[k].getColor();
	}
}

//NEXTとholdの初期化
void CPlayer::nextInit()
{
	for (int i = 0; i < NEXT_N; i++)
	{
		e_color color = getRandomColor();
		nextBlock[i].setColor(color);
	}
}
