#include "stdafx.h"
#include "afxdialogex.h"
#include "DisplayDlg.h"

IMPLEMENT_DYNAMIC(DisplayDlg, CDialogEx)
DisplayDlg::DisplayDlg(CWnd* pParent,int position)
	:CDialogEx(IDD_DIALOG1, pParent)
{
	m_pOldFont = NULL;
}


DisplayDlg::~DisplayDlg()
{
	//delete 	m_newFont;
	delete 	m_pOldFont;
}
BEGIN_MESSAGE_MAP(DisplayDlg, CDialogEx)
	ON_WM_CLOSE()
	ON_WM_PAINT()
END_MESSAGE_MAP()


void DisplayDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnClose();
}


void DisplayDlg::OnPaint()
{
	//CPaintDC dc(this); // device context for painting
	//				   // TODO: 在此处添加消息处理程序代码
	//				   // 不为绘图消息调用 CDialogEx::OnPaint()
	CRect rc;
	GetClientRect(rc);

	//if (memDC.m_hDC == NULL) {
	//	memDC.CreateCompatibleDC(&dc);
	//}
	//SetTextColor(memDC, RGB(255, 0, 0));
	//memDC.FillRect(rc, &CBrush((COLORREF)0xffffff));
	////memDC.TextOutW(rc.CenterPoint().x, rc.CenterPoint().y, text);
	//memDC.DrawTextW(text, rc, DT_CENTER);
	//dc.BitBlt(rc.left, rc.top, rc.Width(), rc.Height(), &memDC, 0, 0, SRCCOPY);

	CSize txtpot;

	CPaintDC dc(this); // device context for painting   
					   // 设置m_newFont对象的字体为当前字体，并将之前的字体指针保存到m_pOldFont   
	m_pOldFont = (CFont*)dc.SelectObject(&m_newFont);
	// 设置   
	dc.SetBkMode(TRANSPARENT); //设置背景为透明！   
							   // 设置文本颜色为红色   
	dc.SetTextColor(RGB(255, 0, 0));
	txtpot = dc.GetTextExtent(text);
	// 在指定位置输出文本   
	dc.TextOut(rc.CenterPoint().x- txtpot.cx/2, rc.CenterPoint().y- txtpot.cy/2, text);
	dc.SelectObject(m_pOldFont);

	CDialogEx::OnPaint();

}


void DisplayDlg::DoDataExchange(CDataExchange* pDX)
{
	// TODO: 在此添加专用代码和/或调用基类

	CDialogEx::DoDataExchange(pDX);
}


BOOL DisplayDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_newFont.CreatePointFont(1000, _T("宋体"));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

void DisplayDlg::SetText(CString x){
	text = x;
	Invalidate();
}
