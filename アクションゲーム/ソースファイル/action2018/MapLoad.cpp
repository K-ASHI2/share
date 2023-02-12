#include"DxLib.h"
#include"extern.h"
#include"function.h"

//�}�b�v�`�b�v�ǂݍ���
void ReadMap() {
	FILE *fp = NULL;

	//mapload�ϐ�����ǂݍ��ރt�@�C�����̕�����𐶐����A���̃t�@�C�����J��
	fp = fopen(mapToChar(), "r");

	if (fp == NULL) {
		OutputDebugString("MapData Read Error\n");	//�����}�b�v�f�[�^���J�����Ƃ��o���Ȃ�������f�o�b�O��ʂ�"Map Data Read Error"�ƕ\��
		exit(EXIT_FAILURE);
	}

	static int LENGTH = 16;	//���͂̌����̌��E
	char inputc[16];	//���͂̐���������z��
	int input[16];		//���͂̕����R�[�h������z��
	int n = 0;	//�G�̎��X�e�[�^�X�̍��ڂ̔ԍ�
	int j = 0;	//�G�̏o�����̔z��̓Y����

	input[0] = getc(fp);
	inputc[0] = (char)input[0];

	//�ŏ��̍s��/�Ŏn�܂��Ă���΂Ȃ�Ȃ�
	if (input[0] == '/') {
		while (getc(fp) != '\n');
	}
	else {
		fclose(fp);
		OutputDebugString("MapData Format Error\n");
		exit(EXIT_FAILURE);
	}
	for (int j = 0; j < 5; j++) {
		//for�����������������[�v�ɋ߂��̂ň�̍��ڂ�ǂ񂾂�break�Ŕ�����
		for (int i = 0; i < LENGTH; i++) {
			input[i] = getc(fp);
			inputc[i] = (char)input[i];
			//'/'�Ŏn�܂�s�̓R�����g�s�Ȃ̂ōs���܂œǂݔ�΂�
			if (input[i] == '/') {
				//fgets�ł�1�s�ǂݎ��邪�z��̒��������������K�v�Œ����Ȃ肷���邽�ߎg��Ȃ�
				while (getc(fp) != '\n');
				i = -1;
				continue;
			}
			//,�������炻�̕����܂ł���؂�Ƃ��ēǂݎ��
			else if (input[i] == ',') {
				//������������Γǂݔ�΂�
				if (i == 0) {
					i = -1;
					continue;
				}
				inputc[i] = '\0';
				switch (j) {
				case 0:	width_size = atoi(inputc); break;
				case 1:	height_size = atoi(inputc); break;
				case 2:	background_n = atoi(inputc); break;
				case 3:	music_n = atoi(inputc); break;
				case 4:	scroll_v = atoi(inputc); break;
				}
				//1���ړǂݎ�����玟�̍��ڂ�ǂނ��߂�for���𔲂���
				break;
			}
			else if (input[i] == '\n') {
				inputc[i] = '\0';
				break;
			}
			//�t�@�C���̏I���܂œǂݍ���ł��܂��������
			else if (input[i] == EOF) {
				fclose(fp);
				OutputDebugString("�}�b�v�̃X�e�[�^�X���s�����Ă��܂��B\n");
				exit(EXIT_FAILURE);
			}
		}
	}

	//�X�e�[�^�X�̍��ڂ�ǂݏI������炻�̍s�͏I���܂Ŕ�΂�
	while (getc(fp) != '\n');

	//�c��̍s�̓}�b�v�ǂݍ��݂ƂȂ�
	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			//�t�@�C���̏I���܂œǂݍ���ł��܂��������
			if (fscanf(fp, "%d,", &map[i][j]) == EOF) {
				fclose(fp);
				OutputDebugString("�}�b�v�̃f�[�^���s�����Ă��܂��B\n");
				exit(EXIT_FAILURE);
			}
		}
	}
	fclose(fp);
}