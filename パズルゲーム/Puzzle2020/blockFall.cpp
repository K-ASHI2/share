#include "DxLib.h"
#include "extern.h"
#include "Player.h"
#include <vector>

//ブロックの落下
void CPlayer::blockFall()
{
	//下にブロックがない時にそのブロックを落下状態にする 
	for (int j = 2; j <= FIELD_H; j++)
	{
		for (int i = 1; i <= FIELD_W; i++)
		{
			//消滅中でも塗っている途中でもないブロックに対し,下にブロックが無ければ行う
			if (block[i][j].getColor() != ec_null && block[i][j].getVanishCount() == 0 && block[i][j].getDrawEffectCount() == 0)
			{
				if (block[i][j - 1].getColor() == ec_null)
				{
					//ブロックのある場所に落下ブロックを生成し、連鎖判定を持たせる
					int k = createFallingBlock(i, j, block[i][j].getColor());

					//ブロックの持っている連鎖数を落下中も持つ
					fallingBlock[k].setChain(block[i][j].getChain());

					block[i][j].init(i, j);
				}
			}
		}
	}

	//落下速度
	static const int vy = 6;

	//低い順にソートしたほうがいいかも

	//全ての落下中のブロックを落下させる
	for (int k = 0; k <= FIELD_W * FIELD_H; k++)
	{
		if (fallingBlock[k].getColor() != ec_null)
		{
			fallingBlock[k].addY(vy);

			//今いる列を取得し、その列に対し判定する
			const int line = fallingBlock[k].getLine();

			//一番高いブロックのy座標を得る
			//const int h = getHighestBlock(line);
			const int h = getHighestUnderBlock(line, fallingBlock[k].getY());
			const int highest_y = get_y_from_j(h);

			//printfDx("%s%d%s%d%s%d%s%d\n", "i : ", line, " h : ", h, " k : ", k ,  " y : ",fallingBlock[k].getY());

			//一番高いブロックの上端よりも落下中のブロックが下に来たらその上にブロックを置く
			if (fallingBlock[k].getY() + BLOCK_SIZE + 1 > highest_y)
			{
				landingBlock(k, h);
			}
		}
	}
}

std::vector<int> CPlayer::getRandomOrder(int length)
{
	//求める順列
	std::vector<int> order(length);

	//GetRand用に残ってる数字を手前に詰めた配列
	std::vector<int> table(length);

	//数字は一つずらす
	for (int i = 0; i < length; i++)
	{
		table[i] = i + 1;
	}

	for (int i = length - 1; i > 0; i--)
	{
		//0～iまでの乱数を得る
		int x = GetRand(i);

		//tableに対応した数をorderに入れる
		order[i] = table[x];
		//printfDx("%s%d%s%d\n", "order ", i, " : ", order[i]);

		//tableを手前に詰める
		for (int j = 0; j < i; j++)
		{
			//xより小さい部分はそのままにする
			//xより大きい部分を前に詰める
			if (j >= x)
			{
				table[j] = table[j + 1];
			}
		}
	}

	//最後は乱数を取得しないで入れる
	order[0] = table[0];

	return order;
}

//iの列においてyより下で一番上に存在するブロックの位置を取得する
//存在しなければ0を返す
int CPlayer::getHighestUnderBlock(int i, int fby)
{

	//yの高さより下のブロックから探す
	//yは上基準、blockは下基準なので引いて求める
	int j = (FIELD_H - 1) - (fby - field_upper) / (BLOCK_SIZE + 1);

	while (j > 0)
	{
		//今の位置にブロックが存在するならその位置を返す
		if (block[i][j].getColor() != ec_null)
		{
			break;
		}
		else
		{
			j--;
		}
	}
	return j;
}

//ブロックの列(左から何番目か)からx座標を得る
int CPlayer::get_x_from_i(int i)
{
	return  field_left + 1 + (i - 1) * (BLOCK_SIZE + 1);
}

//ブロックの行(高さ)からy座標を得る
int CPlayer::get_y_from_j(int j)
{
	//画面外の分の一段を引く
	return field_upper + (FIELD_H - 1 - j) * (BLOCK_SIZE + 1);
}


