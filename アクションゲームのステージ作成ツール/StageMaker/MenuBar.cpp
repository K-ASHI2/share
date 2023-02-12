#include"DxLib.h"
#include"extern.h"
#include"function.h"
#include"resource.h"

//�}�b�v�̑傫���ύX���̃_�C�A���O
LRESULT CALLBACK ChangeMapSizeDlg(HWND hDlg, UINT msg, WPARAM wp, LPARAM lp);

//�R�[���o�b�N
LRESULT CALLBACK MyWndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {

	int message;
	SCROLLINFO scr;

	switch (msg) {
	case WM_CLOSE:
		//�ύX����Ă���΃Z�[�u���邩����
		//YES:�Z�[�u���ďI�� NO:�Z�[�u�����I�� �L�����Z��:���̉�ʂɖ߂�

		/*if(saveflag == 1){*/
		/*message = MessageBox(hMainWnd, "�ύX����Ă��܂��B�Z�[�u���܂����H", "STAGE MAKER", MB_YESNOCANCEL);
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
		//�q���j���[��ID�ɂ���ď������s��
		//WPARAM�̉��ʃ��[�h�Ɏq���j���[��ID�������Ă���
		switch (LOWORD(wp)) {
		case IDM_NEWFILE:
			//�ύX����Ă���΃Z�[�u���邩����
			//YES:�Z�[�u���ďI�� NO:�Z�[�u�����ɂЂ炭 �L�����Z��:���̉�ʂɖ߂�

			/*if(saveflag == 1){*/
			message = MessageBox(hMainWnd, "�ύX����Ă��܂��B�Z�[�u���܂����H", "STAGE MAKER", MB_YESNOCANCEL);
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
			//�t�@�C���ǂݍ���
			//�t�@�C�����I�����ꂽ��}�b�v��ǂݍ��ݏ���������
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
			//�I���̖��߂𑗂�
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

//�}�b�v�̑傫���ύX���̃_�C�A���O
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
			//�_�C�A���O�����
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

////�Z�[�u���Ȃ��ŏI�������������̃_�C�A���O�̏���
////TRUE��Ԃ��ƃ_�C�A���O�����
//LRESULT CALLBACK MyDlgProc(HWND hDlg, UINT msg, WPARAM wp, LPARAM lp) {
//
//	switch (msg) {
//	case WM_COMMAND:
//		switch (LOWORD(wp)) {
//		case IDOK:
//			//�_�C�A���O�����
//			EndDialog(hDlg, IDOK);
//			return TRUE;
//		case IDCANCEL:
//			int answer = MessageBox(hDlg, "�ݒ��ύX�����Ƀ_�C�A���O����܂�", "�m�F", MB_OKCANCEL);
//			if (answer == IDOK) {
//				EndDialog(hDlg, IDOK);
//			}
//			return TRUE;
//		}
//	}
//	return FALSE;
//}
