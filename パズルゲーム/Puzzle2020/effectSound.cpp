#include "DxLib.h"
#include "extern.h"
#include "Music.h"

//引数eに対応するエフェクトを鳴らす
void CMusic::efs(enum e_effectSound e)
{
	switch (e) {
	case efs_draw:		PlaySoundMem(draw, DX_PLAYTYPE_BACK);	break;
	case efs_vanish:	PlaySoundMem(vanish, DX_PLAYTYPE_BACK);	break;
	case efs_select:	PlaySoundMem(select, DX_PLAYTYPE_BACK);	break;
	case efs_back:		PlaySoundMem(back, DX_PLAYTYPE_BACK);		break;
	case efs_decision:	PlaySoundMem(decision, DX_PLAYTYPE_BACK);	break;
	case efs_result:	PlaySoundMem(result, DX_PLAYTYPE_BACK);	break;
	case efs_pause:		PlaySoundMem(pause, DX_PLAYTYPE_BACK);	break;
	}
}
