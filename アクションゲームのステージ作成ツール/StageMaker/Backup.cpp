#include"DxLib.h"
#include"extern.h"
#include"function.h"	//���ʂ̊֐�

//�}�b�v�̕ύX�̗�����ۑ�����
void BackUp() {

	//�}�b�v�̑S�Ă�T�����A�ύX����Ă�������������Ȃ�o�b�N�A�b�v�����
	for (int j = 0; j< height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			//��O�̃}�b�v�ƌ��ݍ�Ƃ����}�b�v���Ⴄ���������ύX���ꂽ�ꍇ
			if (backup[back_c][i][j] != map[i][j] || backup_w[back_c] != width_size || backup_h[back_c] != height_size) {
				if (back_c != BACK_MAX - 1)
					back_c++;//���݂̎Q�Ƃ�����炷
				else
					back_c = 0;//�擪�̃f�[�^�ɏ㏑������
				back_top = back_c;//�o�b�N�A�b�v�f�[�^�̍Ō�������݂̃}�b�v�ɂ���
				if (back_top == back_head)//�o�b�N�A�b�v�f�[�^�̐擪���Ō���Əd�Ȃ�����
					if (back_head != BACK_MAX - 1)
						back_head++;//�擪�̃f�[�^�͏㏑������Ă���̂�back_head������ɂ��炷
					else
						back_head = 0;
				for (j = 0; j< height_size; j++)
					for (i = 0; i < width_size; i++)
						backup[back_c][i][j] = map[i][j];//���݂̃}�b�v���o�b�N�A�b�v�Ɉڂ�
				backup_w[back_c] = width_size;
				backup_h[back_c] = height_size;
				return;
			}
		}
	}
}
