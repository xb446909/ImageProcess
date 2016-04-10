// PropertyView.cpp : 实现文件
//

#include "stdafx.h"
#include "ImageProcess.h"
#include "PropertyView.h"
#include "ToolBox.h"


// CPropertyView

IMPLEMENT_DYNAMIC(CPropertyView, CDockablePane)

CPropertyView::CPropertyView()
{

}

CPropertyView::~CPropertyView()
{
}


BEGIN_MESSAGE_MAP(CPropertyView, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()

CPropertyView* CPropertyView::pInst = new CPropertyView();

CPropertyView* CPropertyView::Get()
{
	return pInst;
}

// CPropertyView 消息处理程序




int CPropertyView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	gID = 1;
	pProperty = NULL;
	return 0;
}



void CPropertyView::AdjustLayout()
{
	if (GetSafeHwnd() == NULL)
	{
		return;
	}

	CRect rectClient;
	GetClientRect(rectClient);

	if (pProperty != NULL)
	{
		pProperty->SetWindowPos(NULL, rectClient.left, rectClient.top, rectClient.Width(), rectClient.Height(), SWP_NOACTIVATE | SWP_NOZORDER);
	}
}


void CPropertyView::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	AdjustLayout();
}

int CPropertyView::ShowProperty(CMFCPropertyGridCtrl* pp)
{
	pProperty = pp;
	AdjustLayout();
	return 0;
}

int CPropertyView::CreateProperty(CMFCPropertyGridCtrl* pp)
{
	CRect rect;
	rect.SetRectEmpty();
	if (!pp->Create(WS_VISIBLE | WS_CHILD, rect, this, gID++))
	{
		return -1;
	}

	pp->EnableHeaderCtrl(FALSE);
	pp->EnableDescriptionArea();
	pp->SetVSDotNetLook();
	pp->MarkModifiedProperties();

	//InitPropList(pp);
}



void CPropertyView::InitPropList(CMFCPropertyGridCtrl* pp)
{

	CMFCPropertyGridProperty* pGroup1 = new CMFCPropertyGridProperty(_T("Appearance"));

	pGroup1->AddSubItem(new CMFCPropertyGridProperty(_T("3D Look"), (_variant_t) false, _T("Specifies the window's font will be non-bold and controls will have a 3D border")));

	CMFCPropertyGridProperty* pProp = new CMFCPropertyGridProperty(_T("Border"), _T("Dialog Frame"), _T("One of: None, Thin, Resizable, or Dialog Frame"));
	pProp->AddOption(_T("None"));
	pProp->AddOption(_T("Thin"));
	pProp->AddOption(_T("Resizable"));
	pProp->AddOption(_T("Dialog Frame"));
	pProp->AllowEdit(FALSE);

	pGroup1->AddSubItem(pProp);
	pGroup1->AddSubItem(new CMFCPropertyGridProperty(_T("Caption"), (_variant_t) _T("About"), _T("Specifies the text that will be displayed in the window's title bar")));

	pp->AddProperty(pGroup1);
}
