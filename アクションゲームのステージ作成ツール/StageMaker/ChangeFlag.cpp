#include"DxLib.h"
#include"extern.h"
#include"function.h"

//フラグを変える関数
//フラグが変わった時だけにする処理を実行する
//f:フラグの種類 c:縦カーソルの位置 デフォルト引数 0 c2:横カーソルの位置 デフォルト引数 0
void ChangeFlag(enum e_flag f, int c, int c2) {

	//最初はフェードアウトのみを行い、その後change_flag2が呼び出されてフェードインとフラグの変更を行う
	fade_flag = ef_fadeOut;
	changeFlag_flag = f;
	changeFlag_cursor = c;
	changeFlag_cursor2 = c2;
}

//フェードアウト後に実際にフラグを変える関数
//f:フラグの種類 c:縦カーソルの位置 デフォルト引数 0 c2:横カーソルの位置 デフォルト引数 0
void ChangeFlag2(enum e_flag f, int c, int c2) {

	enum e_flag flag2 = flag;	//変更前のフラグ
	flag = f;
	//フラグの内容ごとの処理を実行する
	switch (flag) {
	case e_createStage:
		PM_Number();	//背景に合った音楽を鳴らす
		break;
	}
}
