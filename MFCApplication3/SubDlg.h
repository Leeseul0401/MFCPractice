#pragma once

// SubDlg 대화 상자
class CMFCApplication3Dlg;
class SubDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SubDlg)

public:
	SubDlg(CWnd* pParent);   // 표준 생성자입니다.
	virtual ~SubDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SubDlg };
#endif

protected:
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP();

public:
	CMFCApplication3Dlg* pParent;
	CListBox listbox;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnLbnSelchangeList1();
};
