#include"DrawFunction.h"
#include"InitFunction.h"
#include"MenuFunction.h"
#include"csFunction.h"

/*読み込み関数*/
//マップチップ読み込み
//_FileName:読み込むマップファイルのパス
void ReadMap(const char *_FileName);
//引数を指定しない場合CurrentFileをパスとする
void ReadMap();
//古いバージョンのマップ読み込み
void ReadSimpleMap(const char *_FileName);
//新規作成
void NewMap();
//マップチップに書き込む関数
void WriteMap();
//画像のロード
void LoadImage();
//アニメーションのロード
void LoadAnime();
//音楽のロード
void LoadMusic();
//音楽のセット
void SetMusic(char *FileName);
//背景のロード
void LoadBackground();
//背景のセット
void SetBackground(const TCHAR *FileName, int size_x, int size_y);
//ステージに置く物の初期化
void LoadSelectThings();
//select_thingのセット(説明付き、LoadSelectThingsから以外の呼出し禁止)
void SetSelectThing(int number, int GrHandle, char *description, bool turn = false, bool drawflag = true);
//select_thingのセット(LoadSelectThingsから以外の呼出し禁止)
void SetSelectThing(int number, int GrHandle, bool turn = false, bool drawflag = true);
//select_thingのセット(番号指定あり)
void SetSelectThing2(int i, int number, int GrHandle, bool turn = false, bool drawflag = true);
//通常より判定の大きさをずらす場合の設定
void SetSelectShift(int i, int l_shift, int r_shift, int u_shift, int d_shift);

/*音楽を鳴らす関数*/
//引数mに対応した音楽を鳴らす loop : 1ならループし、それ以外ならループしない
void PlayMusic(int m, int loop = 1);
//設定した数字の音楽を鳴らす
void PM_Number();
//引数eに対応した効果音を鳴らす
//void EffectSound(enum e_effectSound e);

/*更新関数*/
//ゲーム処理の更新
void Update();
//ステージ作成中のゲーム処理
void CreateStage();


