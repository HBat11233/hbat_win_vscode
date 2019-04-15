#include "stdafx.h"
#include "CLine.h"


CLine::CLine()
{
}


CLine::~CLine()
{
}

CLine::CLine(CPoint b, CPoint e)
	:b(b), e(e) {}

void CLine::Draw(CDC *pDC)
{
	HBRUSH hbrush();
}