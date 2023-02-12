#include"DxLib.h"
#include"math.h"
#include"extern.h"
#include"function.h"	//���ʂ̊֐�

//�󂯎��������x��n���ڂ�f�̐����ɏ��������ĕԂ�
int FigureChange(int x, int n, int f) {

	double dn = (double)n;
	int a = x / (int)pow(10.0, dn);	//n���ڂ���̈ʂ�a�ɕۑ�����
	int b = x % (int)pow(10.0, dn - 1.0);	//n���ڂ�艺�̈ʂ�b�ɕۑ�����
	return(a * (int)pow(10.0, dn) + f * (int)pow(10.0, dn - 1.0) + b);	//n���ڂ�f�������Ă��Ďc��͌��ɖ߂�
}

//���j���[�̕ύX
void CSChangeMenu() {

	//���ꂼ��̃��j���[��������Ă���΁A���̃��j���[�ɕύX����
	for (int i = 0; i < 4; i++) {
		if (JudgeMouse2(0 + 142 * i, 500, 136 + 142 * i, 525)) {
			//���݂ƈႤ���j���[�������ꂽ�Ȃ烁�j���[��ύX���A���̑O�̃J�[�\���͏�����
			if (menu_b != i + 1) {
				menu_b = i + 1;
				sx = -1;
				sy = -1;
				sx2 = -1;
				sy2 = -1;
				cs_map = 0;
				break;	//��x�ɕ����̃��j���[�͉�����Ȃ��̂�break����
			}
		}
	}
}

//�֎~�����u���������Ă�����1��Ԃ��֐�
int ProhibitCheck() {

	//�J�n����ɃQ�[���I�[�o�[�ɂȂ�Ȃ�o�b�N�A�b�v�����O�ɖ߂�
	//�v���C���[�̏������W����ʓ��ɑ��݂��Ȃ�
	//�v���C���[�̏������W�̏オ�ǂɂȂ��Ă���
	for (int j = 0; j < height_size - 1; j++) {
		for (int i = 0; i < width_size; i++) {
			//��l���̍��W������Ȃ�
			if (map[i][j] % 1000 == 999) {
				//��l���̑��̍��W�ɉ��������d�Ȃ��Ă���
				if (map[i][j + 1] % 1000 != 0) {
					return 1;
				}
				//�v���C���[�̏������W�̉��ɏ�ɓ�����������
				if (j < height_size - 2) {
					if ((map[i][j + 2] % 1000 == 12 || map[i][j + 2] % 1000 == 48) && map[i][j + 2] % 100000 / 10000 == 1) {
						return 1;
					}
				}
				//�v���C���[�̏������W�̏�ɉ��ɓ�����������
				if (j > 1) {
					if ((map[i][j - 1] % 1000 == 12 || map[i][j - 1] % 1000 == 48) && map[i][j - 1] % 100000 / 10000 == 2) {
						return 1;
					}
				}
				//�v���C���[�̏������W�̍��ɉE�ɓ�����������
				if (i > 1) {
					if (map[i - 1][j] % 1000 == 6 && map[i - 1][j] % 100000 / 10000 == 2 || map[i - 1][j + 1] % 1000 == 6 && map[i - 1][j + 1] % 100000 / 10000 == 2) {
						return 1;
					}
				}
				//�v���C���[�̏������W�̉E�ɍ��ɓ�����������
				if (i < width_size - 1) {
					if (map[i + 1][j] % 1000 == 6 && map[i + 1][j] % 100000 / 10000 == 1 || map[i + 1][j + 1] % 1000 == 6 && map[i + 1][j + 1] % 100000 / 10000 == 1) {
						return 1;
					}
				}
				return 0;
			}
			
		}
	}
	//��l���̍��W������
	return 1;
}

//�}�b�v�̕ۑ�
void SaveMap() {

	//map[0][height_size] = background_n;//�}�b�v�̈�ԉ��̗�̍��[�ɔw�i�̔ԍ�����������
	WriteMap();	//�}�b�v�̃t�@�C���ɏ�������
	MessageBox(hMainWnd, "�Z�[�u���܂���", "STAGE MAKER", MB_OK);
}

