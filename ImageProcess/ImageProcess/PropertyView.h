#pragma once


// CPropertyView

class CPropertyView : public CDockablePane
{
	DECLARE_DYNAMIC(CPropertyView)

public:
	CPropertyView();
	virtual ~CPropertyView();

	static CPropertyView* pInst;
	static CPropertyView* Get();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};


