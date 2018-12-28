#include "pch.h"
#include <iostream>
#include "matr.h"
#include "vector.h"
using std::cin;
using std::cout;



int main()
{
	setlocale(LC_ALL, "Russian");
	matrix A1, A2;
	A1.input();
	A1.print();
	A2.input();
	A1.summmatr(A2);
	A1.print();
	A1.multmatr(A2);
	A1.print();
	A1.transp();
	A1.print();


};