//ブロックが落下して地面についた時の処理
void CPlayer::landingBlock(int k, int j)
{
	const int CHAIN_TIME = 10;
	const int i = fallingBlock[k].getLine();

	//一番上(画面外)の段でなければ一つ上の段に置く
	//一番上の段なら落下中のブロックを消滅させる(一番上の段の上に落ちる仕様にするならエフェクトをつけるが現状発生しないはず)
	if (j < FIELD_H)
	{
		block[i][j + 1].setColor(fallingBlock[k].getColor());
		//連鎖数を持たせ、連鎖判定時間を設定する
		block[i][j + 1].setChain(fallingBlock[k].getChain());
		block[i][j + 1].setChainTime(CHAIN_TIME);
	}

	fallingBlock[k].init();
	//printfDx("%s%d%s%d\n", "landingBlock k : ", k, " j : ", j);
}

//上から落ちてくるブロックをn段落とす
//現状では一段のみ対応
void CPlayer::dropBlock(int n)
{
	for (int l = 0; l < n; l++)
	{
		//ブロックを生成する順序
		std::vector<int> order = getRandomOrder(FIELD_W);

		//ブロックのない一番上の座標に使用可能な色(置いても消えない色)を取得し、画面外に落下ブロックを作る
		//一番上の段にブロックを生成する
		for (int x = 0; x < FIELD_W; x++)
		{
			int i = order[x];

			//一番上の段にブロックが存在する時の処理
			if (resultField[i][FIELD_H - 1] != ec_null)
			{
				//スコアアタックモードでは一番上の段にブロックがあるならブロックを生成しない
				if (mode_flag == em_score_attack)
				{
					continue;
				}
			}

			//ブロックが存在しない段を探す
			const int j = getHighestResultBlock(i) + 1;

			/*printfDx("%s", "resultField ");
			for (int a = 1; a <= FIELD_W; a++)
			{
				printfDx("%d ", resultField[a][j]);
			}
			printfDx("\n");*/

			//それぞれの色に対し、配列の対応した番号に使用可能かどうかを持つ
			std::vector<bool> usable(color_n + 1);

			for (int k = 1; k <= color_n; k++)
			{
				usable[k] = true;
			}

			//周りのブロックと同じ色にならないようにする
			//後で置く部分を調べる意味はない

			//3つ以上同じ色が並ばないようにする
			//手前2つが同じ色ならその色を使用不可にする
			if (i > 2)
			{
				e_color color1 = resultField[i - 1][j];
				if (color1 > ec_null)
				{
					if (color1 == resultField[i - 2][j])
					{
						usable[(int)color1] = false;
						//printfDx("手前2つ\n");
					}
				}
			}

			//後ろ2つが同じ色ならその色を使用不可にする
			if (i < FIELD_W - 1)
			{
				e_color color1 = resultField[i + 1][j];
				if (color1 > ec_null)
				{
					if (color1 == resultField[i + 2][j])
					{
						usable[(int)color1] = false;
						//printfDx("後ろ2つ\n");
					}
				}
			}

			//前後2つが同じ色ならその色を使用不可にする
			if (i > 1 && i < FIELD_W)
			{
				e_color color1 = resultField[i - 1][j];
				if (color1 > ec_null)
				{
					if (color1 == resultField[i + 1][j])
					{
						usable[(int)color1] = false;
						//printfDx("前後\n");
					}
				}
			}

			//下2つと同じ色ならその色を使用不可にする
			if (j > 2)
			{
				e_color color1 = resultField[i][j - 1];
				if (color1 > ec_null)
				{
					if (color1 == resultField[i][j - 2])
					{
						usable[(int)color1] = false;
					}
				}
			}

			//ミス？落下先の何もないブロック(ec_null)をfalseにしているだけ
			//usable[(int)block[i][j].getColor()] = false;

			//使用可能な色の数
			int usable_n = 0;
			for (int k = 1; k <= color_n; k++)
			{
				if (usable[k])
				{
					usable_n++;
				}
			}

			//使用可能な色を配列の手前に詰めて入れる
			std::vector<e_color> usableColor(usable_n);

			int m = 0;

			for (int k = 1; k <= color_n; k++)
			{
				if (usable[k])
				{
					usableColor[m++] = (e_color)k;
				}
			}

			e_color color = getRandomUsableColor(usableColor, usable_n);

			//落下後の仮のフィールドに生成したブロックを加える
			resultField[i][j] = color;

			//画面外からドロップさせる
			//2段以上出す場合上にずらす(2段以上落とすのは未実装)
			int y = G_W_UPPER - (3 + l) * (BLOCK_SIZE + 1);

			//列とy座標と色を与えて落下中のブロックを作る
			createFallingBlock2(i, y, color);
		}
	}
}

