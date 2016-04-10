// ToolBoxWnd.cpp : 实现文件
//

#include "stdafx.h"
#include "ImageProcess.h"
#include "ToolBoxWnd.h"
#include "afxdialogex.h"
#include "OutputWnd.h"
#include "FlowView.h"
#include "ToolBox.h"


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
	std::vector<pFlowItem>::iterator it;
	HTREEITEM hRoot, hLelf;

	//hRoot = m_tree.InsertItem(L"图像处理");
	//hLelf = m_tree.InsertItem(L"二值化", hRoot);
	//hLelf = m_tree.InsertItem(L"边缘检测", hRoot);
	//hRoot = m_tree.InsertItem(L"计算");

	for (it = CToolBox::Get()->flowList.begin(); it != CToolBox::Get()->flowList.end(); it++)
	{
		hRoot = m_tree.GetRootItem();
		while (hRoot != NULL)
		{
			if (StrCmp(((pFlowItem)*it)->groupName, m_tree.GetItemText(hRoot)) == 0)
			{
				m_tree.InsertItem(((pFlowItem)*it)->flowName, hRoot);
				break;
			}
			else
			{
				hRoot = m_tree.GetNextItem(hRoot, TVGN_NEXT);
			}
		}
		if (hRoot == NULL)
		{
			hRoot = m_tree.InsertItem(((pFlowItem)*it)->groupName);
			m_tree.InsertItem(((pFlowItem)*it)->flowName, hRoot);
		}
	}


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CToolBoxWnd::OnNMDblclkTreeTools(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	HTREEITEM hItem;
	hItem = m_tree.GetSelectedItem();
	std::vector<pFlowItem>::iterator it;

	if ((m_tree.GetChildItem(hItem) == NULL) && (m_tree.GetParentItem(hItem) != NULL))
	{
		for (it = CToolBox::Get()->flowList.begin(); it != CToolBox::Get()->flowList.end(); it++)
		{
			if (StrCmp(((pFlowItem)*it)->flowName, m_tree.GetItemText(hItem)) == 0)
			{
				CFlowView::Get()->InsertFlow(((pFlowItem)*it)->flowName, ((pFlowItem)*it)->info);
			} 
		}
	}

	*pResult = 0;
}
