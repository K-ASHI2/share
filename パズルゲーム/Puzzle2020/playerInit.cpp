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

	//�v���C���[����Ȃ�v�l���Ԃ̃f�B���C��0�ɂ���
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
		//�v����
		//�U���ŗ�����ʂ�������̂ōŏ��͒x�߂ł��ǂ�����
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
		//2P��1P�Ɠ��������t�B�[���h�ɂ���
		fieldClear();
		fieldCopy(player1);
		field_left = G_W_LEFT_2;
		field_right = G_W_RIGHT_2;
		field_upper = G_W_UPPER;
		field_lower = G_W_LOWER;
	}
}

//�t�B�[���h����ɂ���
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

//�t�B�[���h�̏�����
void CPlayer::fieldInit()
{
	//�ŏ��Ƀt�B�[���h����ɂ���
	//�S����ɂ���͎̂��Ԃ̖��ʂ����A�v�Z�ʂ����Ȃ��̂Ŗ�������
	fieldClear();

	//�t�B�[���h�ɐςݏグ�鏉���̍���
	//�X�R�A�A�^�b�N�ł͉�ʑS�́A�ΐ�ł͔���
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

			//c++�̎d�l�ł͔z��̗v�f���ɕϐ�������ꍇ�|�C���^���g��Ȃ���΂Ȃ�Ȃ�
			//�������m�ۂ̓o�O����������̂�vector���g��
			std::vector<bool> usable(color_n + 1);

			//�S�Ă̐F���ŏ��͎g�p�\�ɂ���
			for (int k = 1; k <= color_n; k++)
			{
				usable[k] = true;
			}

			//����̃u���b�N�Ɠ����F�ɂȂ�Ȃ��悤�ɂ���
			//��Œu�������͒��ׂȂ��Ă悢
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

//�w�肳�ꂽ�v���C���[�̃t�B�[���h���R�s�[����
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

//�g�p�\�Ǝw�肳�ꂽ�F�̒����烉���_���ŐF��Ԃ�
e_color CPlayer::getRandomUsableColor(const std::vector<e_color> &usable, int n)
{
	const int rand = GetRand(n - 1);
	return usable[rand];
}

//�v���C���[���g�p����F�̒����烉���_���ŐF���擾����
e_color CPlayer::getRandomColor()
{
	return (e_color)(GetRand(color_n - 1) + 1);
}

//�������̃u���b�N�̏�����
void CPlayer::fallingBlockInit()
{
	for (int k = 0; k < FIELD_H * FIELD_W; k++)
	{
		fallingBlock[k].init();
	}
}

//������̃t�B�[���h����ɂ���
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

//������̃t�B�[���h�����߂Ȃ���
void CPlayer::resultFieldInit()
{
	//�������̃u���b�N����������̏�Ԃ����������A�V���ɋ��߂�
	resultFieldClear();

	//�t�B�[���h�ɑ��݂���u���b�N���܂�����Ă���
	for (int j = 1; j <= FIELD_H; j++)
	{
		for (int i = 1; i <= FIELD_W; i++)
		{
			resultField[i][j] = block[i][j].getColor();
		}
	}

	//�������̃u���b�N�ɑ΂��A������̏�Ԃɂ���
	//�܂��\�[�g���A�������Ⴂ���ɂ���
	quickSort(fallingBlock, FIELD_H * FIELD_W);

	for (int k = 0; k < FIELD_H * FIELD_W; k++)
	{
		//�\�[�g����Č��ɋ�̗v�f������̂Ō�������I���ɂ���
		if (fallingBlock[k].getY() == INT_MAX)
		{
			break;
		}

		//�u���b�N�𗎉���̏�Ԃɕۑ�����
		const int i = fallingBlock[k].getLine();
		const int h = getHighestResultBlock(i);
		resultField[i][h + 1] = fallingBlock[k].getColor();
	}
}

//NEXT��hold�̏�����
void CPlayer::nextInit()
{
	for (int i = 0; i < NEXT_N; i++)
	{
		e_color color = getRandomColor();
		nextBlock[i].setColor(color);
	}
}
