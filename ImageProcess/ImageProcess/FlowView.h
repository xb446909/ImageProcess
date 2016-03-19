#pragma once
#include "afxdockablepane.h"
#include "FlowViewWnd.h"
class CFlowView :
	public CDockablePane
{
private:
	static CFlowView* pInst;
public:
	CFlowView(void);
	~CFlowView(void);

	static CFlowView* Get();
	DECLARE_MESSAGE_MAP()
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

protected:
	void AdjustLayout();
	CFlowViewWnd dlg;
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
};

