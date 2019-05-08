#include "pch.h"
#include "MathMatrix.h"


MathMatrix::MathMatrix()
	:lenx(0),leny(0),matrix(NULL)
{
}


MathMatrix::~MathMatrix()
{
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

bool MathMatrix::clear()
{
	if (matrix != NULL)
	{
		for (int i = 0; i < lenx; ++i)
			delete[] matrix[i];
		delete[] matrix;
		matrix = NULL;
	}
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
