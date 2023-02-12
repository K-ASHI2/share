#include"DxLib.h"
#include"extern.h"
#include"function.h"

//選択画面を設定する n:項目数 c:カーソルの位置 デフォルト引数 0
void CMenuWindow::setSelectWindow(int n, int c)
{
	cursor = c;		//カーソルの位置の初期化
	cursor_count = 0;		//入力の間隔の初期化
	N_o_i = n;		//縦の項目数の設定
}

//選択画面を設定する n:縦の項目数 n2:横の項目数  c:縦カーソルの位置 デフォルト 0 c2:横カーソルの位置 デフォルト 0
void CMenuWindow::setSelectWindow_LR(int n, int n2, int c, int c2)
{
	setSelectWindow(n, c);
	cursor_LR = c2;	//カーソルの位置の初期化
	N_o_i_LR = n2;	//横の項目数の設定
}

//選択画面の縦カーソルの移動
//上下の操作以外はここに書かない
void CMenuWindow::selectWindow(int mode)
{
	if (cursor_count == 0)
	{
		if ((keyPad.getButton(KEY_UP) > 0 && mode == 0) || keyPad.getButton(KEY_UP) == 1)
		{
			music.efs(efs_select);
			if (cursor > 0)
			{
				cursor--;
				cursor_count = COUNT;
			}
			else
			{
				cursor = N_o_i - 1;
				cursor_count = COUNT;
			}
		}
		if ((keyPad.getButton(KEY_DOWN) > 0 && mode == 0) || keyPad.getButton(KEY_DOWN) == 1)
		{
			music.efs(efs_select);
			if (cursor < N_o_i - 1)
			{
				cursor++;
				cursor_count = COUNT;
			}
			else
			{
				cursor = 0;
				cursor_count = COUNT;
			}
		}
	}

	if (cursor_count > 0)
	{
		cursor_count--;
	}
}

//選択画面の横カーソルの移動
//左右の操作以外はここに書かない
void CMenuWindow::selectWindow_LR()
{
	if (cursor_count == 0)
	{
		if (keyPad.getButton(KEY_LEFT) > 0)
		{
			music.efs(efs_select);
			if (cursor_LR > 0)
			{
				cursor_LR--;
				cursor_count = COUNT;
			}
			else
			{
				cursor_LR = N_o_i_LR - 1;
				cursor_count = COUNT;
			}
		}
		if (keyPad.getButton(KEY_RIGHT) > 0)
		{
			music.efs(efs_select);
			if (cursor_LR < N_o_i_LR - 1)
			{
				cursor_LR++;
				cursor_count = COUNT;
			}
			else
			{
				cursor_LR = 0;
				cursor_count = COUNT;
			}
		}
	}

	if (cursor_count > 0)
	{
		cursor_count--;
	}
}
