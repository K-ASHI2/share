#include"DxLib.h"
#include"extern.h"
#include"function.h"

//説明
void CMenuWindow::manual()
{
	selectWindow();

	//キャンセル
	if (keyPad.getButton(KEY_CANCEL) == 1)
	{
		cursor = N_o_i - 1;	//カーソルを一番下にする
		music.efs(efs_back);
	}

	//決定
	if (keyPad.getButton(KEY_SHOT) == 1)
	{
		if (cursor == N_o_i - 1)
		{
			changeFlag(e_title);
			music.efs(efs_decision);
		}
	}
}

//キーコンフィグの描画
void CMenuWindow::drawManual()
{
	const static int green = font.getGreen();
	const static int font0 = font.getFont(0);
	DrawGraph(0, 0, img.title, TRUE);
	drawRed(100, 100, "操作について", 0);
	drawRed(100, 150, "ブロックの落下", 1);
	drawRed(100, 200, "レベルについて", 2);
	drawRed(100, 250, "連鎖とスコア", 3);
	drawRed(100, 300, "勝つためのコツ", 4);
	drawRed(100, 350, "タイトルに戻る", 5);
	
	switch (cursor) {
	case 0:
		DrawStringToHandle(320, 60, "上下左右で移動します。", green, font0);
		DrawStringToHandle(320, 90, "塗るボタンを押すとカーソルの色を塗り、", green, font0);
		DrawStringToHandle(320, 120, "NEXTの下の色がカーソルの色となる。", green, font0);
		DrawStringToHandle(320, 150, "NEXTは5連続で出ない色があると", green, font0);
		DrawStringToHandle(320, 180, "その色が次に確定で出現する。", green, font0);
		DrawStringToHandle(320, 210, "ドロップボタンを押すと色ブロックを", green, font0);
		DrawStringToHandle(320, 240, "手動で落下できる。", green, font0);
		DrawStringToHandle(320, 270, "ドロップボタンの落下では、次のブロック", green, font0);
		DrawStringToHandle(320, 300, "落下までの時間はリセットされる。", green, font0);
		DrawStringToHandle(320, 330, "白ブロックは塗ることはできるが、", green, font0);
		DrawStringToHandle(320, 360, "そのままでは揃っても消えない。", green, font0);
		DrawStringToHandle(320, 390, "塗っている途中のブロックや", green, font0);
		DrawStringToHandle(320, 420, "消滅中のブロックは落下しない。", green, font0);
		break;

	case 1:
		DrawStringToHandle(320, 60, "ブロック落下間隔はレベルが高いほど短くなる。", green, font0);
		DrawStringToHandle(320, 90, "色ブロックは6列全て、中央4列のみの", green, font0);
		DrawStringToHandle(320, 120, "2通りで交互に落下する。", green, font0);
		DrawStringToHandle(320, 150, "初期配置、画面外から落下するブロックは", green, font0);
		DrawStringToHandle(320, 180, "落下後に揃わない配置で出現する。", green, font0);
		DrawStringToHandle(320, 210, "白ブロックは色ブロックの落下の1/4の合間に", green, font0);
		DrawStringToHandle(320, 240, "攻撃が残っているなら一列分だけ落下する。", green, font0);
		DrawStringToHandle(320, 270, "白ブロックは一列分の6個を一度に落とさない", green, font0);
		DrawStringToHandle(320, 300, "限り、低い列を優先して落ちる。", green, font0);
		DrawStringToHandle(320, 330, "画面外にブロックが置かれてから", green, font0);
		DrawStringToHandle(320, 360, "0.5秒経つと敗北となる。", green, font0);
		break;
	case 2:
		DrawStringToHandle(320, 60, "レベルは最大99まで上がる。", green, font0);
		DrawStringToHandle(320, 90, "スコアを10万稼ぐ毎に相手プレイヤーの", green, font0);
		DrawStringToHandle(320, 120, "レベルが一つ上がる。", green, font0);
		DrawStringToHandle(320, 150, "レベル50まではレベルが一つ上がる毎に2/60秒、", green, font0);
		DrawStringToHandle(320, 180, "レベル51～99はレベルが一つ上がる毎に1/60秒", green, font0);
		DrawStringToHandle(320, 210, "ブロックの落下間隔の時間が短くなる。", green, font0);
		break;
	case 3:
		DrawStringToHandle(320, 60, "ブロックを消すと、200点が加算される。", green, font0);
		DrawStringToHandle(320, 90, "4つ以上同時に消すと、(消した数 - 3)×2個の", green, font0);
		DrawStringToHandle(320, 120, "白ブロックが送られる。", green, font0);
		DrawStringToHandle(320, 150, "4つ以上消した部分のスコアは1つにつき", green, font0);
		DrawStringToHandle(320, 180, "500点がさらに加算される。", green, font0);
		DrawStringToHandle(320, 210, "ブロックを消した時、上に乗っているブロック", green, font0);
		DrawStringToHandle(320, 240, "全てが連鎖対象となる。", green, font0);
		DrawStringToHandle(320, 270, "連鎖すると、高いスコアの獲得と白ブロックを", green, font0);
		DrawStringToHandle(320, 300, "送ることができる。", green, font0);
		DrawStringToHandle(320, 330, "白ブロックの数は2連鎖以上の時、", green, font0);
		DrawStringToHandle(320, 360, "連鎖数 + 2個が送られる。", green, font0);
		DrawStringToHandle(320, 390, "消した個数による得点の合計に", green, font0);
		DrawStringToHandle(320, 420, "(連鎖数 - 1)×8の倍率をかける。", green, font0);
		break;
	case 4:
		DrawStringToHandle(320, 60, "白青青黄黄白", green, font0);
		DrawStringToHandle(320, 90, "白赤赤青青黄", green, font0);
		DrawStringToHandle(320, 120, "上のように塗り、赤を消すと3連鎖までは", green, font0);
		DrawStringToHandle(320, 150, "簡単に組める。", green, font0);
		DrawStringToHandle(320, 180, "4連鎖以上なら縦に連鎖をつなげる必要がある。", green, font0);
		DrawStringToHandle(320, 210, "また、消滅中のブロックの上のブロックは", green, font0);
		DrawStringToHandle(320, 240, "落下始める前なら何度も塗れるので、", green, font0);
		DrawStringToHandle(320, 270, "連鎖を無理矢理つなげることもできる。", green, font0);
		DrawStringToHandle(320, 300, "3連鎖で1列、4連鎖で2列、2連鎖と同時消し", green, font0);
		DrawStringToHandle(320, 330, "1回で1列以上送れる。", green, font0);
		DrawStringToHandle(320, 360, "一列以上送ると高い列にも送れるので", green, font0);
		DrawStringToHandle(320, 390, "強い妨害となる。", green, font0);
		DrawStringToHandle(320, 420, "端の列は消しにくいので、", green, font0);
		DrawStringToHandle(320, 450, "ある程度意識すると良いかも。", green, font0);
		break;
	case 5: break;
	}


}
