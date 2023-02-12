#include"DxLib.h"
#include"extern.h"
#include"function.h"
#include"math.h"

//ゲームプレイ中の描画
//背景→ブロック→カーソルの順に描画する
void drawPlay()
{
	
	if (mode_flag == em_score_attack)
	{
		//外枠
		DrawGraph(0, 0, img.frame, TRUE);

		//背景の描画
		drawBackGround(player1);

		//ブロックの描画
		drawFieldBlock(player1);

		//カーソルの描画
		drawCursor(player1);

		//ゲームプレイ中の画面外の描画
		drawPlayWindow();
	}
	else if (mode_flag == em_vs)
	{
		//外枠
		DrawGraph(0, 0, img.frame, TRUE);

		//背景の描画
		drawBackGround(player1);
		drawBackGround(player2);

		//ブロックの描画
		drawFieldBlock(player1);
		drawFieldBlock(player2);

		//カーソルの描画
		drawCursor(player1);
		drawCursor(player2);

		//ゲームプレイ中の画面外の描画
		drawVsWindow();
	}
}

//引数の色に対応したブロックの画像を返す
int getBlockImg(const e_color color)
{
	switch (color)
	{
	case ec_white: return img.whiteblock;
	case ec_blue: return img.blueblock;
	case ec_red: return img.redblock;
	case ec_green: return img.greenblock;
	case ec_yellow: return img.yellowblock;
	case ec_purple: return img.purpleblock;
	default: return -1;
	}
}

//引数の色に対応したカーソルの画像を返す
int getCursorImg(const e_color color)
{
	switch (color)
	{
	case ec_blue: return img.blueCursor;
	case ec_red: return img.redCursor;
	case ec_green: return img.greenCursor;
	case ec_yellow: return img.yellowCursor;
	case ec_purple: return img.purpleCursor;
	default: return -1;
	}
}

//フィールド上のブロックの描画
void drawFieldBlock(CPlayer player)
{
	for (int j = 1; j <= FIELD_H; j++)
	{
		for (int i = 1; i <= FIELD_W; i++)
		{
			const int x = player.get_x_from_i(i);
			const int y = player.get_y_from_j(j);
			CBlock block = player.getBlock(i, j);
			//消滅中のブロックは点滅させる
			if (block.getVanishCount() % 8 < 5 && block.getVanishCount() > 0)
			{
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 64);
			}
			DrawGraph(x, y, getBlockImg(player.getBlock(i, j).getColor()), TRUE);
			if (block.getVanishCount() % 8 < 5 && block.getVanishCount() > 0)
			{
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			}

			//消滅中のブロックに連鎖数を表示する
			//加算されているのは消滅したブロックの上側のみなので+1して表示する
			if (mode_flag == em_vs)
			{
				if (block.getVanishCount() > 0)
				{
					DrawFormatStringToHandle(x + 10, y + 10, font.getBlack(), font.getFont(6), "%d", block.getChain() + 1);
				}
			}

			//DrawFormatStringToHandle(x + 20, y + 20, font.getBlack(), font.getFont(0), "%d", block.getChain());
		}
	}

	//落下中のブロックの描画
	for (int k = 0; k <= FIELD_W * FIELD_H; k++)
	{
		if (player.getFallingBlock(k).getColor() != ec_null)
		{
			const int i = player.getFallingBlock(k).getLine();
			const e_color color = player.getFallingBlock(k).getColor();
			const int x = player.getFieldLeft() + 1 + (i - 1) * (BLOCK_SIZE + 1);	//40 + 247 + 1 = 288	40以上286以下
			const int y = player.getFallingBlock(k).getY();
			DrawGraph(x, y, getBlockImg(color), TRUE);
		}
	}

	//ブロックを塗った時のエフェクトの描画
	for (int j = 1; j <= FIELD_H; j++)
	{
		for (int i = 1; i <= FIELD_W; i++)
		{
			const int x = player.get_x_from_i(i);
			const int y = player.get_y_from_j(j);
			CBlock *block = player1.getBlock2(i, j);
			if (player.getP() == e_1p) {
				block = player1.getBlock2(i, j);
			}
			else if(player.getP() == e_2p){
				block = player2.getBlock2(i, j);
			}

			int count = (*block).getDrawEffectCount();
			if (count > 0)
			{
				int *effect = img.BlueBalletVanish;
				e_color drawColor = (*block).getDrawColor();

				//色によってエフェクトの色を変える
				//色を増やしたらここも増やす
				switch (drawColor)
				{
				case ec_blue: effect = img.BlueBalletVanish; break;
				case ec_red: effect = img.RedBalletVanish; break;
				case ec_yellow: effect = img.YellowBalletVanish; break;
				case ec_green: effect = img.GreenBalletVanish; break;
				default: break;
				}
				DrawExtendGraph(x - 4, y - 4, x + BLOCK_SIZE + 4, y + BLOCK_SIZE + 4, effect[DRAW_EFFECT_TIME - count], TRUE);
				//DrawGraph(x, y, img.BlueBalletVanish[DRAW_EFFECT_TIME - (*block).getDrawEffectCount()], TRUE);
				//DrawRotaGraph(x, y, 1, 0, img.BlueBalletVanish[10], TRUE);

				//塗るエフェクトが半分経過したら実際に塗る
				if (count == DRAW_EFFECT_TIME / 2) {
					(*block).setColor(drawColor);
					(*block).setDrawColor(ec_null);
				}

				(*block).decrementDrawEffectCount();
			}
		}
	}

	//画面外の敗北判定の描画
	for (int i = 1; i <= FIELD_W; i++)
	{
		if (player.getLoseCount(i) > 0)
		{
			const int x = player.get_x_from_i(i);
			const int y = player.get_y_from_j(FIELD_H);
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 * player.getLoseCount(i) / LOSE_LIMIT);
			DrawGraph(x, y, img.cross, TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
	}
}

//背景の描画
void drawBackGround(CPlayer player)
{
	//一番上の段は画面外なので表示しない
	for (int j = 1; j <= FIELD_H - 1; j++)
	{
		for (int i = 1; i <= FIELD_W; i++)
		{
			//通常のブロックより1ずつ左上となる
			const int x = player.get_x_from_i(i) - 1;
			const int y = player.get_y_from_j(j) - 1;
			DrawGraph(x, y, img.backBlock, TRUE);
		}
	}
}	

//カーソルの描画
void drawCursor(CPlayer player)
{
	const int x1 = player.getFieldLeft() + (player.getX() - 1) * (BLOCK_SIZE + 1);
	const int x2 = player.getFieldLeft() + (player.getX()) * (BLOCK_SIZE + 1);
	const int y1 = player.getFieldLower() - player.getY() * (BLOCK_SIZE + 1) - 1;
	const int nextColor0 = getCursorImg(player.getNextBlock(0).getColor());
	DrawGraph(x1, y1, nextColor0, TRUE);
	DrawGraph(x2, y1, nextColor0, TRUE);
}
