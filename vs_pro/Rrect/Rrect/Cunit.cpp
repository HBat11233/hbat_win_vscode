#include "stdafx.h"
#include "Cunit.h"


Cunit::Cunit()
{
	init();
	len = 4;
	arr = NULL;
	Hmap = NULL;
}


Cunit::~Cunit()
{
	clear();
}


bool Cunit::init(int style, CMap *mHmap,int **m,int mlen)
{
	// TODO: 在此处添加实现代码.
	init();
	Hmap = mHmap;
	arr = NULL;
	len = 4;
	switch (style)
	{
	case STY1:
		arr = new int*[3];
		arr[0] = new int[len];
		arr[1] = new int[len];
		arr[2] = new int[len];
		for (int i = 0; i < len; ++i)
			arr[2][i] = 1;
		arr[0][0] = XLEN / 2;
		arr[1][0] = 0;
		arr[0][1] = XLEN / 2+1;
		arr[1][1] = 0;
		arr[0][2] = XLEN / 2;
		arr[1][2] = 1;
		arr[0][3] = XLEN / 2+1;
		arr[1][3] = 1;
		break;
	case STY2:
		arr = new int*[3];
		arr[0] = new int[len];
		arr[1] = new int[len];
		arr[2] = new int[len];
		for (int i = 0; i < len; ++i)
			arr[2][i] = 1;
		arr[0][0] = XLEN / 2;
		arr[1][0] = 0;
		arr[0][1] = XLEN / 2;
		arr[1][1] = 1;
		arr[0][2] = XLEN / 2+1;
		arr[1][2] = 1;
		arr[0][3] = XLEN / 2+2;
		arr[1][3] = 1;
		break;
	case STY3:
		arr = new int*[3];
		arr[0] = new int[len];
		arr[1] = new int[len];
		arr[2] = new int[len];
		for (int i = 0; i < len; ++i)
			arr[2][i] = 1;
		arr[0][0] = XLEN / 2+2;
		arr[1][0] = 0;
		arr[0][1] = XLEN / 2;
		arr[1][1] = 1;
		arr[0][2] = XLEN / 2+1;
		arr[1][2] = 1;
		arr[0][3] = XLEN / 2+2;
		arr[1][3] = 1;
		break;
	case STY4:
		arr = new int*[3];
		arr[0] = new int[len];
		arr[1] = new int[len];
		arr[2] = new int[len];
		for (int i = 0; i < len; ++i)
			arr[2][i] = 1;
		arr[0][0] = XLEN / 2+1;
		arr[1][0] = 0;
		arr[0][1] = XLEN / 2;
		arr[1][1] = 1;
		arr[0][2] = XLEN / 2+1;
		arr[1][2] = 1;
		arr[0][3] = XLEN / 2+2;
		arr[1][3] = 1;
		break;
	case STY5:
		arr = new int*[3];
		arr[0] = new int[len];
		arr[1] = new int[len];
		arr[2] = new int[len];
		for (int i = 0; i < len; ++i)
			arr[2][i] = 1;
		arr[0][0] = XLEN / 2-1;
		arr[1][0] = 0;
		arr[0][1] = XLEN / 2;
		arr[1][1] = 0;
		arr[0][2] = XLEN / 2+1;
		arr[1][2] = 0;
		arr[0][3] = XLEN / 2+2;
		arr[1][3] = 0;
		break;
	default:
		len = mlen;
		arr = new int*[3];
		arr[0] = new int[len];
		arr[1] = new int[len];
		arr[2] = new int[len];
		for (int i = 0; i < len; ++i)
			arr[2][i] = 1;
		for (int i = 0; i < len; ++i)
			for (int j = 0; j < len; ++j)
				arr[i][j] = m[i][j];
		break;
	}
	return Hmap->stauts(arr[0], arr[1], len);
}


void Cunit::clear()
{
	cleararr(arr, 3);
	arr = NULL;
	Hmap = NULL;
	len = 4;
	init();
	// TODO: 在此处添加实现代码.
}


bool Cunit::run(HDC hdc, HBRUSH hbr)
{
	// TODO: 在此处添加实现代码.
	downButton(hdc, hbr);
	if (left)
		leftButton(hdc, hbr);
	if (right)
		rightButton(hdc, hbr);
	if (down)
		downButton(hdc, hbr);
	if (up)
		upButton(hdc, hbr);
	init();
	return false;
}


