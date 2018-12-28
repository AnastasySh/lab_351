#include "pch.h"
#include <iostream>
#include "matr.h"
using std::cin;
using std::cout;
using std::endl;
matrix::matrix()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			matr[i][j] = 0;
			
		}
	}
};
matrix::~matrix()
{
};
void matrix::input()
{
	cout << "введите количество строк" << endl;
	cin >> strok;
	cout << "введите количество стoлбцов" << endl;
	cin >> stolb;

	for (int i = 0; i < strok; i++)
	{
		for (int j = 0; j < stolb; j++)
		{
			cout << "введите"<<i<<" "<<j<<" элемент"<< endl;
			cin >> matr[i][j];

		}
	}
};
void matrix::print()
{
	
	for (int i = 0; i < strok; i++)
	{
		for (int j = 0; j < stolb; j++)
		{
			cout << matr[i][j]<<" ";

		}
		cout << endl;
	}
};
int matrix::getstrok(matrix matr1)
{
	return strok;
};
int matrix::getstolb(matrix matr1)
{
	return stolb;
};
void matrix::summmatr(matrix matr1, matrix matr2)
{
	if (matr1.strok != matr2.strok || matr1.stolb != matr2.stolb)
	{
		cout << "error!" << endl;
	}
	else
	{
		for (int i = 0; i < strok; i++)
		{
			for (int j = 0; j < stolb; j++)
			{
				matr1[i][j] += matr2[i][j];
			};
		};
	};
};
void matrix::multmatr(matrix matr1, matrix matr2)
{
	if (matr1.strok == matr2.stolb || matr2.strok == matr1.stolb)
	{
		for (int i = 0; i < strok; i++)
		{
			for (int j = 0; j < stolb; j++)
			{
				for (int k = 0; k < strok; k++)
				{
					matr1[i][k] * matr2[k][j];
				};
			};
		};
	};
};
void matrix::transp(matrix matr1)
{
	int a = matrix::getstrok(matr1);
	int b = matrix::getstolb(matr1);
	int matrtime[10][10] = { 0 };
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			matrtime[j][i] = matr1[i][j];
		};
	};
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			matr[i][j] = matrtime[i][j];

		}
	}

};

