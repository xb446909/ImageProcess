// Threshold.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "Threshold.h"
#include "afxpropertygridctrl.h"
#include <vector>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO:  ����� DLL ����� MFC DLL �Ƕ�̬���ӵģ�
//		��Ӵ� DLL �������κε���
//		MFC �ĺ������뽫 AFX_MANAGE_STATE ����ӵ�
//		�ú�������ǰ�档
//
//		����: 
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// �˴�Ϊ��ͨ������
//		}
//
//		�˺������κ� MFC ����
//		������ÿ��������ʮ����Ҫ��  ����ζ��
//		��������Ϊ�����еĵ�һ�����
//		���֣������������ж������������
//		������Ϊ���ǵĹ��캯���������� MFC
//		DLL ���á�
//
//		�й�������ϸ��Ϣ��
//		����� MFC ����˵�� 33 �� 58��
//

// CThresholdApp

BEGIN_MESSAGE_MAP(CThresholdApp, CWinApp)
END_MESSAGE_MAP()


UINT gID = 0;

// CThresholdApp ����

CThresholdApp::CThresholdApp()
{
	// TODO:  �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}

CThresholdApp::~CThresholdApp()
{

}


// Ψһ��һ�� CThresholdApp ����

CThresholdApp theApp;


// CThresholdApp ��ʼ��

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
	strcpy_s(groupName, 64, "ͼ����");
	strcpy_s(name, 64, "��ֵ��");
	strcpy_s(info, 1024, "��ͼƬ���ж�ֵ������");
}
