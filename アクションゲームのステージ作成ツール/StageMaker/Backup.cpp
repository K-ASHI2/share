#include"DxLib.h"
#include"extern.h"
#include"function.h"	//共通の関数

//マップの変更の履歴を保存する
void BackUp() {

	//マップの全てを探索し、変更されていた部分があるならバックアップを取る
	for (int j = 0; j< height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			//一つ前のマップと現在作業したマップが違うか横幅が変更された場合
			if (backup[back_c][i][j] != map[i][j] || backup_w[back_c] != width_size || backup_h[back_c] != height_size) {
				if (back_c != BACK_MAX - 1)
					back_c++;//現在の参照を一つずらす
				else
					back_c = 0;//先頭のデータに上書きする
				back_top = back_c;//バックアップデータの最後尾を現在のマップにする
				if (back_top == back_head)//バックアップデータの先頭が最後尾と重なったら
					if (back_head != BACK_MAX - 1)
						back_head++;//先頭のデータは上書きされているのでback_headを一つ後ろにずらす
					else
						back_head = 0;
				for (j = 0; j< height_size; j++)
					for (i = 0; i < width_size; i++)
						backup[back_c][i][j] = map[i][j];//現在のマップをバックアップに移す
				backup_w[back_c] = width_size;
				backup_h[back_c] = height_size;
				return;
			}
		}
	}
}
