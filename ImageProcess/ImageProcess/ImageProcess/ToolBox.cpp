// ToolBox.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ImageProcess.h"
#include "ToolBox.h"
#include "OutputWnd.h"


// CToolBox

IMPLEMENT_DYNAMIC(CToolBox, CDockablePane)

CToolBox::CToolBox()
{
	WIN32_FIND_DATA FindFileData;
	pFlowItem pItem = new FlowItem;
	HANDLE hFind = ::FindFirstFile(L".\\Extensions\\*.dll", &FindFileData);
	if (INVALID_HANDLE_VALUE == hFind)
	{
		return;
	}

	while (TRUE)
	{
		if (!(FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
		{
			AfxMessageBox(FindFileData.cFileName);
		}
		if (!FindNextFile(hFind, &FindFileData))    break;
	}
	FindClose(hFind);
}

CToolBox::~CToolBox()
{
}

CToolBox* CToolBox::pInst = new CToolBox();

CToolBox* CToolBox::Get()
{
	return pInst;
}

BEGIN_MESSAGE_MAP(CToolBox, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_CONTEXTMENU()
END_MESSAGE_MAP()



// CToolBox ��Ϣ�������




int CToolBox::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	m_toolboxWnd.Create(IDD_DIALOG_TOOLBOX, this);
	m_toolboxWnd.ShowWindow(SW_SHOW);
	return 0;
}


void CToolBox::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
	if (GetSafeHwnd() == NULL)
	{
		return;
	}

	CRect rectClient;
	GetClientRect(rectClient);
	m_toolboxWnd.SetWindowPos(NULL, rectClient.left, rectClient.top, rectClient.Width(), rectClient.Height(), SWP_NOACTIVATE | SWP_NOZORDER);

}


void CToolBox::OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/)
{
	// TODO: �ڴ˴������Ϣ����������
}
