
// MFCtest1View.cpp: CMFCtest1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCtest1.h"
#endif

#include "MFCtest1Doc.h"
#include "MFCtest1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtest1View

IMPLEMENT_DYNCREATE(CMFCtest1View, CView)

BEGIN_MESSAGE_MAP(CMFCtest1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCtest1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFCtest1View 构造/析构

CMFCtest1View::CMFCtest1View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCtest1View::~CMFCtest1View()
{
}

BOOL CMFCtest1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCtest1View 绘图

void CMFCtest1View::OnDraw(CDC* pDC)
{
	CMFCtest1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CRect rect;
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(rect.Width(), rect.Height());
	pDC->SetViewportExt(rect.Width(), -rect.Height());
	pDC->SetViewportOrg(rect.Width() / 2, rect.Height() / 2);

	rect.OffsetRect(-rect.Width() / 2, -rect.Height() / 2);

	CPoint p0(-rect.Width() / 2, 0), p1(rect.Width() / 2, 0);
	pDC->MoveTo(p0);
	pDC->LineTo(p1);

	p0 = CPoint(0, -rect.Height());
	p1 = CPoint(0, rect.Height());

	pDC->MoveTo(p0);
	pDC->LineTo(p1);

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCtest1View 打印


void CMFCtest1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCtest1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCtest1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCtest1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CMFCtest1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtest1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtest1View 诊断

#ifdef _DEBUG
void CMFCtest1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtest1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtest1Doc* CMFCtest1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtest1Doc)));
	return (CMFCtest1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtest1View 消息处理程序
