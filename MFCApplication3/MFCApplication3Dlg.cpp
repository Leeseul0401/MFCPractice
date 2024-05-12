// MFCApplication3Dlg.cpp: 구현 파일
//
#include "stdafx.h"
#include "MFCApplication3.h"
#include "MFCApplication3Dlg.h"
#include "afxdialogex.h"
#include "SubDlg.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <locale.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication3Dlg 대화 상자

CMFCApplication3Dlg::CMFCApplication3Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION3_DIALOG, pParent)
	, vscrollValue(0)
	, hscrollValue(0)
	, comboValue(_T(""))
	, listBox(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	TCHAR szCurDir[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, szCurDir);
	strCurDir = szCurDir;
	strCurDir.Append(L"\\");
}

void CMFCApplication3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_COMBO2, comboBox);
	DDX_Control(pDX, IDC_BUTTON1, sub);
	DDX_Control(pDX, IDC_RADIO1, radio1);
	DDX_Control(pDX, IDC_RADIO2, radio2);
	DDX_Control(pDX, IDC_RADIO3, radio3);
	DDX_Control(pDX, IDC_CHECK1, checkBox1);
	DDX_Control(pDX, IDC_CHECK2, checkBox2);
	DDX_Control(pDX, IDC_CHECK3, checkBox3);
	DDX_Control(pDX, IDC_BUTTON3, start);
	DDX_Control(pDX, IDC_BUTTON4, stop);
	DDX_Control(pDX, IDC_BUTTON2, exit);
	DDX_Control(pDX, IDC_EDIT2, vscrollEdit);
	DDX_Control(pDX, IDC_EDIT1, staticEdit);
	DDX_Control(pDX, IDC_EDIT4, checkEdit);

	DDX_Control(pDX, IDC_SCROLLBAR1, hscroll);
	DDX_Control(pDX, IDC_SCROLLBAR2, vscroll);
	DDX_Control(pDX, IDC_EDIT3, hscrollEdit);
	DDX_Scroll(pDX, IDC_SCROLLBAR2, vscrollValue);
	DDX_Scroll(pDX, IDC_SCROLLBAR1, hscrollValue);
	DDX_CBString(pDX, IDC_COMBO2, comboValue);
	DDX_LBString(pDX, IDC_LIST1, listBox);
	DDX_Control(pDX, IDC_LIST1, cListBox);
	DDX_Control(pDX, IDC_BUTTON5, reset);
	DDX_Control(pDX, IDC_BUTTON7, saveBtn);
	DDX_Control(pDX, IDC_BUTTON6, deleteBtn);
}

BEGIN_MESSAGE_MAP(CMFCApplication3Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication3Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication3Dlg::OnBnClickedButton3)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CMFCApplication3Dlg::OnCbnSelchangeCombo2)
	ON_EN_CHANGE(IDC_EDIT1, &CMFCApplication3Dlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CMFCApplication3Dlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT4, &CMFCApplication3Dlg::OnEnChangeEdit4)
	ON_BN_CLICKED(IDC_CHECK1, &CMFCApplication3Dlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &CMFCApplication3Dlg::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK3, &CMFCApplication3Dlg::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_RADIO1, &CMFCApplication3Dlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CMFCApplication3Dlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CMFCApplication3Dlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication3Dlg::OnBnClickedButton4)
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
	ON_WM_TIMER()
	ON_LBN_SELCHANGE(IDC_LIST1, &CMFCApplication3Dlg::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication3Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication3Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCApplication3Dlg::OnBnClickedButton7)
	ON_EN_CHANGE(IDC_EDIT3, &CMFCApplication3Dlg::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication3Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCApplication3Dlg::OnBnClickedButton8)
END_MESSAGE_MAP()


// CMFCApplication3Dlg 메시지 처리기

