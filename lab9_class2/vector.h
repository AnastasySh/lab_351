#pragma once
#include "matr.h"
class vector : matrix
{
private:
	int size;
	double vec[10];
public:
	double scalMultVector(vector vec2);
	double getElem(int n);
	void vecMult(double k);
};