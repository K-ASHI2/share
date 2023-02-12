#include"DxLib.h"
#include"extern.h"
#include"function.h"
#include"SearchField.h"
#include <queue>
#include"math.h"

const static int MOVE_WAIT = 11;

//プレイヤーの移動
void CPlayer::movePlayer()
{

	//時間経過による待ち時間の減少
	if (t > 0)
	{
		t--;
	}

	if (shot_t > 0)
	{
		shot_t--;
	}

	//プレイヤーが操作するモード
	if (cpuMove == ec_player)
	{
		//cpu対戦時
		if (player2.cpuMove != ec_player || mode_flag == em_score_attack)
		{
			if (t == 0)
			{
				//同時押しされた時の制御
				int k = 0;
				if (keyPad.getButton(KEY_RIGHT) > 0)
				{
					rightMove();
					k++;
				}

				if (keyPad.getButton(KEY_LEFT) > 0)
				{
					leftMove();
					//左右同時押し時は入力待ちをしない(高速に左右に入力すると同時入力される可能性があるため)
					if (k != 0)
					{
						t = 0;
					}
					else
					{
						k++;
					}
				}
				//縦横同時に押されたら縦には動かさない
				if (k == 0) {
					if (keyPad.getButton(KEY_UP) > 0)
					{
						upMove();
						k++;
					}
					if (keyPad.getButton(KEY_DOWN) > 0)
					{
						downMove();
						//上下同時押し時も入力待ちをしない
						if (k != 0)
						{
							t = 0;
						}
					}
				}
			}

			//ブロックの射出
			if (keyPad.getButton(KEY_SHOT) == 1)
			{
				blockShot();
			}

			//ボタンを押すと次のブロックがすぐに落下してくるようにする
			if (keyPad.getButton(KEY_CANCEL) == 1 && dropCount > 10 && dropNotice == 0)
			{
				dropCount = dropInterval;
			}
		}
		else {
			if (p == e_1p)
			{
				if (t == 0)
				{
					//同時押しされた時の制御
					int k = 0;
					if (keyPad.getButton1P(KEY_RIGHT) > 0)
					{
						rightMove();
						k++;
					}

					if (keyPad.getButton1P(KEY_LEFT) > 0)
					{
						leftMove();
						//左右同時押し時は入力待ちをしない(高速に左右に入力すると同時入力される可能性があるため)
						if (k != 0)
						{
							t = 0;
						}
						else
						{
							k++;
						}
					}
					//縦横同時に押されたら縦には動かさない
					if (k == 0) {
						if (keyPad.getButton1P(KEY_UP) > 0)
						{
							upMove();
							k++;
						}
						if (keyPad.getButton1P(KEY_DOWN) > 0)
						{
							downMove();
							//上下同時押し時も入力待ちをしない
							if (k != 0)
							{
								t = 0;
							}
						}
					}
				}
				//ブロックの射出
				if (keyPad.getButton1P(KEY_SHOT) == 1)
				{
					blockShot();
				}

				//ボタンを押すと次のブロックがすぐに落下してくるようにする
				if (keyPad.getButton1P(KEY_CANCEL) == 1 && dropCount > 10 && dropNotice == 0)
				{
					dropCount = dropInterval;
				}
			}
			else if (p == e_2p)
			{
				if (t == 0)
				{
					//同時押しされた時の制御
					int k = 0;
					if (keyPad.getButton2P(KEY_RIGHT) > 0)
					{
						rightMove();
						k++;
					}

					if (keyPad.getButton2P(KEY_LEFT) > 0)
					{
						leftMove();
						//左右同時押し時は入力待ちをしない(高速に左右に入力すると同時入力される可能性があるため)
						if (k != 0)
						{
							t = 0;
						}
						else
						{
							k++;
						}
					}
					//縦横同時に押されたら縦には動かさない
					if (k == 0) {
						if (keyPad.getButton2P(KEY_UP) > 0)
						{
							upMove();
							k++;
						}
						if (keyPad.getButton2P(KEY_DOWN) > 0)
						{
							downMove();
							//上下同時押し時も入力待ちをしない
							if (k != 0)
							{
								t = 0;
							}
						}
					}
				}
				//ブロックの射出
				if (keyPad.getButton2P(KEY_SHOT) == 1)
				{
					blockShot();
				}

				//ボタンを押すと次のブロックがすぐに落下してくるようにする
				if (keyPad.getButton2P(KEY_CANCEL) == 1 && dropCount > 10 && dropNotice == 0)
				{
					dropCount = dropInterval;
				}
			}
		}

	}
	else {
		moveCpu();
	}

	//デバッグ用
	/*if (button[KEY_BOMB] == 1 && player1.shot_t == 0) {
		fieldClear();
	}*/
}

