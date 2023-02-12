#include"DxLib.h"
#include"extern.h"
#include"function.h"
#include"resource.h"

//マップを開くダイアログボックス
//成功したら0、失敗したら-1を返す
int MapFileOpen(HWND hWnd, char **pass) {

	//ファイルを開く為の設定用構造体
	OPENFILENAME ofn;

	//開いたファイルのパスを残しておくためにstaticにする
	//staticにしないとpassに参照を渡してもこの関数が終わったらメモリが開放されてしまう
	static char szFile[MAX_PATH] = "";

	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = hWnd;
	ofn.lpstrFilter = "テキスト ファイル (*.prn;*.txt;*.csv)\0*.prn;*.txt;*.csv\0"
		"すべてのファイル(*.*)\0*.*\0\0";
	ofn.lpstrFile = szFile;
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrTitle = "マップファイルの選択";
	ofn.lpstrDefExt = ".txt";

	//OFN_NOCHANGEDIR:カレントディレクトリを元の位置に戻す
	//ディレクトリを戻さないとfopenやLoadGraphなどでファイルが見つからなくなってしまう
	ofn.Flags = OFN_NOCHANGEDIR;

	//ファイルオープンに失敗したら-1を返す
	if (GetOpenFileName(&ofn) == 0) {
		return -1;
	}
	else {
		*pass = szFile;
		return 0;
	}
}

//マップを保存するダイアログボックス
//成功したら0、失敗したら-1を返す
int MapFileSave(HWND hWnd, char **pass) {

	//ファイルを開く為の設定用構造体
	OPENFILENAME ofn;

	//開いたファイルのパスを残しておくためにstaticにする
	//staticにしないとpassに参照を渡してもこの関数が終わったらメモリが開放されてしまう
	static char szFile[MAX_PATH] = "";

	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = hWnd;
	ofn.lpstrFilter = "テキスト ファイル (*.txt;*.csv;*.prn)\0*.txt;prn;*.csv\0"
		"すべてのファイル(*.*)\0*.*\0\0";
	ofn.lpstrFile = szFile;
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrTitle = "保存先のファイルの選択";
	ofn.lpstrDefExt = ".txt";

	//OFN_NOCHANGEDIR:カレントディレクトリを元の位置に戻す
	//ディレクトリを戻さないとfopenやLoadGraphなどでファイルが見つからなくなってしまう
	ofn.Flags = OFN_FILEMUSTEXIST | OFN_OVERWRITEPROMPT | OFN_NOCHANGEDIR;

	//ファイルオープンに失敗したら-1を返す
	if (GetSaveFileName(&ofn) == 0) {
		return -1;
	}
	else {
		*pass = szFile;
		return 0;
	}
}

//ファイルを開くダイアログボックス
//int ImgFileOpen(HWND hWnd) {
//
//	//ファイルを開く為の設定用構造体
//	OPENFILENAME ofn;
//
//	//ここに指定ファイルの絶対パスが代入される
//	char szFile[MAX_PATH];
//
//	//memset関数で変数・配列の中身を全てNULL、\0に
//	memset(&ofn, NULL, sizeof(OPENFILENAME));
//	memset(szFile, '\0', sizeof(szFile));
//
//	//自分自身のサイズ
//	ofn.lStructSize = sizeof(OPENFILENAME);
//	//親ウィンドウのハンドル
//	ofn.hwndOwner = hWnd;
//	//表示させるファイルのフィルタリング
//	ofn.lpstrFilter = "PNG Files {*.png}\0*.png\0"
//		"JPEG Files {*.jpg}\0*.jpg\0"
//		"BITMAP Files {*.bmp}\0*.bmp\0\0";
//	//パスを代入する配列
//	ofn.lpstrFile = szFile;
//	//パスの最大文字数
//	ofn.nMaxFile = MAX_PATH;
//	//ファイル名で拡張子が指定されなかった場合に追加する文字列
//	ofn.lpstrDefExt = ".png";
//	//ウィンドウの名前
//	ofn.lpstrTitle = "画像ファイルの選択";
//
//	//OFN_NOCHANGEDIR:カレントディレクトリを元の位置に戻す
//	//ディレクトリを戻さないとfopenやLoadGraphなどでファイルが見つからなくなってしまう
//	//OFN_HIDEREADONLY:読み取り専用を隠す
//	ofn.Flags = OFN_HIDEREADONLY | OFN_NOCHANGEDIR;
//
//	//ファイルオープンに失敗したらreturn
//	if (GetOpenFileName(&ofn) == 0) return -1;
//
//	//ファイル読み込み
//	img.enemy[0] = LoadGraph(szFile);
//	return 0;
//}
