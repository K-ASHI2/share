#include"DxLib.h"
#include"extern.h"
#include"function.h"
#include"SearchField.h"
#include <queue>
#include"math.h"

const static int MOVE_WAIT = 11;

//�v���C���[�̈ړ�
void CPlayer::movePlayer()
{

	//���Ԍo�߂ɂ��҂����Ԃ̌���
	if (t > 0)
	{
		t--;
	}

	if (shot_t > 0)
	{
		shot_t--;
	}

	//�v���C���[�����삷�郂�[�h
	if (cpuMove == ec_player)
	{
		//cpu�ΐ펞
		if (player2.cpuMove != ec_player || mode_flag == em_score_attack)
		{
			if (t == 0)
			{
				//�����������ꂽ���̐���
				int k = 0;
				if (keyPad.getButton(KEY_RIGHT) > 0)
				{
					rightMove();
					k++;
				}

				if (keyPad.getButton(KEY_LEFT) > 0)
				{
					leftMove();
					//���E�����������͓��͑҂������Ȃ�(�����ɍ��E�ɓ��͂���Ɠ������͂����\�������邽��)
					if (k != 0)
					{
						t = 0;
					}
					else
					{
						k++;
					}
				}
				//�c�������ɉ����ꂽ��c�ɂ͓������Ȃ�
				if (k == 0) {
					if (keyPad.getButton(KEY_UP) > 0)
					{
						upMove();
						k++;
					}
					if (keyPad.getButton(KEY_DOWN) > 0)
					{
						downMove();
						//�㉺���������������͑҂������Ȃ�
						if (k != 0)
						{
							t = 0;
						}
					}
				}
			}

			//�u���b�N�̎ˏo
			if (keyPad.getButton(KEY_SHOT) == 1)
			{
				blockShot();
			}

			//�{�^���������Ǝ��̃u���b�N�������ɗ������Ă���悤�ɂ���
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
					//�����������ꂽ���̐���
					int k = 0;
					if (keyPad.getButton1P(KEY_RIGHT) > 0)
					{
						rightMove();
						k++;
					}

					if (keyPad.getButton1P(KEY_LEFT) > 0)
					{
						leftMove();
						//���E�����������͓��͑҂������Ȃ�(�����ɍ��E�ɓ��͂���Ɠ������͂����\�������邽��)
						if (k != 0)
						{
							t = 0;
						}
						else
						{
							k++;
						}
					}
					//�c�������ɉ����ꂽ��c�ɂ͓������Ȃ�
					if (k == 0) {
						if (keyPad.getButton1P(KEY_UP) > 0)
						{
							upMove();
							k++;
						}
						if (keyPad.getButton1P(KEY_DOWN) > 0)
						{
							downMove();
							//�㉺���������������͑҂������Ȃ�
							if (k != 0)
							{
								t = 0;
							}
						}
					}
				}
				//�u���b�N�̎ˏo
				if (keyPad.getButton1P(KEY_SHOT) == 1)
				{
					blockShot();
				}

				//�{�^���������Ǝ��̃u���b�N�������ɗ������Ă���悤�ɂ���
				if (keyPad.getButton1P(KEY_CANCEL) == 1 && dropCount > 10 && dropNotice == 0)
				{
					dropCount = dropInterval;
				}
			}
			else if (p == e_2p)
			{
				if (t == 0)
				{
					//�����������ꂽ���̐���
					int k = 0;
					if (keyPad.getButton2P(KEY_RIGHT) > 0)
					{
						rightMove();
						k++;
					}

					if (keyPad.getButton2P(KEY_LEFT) > 0)
					{
						leftMove();
						//���E�����������͓��͑҂������Ȃ�(�����ɍ��E�ɓ��͂���Ɠ������͂����\�������邽��)
						if (k != 0)
						{
							t = 0;
						}
						else
						{
							k++;
						}
					}
					//�c�������ɉ����ꂽ��c�ɂ͓������Ȃ�
					if (k == 0) {
						if (keyPad.getButton2P(KEY_UP) > 0)
						{
							upMove();
							k++;
						}
						if (keyPad.getButton2P(KEY_DOWN) > 0)
						{
							downMove();
							//�㉺���������������͑҂������Ȃ�
							if (k != 0)
							{
								t = 0;
							}
						}
					}
				}
				//�u���b�N�̎ˏo
				if (keyPad.getButton2P(KEY_SHOT) == 1)
				{
					blockShot();
				}

				//�{�^���������Ǝ��̃u���b�N�������ɗ������Ă���悤�ɂ���
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

	//�f�o�b�O�p
	/*if (button[KEY_BOMB] == 1 && player1.shot_t == 0) {
		fieldClear();
	}*/
}

//cpu�̓����̃A���S���Y��
void CPlayer::moveCpu()
{
	//�����_���ɑ��삷��cpu�����삷�郂�[�h
	if (cpuMove == ec_random)
	{
		//�ړ��\�Ȏ��̂ݍs��
		if (t == 0)
		{
			//�����������_���Ɏ擾����A4�Ȃ瓮���Ȃ��������Ȃ����_���Ȃ��̂�3�ȉ�
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
			//50%�̊m���œh��
			if (p <= 80)
			{
				blockShot();
			}
			//wait��t���Ȃ��Ɩ��t���[���h�낤�Ƃ���̂Ŏ���100%
			//�ړ������������x���肷��
			else
			{
				shot_t = MOVE_WAIT;
			}
		}
	}
	//�����̓����_�������A�h���ꏊ�̂ݓh��
	else if (cpuMove == ec_move_random)
	{
		//�ړ��\�Ȏ��̂ݍs��
		if (t == 0)
		{
			//�����������_���Ɏ擾����
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
			//�h����������鎞�����h��
			if (shotVanishCheckTwin(x, y))
			{
				blockShot();
			}
		}
	}

	//��ԋ߂��̏�����ꏊ��T������
	//�R���{���Ȃ���₷�����A���������u����̂ŉ^�������ƊȒP�ɕ�����
	else if (cpuMove == ec_search)
	{
		//�ړ��\�Ȏ��̂ݍs��
		if (t == 0)
		{
			CSearchField sf = targetSearch(6);
			//�T�����ɍŏ��Ɉړ����������ɐi��
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
				//��ԋ߂��h���}�X��T��
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
					//�����ꏊ��������΂��̏������
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

//�u���b�N�̎ˏo(�h��)
void CPlayer::blockShot()
{
	//const static int SHOT_WAIT = 25;
	const static int SHOT_WAIT = 20;

	if (shot_t == 0)
	{
		//�J�[�\���̈ʒu�̐F��h��(�F��ς���)
		const bool shot = changeBlockColor(x, y, nextBlock[0].getColor());

		//�F��ς������̂ݍs��
		if (shot)
		{
			//NEXT�����炷
			for (int i = 0; i < NEXT_N - 1; i++)
			{
				nextBlock[i].setColor(nextBlock[i + 1].getColor());
			}

			e_color nextColor = ec_null;

			//5��ȏ�A���ŏo�Ă��Ȃ��F������Ώo��
			//����̂�2�F�ȏ㓯���ɔ������邪�C�����ĂȂ��̂ŏ��������΂�
			for (int i = 1; i <= color_n; i++)
			{
				if (notAppearCount[i] >= 5)
				{
					nextColor = (e_color)i;
					break;
				}
			}

			//�Ȃ���΃����_���Ɏ擾
			if (nextColor == ec_null)
			{
				nextColor = (e_color)(GetRand(color_n - 1) + 1);
			}

			//NEXT�̍Ō���̐F��ݒ肷��
			nextBlock[NEXT_N - 1].setColor(nextColor);

			notAppearCount[nextColor] = 0;

			for (int i = 1; i <= color_n; i++)
			{
				if (i != nextColor)
				{
					notAppearCount[i]++;
				}
			}

			//�����ɂ͎��̐F��h��Ȃ�����
			shot_t = SHOT_WAIT + GetRand(thinkingTime);

			music.efs(efs_draw);
		}

	}
}

//�����̍��W�̃u���b�N�Ɉ����̐F��t����
bool CPlayer::changeBlockColor(int x, int y, e_color color)
{
	//�ǂ�����h��Ȃ�������false��Ԃ��Anext�͂��̂܂�
	bool drawFlag = false;

	//�u���b�N�����݂��Ă��āA���Œ��łȂ��h���Ă���r���ł��Ȃ��Ȃ�F��t����
	//2�}�X�̂����Е��ł��h���Ȃ�h��
	if (block[x][y].getColor() != ec_null && !block[x][y].getVanishFlag() && block[x][y].getVanishCount() == 0)
	{
		block[x][y].setDrawEffectCount(DRAW_EFFECT_TIME);
		block[x][y].setDrawColor(color);

		drawFlag = true;

		//�F��h��G�t�F�N�g�̓r���ŕω�������d�l�ɕύX����
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

//�h��ׂ��u���b�N�̍��W��Ԃ�
//range:�J�[�\���̍��W����T������}�X�ڂ̋����̍ő�l
CSearchField CPlayer::targetSearch(int range)
{
	//�J�[�\���̈ʒu�̍��W�̃t�B�[���h�����
	CSearchField sf0(x, y, ed_noMove, 0);

	//������ꏊ���h��Ώ�����}�X�Ȃ�Ԃ�
	if (shotVanishCheckTwin(x, y))
	{
		return sf0;
	}

	//���W�Ȃǂ̏����������t�B�[���h������L���[
	std::queue<CSearchField> qsf;
	qsf.push(sf0);

	//�T���ς݂̃}�X���ǂ���
	bool searched[FIELD_W + 1][FIELD_H - 1 + 1];
	for (int j = 1; j <= FIELD_H - 1; j++)
	{
		//�E�[�͏���
		for (int i = 1; i <= FIELD_W - 1; i++)
		{
			searched[i][j] = false;
		}
	}

	//�������W�͒T���ς�
	searched[x][y] = true;

	//�L���[�̒��g�����݂���ԍs��
	while (!qsf.empty())
	{
		CSearchField sf = qsf.front();
		qsf.pop();
		int count = sf.getCount();

		int fx = sf.getX();
		int fy = sf.getY();

		//�E�[�̓X�L�b�v����(�L���[�ɓ����Ă��܂��Ă���)
		if (fx == 6) {
			continue;
		}

		//����4�}�X��T������
		for (int i = 0; i < 4; i++)
		{
			CBlock cb = field[fx][fy].getNeighborBlock(i);
			int cbx = cb.getX();
			int cby = cb.getY();

			//���łɒT���ς�(�L���[�ɓ��ꂽ)�̃}�X�͔�΂�
			//��ʒ[�̏ꍇ�����̃}�X���g���Ԃ��Ă��ĒT���ς݂Ȃ̂Ŕ��
			if (searched[cbx][cby])
			{
				continue;
			}

			//�ŏ��Ɉړ������������擾����
			//�܂��ړ����ĒT�����Ă��Ȃ��Ȃ猻�݂̌���������
			e_direction fd = sf.get_fd();
			if (fd == ed_noMove)
			{
				fd = (e_direction)i;
			}

			//�h��Ώ�����}�X����������L������
			if (shotVanishCheckTwin(cbx, cby))
			{
				CSearchField result_sf(cbx, cby, fd, count + 1);
				return result_sf;
			}

			//�T���}�X�����c���Ă���Ȃ�L���[�ɒǉ�����
			if (count < range)
			{
				CSearchField sf1(cbx, cby, fd, count + 1);
				qsf.push(sf1);
				searched[cbx][cby] = true;
			}
		}
	}

	//�Ō�܂Ō�����Ȃ�������null�̃t�B�[���h��Ԃ�
	CSearchField sf1(x, y, ed_null, 0);

	//�ŏ��̍��W���h��Ȃ��}�X�̏ꍇ��ԋ߂��h���}�X��T��
	if (!drawableCheck(x, y))
	{

	}

	return sf1;
}

////�h������2�}�X�����}�X��T��
//CSearchField CPlayer::alignSearch(int range)
//{
//
//	//�J�[�\���̈ʒu�̍��W�̃t�B�[���h�����
//	CSearchField sf0(x, y, ed_noMove, 0);
//
//	//������ꏊ���h������2�}�X�����}�X�ŁA�܂�2�}�X�����Ă��Ȃ��}�X�Ȃ�Ԃ�
//	if (shotAlignCheck(x, y) && !alignCheck(x, y))
//	{
//		return sf0;
//	}
//
//	//���W�Ȃǂ̏����������t�B�[���h������L���[
//	std::queue<CSearchField> qsf;
//	qsf.push(sf0);
//
//	//�T���ς݂̃}�X���ǂ���
//	bool searched[FIELD_W + 1][FIELD_H - 1 + 1];
//	for (int j = 1; j <= FIELD_H - 1; j++)
//	{
//		for (int i = 1; i <= FIELD_W; i++)
//		{
//			searched[i][j] = false;
//		}
//	}
//	//�������W�͒T���ς�
//	searched[x][y] = true;
//
//	//�L���[�̒��g�����݂���ԍs��
//	while (!qsf.empty())
//	{
//		CSearchField sf = qsf.front();
//		qsf.pop();
//		int count = sf.getCount();
//
//		int fx = sf.getX();
//		int fy = sf.getY();
//
//		//����4�}�X��T������
//		for (int i = 0; i < 4; i++)
//		{
//			CBlock cb = field[fx][fy].getNeighborBlock(i);
//			int cbx = cb.getX();
//			int cby = cb.getY();
//
//			//���łɒT���ς�(�L���[�ɓ��ꂽ)�̃}�X�͔�΂�
//			//��ʒ[�̏ꍇ�����̃}�X���g���Ԃ��Ă��ĒT���ς݂Ȃ̂Ŕ��
//			if (searched[cbx][cby])
//			{
//				continue;
//			}
//
//			//�ŏ��Ɉړ������������擾����
//			//�܂��ړ����ĒT�����Ă��Ȃ��Ȃ猻�݂̌���������
//			e_direction fd = sf.get_fd();
//			if (fd == ed_noMove)
//			{
//				fd = (e_direction)i;
//			}
//
//			//�h���2�}�X�����A�܂�2�}�X�����Ă��Ȃ��}�X����������L������
//			if (shotAlignCheck(cbx, cby) && !alignCheck(cbx, cby))
//			{
//				CSearchField result_sf(cbx, cby, fd, count + 1);
//				return result_sf;
//			}
//
//			//�T���}�X�����c���Ă���Ȃ�L���[�ɒǉ�����
//			if (count < range)
//			{
//				CSearchField sf1(cbx, cby, fd, count + 1);
//				qsf.push(sf1);
//				searched[cbx][cby] = true;
//			}
//		}
//	}
//	//�Ō�܂Ō�����Ȃ�������null�̃t�B�[���h��Ԃ�
//	CSearchField sf1(x, y, ed_null, 0);
//	return sf1;
//}

//�h���Ă�2�}�X�����Ă��Ԃ�����Ȃ��}�X��Ԃ�
//CSearchField CPlayer::noAlignSearch(int range)
//{
//	//�J�[�\���̈ʒu�̍��W�̃t�B�[���h�����
//	CSearchField sf0(x, y, ed_noMove, 0);
//
//	//������ꏊ��2�}�X�����Ă��Ȃ��}�X�Ȃ�Ԃ�
//	if (!alignCheck(x, y))
//	{
//		return sf0;
//	}
//
//	//���W�Ȃǂ̏����������t�B�[���h������L���[
//	std::queue<CSearchField> qsf;
//	qsf.push(sf0);
//
//	//�T���ς݂̃}�X���ǂ���
//	bool searched[FIELD_W + 1][FIELD_H - 1 + 1];
//	for (int j = 1; j <= FIELD_H - 1; j++)
//	{
//		for (int i = 1; i <= FIELD_W; i++)
//		{
//			searched[i][j] = false;
//		}
//	}
//	//�������W�͒T���ς�
//	searched[x][y] = true;
//
//	//�L���[�̒��g�����݂���ԍs��
//	while (!qsf.empty())
//	{
//		CSearchField sf = qsf.front();
//		qsf.pop();
//		int count = sf.getCount();
//
//		int fx = sf.getX();
//		int fy = sf.getY();
//
//		//����4�}�X��T������
//		for (int i = 0; i < 4; i++)
//		{
//			CBlock cb = field[fx][fy].getNeighborBlock(i);
//			int cbx = cb.getX();
//			int cby = cb.getY();
//
//			//���łɒT���ς�(�L���[�ɓ��ꂽ)�̃}�X�͔�΂�
//			//��ʒ[�̏ꍇ�����̃}�X���g���Ԃ��Ă��ĒT���ς݂Ȃ̂Ŕ��
//			if (searched[cbx][cby])
//			{
//				continue;
//			}
//
//			//�ŏ��Ɉړ������������擾����
//			//�܂��ړ����ĒT�����Ă��Ȃ��Ȃ猻�݂̌���������
//			e_direction fd = sf.get_fd();
//			if (fd == ed_noMove)
//			{
//				fd = (e_direction)i;
//			}
//
//			//2�}�X�����Ă��Ȃ��}�X����������L������
//			if (!alignCheck(cbx, cby))
//			{
//				CSearchField result_sf(cbx, cby, fd, count + 1);
//				return result_sf;
//			}
//
//			//�T���}�X�����c���Ă���Ȃ�L���[�ɒǉ�����
//			if (count < range)
//			{
//				CSearchField sf1(cbx, cby, fd, count + 1);
//				qsf.push(sf1);
//				searched[cbx][cby] = true;
//			}
//		}
//	}
//	//�Ō�܂Ō�����Ȃ�������null�̃t�B�[���h��Ԃ�
//	CSearchField sf1(x, y, ed_null, 0);
//	return sf1;
//}

//�h���}�X��T��
CSearchField CPlayer::drawableSearch(int range)
{
	//�J�[�\���̈ʒu�̍��W�̃t�B�[���h�����
	CSearchField sf0(x, y, ed_noMove, 0);

	//������ꏊ���h���}�X�Ȃ�Ԃ�
	if (drawableCheckTwin(x, y))
	{
		return sf0;
	}

	//���W�Ȃǂ̏����������t�B�[���h������L���[
	std::queue<CSearchField> qsf;
	qsf.push(sf0);

	//�T���ς݂̃}�X���ǂ���
	bool searched[FIELD_W + 1][FIELD_H - 1 + 1];
	for (int j = 1; j <= FIELD_H - 1; j++)
	{
		//�J�[�\���̓�����͈݂͂̂ŗǂ��̂ŉE�[�͖���
		for (int i = 1; i <= FIELD_W - 1; i++)
		{
			searched[i][j] = false;
		}
	}
	//�������W�͒T���ς�
	searched[x][y] = true;

	//�L���[�̒��g�����݂���ԍs��
	while (!qsf.empty())
	{
		CSearchField sf = qsf.front();
		qsf.pop();
		int count = sf.getCount();

		int fx = sf.getX();
		int fy = sf.getY();

		//�E�[�̓X�L�b�v����(�L���[�ɓ����Ă��܂��Ă���)
		if (fx == 6) {
			continue;
		}

		//����4�}�X��T������
		for (int i = 0; i < 4; i++)
		{
			CBlock cb = field[fx][fy].getNeighborBlock(i);
			int cbx = cb.getX();
			int cby = cb.getY();

			//���łɒT���ς�(�L���[�ɓ��ꂽ)�̃}�X�͔�΂�
			//��ʒ[�̏ꍇ�����̃}�X���g���Ԃ��Ă��ĒT���ς݂Ȃ̂Ŕ��
			if (searched[cbx][cby])
			{
				continue;
			}

			//�ŏ��Ɉړ������������擾����
			//�܂��ړ����ĒT�����Ă��Ȃ��Ȃ猻�݂̌���������
			e_direction fd = sf.get_fd();
			if (fd == ed_noMove)
			{
				fd = (e_direction)i;
			}

			//2�}�X�����Ă��Ȃ��}�X����������Ԃ�
			if (drawableCheckTwin(cbx, cby))
			{
				CSearchField result_sf(cbx, cby, fd, count + 1);
				return result_sf;
			}

			//�T���}�X�����c���Ă���Ȃ�L���[�ɒǉ�����
			if (count < range)
			{
				CSearchField sf1(cbx, cby, fd, count + 1);
				qsf.push(sf1);
				searched[cbx][cby] = true;
			}
		}
	}
	//�Ō�܂Ō�����Ȃ�������null�̃t�B�[���h��Ԃ�
	CSearchField sf1(x, y, ed_null, 0);
	return sf1;
}

void CPlayer::upMove()
{
	//��ʊO�̈��͊܂܂Ȃ�
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