BOOL CMFCApplication3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	
	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	/*
	TCHAR szCurDir[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, szCurDir);
	CString strCurDir(szCurDir);
	CString strRelativePath = _T("Data.ini");
	CStringA strFilePath(strCurDir + _T("\\") + strRelativePath);
	*/
	

	//std::ifstream inputFile(strFilePath);
	std::string line;
	/*
	while (std::getline(inputFile, line)) {
		CString strLine(line.c_str());	
		//comboBox.SetCurSel(_ttoi(strLine));
	}
	*/
	
	comboBox.AddString(_T("default"));
	comboBox.AddString(_T("apple"));
	comboBox.AddString(_T("banana"));
	comboBox.AddString(_T("grape"));
	/*
	CString listStr;
	comboBox.GetWindowTextW(listStr);
	for (int i = 0; i < vec.size(); i++) 
	{
		for (int j = 0; j < vec[i].size(); j++)5
		{
			if (listStr == vec[i][j])  
			{
				//comboBox.SetWindowTextW(vec[i][j]);
			}
		}
	}
	*/

	if (comboBox.GetCount() > 0)
	{
		comboBox.SetCurSel(0);
	}

	SetDlgItemText(IDC_CHECK1, _T("book"));
	SetDlgItemText(IDC_CHECK2, _T("chair"));
	SetDlgItemText(IDC_CHECK3, _T("desk"));
	CString str;

	
	SetDlgItemText(IDC_LIST1, str);
	vscroll.SetScrollRange(0, 255);
	hscroll.SetScrollRange(0, 255);
	CString zero;
	zero = "0";

	SetDlgItemText(IDC_EDIT2, zero);
	SetDlgItemText(IDC_EDIT3, zero);
	SetDlgItemText(IDC_EDIT1, zero);

	std::vector<CString> default;
	std::vector<CString> apple;
	std::vector<CString> banana;
	std::vector<CString> grape;

	vec.push_back(default);
	vec.push_back(apple);
	vec.push_back(banana);
	vec.push_back(grape);

	CString fileName;
	fileName = _T("Data_default.txt");

	CString strFilePath = strCurDir + fileName;
	FileLoad(0, strFilePath);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCApplication3Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCApplication3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCApplication3Dlg::OnEnChangeEdit1()
{
}

void CMFCApplication3Dlg::OnBnClickedButton3()
{
	CString str;
	staticEdit.GetWindowTextW(str);
	num = _ttoi(str);
	SetTimer(1, num, NULL);
}

void CMFCApplication3Dlg::OnBnClickedButton1()
{
	int index = comboBox.GetCurSel();
	if (index != 0) {
		comboBox.DeleteString(index);
		
		comboBox.SetCurSel(index-1);
		
	}
	else 
	{
		AfxMessageBox(_T("default는 삭제 할 수 없습니다!"), MB_OK | MB_ICONWARNING);
	}
}

void CMFCApplication3Dlg::UpdateUI()
{
}

int CMFCApplication3Dlg::GetFindCharCount(CString parm_string, char parm_find_char)
{
	int find_count = 0;
	int caret = 0;
	while (true)
	{
		caret = parm_string.Find(parm_find_char, caret + 1);
		if (caret < 0)
			break;

		find_count++;
	}

	return find_count;
}