//cpuの動きのアルゴリズム
void CPlayer::moveCpu()
{
	//ランダムに操作するcpuが操作するモード
	if (cpuMove == ec_random)
	{
		//移動可能な時のみ行う
		if (t == 0)
		{
			//向きをランダムに取得する、4なら動かないが動かない利点がないので3以下
			int d = GetRand(3);

			switch (d) {
			case ed_up:
				upMove();
				break;
			case ed_right:
				rightMove();
				break;
			case ed_down:
				downMove();
				break;
			case ed_left:
				leftMove();
				break;
			case 4:
				t = MOVE_WAIT;
				break;
			}
		}

		if (shot_t == 0)
		{
			int p = GetRand(99) + 1;
			//50%の確率で塗る
			if (p <= 80)
			{
				blockShot();
			}
			//waitを付けないと毎フレーム塗ろうとするので実質100%
			//移動したらもう一度判定する
			else
			{
				shot_t = MOVE_WAIT;
			}
		}
	}
	//動きはランダムだが、塗れる場所のみ塗る
	else if (cpuMove == ec_move_random)
	{
		//移動可能な時のみ行う
		if (t == 0)
		{
			//向きをランダムに取得する
			int d = GetRand(4);

			switch (d) {
			case ed_up:
				upMove();
				break;
			case ed_right:
				rightMove();
				break;
			case ed_down:
				downMove();
				break;
			case ed_left:
				leftMove();
				break;
			case ed_noMove:
				break;
			}
		}

		if (shot_t == 0)
		{
			//塗ったら消える時だけ塗る
			if (shotVanishCheckTwin(x, y))
			{
				blockShot();
			}
		}
	}

	//一番近くの消える場所を探索する
	//コンボがつながりやすいが、高い列を放置するので運が悪いと簡単に負ける
	else if (cpuMove == ec_search)
	{
		//移動可能な時のみ行う
		if (t == 0)
		{
			CSearchField sf = targetSearch(6);
			//探索時に最初に移動した方向に進む
			switch (sf.get_fd()) {
			case ed_up:
				upMove();
				break;
			case ed_right:
				rightMove();
				break;
			case ed_down:
				downMove();
				break;
			case ed_left:
				leftMove();
				break;
			case ed_noMove:
				blockShot();
				break;
			case ed_null:
				//一番近い塗れるマスを探す
				CSearchField sf2 = drawableSearch(15);
				switch (sf2.get_fd()) {
				case ed_up:
					upMove();
					break;
				case ed_right:
					rightMove();
					break;
				case ed_down:
					downMove();
					break;
				case ed_left:
					leftMove();
					break;
				case ed_noMove:
					blockShot();
					break;
				case ed_null:
					//揃う場所が無ければその場を撃つ
					blockShot();
					break;
				}
			}
		}
	}

	else if (cpuMove == ec_strong)
	{

	}
}

//ブロックの射出(塗る)
void CPlayer::blockShot()
{
	//const static int SHOT_WAIT = 25;
	const static int SHOT_WAIT = 20;

	if (shot_t == 0)
	{
		//カーソルの位置の色を塗る(色を変える)
		const bool shot = changeBlockColor(x, y, nextBlock[0].getColor());

		//色を変えた時のみ行う
		if (shot)
		{
			//NEXTをずらす
			for (int i = 0; i < NEXT_N - 1; i++)
			{
				nextBlock[i].setColor(nextBlock[i + 1].getColor());
			}

			e_color nextColor = ec_null;

			//5回以上連続で出ていない色があれば出す
			//初回のみ2色以上同時に発生するが修正してないので少しだけ偏る
			for (int i = 1; i <= color_n; i++)
			{
				if (notAppearCount[i] >= 5)
				{
					nextColor = (e_color)i;
					break;
				}
			}

			//なければランダムに取得
			if (nextColor == ec_null)
			{
				nextColor = (e_color)(GetRand(color_n - 1) + 1);
			}

			//NEXTの最後尾の色を設定する
			nextBlock[NEXT_N - 1].setColor(nextColor);

			notAppearCount[nextColor] = 0;

			for (int i = 1; i <= color_n; i++)
			{
				if (i != nextColor)
				{
					notAppearCount[i]++;
				}
			}

			//すぐには次の色を塗れなくする
			shot_t = SHOT_WAIT + GetRand(thinkingTime);

			music.efs(efs_draw);
		}

	}
}

