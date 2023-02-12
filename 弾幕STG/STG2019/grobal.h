#include"struct.h"
#include"DxLib.h"
struct _player player;
struct _enemy enemy[ENEMY];
struct _enemyemerge enemyemerge[ENEMYEMERGE];
struct _boss boss;
struct _bullet playerbullet[BULLET];
struct _bullet enemybullet[ENEMYBULLET];
struct _item item[ITEM];
struct _background background;
struct _music music;
struct _img img;
struct _anime ani;
enum e_flag flag;
enum e_flag cancel_flag = e_title;	//キャンセルで戻る時のフラグ
enum e_difficulty difficulty;
enum e_stage stage;		//ステージ
enum e_world world;		//ワールド
enum e_bossflag boss_flag;
enum e_mode mode_flag;	//ゲームモードのフラグ
enum e_fade fade_flag;	//フェードアウトしているかどうかのフラグ
enum e_key ekey;	//ゲーム内で使用されるボタンの数だけ宣言する

/*ゲーム処理の変数*/
int chap;			//チャプターが何番目か
int p_music = -1;	//現在の演奏している曲
long long hiscore;		//ハイスコア
int stageTimeCount;		//ステージ開始からの時間(この時間に応じて敵が出る)
int PlaybackFlag = 0;	//ポーズ画面から戻った後の再生時は1,それ以外は0
int draw_ex = 1;	//操作説明の描画のオンオフでオプションから変更可
int window_mode = 0;	//ウィンドウモードなら0,フルスクリーンモードなら1
int time;	//クリアからの時間のカウント

/*フォント*/
int Font[5];
int black = GetColor(32, 32, 32);
int darkblack = GetColor(0, 0, 0);
int liteblack = GetColor(44, 44, 44);
int red = GetColor(212, 50, 52);
int greenblue = GetColor(31, 255, 255);
int green = GetColor(32, 130, 62);
int litegreen = GetColor(0, 254, 0);
int silver = GetColor(221, 224, 234);
int white = GetColor(255, 255, 255);

/*フェードアウト用の変数*/
int bright = 255;	//画面の輝度

/*change_flagはすぐに実行されないので引数を保存する*/
enum e_flag changeFlag_flag;
int changeFlag_cursor;
int changeFlag_cursor2;

/*メニュー画面の変数*/
int cursor = 0;		//縦カーソルがどの位置にあるか
int cursor_LR = 0;	//横カーソルがどの位置にあるか
int cancel_cursor = 0;	//キャンセルで戻る時のカーソルの位置
int N_o_i = 0;		//現在の選択画面の項目数
int N_o_i_LR = 0;	//現在の選択画面の項目数
int count = 0;		//カーソル入力の待ち時間のカウント

/*キー操作の変数*/
int button[8];		//設定されたボタンの入力フレームカウント e_keyで設定されたenumの値を添え字にする
int key_p[8];		//キーコンフィグで設定されたゲームパッドのボタンを配列にゲームパッドの添え字で保存する e_keyで設定されたenumの値を添え字にする
int Key[256];		//キー入力の入力フレームカウント
int Pad[28];		//ゲームパッドの入力フレームカウント
char *cPad[8];		//ゲームパッドの操作するボタンの文字列で操作説明に用いる
