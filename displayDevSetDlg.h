
// displayDevSetDlg.h: 头文件
//
#pragma once
#include <Vector>
#include "DisplayDlg.h"
#include "resource.h"
typedef struct _tagVMonitorInfo_t
{
	HMONITOR hMonitor; //显示器句柄
	TCHAR szDevice[32]; //显示器名

	RECT rcVirtual; //虚拟显示屏坐标
	RECT rcMonitor; //物理显示坐标
	RECT rcWork; //工作显示坐标
	BOOL bPrimary; //主显示器

	_tagVMonitorInfo_t()
	{
		memset(this, 0, sizeof(*this));
	}
}VMONITORINFO;

// CdisplayDevSetDlg 对话框
class CdisplayDevSetDlg : public CDialog
{
// 构造
public:
	CdisplayDevSetDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DISPLAYDEVSET_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	CStatic m_Dev1;
	CStatic m_Dev2;
	CStatic m_Dev3;
	CStatic m_Dev4;

	CComboBox m_ComboDev1;
	CComboBox m_ComboDev2;
	CComboBox m_ComboDev3;
	CComboBox m_ComboDev4;
	//static std::vector<HMONITOR> g_hMonitorGroup;
	

	DisplayDlg* mDisplayDlg;

	static int m_iMontorNumber;
	static VMONITORINFO m_MonitorInfoExArray[64];


public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();

	afx_msg void OnCbnSelchangeCombo4();
	afx_msg void OnCbnSelchangeCombo3();
	afx_msg void OnCbnSelchangeCombo2();
	afx_msg void OnCbnSelchangeCombo1();

	void initView();

	void ReadDevInfo();

	static int MonitorEnumProc(HMONITOR hMonitor, HDC hdc, LPRECT lpRMonitor, LPARAM dwData);

	afx_msg void OnClose();
	afx_msg void OnBnClickedButton5();
	void SetConfig(int pos, int id);
	CString GetExePath();
};
