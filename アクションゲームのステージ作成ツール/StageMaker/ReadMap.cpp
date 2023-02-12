#include"DxLib.h"
#include"extern.h"
#include"function.h"

//�}�b�v�f�[�^�̓ǂݍ���
//�}�b�v�`�b�v�݂̂̃t�@�C���ł��������ʂł���悤�ɂȂ��Ă���
//_FileName:�ǂݍ��ރ}�b�v�t�@�C���̃p�X
void ReadMap(const char *_FileName) {
	FILE *fp = NULL;

	//��������t�@�C���̃p�X���󂯎��A���̃t�@�C�����J��
	fp = fopen(_FileName, "r");

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
	//�ŏ��̍s��/�Ŏn�܂��Ă���΂Ȃ��΂��A�����łȂ���΃}�b�v�f�[�^�݂̂̃t�@�C���ǂݍ��݂�����
	if (input[0] == '/') {
		while (getc(fp) != '\n');
	}
	else {
		fclose(fp);
		ReadSimpleMap(_FileName);
		return;
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
				MessageBox(hMainWnd, "�}�b�v�̃X�e�[�^�X���s�����Ă��܂��B", "STAGE MAKER", MB_OK);
				return;
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
				MessageBox(hMainWnd, "�}�b�v�̃f�[�^���s�����Ă��܂��B", "STAGE MAKER", MB_OK);
				return;
			}
		}
	}
	fclose(fp);
}

//�Â��o�[�W�����̃}�b�v�ǂݍ���
//_FileName:�ǂݍ��ރ}�b�v�t�@�C���̃p�X
void ReadSimpleMap(const char *_FileName) {
	FILE *fp = NULL;

	//��������t�@�C���̃p�X���󂯎��A���̃t�@�C�����J��
	fp = fopen(_FileName, "r");

	if (fp == NULL) {
		OutputDebugString("MapData Read Error\n");	//�����}�b�v�f�[�^���J�����Ƃ��o���Ȃ�������f�o�b�O��ʂ�"Map Data Read Error"�ƕ\��
		exit(EXIT_FAILURE);
	}
	int map2[HEIGHT_SIZE * MAX_WIDTH + 1];
	int k = 0;

	for (int i = 0; i < HEIGHT_SIZE * MAX_WIDTH + 1; i++) {
		map2[i] = 0;
	}

	while (fscanf(fp, "%d,", &map2[k]) != EOF) {
		k++;
		if (k > HEIGHT_SIZE * MAX_WIDTH) {
			fclose(fp);
			MessageBox(hMainWnd, "�}�b�v���ǂݍ��߂܂���ł����B", "STAGE MAKER", MB_OK);
			return;
		}
	}

	//�}�b�v���ǂݍ��߂���X�e�[�W�̍�������ʂ̍����ɂ��낦��
	height_size = HEIGHT_SIZE;

	//�}�b�v����̔w�i�̓ǂݍ���
	if (k % HEIGHT_SIZE == 1)//�ǂݍ��񂾃}�b�v�ɂ��܂肪����ꍇ���̂��܂肪�w�i�ƂȂ�
		background_n = map2[k - 1];
	width_size = k / HEIGHT_SIZE;
	k = 0;
	for (int j = 0; j < HEIGHT_SIZE; j++) {
		for (int i = 0; i < width_size; i++) {
			map[i][j] = map2[k];
			k++;
		}
	}
	fclose(fp);
}

//�������w�肵�Ȃ��ꍇCurrentFile���p�X�Ƃ���
void ReadMap() {
	ReadMap(CurrentFile);
}

//�V�K�쐬
void NewMap() {
	/*ReadMap("default.txt");*/
	ReadMap("default2.csv");
	CurrentFile = "default2.csv";
}
