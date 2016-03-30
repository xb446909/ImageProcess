// ToolBox.cpp : 实现文件
//

#include "stdafx.h"
#include "ImageProcess.h"
#include "ToolBox.h"
#include "OutputWnd.h"


// CToolBox

IMPLEMENT_DYNAMIC(CToolBox, CDockablePane)

CToolBox::CToolBox()
{
	char groupName[64];
	char name[64];
	char info[1024];

	HINSTANCE hinstLib;
	WIN32_FIND_DATA FindFileData;
	GetNameAndInfo procGetNameAndInfo;
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
			hinstLib = LoadLibrary(FindFileData.cFileName);
			if (hinstLib != NULL)
			{
				procGetNameAndInfo = (GetNameAndInfo)GetProcAddress(hinstLib, "GetNameAndInfo");

				if (NULL != procGetNameAndInfo)
				{
					procGetNameAndInfo(groupName, name, info);
					StrCpy(pItem->groupName, CA2W(groupName));
					StrCpy(pItem->flowName, CA2W(name));
					StrCpy(pItem->info, CA2W(info));
				}
				FreeLibrary(hinstLib);
			}


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



// CToolBox 消息处理程序




int CToolBox::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	m_toolboxWnd.Create(IDD_DIALOG_TOOLBOX, this);
	m_toolboxWnd.ShowWindow(SW_SHOW);
	return 0;
}


void CToolBox::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
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
	// TODO: 在此处添加消息处理程序代码
}
