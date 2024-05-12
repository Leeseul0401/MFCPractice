// SubDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "MFCApplication3.h"
#include "SubDlg.h"
#include "afxdialogex.h"
#include "MFCApplication3Dlg.h"


// SubDlg 대화 상자

IMPLEMENT_DYNAMIC(SubDlg, CDialogEx)

SubDlg::SubDlg(CWnd* pParent)
	: CDialogEx(IDD_SubDlg, pParent)
{
	this->pParent = (CMFCApplication3Dlg*)(pParent);
}

SubDlg::~SubDlg()
{
}

BOOL SubDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	listbox.ResetContent();

	CString s;
	//pParent->comboBox.GetWindowTextW(s);
	//s.Format(L"%ls", s);
	//listbox.AddString(s);

	if (pParent->checkBox1.GetCheck())
	{
		pParent->checkBox1.GetWindowTextW(s);
		s.Format(L"%ls", s);
		listbox.AddString(s);
	}

	if (pParent->checkBox2.GetCheck ())
	{
		pParent->checkBox2.GetWindowTextW(s);
		s.Format(L"%ls", s);
		listbox.AddString(s);
	}

	if (pParent->checkBox3.GetCheck())
	{
		pParent->checkBox3.GetWindowTextW(s);
		s.Format(L"%ls", s);
		listbox.AddString(s);
	}

	if (pParent->radio1.GetCheck())
	{
		pParent->radio1.GetWindowTextW(s);
		s.Format(L"%ls", s);
		listbox.AddString(s);
	}

	if (pParent->radio2.GetCheck())
	{
		pParent->radio2.GetWindowTextW(s);
		s.Format(L"%ls", s);
		listbox.AddString(s);
	}

	if (pParent->radio3.GetCheck())
	{
		pParent->radio3.GetWindowTextW(s);
		s.Format(L"%ls", s);
		listbox.AddString(s);
	}
	
	
	pParent->vscrollEdit.GetWindowTextW(s);
	s.Format(L"%ls", s);
	listbox.AddString(s);
	
	pParent->hscrollEdit.GetWindowTextW(s);
	s.Format(L"%ls", s);
	listbox.AddString(s);

	pParent->staticEdit.GetWindowTextW(s);
	s.Format(L"%ls", s);
	listbox.AddString(s);

	//pParent->staticLbl.GetWindowTextW(s);
	pParent->GetDlgItemTextW(IDC_STATIC, s);
	s.Format(L"%ls", s);
	listbox.AddString(s);

	pParent->GetDlgItemTextW(IDC_COMBO2, s);
	if (!s.IsEmpty())
	{
		s.Format(L"%ls", s);
		listbox.AddString(s);
	}

	return TRUE;

}

void SubDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, listbox);
}


BEGIN_MESSAGE_MAP(SubDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON4, &SubDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON1, &SubDlg::OnBnClickedButton1)
	ON_LBN_SELCHANGE(IDC_LIST1, &SubDlg::OnLbnSelchangeList1)
END_MESSAGE_MAP()



// SubDlg 메시지 처리기


void SubDlg::OnBnClickedButton4()
{
	CDialogEx::DestroyWindow();
}


void SubDlg::OnBnClickedButton1()
{	

	OnInitDialog();
}


void SubDlg::OnLbnSelchangeList1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
