
// MFCtest2View.h: CMFCtest2View 类的接口
//

#pragma once


class CMFCtest2View : public CView
{
protected: // 仅从序列化创建
	CMFCtest2View() noexcept;
	DECLARE_DYNCREATE(CMFCtest2View)

// 特性
public:
	CMFCtest2Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMFCtest2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFCtest2View.cpp 中的调试版本
inline CMFCtest2Doc* CMFCtest2View::GetDocument() const
   { return reinterpret_cast<CMFCtest2Doc*>(m_pDocument); }
#endif

