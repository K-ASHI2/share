#include"DxLib.h"
#include"extern.h"
#include"function.h"

//キーコンフィグ
void CMenuWindow::keyConfig()
{
	selectWindow();
	if (keyPad.getButton(KEY_SHOT) == 1)
	{
		//リセット
		if (cursor == N_o_i - 2)
		{
			keyPad.init();
			music.efs(efs_decision);
		}
		//タイトルに戻る
		else if (cursor == N_o_i - 1)
		{
			changeFlag(e_title, 1);
			music.efs(efs_back);
		}
	}

	//キーボード入力のみ
	if (keyPad.getKey(KEY_INPUT_X) == 1 && cursor_count == 0)
	{
		cursor = N_o_i - 1;	//カーソルを一番下にする
		cursor_count = 12;
		music.efs(efs_back);
	}

	//カーソルを合わせた位置でゲームパッドのボタンを押すとパッドのボタンが設定される
	//上下左右を除いた塗る、キャンセル、ポーズのみに関して行う
	if (cursor < 3)
	{
		//cursorに合った処理はkeyPad側で行う
		keyPad.setKeyConfig(cursor);
	}
}

//キーコンフィグの描画
void CMenuWindow::drawKeyConfig()
{
	const static int green = font.getGreen();

	DrawGraph(0, 0, img.title, TRUE);
	//上下左右は変更する必要はない
	drawRed(100, 100, "DRAW", 0);
	drawRed(100, 150, "DROP", 1);
	drawRed(100, 200, "PAUSE", 2);
	drawRed(100, 250, "RESET", 3);
	drawRed(100, 300, "QUIT", 4);//選択中の項目に関する説明

	//4～6のボタンが変更できる
	for (int i = 4; i < 7; i++)
	{
		//ボタンに対応したchar
		drawRed(300, 100 + (i - 4) * 50, keyPad.getCPad(i), i - 4);
	}

	DrawString(100, 500, "ゲームパッドでボタンを押すと設定できます", green);
	switch (cursor) {
	case 0:	DrawString(100, 550, "塗るボタン", green); break;
	case 1:	DrawString(100, 550, "ブロックを落下させるボタン", green); break;
	case 2:	DrawString(100, 550, "ポーズボタン", green); break;
	case 3:	DrawString(100, 550, "ボタン配置をデフォルトに戻します", green); break;
	case 4: DrawString(100, 550, "タイトル画面に戻ります", green); break;
	}
}
