#include"DxLib.h"
#include"extern.h"
#include"function.h"

//�u���b�N�̏���
void CPlayer::vanishCheck()
{
	//�������̍폜�`�F�b�N���s��
	sideCheck();

	//�c�����̍폜�`�F�b�N���s��
	verticalCheck();

	//�폜����
	if (mode_flag == em_score_attack)
	{
		blockVanish();
	}
	else if(mode_flag == em_vs){
		blockVanishVs();
	}
}

//�������̍폜�`�F�b�N���s��
void CPlayer::sideCheck()
{
	//��񂸂`�F�b�N���Ă���
	for (int j = 1; j <= FIELD_H; j++)
	{
		e_color countColor = ec_null;
		int count = 0;
		//�������u���b�N�̂�����ԘA�������������ɍ��킹���A�����ŏ��ł���
		int maxChain = 0;

		for (int i = 1; i <= FIELD_W; i++) {
			//���Œ��łȂ��F�̂����u���b�N���������J�E���g����
			if (block[i][j].getColor() > 0 && block[i][j].getVanishCount() == 0)
			{
				//�J�E���g���Ă��Ȃ���
				//��ڂ̃u���b�N�������Ȃ��ꏊ�̎��Ȃ�J�E���g���̐F��ݒ肷��
				if (countColor == ec_null)
				{
					countColor = block[i][j].getColor();
					count = 1;
					maxChain = block[i][j].getChain();
				}
				//�J�E���g���̐F�Ȃ���Z����
				else if (countColor == block[i][j].getColor())
				{
					count++;
					//���傫�ȘA�����̃u���b�N������Ες���
					if (block[i][j].getChain() > maxChain)
					{
						maxChain = block[i][j].getChain();
					}
				}
				//�J�E���g���̐F�ȊO�̎�
				else {
					//�J�E���g��3�ȏ�Ȃ�J�E���g�����u���b�N�S�Ăɍ폜�t���O�𗧂Ă�
					if (count >= 3)
					{
						//���̃u���b�N�̈��O����n��������u���b�N�ƂȂ�
						for (int k = 1; k <= count; k++)
						{
							block[i - k][j].setVanishFlag(true);

							//���ł���u���b�N�̘A�������ő�̕��ɑ�����
							//�c>���̘A�����œ����ɏ�����ƘA����������邪�قڋN���Ȃ��̂Ŗ���(�c����Ă��������x�`�F�b�N����΂悢�H)
							block[i - k][j].setChain(maxChain);
						}
					}
					//�Ⴄ�F���o���炻�̐F�ɂ���
					countColor = block[i][j].getColor();
					count = 1;
					maxChain = block[i][j].getChain();
					//��ʒ[���߂��ď����Ȃ��Ȃ�break����
					if (i >= FIELD_W - 1)
					{
						break;
					}
				}
			}
			//�u���b�N���Ȃ��Ȃ�J�E���g�𖳂���
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
				//��ʒ[���߂��ď����Ȃ��Ȃ�break����
				if (i >= FIELD_W - 2)
				{
					break;
				}
			}
		}
		//�[�ɓ��B�������Ƀu���b�N�������Ă���Ȃ�폜�t���O�𗧂Ă�
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

//�c�����̍폜�`�F�b�N���s��
void CPlayer::verticalCheck()
{
	//��񂸂`�F�b�N���Ă���
	for (int i = 1; i <= FIELD_W; i++)
	{
		e_color countColor = ec_null;
		int count = 0;
		//�������u���b�N�̂�����ԘA�������������ɍ��킹���A�����ŏ��ł���
		int maxChain = 0;

		for (int j = 1; j <= FIELD_H; j++)
		{
			//���Œ��łȂ��F�̂����u���b�N���������J�E���g����
			if (block[i][j].getColor() > 0 && block[i][j].getVanishCount() == 0)
			{
				//�J�E���g���Ă��Ȃ���
				//��ڂ̃u���b�N�������Ȃ��ꏊ�̎��Ȃ�J�E���g���̐F��ݒ肷��
				if (countColor == ec_null)
				{
					countColor = block[i][j].getColor();
					count = 1;
					maxChain = block[i][j].getChain();
				}
				//�J�E���g���̐F�Ȃ���Z����
				else if (countColor == block[i][j].getColor())
				{
					count++;
					//���傫�ȘA�����̃u���b�N������Ες���
					if (block[i][j].getChain() > maxChain)
					{
						maxChain = block[i][j].getChain();
					}
				}
				//�J�E���g���̐F�ȊO�̎�
				else {
					//�J�E���g��3�ȏ�Ȃ�J�E���g�����u���b�N�S�Ăɍ폜�t���O�𗧂Ă�
					if (count >= 3)
					{
						//���̃u���b�N�̈��O����n��������u���b�N�ƂȂ�
						for (int k = 1; k <= count; k++)
						{
							block[i][j - k].setVanishFlag(true);

							//���ł���u���b�N�̘A�������ő�̕��ɑ�����
							//�c>���̘A�����œ����ɏ�����ƘA����������邪�قڋN���Ȃ��̂Ŗ���(�c����Ă��������x�`�F�b�N����΂悢�H)
							block[i][j - k].setChain(maxChain);
						}
					}
					//�Ⴄ�F���o���炻�̐F�ɂ���
					countColor = block[i][j].getColor();
					count = 1;
					maxChain = block[i][j].getChain();
					//��ʒ[���߂��ď����Ȃ��Ȃ�break����
					if (j >= FIELD_H - 1)
					{
						break;
					}
				}
			}
			//�u���b�N���Ȃ��Ȃ�J�E���g�𖳂���
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
				//��ʒ[���߂��ď����Ȃ��Ȃ�break����
				if (j >= FIELD_H - 2)
				{
					break;
				}
			}
		}
		//�[�ɓ��B�������Ƀu���b�N�������Ă���Ȃ�폜�t���O�𗧂Ă�
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

//�u���b�N���폜����(�X�R�A�A�^�b�N���[�h)
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

	//��x�ɏ������u���b�N�̐�
	int count = 0;

	for (int j = 1; j <= FIELD_H; j++)
	{
		for (int i = 1; i <= FIELD_W; i++)
		{
			//�u���b�N�̏��Œ��̏���
			if (block[i][j].getVanishCount() > 0)
			{
				block[i][j].decrementVanishCount();
				//�u���b�N�����S�ɏ��ł�����F�𖳂����A�t���O��߂�
				if (block[i][j].getVanishCount() == 0)
				{
					block[i][j].setVanishFlag(false);
					block[i][j].setColor(ec_null);
				}
			}

			//���ł����܂��Ă���u���b�N�ɂ��ď��Ŏ��Ԃ�����
			//���ł����܂������ɏ����Ă��������A�����ōs���ƈꉞ�c�������ɏ��������ɏ����񐔂͌���
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
		//1.5�b�R���{���Ԃ��p��������
		//���Z�����ɕύX���Ă���������
		comboTime = COMBO_TIME;

		double rate = 1.0;

		//�R���{�{�[�i�X
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
			//�R���{�{�[�i�X�̌��E
			else
			{
				rate += 0.0;
			}
		}

		//�R���{���������ɏ�����ꍇ�̃X�R�A
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

//�ΐ탂�[�h�ɂ�����u���b�N�̍폜�J�n����
void CPlayer::blockVanishVs()
{

	//�A�����ڒn���Ă����ɋN���Ȃ���ΘA���������Z�b�g
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

	//�ΐ탂�[�h�ł͏����I��������Ɉ�x�ɏ������u���b�N�̐��𐔂���
	//���Ō�ɍU������ƃX�R�A�̔�����s����������
	int count = 0;

	//�A�������Ƃɏ������u���b�N�̐��𐔂���
	//0�͎g�킸1�`9�ŕ\���A9�A���ȏ��9�Ɠ�������(�����N���Ȃ������̂Ƃ��떳��)
	int chainCount[10];
	for (int i = 1; i <= 9; i++)
	{
		chainCount[i] = 0;
	}

	for (int j = 1; j <= FIELD_H; j++)
	{
		for (int i = 1; i <= FIELD_W; i++)
		{
			//�u���b�N�̏��Œ��̏���
			if (block[i][j].getVanishCount() > 0)
			{
				block[i][j].decrementVanishCount();
				//�u���b�N�����S�ɏ��ł�����F�𖳂����A�t���O��߂�
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
						//�u���b�N�����݂��Ȃ��}�X������΂����ŏI���
						if (block[i][k].getColor() == 0 || block[i][k].getVanishCount() > 0)
						{
							break;
						}
						//��̃u���b�N�S�ĂɘA������^����(1���Z����)
						block[i][k].setChain(block[i][j].getChain() + 1);
					}
				}
			}

			//���ł����܂��Ă���u���b�N�ɂ��ď��Ŏ��Ԃ�����
			//���ł����܂������ɏ����Ă��������A�����ōs���ƈꉞ�c�������ɏ��������ɏ����񐔂͌���
			else if (block[i][j].getVanishFlag())
			{
				block[i][j].setVanishCount(VANISH_TIME);

				//�A���̃J�E���g�𑝂₵�A�A���̌p�����Ԃ�ݒ�(���Z�b�g)����
				//chainCount++;
				//chainTime = MAX_CHAIN_TIME;

			}
		}
	}

	if (count > 0)
	{

		//�R���{���������ɏ�����ꍇ�̃X�R�A���܂��ݒ肷��
		//�������� * 200 �_
		int baseScore = count * 200;

		//4�𒴂��Ă����炻�̕��͒ǉ���500�_
		if (count > 4)
		{
			baseScore += (count - 4) * 500;
		}

		int drop = 0;

		//4�ȏ��������U������
		if (count >= 4)
		{
			//3���������������h���b�v
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

		//�A���{�[�i�X
		//if (chain >= 2)
		//{
		//	//�R���{���ď����ƈ�ǉ��ŗ��Ƃ�
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
		//	//�R���{�{�[�i�X�̌��E
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


//x,y�̈ʒu�Ƀu���b�N�����������A���̃u���b�N�ɂ���ď��ł��N���邩�ǂ���
bool CPlayer::shotVanishCheck(int x, int y)
{
	e_color thisColor = nextBlock[0].getColor();

	//�u���b�N�����݂��Ȃ��}�X���h���Ă���r���̃}�X�Ȃ��false��Ԃ�
	if (block[x][y].getColor() == ec_null || block[x][y].getDrawEffectCount() > 0) {
		return false;
	}
	
	//���E�̔���
	if (x > 1)
	{
		if (block[x - 1][y].getColor() == thisColor && block[x - 1][y].getDrawEffectCount() == 0)
		{
			//����Ɠ����F
			if (x > 2)
			{
				if (block[x - 2][y].getColor() == thisColor && block[x - 2][y].getDrawEffectCount() == 0)
				{
					return true;
				}
			}

			//���E�Ɠ����F
			if (x < FIELD_W)
			{
				if (block[x + 1][y].getColor() == thisColor && block[x + 1][y].getDrawEffectCount() == 0)
				{
					return true;
				}
			}
		}
	}

	//�E��Ɠ����F
	if (x < FIELD_W - 1)
	{
		if (block[x + 1][y].getColor() == thisColor && block[x + 1][y].getDrawEffectCount() == 0
			&& block[x + 2][y].getColor() == thisColor && block[x + 2][y].getDrawEffectCount() == 0)
		{
			return true;
		}
	}

	//�㉺�̔���
	if (y > 1)
	{
		if (block[x][y - 1].getColor() == thisColor && block[x][y - 1].getDrawEffectCount() == 0)
		{
			//����Ɠ����F
			if (y > 2)
			{
				if (block[x][y - 2].getColor() == thisColor && block[x][y - 2].getDrawEffectCount() == 0)
				{
					return true;
				}
			}

			//�㉺�Ɠ����F
			if (y < FIELD_H)
			{
				if (block[x][y + 1].getColor() == thisColor && block[x][y + 1].getDrawEffectCount() == 0)
				{
					return true;
				}
			}
		}
	}

	//���Ɠ����F
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

//x,y�̈ʒu�Ƃ��̉E�̃}�X�̉�2�}�X�Ƀu���b�N�����������A���̃u���b�N�ɂ���ď��ł��N���邩�ǂ���
bool CPlayer::shotVanishCheckTwin(int x, int y)
{
	e_color thisColor = nextBlock[0].getColor();

	//�h��Ȃ��}�X������΁A�����Е��̃}�X�݂̂�h�������̃`�F�b�N������΂悢
	if (!drawableCheck(x, y)) {
		return shotVanishCheck(x + 1, y);
	}
	else if (!drawableCheck(x + 1, y)) {
		return shotVanishCheck(x, y);
	}

	//���E�̔���
	if (x > 1)
	{
		//���Ɠ����F
		if (block[x - 1][y].getColor() == thisColor && block[x - 1][y].getDrawEffectCount() == 0)
		{
			return true;
		}
	}

	//�E�Ɠ����F
	if (x < FIELD_W - 1)
	{
		if (block[x + 2][y].getColor() == thisColor && block[x + 2][y].getDrawEffectCount() == 0)
		{
			return true;
		}
	}

	//�㉺�̔���
	if (y > 1)
	{
		if (block[x][y - 1].getColor() == thisColor && block[x][y - 1].getDrawEffectCount() == 0)
		{
			//����Ɠ����F
			if (y > 2)
			{
				if (block[x][y - 2].getColor() == thisColor && block[x][y - 2].getDrawEffectCount() == 0)
				{
					return true;
				}
			}

			//�㉺�Ɠ����F
			if (y < FIELD_H)
			{
				if (block[x][y + 1].getColor() == thisColor && block[x][y + 1].getDrawEffectCount() == 0)
				{
					return true;
				}
			}
		}
	}

	//���Ɠ����F
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

//x,y�̍��W�ɓh��������2�}�X�F���������ǂ���
bool CPlayer::shotAlignCheck(int x, int y)
{
	e_color thisColor = nextBlock[0].getColor();

	//�h��Ȃ��}�X�Ȃ�false��Ԃ�
	if (!drawableCheck(x, y)) {
		return false;
	}

	//���Ɠ����F
	if (x > 1)
	{
		if (block[x - 1][y].getColor() == thisColor && block[x - 1][y].getDrawEffectCount() == 0)
		{
			return true;
		}
	}

	//�E�Ɠ����F
	if (x < FIELD_W - 1)
	{
		if (block[x + 1][y].getColor() == thisColor && block[x + 1][y].getDrawEffectCount() == 0)
		{
			return true;
		}
	}

	//���Ɠ����F
	if (y > 1)
	{
		if (block[x][y - 1].getColor() == thisColor && block[x][y - 1].getDrawEffectCount() == 0)
		{
			return true;
		}
	}

	//��Ɠ����F
	if (y < FIELD_H - 1)
	{
		if (block[x][y + 1].getColor() == thisColor && block[x][y + 1].getDrawEffectCount() == 0)
		{
			return true;
		}
	}

	return false;
}

//x,y�̍��W��2�}�X�F�������Ă���
bool CPlayer::alignCheck(int x, int y)
{
	e_color thisColor = block[x][y].getColor();

	//�u���b�N�����݂��Ȃ��}�X���h���Ă���r���̃}�X�Ȃ��false��Ԃ�
	if (thisColor == ec_null || block[x][y].getDrawEffectCount() > 0) {
		return false;
	}

	//���Ɠ����F
	if (x > 1)
	{
		if (block[x - 1][y].getColor() == thisColor && block[x - 1][y].getDrawEffectCount() == 0)
		{
			return true;
		}
	}

	//�E�Ɠ����F
	if (x < FIELD_W - 1)
	{
		if (block[x + 1][y].getColor() == thisColor && block[x + 1][y].getDrawEffectCount() == 0)
		{
			return true;
		}
	}

	//���Ɠ����F
	if (y > 1)
	{
		if (block[x][y - 1].getColor() == thisColor && block[x][y - 1].getDrawEffectCount() == 0)
		{
			return true;
		}
	}

	//��Ɠ����F
	if (y < FIELD_H - 1)
	{
		if (block[x][y + 1].getColor() == thisColor && block[x][y + 1].getDrawEffectCount() == 0)
		{
			return true;
		}
	}

	return false;
}

//x,y�̍��W1�}�X�ɓh��邩�ǂ����̃`�F�b�N
bool CPlayer::drawableCheck(int x, int y)
{
	//�F���������A���Œ��̃u���b�N�Ȃ�h��Ȃ�
	if (block[x][y].getColor() == ec_null || block[x][y].getDrawEffectCount() > 0) {
		return false;
	}
	else
	{
		return true;
	}
}

//x,y�̍��W�Ƃ��̉E�̉�2�}�X�ɓh��邩�ǂ����̃`�F�b�N
bool CPlayer::drawableCheckTwin(int x, int y)
{
	//�ǂ��炩�̃}�X���h����true��Ԃ�
	if (drawableCheck(x, y) || drawableCheck(x + 1, y)) {
		return true;
	}
	else
	{
		return false;
	}
}
