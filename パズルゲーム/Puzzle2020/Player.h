#pragma once
#include"define.h"
#include"FallingBlock.h"
#include"NextBlock.h"
#include"Field.h"
#include"Block.h"
#include"SearchField.h"
#include <vector>

class CPlayer
{
private:
	e_player p; //プレイヤーの番号、1P,2P
	int x, y;	//左下から1列目、1段目と数える
	int t;		//連続入力防止用のカウント
	int shot_t;	//ブロックのショット間隔のカウント
	int color_n;	//色の数
	int level;	//上から落下する頻度、時間で上昇する
	int dropNotice;	//落下が予告されているブロックの数
	int dropInterval;	//ブロックが落ちてくる間隔
	bool gameover;	//ゲームオーバーになっているかどうか
	int loseCount[FIELD_W + 1];	//画面外の段のブロックが置かれてからのカウント 
	CNextBlock nextBlock[NEXT_N];
	long long score;	//得点(今の仕様なら最大桁数減らしてintでもいいかも)
	int combo;		//コンボ数
	int comboTime;	//コンボ継続時間のカウント
	int dropCount;	//ドロップするまでの時間のカウント
	e_nextDropMode nextDropMode;	//次の落下でのブロックの落下モード(落下地点など)
	CFallingBlock fallingBlock[FIELD_W * FIELD_H];		//落下中のブロックを持つ(配列の大きさは溢れないように大きめにとった)
	enum e_color resultField[FIELD_W + 1][FIELD_H + 1];	//落下中のブロックが全て落下した場合の結果盤面
	CBlock block[FIELD_W + 1][FIELD_H + 1];	//フィールドのブロック
	CField field[FIELD_W + 1][FIELD_H + 1];	//フィールド
	enum e_cpuMove cpuMove;	//cpu操作をするかどうか、cpuのAIの種類
	int field_left;	//フィールドの枠の左端の座標
	int field_right;	//フィールドの右端の座標
	int field_upper;	//フィールドの上端の座標
	int field_lower;	//フィールドの下端の座標
	int thinkingTime;	//思考時間の最大値、この時間の1/3以上のランダムな待ちを発生する
	int notAppearCount[7];	//ブロックの連続で出現してない回数のカウント(色の最大数設定defineしたほうがいい)

	int createFallingBlock(int i, int j, e_color color);
	int createFallingBlock2(int i, int y, e_color color);
	void fallingBlockInit();
	void resultFieldClear();
	void resultFieldInit();
	void nextInit();
	void dropBlock(int n);
	void dropCenter();
	void dropWhite();
	int getHighestResultBlock(int i);
	void blockFall();
	std::vector<int> getRandomOrder(int length);
	int getHighestUnderBlock(int i, int fby);
	void landingBlock(int k, int j);
	void quickSort(CFallingBlock f[], int n);
	void quickSort(CFallingBlock f[], int low, int high);
	int partition(CFallingBlock f[], int low, int high, int y);
	void vanishCheck();
	void sideCheck();
	void verticalCheck();
	void blockVanish();
	void blockVanishVs();
	void fieldClear();
	void fieldInit();
	void fieldCopy(CPlayer player);
	e_color getRandomUsableColor(const std::vector<e_color>& usable, int n);
	e_color getRandomColor();
	void movePlayer();
	void moveCpu();
	void blockShot();
	bool changeBlockColor(int x, int y, e_color color);
	bool shotVanishCheck(int x, int y);
	bool shotVanishCheckTwin(int x, int y);
	bool drawableCheck(int x, int y);
	bool drawableCheckTwin(int x, int y);
	CSearchField drawableSearch(int range);
	bool shotAlignCheck(int x, int y);
	bool alignCheck(int x, int y);
	CSearchField targetSearch(int range);
	//CSearchField alignSearch(int range);
	//CSearchField noAlignSearch(int range);
	void upMove();
	void downMove();
	void leftMove();
	void rightMove();

public:
	CPlayer();
	~CPlayer();
	int getP();
	int getX();
	int getY();
	int getLevel();
	int incrementLevel();
	int subDropInterval(int sub);
	int getDropNotice();
	void setDropNotice(int dropNotice);
	void addDropNotice(int dropNotice);
	void addOpponentDropNotice(int dropNotice);
	int getGameover();
	int getLoseCount(int line);
	int getFieldLeft();
	int getFieldRight();
	int getFieldUpper();
	int getFieldLower();
	CNextBlock getNextBlock(int i);
	long long int getScore();
	void setScore(long long score);
	int getCombo();
	int getComboTime();
	CFallingBlock getFallingBlock(int i);
	CBlock getBlock(int i, int j);
	CBlock *getBlock2(int i, int j);
	CField getField(int i, int j);
	e_cpuMove getCpuMove();
	void setCpuMove(e_cpuMove cpuMove);
	void setThinkingTime(int thinkingTime);

	void init(e_player player);
	int get_x_from_i(int i);
	int get_y_from_j(int j);
	void update();
};
