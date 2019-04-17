
// MFCtest2View.cpp: CMFCtest2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCtest2.h"
#endif

#include "MFCtest2Doc.h"
#include "MFCtest2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtest2View

IMPLEMENT_DYNCREATE(CMFCtest2View, CView)

BEGIN_MESSAGE_MAP(CMFCtest2View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCtest2View 构造/析构

CMFCtest2View::CMFCtest2View() noexcept
	:buttonBool(FALSE), MemDC(NULL), MemBitmap(NULL)
{
	// TODO: 在此处添加构造代码
}

CMFCtest2View::~CMFCtest2View()
{
}

BOOL CMFCtest2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCtest2View 绘图

void CMFCtest2View::OnDraw(CDC* pDC)
{
	CMFCtest2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	GetClientRect(&rect);
	//首先定义一个显示设备对象
	MemDC = new CDC;
	//定义一个位图对象
	MemBitmap = new CBitmap;
	//建立一个与屏幕显示兼容的内存显示设备，这是还不能绘图，因为没有地方画
	MemDC->CreateCompatibleDC(NULL);
	//建立一个与屏幕显示器兼容的位图，至于位图的大小，可以用窗口的大小
	MemBitmap->CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());
	//将位图选入到内存设备中
	//只有选入了位图的内存显示设备才有地方绘图，画到指定位图上
	CBitmap *pOldBit = MemDC->SelectObject(MemBitmap);
	//先用背景色将位图清除干净，这里用白色作为背景
	MemDC->FillSolidRect(rect, RGB(255, 255, 255));

	//绘图
	
	int length = buttonS.size();
	
	if (length > 0)
	{
		MemDC->MoveTo(buttonS[0]);
		for (int i = 1; i < length; ++i)
			MemDC->LineTo(buttonS[i]);
		if (buttonBool)

			MemDC->LineTo(buttonM);
	}




	//将内存中的图拷贝到屏幕上进行显示
	pDC->BitBlt(0, 0, rect.Width(), rect.Height(), MemDC, 0, 0, SRCCOPY);
	MemBitmap->DeleteObject();
	delete MemBitmap;
	MemBitmap = NULL;
	MemDC->DeleteDC();
	delete MemDC;
	MemDC = NULL;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCtest2View 打印

BOOL CMFCtest2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCtest2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCtest2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCtest2View 诊断

#ifdef _DEBUG
void CMFCtest2View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtest2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtest2Doc* CMFCtest2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtest2Doc)));
	return (CMFCtest2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtest2View 消息处理程序


void CMFCtest2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	buttonBool = TRUE;
	buttonS.push_back(buttonM);
	CView::OnLButtonDown(nFlags, point);
}


void CMFCtest2View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (buttonS.size() > 0)
	{
		if (nFlags == MK_SHIFT)
		{
			if (abs(buttonS.rbegin()->x - point.x) < abs(buttonS.rbegin()->y - point.y))
				buttonM = CPoint(buttonS.rbegin()->x, point.y);
			else
				buttonM = CPoint(point.x, buttonS.rbegin()->y);
		}
		else
		{
			buttonM = buttonS[0];
			for (CPoint i : buttonS)
			{
				int dx = abs(i.x - point.x), dy = abs(i.y - point.y);
				if (dx <= 5 && dy <= 5)
					if (sqrt(dx*dx + dy * dy) <= sqrt(pow((buttonM.x - point.x), 2) + pow((buttonM.y - point.y), 2)))
						buttonM = i;
			}
			if (abs(buttonM.x - point.x) > 5 || abs(buttonM.y - point.y) > 5)
				buttonM = point;
		}

	}
	else
		buttonM = point;
	if (buttonBool)Invalidate(TRUE);
	CView::OnMouseMove(nFlags, point);
}


void CMFCtest2View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CView::OnLButtonUp(nFlags, point);
}


void CMFCtest2View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	buttonBool = FALSE;
	Invalidate(TRUE);
	CView::OnRButtonDown(nFlags, point);
}


VOID CMFCtest2View::myFill()
{
	// TODO: 在此处添加实现代码

	if (buttonS.size() == 0)return;

	GetClientRect(&rect);

	std::vector<CAET>caet;
	std::vector< std::vector<CAET> >cbucket;
	CPoint minp = buttonS[0], maxp = buttonS[0];
	for (CPoint i : buttonS)
	{
		if (i.y < minp.y)minp = i;
		if (i.y > maxp.y)maxp = i;
	}
	cbucket.resize(maxp.y - minp.y + 1);
	return;
}
