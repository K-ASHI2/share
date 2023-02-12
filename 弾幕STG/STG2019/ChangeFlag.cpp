#include"DxLib.h"
#include"extern.h"
#include"function.h"

//フラグを変える関数
//フラグが変わった時だけにする処理を実行する
//f:フラグの種類 c:縦カーソルの位置 デフォルト引数 0 c2:横カーソルの位置 デフォルト引数 0
void ChangeFlag(enum e_flag f, int c, int c2) {

	//最初はフェードアウトのみを行い、その後change_flag2が呼び出されてフェードインとフラグの変更を行う
	changeFlag_flag = f;
	changeFlag_cursor = c;
	changeFlag_cursor2 = c2;

	//ポーズ画面から戻る時
	if (f == e_gameplay && flag == e_pause) {
		//止めていた曲を途中から再生する
		PlaySoundMem(p_music, DX_PLAYTYPE_LOOP, FALSE);
		PlaybackFlag = 0;
	}

	//フラグによってはフェードアウトしないでフラグを変える
	//クリア画面、ゲームオーバー画面、ポーズ画面(出入り両方)、
	if (f != e_clear && f != e_gameover && f != e_pause && (f != e_gameplay || flag != e_pause)) {
		fade_flag = ef_fadeOut;
	}
	else {
		ChangeFlag2(changeFlag_flag, changeFlag_cursor, changeFlag_cursor2);
	}
}

//フェードアウト後に実際にフラグを変える時の処理をする関数
//f:フラグの種類 c:縦カーソルの位置 デフォルト引数 0 c2:横カーソルの位置 デフォルト引数 0
void ChangeFlag2(enum e_flag f, int c, int c2) {

	enum e_flag flag2 = flag;	//変更前のフラグ
	flag = f;
	flagSetFont();	//フラグごとのフォントを決める

	//フラグの内容ごとの処理を実行する
	switch (flag) {
	case e_title:
		SetSelectWindow(4, c);
		switch (flag2) {
		case e_characterselect:
			if (world == ew_extra) {
				cursor = 1;
			}
			else {
				cursor = 0;
			}
			break;
		//case e_practice: cursor = 2; break;
		case e_burragepractice: cursor = 1; break;
		//case e_option: cursor = 4; break;
		//case e_keyconfig: cursor = 2; break;
		case e_soundtest: cursor = 2; break;
		}
		PlayMusic(music.menu);
		break;

	case e_characterselect:
		if (flag2 != e_difficultyselect) {
			cancel_flag = flag2;	//キャンセルで戻る画面を保存する
		}
		SetSelectWindow_LR(2, 2, c, c2);
		PlayMusic(music.menu);
		break;

	case e_difficultyselect:
		SetSelectWindow(3, 1);
		PlayMusic(music.menu);
		break;

	case e_gameplay:
		//SetSelectWindow(6, c);
		break;

	case e_clear:
		PlayMusic(music.result, DX_PLAYTYPE_BACK);
		SetSelectWindow(3, 0);
		time = 0;
		break;

	case e_gameover:
		PlayMusic(music.result, DX_PLAYTYPE_BACK);
		SetSelectWindow(3, 0);
		time = 0;
		break;

	case e_pause:
		//ポーズの効果音を鳴らす
		efs(efs_pause);

		SetSelectWindow(3, c);

		//音楽の中断
		StopSoundMem(p_music);
		break;

	case e_practice:
		Practice();
		SetSelectWindow(4, c);
		PlayMusic(music.menu);
		break;

	case e_burragepractice:
		BurragePractice();
		SetSelectWindow(9, c);
		PlayMusic(music.menu);
		break;

	case e_option:
		SetSelectWindow(4, c);
		break;

	case e_keyconfig:
		SetSelectWindow(6, c);
		break;

	case e_soundtest:
		SetSelectWindow_LR(7, 2, c, c2);
		break;
	}
}
