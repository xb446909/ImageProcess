
// ImageProcessDoc.h : CImageProcessDoc ��Ľӿ�
//


#pragma once


class CImageProcessDoc : public CDocument
{
protected: // �������л�����
	CImageProcessDoc();
	DECLARE_DYNCREATE(CImageProcessDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CImageProcessDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
