#pragma once


// CToolBox
#include "ToolBoxWnd.h"
#include "FlowViewWnd.h"

typedef void(*GetNameAndInfo)(char*, char*, char*);

class CToolBox : public CDockablePane
{
	DECLARE_DYNAMIC(CToolBox)
private:
	static CToolBox* pInst;
public:
	CToolBox();
	virtual ~CToolBox();

	static CToolBox* Get();
	CToolBoxWnd m_toolboxWnd;

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);

	std::vector<pFlowItem> flowList;
};


