#pragma once
#include "afxcmn.h"


// CToolBoxWnd �Ի���

class CToolBoxWnd : public CDialogEx
{
	DECLARE_DYNAMIC(CToolBoxWnd)

public:
	CToolBoxWnd(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CToolBoxWnd();

// �Ի�������
	enum { IDD = IDD_DIALOG_TOOLBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	CTreeCtrl m_tree;
	virtual BOOL OnInitDialog();
	afx_msg void OnNMClickTreeTools(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMDblclkTreeTools(NMHDR *pNMHDR, LRESULT *pResult);
};
