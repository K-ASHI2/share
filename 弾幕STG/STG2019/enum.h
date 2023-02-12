//ループ管理のフラグ
//一つの選択画面につき一つ作る
//ゲームプレイ中のフラグは別に作る
enum e_flag {
	e_title,
	e_characterselect,
	e_difficultyselect,
	e_gameplay,
	e_gameover,
	e_clear,
	e_pause,
	e_practice,
	e_burragepractice,
	e_option,
	e_keyconfig,
	e_soundtest,
};

//弾の種類(外見)
enum eb_kind {
	ebk_blue_S,		//青小弾
	ebk_red_S,		//赤小弾
	ebk_yellow_S,	//黄小弾
	ebk_blue_M,		//青中弾
	ebk_red_M,		//赤中弾
	ebk_yellow_M,	//黄中弾
	ebk_blue_L,		//青大弾
	ebk_red_L,		//赤大弾
	ebk_yellow_L,	//黄大弾
	ebk_snow_S,		//雪小弾
	ebk_snow_M,		//雪中弾
	ebk_fire_S,		//炎小弾
	ebk_fire_M,		//炎中弾
	ebk_thunder,	//雷弾
	ebk_star,		//星弾
	ebk_star_red,	//赤星弾
	ebk_star_blue,	//青星弾
};

//弾の色(消滅時に使用)
enum eb_color {
	ebc_blue,
	ebc_red,
	ebc_yellow,
	ebc_null,
};

//アイテムの種類(外見)
enum ei_kind {
	eik_power_S,	//小P
	eik_power_L,	//大P
	eik_power_F,	//フルパワーアイテム
	eik_score_S,	//得点アイテム(小)
	eik_score,		//得点アイテム
	eik_bomb,		//ボムアイテム
	eik_life,		//エクステンドアイテム
};

//難易度のフラグ
enum e_difficulty {
	ed_easy,
	ed_normal,
	ed_hard,
	ed_lunatic,
};

//ステージ
enum e_stage {
	es_title,	//サウンドテストでタイトル曲を流せるようにする
	es_1_1,
	es_1_2,
	es_2_1,
	es_2_2,
	es_3_1,
	es_3_2,
	es_4_1,
	es_4_2,
	es_e_1,
	es_e_2,
};

//ワールド
enum e_world {
	ew_1,
	ew_2,
	ew_3,
	ew_4,
	ew_extra,
};

enum e_bossflag {
	eb_way,		//道中
	eb_boss,	//ボス
};

//ゲームモードのフラグ
enum e_mode {
	em_normal,		//通常モード
	em_practice,	//プラクティス
	em_burragepractice,	//スペルプラクティス
	em_end,			//ゲームを終了する
};

//フェードアウトのフラグ
enum e_fade {
	ef_normal,			//通常モード
	ef_fadeOut,			//フラグ変更時のフェードアウト
	ef_fadeIn,			//フェードイン
};

//実際のゲームで使うボタン
//キーボードとゲームパッドの入力の両方に対応し、
//キーコンフィグで設定後はボタンが変化する
enum e_key {
	KEY_DOWN,
	KEY_LEFT,
	KEY_RIGHT,
	KEY_UP,
	KEY_SHOT,
	KEY_BOMB,
	KEY_SLOW,
	KEY_PAUSE,
};

//効果音
enum e_effectSound {
	efs_shot,		//攻撃の効果音
	efs_select,		//選択の効果音
	efs_recover,	//回復の効果音
	efs_bomb,		//大砲発射の効果音
	efs_p_bomb,		//大砲発射の効果音
	efs_back,		//キャンセルの効果音
	efs_result,
	efs_decision,	//決定の効果音
	efs_damage,
	efs_boss_crush,
	efs_pause,
};
