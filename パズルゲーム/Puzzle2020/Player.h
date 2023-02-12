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
	e_player p; //�v���C���[�̔ԍ��A1P,2P
	int x, y;	//��������1��ځA1�i�ڂƐ�����
	int t;		//�A�����͖h�~�p�̃J�E���g
	int shot_t;	//�u���b�N�̃V���b�g�Ԋu�̃J�E���g
	int color_n;	//�F�̐�
	int level;	//�ォ�痎������p�x�A���Ԃŏ㏸����
	int dropNotice;	//�������\������Ă���u���b�N�̐�
	int dropInterval;	//�u���b�N�������Ă���Ԋu
	bool gameover;	//�Q�[���I�[�o�[�ɂȂ��Ă��邩�ǂ���
	int loseCount[FIELD_W + 1];	//��ʊO�̒i�̃u���b�N���u����Ă���̃J�E���g 
	CNextBlock nextBlock[NEXT_N];
	long long score;	//���_(���̎d�l�Ȃ�ő包�����炵��int�ł���������)
	int combo;		//�R���{��
	int comboTime;	//�R���{�p�����Ԃ̃J�E���g
	int dropCount;	//�h���b�v����܂ł̎��Ԃ̃J�E���g
	e_nextDropMode nextDropMode;	//���̗����ł̃u���b�N�̗������[�h(�����n�_�Ȃ�)
	CFallingBlock fallingBlock[FIELD_W * FIELD_H];		//�������̃u���b�N������(�z��̑傫���͈��Ȃ��悤�ɑ傫�߂ɂƂ���)
	enum e_color resultField[FIELD_W + 1][FIELD_H + 1];	//�������̃u���b�N���S�ė��������ꍇ�̌��ʔՖ�
	CBlock block[FIELD_W + 1][FIELD_H + 1];	//�t�B�[���h�̃u���b�N
	CField field[FIELD_W + 1][FIELD_H + 1];	//�t�B�[���h
	enum e_cpuMove cpuMove;	//cpu��������邩�ǂ����Acpu��AI�̎��
	int field_left;	//�t�B�[���h�̘g�̍��[�̍��W
	int field_right;	//�t�B�[���h�̉E�[�̍��W
	int field_upper;	//�t�B�[���h�̏�[�̍��W
	int field_lower;	//�t�B�[���h�̉��[�̍��W
	int thinkingTime;	//�v�l���Ԃ̍ő�l�A���̎��Ԃ�1/3�ȏ�̃����_���ȑ҂��𔭐�����
	int notAppearCount[7];	//�u���b�N�̘A���ŏo�����ĂȂ��񐔂̃J�E���g(�F�̍ő吔�ݒ�define�����ق�������)

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
