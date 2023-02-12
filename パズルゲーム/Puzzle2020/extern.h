#include"struct.h"
#include"Player.h"
#include"Block.h"
#include"Music.h"
#include"MenuWindow.h"
#include"KeyPad.h"
#include"Font2.h"

extern CPlayer player1;
extern CPlayer player2;
extern CMusic music;
extern CMenuWindow menuWindow;
extern CKeyPad keyPad;
extern CFont2 font;
extern _img img;

/*ゲーム処理の変数*/
extern long long hiscore;	//ハイスコア
extern int timelimit;		//制限時間
extern int timeCount;	//ゲーム開始からの時間のカウント
extern int clear_count;		//クリアからの時間のカウント
extern bool hiscore_flag;	//ハイスコアを取ったかどうか
extern e_mode mode_flag;	//ゲームモードのフラグ
extern int lastSelectedCPUMode;	//最後に選んだCPUの強さの保存
extern e_padInputMode padInputMode;
