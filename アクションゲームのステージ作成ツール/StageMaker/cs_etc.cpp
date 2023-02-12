#include"DxLib.h"
#include"math.h"
#include"extern.h"
#include"function.h"	//共通の関数

//受け取った数字xのn桁目をfの数字に書き換えて返す
int FigureChange(int x, int n, int f) {

	double dn = (double)n;
	int a = x / (int)pow(10.0, dn);	//n桁目より上の位をaに保存する
	int b = x % (int)pow(10.0, dn - 1.0);	//n桁目より下の位をbに保存する
	return(a * (int)pow(10.0, dn) + f * (int)pow(10.0, dn - 1.0) + b);	//n桁目にfを持ってきて残りは元に戻す
}

//メニューの変更
void CSChangeMenu() {

	//それぞれのメニューが押されていれば、そのメニューに変更する
	for (int i = 0; i < 4; i++) {
		if (JudgeMouse2(0 + 142 * i, 500, 136 + 142 * i, 525)) {
			//現在と違うメニューが押されたならメニューを変更し、その前のカーソルは消える
			if (menu_b != i + 1) {
				menu_b = i + 1;
				sx = -1;
				sy = -1;
				sx2 = -1;
				sy2 = -1;
				cs_map = 0;
				break;	//一度に複数のメニューは押されないのでbreakする
			}
		}
	}
}

//禁止される置き方をしていたら1を返す関数
int ProhibitCheck() {

	//開始直後にゲームオーバーになるならバックアップを取る前に戻す
	//プレイヤーの初期座標が画面内に存在しない
	//プレイヤーの初期座標の上が壁になっている
	for (int j = 0; j < height_size - 1; j++) {
		for (int i = 0; i < width_size; i++) {
			//主人公の座標があるなら
			if (map[i][j] % 1000 == 999) {
				//主人公の足の座標に何か物が重なっている
				if (map[i][j + 1] % 1000 != 0) {
					return 1;
				}
				//プレイヤーの初期座標の下に上に動く床がある
				if (j < height_size - 2) {
					if ((map[i][j + 2] % 1000 == 12 || map[i][j + 2] % 1000 == 48) && map[i][j + 2] % 100000 / 10000 == 1) {
						return 1;
					}
				}
				//プレイヤーの初期座標の上に下に動く床がある
				if (j > 1) {
					if ((map[i][j - 1] % 1000 == 12 || map[i][j - 1] % 1000 == 48) && map[i][j - 1] % 100000 / 10000 == 2) {
						return 1;
					}
				}
				//プレイヤーの初期座標の左に右に動く床がある
				if (i > 1) {
					if (map[i - 1][j] % 1000 == 6 && map[i - 1][j] % 100000 / 10000 == 2 || map[i - 1][j + 1] % 1000 == 6 && map[i - 1][j + 1] % 100000 / 10000 == 2) {
						return 1;
					}
				}
				//プレイヤーの初期座標の右に左に動く床がある
				if (i < width_size - 1) {
					if (map[i + 1][j] % 1000 == 6 && map[i + 1][j] % 100000 / 10000 == 1 || map[i + 1][j + 1] % 1000 == 6 && map[i + 1][j + 1] % 100000 / 10000 == 1) {
						return 1;
					}
				}
				return 0;
			}
			
		}
	}
	//主人公の座標が無い
	return 1;
}

//マップの保存
void SaveMap() {

	//map[0][height_size] = background_n;//マップの一番下の列の左端に背景の番号を書き込む
	WriteMap();	//マップのファイルに書き込む
	MessageBox(hMainWnd, "セーブしました", "STAGE MAKER", MB_OK);
}

//マップを一つ前の状態に戻す
void UndoMap() {

	if (back_c != back_head) {		//先頭でなければ戻る
		if (back_c != 0)
			back_c--;
		else
			back_c = BACK_MAX - 1;
		width_size = backup_w[back_c];	//横幅を戻す
		height_size = backup_h[back_c];	//横幅を戻す
		for (int j = 0; j < height_size; j++)
			for (int i = 0; i < width_size; i++)
				map[i][j] = backup[back_c][i][j];	//マップの全ての座標を元に戻す
		if (stage_x > width_size * block_size - WINDOW_WIDTH)
			stage_x = width_size * block_size - WINDOW_WIDTH;	//カーソルを右端にする
	}
}

//マップを一つ次の状態にする
void RedoMap() {
	
	if (back_c != back_top) {	//最後尾でなければ進む
		if (back_c != BACK_MAX - 1)
			back_c++;
		else
			back_c = 0;
		width_size = backup_w[back_c];	//横幅を進める
		height_size = backup_h[back_c];	//横幅を進める
		for (int j = 0; j < height_size; j++){
			for (int i = 0; i < width_size; i++) {
				map[i][j] = backup[back_c][i][j];	//マップの全ての座標を進める
			}
		}
		if (stage_x > width_size * block_size - WINDOW_WIDTH)
			stage_x = width_size * block_size - WINDOW_WIDTH;	//カーソルを右端にする
	}
}

//選択中の物を切り取る
void TrimmingMap() {

	if (sx >= 0 && sy >= 0) {
		mc = map[sx][sy];
		map[sx][sy] = 0;
	}
}

//選択中の物をコピーする
void CopyMap() {

	if (sx >= 0 && sy >= 0) {
		mc = map[sx][sy];
	}
}

//選択中の物を貼り付ける
void PasteMap() {

	if (sx >= 0 && sy >= 0) {
		map[sx][sy] = mc;
	}
}

//選択中の物を消去する
void DeleteMap() {

	if (sx >= 0 && sy >= 0) {
		map[sx][sy] = 0;
	}
}

//画面サイズの変更
bool ChangeMapSize(int x, int y, int width, int height) {

	if (width <= 0 || height <= 0) {
		MessageBox(hMainWnd, "0以下は入力できません。", "警告", MB_OK);
		return false;
	}
	else if (width > MAX_WIDTH) {
		MessageBox(hMainWnd, "横幅が大きすぎます。", "警告", MB_OK);
		return false;
	}
	else if (height > MAX_HEIGHT) {
		MessageBox(hMainWnd, "縦幅が大きすぎます。", "警告", MB_OK);
		return false;
	}

	int map2[MAX_WIDTH][MAX_HEIGHT];

	//現在のマップをコピーし退避させる
	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			map2[i][j] = map[i][j];
		}
	}
	//一度全てのマップを空にする
	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
			map[i][j] = 0;
		}
	}
	int i = 0;
	int j = 0;
	//x,yが負の数の場合x+iやy+jが負にならないようにする
	if (x < 0) {
		i = -x;
	}
	if (y < 0) {
		j = -y;
	}
	//(x,y)の地点を左上としてマップをコピーする
	for (int j = 0; j < height_size; j++) {
		//新しくできる画面の縦幅を超えないようにする
		if (y + j > height) {
			break;
		}
		for (int i = 0; i < width_size; i++) {
			//新しくできる画面の横幅を超えないようにする
			if (x + i > width) {
				break;
			}
			map[x + i][y + j] = map2[i][j];
		}
	}
	height_size = height;
	width_size = width;
	stage_x = 0;	//スクロールを左端へ
	stage_y = height_size * block_size - WINDOW_HEIGHT;	//スクロールを一番下へ

	return true;
}
