// Dll.cpp : Определяет экспортированные функции для приложения DLL.
//

#include "stdafx.h"
#include <iostream>
#include "Dll.h"

int Disc(int a, int b, int c)
{
	int d = (b*b) - (4 * a*c);
	return d;
}


