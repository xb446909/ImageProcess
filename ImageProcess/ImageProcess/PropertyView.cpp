// PropertyView.cpp : ʵ���ļ�
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

// CPropertyView ��Ϣ�������




int CPropertyView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	return 0;
}


void CPropertyView::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
}
