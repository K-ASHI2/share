#include"struct.h"

extern _player player;						//自機のstructをインスタンス化　　
extern _enemy enemy[ENEMY];				//敵のstructを
extern _enemyemerge enemyemerge[ENEMYEMERGE]; 
extern _boss boss;
extern _bullet playerbullet[BULLET];		//弾のstructを自機の弾用に
extern _bullet enemybullet[ENEMYBULLET];	//弾のstructを敵の弾用に
extern _item item[ITEM];					//アイテムのstructを
extern _background background;				//背景のstructを
extern _img img;							//画像のstructを
extern _anime ani;	//アニメーションを保存する
extern _music music;

extern e_flag flag;
extern e_flag cancel_flag;		//キャンセルで戻る時のフラグ
extern e_difficulty difficulty;
extern e_stage stage;	//ステージ
extern e_world world;		//ワールド
extern e_bossflag boss_flag;
extern e_mode mode_flag;	//ゲームモードのフラグ
extern e_fade fade_flag;	//フェードアウトしているかどうかのフラグ
extern e_key ekey;		//ゲーム内で使用されるボタンの数だけ宣言する

/*defineの数値によって変動する定数*/
static int G_W_CENTER_X = (G_W_LEFT + G_W_RIGHT) / 2;	//画面の中央のX座標
static int G_W_CENTER_Y = (G_W_UPPER + G_W_LOWER) / 2;	//画面の中央のY座標

/*ゲーム処理の変数*/
extern int chap;	//チャプターが何番目か
extern int p_music;	//現在の演奏している曲
extern long long hiscore;		//ハイスコア
extern int stageTimeCount;		//ステージ開始からの時間(この時間に応じて敵が出る)
extern int PlaybackFlag;		//ポーズ画面から戻った後の再生時は1,それ以外は0
extern int draw_ex;	//操作説明の描画のオンオフでオプションから変更可
extern int window_mode;	//ウィンドウモードなら0,フルスクリーンモードなら1
extern int time;	//クリアからの時間のカウント

/*フォント*/
extern int Font[5];
extern int black;
extern int darkblack;
extern int liteblack;
extern int red;
extern int greenblue;
extern int green;
extern int litegreen;
extern int silver;
extern int white;

/*フェードアウト用の変数*/
extern int bright;	//輝度

/*change_flagはすぐに実行されないので引数を保存する*/
extern e_flag changeFlag_flag;
extern int changeFlag_cursor;
extern int changeFlag_cursor2;

/*メニュー画面の変数*/
extern int cursor;		//縦カーソルがどの位置にあるか
extern int cursor_LR;	//横カーソルがどの位置にあるか
extern int cancel_cursor;	//キャンセルで戻る時のカーソルの位置
extern int N_o_i;		//現在の選択画面の項目数
extern int N_o_i_LR;	//現在の選択画面の項目数
extern int count;		//カーソル入力の待ち時間のカウント

/*キー操作の変数*/
extern int button[8];	//設定されたボタンの入力フレームカウント e_keyで設定されたenumの値を添え字にする
extern int key_p[8];	//キーコンフィグで設定されたゲームパッドのボタンを配列にゲームパッドの添え字で保存する e_keyで設定されたenumの値を添え字にする
extern int Key[256];	//キー入力の入力フレームカウント
extern int Pad[28];		//ゲームパッドの入力フレームカウント
extern char *cPad[8];	//ゲームパッドの操作するボタンの文字列で操作説明に用いる
