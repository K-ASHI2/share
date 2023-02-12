#include"DxLib.h"
#include"extern.h"
#include"function.h"

//�G�̏o������ǂݍ��ފ֐�
void LoadEmerge() {

	int fp;
	switch (world) {
	case ew_1: fp = FileRead_open("pattern/emerge1.csv"); break;
	case ew_2: fp = FileRead_open("pattern/emerge2.csv"); break;
	case ew_3: fp = FileRead_open("pattern/emerge3.csv"); break;
	case ew_4: fp = FileRead_open("pattern/emerge4.csv"); break;
	case ew_extra: fp = FileRead_open("pattern/emergeExtra.csv"); break;
	}
		
	if (fp == NULL) {
		OutputDebugString("Enemy Data Read Error\n");	//�����}�b�v�f�[�^���J�����Ƃ��o���Ȃ�������f�o�b�O��ʂ�"Enemy Data Read Error"�ƕ\��
		exit(EXIT_FAILURE);
	}
	else{

		//�ŏ���2�s�͐����̂ݏ����Ă���̂Ŕ�΂�
		for (int i = 0; i < 2; i++) {
			while (FileRead_getc(fp) != '\n');
		}

		char inputc[64];	//���͂̐���������z��
		int input[64];		//���͂̕����R�[�h������z��
		int n = 0;	//�G�̎��X�e�[�^�X�̍��ڂ̔ԍ�
		int j = 0;	//�G�̏o�����̔z��̓Y����
		while (1) {

			for (int i = 0; i < 64; i++) {
				//�z��ɓ��͂̐����ƕ����R�[�h������
				inputc[i] = input[i] = FileRead_getc(fp);
				//'/'�Ŏn�܂�s�̓v���O�����Ɋ֌W�Ȃ��̂ōs���܂œǂݔ�΂�
				if (input[i] == '/') {
					while (FileRead_getc(fp) != '\n');
					i = -1;
					continue;
				}
				else if (input[i] == ',' || input[i] == '\n') {
					inputc[i] = '\0';
					break;
				}
				if (input[i] == EOF) {
					FileRead_close(fp);
					return;
				}
			}
			//�G�̏o���f�[�^������
			switch (n) {
			case 0: enemyemerge[j].frame = atoi(inputc); break;
			case 1: enemyemerge[j].pattern = atoi(inputc); break;
			case 2: enemyemerge[j].kind = atoi(inputc); break;
			case 3: enemyemerge[j].x = atoi(inputc); break;
			case 4: enemyemerge[j].y = atoi(inputc); break;
			case 5: enemyemerge[j].v = atoi(inputc); break;
			case 6: enemyemerge[j].hp = atoi(inputc); break;
			case 7: enemyemerge[j].wait = atoi(inputc); break;
			case 8: enemyemerge[j].bt = atoi(inputc); break;
			case 9: enemyemerge[j].bkind = atoi(inputc); break;
			case 10:enemyemerge[j].color = atoi(inputc); break;
			case 11:enemyemerge[j].item = atoi(inputc); break;
			}
			n++;
			if (n == 12) {
				n = 0;
				j++;
			}
		}

		/*while (fscanf(fp, "%d,", &map2[k]) != EOF) {
			k++;
		}*/

	}
	FileRead_close(fp);
}
