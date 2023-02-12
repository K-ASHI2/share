/*初期化関数*/
//ロードする関数
void Load();
//画像をロードする関数
void LoadImage();
//音楽のロード
void LoadMusic();
//敵の出現情報を読み込む関数
void LoadEmerge();
//フォントの設定
void SetFont();
//初期化関数の入り口
void init();
//プレイヤーの初期化
void init_p();
//プレイヤーのボム数の初期化
void playerBombInit();
//敵ーの初期化
void init_e();
//アイテムの初期化
void init_i();
//引数として受け取ったアイテムを初期化する
void ItemInit(int i);
//背景の初期化
void init_b();
//敵の初期化
void EnemyInit(int i);
//キーボードとゲームパッドの入力の初期化
void init_key();
//ゲームパッドのキーコンフィグの初期化
void init_key_p();
