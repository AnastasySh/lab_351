#include "pch.h"
/*#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;
int bub()
{
	int n = 0; 
	cout << " \t \t \t bubble \n";
	cout << "array size = "; 
	cin >> n; 
	int *mass = new int [n]; /*только через new 
	
	for(int i = 0; i < n; i++) { /*заполнение массива
		cout << i + 1 << "element = ";
		cin >> mass[i];
	}
	system("cls"); /*очистка экрана (прикольная полезная штука)
	cout << "original array" << endl; /*вывод первоначального массива
	for (int i = 0; i < n; i++)
	{
		cout << mass[i] << " "; 
	}
	cout << endl;
/*сама сортировка из двух циклов
	for (int i = 1; i < n; i++) /*внешний - количество проходок 
	{
		for (int r = 0; r < n - i; r++) /*внутренний - сравнивает соседние и переставляет
		{
			if (mass[r] < mass[r + 1])
			{
			
				int С = mass[r]; 
				mass[r] = mass[r + 1];
				mass[r + 1] = С;
			}
		}
	}

	cout << "new array" << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << mass[i] << " ";
	}
	cout << endl;
	return 0;
}*/