//引数の座標のブロックに引数の色を付ける
bool CPlayer::changeBlockColor(int x, int y, e_color color)
{
	//どちらも塗らなかったらfalseを返し、nextはそのまま
	bool drawFlag = false;

	//ブロックが存在していて、消滅中でなく塗っている途中でもないなら色を付ける
	//2マスのうち片方でも塗れるなら塗る
	if (block[x][y].getColor() != ec_null && !block[x][y].getVanishFlag() && block[x][y].getVanishCount() == 0)
	{
		block[x][y].setDrawEffectCount(DRAW_EFFECT_TIME);
		block[x][y].setDrawColor(color);

		drawFlag = true;

		//色を塗るエフェクトの途中で変化させる仕様に変更する
		//block[x][y].setColor(color);
		//return true;
	}

	if (block[x + 1][y].getColor() != ec_null && !block[x + 1][y].getVanishFlag() && block[x + 1][y].getVanishCount() == 0)
	{
		block[x + 1][y].setDrawEffectCount(DRAW_EFFECT_TIME);
		block[x + 1][y].setDrawColor(color);
		drawFlag = true;
	}

	return drawFlag;
}

//塗るべきブロックの座標を返す
//range:カーソルの座標から探索するマス目の距離の最大値
CSearchField CPlayer::targetSearch(int range)
{
	//カーソルの位置の座標のフィールドを作る
	CSearchField sf0(x, y, ed_noMove, 0);

	//今いる場所が塗れば消えるマスなら返す
	if (shotVanishCheckTwin(x, y))
	{
		return sf0;
	}

	//座標などの情報を持ったフィールドを入れるキュー
	std::queue<CSearchField> qsf;
	qsf.push(sf0);

	//探索済みのマスかどうか
	bool searched[FIELD_W + 1][FIELD_H - 1 + 1];
	for (int j = 1; j <= FIELD_H - 1; j++)
	{
		//右端は除く
		for (int i = 1; i <= FIELD_W - 1; i++)
		{
			searched[i][j] = false;
		}
	}

	//初期座標は探索済み
	searched[x][y] = true;

	//キューの中身が存在する間行う
	while (!qsf.empty())
	{
		CSearchField sf = qsf.front();
		qsf.pop();
		int count = sf.getCount();

		int fx = sf.getX();
		int fy = sf.getY();

		//右端はスキップする(キューに入ってしまっている)
		if (fx == 6) {
			continue;
		}

		//周囲4マスを探索する
		for (int i = 0; i < 4; i++)
		{
			CBlock cb = field[fx][fy].getNeighborBlock(i);
			int cbx = cb.getX();
			int cby = cb.getY();

			//すでに探索済み(キューに入れた)のマスは飛ばす
			//画面端の場合もそのマス自身が返ってきて探索済みなので飛ぶ
			if (searched[cbx][cby])
			{
				continue;
			}

			//最初に移動した向きを取得する
			//まだ移動して探索していないなら現在の向きを入れる
			e_direction fd = sf.get_fd();
			if (fd == ed_noMove)
			{
				fd = (e_direction)i;
			}

			//塗れば消えるマスを見つけたら記憶する
			if (shotVanishCheckTwin(cbx, cby))
			{
				CSearchField result_sf(cbx, cby, fd, count + 1);
				return result_sf;
			}

			//探索マス数が残っているならキューに追加する
			if (count < range)
			{
				CSearchField sf1(cbx, cby, fd, count + 1);
				qsf.push(sf1);
				searched[cbx][cby] = true;
			}
		}
	}

	//最後まで見つからなかったらnullのフィールドを返す
	CSearchField sf1(x, y, ed_null, 0);

	//最初の座標が塗れないマスの場合一番近い塗れるマスを探す
	if (!drawableCheck(x, y))
	{

	}

	return sf1;
}

