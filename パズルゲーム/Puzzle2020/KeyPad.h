#pragma once
class CKeyPad
{
private:
	int button[8];		//設定されたボタンの入力フレームカウント e_keyで設定されたenumの値を添え字にする
	int button1P[8];	//対戦モード中の1Pの入力フレームカウント
	int button2P[8];	//対戦モード中の2Pの入力フレームカウント
	int key_p[8];		//キーコンフィグで設定されたゲームパッドのボタンを配列にゲームパッドの添え字で保存する e_keyで設定されたenumの値を添え字にする
	int Key[256];		//キー入力の入力フレームカウント
	int Pad[28];		//ゲームパッドの入力フレームカウント
	int Pad2[28];		//2個目のゲームパッドの入力フレームカウント
	char *cPad[8];		//ゲームパッドの操作するボタンの文字列で操作説明に用いる
	int Pad2P[28];		//2Pのゲームパッドの入力フレームカウント

public:
	CKeyPad();
	~CKeyPad();
	int getButton(int key);
	int getButton1P(int key);
	int getButton2P(int key);
	int getKey(int keyInput);
	int getPad(int padInput);
	char* getCPad(int padInput);
	//カーソルの位置のボタンのキーコンフィグを変更する
	void setKeyConfig(int cursor);
	void init_key();
	void init();
	//キーとパッドが何フレーム押されていたか更新する
	void updateKey();
	void drawEx();
};
