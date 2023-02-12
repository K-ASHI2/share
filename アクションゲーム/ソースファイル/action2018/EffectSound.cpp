#include"DxLib.h"
#include"extern.h"
#include"function.h"

//引数eに対応するエフェクトを鳴らす
void efs(enum e_effectSound e) {
	switch (e) {
	case efs_attack:	PlaySoundMem(music.attack, DX_PLAYTYPE_BACK);	break;
	case efs_select:	PlaySoundMem(music.select, DX_PLAYTYPE_BACK);	break;
	case efs_recover:	PlaySoundMem(music.recover, DX_PLAYTYPE_BACK);	break;
	case efs_bomb:		PlaySoundMem(music.bomb, DX_PLAYTYPE_BACK);		break;
	case efs_shot:		PlaySoundMem(music.shot, DX_PLAYTYPE_BACK);		break;
	case efs_back:		PlaySoundMem(music.back, DX_PLAYTYPE_BACK);		break;
	case efs_decision:	PlaySoundMem(music.decision, DX_PLAYTYPE_BACK);	break;
	}
}
