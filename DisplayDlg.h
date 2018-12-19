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
	CFont m_newFont;   // 新字体   
	CFont *m_pOldFont; // 选择新字体之前的字体  
};

