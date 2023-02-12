#include"struct.h"
#include"Player.h"
#include"Block.h"
#include"Music.h"
#include"MenuWindow.h"
#include"KeyPad.h"
#include"Font2.h"

class CPlayer player1;
class CPlayer player2;
class CMusic music;
class CMenuWindow menuWindow;
class CKeyPad keyPad;
class CFont2 font;
struct _img img;

/*ゲーム処理の変数*/
long long hiscore;	//ハイスコア
int timelimit;		//制限時間
int timeCount;	//ゲーム開始からの時間のカウント
int clear_count;	//クリアからの時間のカウント
bool hiscore_flag;	//ハイスコアを取ったかどうか
e_mode mode_flag;		//ゲームモードのフラグ
int lastSelectedCPUMode = 0;	//最後に選んだCPUの強さの保存
e_padInputMode padInputMode = epad_pad_pad;