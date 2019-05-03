#include "pch.h"
#include <iostream>
#include "matr.h"
#include "vector.h"


double vector::scalMultVector(vector vec2)
{
	if (size == vec2.size)
	{
		double sum = 0;
		for (int i = 0; i < size; i++)
		{
			sum += vec[i] * vec2.vec[i];
		}
		return sum;
	}
	else
	{
		std::cout << "Error!";
		return -1;
	}
}

double vector::getElem(int n)
{
	if (n < 10 && n > -1)
	{
		return vec[n];
	}
	return -1;
}

void vector::vecMult(double k)
{
	for (int i = 0; i < size; i++)
	{
		vec[i] *= k;
	}
}