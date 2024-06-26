
// MFCApplication3Dlg.h: 헤더 파일
//

#pragma once
#include <map>
#include <vector>
#include <iostream>

class SubDlg;
class SubEditDlg;
// CMFCApplication3Dlg 대화 상자
class CMFCApplication3Dlg : public CDialogEx
{
	// 생성입니다.
public:
	CMFCApplication3Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.5
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION3_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.

// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	void UpdateUI();
	int CMFCApplication3Dlg::GetFindCharCount(CString parm_string, char parm_find_char);
	void FileLoad(int index, const CString& filePath);
	void ResetUI();
	void FileWrite(int index, CString strCombo, CString fileName);
	void ListBoxLog(CString menu, CWnd& button);
	std::vector<std::vector<CString>> vec;
	//std::vector<std::vector<CString>> ReadIniToDoubleVector(const std::string& strIniFilePath, std::vector<std::vector<std::string>>& vecData);
	//std::vector<std::vector<std::string>> ConvertCStringVectorToStringVector(const std::vector<std::vector<CString>>& cStringVector);
	//std::vector<std::vector<CString>> ConvertToCString(const std::vector<std::vector<std::string>>& strVector);

public:
	afx_msg void OnDeleteButton();
	afx_msg void OnCbnSelchangeCombo2();
	afx_msg void ComboBoxOptionPlusClickedButton();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedButton4();
	afx_msg void ScrollControl(UINT nSBCode, UINT nPos, CScrollBar& pScrollBar);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnSaveButton();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnSubDlgButton();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton2();

public:

	CComboBox comboBox;

	CButton sub;
	CButton exit;
	CButton radio1;
	CButton radio2;
	CButton radio3;
	CButton checkBox1;
	CButton checkBox2;
	CButton checkBox3;
	CButton start;
	CButton stop;
	CButton reset;
	CButton saveBtn;
	CButton deleteBtn;
	CStatic staticLbl;

	CEdit staticEdit;
	CEdit hscrollEdit;
	CEdit vscrollEdit;
	CEdit checkEdit;

	CScrollBar hscroll;
	CScrollBar vscroll;

	CListBox cListBox;

private:
	int vscrollValue;
	int hscrollValue;

	UINT num;
	CString strCurDir;
	CString listBox;
	CString comboValue;
};
