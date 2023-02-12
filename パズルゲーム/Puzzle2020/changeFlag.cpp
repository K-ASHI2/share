#include"DxLib.h"
#include"extern.h"
#include"function.h"

//フラグを変える関数
//フラグが変わった時だけにする処理を実行する
//f:フラグの種類 c:縦カーソルの位置 デフォルト引数 0 c2:横カーソルの位置 デフォルト引数 0
void CMenuWindow::changeFlag(e_flag f, int c, int c2)
{
	//最初はフェードアウトのみを行い、その後change_flag2が呼び出されてフェードインとフラグの変更を行う
	changeFlag_flag = f;
	changeFlag_cursor = c;
	changeFlag_cursor2 = c2;

	//ポーズ画面から戻る時
	if (f == e_gameplay && flag == e_pause)
	{
		//止めていた曲を途中から再生する
		PlaySoundMem(music.getPlayingMusic(), DX_PLAYTYPE_LOOP, FALSE);
		PlaybackFlag = 0;
	}

	//フラグによってはフェードアウトしないでフラグを変える
	//クリア画面、ポーズ画面(出入り両方)、ゲーム開始時(出入り両方)
	if (f != e_clear && f != e_pause && f != e_start && (f != e_gameplay || flag != e_pause || flag != e_start))
	{
		fadeFlag = ef_fadeOut;
	}
	else
	{
		changeFlag2(changeFlag_flag, changeFlag_cursor, changeFlag_cursor2);
	}
}

//フェードアウト後に実際にフラグを変える時の処理をする関数
//f:フラグの種類 c:縦カーソルの位置 デフォルト引数 0 c2:横カーソルの位置 デフォルト引数 0
void CMenuWindow::changeFlag2(enum e_flag f, int c, int c2)
{
	const e_flag flag2 = flag;	//変更前のフラグ
	flag = f;
	flagSetFont();	//フラグごとのフォントを決める

	//フラグの内容ごとのフラグ変更時の処理を実行する
	switch (flag)
	{
	case e_title:
		setSelectWindow(6, c);
		cursor = cancel_cursor;
		/*switch (flag2)
		{
		case e_keyconfig: cursor = 2; break;
		}*/
		music.playMenu();
		break;

	case e_movemenu:
		setSelectWindow(5, c);
		break;

	case e_operationmenu:
		setSelectWindow(3, c);
		break;

	case e_start:
		stageStartCount = 175;
		stageStartFlag = false;
		break;

	case e_gameplay:
		break;

	case e_clear:
		StopSoundMem(music.getPlayingMusic());
		music.efs(efs_result);
		clear_count = 0;
		//ハイスコアを更新していたら記録する
		if (hiscore_flag)
		{
			writeHiscore();
		}
		break;

	case e_win:
		StopSoundMem(music.getPlayingMusic());
		music.efs(efs_result);
		clear_count = 0;
		break;

	case e_pause:
		//ポーズの効果音を鳴らす
		music.efs(efs_pause);

		setSelectWindow(3, c);

		//音楽の中断
		StopSoundMem(music.getPlayingMusic());
		break;

	case e_keyconfig:
		setSelectWindow(5, c);
		break;

	case e_manual:
		setSelectWindow(6, c);
		break;
	}
}
