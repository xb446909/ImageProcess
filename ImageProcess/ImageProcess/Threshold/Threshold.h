// Threshold.h : Threshold DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CThresholdApp
// �йش���ʵ�ֵ���Ϣ������� Threshold.cpp
//
class CThresholdApp : public CWinApp
{
public:
	CThresholdApp();
	~CThresholdApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
