#include "stdafx.h"
#include "CLine.h"


CLine::CLine()
	:pk(FALSE)
{
}


CLine::~CLine()
{
}

CLine::CLine(CPoint b, CPoint e)
	:b(b), e(e), pk(FALSE) {}

VOID CLine::Draw(CDC *pDC)
{
	CPoint p, t;
	if (fabs(b.x - e.x) < 1e-6)
	{
		if (b.y > e.y)
		{
			t = b;
			b = e;
			e = t;
			pk = TRUE;
		}
		for (p = b; p.y < e.y; p.y++)
		{
			double i = (p.y - b.y) / double(e.y - b.y);
			DOUBLE j = (1 - i);
			if (pk)
			{
				DOUBLE t = i;
				i = j;
				j = t;
			}
			pDC->SetPixelV(round(p.x), round(p.y), RGB(255 * i, 255 * j, 0));
		}
	}
	else
	{  
		double k, d;
		k = (e.y - b.y) / double(e.x - b.x);
		if (k > 1.0)
		{
			if (b.y > e.y)
			{
				t = b;
				b = e;
				e = t;
				pk = TRUE;
			}
			d = 1 - 0.5*k;
			for (p = b; p.y < e.y; p.y++)
			{
				double i = (p.y - b.y) / double(e.y - b.y);
				DOUBLE j = (1 - i);
				if (pk)
				{
					DOUBLE t = i;
					i = j;
					j = t;
				}
				pDC->SetPixelV(round(p.x), round(p.y), RGB(255 * i, 255 * j, 0));
				if (d >= 0)
				{
					p.x++; 
					d += 1 - k;
				}
				else d += 1;
			}
		}
		else if (k <= 1.0&&k >= 0.0)
		{
			if (b.x > e.x)
			{
				t = b;
				b = e;
				e = t;
				pk = TRUE;
			}
			d = 0.5 - k;
			for (p = b; p.x < e.x; p.x++)
			{
				double i = (p.x - b.x) / double(e.x - b.x);
				DOUBLE j = (1 - i);
				if (pk)
				{
					DOUBLE t = i;
					i = j;
					j = t;
				}
				pDC->SetPixelV(round(p.x), round(p.y), RGB(255 * i, 255 * j, 0));
				if (d < 0)
				{
					p.y++;
					d += 1 - k;
				}
				else d -= k;
			}
		}
		else if (k >= -1.0&&k < 0.0)
		{
			if (b.x > e.x)
			{
				t = b;
				b = e;
				e = t;
				pk = TRUE;
			}
			d = -0.5 - k;
			for (p = b; p.x < e.x; p.x++)
			{
				double i = (p.x - b.x) / double(e.x - b.x);
				DOUBLE j = (1 - i);
				if (pk)
				{
					DOUBLE t = i;
					i = j;
					j = t;
				}
				pDC->SetPixelV(round(p.x), round(p.y), RGB(255 * i, 255 * j, 0));
				if (d > 0)
				{
					p.y--;
					d -= 1 + k;
				}
				else d -= k;
			}
		}
		else if (k < -1.0)
		{
			if (b.y < e.y)
			{
				t = b;
				b = e;
				e = t;
				pk = TRUE;
			}
			d = -1 - 0.5*k;
			for (p = b; p.y > e.y; --p.y)
			{
				double i = (p.y - b.y) / double(e.y - b.y);
				DOUBLE j = (1 - i);
				if (pk)
				{
					DOUBLE t = i;
					i = j;
					j = t;
				}
				pDC->SetPixelV(round(p.x), round(p.y), RGB(255 * i, 255 * j, 0));
				if (d < 0)
				{
					p.x++;
					d -= 1 + k;
				}
				else
				{
					d -= 1;
				}

			}
		}
	}
}

VOID CLine::MoveTo(CPoint p)
{
	b = p;
}

VOID CLine::LineTo(CDC* pDC,CPoint p)
{
	e = p;
	Draw(pDC);
	b = e;
}