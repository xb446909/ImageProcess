// FlowViewWnd.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ImageProcess.h"
#include "FlowViewWnd.h"
#include "afxdialogex.h"


// CFlowViewWnd �Ի���

IMPLEMENT_DYNAMIC(CFlowViewWnd, CDialogEx)

CFlowViewWnd::CFlowViewWnd(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFlowViewWnd::IDD, pParent)
{

}

CFlowViewWnd::~CFlowViewWnd()
{
}

void CFlowViewWnd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_FLOWNO, m_ModalNo);
	DDX_Control(pDX, IDC_LIST_PROC, m_ProcList);
}


BEGIN_MESSAGE_MAP(CFlowViewWnd, CDialogEx)
	ON_WM_SIZE()
	ON_NOTIFY(NM_CLICK, IDC_LIST_PROC, &CFlowViewWnd::OnNMClickListProc)
	ON_NOTIFY(NM_RCLICK, IDC_LIST_PROC, &CFlowViewWnd::OnNMRClickListProc)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_DELETE, &CFlowViewWnd::OnDelete)
END_MESSAGE_MAP()


// CFlowViewWnd ��Ϣ�������

void CFlowViewWnd::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	if ((GetSafeHwnd() == NULL) || (m_ModalNo.GetSafeHwnd() == NULL) || (m_ProcList.GetSafeHwnd() == NULL))
	{
		return;
	}

	// TODO: �ڴ˴������Ϣ����������
	CRect combobox_rect, list_rect;
	m_ModalNo.GetWindowRect(combobox_rect);
	m_ProcList.GetWindowRect(list_rect);
	ScreenToClient(combobox_rect);
	ScreenToClient(list_rect);
	combobox_rect.right = cx - 10;
	list_rect.right = combobox_rect.right;
	list_rect.bottom = cy - 10;
	m_ModalNo.SetWindowPos(NULL, combobox_rect.left, combobox_rect.top, combobox_rect.Width(), combobox_rect.Height(), SWP_NOACTIVATE | SWP_NOZORDER);
	m_ProcList.SetWindowPos(NULL, list_rect.left, list_rect.top, list_rect.Width(), list_rect.Height(), SWP_NOACTIVATE | SWP_NOZORDER);
}


BOOL CFlowViewWnd::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CString str;
	int i;
	for (i = 0; i < 10; i++)
	{
		str.Format(L"%d", i + 1);
		m_ModalNo.InsertString(i, str);
	}
	m_ModalNo.SetCurSel(0);

	m_ProcList.SetExtendedStyle(m_ProcList.GetExtendedStyle() | LVS_EX_ONECLICKACTIVATE | LVS_EX_FULLROWSELECT);
	m_ProcList.InsertColumn(0, L"������", 0, 80);
	m_ProcList.InsertColumn(1, L"˵��", 0, 300);
	for (i = 0; i < 10; i++)
	{
		str.Format(L"%d", i + 1);
		m_ProcList.InsertItem(i, str);
		m_ProcList.SetItemText(i, 1, str + "GOOD");
	}


	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CFlowViewWnd::OnNMClickListProc(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str;
	str.Format(L"������Item:%d", pNMItemActivate->iItem);
	m_ProcList.InsertItem(11, str);
	*pResult = 0;
}


void CFlowViewWnd::OnNMRClickListProc(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CRect rect;
	m_ProcList.GetWindowRect(rect);

	CMenu menu;
	menu.LoadMenu(IDR_MENU_FLOWVIEW_POPUP);

	CMenu* pSumMenu = menu.GetSubMenu(0);

	POINT pt;
	pt.x = pNMItemActivate->ptAction.x + rect.left;
	pt.y = pNMItemActivate->ptAction.y + rect.top;

	if ((AfxGetMainWnd()->IsKindOf(RUNTIME_CLASS(CMDIFrameWndEx))) && (pNMItemActivate->iItem != -1))
	{
		CMFCPopupMenu* pPopupMenu = new CMFCPopupMenu;

		if (!pPopupMenu->Create(this, pt.x, pt.y, (HMENU)pSumMenu->m_hMenu, FALSE, TRUE))
			return;

		((CMDIFrameWndEx*)AfxGetMainWnd())->OnShowPopupMenu(pPopupMenu);
		UpdateDialogControls(this, FALSE);
	}
}


void CFlowViewWnd::OnContextMenu(CWnd* /*pWnd*/, CPoint)
{
	// TODO: �ڴ˴������Ϣ����������
}


void CFlowViewWnd::OnDelete()
{
	// TODO: �ڴ���������������
	m_ProcList.DeleteItem(m_ProcList.GetNextItem(-1, LVIS_SELECTED));
}
