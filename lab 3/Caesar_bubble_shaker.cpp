/*
ЛАБОРАТОРНАЯ РАБОТА №3
шифр цезаря. сортировка пузырьком. шейкерная сортировка.
Функции. объявление и вызов. 
функции пишутся вне main. использование функций помогает сократить код. 
если функция ничего не возвращает можно использовать тип данных void. А так же оставить пустым место под аргументы. 
ОБЪЯВЛЕНИЕ ФУНКЦИИ: <взвращаемый тип данных> <имя> (<аргументы функции>) {
  };
  ПРИМЕР: int sum(int b, int c) 
  {
  return a + b; // то что функция возвращает пишется через return. не забывай что в return можно записывать не одну переменную,
  а в принципе все действия в строчку. по факту тело функции может вообще состоять из одного большого return
  };
  ВЫЗОВ ФУНКЦИИ: 
  <имя функции> (<аргументы, если они есть>);
  ПРИМЕР: sum(1, 2);
*/

#include "pch.h"
//#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std; // использовать данную штуку не очень хорошо как оказалось. лучше испольховать следующие конструкции.
// using std::cin;
// using std::cout;

void caesar()
{
	cout << "enter the message \n";
	char buffer[50] = { 0 };
	cin >> buffer;
	for (int i = 0; i < strlen(buffer); i++) /*strlen - функция определяющая количество символов в строке*/

		if (buffer[i] >= 88 && buffer[i] <= 90
			||
			buffer[i] >= 120 && buffer[i] <= 122) /*чтобы xyz заменялся на abc
												   (надо потом поискать как заменить
												   кучу and на что-то более красивое)*/
		{
			buffer[i] -= 23;
		}
		else {
			buffer[i] += 3;
		}
	cout << "encrypted message \n" << buffer << endl;
	system("pause");
	system("cls");
};
void bubble()
{
	int n = 0;

	cout << "array size = ";
	cin >> n;
	int *mass = new int[n]; /*реализация через динамическую память */

	for (int i = 0; i < n; i++) { /*заполнение массива*/
		cout << i + 1 << "element = ";
		cin >> mass[i];
	}
	system("cls"); /*очистка экрана (прикольная полезная штука)*/
	cout << "original array" << endl; /*вывод первоначального массива*/
	for (int i = 0; i < n; i++)
	{
		cout << mass[i] << " ";
	}
	cout << endl;
	/*сама сортировка из двух циклов*/
	for (int i = 1; i < n; i++) /*внешний - количество проходок */
	{
		for (int r = 0; r < n - i; r++) /*внутренний - сравнивает соседние и переставляет*/
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
	for (int i = 0; i < n; i++)
	{
		cout << mass[i] << " ";
	}
	cout << endl;
	delete[] mass; /*очистка динамического массива*/

	system("pause");
	system("cls");
};
void coctail()
{
	int m = 0;

	cout << "array size = ";
	cin >> m;
	int *mass2 = new int[m];

	for (int i = 0; i < m; i++) {
		cout << i + 1 << "element = ";
		cin >> mass2[i];
	}
	system("cls");
	cout << "original array" << endl;
	for (int i = 0; i < m; i++)
	{
		cout << mass2[i] << " ";
	}
	cout << endl;

	int L, R, i;

	L = 1;
	R = m - 1;
	while (L <= R)
	{

		for (i = R; i >= L; i--)
			if (mass2[i - 1] > mass2[i])
			{
				int С = mass2[i];
				mass2[i] = mass2[i - 1];
				mass2[i - 1] = С;

			};
		L++;
		for (i = L; i <= R; i++)
			if (mass2[i - 1] > mass2[i])
			{
				int С = mass2[i];
				mass2[i] = mass2[i - 1];
				mass2[i - 1] = С;

			};
		R--;
	}

	cout << "new array" << endl;
	for (int i = 0; i < m; i++)
	{
		cout << mass2[i] << " ";
	}
	cout << endl;
};

int main()
{
	cout << "\t \t \t the Caesar cipher (En) \n";
		caesar();
	cout << " \t \t \t bubble \n";
		bubble();
	cout << " \t \t \t  Cocktail sort \n";
		coctail();		
	return 0;
}
