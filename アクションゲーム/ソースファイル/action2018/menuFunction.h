/*メニュー関数*/
//選択画面を設定する n:項目数 c:カーソルの位置 デフォルト引数 0
void set_select_window(int n, int c = 0);
//選択画面を設定する n:縦の項目数 n2:横の項目数 c:縦カーソルの位置 デフォルト引数 0 c2:横カーソルの位置 デフォルト引数 0
void set_select_window_LR(int n,  int n2, int c = 0, int c2 = 0);
//選択画面の操作
void select_window();
//選択画面の横操作
void select_window_LR();	
//f:フラグの種類 c:縦カーソルの位置 default 0  c2:横カーソルの位置 default 0
void change_flag(enum e_flag f, int c = 0, int c2 = 0);
//フェードアウト後に実際にフラグを変える時の処理をする関数
void change_flag2(enum e_flag f, int c = 0, int c2 = 0);
//タイトル画面のメニュー
void title();	
//ゲームオーバー画面
void gameover();
//クリア画面
void clear();
//ステージ選択画面
void stage_select();
//難易度選択画面
void difficulty_select();
//ポーズ画面
void pause();
//ステージ制作のポーズ
void createPause();
//キー入力の更新
void updateKey();
//フラグ変更時のフェードアウト
void fadeOut();
//ドアの移動のフェードアウト
void fadeOut_door();
//次の画面に進むドアのフェードアウト
void fadeOut_door2();
//フェードイン
void fadeIn();
