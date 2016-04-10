// Threshold.cpp : 定义 DLL 的初始化例程。
//

#include "stdafx.h"
#include "Threshold.h"
#include "afxpropertygridctrl.h"
#include <vector>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO:  如果此 DLL 相对于 MFC DLL 是动态链接的，
//		则从此 DLL 导出的任何调入
//		MFC 的函数必须将 AFX_MANAGE_STATE 宏添加到
//		该函数的最前面。
//
//		例如: 
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// 此处为普通函数体
//		}
//
//		此宏先于任何 MFC 调用
//		出现在每个函数中十分重要。  这意味着
//		它必须作为函数中的第一个语句
//		出现，甚至先于所有对象变量声明，
//		这是因为它们的构造函数可能生成 MFC
//		DLL 调用。
//
//		有关其他详细信息，
//		请参阅 MFC 技术说明 33 和 58。
//

// CThresholdApp

BEGIN_MESSAGE_MAP(CThresholdApp, CWinApp)
END_MESSAGE_MAP()


UINT gID = 0;

// CThresholdApp 构造

CThresholdApp::CThresholdApp()
{
	// TODO:  在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}

CThresholdApp::~CThresholdApp()
{

}


// 唯一的一个 CThresholdApp 对象

CThresholdApp theApp;


// CThresholdApp 初始化

BOOL CThresholdApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}


std::vector<CMFCPropertyGridProperty*>* GetProperties()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	std::vector<CMFCPropertyGridProperty*>* vec_prop = new std::vector<CMFCPropertyGridProperty*>;
	CMFCPropertyGridProperty* pGroup1 = new CMFCPropertyGridProperty(_T("Appearance1"));
	CMFCPropertyGridProperty* pGroup2 = new CMFCPropertyGridProperty(_T("Appearance2"));
	CMFCPropertyGridProperty* pGroup3 = new CMFCPropertyGridProperty(_T("Appearance3"));


	//pGroup1->AddSubItem(new CMFCPropertyGridProperty(_T("3D Look"), (_variant_t) false, _T("Specifies the window's font will be non-bold and controls will have a 3D border")));

	//CMFCPropertyGridProperty* pProp = new CMFCPropertyGridProperty(_T("Border"), _T("Dialog Frame"), _T("One of: None, Thin, Resizable, or Dialog Frame"));
	//pProp->AddOption(_T("None"));
	//pProp->AddOption(_T("Thin"));
	//pProp->AddOption(_T("Resizable"));
	//pProp->AddOption(_T("Dialog Frame"));
	//pProp->AllowEdit(FALSE);

	//pGroup1->AddSubItem(pProp);
	//pGroup1->AddSubItem(new CMFCPropertyGridProperty(_T("Caption"), (_variant_t) _T("About"), _T("Specifies the text that will be displayed in the window's title bar")));

	//pp->AddProperty(pGroup1);
	vec_prop->push_back(pGroup1);
	vec_prop->push_back(pGroup2);
	vec_prop->push_back(pGroup3);
	return vec_prop;
}

void ImageProc(void* src, void* dst, CMFCPropertyGridCtrl*)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
}


void GetNameAndInfo(char* groupName, char* name, char* info)
{
	strcpy_s(groupName, 64, "图像处理");
	strcpy_s(name, 64, "二值化");
	strcpy_s(info, 1024, "将图片进行二值化处理");
}