//�}�b�v����O�̏�Ԃɖ߂�
void UndoMap() {

	if (back_c != back_head) {		//�擪�łȂ���Ζ߂�
		if (back_c != 0)
			back_c--;
		else
			back_c = BACK_MAX - 1;
		width_size = backup_w[back_c];	//������߂�
		height_size = backup_h[back_c];	//������߂�
		for (int j = 0; j < height_size; j++)
			for (int i = 0; i < width_size; i++)
				map[i][j] = backup[back_c][i][j];	//�}�b�v�̑S�Ă̍��W�����ɖ߂�
		if (stage_x > width_size * block_size - WINDOW_WIDTH)
			stage_x = width_size * block_size - WINDOW_WIDTH;	//�J�[�\�����E�[�ɂ���
	}
}

//�}�b�v������̏�Ԃɂ���
void RedoMap() {
	
	if (back_c != back_top) {	//�Ō���łȂ���ΐi��
		if (back_c != BACK_MAX - 1)
			back_c++;
		else
			back_c = 0;
		width_size = backup_w[back_c];	//������i�߂�
		height_size = backup_h[back_c];	//������i�߂�
		for (int j = 0; j < height_size; j++){
			for (int i = 0; i < width_size; i++) {
				map[i][j] = backup[back_c][i][j];	//�}�b�v�̑S�Ă̍��W��i�߂�
			}
		}
		if (stage_x > width_size * block_size - WINDOW_WIDTH)
			stage_x = width_size * block_size - WINDOW_WIDTH;	//�J�[�\�����E�[�ɂ���
	}
}

//�I�𒆂̕���؂���
void TrimmingMap() {

	if (sx >= 0 && sy >= 0) {
		mc = map[sx][sy];
		map[sx][sy] = 0;
	}
}

//�I�𒆂̕����R�s�[����
void CopyMap() {

	if (sx >= 0 && sy >= 0) {
		mc = map[sx][sy];
	}
}

//�I�𒆂̕���\��t����
void PasteMap() {

	if (sx >= 0 && sy >= 0) {
		map[sx][sy] = mc;
	}
}

//�I�𒆂̕�����������
void DeleteMap() {

	if (sx >= 0 && sy >= 0) {
		map[sx][sy] = 0;
	}
}

//��ʃT�C�Y�̕ύX
bool ChangeMapSize(int x, int y, int width, int height) {

	if (width <= 0 || height <= 0) {
		MessageBox(hMainWnd, "0�ȉ��͓��͂ł��܂���B", "�x��", MB_OK);
		return false;
	}
	else if (width > MAX_WIDTH) {
		MessageBox(hMainWnd, "�������傫�����܂��B", "�x��", MB_OK);
		return false;
	}
	else if (height > MAX_HEIGHT) {
		MessageBox(hMainWnd, "�c�����傫�����܂��B", "�x��", MB_OK);
		return false;
	}

	int map2[MAX_WIDTH][MAX_HEIGHT];

	//���݂̃}�b�v���R�s�[���ޔ�������
	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			map2[i][j] = map[i][j];
		}
	}
	//��x�S�Ẵ}�b�v����ɂ���
	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
			map[i][j] = 0;
		}
	}
	int i = 0;
	int j = 0;
	//x,y�����̐��̏ꍇx+i��y+j�����ɂȂ�Ȃ��悤�ɂ���
	if (x < 0) {
		i = -x;
	}
	if (y < 0) {
		j = -y;
	}
	//(x,y)�̒n�_������Ƃ��ă}�b�v���R�s�[����
	for (int j = 0; j < height_size; j++) {
		//�V�����ł����ʂ̏c���𒴂��Ȃ��悤�ɂ���
		if (y + j > height) {
			break;
		}
		for (int i = 0; i < width_size; i++) {
			//�V�����ł����ʂ̉����𒴂��Ȃ��悤�ɂ���
			if (x + i > width) {
				break;
			}
			map[x + i][y + j] = map2[i][j];
		}
	}
	height_size = height;
	width_size = width;
	stage_x = 0;	//�X�N���[�������[��
	stage_y = height_size * block_size - WINDOW_HEIGHT;	//�X�N���[������ԉ���

	return true;
}
