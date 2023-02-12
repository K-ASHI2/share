#include"DxLib.h"
#include"extern.h"
#include"function.h"

//select_thingの配列の添え字
//外部から呼び出すとバグるので良くないが、作業量を減らすために用いている
static int si;

//ステージに置く物の初期化
void LoadSelectThings() {

	for (int i = 0; i < MAX_THINGS; i++) {

		//使わない部分も余分に配列を取っているので全部初期化する
		select_description[i] = "未設定";

		//大きさ1に初期化する
		SetSelectShift(i, 0, 0, 0, 0);
	}

	//マップ上の番号からselect_thingの配列の添え字の初期化
	map_si[0] = 0;

	for (int i = 1; i < MAX_THINGS; i++) {
		map_si[i] = -1;
	}

	si = 0;

	//敵
	//1～100:普通の敵 101～200:倒せない敵 251～299:ボス
	SetSelectThing(12001, img.enemy[2], "横に動いて落ちる敵");
	SetSelectThing(12002, img.enemy[7], "穴の手前で方向転換");
	SetSelectThing(12003, img.enemy[4], "飛び跳ねる敵");
	SetSelectThing(14004, img.enemy[1], "横に往復する敵");
	SetSelectThing(14005, img.enemy[3], "縦に往復する敵");
	SetSelectThing(14006, img.enemy[6], "円運動する敵", false, false);
	SetSelectThing(12007, img.fish, "画面外まで上下する敵");
	SetSelectThing(12008, img.redghost_S, "上下に揺れる敵");
	SetSelectThing(12009, img.enemy[5], "壁で反射する敵");
	SetSelectThing(12010, img.enemy[12], "ジャンプすると飛ぶ敵");
	SetSelectThing(14011, img.ghost_S, "追いかける敵");
	SetSelectThing(14012, img.blueghost_S, "ランダムに動きつつ追いかける敵");
	SetSelectThing(12013, img.enemy[32], "正面に弾を撃つ敵");
	SetSelectThing(14014, img.enemy[35], "縦往復自機狙い弾");
	SetSelectThing(14015, img.enemy[33], "縦往復して正面に弾", false, false);
	SetSelectThing(14016, img.enemy[34], "円運動して正面に弾", false, false);
	SetSelectThing(14017, img.cloud_monster_blue, "氷を飛ばす");
	SetSelectThing(14018, img.cloud_monster, "下に雷を飛ばす");
	SetSelectThing(100, img.togeblock4, "止まっているトゲ");
	SetSelectThing(14101, img.togeblock2, "横に動くトゲ");
	SetSelectThing(14102, img.togeblock3, "縦に動くトゲ");
	SetSelectThing(14103, img.togeblock, "円運動するトゲ", false, false);
	SetSelectThing(14251, img.boss[1], "ボス1");
	SetSelectThing(14252, img.boss[3], "ボス2");

	si_block = si;
	cs_max_page[1] = (si_block - 1) / (10 * 2) + 1;

	//ブロック
	//301～500:普通のブロック 501～600:特殊な判定のブロック 601～699:大砲など
	SetSelectThing(301, img.yuka[1], "ブロック1");
	SetSelectThing(302, img.yuka[2], "ブロック2");
	SetSelectThing(303, img.yuka[3], "ブロック3");
	SetSelectThing(304, img.yuka[4], "ブロック4");
	SetSelectThing(305, img.yuka[0], "ブロック5");
	SetSelectThing(306, img.yuka[8], "ブロック6");
	SetSelectThing(307, img.kabe, "床");
	SetSelectThing(308, img.block_gray, "ブロック7");
	SetSelectThing(309, img.block_wood, "ブロック8");
	SetSelectThing(500, img.through, "すり抜け床");
	SetSelectThing(501, img.toge, "トゲブロック");
	SetSelectThing(502, img.block2, "壊れる壁");
	SetSelectThing(30503, img.moveblock[0], "3秒後に消えるブロック");
	SetSelectThing(2504, img.moveblock[4], "横に動く床");
	SetSelectThing(2505, img.moveblock[7], "縦に動く床");
	SetSelectThing(2506, img.moveblock[6], "画面外まで上下する床");
	SetSelectThing(507, img.iceblock, "氷の床");
	SetSelectThing(601, img.taihou[2], "自機狙い弾を撃つ大砲");
	SetSelectThing(602, img.taihou[1], "左に弾を撃つ大砲");
	SetSelectThing(603, img.taihou[1], "右に弾を撃つ大砲", true);
	SetSelectThing(604, img.taihou[4], "上に弾を撃つ大砲");
	SetSelectThing(605, img.taihou[3], "下に弾を撃つ大砲");
	SetSelectThing(606, img.taihou[5], "左上に弾を撃つ大砲");
	SetSelectThing(607, img.taihou[5], "右上に弾を撃つ大砲", true);
	SetSelectThing(608, img.taihou[6], "左下に弾を撃つ大砲");
	SetSelectThing(609, img.taihou[6], "右下に弾を撃つ大砲", true);

	si_etc = si;
	cs_max_page[2] = (si_etc - si_block - 1) / (10 * 2) + 1;

	//その他
	//701～800:スイッチなどの仕掛け 801～900:扉 901～997:アイテム
	SetSelectThing(701, img.sw[0], "赤スイッチ");
	SetSelectThing(702, img.sw[1], "緑スイッチ");
	SetSelectThing(703, img.swb[0], "赤スイッチで出る床");
	SetSelectThing(704, img.swb[1], "緑スイッチで出る床");
	SetSelectThing(705, img.firebar, "ファイアバー", false, false);
	SetSelectThing(706, img.meteor, "炎");
	SetSelectThing(707, img.star, "黄星が落ちてくる場所");
	SetSelectThing(708, img.star_blue, "青星が落ちてくる場所");
	SetSelectThing(709, img.star_red, "赤星が落ちてくる場所");
	SetSelectThing(801, img.door[3], "ゴールの扉");
	SetSelectThing(901, img.item, "アイテム");
	SetSelectThing(20902, img.max_item, "全快アイテム");

	//昔のステージの99を書き換える用
	SetSelectThing(999, img.hito[6], "プレイヤー");


	//多分使わないで違う敵にする
	SetSelectThing(12990, img.enemy[21], "大きい敵");
	SetSelectThing(12991, img.enemy[11], "縦長の敵");
	SetSelectThing(12992, img.enemy[16], "横長の敵");

	si_etc_end = si;

	//置くもの以外の設定
	//SetSelectThing(999, img.hito[6], "プレイヤー");

	cs_max_page[3] = (si_etc_end - si_etc - 1) / (10 * 2) + 1;

	//残りを全部nullにする
	for (; si < MAX_THINGS; si++) {
		SetSelectThing2(si, 998, img.null);
	}
}

