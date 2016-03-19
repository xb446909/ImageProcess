#include "StdAfx.h"
#include "FlowView.h"
#include "Resource.h"


CFlowView::CFlowView(void)
{
}


CFlowView::~CFlowView(void)
{
}

CFlowView* CFlowView::pInst = NULL;
HANDLE hMutex = CreateMutex(NULL, FALSE, NULL);

CFlowView* CFlowView::Get()
{
	if (pInst == NULL)
	{
		WaitForSingleObject(hMutex, INFINITE);
		if (pInst == NULL)
		{
			pInst = new CFlowView();
		}
		ReleaseMutex(hMutex);
		CloseHandle(hMutex);
	}
	return pInst;
}
BEGIN_MESSAGE_MAP(CFlowView, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()


int CFlowView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码

	dlg.Create(IDD_DIALOG_FLOWVIEW, this);
	dlg.ShowWindow(SW_SHOW);

	AdjustLayout();

	return 0;
}

void CFlowView::AdjustLayout()
{
	if (GetSafeHwnd() == NULL)
	{
		return;
	}

	CRect rectClient;
	GetClientRect(rectClient);
	dlg.SetWindowPos(NULL, rectClient.left, rectClient.top, rectClient.Width(), rectClient.Height(), SWP_NOACTIVATE | SWP_NOZORDER);

}

void CFlowView::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	AdjustLayout();
}


void CFlowView::InsertFlow(LPCTSTR flowName, LPCTSTR info)
{
	POSITION pos = dlg.m_ProcList.GetFirstSelectedItemPosition();
	int nItem = dlg.m_ProcList.GetNextSelectedItem(pos);
	if (nItem == -1)
	{
		dlg.m_ProcList.InsertItem(dlg.m_ProcList.GetItemCount(), flowName);
		dlg.m_ProcList.SetItemText(dlg.m_ProcList.GetItemCount() - 1, 1, info);
	}
	else
	{
		dlg.m_ProcList.InsertItem(nItem, flowName);
		dlg.m_ProcList.SetItemText(nItem, 1, info);
	}
}