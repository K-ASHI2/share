#pragma once

/*�������֐�*/
//�}�b�v�ǂݍ��ݎ��̏�����
void init();
//�}�b�v�̐����̏������̌ʏ���
void init_map(int i, int j);
//background�̏�����
void init_b();
//hp�̏�����
void init_l();
//�G�̍��W�ƃ��C�t�Ǝ�ނƓG�̏o���̏�����
void init_e(int i, int j, int l = 0, int s = -1, int a = 1);
//�ǔ�������Ȃ��G�̏�����
void init_j(int i, int j);
//��C�̏�����
void init_t(int i, int j, int l, int s);
//�L�[�{�[�h�ƃQ�[���p�b�h�̓��͂̏�����
void init_key();
//�Q�[���p�b�h�̃L�[�R���t�B�O�̏�����
void init_key_p();
//�v���C���[�̏�����
void playerInit();
//�G�̏�����
void enemyInit();
