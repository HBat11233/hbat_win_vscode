#pragma once
class MathMatrix
{
public:
	int lenx;
	int leny;
	int** matrix;
public:
	MathMatrix();
	MathMatrix(MathMatrix& m);
	~MathMatrix();
	bool init(int, int, int** = NULL);
	bool clear();
	MathMatrix operator * (MathMatrix&);
};

