// Threshold.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "Threshold.h"
#include "afxpropertygridctrl.h"

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


// Ψһ��һ�� CThresholdApp ����

CThresholdApp theApp;


// CThresholdApp ��ʼ��

BOOL CThresholdApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}


CMFCPropertyGridCtrl* CreateProperty(CWnd* pParent)
{
	CMFCPropertyGridCtrl* pp = new CMFCPropertyGridCtrl();
	CRect rect;
	rect.SetRectEmpty();
	if (!pp->Create(WS_VISIBLE | WS_CHILD, rect, pParent, gID++))
	{
		return NULL;
	}
}

void ImageProc(void* src, void* dst, CMFCPropertyGridCtrl*)
{

}


void GetNameAndInfo(char* groupName, char* name, char* info)
{
	strcpy_s(groupName, 64, "ͼ����");
	strcpy_s(name, 64, "��ֵ��");
	strcpy_s(info, 1024, "��ͼƬ���ж�ֵ������");
}
