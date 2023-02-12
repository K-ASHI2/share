#pragma once
#include"enum.h"
#include <bitset>

//�t�B�[���h��ɑ��݂���u���b�N
//�t�B�[���h�ɐڒn���đ��݂���u���b�N�̏�������

class CBlock
{
private:
	int x, y;	//�ǂ̈ʒu�ɑ��݂���u���b�N��
	e_color color;	//���F�������Ă��邩
	e_color drawColor;	//�G�t�F�N�g�̓r���܂ŗ�����h����F��ێ�����
	bool vanishFlag;	//�u���b�N�������邩�ǂ���(�u���b�N�̍폜���̂ݎ���)
	int vanishCount;	//�u���b�N�������Ă��痎������܂ł̃J�E���g
	int drawEffectCount;	//�F��h���Ă���G�t�F�N�g�̕\������
	int chain;	//�u���b�N�̘A����
	int chainTime;	//�u���b�N�̘A������ێ����鎞��(�������Đ��t���[���̂ݕێ�����)
	
public:
	CBlock();
	~CBlock();
	e_color getColor();
	void setColor(e_color color);
	e_color getDrawColor();
	void setDrawColor(e_color drawColor);
	bool getVanishFlag();
	void setVanishFlag(bool flag);
	int getVanishCount();
	void setVanishCount(int vanishCount);
	int getDrawEffectCount();
	void setDrawEffectCount(int drawEffectCount);
	int getX();
	int getY();
	int getChain();
	void setChain(int chain);
	int getChainTime();
	void setChainTime(int chainTime);
	void decrementChainTime();
	void init(int x, int y);
	void decrementVanishCount();
	void decrementDrawEffectCount();
};
