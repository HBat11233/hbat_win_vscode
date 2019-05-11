
// MFCtest4View.cpp: CMFCtest4View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCtest4.h"
#endif

#include "MFCtest4Doc.h"
#include "MFCtest4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtest4View

IMPLEMENT_DYNCREATE(CMFCtest4View, CView)

BEGIN_MESSAGE_MAP(CMFCtest4View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFCtest4View 构造/析构

CMFCtest4View::CMFCtest4View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCtest4View::~CMFCtest4View()
{
}

BOOL CMFCtest4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCtest4View 绘图

void CMFCtest4View::OnDraw(CDC* pDC)
{
	CMFCtest4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CRect rect;//定义客户区矩形
	GetClientRect(rect);//获取客户区矩形
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(rect.Width(), rect.Height());//设置窗口范围
	pDC->SetViewportExt(rect.Width(), -rect.Height());//设置视区范围，x轴水平向右，y轴垂直向上
	pDC->SetViewportOrg(rect.Width() / 2, rect.Height() / 2);//客户区中心
	CDC memDC;//内存DC
	CBitmap NewBitMap, *pOldBitmap;//内存中临时位图
	memDC.CreateCompatibleDC(pDC);//创建一个与显示pDC兼容的内存
	NewBitMap.CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());//创建兼容位图
	pOldBitmap = memDC.SelectObject(&NewBitMap);//将兼容位图选入memDC
	memDC.FillSolidRect(rect, pDC->GetBkColor());//按原来背景填充客户区，否则是黑色
	memDC.SetMapMode(MM_ANISOTROPIC);
	memDC.SetWindowExt(rect.Width(), rect.Height());
	memDC.SetViewportExt(rect.Width(), -rect.Height());
	memDC.SetViewportOrg(rect.Width() / 2, rect.Height() / 2);
	rect.OffsetRect(-rect.Width() / 2, -rect.Height() / 2);
	
	//绘图代码

	pDC->BitBlt(rect.left, rect.top, rect.Width(), rect.Height(), &memDC, -rect.Width() / 2, -rect.Height() / 2, SRCCOPY);
	memDC.SelectObject(pOldBitmap);//恢复位图
	NewBitMap.DeleteObject();//删除位图
}


// CMFCtest4View 打印

BOOL CMFCtest4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCtest4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCtest4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCtest4View 诊断

#ifdef _DEBUG
void CMFCtest4View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtest4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtest4Doc* CMFCtest4View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtest4Doc)));
	return (CMFCtest4Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtest4View 消息处理程序
