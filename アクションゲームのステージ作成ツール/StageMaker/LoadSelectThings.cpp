#include"DxLib.h"
#include"extern.h"
#include"function.h"

//select_thing�̔z��̓Y����
//�O������Ăяo���ƃo�O��̂ŗǂ��Ȃ����A��Ɨʂ����炷���߂ɗp���Ă���
static int si;

//�X�e�[�W�ɒu�����̏�����
void LoadSelectThings() {

	for (int i = 0; i < MAX_THINGS; i++) {

		//�g��Ȃ��������]���ɔz�������Ă���̂őS������������
		select_description[i] = "���ݒ�";

		//�傫��1�ɏ���������
		SetSelectShift(i, 0, 0, 0, 0);
	}

	//�}�b�v��̔ԍ�����select_thing�̔z��̓Y�����̏�����
	map_si[0] = 0;

	for (int i = 1; i < MAX_THINGS; i++) {
		map_si[i] = -1;
	}

	si = 0;

	//�G
	//1�`100:���ʂ̓G 101�`200:�|���Ȃ��G 251�`299:�{�X
	SetSelectThing(12001, img.enemy[2], "���ɓ����ė�����G");
	SetSelectThing(12002, img.enemy[7], "���̎�O�ŕ����]��");
	SetSelectThing(12003, img.enemy[4], "��ђ��˂�G");
	SetSelectThing(14004, img.enemy[1], "���ɉ�������G");
	SetSelectThing(14005, img.enemy[3], "�c�ɉ�������G");
	SetSelectThing(14006, img.enemy[6], "�~�^������G", false, false);
	SetSelectThing(12007, img.fish, "��ʊO�܂ŏ㉺����G");
	SetSelectThing(12008, img.redghost_S, "�㉺�ɗh���G");
	SetSelectThing(12009, img.enemy[5], "�ǂŔ��˂���G");
	SetSelectThing(12010, img.enemy[12], "�W�����v����Ɣ�ԓG");
	SetSelectThing(14011, img.ghost_S, "�ǂ�������G");
	SetSelectThing(14012, img.blueghost_S, "�����_���ɓ����ǂ�������G");
	SetSelectThing(12013, img.enemy[32], "���ʂɒe�����G");
	SetSelectThing(14014, img.enemy[35], "�c�������@�_���e");
	SetSelectThing(14015, img.enemy[33], "�c�������Đ��ʂɒe", false, false);
	SetSelectThing(14016, img.enemy[34], "�~�^�����Đ��ʂɒe", false, false);
	SetSelectThing(14017, img.cloud_monster_blue, "�X���΂�");
	SetSelectThing(14018, img.cloud_monster, "���ɗ����΂�");
	SetSelectThing(100, img.togeblock4, "�~�܂��Ă���g�Q");
	SetSelectThing(14101, img.togeblock2, "���ɓ����g�Q");
	SetSelectThing(14102, img.togeblock3, "�c�ɓ����g�Q");
	SetSelectThing(14103, img.togeblock, "�~�^������g�Q", false, false);
	SetSelectThing(14251, img.boss[1], "�{�X1");
	SetSelectThing(14252, img.boss[3], "�{�X2");

	si_block = si;
	cs_max_page[1] = (si_block - 1) / (10 * 2) + 1;

	//�u���b�N
	//301�`500:���ʂ̃u���b�N 501�`600:����Ȕ���̃u���b�N 601�`699:��C�Ȃ�
	SetSelectThing(301, img.yuka[1], "�u���b�N1");
	SetSelectThing(302, img.yuka[2], "�u���b�N2");
	SetSelectThing(303, img.yuka[3], "�u���b�N3");
	SetSelectThing(304, img.yuka[4], "�u���b�N4");
	SetSelectThing(305, img.yuka[0], "�u���b�N5");
	SetSelectThing(306, img.yuka[8], "�u���b�N6");
	SetSelectThing(307, img.kabe, "��");
	SetSelectThing(308, img.block_gray, "�u���b�N7");
	SetSelectThing(309, img.block_wood, "�u���b�N8");
	SetSelectThing(500, img.through, "���蔲����");
	SetSelectThing(501, img.toge, "�g�Q�u���b�N");
	SetSelectThing(502, img.block2, "�����");
	SetSelectThing(30503, img.moveblock[0], "3�b��ɏ�����u���b�N");
	SetSelectThing(2504, img.moveblock[4], "���ɓ�����");
	SetSelectThing(2505, img.moveblock[7], "�c�ɓ�����");
	SetSelectThing(2506, img.moveblock[6], "��ʊO�܂ŏ㉺���鏰");
	SetSelectThing(507, img.iceblock, "�X�̏�");
	SetSelectThing(601, img.taihou[2], "���@�_���e������C");
	SetSelectThing(602, img.taihou[1], "���ɒe������C");
	SetSelectThing(603, img.taihou[1], "�E�ɒe������C", true);
	SetSelectThing(604, img.taihou[4], "��ɒe������C");
	SetSelectThing(605, img.taihou[3], "���ɒe������C");
	SetSelectThing(606, img.taihou[5], "����ɒe������C");
	SetSelectThing(607, img.taihou[5], "�E��ɒe������C", true);
	SetSelectThing(608, img.taihou[6], "�����ɒe������C");
	SetSelectThing(609, img.taihou[6], "�E���ɒe������C", true);

	si_etc = si;
	cs_max_page[2] = (si_etc - si_block - 1) / (10 * 2) + 1;

	//���̑�
	//701�`800:�X�C�b�`�Ȃǂ̎d�|�� 801�`900:�� 901�`997:�A�C�e��
	SetSelectThing(701, img.sw[0], "�ԃX�C�b�`");
	SetSelectThing(702, img.sw[1], "�΃X�C�b�`");
	SetSelectThing(703, img.swb[0], "�ԃX�C�b�`�ŏo�鏰");
	SetSelectThing(704, img.swb[1], "�΃X�C�b�`�ŏo�鏰");
	SetSelectThing(705, img.firebar, "�t�@�C�A�o�[", false, false);
	SetSelectThing(706, img.meteor, "��");
	SetSelectThing(707, img.star, "�����������Ă���ꏊ");
	SetSelectThing(708, img.star_blue, "���������Ă���ꏊ");
	SetSelectThing(709, img.star_red, "�Ԑ��������Ă���ꏊ");
	SetSelectThing(801, img.door[3], "�S�[���̔�");
	SetSelectThing(901, img.item, "�A�C�e��");
	SetSelectThing(20902, img.max_item, "�S���A�C�e��");

	//�̂̃X�e�[�W��99������������p
	SetSelectThing(999, img.hito[6], "�v���C���[");


	//�����g��Ȃ��ňႤ�G�ɂ���
	SetSelectThing(12990, img.enemy[21], "�傫���G");
	SetSelectThing(12991, img.enemy[11], "�c���̓G");
	SetSelectThing(12992, img.enemy[16], "�����̓G");

	si_etc_end = si;

	//�u�����̈ȊO�̐ݒ�
	//SetSelectThing(999, img.hito[6], "�v���C���[");

	cs_max_page[3] = (si_etc_end - si_etc - 1) / (10 * 2) + 1;

	//�c���S��null�ɂ���
	for (; si < MAX_THINGS; si++) {
		SetSelectThing2(si, 998, img.null);
	}
}

