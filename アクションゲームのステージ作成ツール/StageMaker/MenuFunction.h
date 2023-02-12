/*メニュー関数*/

//コールバック
LRESULT CALLBACK MyWndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
//マップファイルを開くダイアログボックス
int MapFileOpen(HWND hWnd, char **pass);
//マップを保存するダイアログボックス
int MapFileSave(HWND hWnd, char **pass);
//画像ファイルを開くダイアログボックス
int ImgFileOpen(HWND hWnd);

//選択画面を設定する n:項目数 c:カーソルの位置 デフォルト引数 0
void SetSelectWindow(int n, int c = 0);
//選択画面を設定する n:縦の項目数 n2:横の項目数 c:縦カーソルの位置 デフォルト引数 0 c2:横カーソルの位置 デフォルト引数 0
void SetSelectWindow_LR(int n,  int n2, int c = 0, int c2 = 0);
//選択画面の操作
void SelectWindow();
//選択画面の横操作
void SelectWindow_LR();	
//f:フラグの種類 c:縦カーソルの位置 default 0  c2:横カーソルの位置 default 0
void ChangeFlag(enum e_flag f, int c = 0, int c2 = 0);
//フェードアウト後に実際にフラグを変える時の処理をする関数
void ChangeFlag2(enum e_flag f, int c = 0, int c2 = 0);
//ポーズ
void Pause();
//キー入力の更新
void UpdateKey();
//フラグ変更時のフェードアウト
void FadeOut();
//フェードイン
void FadeIn();
