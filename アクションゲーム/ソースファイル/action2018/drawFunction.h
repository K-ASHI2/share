/*描画関数*/
//1フレーム毎の描画
void draw();
//タイトル画面の描画
void drawTitle();
//ゲームプレイ中の描画
void drawPlay();
//座標、画像、向きを受け取って描画する dが1なら左、2なら右
void DrawGraph2(int x, int y, int GrHandle, int d);
//ステージ選択の描画
void drawStageSelect();
//難易度選択の描画
void drawDifficultySelect();
//ステージの描画
void drawStage();
//ポーズ画面の描画
void drawPause();
//背景の描画
void draw_background();
//指定した時間だけ画面が切り替わる時に真っ暗にする
void black_screen(int t);
//x座標,y座標,文字列、何番目かを引数とし、カーソルの位置が同じなら赤、違うなら黒で描画する関数
void DrawRed(int x, int y, const TCHAR *String, int c);
//x座標,y座標,文字列、縦横に何番目かを引数とし、カーソルの位置が同じなら赤、違うなら黒で描画する関数
void DrawRed2(int x, int y, const TCHAR *String, int c, int c2);
