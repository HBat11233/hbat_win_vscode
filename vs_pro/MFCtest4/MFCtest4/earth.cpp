#include "pch.h"
#include "earth.h"


earth::earth()
	:n(0),m(0),R(0),len(0),que(NULL)
{
}


earth::~earth()
{
	clear();
}


bool earth::init(int n, int m, int R)
{
	// TODO: 在此处添加实现代码.
	if (len)
		clear();
	this->n = n;
	this->m = m;
	this->R = R;
	len = n * m;
	CP3** cp3;
	cp3 = this->CreateCP3();
	CreateCFace(cp3);
	DeleteCP3(cp3);
	return false;
}


CP3** earth::CreateCP3()
{
	// TODO: 在此处添加实现代码.
	const double PI = 3.1415926;
	CP3** cp3;
	cp3 = new CP3 * [m - 1];
	for (int i = 0; i < m - 1; ++i)
		cp3[i] = new CP3[n];
	double dx = 2 * PI / n;
	double dy = PI / m;
	for (int i = 1; i < m; ++i)
		for (int j = 0; j < n; ++j)
		{
			//int a = round(R * sin(i * dy) * sin(j * dx));
			//int b = round(R * cos(i * dy));
			//int c = round(R * sin(i * dy) * cos(j * dx));
			cp3[i - 1][j] = CP3(round(R * sin(i * dy) * sin(j * dx)), round(R * cos(i * dy)), round(R * sin(i * dy) * cos(j * dx)));
		}
	return cp3;
}


bool earth::DeleteCP3(CP3** cp3)
{
	// TODO: 在此处添加实现代码.
	for (int i = 0; i < m - 1; ++i)
		delete[] cp3[i];
	delete[] cp3;
	return false;
}


bool earth::CreateCFace(CP3** cp3)
{
	// TODO: 在此处添加实现代码.
	const int lenx = m - 1;
	const int leny = n;
	const CP3 ncp(0,R,0);
	const CP3 scp(0, -R, 0);
	que = new CFace[len];
	//开始创建，创建三角形
	//创建新建点，边集合
	CP3* t = new CP3[3];
	std::pair<int, int>* p = new std::pair<int, int>[3];
	p[0].first = p[2].second = 0;
	p[1].first = p[0].second = 1;
	p[2].first = p[1].second = 2;
	for (int i = 0; i < n; ++i)
	{
		//设置北极三角
		que[i].SetEn(3);
		t[0] = ncp;
		t[1] = cp3[0][i];
		t[2] = cp3[0][(i + 1) % n];
		que[i].SetPoint(t);
		que[i].SetPair(p);
		//设置南极三角
		que[i+n].SetEn(3);
		t[0] = scp;
		t[1] = cp3[m-2][(i) % n];
		t[2] = cp3[m-2][(i + 1) % n];
		que[i+n].SetPoint(t);
		que[i+n].SetPair(p);
	}
	delete[] t;
	delete[] p;
	//转换四边形
	t = new CP3[4];
	p = new std::pair<int, int>[4];
	p[0].first = p[3].second = 0;
	p[1].first = p[0].second = 1;
	p[2].first = p[1].second = 2;
	p[3].first = p[2].second = 3;
	for (int i = 1; i < m - 1; ++i)
		for (int j = 0; j < n; ++j)
		{
			t[0] = cp3[i][j];
			t[1] = cp3[i][(j + 1)%n];
			t[2] = cp3[i - 1][(j + 1)%n];
			t[3] = cp3[i - 1][j];
			que[(i + 1) * n + j].SetEn(4);
			que[(i + 1) * n + j].SetPair(p);
			que[(i + 1) * n + j].SetPoint(t);
		}
	delete[] t;
	delete[] p;
	t = NULL;
	p = NULL;
	return false;
}


bool earth::clear()
{
	// TODO: 在此处添加实现代码.
	delete[] que;
	return false;
}
