#pragma once

#include <algorithm>
typedef INT COLOR24;

class CLine
{
private:
	CPoint b;
	CPoint e;
	BOOL pk;
	COLOR24 cb;
	COLOR24 ce;
public:
	CLine();
	CLine(CPoint b, CPoint e);
	~CLine();
	VOID Draw(CDC *pDC);
	VOID MoveTo(CPoint p);
	VOID LineTo(CDC* pDC,CPoint p);
	CPoint getB();
	CPoint getE();
	VOID SetColorB(COLOR24 b);
	VOID SetColorE(COLOR24 e);
	VOID SetColor(COLOR24 b, COLOR24 e);
};

