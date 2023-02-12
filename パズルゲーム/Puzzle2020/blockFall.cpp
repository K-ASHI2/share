#include "DxLib.h"
#include "extern.h"
#include "Player.h"
#include <vector>

//�u���b�N�̗���
void CPlayer::blockFall()
{
	//���Ƀu���b�N���Ȃ����ɂ��̃u���b�N�𗎉���Ԃɂ��� 
	for (int j = 2; j <= FIELD_H; j++)
	{
		for (int i = 1; i <= FIELD_W; i++)
		{
			//���Œ��ł��h���Ă���r���ł��Ȃ��u���b�N�ɑ΂�,���Ƀu���b�N��������΍s��
			if (block[i][j].getColor() != ec_null && block[i][j].getVanishCount() == 0 && block[i][j].getDrawEffectCount() == 0)
			{
				if (block[i][j - 1].getColor() == ec_null)
				{
					//�u���b�N�̂���ꏊ�ɗ����u���b�N�𐶐����A�A���������������
					int k = createFallingBlock(i, j, block[i][j].getColor());

					//�u���b�N�̎����Ă���A�����𗎉���������
					fallingBlock[k].setChain(block[i][j].getChain());

					block[i][j].init(i, j);
				}
			}
		}
	}

	//�������x
	static const int vy = 6;

	//�Ⴂ���Ƀ\�[�g�����ق�����������

	//�S�Ă̗������̃u���b�N�𗎉�������
	for (int k = 0; k <= FIELD_W * FIELD_H; k++)
	{
		if (fallingBlock[k].getColor() != ec_null)
		{
			fallingBlock[k].addY(vy);

			//���������擾���A���̗�ɑ΂����肷��
			const int line = fallingBlock[k].getLine();

			//��ԍ����u���b�N��y���W�𓾂�
			//const int h = getHighestBlock(line);
			const int h = getHighestUnderBlock(line, fallingBlock[k].getY());
			const int highest_y = get_y_from_j(h);

			//printfDx("%s%d%s%d%s%d%s%d\n", "i : ", line, " h : ", h, " k : ", k ,  " y : ",fallingBlock[k].getY());

			//��ԍ����u���b�N�̏�[�����������̃u���b�N�����ɗ����炻�̏�Ƀu���b�N��u��
			if (fallingBlock[k].getY() + BLOCK_SIZE + 1 > highest_y)
			{
				landingBlock(k, h);
			}
		}
	}
}

std::vector<int> CPlayer::getRandomOrder(int length)
{
	//���߂鏇��
	std::vector<int> order(length);

	//GetRand�p�Ɏc���Ă鐔������O�ɋl�߂��z��
	std::vector<int> table(length);

	//�����͈���炷
	for (int i = 0; i < length; i++)
	{
		table[i] = i + 1;
	}

	for (int i = length - 1; i > 0; i--)
	{
		//0�`i�܂ł̗����𓾂�
		int x = GetRand(i);

		//table�ɑΉ���������order�ɓ����
		order[i] = table[x];
		//printfDx("%s%d%s%d\n", "order ", i, " : ", order[i]);

		//table����O�ɋl�߂�
		for (int j = 0; j < i; j++)
		{
			//x��菬���������͂��̂܂܂ɂ���
			//x���傫��������O�ɋl�߂�
			if (j >= x)
			{
				table[j] = table[j + 1];
			}
		}
	}

	//�Ō�͗������擾���Ȃ��œ����
	order[0] = table[0];

	return order;
}