void CMFCApplication3Dlg::FileLoad(int index, const CString & filePath)
{
	CFileException ex;
	CFile file;
	if (file.Open(filePath, CFile::modeRead, &ex))
	{
		CString data;
		auto size = file.Read(data.GetBufferSetLength(file.GetLength() / sizeof(TCHAR)), file.GetLength());

		vec[index].clear();

		int sepCount = GetFindCharCount(data, ':');
		CString* temp = new CString[sepCount + 1];
		int cnt = 0;
		CString strTok;
		while (1)
		{
			AfxExtractSubString(strTok, data, cnt, ':');
			if (sepCount >= cnt)
			{
				temp[cnt++] = strTok;
			}
			else
			{
				break;
			}

		}

		for (int i = 0; i < sepCount; i++)
		{
			vec[index].push_back(temp[i]);
		}
		delete[] temp;

		if (vec[index].size() > 0)
		{
			CString str;
			str = vec[index][1].GetString();
			num = _ttoi(str);
			int Hour = num / 3600;
			int Minute = (num / 60) % 60;
			int Second = num % 60;

			str.Format(_T("%dhour %dmin %dsec"), Hour, Minute, Second);
			SetDlgItemTextW(IDC_STATIC, str);

			str = vec[index][2].GetString();
			if (str == "Radio1")
			{
				radio1.SetCheck(TRUE);
			}
			else if (str == "Radio2")
			{
				radio2.SetCheck(TRUE);

				checkBox1.ShowWindow(SW_HIDE);
				checkBox2.ShowWindow(SW_HIDE);
				checkBox3.ShowWindow(SW_HIDE);
			}
			else if (str == "Radio3")
			{
				radio3.SetCheck(TRUE);

				checkBox1.SetCheck(FALSE);
				checkBox2.SetCheck(FALSE);
				checkBox3.SetCheck(FALSE);

				checkBox1.EnableWindow(FALSE);
				checkBox2.EnableWindow(FALSE);
				checkBox3.EnableWindow(FALSE);

				checkBox1.ShowWindow(SW_SHOW);
				checkBox2.ShowWindow(SW_SHOW);
				checkBox3.ShowWindow(SW_SHOW);
			}

			str = vec[index][3].GetString();
			checkBox1.SetCheck(str == "book");

			str = vec[index][4].GetString();
			checkBox2.SetCheck(str == "chair");

			str = vec[index][5].GetString();
			checkBox3.SetCheck(str == "desk");

			str = vec[index][6].GetString();
			SetDlgItemTextW(IDC_STATIC, str);

			str = vec[index][7].GetString();
			staticEdit.SetWindowTextW(str);

			str = vec[index][8].GetString();
			hscroll.SetScrollPos(_ttoi(str));
			hscrollEdit.SetWindowTextW(str);

			str = vec[index][9].GetString();
			vscroll.SetScrollPos(_ttoi(str));
			vscrollEdit.SetWindowTextW(str);
		}
	}
	else {
		ex.ReportError();
	}

}

void CMFCApplication3Dlg::ResetUI()
{
	radio1.SetCheck(FALSE);
	radio2.SetCheck(FALSE);
	radio3.SetCheck(FALSE);

	checkBox1.SetCheck(FALSE);
	checkBox2.SetCheck(FALSE);
	checkBox3.SetCheck(FALSE);

	SetDlgItemText(IDC_STATIC, L"hour  min  sec");

	hscroll.SetScrollPos(0);

	SetDlgItemTextW(IDC_EDIT1, _T("0"));
	SetDlgItemTextW(IDC_EDIT2, _T("0"));
	SetDlgItemTextW(IDC_EDIT3, _T("0"));

	vscroll.SetScrollPos(0);

	checkBox1.EnableWindow(TRUE);
	checkBox2.EnableWindow(TRUE);
	checkBox3.EnableWindow(TRUE);

	checkBox1.ShowWindow(SW_SHOW);
	checkBox2.ShowWindow(SW_SHOW);
	checkBox3.ShowWindow(SW_SHOW);

}

void CMFCApplication3Dlg::OnCbnSelchangeCombo2()
{
	int index = comboBox.GetCurSel();
	num = 1;

	ResetUI();

	CString str;
	comboBox.GetLBText(index, str);

	CString fileName;
	fileName = _T("Data_") + str + _T(".txt");

	CString strFilePath = strCurDir + fileName;
	FileLoad(index, strFilePath);

	CString result;
	result.Format(_T("combo Box ---- %s"), str);
	cListBox.InsertString(-1, result);
	cListBox.SetTopIndex(cListBox.GetCount() - 1);
}

void CMFCApplication3Dlg::OnBnClickedRadio1()
{
	if (radio1.GetCheck() == BST_CHECKED)
	{
		checkBox1.EnableWindow(TRUE);
		checkBox2.EnableWindow(TRUE);
		checkBox3.EnableWindow(TRUE);

		checkBox1.ShowWindow(SW_SHOW);
		checkBox2.ShowWindow(SW_SHOW);
		checkBox3.ShowWindow(SW_SHOW);

		CString str;
		radio1.GetWindowTextW(str);
		CString result;
		result.Format(_T("Radio Box ---- %s"), str);
		cListBox.InsertString(-1, result);
		cListBox.SetTopIndex(cListBox.GetCount() - 1);
	}
}