bool Cunit::leftButton(HDC hdc, HBRUSH hbr)
{
	// TODO: 在此处添加实现代码.
	int **tarr = new int*[2];
	tarr[0] = new int[len];
	tarr[1] = new int[len];
	for (int i = 0; i < len; ++i)
	{
		tarr[0][i] = arr[0][i] - 1;
		tarr[1][i] = arr[1][i];
	}
	int message = 0;
	if (message = Hmap->draw(hdc, hbr, tarr[0], tarr[1], len))
	{
		Hmap->draw(hdc, hbr, arr[0], arr[1], len);
		cleararr(tarr, 2);
		tarr = NULL;
		return true;
	}
	else
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < len; ++j)
				arr[i][j] = tarr[i][j];
	cleararr(tarr, 2);
	tarr = NULL;
	return false;
}

bool Cunit::rightButton(HDC hdc, HBRUSH hbr)
{
	// TODO: 在此处添加实现代码.
	int **tarr = new int*[2];
	tarr[0] = new int[len];
	tarr[1] = new int[len];
	for (int i = 0; i < len; ++i)
	{
		tarr[0][i] = arr[0][i] +1;
		tarr[1][i] = arr[1][i];
	}
	int message = 0;
	if (message = Hmap->draw(hdc, hbr, tarr[0], tarr[1], len))
	{
		Hmap->draw(hdc, hbr, arr[0], arr[1], len);
		cleararr(tarr, 2);
		tarr = NULL;
		return true;
	}
	else
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < len; ++j)
				arr[i][j] = tarr[i][j];
	cleararr(tarr, 2);
	tarr = NULL;
	return false;
}

bool Cunit::downButton(HDC hdc, HBRUSH hbr)
{
	// TODO: 在此处添加实现代码.
	int **tarr = new int*[2];
	tarr[0] = new int[len];
	tarr[1] = new int[len];
	for (int i = 0; i < len; ++i)
	{
		tarr[0][i] = arr[0][i];
		tarr[1][i] = arr[1][i] + 1;
	}
	int message = 0;
	if (message = Hmap->draw(hdc, hbr, tarr[0], tarr[1], len))
	{
		Hmap->add(hdc, hbr, arr[0], arr[1], len);
		cleararr(tarr, 2);
		tarr = NULL;
		clear();
		return true;
	}
	else
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < len; ++j)
				arr[i][j] = tarr[i][j];
	cleararr(tarr, 2);
	tarr = NULL;
	return false;
}

bool Cunit::upButton(HDC hdc, HBRUSH hbr)
{
	// TODO: 在此处添加实现代码.
	int **tarr = new int*[3];
	tarr[0] = new int[len];
	tarr[1] = new int[len];
	tarr[2] = new int[len];
	for (int i = 0; i < len; ++i)
	{
		tarr[2][i] = 0;
		tarr[0][i] = 0;
		tarr[1][i] = 0;
	}
	int xunazhuan[3][3]=
	{
		{0,1,0},
		{-1,0,0},
		{arr[0][0]+arr[1][0],arr[1][0]-arr[0][0],1}
	};
	for (int i = 0; i < len; ++i)
		for (int j = 0; j < 3; ++j)
			for (int k = 0; k < 3; ++k)
				tarr[j][i] += arr[k][i] * xunazhuan[k][j];
	int message = 0;
	if (message = Hmap->draw(hdc, hbr, tarr[0], tarr[1], len))
	{
		Hmap->draw(hdc, hbr, arr[0], arr[1], len);
		cleararr(tarr, 2);
		tarr = NULL;
		return true;
	}
	else
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < len; ++j)
				arr[i][j] = tarr[i][j];
	cleararr(tarr, 2);
	tarr = NULL;
	return false;
}

// 非自定义变量赋初值
bool Cunit::init()
{
	// TODO: 在此处添加实现代码.
	up = false;
	down = false;
	left = false;
	right = false;
	return false;
}


// 判断当前方块是否存活
// true：不存活
bool Cunit::stauts()
{
	// TODO: 在此处添加实现代码.
	if (Hmap == NULL)
		return true;
	return false;
}


bool Cunit::cleararr(int **tarr,int mlen)
{
	// TODO: 在此处添加实现代码.
	for (int i = 0; i < mlen; ++i)
		delete[] tarr[i];
	delete[] tarr;
	return false;
}


bool Cunit::leftButton()
{
	// TODO: 在此处添加实现代码.
	left = true;
	return false;
}


bool Cunit::rightButton()
{
	// TODO: 在此处添加实现代码.
	right = true;
	return false;
}


bool Cunit::upButton()
{
	// TODO: 在此处添加实现代码.
	up = true;
	return false;
}


bool Cunit::downButton()
{
	// TODO: 在此处添加实现代码.
	down = true;
	return false;
}