//i�̗�ɂ�����y��艺�ň�ԏ�ɑ��݂���u���b�N�̈ʒu���擾����
//���݂��Ȃ����0��Ԃ�
int CPlayer::getHighestUnderBlock(int i, int fby)
{

	//y�̍�����艺�̃u���b�N����T��
	//y�͏��Ablock�͉���Ȃ̂ň����ċ��߂�
	int j = (FIELD_H - 1) - (fby - field_upper) / (BLOCK_SIZE + 1);

	while (j > 0)
	{
		//���̈ʒu�Ƀu���b�N�����݂���Ȃ炻�̈ʒu��Ԃ�
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

//�u���b�N�̗�(�����牽�Ԗڂ�)����x���W�𓾂�
int CPlayer::get_x_from_i(int i)
{
	return  field_left + 1 + (i - 1) * (BLOCK_SIZE + 1);
}

//�u���b�N�̍s(����)����y���W�𓾂�
int CPlayer::get_y_from_j(int j)
{
	//��ʊO�̕��̈�i������
	return field_upper + (FIELD_H - 1 - j) * (BLOCK_SIZE + 1);
}


//�u���b�N���������Ēn�ʂɂ������̏���
void CPlayer::landingBlock(int k, int j)
{
	const int CHAIN_TIME = 10;
	const int i = fallingBlock[k].getLine();

	//��ԏ�(��ʊO)�̒i�łȂ���Έ��̒i�ɒu��
	//��ԏ�̒i�Ȃ痎�����̃u���b�N�����ł�����(��ԏ�̒i�̏�ɗ�����d�l�ɂ���Ȃ�G�t�F�N�g�����邪���󔭐����Ȃ��͂�)
	if (j < FIELD_H)
	{
		block[i][j + 1].setColor(fallingBlock[k].getColor());
		//�A�������������A�A�����莞�Ԃ�ݒ肷��
		block[i][j + 1].setChain(fallingBlock[k].getChain());
		block[i][j + 1].setChainTime(CHAIN_TIME);
	}

	fallingBlock[k].init();
	//printfDx("%s%d%s%d\n", "landingBlock k : ", k, " j : ", j);
}

//�ォ�痎���Ă���u���b�N��n�i���Ƃ�
//����ł͈�i�̂ݑΉ�
void CPlayer::dropBlock(int n)
{
	for (int l = 0; l < n; l++)
	{
		//�u���b�N�𐶐����鏇��
		std::vector<int> order = getRandomOrder(FIELD_W);

		//�u���b�N�̂Ȃ���ԏ�̍��W�Ɏg�p�\�ȐF(�u���Ă������Ȃ��F)���擾���A��ʊO�ɗ����u���b�N�����
		//��ԏ�̒i�Ƀu���b�N�𐶐�����
		for (int x = 0; x < FIELD_W; x++)
		{
			int i = order[x];

			//��ԏ�̒i�Ƀu���b�N�����݂��鎞�̏���
			if (resultField[i][FIELD_H - 1] != ec_null)
			{
				//�X�R�A�A�^�b�N���[�h�ł͈�ԏ�̒i�Ƀu���b�N������Ȃ�u���b�N�𐶐����Ȃ�
				if (mode_flag == em_score_attack)
				{
					continue;
				}
			}

			//�u���b�N�����݂��Ȃ��i��T��
			const int j = getHighestResultBlock(i) + 1;

			/*printfDx("%s", "resultField ");
			for (int a = 1; a <= FIELD_W; a++)
			{
				printfDx("%d ", resultField[a][j]);
			}
			printfDx("\n");*/

			//���ꂼ��̐F�ɑ΂��A�z��̑Ή������ԍ��Ɏg�p�\���ǂ���������
			std::vector<bool> usable(color_n + 1);

			for (int k = 1; k <= color_n; k++)
			{
				usable[k] = true;
			}

			//����̃u���b�N�Ɠ����F�ɂȂ�Ȃ��悤�ɂ���
			//��Œu�������𒲂ׂ�Ӗ��͂Ȃ�

			//3�ȏ㓯���F�����΂Ȃ��悤�ɂ���
			//��O2�������F�Ȃ炻�̐F���g�p�s�ɂ���
			if (i > 2)
			{
				e_color color1 = resultField[i - 1][j];
				if (color1 > ec_null)
				{
					if (color1 == resultField[i - 2][j])
					{
						usable[(int)color1] = false;
						//printfDx("��O2��\n");
					}
				}
			}

			//���2�������F�Ȃ炻�̐F���g�p�s�ɂ���
			if (i < FIELD_W - 1)
			{
				e_color color1 = resultField[i + 1][j];
				if (color1 > ec_null)
				{
					if (color1 == resultField[i + 2][j])
					{
						usable[(int)color1] = false;
						//printfDx("���2��\n");
					}
				}
			}

			//�O��2�������F�Ȃ炻�̐F���g�p�s�ɂ���
			if (i > 1 && i < FIELD_W)
			{
				e_color color1 = resultField[i - 1][j];
				if (color1 > ec_null)
				{
					if (color1 == resultField[i + 1][j])
					{
						usable[(int)color1] = false;
						//printfDx("�O��\n");
					}
				}
			}

			//��2�Ɠ����F�Ȃ炻�̐F���g�p�s�ɂ���
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

			//�~�X�H������̉����Ȃ��u���b�N(ec_null)��false�ɂ��Ă��邾��
			//usable[(int)block[i][j].getColor()] = false;

			//�g�p�\�ȐF�̐�
			int usable_n = 0;
			for (int k = 1; k <= color_n; k++)
			{
				if (usable[k])
				{
					usable_n++;
				}
			}

			//�g�p�\�ȐF��z��̎�O�ɋl�߂ē����
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

			//������̉��̃t�B�[���h�ɐ��������u���b�N��������
			resultField[i][j] = color;

			//��ʊO����h���b�v������
			//2�i�ȏ�o���ꍇ��ɂ��炷(2�i�ȏ㗎�Ƃ��͖̂�����)
			int y = G_W_UPPER - (3 + l) * (BLOCK_SIZE + 1);

			//���y���W�ƐF��^���ė������̃u���b�N�����
			createFallingBlock2(i, y, color);
		}
	}
}

//����4�}�X�݂̂Ɉ�i���Ƃ�
void CPlayer::dropCenter()
{
	//�u���b�N�𐶐����鏇��
	std::vector<int> order = getRandomOrder(FIELD_W - 2);
	//2�`5��ڂ�p���邪�A1�`4�ŕ\����Ă��邽�߂��炷
	for (int x = 0; x < FIELD_W - 2; x++)
	{
		order[x]++;
	}

	//�u���b�N�̂Ȃ���ԏ�̍��W�Ɏg�p�\�ȐF(�u���Ă������Ȃ��F)���擾���A��ʊO�ɗ����u���b�N�����
	//��ԏ�̒i�Ƀu���b�N�𐶐�����
	for (int x = 0; x < FIELD_W - 2; x++)
	{
		int i = order[x];

		//�u���b�N�����݂��Ȃ��i��T��
		const int j = getHighestResultBlock(i) + 1;

		/*printfDx("%s", "resultField ");
		for (int a = 1; a <= FIELD_W; a++)
		{
		printfDx("%d ", resultField[a][j]);
		}
		printfDx("\n");*/

		//���ꂼ��̐F�ɑ΂��A�z��̑Ή������ԍ��Ɏg�p�\���ǂ���������
		std::vector<bool> usable(color_n + 1);

		for (int k = 1; k <= color_n; k++)
		{
			usable[k] = true;
		}

		//����̃u���b�N�Ɠ����F�ɂȂ�Ȃ��悤�ɂ���
		//��Œu�������𒲂ׂ�Ӗ��͂Ȃ�

		//3�ȏ㓯���F�����΂Ȃ��悤�ɂ���
		//��O2�������F�Ȃ炻�̐F���g�p�s�ɂ���
		if (i > 2)
		{
			e_color color1 = resultField[i - 1][j];
			if (color1 > ec_null)
			{
				if (color1 == resultField[i - 2][j])
				{
					usable[(int)color1] = false;
					//printfDx("��O2��\n");
				}
			}
		}

		//���2�������F�Ȃ炻�̐F���g�p�s�ɂ���
		if (i < FIELD_W - 1)
		{
			e_color color1 = resultField[i + 1][j];
			if (color1 > ec_null)
			{
				if (color1 == resultField[i + 2][j])
				{
					usable[(int)color1] = false;
					//printfDx("���2��\n");
				}
			}
		}

		//�O��2�������F�Ȃ炻�̐F���g�p�s�ɂ���
		if (i > 1 && i < FIELD_W)
		{
			e_color color1 = resultField[i - 1][j];
			if (color1 > ec_null)
			{
				if (color1 == resultField[i + 1][j])
				{
					usable[(int)color1] = false;
					//printfDx("�O��\n");
				}
			}
		}

		//��2�Ɠ����F�Ȃ炻�̐F���g�p�s�ɂ���
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

		//�~�X�H������̉����Ȃ��u���b�N(ec_null)��false�ɂ��Ă��邾��
		//usable[(int)block[i][j].getColor()] = false;

		//�g�p�\�ȐF�̐�
		int usable_n = 0;
		for (int k = 1; k <= color_n; k++)
		{
			if (usable[k])
			{
				usable_n++;
			}
		}

		//�g�p�\�ȐF��z��̎�O�ɋl�߂ē����
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

		//������̉��̃t�B�[���h�ɐ��������u���b�N��������
		resultField[i][j] = color;

		//��ʊO����h���b�v������
		//2�i�ȏ�o���ꍇ��ɂ��炷(2�i�ȏ㗎�Ƃ��͖̂�����)
		int y = G_W_UPPER - 3 * (BLOCK_SIZE + 1);

		//���y���W�ƐF��^���ė������̃u���b�N�����
		createFallingBlock2(i, y, color);
	}
}

void CPlayer::dropWhite()
{
	//�u���b�N�𐶐����鏇��
	int order[FIELD_W + 1];

	//�����̗�̃u���b�N�̍ő�̍���
	int height[FIELD_W + 1];

	bool used[FIELD_W + 1];

	for (int i = 1; i <= FIELD_W; i++)
	{
		height[i] = getHighestResultBlock(i);
		used[i] = false;
	}

	//�Ⴂ���ɏ�����I��
	//�񂪏��Ȃ��Ď��Ԃ�������Ȃ��̂œK���ȃA���S���Y��
	for (int i = 1; i <= FIELD_W; i++)
	{
		//�g�p����Ă��Ȃ����̂����ԒႢ����I��ł���
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

	//��̉񐔂����ő�s��
	for (int i = 1; i <= FIELD_W; i++)
	{
		const int line = order[i];

		//���Ƃ��u���b�N���Ȃ��Ȃ�����I���ɂ���
		if (dropNotice == 0)
		{
			break;
		}

		//��ʊO����h���b�v������
		//2�i�ȏ�o���ꍇ��ɂ��炷(2�i�ȏ㗎�Ƃ��͖̂�����)
		int y = G_W_UPPER - 3 * (BLOCK_SIZE + 1);

		//���y���W�ƐF��^���ė������̃u���b�N�����
		createFallingBlock2(line, y, ec_white);

		dropNotice--;
	}
}

//�������̃u���b�N��V���ɍ��A���̔z��̓Y������Ԃ�
int CPlayer::createFallingBlock(int i, int j, e_color color)
{
	return createFallingBlock2(i, G_W_UPPER + (FIELD_H - j - 1) * (BLOCK_SIZE + 1), color);
}

//�������̃u���b�N��V���ɍ��A���̔z��̓Y������Ԃ�
//������ł�y���W�𒼐ڗ^����
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

//�󒆂ɂ���S�u���b�N�̗�����̃t�B�[���h�ɑ��݂����ԏ�̃u���b�N�����߂�
//��ʊO�ɓ��B���Ă����ꍇ�A��肭��������Ȃ��̂ŕK�v�Ȃ璼��
//getHighestBlock�Ǝd�l�𑵂��Ă���
int CPlayer::getHighestResultBlock(int i)
{
	int j = 0;
	while (j + 1 < FIELD_H)
	{
		//�u���b�N�����݂��Ȃ��Ȃ�u���b�N�̈ʒu���擾����
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

//�������̃u���b�N��y���W�ŏ����Ƀ\�[�g����
void CPlayer::quickSort(CFallingBlock f[], int n)
{
	quickSort(f, 0, n - 1);
}

void CPlayer::quickSort(CFallingBlock f[], int low, int high)
{

	if (high <= low)//*�ŏ��ɍ��[�ɂ��������̈ړ���̈ʒu��荶�����בւ��I�������
		return;
	const int y = f[low].getY();   //*���肵�������i���ׂ�͈͂̍��[�̐��j��x�ɑ������
	const int m = partition(f, low, high, y);
	quickSort(f, low, m);    //���߂��ʒu���獶���ɔ��肷�鐔��菬����������ׂ�
	quickSort(f, m + 1, high); //���߂��ʒu����E���ɔ��肷�鐔���傫��������ׂ�
}

//���肷�鐔���ǂ̈ʒu�ɗ��邩�����߂�
int CPlayer::partition(CFallingBlock f[], int low, int high, int y)
{

	//�z��̗v�f�����L������
	int n = high - low + 1;
	std::vector<CFallingBlock> b(high - low + 1);

	//small��define����Ă���̂Ŗ��O��ς���
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