//select_thingのセット(説明付き、LoadSelectThingsから以外の呼出し禁止)
void SetSelectThing(int number, int GrHandle, char *description, bool turn, bool drawflag) {

	SetSelectThing(number, GrHandle, turn, drawflag);
	//引数の番号を持つ物が選ばれた時にその説明を描画する
	select_description[number % 1000] = description;
}

//select_thingのセット(LoadSelectThingsから以外の呼出し禁止)
void SetSelectThing(int number, int GrHandle, bool turn, bool drawflag) {

	SetSelectThing2(si, number, GrHandle, turn, drawflag);
	si++;
}

//select_thingのセット(番号指定あり)
void SetSelectThing2(int i, int number, int GrHandle, bool turn, bool drawflag) {

	select_thing[i].number = number;
	select_thing[i].GrHandle = GrHandle;
	select_thing[i].turn = turn;
	select_thing[i].drawflag = drawflag;

	//マップ上の番号からselect_thingの配列の添え字を逆引きできるようにする
	map_si[number % 1000] = i;
}

//通常より判定の大きさをずらす場合の設定
void SetSelectShift(int i, int l_shift, int r_shift, int u_shift, int d_shift) {

	select_thing[i].l_shift = l_shift;
	select_thing[i].r_shift = r_shift;
	select_thing[i].u_shift = u_shift;
	select_thing[i].d_shift = d_shift;
}