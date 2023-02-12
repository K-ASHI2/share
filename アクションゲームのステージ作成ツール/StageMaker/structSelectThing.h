//背景のstruct
struct S_SelectThing {
	
	//マップにおける数字
	int number;
	//画像
	int GrHandle;
	//反転するかどうか
	bool turn;
	//描画するかどうか
	bool drawflag;

	//現状では使用していない
	//通常より判定が左に何マス大きいか
	int l_shift;
	//通常より判定が左に何マス大きいか
	int r_shift;
	//通常より判定が左に何マス大きいか
	int u_shift;
	//通常より判定が左に何マス大きいか
	int d_shift;
};