void CMFCApplication3Dlg::OnBnClickedCheck1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString msg;
	if (checkBox1.GetCheck() == BST_CHECKED)
	{
		GetDlgItemText(IDC_CHECK1, msg);
		CString str;
		checkBox1.GetWindowTextW(str);
		CString result;
		result.Format(_T("check Box ---- %s"), str);
		cListBox.InsertString(-1, result);
		cListBox.SetTopIndex(cListBox.GetCount() - 1);
	}

	checkEdit.SetWindowTextW(msg);


}


void CMFCApplication3Dlg::OnEnChangeEdit2()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.

}

void CMFCApplication3Dlg::OnEnChangeEdit4()
{
}






void CMFCApplication3Dlg::OnBnClickedCheck2()
{
	CString msg;
	if (checkBox2.GetCheck() == BST_CHECKED)
	{
		GetDlgItemText(IDC_CHECK2, msg);

		CString str;
		checkBox2.GetWindowTextW(str);
		CString result;
		result.Format(_T("check Box ---- %s"), str);
		cListBox.InsertString(-1, result);
		cListBox.SetTopIndex(cListBox.GetCount() - 1);
	}

	checkEdit.SetWindowTextW(msg);
}


void CMFCApplication3Dlg::OnBnClickedCheck3()
{
	CString msg;
	if (checkBox3.GetCheck() == BST_CHECKED)
	{
		GetDlgItemText(IDC_CHECK3, msg);

		CString str;
		checkBox3.GetWindowTextW(str);
		CString result;
		result.Format(_T("check Box ---- %s"), str);
		cListBox.InsertString(-1, result);
		cListBox.SetTopIndex(cListBox.GetCount() - 1);

	}

	checkEdit.SetWindowTextW(msg);
}


void CMFCApplication3Dlg::OnBnClickedRadio2()
{
	if (radio2.GetCheck() == BST_CHECKED)
	{
		checkBox1.ShowWindow(SW_HIDE);
		checkBox2.ShowWindow(SW_HIDE);
		checkBox3.ShowWindow(SW_HIDE);


		//int index = comboBox.GetCurSel();
		CString str;
		radio2.GetWindowTextW(str);
		CString result;
		result.Format(_T("Radio Box ---- %s"), str);
		cListBox.InsertString(-1, result);
		cListBox.SetTopIndex(cListBox.GetCount() - 1);
	}
}


void CMFCApplication3Dlg::OnBnClickedRadio3()
{
	if (radio3.GetCheck() == BST_CHECKED)
	{
		
		checkBox1.EnableWindow(FALSE);
		checkBox2.EnableWindow(FALSE);
		checkBox3.EnableWindow(FALSE);

		checkBox1.ShowWindow(SW_SHOW);
		checkBox2.ShowWindow(SW_SHOW);
		checkBox3.ShowWindow(SW_SHOW);

		CString str;
		radio3.GetWindowTextW(str);
		CString result;
		result.Format(_T("Radio Box ---- %s"), str);
		cListBox.InsertString(-1, result);
		cListBox.SetTopIndex(cListBox.GetCount() - 1);
	}
}

void CMFCApplication3Dlg::OnBnClickedButton4()
{
	KillTimer(1);
	CString listStr;
	stop.GetWindowTextW(listStr);
	CString s;
	GetDlgItemTextW(IDC_STATIC, s);
	CString result;
	result.Format(_T("Time Lapse ---- stop : %s"), s);
	cListBox.InsertString(-1, result);
	cListBox.SetTopIndex(cListBox.GetCount() - 1);
}


