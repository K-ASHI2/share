#include "DxLib.h"
#include "extern.h"
#include "Music.h"

//�X�e�[�W�ɑΉ��������y��炷
//����ł͈�X�e�[�W�Ń����_���Đ�����d�l
void CMusic::stageMusic()
{
	//3�Ȃ��烉���_���Đ�����
	const int r = GetRand(2);
	switch (r)
	{
	case 0:	playMusic(stage_1_1); break;
	case 1:	playMusic(stage_1_2); break;
	case 2:	playMusic(stage_2_2); break;
	}
}
