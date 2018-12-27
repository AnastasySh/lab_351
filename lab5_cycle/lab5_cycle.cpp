// ЦИКЛЫ, ПЕРЕХОДЫ
/* if - оператор условного перехода
if(лог_усл)
{
		код, выполняемый если (лог_усл ==true)
}
if(лог_усл)
{
		код, выполняемый если лог_усл ==true
}
else
{
		код, выполняемый в противном случае
}
Примеры:
if(a > b){... ;
bool c = ...;
bool d = ...;
if(c && d) {...
*/

#include "pch.h"
#include <iostream>

int arr_int[10] = { 0 };
void input_array(int *arr) {
	for (int i = 0; i < 20; i++)
	{
		std::cin >> arr[i];
	}
}
int func(int *num1, int num2);
int main()
{
	int num1 = 1, num2 = 2, res = 0;
	res = func(&num1, num2);
	std::cout << res << " " << num1 << " " << num2;
}
int func(int *num1, int num2) {
	*num1 += 20;
	return *num1 + num2;
}
