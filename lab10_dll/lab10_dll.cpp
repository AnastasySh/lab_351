// lab10_dll.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "Windows.h"

extern "C" __declspec(dllimport) int Disc(int a, int b, int c);

int main()
{

	int a, b, c;
	int d = 0;
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	d = Disc(a, b, c);
	std::cout << d;
	return 0;
}
