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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CDialogEx::OnClose();
}


void DisplayDlg::OnPaint()
{
	//CPaintDC dc(this); // device context for painting
	//				   // TODO: �ڴ˴������Ϣ����������
	//				   // ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
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
					   // ����m_newFont���������Ϊ��ǰ���壬����֮ǰ������ָ�뱣�浽m_pOldFont   
	m_pOldFont = (CFont*)dc.SelectObject(&m_newFont);
	// ����   
	dc.SetBkMode(TRANSPARENT); //���ñ���Ϊ͸����   
							   // �����ı���ɫΪ��ɫ   
	dc.SetTextColor(RGB(255, 0, 0));
	txtpot = dc.GetTextExtent(text);
	// ��ָ��λ������ı�   
	dc.TextOut(rc.CenterPoint().x- txtpot.cx/2, rc.CenterPoint().y- txtpot.cy/2, text);
	dc.SelectObject(m_pOldFont);

	CDialogEx::OnPaint();

}


void DisplayDlg::DoDataExchange(CDataExchange* pDX)
{
	// TODO: �ڴ����ר�ô����/����û���

	CDialogEx::DoDataExchange(pDX);
}


BOOL DisplayDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_newFont.CreatePointFont(1000, _T("����"));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}

void DisplayDlg::SetText(CString x){
	text = x;
	Invalidate();
}
