#pragma once
#include "resource.h"
class DisplayDlg : public CDialogEx
{
	DECLARE_DYNAMIC(DisplayDlg)
public:
	DisplayDlg(CWnd* pParent = NULL, int position = 0);
	~DisplayDlg();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnClose();
	afx_msg void OnPaint();
	virtual void DoDataExchange(CDataExchange* pDX);
	virtual BOOL OnInitDialog();

public:
	void SetText(CString x);
private :
	CDC memDC;//
	CString text;
	CFont m_newFont;   // ������   
	CFont *m_pOldFont; // ѡ��������֮ǰ������  
};

