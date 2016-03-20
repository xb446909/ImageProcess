// ToolBoxWnd.cpp : 实现文件
//

#include "stdafx.h"
#include "ImageProcess.h"
#include "ToolBoxWnd.h"
#include "afxdialogex.h"
#include "OutputWnd.h"
#include "FlowView.h"


// CToolBoxWnd 对话框

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


// CToolBoxWnd 消息处理程序

void CToolBoxWnd::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	if (m_tree.GetSafeHwnd() == NULL)
	{
		return;
	}
	m_tree.SetWindowPos(NULL, 0, 0, cx, cy, SWP_NOACTIVATE | SWP_NOZORDER);
}


BOOL CToolBoxWnd::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	HTREEITEM hRoot, hLelf;

	hRoot = m_tree.InsertItem(L"图像处理");
	hLelf = m_tree.InsertItem(L"二值化", hRoot);
	hLelf = m_tree.InsertItem(L"边缘检测", hRoot);
	hRoot = m_tree.InsertItem(L"计算");


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CToolBoxWnd::OnNMDblclkTreeTools(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
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
