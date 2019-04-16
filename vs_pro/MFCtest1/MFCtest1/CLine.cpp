#include "stdafx.h"
#include "CLine.h"


CLine::CLine()
	:pk(FALSE), cb(0x000000), ce(0x000000)
{
}


CLine::~CLine()
{
}

CLine::CLine(CPoint b, CPoint e)
	:b(b), e(e), pk(FALSE), cb(0x000000), ce(0x000000) {}

VOID CLine::Draw(CDC *pDC)
{
	CPoint p;
	DOUBLE drtR = INT(ce / (1 << 16)) - INT(cb / (1 << 16));
	DOUBLE drtG = INT((ce % (1 << 16)) / (1 << 8)) - INT((cb % (1 << 16)) / (1 << 8));
	DOUBLE drtB = INT(ce % (1 << 8)) - INT(cb % (1 << 8));
	if (fabs(b.x - e.x) < 1e-6)
	{
		if (b.y > e.y)
		{
			std::swap(b, e);
			pk = TRUE;
		}
		for (p = b; p.y < e.y; p.y++)
		{
			double i = (p.y - b.y) / double(e.y - b.y);
			DOUBLE j = (1 - i);
			if (pk)
				std::swap(i, j);
			COLOR24 t = cb + drtR * i*(1 << 16) + drtG * i * (1 << 8) - drtB * i;
			if (pk)
				t = ce - drtR * j*(1 << 16) - drtG * j * (1 << 8) - drtB * j;
			pDC->SetPixelV(round(p.x), round(p.y), t);
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
				std::swap(b, e);
				pk = TRUE;
			}
			d = 1 - 0.5*k;
			for (p = b; p.y < e.y; p.y++)
			{
				double i = (p.y - b.y) / double(e.y - b.y);
				DOUBLE j = (1 - i);
				if (pk)
					std::swap(i, j);
				COLOR24 t = cb + drtR * i*(1 << 16) + drtG * i * (1 << 8) - drtB * i;
				if (pk)
					t = ce - drtR * j*(1 << 16) - drtG * j * (1 << 8) - drtB * j;
				pDC->SetPixelV(round(p.x), round(p.y), t);
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
				std::swap(b, e);
				pk = TRUE;
			}
			d = 0.5 - k;
			for (p = b; p.x < e.x; p.x++)
			{
				double i = (p.x - b.x) / double(e.x - b.x);
				DOUBLE j = (1 - i);
				if (pk)
					std::swap(i, j);
				COLOR24 t = cb + drtR * i*(1 << 16) + drtG * i * (1 << 8) - drtB * i;
				if (pk)
					t = ce - drtR * j*(1 << 16) - drtG * j * (1 << 8) - drtB * j;
				pDC->SetPixelV(round(p.x), round(p.y), t);
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
				std::swap(b, e);
				pk = TRUE;
			}
			d = -0.5 - k;
			for (p = b; p.x < e.x; p.x++)
			{
				double i = (p.x - b.x) / double(e.x - b.x);
				DOUBLE j = (1 - i);
				if (pk)
					std::swap(i, j);
				COLOR24 t = cb + drtR * i*(1 << 16) + drtG * i * (1 << 8) - drtB * i;
				if (pk)
					t = ce - drtR * j*(1 << 16) - drtG * j * (1 << 8) - drtB * j;
				pDC->SetPixelV(round(p.x), round(p.y), t);
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
				std::swap(b, e);
				pk = TRUE;
			}
			d = -1 - 0.5*k;
			for (p = b; p.y > e.y; --p.y)
			{
				double i = (p.y - b.y) / double(e.y - b.y);
				DOUBLE j = (1 - i);
				if (pk)
					std::swap(i, j);
				COLOR24 t = cb + drtR * i*(1 << 16) + drtG * i * (1 << 8) - drtB * i;
				if (pk)
					t = ce - drtR * j*(1 << 16) - drtG * j * (1 << 8) - drtB * j;
				pDC->SetPixelV(round(p.x), round(p.y), t);
				if (d < 0)
				{
					p.x++;
					d -= 1 + k;
				}
				else
					d -= 1;
			}
		}
	}
}

VOID CLine::MoveTo(CPoint p)
{
	b = p;
	pk = FALSE;
}

VOID CLine::LineTo(CDC* pDC, CPoint p)
{
	e = p;
	Draw(pDC);
	MoveTo(e);
}

CPoint CLine::getB()
{
	return b;
}

CPoint CLine::getE()
{
	return e;
}

VOID CLine::SetColorB(COLOR24 b)
{
	cb = b;
}

VOID CLine::SetColorE(COLOR24 e)
{
	ce = e;
}

VOID CLine::SetColor(COLOR24 b, COLOR24 e)
{
	SetColorB(b);
	SetColorE(e);
}