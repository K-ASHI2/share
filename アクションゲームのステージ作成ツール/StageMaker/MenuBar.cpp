#include"DxLib.h"
#include"extern.h"
#include"function.h"
#include"resource.h"

//マップの大きさ変更時のダイアログ
LRESULT CALLBACK ChangeMapSizeDlg(HWND hDlg, UINT msg, WPARAM wp, LPARAM lp);

//コールバック
LRESULT CALLBACK MyWndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {

	int message;
	SCROLLINFO scr;

	switch (msg) {
	case WM_CLOSE:
		//変更されていればセーブするか聞く
		//YES:セーブして終了 NO:セーブせず終了 キャンセル:元の画面に戻る

		/*if(saveflag == 1){*/
		/*message = MessageBox(hMainWnd, "変更されています。セーブしますか？", "STAGE MAKER", MB_YESNOCANCEL);
		switch (message) {
		case IDYES:
			SaveMap();
			DestroyWindow(hWnd);
			break;
		case IDNO:
			DestroyWindow(hWnd);
			break;
		case IDCANCEL:
			return 0;
		}*/
		break;

	case WM_CREATE:
		scr.cbSize = sizeof(SCROLLINFO);
		scr.fMask = SIF_PAGE | SIF_RANGE | SIF_DISABLENOSCROLL;
		scr.nMin = 0;
		scr.nMax = 9;
		scr.nPage = 2;

		SetScrollInfo(hWnd, SB_VERT, &scr, TRUE);
		break;

	case WM_COMMAND:
		//子メニューのIDによって処理を行う
		//WPARAMの下位ワードに子メニューのIDが入っている
		switch (LOWORD(wp)) {
		case IDM_NEWFILE:
			//変更されていればセーブするか聞く
			//YES:セーブして終了 NO:セーブせずにひらく キャンセル:元の画面に戻る

			/*if(saveflag == 1){*/
			message = MessageBox(hMainWnd, "変更されています。セーブしますか？", "STAGE MAKER", MB_YESNOCANCEL);
			switch (message) {
			case IDYES:
				SaveMap();
				NewMap();
				init_c();
				break;
			case IDNO:
				NewMap();
				init_c();
				break;
			case IDCANCEL:
				break;
			}
			break;
		case IDM_OPENFILE:
			//ファイル読み込み
			//ファイルが選択されたらマップを読み込み初期化する
			if (MapFileOpen(hWnd, &CurrentFile) == 0) {
				ReadMap(CurrentFile);
				init_c();
			}
			break;
		case IDM_SAVE:
			SaveMap();
			break;
		case IDM_SAVEAS:
			if (MapFileSave(hWnd, &CurrentFile) == 0) {
				SaveMap();
			}
			break;
		case IDM_END:
			//終了の命令を送る
			SendMessage(hWnd, WM_CLOSE, NULL, NULL);
			break;

		case IDM_UNDO:
			UndoMap();
			break;
		case IDM_REDO:
			RedoMap();
			break;
		case IDM_TRIMMING:
			TrimmingMap();
			break;
		case IDM_COPY:
			CopyMap();
			break;
		case IDM_PASTE:
			PasteMap();
			break;
		case IDM_DELETE:
			DeleteMap();
			break;
		case IDM_CHANGE_SIZE:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)ChangeMapSizeDlg);
			break;
		}
		break;
	}
	return CallWindowProc(dxWndProc, hWnd, msg, wp, lp);
}

//マップの大きさ変更時のダイアログ
LRESULT CALLBACK ChangeMapSizeDlg(HWND hDlg, UINT msg, WPARAM wp, LPARAM lp) {

	int width = width_size, height = height_size;
	switch (msg) {
	case WM_INITDIALOG:
		SetDlgItemInt(hDlg, IDD_WIDTH, width, TRUE);
		SetDlgItemInt(hDlg, IDD_HEIGHT, height, TRUE);
		return TRUE;
	case WM_COMMAND:
		switch (LOWORD(wp)) {
		case IDCANCEL:
			//ダイアログを閉じる
			EndDialog(hDlg, IDOK);
			return TRUE;
		case IDOK:
			width = GetDlgItemInt(hDlg, IDD_WIDTH, NULL, TRUE);
			height = GetDlgItemInt(hDlg, IDD_HEIGHT, NULL, TRUE);
			ChangeMapSize(0, height - height_size, width, height);
			EndDialog(hDlg, IDOK);
			return TRUE;
		}
	}
	return FALSE;
}

////セーブしないで終了を押した時のダイアログの処理
////TRUEを返すとダイアログを閉じる
//LRESULT CALLBACK MyDlgProc(HWND hDlg, UINT msg, WPARAM wp, LPARAM lp) {
//
//	switch (msg) {
//	case WM_COMMAND:
//		switch (LOWORD(wp)) {
//		case IDOK:
//			//ダイアログを閉じる
//			EndDialog(hDlg, IDOK);
//			return TRUE;
//		case IDCANCEL:
//			int answer = MessageBox(hDlg, "設定を変更せずにダイアログを閉じます", "確認", MB_OKCANCEL);
//			if (answer == IDOK) {
//				EndDialog(hDlg, IDOK);
//			}
//			return TRUE;
//		}
//	}
//	return FALSE;
//}
