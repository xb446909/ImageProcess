
// ImageProcessView.cpp : CImageProcessView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "ImageProcess.h"
#endif

#include "ImageProcessDoc.h"
#include "ImageProcessView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CImageProcessView

IMPLEMENT_DYNCREATE(CImageProcessView, CView)

BEGIN_MESSAGE_MAP(CImageProcessView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CImageProcessView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CImageProcessView ����/����

CImageProcessView::CImageProcessView()
{
	// TODO: �ڴ˴���ӹ������

}

CImageProcessView::~CImageProcessView()
{
}

BOOL CImageProcessView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CImageProcessView ����

void CImageProcessView::OnDraw(CDC* pDC)
{
	CImageProcessDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	DrawToCDC(pDoc->pDst, pDC);
	
}


// CImageProcessView ��ӡ


void CImageProcessView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CImageProcessView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CImageProcessView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CImageProcessView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CImageProcessView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CImageProcessView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CImageProcessView ���

#ifdef _DEBUG
void CImageProcessView::AssertValid() const
{
	CView::AssertValid();
}

void CImageProcessView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CImageProcessDoc* CImageProcessView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImageProcessDoc)));
	return (CImageProcessDoc*)m_pDocument;
}
#endif //_DEBUG


// CImageProcessView ��Ϣ�������
float CImageProcessView::DrawToCDC(IplImage* img, CDC* pDC)
{
	CRect rect;
	CImage bkgound;
	float ratio;
	BITMAPINFO bmi;
	BITMAPINFOHEADER* bmih = &(bmi.bmiHeader);
	memset(bmih, 0, sizeof(*bmih));
	IplImage* pImg = cvCreateImage(cvSize(img->width, img->height), IPL_DEPTH_8U, 3);

	if ((img->nChannels * img->depth) == 8)
	{
		cvCvtColor(img, pImg, CV_GRAY2RGB);
	}

	if ((img->nChannels * img->depth) == 24)
	{
		cvCopy(img, pImg);
	}
	if ((img->nChannels * img->depth) > 24)
	{
		AfxMessageBox(L"������8BPP��24BPP��ͼ��");
		return 0;
	}

	bmih->biSize = sizeof(BITMAPINFOHEADER);
	bmih->biWidth = pImg->width;
	bmih->biHeight = -abs(pImg->height);
	bmih->biPlanes = 1;
	bmih->biBitCount = 24;
	bmih->biCompression = BI_RGB;

	pDC->GetWindow()->GetWindowRect(&rect);
	bkgound.Create(rect.Width(), rect.Height(), 24);
	bkgound.Draw(pDC->GetSafeHdc(), 0, 0, rect.Width(), rect.Height());
	ratio = MIN(((float)rect.Height() / pImg->height), ((float)rect.Width() / pImg->width));
	pDC->SetStretchBltMode(HALFTONE);
	::StretchDIBits(pDC->GetSafeHdc(), (int)((rect.Width() - pImg->width*ratio) / 2), (int)((rect.Height() - pImg->height*ratio) / 2),
		(int)((pImg->width)*ratio), (int)((pImg->height)*ratio), 0, 0, pImg->width, pImg->height, pImg->imageData, &bmi, DIB_RGB_COLORS, SRCCOPY);
	cvReleaseImage(&pImg);

	return ratio;
}