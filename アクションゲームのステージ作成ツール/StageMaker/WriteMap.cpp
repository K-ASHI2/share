#include"DxLib.h"
#include"extern.h"
#include"function.h"

//�}�b�v�t�@�C���ɏ������ފ֐�
void WriteMap() {

	FILE *fp = NULL;

	if ((fp = fopen(CurrentFile, "w")) == NULL) {
		OutputDebugString("MapData Write Error\n");
		exit(EXIT_FAILURE);
	}
	//�p�����[�^�̐���
	fprintf(fp, "/����,�c��,�w�i,���y,�X�N���[��,\n");

	//�p�����[�^
	fprintf(fp, " %d,", width_size);
	fprintf(fp, " %d,", height_size);
	fprintf(fp, " %d,", background_n);
	fprintf(fp, " %d,", music_n);
	fprintf(fp, " %d,", scroll_v);
	fprintf(fp, "\n");

	//�}�b�v�f�[�^
	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			fprintf(fp, " %d,", map[i][j]);
		}
		fprintf(fp, "\n");
	}

	fclose(fp);
}
