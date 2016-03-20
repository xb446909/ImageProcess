// ToolBoxWnd.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ImageProcess.h"
#include "ToolBoxWnd.h"
#include "afxdialogex.h"
#include "OutputWnd.h"
#include "FlowView.h"


// CToolBoxWnd �Ի���

IMPLEMENT_DYNAMIC(CToolBoxWnd, CDialogEx)

CToolBoxWnd::CToolBoxWnd(CWnd* pParent /*=NULL*/)
	: CDialogEx(CToolBoxWnd::IDD, pParent)
{

}

CToolBoxWnd::~CToolBoxWnd()
{
}

void CToolBoxWnd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE_TOOLS, m_tree);
}


BEGIN_MESSAGE_MAP(CToolBoxWnd, CDialogEx)
	ON_WM_SIZE()
	ON_NOTIFY(NM_DBLCLK, IDC_TREE_TOOLS, &CToolBoxWnd::OnNMDblclkTreeTools)
END_MESSAGE_MAP()


// CToolBoxWnd ��Ϣ�������

void CToolBoxWnd::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
	if (m_tree.GetSafeHwnd() == NULL)
	{
		return;
	}
	m_tree.SetWindowPos(NULL, 0, 0, cx, cy, SWP_NOACTIVATE | SWP_NOZORDER);
}


BOOL CToolBoxWnd::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	HTREEITEM hRoot, hLelf;

	hRoot = m_tree.InsertItem(L"ͼ����");
	hLelf = m_tree.InsertItem(L"��ֵ��", hRoot);
	hLelf = m_tree.InsertItem(L"��Ե���", hRoot);
	hRoot = m_tree.InsertItem(L"����");


	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CToolBoxWnd::OnNMDblclkTreeTools(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HTREEITEM hItem;
	hItem = m_tree.GetSelectedItem();
	
	if ((m_tree.GetChildItem(hItem) == NULL) && (m_tree.GetParentItem(hItem) != NULL))
	{
		CFlowView::Get()->InsertFlow(m_tree.GetItemText(hItem), m_tree.GetItemText(hItem));
	}

	//AfxGetApp()->m_pMainWnd->OnClose();


	//AfxGetApp()->OpenDocumentFile(m_tree.GetItemText(hItem));

	*pResult = 0;
}