////塗った時2マス揃うマスを探す
//CSearchField CPlayer::alignSearch(int range)
//{
//
//	//カーソルの位置の座標のフィールドを作る
//	CSearchField sf0(x, y, ed_noMove, 0);
//
//	//今いる場所が塗った時2マス揃うマスで、まだ2マス揃っていないマスなら返す
//	if (shotAlignCheck(x, y) && !alignCheck(x, y))
//	{
//		return sf0;
//	}
//
//	//座標などの情報を持ったフィールドを入れるキュー
//	std::queue<CSearchField> qsf;
//	qsf.push(sf0);
//
//	//探索済みのマスかどうか
//	bool searched[FIELD_W + 1][FIELD_H - 1 + 1];
//	for (int j = 1; j <= FIELD_H - 1; j++)
//	{
//		for (int i = 1; i <= FIELD_W; i++)
//		{
//			searched[i][j] = false;
//		}
//	}
//	//初期座標は探索済み
//	searched[x][y] = true;
//
//	//キューの中身が存在する間行う
//	while (!qsf.empty())
//	{
//		CSearchField sf = qsf.front();
//		qsf.pop();
//		int count = sf.getCount();
//
//		int fx = sf.getX();
//		int fy = sf.getY();
//
//		//周囲4マスを探索する
//		for (int i = 0; i < 4; i++)
//		{
//			CBlock cb = field[fx][fy].getNeighborBlock(i);
//			int cbx = cb.getX();
//			int cby = cb.getY();
//
//			//すでに探索済み(キューに入れた)のマスは飛ばす
//			//画面端の場合もそのマス自身が返ってきて探索済みなので飛ぶ
//			if (searched[cbx][cby])
//			{
//				continue;
//			}
//
//			//最初に移動した向きを取得する
//			//まだ移動して探索していないなら現在の向きを入れる
//			e_direction fd = sf.get_fd();
//			if (fd == ed_noMove)
//			{
//				fd = (e_direction)i;
//			}
//
//			//塗れば2マス揃い、まだ2マス揃っていないマスを見つけたら記憶する
//			if (shotAlignCheck(cbx, cby) && !alignCheck(cbx, cby))
//			{
//				CSearchField result_sf(cbx, cby, fd, count + 1);
//				return result_sf;
//			}
//
//			//探索マス数が残っているならキューに追加する
//			if (count < range)
//			{
//				CSearchField sf1(cbx, cby, fd, count + 1);
//				qsf.push(sf1);
//				searched[cbx][cby] = true;
//			}
//		}
//	}
//	//最後まで見つからなかったらnullのフィールドを返す
//	CSearchField sf1(x, y, ed_null, 0);
//	return sf1;
//}

//塗っても2マス揃ってる状態を崩さないマスを返す
//CSearchField CPlayer::noAlignSearch(int range)
//{
//	//カーソルの位置の座標のフィールドを作る
//	CSearchField sf0(x, y, ed_noMove, 0);
//
//	//今いる場所が2マス揃っていないマスなら返す
//	if (!alignCheck(x, y))
//	{
//		return sf0;
//	}
//
//	//座標などの情報を持ったフィールドを入れるキュー
//	std::queue<CSearchField> qsf;
//	qsf.push(sf0);
//
//	//探索済みのマスかどうか
//	bool searched[FIELD_W + 1][FIELD_H - 1 + 1];
//	for (int j = 1; j <= FIELD_H - 1; j++)
//	{
//		for (int i = 1; i <= FIELD_W; i++)
//		{
//			searched[i][j] = false;
//		}
//	}
//	//初期座標は探索済み
//	searched[x][y] = true;
//
//	//キューの中身が存在する間行う
//	while (!qsf.empty())
//	{
//		CSearchField sf = qsf.front();
//		qsf.pop();
//		int count = sf.getCount();
//
//		int fx = sf.getX();
//		int fy = sf.getY();
//
//		//周囲4マスを探索する
//		for (int i = 0; i < 4; i++)
//		{
//			CBlock cb = field[fx][fy].getNeighborBlock(i);
//			int cbx = cb.getX();
//			int cby = cb.getY();
//
//			//すでに探索済み(キューに入れた)のマスは飛ばす
//			//画面端の場合もそのマス自身が返ってきて探索済みなので飛ぶ
//			if (searched[cbx][cby])
//			{
//				continue;
//			}
//
//			//最初に移動した向きを取得する
//			//まだ移動して探索していないなら現在の向きを入れる
//			e_direction fd = sf.get_fd();
//			if (fd == ed_noMove)
//			{
//				fd = (e_direction)i;
//			}
//
//			//2マス揃っていないマスを見つけたら記憶する
//			if (!alignCheck(cbx, cby))
//			{
//				CSearchField result_sf(cbx, cby, fd, count + 1);
//				return result_sf;
//			}
//
//			//探索マス数が残っているならキューに追加する
//			if (count < range)
//			{
//				CSearchField sf1(cbx, cby, fd, count + 1);
//				qsf.push(sf1);
//				searched[cbx][cby] = true;
//			}
//		}
//	}
//	//最後まで見つからなかったらnullのフィールドを返す
//	CSearchField sf1(x, y, ed_null, 0);
//	return sf1;
//}

