/*ステージ作成のみに用いる関数*/
//ステージ作成時のスクロールバーの移動
void MoveScrollBar();
//メニューの変更
void CSChangeMenu();
//禁止される置き方をしていたら1を返す関数
int ProhibitCheck();
//マップの保存
void SaveMap();
//マップを一つ前の状態に戻す
void UndoMap();
//マップを一つ次の状態に戻す
void RedoMap();
//選択中の物を切り取る
void TrimmingMap();
//選択中の物をコピーする
void CopyMap();
//選択中の物を貼り付ける
void PasteMap();
//選択中の物を消去する
void DeleteMap();
//画面サイズの変更
bool ChangeMapSize(int x, int y, int width, int height);
//マップの変更の履歴を保存する
void BackUp();

//編集可能な画面内の幅を求めて返す
int GetDrawWidth();
//編集可能な画面内の高さを求めて返す
int GetDrawHeight();

//受け取った数字xのn桁目をfの数字に書き換えて返す
int FigureChange(int x, int n, int f);

/*ボタン処理*/
//X座標,Y座標,文字の数,数字の数,色 文字数に合うサイズのボタンを生成する
void DrawButton(int x, int y, int s, int n, unsigned int Color);
//速さのボタンの処理 座標と数字を受け取りその座標と数字を表示する
void DrawButton2(int x, int y, const char *c);
//左右のボタンの処理 座標と文字と何番目かを受け取りその座標と文字を表示する
void DrawButton3(int x, int y, const char *c, int b);
//正方形のボタンを作る
int DrawButton4(int x, int y);
//大きさが可変なボタンを作る
int DrawButton4(int x, int y, int size_x, int size_y);
//座標、画像、向きを受け取って描画する
void DrawCreate(int x, int y, int GrHandle, int d);
//ボタンのxy座標、文字の数、数字の数を受け取り押されていなければ0、押されていれば1を返す
int JudgeMouse(int x, int y, int s, int n);
//ボタンの4つの頂点の座標を受け取り、押されていなければ0、押されていれば1を返す
int JudgeMouse2(int x1, int y1, int x2, int y2);
//ボタンのxy座標、文字の数、数字の数を受け取りマウスの変わりにsxとsyで判定する
int JudgeMouse3(int x, int y, int s, int n);
//ボタンのxy座標、文字の数、数字の数を受け取り1フレーム前のマウスの座標で判定する
int JudgeMouse4(int x, int y, int s, int n);