//select_thing�̃Z�b�g(�����t���ALoadSelectThings����ȊO�̌ďo���֎~)
void SetSelectThing(int number, int GrHandle, char *description, bool turn, bool drawflag) {

	SetSelectThing(number, GrHandle, turn, drawflag);
	//�����̔ԍ����������I�΂ꂽ���ɂ��̐�����`�悷��
	select_description[number % 1000] = description;
}

//select_thing�̃Z�b�g(LoadSelectThings����ȊO�̌ďo���֎~)
void SetSelectThing(int number, int GrHandle, bool turn, bool drawflag) {

	SetSelectThing2(si, number, GrHandle, turn, drawflag);
	si++;
}

//select_thing�̃Z�b�g(�ԍ��w�肠��)
void SetSelectThing2(int i, int number, int GrHandle, bool turn, bool drawflag) {

	select_thing[i].number = number;
	select_thing[i].GrHandle = GrHandle;
	select_thing[i].turn = turn;
	select_thing[i].drawflag = drawflag;

	//�}�b�v��̔ԍ�����select_thing�̔z��̓Y�������t�����ł���悤�ɂ���
	map_si[number % 1000] = i;
}

//�ʏ��蔻��̑傫�������炷�ꍇ�̐ݒ�
void SetSelectShift(int i, int l_shift, int r_shift, int u_shift, int d_shift) {

	select_thing[i].l_shift = l_shift;
	select_thing[i].r_shift = r_shift;
	select_thing[i].u_shift = u_shift;
	select_thing[i].d_shift = d_shift;
}