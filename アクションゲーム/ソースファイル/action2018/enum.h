//ゲームループのフラグ
enum e_flag {
	e_title,
	e_difficulty_select,
	e_stage_select,
	e_clear,
	e_gameplay,
	e_gameover,
	e_pause,
	e_keyconfig,
};

//ゲームモードのフラグ
enum e_mode {
	em_normal,		//通常モード
	em_end,			//ゲームを終了する
};

//フェードアウトのフラグ
enum e_fade {
	ef_normal,			//通常モード
	ef_fadeOut,			//フラグ変更時のフェードアウト
	ef_fadeOut_door,	//扉移動中のフェードアウト
	ef_fadeOut_door2,	//次の画面に進むドアのフェードアウト
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
	KEY_JUMP,
	KEY_JUMP2,
	KEY_ATTACK,
	KEY_ATTACK2,
	KEY_PAUSE,
};

//効果音
enum e_effectSound {
	efs_attack,		//攻撃の効果音
	efs_select,		//選択の効果音
	efs_recover,	//回復の効果音
	efs_bomb,		//大砲発射の効果音
	efs_back,		//キャンセルの効果音
	efs_decision,	//決定の効果音
	efs_shot,		//敵の弾を出す時の音
};

//背景
enum e_background {
	eb_sky,			//青空
	eb_cave,		//洞窟
	eb_darkcave,	//暗い洞窟
	eb_darkcloud,	//暗雲
	eb_line,		//紫と水色のライン
	eb_orange,		//オレンジ
	eb_check,		//チェック
};
