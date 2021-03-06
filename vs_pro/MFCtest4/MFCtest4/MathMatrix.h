#pragma once

#include "CP3.h"

class MathMatrix
{
public:
	int lenx;
	int leny;
	double ** matrix;
public:
	MathMatrix();
	MathMatrix(MathMatrix& m);
	~MathMatrix();
	bool init(int, int, double** = NULL);
	bool init(int, int, CP3*);
	bool clear();
	MathMatrix operator * (MathMatrix&);
	MathMatrix& operator = (MathMatrix&);
	bool toArr(int** arr);
	bool toCP3(CP3* p);
};

