#include"DxLib.h"
#include"extern.h"
#include"function.h"

//�n�C�X�R�A���t�@�C������ǂݍ��ފ֐�
void LoadHiscore() {

	CreateSaveFile();	//�Z�[�u�f�[�^��������΍쐬����(����read�ŊJ���ƃG���[�ƂȂ�)

	FILE *fp = fopen("savedata/score.dat", "rb"); // �t�@�C�����J��

	//�n�C�X�R�A���t�@�C������ǂݍ���
	fread(&hiscore, sizeof(hiscore), 1, fp);

	fclose(fp); //�t�@�C�������
}

//�n�C�X�R�A���t�@�C���ɏ������ފ֐�
void WriteHiscore() {

	FILE *fp = fopen("savedata/score.dat", "wb");	//�t�@�C�����������݂ŊJ��(�t�@�C����������������)
	fwrite(&hiscore, sizeof(hiscore), 1, fp); //�t�@�C���ɏ�������
	fclose(fp); //�t�@�C�������
}

//�Z�[�u�f�[�^��������΍쐬����֐�
void CreateSaveFile() {

	//�t�@�C�������������珑������
	FILE *fp = fopen("savedata/score.dat", "ab");	//�ǉ��������݂ɂ��邱�Ƃł��łɂ���t�@�C���������Ȃ�
	if (fp == NULL) {
		hiscore = 0;
		fwrite(&hiscore, sizeof(hiscore), 1, fp);	//�t�@�C���ɏ�������
	}
	fclose(fp); //�t�@�C�������
}
