﻿// ЦИКЛЫ, ПЕРЕХОДЫ

/*
В языке Си следующие операторы циклов:
for — параметрический цикл (цикл с заданным числом повторений).
while — цикл с предусловием;
do…while — цикл с постусловием;
 операторы условий 
 иф и свитч
 свитч необходим в тех случаях, когда в зависимости от значений переменной надо выполнить те или иные операторы:
switch (выражение)
{
case значение_1: операторы_1; break;
case значение_2: операторы_2; break;
case значение_3: операторы_3; break;
…
case значение_n: операторы_n; break;
default: операторы; break;
}
Оператор break необходим для того, чтобы осуществить выход из
операторы switch. Если он не указан, то будут выполняться следующие операторы из списка, 
несмотря на то, что значение, которым они помечены, не совпадает со значением выражения.

Оператор continue
Этот оператор применяется тогда, когда необходимо прервать (пропустить) текущую итерацию 
цикла и приступить к следующей итерации. При его выполнении в цикле for происходит остановка текущей итерации, 
переход к изменению управляющей переменной, а затем проверка условия продолжения выполнения цикла.

Тернарный оператор
Тернарный оператор позволяет выполнять различные коды в зависимости от значения условия,
и результатом выражения является результат выполнения кода. Например:
1
iint divide = ( val != 0 ? 5 / val : 0 );
Cначала выполняется проверка, val != 0 или равно, и если условие — истина,
то выполняется операция деления — 5 / val.
*/
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
