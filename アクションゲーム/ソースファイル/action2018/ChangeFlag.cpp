#include"DxLib.h"
#include"extern.h"
#include"function.h"
#include"math.h"

//フラグを変える関数
//フラグが変わった時だけにする処理を実行する
//f:フラグの種類 c:縦カーソルの位置 デフォルト引数 0 c2:横カーソルの位置 デフォルト引数 0
void change_flag(enum e_flag f, int c, int c2) {

	//最初はフェードアウトのみを行い、その後change_flag2が呼び出されてフェードインとフラグの変更を行う
	fade_flag = ef_fadeOut;
	changeFlag_flag = f;
	changeFlag_cursor = c;
	changeFlag_cursor2 = c2;

}

//フェードアウト後に実際にフラグを変える関数
//f:フラグの種類 c:縦カーソルの位置 デフォルト引数 0 c2:横カーソルの位置 デフォルト引数 0
void change_flag2(enum e_flag f, int c, int c2) {

	enum e_flag flag2 = flag;	//変更前のフラグ
	flag = f;
	switch (flag) {	//フラグの内容ごとの処理を実行する
	case e_title:
		mode_flag = em_normal;
		PlayMusic(music.menu);
		set_select_window(2, c);
		break;

	case e_stage_select:

		//難易度選択以外からステージ選択に入ったら元のフラグを保存する
		if (flag2 != e_difficulty_select) {
			cancel_flag = flag2;
		}

		PlayMusic(music.menu);
		set_select_window_LR(4, 4, c, c2);	//縦横に動かせる選択画面の設定
		break;

	case e_difficulty_select:
		set_select_window(3, c);
		break;

	case e_gameplay:

		//クリア画面からゲームプレイ画面に戻った時にエリアを変える
		if (flag2 == e_clear) {
			if (mapload % 1000 % 100 >= 40) {
				mapload = mapload / 100 * 100 + 111;//次のワールドへ
			}
			else {
				mapload = mapload / 10 * 10 + 11;//次のエリアへ
			}
		}

		//ポーズ画面から戻る時以外はステージを初期化する
		if (flag2 != e_pause) {
			ReadMap();
			PlayMusic(s_music[music_n]);	//音楽を指定された音楽にする
			init();
			init_l();	//hpの初期化
		}
		break;

	case e_clear:
		PlayMusic(music.clear, 0);
		break;

	case e_gameover:
		PlayMusic(music.gameover, 0);

		//ゲームオーバー画面がすぐに消えないようにするため例外的にここで描画する
		ClearDrawScreen();
		DrawGraph(0, 0, img.gameover, TRUE);	//ゲームオーバー画面を描画
		ScreenFlip();
		break;

	case e_pause:
		PlaySoundMem(music.pause, DX_PLAYTYPE_BACK);	//efmに修正する
		set_select_window(3, c);
		break;

		/*case option:
		set_select_window(4, c);
		break;*/

	case e_keyconfig:
		set_select_window(6, c);
		break;

		/*case e_soundtest:
		set_select_window(10, c);
		break;*/
	}
}