//中央4マスのみに一段落とす
void CPlayer::dropCenter()
{
	//ブロックを生成する順序
	std::vector<int> order = getRandomOrder(FIELD_W - 2);
	//2～5列目を用いるが、1～4で表されているためずらす
	for (int x = 0; x < FIELD_W - 2; x++)
	{
		order[x]++;
	}

	//ブロックのない一番上の座標に使用可能な色(置いても消えない色)を取得し、画面外に落下ブロックを作る
	//一番上の段にブロックを生成する
	for (int x = 0; x < FIELD_W - 2; x++)
	{
		int i = order[x];

		//ブロックが存在しない段を探す
		const int j = getHighestResultBlock(i) + 1;

		/*printfDx("%s", "resultField ");
		for (int a = 1; a <= FIELD_W; a++)
		{
		printfDx("%d ", resultField[a][j]);
		}
		printfDx("\n");*/

		//それぞれの色に対し、配列の対応した番号に使用可能かどうかを持つ
		std::vector<bool> usable(color_n + 1);

		for (int k = 1; k <= color_n; k++)
		{
			usable[k] = true;
		}

		//周りのブロックと同じ色にならないようにする
		//後で置く部分を調べる意味はない

		//3つ以上同じ色が並ばないようにする
		//手前2つが同じ色ならその色を使用不可にする
		if (i > 2)
		{
			e_color color1 = resultField[i - 1][j];
			if (color1 > ec_null)
			{
				if (color1 == resultField[i - 2][j])
				{
					usable[(int)color1] = false;
					//printfDx("手前2つ\n");
				}
			}
		}

		//後ろ2つが同じ色ならその色を使用不可にする
		if (i < FIELD_W - 1)
		{
			e_color color1 = resultField[i + 1][j];
			if (color1 > ec_null)
			{
				if (color1 == resultField[i + 2][j])
				{
					usable[(int)color1] = false;
					//printfDx("後ろ2つ\n");
				}
			}
		}

		//前後2つが同じ色ならその色を使用不可にする
		if (i > 1 && i < FIELD_W)
		{
			e_color color1 = resultField[i - 1][j];
			if (color1 > ec_null)
			{
				if (color1 == resultField[i + 1][j])
				{
					usable[(int)color1] = false;
					//printfDx("前後\n");
				}
			}
		}

		//下2つと同じ色ならその色を使用不可にする
		if (j > 2)
		{
			e_color color1 = resultField[i][j - 1];
			if (color1 > ec_null)
			{
				if (color1 == resultField[i][j - 2])
				{
					usable[(int)color1] = false;
				}
			}
		}

		//ミス？落下先の何もないブロック(ec_null)をfalseにしているだけ
		//usable[(int)block[i][j].getColor()] = false;

		//使用可能な色の数
		int usable_n = 0;
		for (int k = 1; k <= color_n; k++)
		{
			if (usable[k])
			{
				usable_n++;
			}
		}

		//使用可能な色を配列の手前に詰めて入れる
		std::vector<e_color> usableColor(usable_n);

		int m = 0;

		for (int k = 1; k <= color_n; k++)
		{
			if (usable[k])
			{
				usableColor[m++] = (e_color)k;
			}
		}

		e_color color = getRandomUsableColor(usableColor, usable_n);

		//落下後の仮のフィールドに生成したブロックを加える
		resultField[i][j] = color;

		//画面外からドロップさせる
		//2段以上出す場合上にずらす(2段以上落とすのは未実装)
		int y = G_W_UPPER - 3 * (BLOCK_SIZE + 1);

		//列とy座標と色を与えて落下中のブロックを作る
		createFallingBlock2(i, y, color);
	}
}