void CMFCApplication3Dlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	ScrollControl(nSBCode, nPos, *pScrollBar);

	UpdateData(TRUE);//컨트롤 값을 변수로 전송

	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
	int hpos = hscroll.GetScrollPos();
	CString str;
	str.Format(_T("%d"), hpos);
	hscrollEdit.SetWindowTextW(str);


	if (nSBCode == SB_ENDSCROLL)
	{
		CString listStr;
		hscrollEdit.GetWindowTextW(listStr);
		CString result;
		result.Format(_T("가로 스크롤바 ---- %s"), listStr);
		cListBox.InsertString(-1, result);
		cListBox.SetTopIndex(cListBox.GetCount() - 1);
	}
}

void CMFCApplication3Dlg::ScrollControl(UINT nSBCode, UINT nPos, CScrollBar& pScrollBar)
{

	switch (nSBCode)
	{

	case SB_LINEUP: //scrolls one line up (한 줄 위로 스크롤)
		pScrollBar.SetScrollPos(pScrollBar.GetScrollPos() - 1);
		break;

	case SB_LINEDOWN: //scrolls one line down( 한 줄 아래로 스크롤)
		pScrollBar.SetScrollPos(pScrollBar.GetScrollPos() + 1);
		break;

	case SB_PAGEUP://scrolls one page up( 유저가 스크롤 바의 바 위쪽을 누름)
		pScrollBar.SetScrollPos(pScrollBar.GetScrollPos() - 2);
		break;

	case SB_PAGEDOWN://scrolls one page down(유저가 스크롤 바의 바 아래쪽을 누름)
		pScrollBar.SetScrollPos(pScrollBar.GetScrollPos() + 2);
		break;

	case SB_TOP://scrolls to the upper left(제일 위쪽에 스크롤된다)
		pScrollBar.SetScrollPos(0);
		break;

	case SB_BOTTOM: //scrolls to the lower right.(제일 아래쪽에 스크롤된다)
		pScrollBar.SetScrollPos(pScrollBar.GetScrollLimit());
		break;

	case SB_THUMBTRACK: //The user is dragging the scroll box.( 유저가 스크롤을 드래그 한다.) 
		pScrollBar.SetScrollPos(nPos);
		break;

	default:
		break;
	}
}


void CMFCApplication3Dlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	ScrollControl(nSBCode, nPos, *pScrollBar);

	UpdateData(TRUE);

	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
	
	CString str;
	str.Format(_T("%d"), vscrollValue);
	vscrollEdit.SetWindowText(str);

	if (nSBCode == SB_ENDSCROLL)
	{
		CString listStr;
		vscrollEdit.GetWindowTextW(listStr);
		CString result;
		result.Format(_T("세로 스크롤바 ---- %s"), listStr);
		cListBox.InsertString(-1, result);
		cListBox.SetTopIndex(cListBox.GetCount() - 1);
	}
}


void CMFCApplication3Dlg::OnTimer(UINT_PTR nIDEvent)
{
		
	if (nIDEvent == 1)
	{
		int Hour = num / 3600;
		int Minute = (num / 60) % 60;
		int Second = num % 60;
		CString str;
		str.Format(_T("%dhour %dmin %dsec"), Hour, Minute, Second);
		SetDlgItemTextW(IDC_STATIC, str);
		num++;

		
	}

	
}


void CMFCApplication3Dlg::OnLbnSelchangeList1()
{	
	/*
	int index = cListBox.GetCurSel();
	CString str;
	comboBox.GetLBText(index, str);
	
	cListBox.InsertString(-1, str);
	cListBox.SetTopIndex(cListBox.GetCount() - 1);
	*/
}


void CMFCApplication3Dlg::OnBnClickedButton5()
{
	int Hour = 0;
	int Minute = 0;
	int Second = 0;
	num = 1;
	CString str;
	str.Format(_T("%dhour %dmin %dsec"), Hour, Minute, Second);
	SetDlgItemTextW(IDC_STATIC, str);
	
	CString listStr;
	reset.GetWindowTextW(listStr);
	CString result;
	result.Format(_T("Time Lapse ---- %s"), listStr);
	cListBox.InsertString(-1, result);
	cListBox.SetTopIndex(cListBox.GetCount() - 1);
}


