#pragma once

#include "resource.h"
#include "afxwin.h"
#include "afxcmn.h"
#include <vector>
// CFlowViewWnd 对话框

typedef std::vector<CMFCPropertyGridProperty*>* (*GetProperties)();

typedef struct flow_tag
{

#ifdef UNICODE
	WCHAR groupName[64];
	WCHAR flowName[64];
	WCHAR info[1024];
#else
	CHAR groupName[64];
	CHAR flowName[64];
	CHAR info[1024];
#endif

	GetProperties funcGetProperties;
	CMFCPropertyGridCtrl* pProperty;

}FlowItem, *pFlowItem;

class CFlowViewWnd : public CDialogEx
{
	DECLARE_DYNAMIC(CFlowViewWnd)

public:
	CFlowViewWnd(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CFlowViewWnd();

// 对话框数据
	enum { IDD = IDD_DIALOG_FLOWVIEW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	CComboBox m_ModalNo;
	CListCtrl m_ProcList;
	virtual BOOL OnInitDialog();
	afx_msg void OnNMClickListProc(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMRClickListProc(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	afx_msg void OnDelete();
	void UpdateList();

	std::vector<FlowItem> vec_flow;

};
