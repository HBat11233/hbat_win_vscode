#pragma once
class CLine
{
private:
	CPoint b;
	CPoint e;
	BOOL pk;
public:
	CLine();
	CLine(CPoint b, CPoint e);
	~CLine();
	VOID Draw(CDC *pDC);
	VOID MoveTo(CPoint p);
	VOID LineTo(CDC* pDC,CPoint p);
};

