

#include "pch.h"
#include <iostream>

int main()
{
	int strok = 5;
	int stolb = 4;
	int ** matr = new int *[strok];
	matr[0] = new int [strok*stolb];
	for (int i = 0; i < strok; i++)
	{
		matr[i] = matr[i - 1] + stolb;
	}
}
