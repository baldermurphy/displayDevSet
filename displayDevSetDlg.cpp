
// displayDevSetDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "displayDevSet.h"
#include "displayDevSetDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CdisplayDevSetDlg 对话框

int CdisplayDevSetDlg::m_iMontorNumber;
VMONITORINFO CdisplayDevSetDlg::m_MonitorInfoExArray[64];

CdisplayDevSetDlg::CdisplayDevSetDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DISPLAYDEVSET_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CdisplayDevSetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC1, m_Dev1);
	DDX_Control(pDX, IDC_STATIC2, m_Dev2);
	DDX_Control(pDX, IDC_STATIC3, m_Dev3);
	DDX_Control(pDX, IDC_STATIC4, m_Dev4);

	DDX_Control(pDX, IDC_COMBO1, m_ComboDev1);
	DDX_Control(pDX, IDC_COMBO2, m_ComboDev2);
	DDX_Control(pDX, IDC_COMBO3, m_ComboDev3);
	DDX_Control(pDX, IDC_COMBO4, m_ComboDev4);

}

BEGIN_MESSAGE_MAP(CdisplayDevSetDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CdisplayDevSetDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CdisplayDevSetDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CdisplayDevSetDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CdisplayDevSetDlg::OnBnClickedButton4)
	ON_CBN_SELCHANGE(IDC_COMBO4, &CdisplayDevSetDlg::OnCbnSelchangeCombo4)
	ON_CBN_SELCHANGE(IDC_COMBO3, &CdisplayDevSetDlg::OnCbnSelchangeCombo3)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CdisplayDevSetDlg::OnCbnSelchangeCombo2)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CdisplayDevSetDlg::OnCbnSelchangeCombo1)

	

	//ON_STN_CLICKED(IDC_STATIC1, &CdisplayDevSetDlg::OnStnClickedStatic1)
	//ON_STN_CLICKED(IDC_STATIC2, &CdisplayDevSetDlg::OnStnClickedStatic2)
	//ON_STN_CLICKED(IDC_STATIC3, &CdisplayDevSetDlg::OnStnClickedStatic3)
	//ON_STN_CLICKED(IDC_STATIC4, &CdisplayDevSetDlg::OnStnClickedStatic4)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON5, &CdisplayDevSetDlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CdisplayDevSetDlg 消息处理程序

BOOL CdisplayDevSetDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	ShowWindow(SW_MAXIMIZE);

	//ShowWindow(SW_MINIMIZE);
	ReadDevInfo();
	initView();


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CdisplayDevSetDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}


HCURSOR CdisplayDevSetDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CdisplayDevSetDlg::OnBnClickedButton1(){
	int pos=0;
	pos=m_ComboDev1.GetCurSel();
	CString strtext;
	m_ComboDev1.GetLBText(pos, strtext);
	mDisplayDlg->ShowWindow(SW_SHOW);
	mDisplayDlg->SetText(strtext);
	mDisplayDlg->MoveWindow(CRect(m_MonitorInfoExArray[0].rcMonitor));
}


void CdisplayDevSetDlg::OnBnClickedButton2(){
	int pos = 0;
	pos = m_ComboDev2.GetCurSel();
	CString strtext;
	m_ComboDev2.GetLBText(pos, strtext);
	mDisplayDlg->ShowWindow(SW_SHOW);
	mDisplayDlg->SetText(strtext);
	mDisplayDlg->MoveWindow(CRect(m_MonitorInfoExArray[1].rcMonitor));
}


void CdisplayDevSetDlg::OnBnClickedButton3()
{
	int pos = 0;
	//m_ComboDev3.SetCurSel(pos);
	pos = m_ComboDev3.GetCurSel();
	CString strtext;
	m_ComboDev3.GetLBText(pos, strtext);
	mDisplayDlg->ShowWindow(SW_SHOW);
	mDisplayDlg->SetText(strtext);
	mDisplayDlg->MoveWindow(CRect(m_MonitorInfoExArray[2].rcMonitor));
	
}


void CdisplayDevSetDlg::OnBnClickedButton4()
{
	int pos = 0;
	//m_ComboDev4.SetCurSel(pos);
	pos = m_ComboDev4.GetCurSel();
	CString strtext;
	m_ComboDev4.GetLBText(pos, strtext);
	mDisplayDlg->ShowWindow(SW_SHOW);
	mDisplayDlg->SetText(strtext);
	mDisplayDlg->MoveWindow(CRect(m_MonitorInfoExArray[3].rcMonitor));
	
}


void CdisplayDevSetDlg::OnCbnSelchangeCombo4()
{
	
}


void CdisplayDevSetDlg::OnCbnSelchangeCombo3(){
	
}


