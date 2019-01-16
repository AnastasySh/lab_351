

#include "pch.h"
#include <iostream>
#include <cstring>
#include <string>
#include "classstr.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	char a[] = { "12345" };
	std::string s1 = { "i`mtired" };
	str A1;
	A1.test();	
	str A2(a);
	A2.test();	
	/*str A3(s1);
	A3.test();
	str A4(A3);
	A4.test();
	A3.clear();//дальше проблемы
	A3.test();
	A1.add(s1);
	A1.test();
	A1.add(a);
	A1.test();*/
	A1.insert(s1);
	A1.test();
	A1 = A1 + s1;
	std::cout << A1;
	A2 = A2 + a;
	std::cout << A1;
	A1 = A1 + A2;
	std::cout << A1;
	A1.~str();
	A2.~str();
	/*A3.~str();
	A4.~str();*/

}
