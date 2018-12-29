#include "pch.h"
#include <iostream>
#include "matr.h"
using std::cin;
using std::cout;
using std::endl;
matrix::matrix()
{
	/*setlocale(LC_ALL, "Russian");
	int strok1, stolb1;
	cout << "������� ���������� �����" << endl;
	cin >> strok1;
	cout << "������� ���������� ��o�����" << endl;
	cin >> stolb1;
	strok = strok1;
	stolb = stolb1;
	matr[0] = new int[strok*stolb];
	for (int i = 0; i < strok; i++)
	{
		matr[i] = matr[i - 1] + stolb;
	}*/
};
matrix::~matrix()
{
	delete[] matr[0];
	delete[] matr; 
};
void matrix::input()
{
	setlocale(LC_ALL, "Russian");
	int strok1, stolb1;
	cout << "������� ���������� �����" << endl;
	cin >> strok1;
	cout << "������� ���������� ��o�����" << endl;
	cin >> stolb1;
	strok = strok1;
	stolb = stolb1;
	*matr = new int [strok * stolb];
	for (int i = 0; i < strok; i++)
	{
		for (int j = 0; j < stolb; j++)
		{
			std::cin >> *matr[i * stolb + j];
		}
	}
	
	/*������������ ������ 1 - ������ �� ������ �� �������� 2. ������ �� ������
	//������ ������������� - �������� ������ ������. ������ ������������� �������� ������ ������. ��� � ��� ���� �������� ��������
	for (int i = 0; i < strok; i++)
	{
		for (int j = 0; j < stolb; j++)
		{
			cin >> *matr[i * stolb + j];
		}
	}
	/*for (int i = 0; i < strok; i++)
	{

		for (int j = 0; j < stolb; j++)
		{
			cout << "�������" << i << " " << j << " �������" << endl;
			cin >> *matr[i]/*������������� ������� �������� ������+ ;

		}
	}*/
};
void matrix::print()
{
	cout << "������� �������" << endl;
	for (int i = 0; i < strok; i++)
	{
		for (int j = 0; j < stolb; j++)
		{
			cout << matr[i][j] << " ";

		}
		cout << endl;
	}
};
int matrix::getstrok()
{
	return strok;
};
int matrix::getstolb()
{
	return stolb;
};
int matrix::getelement(int i, int j)
{
	if (0 <= i < strok & 0 <= j < stolb)
	{
		return matr[i][j];
	}
	else
		cout << "error!";
};
void matrix::summmatr(matrix matr2)
{

	if (strok != matr2.strok || stolb != matr2.stolb)
	{
		cout << "error!" << endl;
	}
	else
	{
		for (int i = 0; i < strok; i++)
		{
			for (int j = 0; j < stolb; j++)
			{
				matr[i][j] += matr2.matr[i][j];
			};
		};
	};

};
void matrix::multmatr(matrix matr2)
{
	int a = 0;
	if (strok == matr2.stolb || matr2.strok == stolb)
	{
		for (int i = 0; i < strok; i++)
		{
			for (int j = 0; j < stolb; j++)
			{
				for (int k = 0; k < strok; k++)
				{
					a = matr[i][k] * matr2.matr[k][j];
				};
				matr[i][j] = a;
			};
		};
	};
};
void matrix::transp()
{
	matrix newmatr;
	int a = matrix::getstrok();
	int b = matrix::getstolb();

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			newmatr.matr[j][i] = matr[i][j];
		};
	};
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			matr[i][j] = newmatr.matr[i][j];
		};
	};
};

