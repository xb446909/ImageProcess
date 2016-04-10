#include "StdAfx.h"
#include "FlowView.h"
#include "Resource.h"
#include "Strsafe.h"
#include "PropertyView.h"
#include "ToolBox.h"

#pragma comment(lib, "..\\Debug\\Threshold.lib")

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
	std::vector<pFlowItem>::iterator it;

	FlowItem flow;
	StringCbCopy(flow.flowName, 64, flowName);
	StringCbCopy(flow.info, 1024, info);
	flow.pProperty = new CMFCPropertyGridCtrl();
	CPropertyView::Get()->CreateProperty(flow.pProperty);

	std::vector<CMFCPropertyGridProperty*>* vec_prop;

	for (it = CToolBox::Get()->flowList.begin(); it != CToolBox::Get()->flowList.end(); it++)
	{
		if (StrCmp(((pFlowItem)*it)->flowName, flowName) == 0)
		{
			vec_prop = ((pFlowItem)*it)->funcGetProperties();
			
			for (auto it = vec_prop->begin(); it != vec_prop->end(); it++)
			{
				flow.pProperty->AddProperty(*it);
			}
		} 
	}

	if (nItem == -1)
	{
		dlg.vec_flow.push_back(flow);
	}
	else
	{
		dlg.vec_flow.insert(dlg.vec_flow.begin() + nItem, flow);
	}
	dlg.UpdateList();
}