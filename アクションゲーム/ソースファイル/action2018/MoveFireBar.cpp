#include"Dxlib.h"
#include"extern.h"
#include"function.h"
#include<math.h>

void moveFirebar() {		//�t�@�C�A�o�[�̉�]

	double rad;
	for (int j = 0; j < height_size; j++) {
		for (int i = 0; i < width_size; i++) {
			if (enemy[i][j].species == 39) {
				for (int k = 0; k < BULLET; k++) {
					if (enemy[i][j].dire == 0) {//�����v���
						rad = (enemy[i][j].rad + deg * PI) / 180.0 * (0.6 + enemy[i][j].m_rad / 10);//���x�̒��S��4����Ƃ��ĕω�������
						enemybullet[i][j][1].x = i * BLOCK + 32 * cos(rad);
						enemybullet[i][j][1].y = j * BLOCK + 32 * sin(rad);
						enemybullet[i][j][2].x = i * BLOCK + 64 * cos(rad);
						enemybullet[i][j][2].y = j * BLOCK + 64 * sin(rad);
						enemybullet[i][j][3].x = i * BLOCK + 96 * cos(rad);
						enemybullet[i][j][3].y = j * BLOCK + 96 * sin(rad);
					}
					else {//���v���
						rad = (enemy[i][j].rad - deg * PI) / 180.0 * (0.6 + enemy[i][j].m_rad / 10);
						enemybullet[i][j][1].x = i * BLOCK + 32 * cos(rad);
						enemybullet[i][j][1].y = j * BLOCK + 32 * sin(rad);
						enemybullet[i][j][2].x = i * BLOCK + 64 * cos(rad);
						enemybullet[i][j][2].y = j * BLOCK + 64 * sin(rad);
						enemybullet[i][j][3].x = i * BLOCK + 96 * cos(rad);
						enemybullet[i][j][3].y = j * BLOCK + 96 * sin(rad);
					}
				}
				if (enemy[i][j].species == 40) {
					if (enemy[i][j].dire == 0) {//�����v���
						rad = (enemy[i][j].rad + deg * PI) / 180.0 * (0.6 + enemy[i][j].m_rad / 10);
						enemybullet[i][j][1].x = i * BLOCK + 32 * cos(rad);
						enemybullet[i][j][1].y = j * BLOCK + 32 * sin(rad);
						enemybullet[i][j][2].x = i * BLOCK + 64 * cos(rad);
						enemybullet[i][j][2].y = j * BLOCK + 64 * sin(rad);
						enemybullet[i][j][3].x = i * BLOCK + 96 * cos(rad);
						enemybullet[i][j][3].y = j * BLOCK + 96 * sin(rad);
					}
					else {//���v���
						rad = (enemy[i][j].rad - deg * PI) / 180.0 * (0.6 + enemy[i][j].m_rad / 10);
						enemybullet[i][j][1].x = i * BLOCK + 32 * cos(rad);
						enemybullet[i][j][1].y = j * BLOCK + 32 * sin(rad);
						enemybullet[i][j][2].x = i * BLOCK + 64 * cos(rad);
						enemybullet[i][j][2].y = j * BLOCK + 64 * sin(rad);
						enemybullet[i][j][3].x = i * BLOCK + 96 * cos(rad);
						enemybullet[i][j][3].y = j * BLOCK + 96 * sin(rad);
					}
				}
			}
		}
	}
}
