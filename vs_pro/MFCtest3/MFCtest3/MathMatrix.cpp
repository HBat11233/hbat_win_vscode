#include "pch.h"
#include "MathMatrix.h"


MathMatrix::MathMatrix()
	:lenx(0),leny(0),matrix(NULL)
{
}


MathMatrix::~MathMatrix()
{
	clear();
}

MathMatrix::MathMatrix(MathMatrix& m)
{
	init(m.lenx, m.leny, m.matrix);
}

bool MathMatrix::init(int x, int y, int** m)
{
	matrix = new int*[x];
	for (int i = 0; i < x; ++i)
		matrix[i] = new int[y];
	if (m != NULL)
		for (int i = 0; i < x; ++i)
			for (int j = 0; j < y; ++j)
				matrix[i][j] = m[i][j];
	else
		for (int i = 0; i < x; ++i)
			for (int j = 0; j < y; ++j)
				matrix[i][j] = 0;
	return false;
}

bool MathMatrix::init(int x, int y, CP3* p)
{
	matrix = new int* [x];
	for (int i = 0; i < x; ++i)
		matrix[i] = new int[y];
	for(int i=0;i<x;++i)
		for (int j = 0; j < y; ++j)
		{
			switch (j)
			{
			case 0:
				matrix[i][j] = p[i].x;
				break;
			case 1:
				matrix[i][j] = p[i].y;
				break;
			case 2:
				matrix[i][j] = p[i].y;
			default:
				matrix[i][j] = 1;
				break;
			}
		}
	return false;
}

bool MathMatrix::clear()
{
	if (matrix != NULL)
	{
		for (int i = 0; i < lenx; ++i)
			delete[] matrix[i];
		delete[] matrix;
		matrix = NULL;
	}
	return false;
}

MathMatrix MathMatrix::operator*(MathMatrix&m)
{
	MathMatrix ans;
	ans.init(this->lenx, m.leny);
	for (int i = 0; i < this->lenx; ++i)
		for (int j = 0; j < m.leny; ++j)
			for (int k = 0; k < this->leny; ++k)
				ans.matrix[i][j] += this->matrix[i][k] * m.matrix[k][j];
	return ans;
}


bool MathMatrix::toArr(int** arr)
{
	// TODO: 在此处添加实现代码.
	for (int i = 0; i < lenx; ++i)
		for (int j = 0; j < leny; ++j)
			arr[i][j] = matrix[i][j];
	return false;
}


bool MathMatrix::toCP3(CP3* p)
{
	// TODO: 在此处添加实现代码.
	for (int i = 0; i < lenx; ++i)
		p[i] = CP3(matrix[i][0], matrix[i][1], matrix[i][2]);
	return false;
}