/*描画関数*/
//1フレーム毎の描画
void Draw();
//ステージの描画
void DrawStage();
//背景の描画
void DrawBackground();
//指定した時間だけ画面が切り替わる時に真っ暗にする
void BlackScreen(int t);
//x座標,y座標,文字列、何番目かを引数とし、カーソルの位置が同じなら赤、違うなら黒で描画する関数
void DrawRed(int x, int y, const TCHAR *String, int c);
//x座標,y座標,文字列、縦横に何番目かを引数とし、カーソルの位置が同じなら赤、違うなら黒で描画する関数
void DrawRed2(int x, int y, const TCHAR *String, int c, int c2);

//メニューの描画
void DrawCSMenu();
//ステージ作成のマップの描画
void DrawMap();
//マップの値を受け取って表示する
void DrawMapThings(int x, int y, int map);
//マップの奥に描画したいものを描画する
void DrawMapThings2(int x, int y, int map);
//マップの手前に描画したいものを描画する
void DrawMapThings3(int x, int y, int map);
//マップのさらに手前に描画したいものを描画する
void DrawMapThings4(int x, int y, int map);
//座標、画像を受け取って描画する
void MapDrawExtendGraph(int x1, int y1, int GrHandle, int TransFlag);
//座標、画像、透過フラグを受け取って描画する
void MapDrawExtendGraph(int x1, int y1, int GrHandle);
//座標、画像と透過フラグを受け取って置く物の画像を描画する
void DrawSelectThing(int x1, int y1, int GrHandle, bool turn, int TransFlag = TRUE);
//座標、画像を受け取って置く物の画像を描画する
void DrawSelectThing(int x1, int y1, int GrHandle);
//座標、画像(、透過フラグ)を受け取って置く物の画像を反転して描画する
void DrawTurnSelectThing(int x1, int y1, int GrHandle, int TransFlag = TRUE);