//塗れるマスを探す
CSearchField CPlayer::drawableSearch(int range)
{
	//カーソルの位置の座標のフィールドを作る
	CSearchField sf0(x, y, ed_noMove, 0);

	//今いる場所が塗れるマスなら返す
	if (drawableCheckTwin(x, y))
	{
		return sf0;
	}

	//座標などの情報を持ったフィールドを入れるキュー
	std::queue<CSearchField> qsf;
	qsf.push(sf0);

	//探索済みのマスかどうか
	bool searched[FIELD_W + 1][FIELD_H - 1 + 1];
	for (int j = 1; j <= FIELD_H - 1; j++)
	{
		//カーソルの動ける範囲のみで良いので右端は無し
		for (int i = 1; i <= FIELD_W - 1; i++)
		{
			searched[i][j] = false;
		}
	}
	//初期座標は探索済み
	searched[x][y] = true;

	//キューの中身が存在する間行う
	while (!qsf.empty())
	{
		CSearchField sf = qsf.front();
		qsf.pop();
		int count = sf.getCount();

		int fx = sf.getX();
		int fy = sf.getY();

		//右端はスキップする(キューに入ってしまっている)
		if (fx == 6) {
			continue;
		}

		//周囲4マスを探索する
		for (int i = 0; i < 4; i++)
		{
			CBlock cb = field[fx][fy].getNeighborBlock(i);
			int cbx = cb.getX();
			int cby = cb.getY();

			//すでに探索済み(キューに入れた)のマスは飛ばす
			//画面端の場合もそのマス自身が返ってきて探索済みなので飛ぶ
			if (searched[cbx][cby])
			{
				continue;
			}

			//最初に移動した向きを取得する
			//まだ移動して探索していないなら現在の向きを入れる
			e_direction fd = sf.get_fd();
			if (fd == ed_noMove)
			{
				fd = (e_direction)i;
			}

			//2マス揃っていないマスを見つけたら返す
			if (drawableCheckTwin(cbx, cby))
			{
				CSearchField result_sf(cbx, cby, fd, count + 1);
				return result_sf;
			}

			//探索マス数が残っているならキューに追加する
			if (count < range)
			{
				CSearchField sf1(cbx, cby, fd, count + 1);
				qsf.push(sf1);
				searched[cbx][cby] = true;
			}
		}
	}
	//最後まで見つからなかったらnullのフィールドを返す
	CSearchField sf1(x, y, ed_null, 0);
	return sf1;
}

void CPlayer::upMove()
{
	//画面外の一列は含まない
	if (y < FIELD_H - 1)
	{
		y++;
		t = MOVE_WAIT + GetRand(thinkingTime);
	}
}

void CPlayer::downMove()
{
	if (y > 1)
	{
		y--;
		t = MOVE_WAIT + GetRand(thinkingTime);
	}
}

void CPlayer::leftMove()
{
	if (x > 1)
	{
		x--;
		t = MOVE_WAIT + GetRand(thinkingTime);
	}
}

void CPlayer::rightMove()
{
	if (x < FIELD_W - 1)
	{
		x++;
		t = MOVE_WAIT + GetRand(thinkingTime);
	}
}
