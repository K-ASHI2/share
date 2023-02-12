#include"DxLib.h"
#include"extern.h"
#include"function.h"
#include"math.h"

//�Q�[���v���C���̕`��
//�w�i���u���b�N���J�[�\���̏��ɕ`�悷��
void drawPlay()
{
	
	if (mode_flag == em_score_attack)
	{
		//�O�g
		DrawGraph(0, 0, img.frame, TRUE);

		//�w�i�̕`��
		drawBackGround(player1);

		//�u���b�N�̕`��
		drawFieldBlock(player1);

		//�J�[�\���̕`��
		drawCursor(player1);

		//�Q�[���v���C���̉�ʊO�̕`��
		drawPlayWindow();
	}
	else if (mode_flag == em_vs)
	{
		//�O�g
		DrawGraph(0, 0, img.frame, TRUE);

		//�w�i�̕`��
		drawBackGround(player1);
		drawBackGround(player2);

		//�u���b�N�̕`��
		drawFieldBlock(player1);
		drawFieldBlock(player2);

		//�J�[�\���̕`��
		drawCursor(player1);
		drawCursor(player2);

		//�Q�[���v���C���̉�ʊO�̕`��
		drawVsWindow();
	}
}

//�����̐F�ɑΉ������u���b�N�̉摜��Ԃ�
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

//�����̐F�ɑΉ������J�[�\���̉摜��Ԃ�
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

//�t�B�[���h��̃u���b�N�̕`��
void drawFieldBlock(CPlayer player)
{
	for (int j = 1; j <= FIELD_H; j++)
	{
		for (int i = 1; i <= FIELD_W; i++)
		{
			const int x = player.get_x_from_i(i);
			const int y = player.get_y_from_j(j);
			CBlock block = player.getBlock(i, j);
			//���Œ��̃u���b�N�͓_�ł�����
			if (block.getVanishCount() % 8 < 5 && block.getVanishCount() > 0)
			{
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 64);
			}
			DrawGraph(x, y, getBlockImg(player.getBlock(i, j).getColor()), TRUE);
			if (block.getVanishCount() % 8 < 5 && block.getVanishCount() > 0)
			{
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			}

			//���Œ��̃u���b�N�ɘA������\������
			//���Z����Ă���̂͏��ł����u���b�N�̏㑤�݂̂Ȃ̂�+1���ĕ\������
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

	//�������̃u���b�N�̕`��
	for (int k = 0; k <= FIELD_W * FIELD_H; k++)
	{
		if (player.getFallingBlock(k).getColor() != ec_null)
		{
			const int i = player.getFallingBlock(k).getLine();
			const e_color color = player.getFallingBlock(k).getColor();
			const int x = player.getFieldLeft() + 1 + (i - 1) * (BLOCK_SIZE + 1);	//40 + 247 + 1 = 288	40�ȏ�286�ȉ�
			const int y = player.getFallingBlock(k).getY();
			DrawGraph(x, y, getBlockImg(color), TRUE);
		}
	}

	//�u���b�N��h�������̃G�t�F�N�g�̕`��
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

				//�F�ɂ���ăG�t�F�N�g�̐F��ς���
				//�F�𑝂₵���炱�������₷
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

				//�h��G�t�F�N�g�������o�߂�������ۂɓh��
				if (count == DRAW_EFFECT_TIME / 2) {
					(*block).setColor(drawColor);
					(*block).setDrawColor(ec_null);
				}

				(*block).decrementDrawEffectCount();
			}
		}
	}

	//��ʊO�̔s�k����̕`��
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

//�w�i�̕`��
void drawBackGround(CPlayer player)
{
	//��ԏ�̒i�͉�ʊO�Ȃ̂ŕ\�����Ȃ�
	for (int j = 1; j <= FIELD_H - 1; j++)
	{
		for (int i = 1; i <= FIELD_W; i++)
		{
			//�ʏ�̃u���b�N���1������ƂȂ�
			const int x = player.get_x_from_i(i) - 1;
			const int y = player.get_y_from_j(j) - 1;
			DrawGraph(x, y, img.backBlock, TRUE);
		}
	}
}	

//�J�[�\���̕`��
void drawCursor(CPlayer player)
{
	const int x1 = player.getFieldLeft() + (player.getX() - 1) * (BLOCK_SIZE + 1);
	const int x2 = player.getFieldLeft() + (player.getX()) * (BLOCK_SIZE + 1);
	const int y1 = player.getFieldLower() - player.getY() * (BLOCK_SIZE + 1) - 1;
	const int nextColor0 = getCursorImg(player.getNextBlock(0).getColor());
	DrawGraph(x1, y1, nextColor0, TRUE);
	DrawGraph(x2, y1, nextColor0, TRUE);
}
