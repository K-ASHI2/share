#include"DxLib.h"
#include<vector>

/*ゲーム処理関数*/
//処理の更新
void update();
//ハイスコアをファイルから読み込む関数
void loadHiscore();
//ハイスコアをファイルに書き込む関数
void writeHiscore();
//セーブデータが無ければ作成する関数
void createSaveFile();

/*初期化関数*/
//ロードする関数
void load();
//画像をロードする関数
void loadImage();
//初期化関数の入り口
void init();
//フラグごとのフォントを決める
void flagSetFont();

/*描画関係関数*/
void draw();
//ゲームプレイ中の画面の描画
void drawPlay();
//背景の描画
void drawBackGround(CPlayer player);
//カーソルの描画
void drawCursor(CPlayer player);
//フィールド上のブロックの描画
void drawFieldBlock(CPlayer player);
//ゲームプレイ中の画面外の描画
void drawPlayWindow();
//対戦モードのゲームプレイ中の画面外の描画
void drawVsWindow();
//レベルの数値の描画
void drawLevel(int x, int y, CPlayer player);
//コンボの数値の描画
void drawCombo(int x, int y, CPlayer player);
//連鎖数の描画
//void drawChain(int x, int y, CPlayer player);
//対戦モードのコンボの数値の描画
void drawVsCombo(int x, int y, CPlayer player);
//NEXTの描画
void drawNext();
//コンボ時間のバー
void drawComboCountBar();
//対戦モードのコンボ時間のバー
void drawComboCountBarVS();
//敵の体力に応じたHPバーの色を返す関数
int GetHPColor(int hp, int maxhp);
//引数の色に対応したブロックの画像を返す
int getBlockImg(e_color color);
//引数の色に対応したカーソルの画像を返す
int getCursorImg(e_color color);
