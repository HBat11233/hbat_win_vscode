
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
	ON_WM_TIMER()
	ON_COMMAND(ID_FUN_RUN, &CMFCtest3View::OnFunRun)
END_MESSAGE_MAP()

// CMFCtest3View 构造/析构

CMFCtest3View::CMFCtest3View() noexcept
{
	// TODO: 在此处添加构造代码
	ReadPoint();
	Theta = 0;
	Phi = 0;
	R = 1000;
	d = 100;
	bRun = false;
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

void CMFCtest3View::OnDraw(CDC* pDC)
{
	CMFCtest3Doc* pDoc = GetDocument();
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
	CBitmap NewBitMap, * pOldBitmap;//内存中临时位图
	memDC.CreateCompatibleDC(pDC);//创建一个与显示pDC兼容的内存
	NewBitMap.CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());//创建兼容位图
	pOldBitmap = memDC.SelectObject(&NewBitMap);//将兼容位图选入memDC
	memDC.FillSolidRect(rect, pDC->GetBkColor());//按原来背景填充客户区，否则是黑色
	memDC.SetMapMode(MM_ANISOTROPIC);
	memDC.SetWindowExt(rect.Width(), rect.Height());
	memDC.SetViewportExt(rect.Width(), -rect.Height());
	memDC.SetViewportOrg(rect.Width() / 2, rect.Height() / 2);
	rect.OffsetRect(-rect.Width() / 2, -rect.Height() / 2);
	ReadFace();
	DrawCuboid(&memDC);
	pDC->BitBlt(rect.left, rect.top, rect.Width(), rect.Height(), &memDC, -rect.Width() / 2, -rect.Height() / 2, SRCCOPY);
	memDC.SelectObject(pOldBitmap);//恢复位图
	NewBitMap.DeleteObject();//删除位图
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
	point[0] = CP3(-a, -a, -a);
	point[1] = CP3(a, -a, -a);
	point[2] = CP3(a, a, -a);
	point[3] = CP3(-a, a, -a);
	point[4] = CP3(-a, -a, a); 
	point[5] = CP3(a, -a, a); 
	point[6] = CP3(a, a, a); 
	point[7] = CP3(-a, a, a);
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
	p[1] = std::pair<int, int>(1, 2);
	p[2] = std::pair<int, int>(2, 3);
	p[3] = std::pair<int, int>(3, 0);
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


bool CMFCtest3View::DrawCuboid(CDC *pDC)
{
	// TODO: 在此处添加实现代码.
	for (int i = 0; i < 6; ++i)
		for (int j = 0; j < 4; ++j)
		{
			pDC->MoveTo(face[i].point[face[i].Eque[j].first].toCPoint());
			pDC->LineTo(face[i].point[face[i].Eque[j].second].toCPoint());
		}
	return false;
}


bool CMFCtest3View::initK()
{
	// TODO: 在此处添加实现代码.
	k[0] = sin(PI * Theta / 180);
	k[1] = sin(PI * Phi / 180);
	k[2] = cos(PI * Theta / 180);
	k[3] = cos(PI * Phi / 180);
	k[4] = k[1] * k[2];
	k[5] = k[1] * k[0];
	k[6] = k[3] * k[2];
	k[7] = k[3] * k[0];
	return false;
}


void CMFCtest3View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	initK();
	Theta++;
	Phi++;
	MathMatrix cub;
	cub.init(8, 4, point);
	MathMatrix T;
	int** t = new int* [4];
	for (int i = 0; i < 4; ++i)
		t[i] = new int[4];
	t[0][0] = k[3];
	t[0][1] = -k[4];
	t[0][2] = 0;
	t[0][3] = -k[5] / d;
	t[1][0] = 0;
	t[1][1] = k[0];
	t[1][2] = 0;
	t[1][3] = -k[2] / d;
	t[2][0] = -k[1];
	t[2][1] = k[6];
	t[2][2] = 0;
	t[2][3] = -k[7] / d;
	t[3][0] = 0;
	t[3][1] = 0;
	t[3][2] = 0;
	t[3][3] = 1 + R / d;
	T.init(4, 4, t);
	cub = cub * T;
	cub.toCP3(point);
	CDC* pDC = GetDC();
	OnDraw(pDC);
	CView::OnTimer(nIDEvent);
}


void CMFCtest3View::OnFunRun()
{
	// TODO: 在此添加命令处理程序代码
	bRun = !bRun;
	if (bRun)
		SetTimer(1, 150, NULL);
	else
		KillTimer(1);
}
