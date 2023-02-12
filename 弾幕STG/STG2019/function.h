#include"DxLib.h"
#include"drawFunction.h"
#include"initFunction.h"
#include"menuFunction.h"

/*ゲーム処理関数*/
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
//ボスの生成
void CreateBoss();
//ボスの出現
void BossAppear();
//自機の弾を作る関数
void CreatePlayerBullet();
//弾の攻撃力、XY速度、XY座標、種類を受け取って弾を作る関数
void CreatePlayerBullet2(double atk, double vx, double vy, double x, double y, int kind);
//敵の弾を作る関数
void CreateEnemyBullet();
//ボスの弾を作る関数
void CreateBossBullet1();
//ボスの弾を作る関数
void CreateBossBullet2();
//ボスの弾を作る関数
void CreateBossBullet3();
//ボスの弾を作る関数
void CreateBossBullet4();
//ボスの弾を作る関数
void CreateBossBulletExtra();
//自機依存nway弾を作る関数 k:弾の種類 x:x座標 y:y座標 n:way数 a:角度 v:速度 m:弾の変化 bkind:動きの種類
void Burrage_NWay(enum eb_kind k, double x, double y, int n, double a, double v, int m = 0, int bkind = 0);
//自機依存しないnway弾を作る関数 k:弾の種類 x:x座標 y:y座標 n:way数 a:角度 v:速度 m:弾の変化 bkind:動きの種類
void Burrage_NWay2(enum eb_kind k, double x, double y, int n, double a, double v, int m = 0, int bkind = 0);
//真下に落ちるnway弾を作る関数 k:弾の種類 x:x座標 y:y座標 n:way数 a:角度 v:速度 m:弾の変化  bkind:動きの種類
void Burrage_Fall(enum eb_kind k, double x, double y, int n, double a, double v, int m = 0, int bkind = 0);
//敵の大きさを与えられた敵の種類に応じて設定する関数
void SetEKind(int i, int j);
//弾の外見と大きさと色を与えられた引数に応じて設定する関数
void SetEBKind(enum eb_kind k, int i);
//敵の大きさを与えられた敵の種類に応じて設定する関数
void SetEnemyBullet(int i, double x, double y, double vx, double vy, int bkind = 0, double ang = 0.0);
//ボムなど自機の行動で敵の弾が消える時の処理
void RemoveBullet(int eb);
//ボスの形態変化で敵の弾が消える時の処理
void RemoveBullet2(int eb);
//生成可能な自機の弾の配列の番号を取得する関数
int getPlayerBulletNumber();
//生成可能な敵の配列の番号を取得する関数
int getEnemyNumber();
//生成可能な敵の弾の配列の番号を取得する関数
int getEnemyBulletNumber();
//アイテムの生成
void CreateItem(int x,int y,int kind);
//被弾処理
void PlayerDamage();
//被弾後の処理(くらいボムも含む)
void PlayerDamaged();
//ボムの処理
void Bomb();
//ボムのエフェクト
void BombEffect();
//処理の更新
void Update();
//入力の更新
void UpdateKey();
//フェードアウト関数
void FadeOut();
//フェードイン関数
void FadeIn();
//引数SoundHandleに対応した音楽を鳴らす
void PlayMusic(int SoundHandle, int PlayType = DX_PLAYTYPE_LOOP, int TopPositionFlag = TRUE);
//引数eに対応するエフェクトを鳴らす
void efs(enum e_effectSound e);
//ステージを現在のワールドの1つ目のステージにする
void WorldStage();
//ステージの音楽を鳴らす
void StageMusic();
//ハイスコアをファイルから読み込む関数
void LoadHiscore();
//ハイスコアをファイルに書き込む関数
void WriteHiscore();
//セーブデータが無ければ作成する関数
void CreateSaveFile();
void Stage();
void Stage1();
void Stage2();
void Stage3();
void Stage4();
void StageExtra();

/*判定の関数*/
void judge_player_to_enemy();
void judge_player_to_boss();
void judge_playerbullet_to_enemy();
void judge_playerbullet_to_boss();
void judge_enemybullet_to_player();
void judge_player_to_item();
int judge(double x1, double y1, int size1, double x2, double y2, double size2);
//レーザーの判定
int judge_laser(double x1, double y1, int size1, double x2, double y2, double size2);
void Graze();	//グレイズ処理
void PlayerBulletHitEnemy(int e, int pb);	//雑魚敵に弾を当てた時の処理 e:敵 pb 自機の弾
void PlayerBulletHitBoss(int pb);			//ボスに弾を当てた時の処理 pb 自機の弾
void EnemyDamaged(int e, double d);	//雑魚敵がダメージを受ける時の処理
void BossDamaged(double d);	//ボスがダメージを受ける時の処理

