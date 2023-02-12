#include"DxLib.h"
#include"drawFunction.h"
#include"initFunction.h"
#include"menuFunction.h"

/*�Q�[�������֐�*/
void MovePlayer();
void MoveEnemy();
void EnemyPattern(int i);
void EnemyPattern0(int i);
void EnemyPattern1(int i);
void EnemyPattern2(int i);
void EnemyPattern3(int i);
void EnemyPattern4(int i);
void MovePlayerBullet();
void MoveEnemyBullet();
void MoveItem();
void MoveBackground();
void CreateEnemy();
//�{�X�̐���
void CreateBoss();
//�{�X�̏o��
void BossAppear();
//���@�̒e�����֐�
void CreatePlayerBullet();
//�e�̍U���́AXY���x�AXY���W�A��ނ��󂯎���Ēe�����֐�
void CreatePlayerBullet2(double atk, double vx, double vy, double x, double y, int kind);
//�G�̒e�����֐�
void CreateEnemyBullet();
//�{�X�̒e�����֐�
void CreateBossBullet1();
//�{�X�̒e�����֐�
void CreateBossBullet2();
//�{�X�̒e�����֐�
void CreateBossBullet3();
//�{�X�̒e�����֐�
void CreateBossBullet4();
//�{�X�̒e�����֐�
void CreateBossBulletExtra();
//���@�ˑ�nway�e�����֐� k:�e�̎�� x:x���W y:y���W n:way�� a:�p�x v:���x m:�e�̕ω� bkind:�����̎��
void Burrage_NWay(enum eb_kind k, double x, double y, int n, double a, double v, int m = 0, int bkind = 0);
//���@�ˑ����Ȃ�nway�e�����֐� k:�e�̎�� x:x���W y:y���W n:way�� a:�p�x v:���x m:�e�̕ω� bkind:�����̎��
void Burrage_NWay2(enum eb_kind k, double x, double y, int n, double a, double v, int m = 0, int bkind = 0);
//�^���ɗ�����nway�e�����֐� k:�e�̎�� x:x���W y:y���W n:way�� a:�p�x v:���x m:�e�̕ω�  bkind:�����̎��
void Burrage_Fall(enum eb_kind k, double x, double y, int n, double a, double v, int m = 0, int bkind = 0);
//�G�̑傫����^����ꂽ�G�̎�ނɉ����Đݒ肷��֐�
void SetEKind(int i, int j);
//�e�̊O���Ƒ傫���ƐF��^����ꂽ�����ɉ����Đݒ肷��֐�
void SetEBKind(enum eb_kind k, int i);
//�G�̑傫����^����ꂽ�G�̎�ނɉ����Đݒ肷��֐�
void SetEnemyBullet(int i, double x, double y, double vx, double vy, int bkind = 0, double ang = 0.0);
//�{���Ȃǎ��@�̍s���œG�̒e�������鎞�̏���
void RemoveBullet(int eb);
//�{�X�̌`�ԕω��œG�̒e�������鎞�̏���
void RemoveBullet2(int eb);
//�����\�Ȏ��@�̒e�̔z��̔ԍ����擾����֐�
int getPlayerBulletNumber();
//�����\�ȓG�̔z��̔ԍ����擾����֐�
int getEnemyNumber();
//�����\�ȓG�̒e�̔z��̔ԍ����擾����֐�
int getEnemyBulletNumber();
//�A�C�e���̐���
void CreateItem(int x,int y,int kind);
//��e����
void PlayerDamage();
//��e��̏���(���炢�{�����܂�)
void PlayerDamaged();
//�{���̏���
void Bomb();
//�{���̃G�t�F�N�g
void BombEffect();
//�����̍X�V
void Update();
//���͂̍X�V
void UpdateKey();
//�t�F�[�h�A�E�g�֐�
void FadeOut();
//�t�F�[�h�C���֐�
void FadeIn();
//����SoundHandle�ɑΉ��������y��炷
void PlayMusic(int SoundHandle, int PlayType = DX_PLAYTYPE_LOOP, int TopPositionFlag = TRUE);
//����e�ɑΉ�����G�t�F�N�g��炷
void efs(enum e_effectSound e);
//�X�e�[�W�����݂̃��[���h��1�ڂ̃X�e�[�W�ɂ���
void WorldStage();
//�X�e�[�W�̉��y��炷
void StageMusic();
//�n�C�X�R�A���t�@�C������ǂݍ��ފ֐�
void LoadHiscore();
//�n�C�X�R�A���t�@�C���ɏ������ފ֐�
void WriteHiscore();
//�Z�[�u�f�[�^��������΍쐬����֐�
void CreateSaveFile();
void Stage();
void Stage1();
void Stage2();
void Stage3();
void Stage4();
void StageExtra();

/*����̊֐�*/
void judge_player_to_enemy();
void judge_player_to_boss();
void judge_playerbullet_to_enemy();
void judge_playerbullet_to_boss();
void judge_enemybullet_to_player();
void judge_player_to_item();
int judge(double x1, double y1, int size1, double x2, double y2, double size2);
//���[�U�[�̔���
int judge_laser(double x1, double y1, int size1, double x2, double y2, double size2);
void Graze();	//�O���C�Y����
void PlayerBulletHitEnemy(int e, int pb);	//�G���G�ɒe�𓖂Ă����̏��� e:�G pb ���@�̒e
void PlayerBulletHitBoss(int pb);			//�{�X�ɒe�𓖂Ă����̏��� pb ���@�̒e
void EnemyDamaged(int e, double d);	//�G���G���_���[�W���󂯂鎞�̏���
void BossDamaged(double d);	//�{�X���_���[�W���󂯂鎞�̏���

