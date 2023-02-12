/*メニュー関数*/
//選択画面を設定する n:項目数 c:カーソルの位置 デフォルト引数 0
void SetSelectWindow(int n, int c = 0);
//選択画面を設定する n:縦の項目数 n2:横の項目数 c:縦カーソルの位置 c2:横カーソルの位置
void SetSelectWindow_LR(int n, int n2, int c = 0, int c2 = 0);
//選択画面の縦操作 mode:1なら押し続けて移動しない デフォルト引数 0
void SelectWindow(int mode = 0);	
//選択画面の横操作
void SelectWindow_LR();
//タイトル画面
void Title();
//キャラ選択画面
void CharacterSelect();
//難易度選択
void DifficultySelect();
//ポーズ画面
void Pause();
//ゲームオーバー画面
void GameOver();
//クリア画面
void Clear();
//プラクティス
void Practice();
//弾幕プラクティス
void BurragePractice();
//オプション
void Option();
//キーコンフィグ
void KeyConfig();
//サウンドテスト
void SoundTest();
//f:フラグの種類 c:縦カーソルの位置 default 0  c2:横カーソルの位置 default 0
void ChangeFlag(enum e_flag f, int c = 0, int c2 = 0);
//フェードアウト後に実際にフラグを変える時の処理をする関数
void ChangeFlag2(enum e_flag f, int c = 0, int c2 = 0);
//フラグごとのフォントを決める
void flagSetFont();