void CdisplayDevSetDlg::OnCbnSelchangeCombo2(){
	
}


void CdisplayDevSetDlg::OnCbnSelchangeCombo1(){


}
void CdisplayDevSetDlg::initView() {
	for (int i = 0; i < m_iMontorNumber; i++) {
		switch (i)
		{
		case 0:
			m_Dev1.SetWindowTextW(m_MonitorInfoExArray[i].szDevice);
			m_ComboDev1.AddString(_T("无配置"));
			m_ComboDev1.AddString(_T("输出照片屏幕"));
			m_ComboDev1.AddString(_T("视频屏幕"));
			m_ComboDev1.AddString(_T("投影屏幕"));
			
			m_ComboDev1.SetCurSel(0);
			break;
		case 1:
			m_Dev2.SetWindowTextW(m_MonitorInfoExArray[i].szDevice);
			m_ComboDev2.AddString(_T("无配置"));
			m_ComboDev2.AddString(_T("输出照片屏幕"));
			m_ComboDev2.AddString(_T("视频屏幕"));
			m_ComboDev2.AddString(_T("投影屏幕"));
			
			m_ComboDev2.SetCurSel(0);
			break;
		case 2:
			m_Dev3.SetWindowTextW(m_MonitorInfoExArray[i].szDevice);
			m_ComboDev3.AddString(_T("无配置"));
			m_ComboDev3.AddString(_T("输出照片屏幕"));
			m_ComboDev3.AddString(_T("视频屏幕"));
			m_ComboDev3.AddString(_T("投影屏幕"));
			
			m_ComboDev3.SetCurSel(0);
			break;
		case 3:
			m_Dev4.SetWindowTextW(m_MonitorInfoExArray[i].szDevice);
			m_ComboDev4.AddString(_T("无配置"));
			m_ComboDev4.AddString(_T("输出照片屏幕"));
			m_ComboDev4.AddString(_T("视频屏幕"));
			m_ComboDev4.AddString(_T("投影屏幕"));
			m_ComboDev4.SetCurSel(0);
			break;
		default:
			break;
		}
	}
	mDisplayDlg = new DisplayDlg(NULL);
	mDisplayDlg->Create(IDD_DIALOG1);
	mDisplayDlg->ShowWindow(SW_HIDE);

}

