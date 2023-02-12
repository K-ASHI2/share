/*描画関係関数*/
void Draw();
//ゲームプレイ中の画面の描画
void DrawPlay();
//タイトル画面の描画
void DrawTitle();
//キャラクター選択画面の描画
void DrawCharacterSelect();
//難易度選択画面の描画
void DrawDifficultySelect();
//プラクティスの描画
void DrawPractice();
//弾幕プラクティスの描画
void DrawBulletPractice();
//オプションの描画
void DrawOption();
//キーコンフィグの描画
void DrawKeyConfig();
//ポーズ画面の描画
void DrawPause();
//クリア画面の描画
void DrawClear();
//ゲームオーバー画面の描画
void DrawGameover();
//消滅することが確定している敵や弾に対して消滅エフェクトを描画する。
void DrawVanished();
//背景の描画
void DrawBackGround();
//ゲームプレイ中の画面外の描画
void DrawPlayWindow();
//サウンドテストの描画
void DrawSoundTest();
//HPバーの描画
void DrawHPBar();
//属性のバーの描画
void DrawElementBar();
//敵の体力に応じたHPバーの色を返す関数
int GetHPColor(int hp, int maxhp);
//操作説明の描画
void DrawEx();
//x座標,y座標,文字列、何番目かを引数とし、カーソルの位置が同じなら赤、違うなら黒で描画する関数
void DrawRed(int x, int y, const char *String, int c);
//x座標,y座標,文字列、縦横に何番目かを引数とし、カーソルの位置が同じなら赤、違うなら黒で描画する関数
void DrawRed2(int x, int y, const char *String, int c, int c2);
//x座標,y座標,文字列、縦に何番目かを引数とし、カーソルの位置が同じならC_ColorとC_EdgeColor、違うならN_ColorとN_EdgeColorで描画する関数
void DrawColor(int x, int y, const char *String, int c, unsigned int N_Color, unsigned int C_Color, unsigned int N_EdgeColor = 0U, unsigned int C_EdgeColor = 0U);
