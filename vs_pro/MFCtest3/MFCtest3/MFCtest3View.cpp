
// MFCtest3View.cpp: CMFCtest3View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCtest3.h"
#endif

#include "MFCtest3Doc.h"
#include "MFCtest3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtest3View

IMPLEMENT_DYNCREATE(CMFCtest3View, CView)

BEGIN_MESSAGE_MAP(CMFCtest3View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFCtest3View 构造/析构

CMFCtest3View::CMFCtest3View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCtest3View::~CMFCtest3View()
{
}

BOOL CMFCtest3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCtest3View 绘图

void CMFCtest3View::OnDraw(CDC* /*pDC*/)
{
	CMFCtest3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCtest3View 打印

BOOL CMFCtest3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCtest3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCtest3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCtest3View 诊断

#ifdef _DEBUG
void CMFCtest3View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtest3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtest3Doc* CMFCtest3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtest3Doc)));
	return (CMFCtest3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtest3View 消息处理程序


int CMFCtest3View::ReadPoint()
{
	// TODO: 在此处添加实现代码.
	int a = 150;
	point[0];
	point[1] = CP3(a, 0, 0);
	point[2] = CP3(a, a, 0);
	point[3] = CP3(0, a, 0);
	point[4] = CP3(0, 0, a); 
	point[5] = CP3(a, 0, a); 
	point[6] = CP3(a, a, a); 
	point[7] = CP3(0, a, a);
	return 8;
}

int CMFCtest3View::ReadFace()
{	
	// TODO: 在此处添加实现代码.
	for (int i = 0; i < 6; ++i)
		face[i].SetEn(4);
	CP3* t = new CP3[4];
	std::pair<int, int>* p = new std::pair<int, int>[4];
	face[0].SetPoint(point);
	p[0] = std::pair<int, int>(0, 1);
	p[0] = std::pair<int, int>(1, 2);
	p[0] = std::pair<int, int>(2, 3);
	p[0] = std::pair<int, int>(3, 0);
	face[0].SetPair(p);
	face[1].SetPoint(point + 4);
	face[1].SetPair(p);
	t[0] = point[0];
	t[1] = point[1];
	t[2] = point[5];
	t[3] = point[4];
	face[2].SetPoint(t);
	face[2].SetPair(p);
	t[0] = point[2];
	t[1] = point[3];
	t[2] = point[7];
	t[3] = point[6];
	face[3].SetPoint(t);
	face[3].SetPair(p);
	t[0] = point[0];
	t[1] = point[3];
	t[2] = point[4];
	t[3] = point[7];
	face[4].SetPoint(t);
	face[4].SetPair(p);
	t[0] = point[1];
	t[1] = point[2];
	t[2] = point[5];
	t[3] = point[6];
	face[5].SetPoint(t);
	face[5].SetPair(p);
	return 6;
}