void CMFCApplication3Dlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::DestroyWindow();
}



void CMFCApplication3Dlg::OnBnClickedButton7()
{
	int index = comboBox.GetCurSel();
	//int radio = comboBox.SetItemData(index, )
	
	vec[index].clear();
	CString chk;

	chk.Format(_T("%d"), index);
	vec[index].push_back(chk);

	CString str;
	str.Format(_T("%d"), num);
	vec[index].push_back(str);
	if (radio1.GetCheck())
	{
		GetDlgItemTextW(IDC_RADIO1, chk);
		vec[index].push_back(chk);
	}
	else if (radio2.GetCheck())
	{
		GetDlgItemTextW(IDC_RADIO2, chk);
		vec[index].push_back(chk);
	}
	else if (radio3.GetCheck())
	{
		GetDlgItemTextW(IDC_RADIO3, chk);
		vec[index].push_back(chk);
	}

	//
	if (checkBox1.GetCheck())
	{
		GetDlgItemTextW(IDC_CHECK1, chk);
		vec[index].push_back(chk);
	}
	else
	{
		vec[index].push_back(L"");
	}

	if (checkBox2.GetCheck())
	{
		GetDlgItemTextW(IDC_CHECK2, chk);
		vec[index].push_back(chk);
	}
	else
	{
		vec[index].push_back(L"");
	}

	if (checkBox3.GetCheck())
	{
		GetDlgItemTextW(IDC_CHECK3, chk);
		vec[index].push_back(chk);
	}
	else
	{
		vec[index].push_back(L"");
	}

	GetDlgItemTextW(IDC_STATIC, chk);
	vec[index].push_back(chk);

	GetDlgItemTextW(IDC_EDIT1, chk);
	vec[index].push_back(chk);

	GetDlgItemTextW(IDC_EDIT3, chk);
	vec[index].push_back(chk);

	GetDlgItemTextW(IDC_EDIT2, chk);
	vec[index].push_back(chk);



	// 파일 출력 코드 추가
	CString strCombo;
	CString fileName;
	comboBox.GetLBText(index, strCombo);
	fileName = _T("Data_") + strCombo + _T(".txt");

	// 텍스트 파일에 값을 쓰기
	CString strFilePath = strCurDir + fileName;
	CFile file;
	//setlocale(LC_ALL, "korean");
	if (file.Open(strFilePath, CFile::modeCreate | CFile::modeWrite))
	{
		for (int i = 0; i < vec.size(); i++) {
			if (index != i)
				continue;

			for (auto cstr : vec[i]) {
				//std::string str = std::string(CT2CA(cstr));
				//str += '\n';
				//file.Write(str.data(), str.length());
				cstr.AppendChar(':');
				file.Write(cstr, cstr.GetLength() * sizeof(TCHAR));
			}
		}
	}
	file.Close();

	//std::ofstream outputFile(fileName); // 출력 파일 열기
	//std::ifstream inputFile("Data.ini");

	/*
	if (outputFile.is_open()) {

		outputFile.close(); // 파일 닫기
		AfxMessageBox(_T("save"), MB_OK | MB_ICONINFORMATION);
	}
	else 
	{
		AfxMessageBox(_T("출력 파일을 열 수 없습니다."), MB_OK | MB_ICONERROR);
	}
	*/

	
}


void CMFCApplication3Dlg::OnEnChangeEdit3()
{
}


void CMFCApplication3Dlg::OnBnClickedButton6()
{
	SubDlg* subDlg = new SubDlg(this);
	subDlg->Create(IDD_SubDlg, this);
	subDlg->ShowWindow(SW_SHOW);
}
void CMFCApplication3Dlg::OnBnClickedButton8()
{
	CString str;
	comboBox.GetWindowTextW(str);
	comboBox.AddString(str);
	AfxMessageBox(str + _T("이/가 추가되었습니다."), MB_OK | MB_ICONINFORMATION);

}
