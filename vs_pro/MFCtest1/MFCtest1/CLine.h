#pragma once
class CLine
{
private:
	CPoint b;
	CPoint e;
public:
	CLine();
	CLine(CPoint b, CPoint e);
	~CLine();
	void Draw(CDC *pDC);
};

