/*ゲーム処理関数*/
//プレイヤーの攻撃
void attack();
//ブロックの動き
void blockmove();
//プレイヤーの動き
void move();
//敵の弾の生成
void create_enemybullet();
//敵の生成
void create_enemy();
void move_enemybullet();
//ファイアバーの回転
void moveFirebar();
//背景の移動
void move_background();
//敵の移動
void enemymove();
//x方向にsin波で動く物の移動
void sin_move(int i, int j);
//y方向にsin波で動く物の移動
void sin_move_y(int i, int j);
//扉の移動
void door(int dx, int dy);
//フェードアウト後の扉の移動
void door_fade(int dx, int dy);
//次の画面に進む扉 m : 今のマップの番号
void door2(int m);
//フェードアウト後の扉の移動
void door_fade2(int m);
