﻿// ПЕРЕГРУЗКА ОПЕРАТОРОВ
//ПЕРЕГРУЗКА ФУНКЦИЙ, МЕТОДОВ И ОПЕРАТОРОВ
//Перегрузка (overloading) - объявление нескольких функций, а также методов 
//классов и операторов, которые тоже являются функциями с одинаковыми именами, 
//но разным набором аргументов.

//унарные и бинарные операторы перегружаются по-разному.
//унарные - в самом классе (получается новый метод класса)
//бинарные - как отдельная функция

//бинарные операторы прописываются вне класса, так как результат не обязательно 
//записывается в один из операндов, а может записываться в некий третий объект 

/*К бинарным операциям, которые можно перегружать в языке С# относятся:

*арифметические операции(+, -, *, / , %)

* битовые(&, | , ^, << , >> )

* логические(= =, != , > , < , >= , <= )

	Синтаксис объявления перегруженной бинарной операции :

Public static тип_возвр_знач operator бинарная_операция (параметр1, параметр2),

где параметр – это класс, для которого перегружается данная операция, не обязательно 
2 параметра будут экземплярами класса.Перегруженная бинарная операция может возвращать величину любого типа.


*/
//в унарных операторах результат записывается в тот же самый объект, 
//для которого вызван оператор, поэтому унарный стоит отнести к методам класса.


/*
matrix & operator += (matrix & matr2) {
for (int i = 0; i < rows; i++) {
	for (int j = 0; j < columns; j++) {
		this->setElem(i, j, matr1[i][j] + matr2.getElem(i, j))
			return (*this);
	}
}
	}
*/

#include "pch.h"
#include <iostream>
#include "matr2.h"
using std::cin;
using std::cout;

int main()
{
	matrix A1, A2;
	A1.input();
	A2.input();
	A1 = A1 + A2;
	A1 = A1 - A2;
	A1 = A1 * A2;
	A1.print();

}

