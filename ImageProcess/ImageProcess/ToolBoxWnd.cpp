// ToolBoxWnd.cpp : 实现文件
//

#include "stdafx.h"
#include "ImageProcess.h"
#include "ToolBoxWnd.h"
#include "afxdialogex.h"
#include "OutputWnd.h"


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
	ON_NOTIFY(NM_CLICK, IDC_TREE_TOOLS, &CToolBoxWnd::OnNMClickTreeTools)
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


void CToolBoxWnd::OnNMClickTreeTools(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	//POINT pt;
	//HTREEITEM hItem;
	//GetCursorPos(&pt);
	//hItem = m_tree.HitTest(pt);
	//hItem = m_tree.GetSelectedItem();
	//m_tree.SelectItem(hItem);
	//MessageBox(m_tree.GetItemText(hItem));

	//COutputWnd::Get()->OutputString(m_tree.GetItemText(hItem));

	*pResult = 0;
}


void CToolBoxWnd::OnNMDblclkTreeTools(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	HTREEITEM hItem;
	hItem = m_tree.GetSelectedItem();
	if (m_tree.GetParentItem(hItem) == NULL)
	{
		COutputWnd::Get()->OutputString(L"ROOT Item");
	}
	else
	{
		COutputWnd::Get()->OutputString(m_tree.GetItemText(hItem));
	}
	*pResult = 0;
}
