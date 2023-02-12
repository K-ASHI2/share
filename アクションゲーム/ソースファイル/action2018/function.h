#include"drawFunction.h"
#include"gameFunction.h"
#include"initFunction.h"
#include"judgeFunction.h"
#include"menuFunction.h"

/*読み込み関数*/
//マップを読み込む関数
void ReadMap();
//mapload変数から読み込むテキストファイル名を生成し返す関数
char *mapToChar();
//画像のロード
void image();
//アニメーションのロード
void anime();
//音楽のロード
void LoadMusic();
//音楽のセット
void SetMusic(char *FileName);
//音楽のロード
void Music();
//背景のロード
void LoadBackground();
//背景のセット
void SetBackground(const TCHAR *FileName, int size_x, int size_y);

/*音楽を鳴らす関数*/
//引数mに対応した音楽を鳴らす loop : 1ならループし、それ以外ならループしない
void PlayMusic(int m, int loop = 1);
//引数eに対応した効果音を鳴らす
void efs(enum e_effectSound e);

/*更新関数*/
//ゲーム処理の更新
void update();
//ゲームプレイ中のアップデート処理
void playUpdate();