void CPlayer::dropWhite()
{
	//ブロックを生成する順序
	int order[FIELD_W + 1];

	//引数の列のブロックの最大の高さ
	int height[FIELD_W + 1];

	bool used[FIELD_W + 1];

	for (int i = 1; i <= FIELD_W; i++)
	{
		height[i] = getHighestResultBlock(i);
		used[i] = false;
	}

	//低い順に順序を選ぶ
	//列が少なくて時間がかからないので適当なアルゴリズム
	for (int i = 1; i <= FIELD_W; i++)
	{
		//使用されていないものから一番低い物を選んでいく
		int lowest = INT_MAX;
		int lowestLine = -1;
		for (int j = 1; j <= FIELD_W; j++)
		{
			if (!used[j])
			{
				if (height[j] < lowest)
				{
					lowest = height[j];
					lowestLine = j;
				}
			}
		}
		order[i] = lowestLine;
		used[lowestLine] = true;
	}

	//列の回数だけ最大行う
	for (int i = 1; i <= FIELD_W; i++)
	{
		const int line = order[i];

		//落とすブロックがなくなったら終わりにする
		if (dropNotice == 0)
		{
			break;
		}

		//画面外からドロップさせる
		//2段以上出す場合上にずらす(2段以上落とすのは未実装)
		int y = G_W_UPPER - 3 * (BLOCK_SIZE + 1);

		//列とy座標と色を与えて落下中のブロックを作る
		createFallingBlock2(line, y, ec_white);

		dropNotice--;
	}
}

//落下中のブロックを新たに作り、その配列の添え字を返す
int CPlayer::createFallingBlock(int i, int j, e_color color)
{
	return createFallingBlock2(i, G_W_UPPER + (FIELD_H - j - 1) * (BLOCK_SIZE + 1), color);
}

//落下中のブロックを新たに作り、その配列の添え字を返す
//こちらではy座標を直接与える
int CPlayer::createFallingBlock2(int i, int y, e_color color)
{
	for (int k = 0; k < FIELD_H * FIELD_W; k++)
	{
		if (fallingBlock[k].getColor() == ec_null)
		{
			fallingBlock[k].setLine(i);
			fallingBlock[k].setY(y);
			fallingBlock[k].setColor(color);
			return k;
		}
	}
	return -1;
}

//空中にある全ブロックの落下後のフィールドに存在する一番上のブロックを求める
//画面外に到達していた場合、上手く処理されないので必要なら直す
//getHighestBlockと仕様を揃えている
int CPlayer::getHighestResultBlock(int i)
{
	int j = 0;
	while (j + 1 < FIELD_H)
	{
		//ブロックが存在しないならブロックの位置を取得する
		if (resultField[i][j + 1] == ec_null)
		{
			break;
		}
		else
		{
			j++;
		}
	}
	return j;
}

//落下中のブロックをy座標で昇順にソートする
void CPlayer::quickSort(CFallingBlock f[], int n)
{
	quickSort(f, 0, n - 1);
}

void CPlayer::quickSort(CFallingBlock f[], int low, int high)
{

	if (high <= low)//*最初に左端にあった数の移動後の位置より左が並べ替え終わったら
		return;
	const int y = f[low].getY();   //*判定したい数（調べる範囲の左端の数）をxに代入する
	const int m = partition(f, low, high, y);
	quickSort(f, low, m);    //求めた位置から左側に判定する数より小さい数を並べる
	quickSort(f, m + 1, high); //求めた位置から右側に判定する数より大きい数を並べる
}

//判定する数がどの位置に来るかを求める
int CPlayer::partition(CFallingBlock f[], int low, int high, int y)
{

	//配列の要素数を記憶する
	int n = high - low + 1;
	std::vector<CFallingBlock> b(high - low + 1);

	//smallはdefineされているので名前を変える
	int small2 = 0;
	int equal = 0;

	for (int i = 0; i < n; i++)
	{
		b[i] = f[low + i];
		if (b[i].getY() < y)
		{
			small2++;
		}
		if (b[i].getY() == y)
		{
			equal++;
		}
	}

	int j = low;
	int k = low + small2;
	int h = low + small2 + equal;
	for (int i = 0; i < n; i++)
	{
		if (b[i].getY() < y)
		{
			f[j++] = b[i];
		}
		else if (b[i].getY() == y)
		{
			f[k++] = b[i];

		}
		else {
			f[h++] = b[i];
		}
	}

	if (low + small2 < high)
	{
		return low + small2;
	}
	else
	{
		return low + small2 - 1;
	}
}
