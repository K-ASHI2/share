//ゲームループのフラグ
enum e_flag {
	e_createStage,
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
	KEY_ATTACK,
	KEY_PAUSE,
};

//効果音
//enum e_effectSound {
//	efs_select,		//選択の効果音
//	efs_back,		//キャンセルの効果音
//	efs_decision,	//決定の効果音
//};