void CdisplayDevSetDlg::ReadDevInfo() {
	m_iMontorNumber = 0;
	EnumDisplayMonitors(NULL, NULL, MonitorEnumProc, NULL);
}

 int CALLBACK CdisplayDevSetDlg::MonitorEnumProc(HMONITOR hMonitor,
	HDC hdc,
	LPRECT lpRMonitor,
	LPARAM dwData) {
	//g_hMonitorGroup.push_back(hMonitor);


	if (lpRMonitor)
	{
		printf(("%p (l=%d t=%d r=%d b=%d)\n"),
			hMonitor,
			lpRMonitor->left, lpRMonitor->top,
			lpRMonitor->right, lpRMonitor->bottom);
	}

	//GetMonitorInfo 获取显示器信息
	MONITORINFOEX infoEx;
	memset(&infoEx, 0, sizeof(infoEx));
	infoEx.cbSize = sizeof(infoEx);
	if (GetMonitorInfo(hMonitor, &infoEx))
	{
		USES_CONVERSION;
		printf(("%p [%s] %s rcMonitor(l=%d t=%d r=%d b=%d) rcWork(l=%d t=%d r=%d b=%d) \n \n \n \n"),
			hMonitor,
			T2A(infoEx.szDevice),
			infoEx.dwFlags == MONITORINFOF_PRIMARY ? ("Primary") : ("Slave"),
			infoEx.rcMonitor.left, infoEx.rcMonitor.top, infoEx.rcMonitor.right, infoEx.rcMonitor.bottom,
			infoEx.rcWork.left, infoEx.rcWork.top, infoEx.rcWork.right, infoEx.rcWork.bottom);
	}

	//保存显示器信息
	if (m_iMontorNumber < 63)
	{
		VMONITORINFO *pInfo = &m_MonitorInfoExArray[m_iMontorNumber];
		pInfo->hMonitor = hMonitor;
		if (lpRMonitor)
		{
			pInfo->rcVirtual = *lpRMonitor;
		}
		pInfo->rcMonitor = infoEx.rcMonitor;
		pInfo->rcWork = infoEx.rcWork;
		pInfo->bPrimary = (infoEx.dwFlags== MONITORINFOF_PRIMARY);
		_tcscpy_s(pInfo->szDevice, infoEx.szDevice);

		m_iMontorNumber++;

		return TRUE; //continue the enumeration
	}
	return 1;
}







 void CdisplayDevSetDlg::OnClose()
 {
	 // TODO: 在此添加消息处理程序代码和/或调用默认值
	 delete mDisplayDlg;
	 mDisplayDlg = NULL;
	 CDialog::OnClose();
 }


 void CdisplayDevSetDlg::OnBnClickedButton5(){
	 int pos = 0;
	 pos = m_ComboDev1.GetCurSel();
	 if (pos != 0) {
		 SetConfig(pos, 0);
	 }
	 pos = 0;
	 pos = m_ComboDev2.GetCurSel();
	 if (pos != 0) {
		 SetConfig(pos, 1);
	 }
	 pos = 0;
	 pos = m_ComboDev3.GetCurSel();
	 if (pos != 0) {
		 SetConfig(pos, 2);
	 }
	 pos = 0;
	 pos = m_ComboDev4.GetCurSel();
	 if (pos != 0) {
		 SetConfig(pos, 3);
	 }
 }
 void CdisplayDevSetDlg::SetConfig(int pos,int id) {
	 CString strcfgpath = GetExePath();
	 strcfgpath += _T("\\config.cfg");
	 CString temp;
	 switch (pos)
	 {
	 case 1:
		 temp.Format(_T("%ld"), m_MonitorInfoExArray[id].rcMonitor.left);
		 WritePrivateProfileString(TEXT("image_wnd"), TEXT("left"), temp.GetBuffer(), strcfgpath.GetBuffer());
		 temp.Format(_T("%ld"), m_MonitorInfoExArray[id].rcMonitor.top);
		 WritePrivateProfileString(TEXT("image_wnd"), TEXT("top"), temp.GetBuffer(), strcfgpath.GetBuffer());
		 temp.Format(_T("%ld"), m_MonitorInfoExArray[id].rcMonitor.bottom);
		 WritePrivateProfileString(TEXT("image_wnd"), TEXT("bottom"), temp.GetBuffer(), strcfgpath.GetBuffer());
		 temp.Format(_T("%ld"), m_MonitorInfoExArray[id].rcMonitor.right);
		 WritePrivateProfileString(TEXT("image_wnd"), TEXT("right"), temp.GetBuffer(), strcfgpath.GetBuffer());
		 break;
	 case 3:
		 temp.Format(_T("%ld"), m_MonitorInfoExArray[id].rcMonitor.left);
		 WritePrivateProfileString(_T("scene_wnd"), _T("left"), temp.GetBuffer(), strcfgpath.GetBuffer());
		 temp.Format(_T("%ld"), m_MonitorInfoExArray[id].rcMonitor.top);
		 WritePrivateProfileString(_T("scene_wnd"), _T("top"), temp.GetBuffer(), strcfgpath.GetBuffer());
		 temp.Format(_T("%ld"), m_MonitorInfoExArray[id].rcMonitor.right);
		 WritePrivateProfileString(_T("scene_wnd"), _T("right"), temp.GetBuffer(), strcfgpath.GetBuffer());
		 temp.Format(_T("%ld"), m_MonitorInfoExArray[id].rcMonitor.bottom);
		 WritePrivateProfileString(_T("scene_wnd"), _T("bottom"), temp.GetBuffer(), strcfgpath.GetBuffer());
		 break;
	 case 2:
		 temp.Format(_T("%ld"), m_MonitorInfoExArray[id].rcMonitor.left);
		 WritePrivateProfileString(_T("video_wnd"), _T("left"), temp.GetBuffer(), strcfgpath.GetBuffer());
		 temp.Format(_T("%ld"), m_MonitorInfoExArray[id].rcMonitor.top);
		 WritePrivateProfileString(_T("video_wnd"), _T("top"), temp.GetBuffer(), strcfgpath.GetBuffer());
		 temp.Format(_T("%ld"), m_MonitorInfoExArray[id].rcMonitor.right);
		 WritePrivateProfileString(_T("video_wnd"), _T("right"), temp.GetBuffer(), strcfgpath.GetBuffer());
		 temp.Format(_T("%ld"), m_MonitorInfoExArray[id].rcMonitor.bottom);
		 WritePrivateProfileString(_T("video_wnd"), _T("bottom"), temp.GetBuffer(), strcfgpath.GetBuffer());
		 break;
	 default:
		 break;
	 }
 }


 CString CdisplayDevSetDlg::GetExePath()
 {
	 TCHAR FilePath[MAX_PATH];
	 GetModuleFileName(NULL, FilePath, MAX_PATH);
	 (_tcsrchr(FilePath, '\\'))[1] = 0;
	 //lstrcat(FilePath, _T("MY.ini"));
	 return FilePath;
 }