// PropertyView.cpp : 实现文件
//

#include "stdafx.h"
#include "ImageProcess.h"
#include "PropertyView.h"


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
	return 0;
}


void CPropertyView::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
}
