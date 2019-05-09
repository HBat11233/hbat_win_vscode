
// MFCtest3View.h: CMFCtest3View 类的接口
//

#pragma once

#include "CP3.h"
#include "CFace.h"
#include "MathMatrix.h"

class CMFCtest3View : public CView
{
protected: // 仅从序列化创建
	CMFCtest3View() noexcept;
	DECLARE_DYNCREATE(CMFCtest3View)

	// 特性
public:
	CMFCtest3Doc* GetDocument() const;

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
	virtual ~CMFCtest3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	int ReadPoint();
	int ReadFace();
private:
	CP3 point[8];
	CFace face[6];
	double k[8];
	double Theta;
	double Phi;
	double R;
	double d;
	const double PI = 3.1415926;
	bool bRun;
	bool ty;
	bool xz;
public:
	bool DrawCuboid(CDC* pDC);
	bool initK();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnFunRun();
	afx_msg void OnFun32772();
	afx_msg void OnFun32773();
};

#ifndef _DEBUG  // MFCtest3View.cpp 中的调试版本
inline CMFCtest3Doc* CMFCtest3View::GetDocument() const
{
	return reinterpret_cast<CMFCtest3Doc*>(m_pDocument);
}
#endif

