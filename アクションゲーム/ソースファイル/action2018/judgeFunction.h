/*判定関数*/
//敵の壁に対する左右判定1 : 壁に当たったら反転する
void judge_eh(int blx, int bly);
//敵の壁に対する左右判定2 : 壁に横から重なったら壁の横にずらす
void judge_eh2(int blx, int bly);
//敵の壁に対する上下判定
void judge_ev(int blx, int bly);
//上下の反射判定
void judge_ev2(int blx, int bly);
//敵のすり抜け床の判定
void judge_ev3(int blx, int bly);
//敵のすり抜け床の反射判定
void judge_ev4(int blx, int bly);
//プレイヤーの壁の左右判定
void judge_h(int blx, int bly);
//プレイヤーの壁の上下判定
void judge_v(int blx, int bly);
//すり抜け床の判定
void judge_v2(int blx, int bly);
//床に乗っているかどうかの判定
int judge_yuka(int x, int y);
//壁に重なっていたらゲームオーバー
void judge_death(int blx, int bly);
//すり抜け床に重なっていたらゲームオーバー
void judge_death2(int blx, int bly);
//動く床に重なっていたらゲームオーバー
void judge_death3(double blx, double bly);
//ドアに入った時の移動・読み込み
void judgeDoor();
