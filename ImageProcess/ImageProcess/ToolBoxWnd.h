#pragma once
#include "afxcmn.h"


// CToolBoxWnd 对话框

class CToolBoxWnd : public CDialogEx
{
	DECLARE_DYNAMIC(CToolBoxWnd)

public:
	CToolBoxWnd(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CToolBoxWnd();

// 对话框数据
	enum { IDD = IDD_DIALOG_TOOLBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	CTreeCtrl m_tree;
	virtual BOOL OnInitDialog();
	afx_msg void OnNMClickTreeTools(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMDblclkTreeTools(NMHDR *pNMHDR, LRESULT *pResult);
};
