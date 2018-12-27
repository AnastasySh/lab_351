﻿
/* Указатель - переменная, хранящая адрес(смещение) каких-либо данных,
переменных в оперативной памяти.(pointer) ptr_a, ptr_b.
1. Укахатель объявляется как обычная переменная с добавлением звездочки.
тип_данных * имя_указателя int * ptr_a
ptr_a = &a унарный оператор & амперсенд - оператор получения адреса
Фактически указатель это unsigned int или insigned long long,
так как отрицательных адресов нет.
2. Размер указателя
все указатели всегда одной и той же разрядности (размера)
каким бы ни был огромным тип данных (строка, объект, массив)
указатель на него всегда будет занимать 4/8 байт, что и является основным
преимуществом указателей.
В случае сборки на х64 размер указателей будет 8 байт (64-разрядная адресация)
3. Содержимое указателя
имя_указателя
int i = 3;
int *p = 0 ; этот указатель обнулен, то есть не указывает ни на одну ячейку памяти. 
Операция получения адреса: p = &i;

операция разыменования:  *p = 10; по факту 10 записывается в ячейку в которой храниться i, а нзачит i=10;
если делать например функцию перемены значений  без указателей, то переменные поменяются, 
но только внутри действующей функции. когда она завершит работу и уйдет из стека вызовов, то в майне 
значения остануться на прежних местах. по этому нужно использовать указатели. они по факту
работают именно с ячейкой в которой находятся значения переменных. 
ПРИМЕР:
void swap (int * a, int * b) // однако если использовать указатели, то не надо использовать
здесь кучу звездочек. указатель это int &
{
int t=*a;
*a=*b;
*b=t;
}
int main ()
{ ...
swap (&k, &m)
}

СВЯЗЬ МАССИВОВ И УКАЗАТЕЛЕЙ. АРИФМЕТИКА УКАЗАТЕЛЕЙ.
ПРИМЕР: int m[10];
int *p = &m[0];
int *q = & m [9];
(p+k) - сдвиг вправо на K ячеек размера int
(p-k) - сдвиг влево на K ячеек размера int
(q-p) - количество ячеек между указателями
p[k] - то же самое что и *(p+k)
если написать конструкцию int *p=m, то это тоже самое, что и int *p= &m[0];
заполнение массива с помощью цикла на указателях
int m[10]={0};
for (int *p = m; p <= m + 9; ++p ) 
*p= (p-m)+1;
по факту это дело забивает массив числами от 1 до 10

ПЕРЕДАЧА МАССИВА В ФУНКЦИЮ
если мы хотим чтобы функция возвращала указатель, тогда она должна быть int *
так же  в функции можно указать дополнительный элемент int * res в виде указателя в котором должен храниться результат.
сама функция может возвращать булево значение. 
ПРИМЕР 1:
объявление: int * poisk (int *p, int *q, int * res)
вызов:
int max = 0;
poisk (m, m+10, &max)
если же нам нужно получить из функции указатель тогда мы пользуемся указателем на указатель.
ПРИМЕР 2:
объявление: int * poisk(int *p, int *q, int ** res)
вызов: 
int *pmax = 0;
poisk (m, m+10, &pmax)
ПРИМЕР 3: 
int * poisk(int *m, int size, int value){ // первый указатель на начало массива. второе - размер 

for (int i = 1; i < size; ++i)
{ 
if (m[i]==value) 
{
return m[i]
}
else 
{
return 0
}
}
или же 
(int *p, int*q, int value) //где дается указание на начало и на элемент идущий после конца массива (конец массива 
в функцию можно передавать как m+10 где 10 размер массива например), тогда
for (p != q, ++p)
if ( *p == value)
 и т.д.
*/
#include "pch.h"
//
#include "stdafx.h"
#include <iostream>
using std::cout;
using std::endl;
int main()
{
	int arr1[10] = { 2, 3, 10, 32, 4 };
	int a;
	double dbl;
	int * ptr_int = &a;
	double * ptr_double = &dbl;
	cout << "int pointer size = " << sizeof(ptr_int) << endl;
	cout << "double pointer size = " << sizeof(ptr_double) << endl;
	cout << "char pointer size = " << sizeof(char*) << endl;
	cout << "long long pointer size = " << sizeof(long long*) << endl;
	cout << "bool pointer size = " << sizeof(bool*) << endl;
	//Содержимое указателей.
	cout << "ptr_int = " << ptr_int << endl;
	cout << "ptr_double = " << ptr_double << endl;
	cout << std::endl << "ptr_int = 0x" << std::hex << ptr_int << endl;
	/* std::hex включает отображение целых чисел по 16-ричной системе
	пока не будет включена другая система счисления подобным образом все числа
	будут печататья в х16 системе счисления
	*/
	cout << "arr = " << arr1 << endl;
	cout << "*arr = arr[0] = " << *arr1 << endl;
	cout << "*(arr1 + 4) = arr[4] = " << *(arr1 + 4) << endl;
	//Чтобы получить значение из указателя нужно поставить звездочку перед названием указателя
	//* имя_указателя

}
