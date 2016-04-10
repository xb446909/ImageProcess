#pragma once


// CPropertyView

class CPropertyView : public CDockablePane
{
	DECLARE_DYNAMIC(CPropertyView)

public:
	CPropertyView();
	virtual ~CPropertyView();

	static CPropertyView* Get();

protected:
	static CPropertyView* pInst;
	CMFCPropertyGridCtrl* pProperty;
	CFont m_fntPropList;
	void AdjustLayout();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	int CreateProperty(CMFCPropertyGridCtrl* pp);
	int ShowProperty(CMFCPropertyGridCtrl* pp);
	void InitPropList(CMFCPropertyGridCtrl* pp);
	UINT gID;
};


