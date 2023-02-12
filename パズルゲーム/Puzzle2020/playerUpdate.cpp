#include"DxLib.h"
#include"extern.h"
#include"function.h"

void CPlayer::update()
{
	//�v���C���[�̈ړ�
	movePlayer();

	//�u���b�N�̏���
	vanishCheck();

	//������̃t�B�[���h�����߂Ȃ���
	resultFieldInit();

	//�u���b�N�̎��R������Ԃւ̈ڍs
	blockFall();

	//�X�R�A�A�^�b�N���[�h
	if (mode_flag == em_score_attack)
	{
		//��莞�Ԗ��Ɉ�i�𗎂Ƃ�
		if (dropCount == dropInterval)
		{
			dropBlock(1);
			dropCount = 0;
		}
		else
		{
			dropCount++;
		}

		//�n�C�X�R�A�̍X�V
		//�X�V������N���A��ʂŎQ�Ƃł���悤�Ƀt���O�𗧂Ă�
		if (hiscore < score)
		{
			hiscore = score;
			hiscore_flag = true;
		}

		//�N���A��ʂւ̈ڍs
		if (timelimit == 0)
		{
			menuWindow.changeFlag(e_clear);
		}
		else {
			//�������Ԃ����炷
			timelimit--;

			//�|�[�Y�{�^���̏���
			if (keyPad.getButton(KEY_PAUSE) == 1)
			{
				menuWindow.changeFlag(e_pause);
			}
		}
	}

	//�ΐ탂�[�h
	else if (mode_flag == em_vs)
	{

		//��莞�Ԗ��Ɉ�i�𗎂Ƃ�
		if (dropCount >= dropInterval)
		{
			//�����݂̂ɗ��Ƃ��̂�2�`3���1������1
			if (nextDropMode == endm_normal)
			{
				dropBlock(1);
				nextDropMode = endm_center;
			}
			else if (nextDropMode == endm_center)
			{
				//����4�}�X�݂̂Ƀh���b�v����
				dropCenter();
				nextDropMode = endm_normal;
			}
			dropCount = 0;
		}

		//�u���b�N��������������łȂ��U��������Ώ�������
		//1/4�̎��Ԗ��ɔ��肵�A���Ƃ�
		//dropInterval��4�Ŋ���؂�Ȃ��ꍇ�A�\���𗎂Ƃ�������ɐF�u���b�N�̗����ɂȂ�̂Œ��O�͗��������Ȃ�
		//else if (dropCount > 10 && dropNotice > 0) {
		else if (dropCount % (dropInterval / 4) == 0 && dropCount < dropInterval - 10 && dropNotice > 0) {

			//�\���̌����𗎂Ƃ�
			dropWhite();

			//�A���ŗ����ďd�Ȃ�̂������
			/*if (dropCount > dropInterval - 10)
			{
				dropCount = dropInterval - 10;
			}*/
		}

		dropCount++;

		////�A�����̎��A�󒆂ɘA������u���b�N�����݂����A���Œ��̃u���b�N�����݂��Ȃ��Ȃ�J�E���g������
		//if (chainTime > 0)
		//{
		//	bool decrement = true;
		//	//�S�Ă̗������̃u���b�N�𗎉�������
		//	for (int k = 0; k <= FIELD_W * FIELD_H; k++)
		//	{
		//		//��ł��A���ł���u���b�N������ΏI��
		//		if (fallingBlock[k].getChain())
		//		{
		//			decrement = false;
		//			break;
		//		}
		//	}
		//	if (decrement)
		//	{
		//		for (int i = 1; i <= FIELD_W; i++)
		//		{
		//			for (int j = 1; j <= FIELD_H; j++)
		//			{
		//				//��ł����Œ��̃u���b�N������ΏI��
		//				if (block[i][j].getVanishFlag())
		//				{
		//					decrement = false;
		//					break;
		//				}
		//			}
		//			if (!decrement)
		//			{
		//				break;
		//			}
		//		}
		//		if (decrement)
		//		{
		//			chainTime--;
		//			//�A�����Ԃ��؂ꂽ�烊�Z�b�g
		//			if (chainTime == 0)
		//			{
		//				chainCount = 0;
		//			}
		//		}
		//	}

		//}

		//��ԏ�(��ʊO)�̒i�Ɉ�莞�ԑ��݂�����Q�[���I�[�o�[�ɂ���
		//��ʊO�ɏ���Ă��班���������Ԃ̗P�\��^����
		for (int i = 1; i <= FIELD_W; i++)
		{
			if (block[i][FIELD_H].getColor() != ec_null)
			{
				loseCount[i]++;
				if (loseCount[i] == LOSE_LIMIT)
				{
					gameover = true;
					break;
				}
			}
			else {
				if (loseCount[i] > 0)
				{
					loseCount[i]--;
				}
			}
		}

		//���U���g��ʂւ̈ڍs
		//1P��2P�������ɔs�k�����2��Ăяo�����̂Ŗ�肠�肻���Ȃ璼��
		if (gameover)
		{
			menuWindow.changeFlag(e_win);
		}
		else
		{
			//�|�[�Y�{�^���̏���
			if (keyPad.getButton(KEY_PAUSE) == 1)
			{
				menuWindow.changeFlag(e_pause);
			}
		}
	}
}
