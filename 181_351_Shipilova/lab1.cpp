/*Лабораторная №1 
Типы данных. Тиблица максимальных и минимальных значений типов данных. 
Bool - целочисленный логический тип даннных.
Char - символьный тип данных
int - целочисленный тип данных.
long и short - приставки с помощзью которых увеличивают или уменьшают количество занимаемой памяти. 
double - с плавающей точкой. в два раза больше чем float.
float - с плавающей точкой. 
*/
#include "pch.h"
/*#include "stdafx.h"*/
#include <limits.h>

#include <iostream>
using namespace std;

int main()
{
	cout << "a=300 b=560" << endl;
	long long int a = 300, b = 560;
	cout << "a*a*b*b=" << a * b*a*b << endl;

	char symbol_A = 'A';
	cout << "b/a =" << b / a << endl << "b%a = " << b % a << endl;

	cout << symbol_A + a << endl << "A" << a << endl;
	cout << "size of int = " << sizeof(int) << endl;

	int max_int = 0b01111111111111111111111111111111;
	cout << max_int << endl;

	int min_int = 0b10000000000000000000000000000000;
	cout << min_int << endl;

	//тип - размер - мин значение - макс значение

	cout << "name\t\t|size of|min\t\t\t|max\t\t\n";
	cout << "int\t\t|" << sizeof(int) << "\t|" << INT_MIN << "\t\t|" << INT_MAX << "\t\n";
	cout << "char\t\t|" << sizeof(char) << "\t|" << CHAR_MIN << "\t\t\t|" << CHAR_MAX << "\t\n";
	cout << "bool\t\t|" << sizeof(bool) << "\t|" << 0b0000000 << "\t\t\t|" << 0b100000000 << "\t\n";
	cout << "long\t\t|" << sizeof(long) << "\t|" << LONG_MIN << "\t\t|" << LONG_MAX << "\t\n";
	cout << "short\t\t|" << sizeof(short) << "\t|" << SHRT_MIN << "\t\t\t|" << SHRT_MAX << "\t\n";
	cout << "unsigned char\t|" << sizeof(unsigned char) << "\t|" << 0 << "\t\t\t|" << UCHAR_MAX << "\t\n";
	cout << "unsigned int\t|" << sizeof(unsigned int) << "\t|" << 0 << "\t\t\t|" << UINT_MAX << "\t\n";
	cout << "unsigned long\t|" << sizeof(unsigned long) << "\t|" << 0 << "\t\t\t|" << ULONG_MAX << "\t\n";
	cout << "float\t\t|" << sizeof(float) << "\t|" << FLT_MIN << "\t\t|" << FLT_MAX << "\t\n";
	cout << "double\t\t|" << sizeof(double) << "\t|" << DBL_MIN << "\t\t|" << DBL_MAX << "\t\n";
	cout << "long long\t|" << sizeof(long long) << "\t|" << LLONG_MIN << "\t|" << LLONG_MAX << "\t\n" << endl;
	/* точка входа
	// блок кода идет в {}. разделение строк ; .
	// main() - точка входа.
	// include - подключение сторонних библиотек.
	// вывод на консоль - cout. std - область видимости. в iostream есть часть библиотеки Std.
	//\n - знак переноса строки.
	// \t - табуляция. \\ - "\". \" - отображение "*/

	std::cout << "newline \n";
	std::cout << "\t horisontal tab \n";
	std::cout << "backspace.\b \n";
	std::cout << "carriage return\r \n";
	std::cout << "alert\a \n";
	std::cout << "backslash \\ \n";
	std::cout << "\' \n";
	std::cout << "\" \n";
	std::cout << "\? \n";
	std::cout << "form feed \f \n";
	std::cout << "vertical tab \v \n";

	std::cout << "ASCII \n";
	std::cout << "	\x00 \t \x13 \t \x27 \t \x3A \t \x4D \t \x60 \t \x73 \n ";
	std::cout << "	\x01 \t \x14 \t \x28 \t \x3B \t \x4E \t \x61 \t \x74 \n ";
	std::cout << "	\x02 \t \x15 \t \x29 \t \x3C \t \x4F \t \x62 \t \x75 \n ";
	std::cout << "	\x03 \t \x16 \t \x2A \t \x3D \t \x50 \t \x63 \t \x76 \n ";
	std::cout << "	\x04 \t \x17 \t \x2B \t \x3E \t \x51 \t \x64 \t \x77 \n ";
	std::cout << "	\x05 \t \x18 \t \x2C \t \x3F \t \x52 \t \x65 \t \x78 \n ";
	std::cout << "	\x06 \t \x19 \t \x2D \t \x40 \t \x53 \t \x66 \t \x79 \n ";
	std::cout << "	\x07 \t \x1A \t \x2E \t \x41 \t \x54 \t \x67 \t \x7A \n ";
	std::cout << "	\x08 \t \x1B \t \x2F \t \x42 \t \x55 \t \x68 \t \x7B \n ";
	std::cout << "	\x09 \t \x1C \t \x30 \t \x43 \t \x56 \t \x69 \t \x7C \n ";
	std::cout << "	\x0A \t \x1E \t \x31 \t \x44 \t \x57 \t \x6A \t \x7D \n ";
	std::cout << "	\x0B \t \x1F \t \x32 \t \x45 \t \x58 \t \x6B \t \x7E \n ";
	std::cout << "	\x0C \t \x20 \t \x33 \t \x46 \t \x59 \t \x6C \n ";
	std::cout << "	\x0D \t \x21 \t \x34 \t \x47 \t \x5A \t \x6D \n ";
	std::cout << "	\x0E \t \x22 \t \x35 \t \x48 \t \x5B \t \x6E \n ";
	std::cout << "	\x0F \t \x23 \t \x36 \t \x49 \t \x5C \t \x6F \n ";
	std::cout << "	\x10 \t \x24 \t \x37 \t \x4A \t \x5D \t \x70 \n ";
	std::cout << "	\x11 \t \x25 \t \x38 \t \x4B \t \x5E \t \x71 \n ";
	std::cout << "	\x12 \t \x26 \t \x39 \t \x4C \t \x5F \t \x72 \n "<< endl;
	
/* объявление переменных - указывается тип данных имя переменной:
Типы данных

целочисленный (логический) тип данных
bool (1 байт) 0/255

целочисленный (символьный) тип данных
char (1) 0 - 255. один символ в кодировке ASCII
signed char (1) -127 - 127
unsigned char (1) 0 - 255
wchar_t  расширенный символ w(2) 0 - 65 535  l(4) 0 - 4 294 967 295
char16_t символ в кодировке unicode  (2) 0 - 65 535
char32_t символ в кодировке unicode (4) 0 - 4 294 967 295

целочисленные типы данных
short int (по факту он же short, signed short int, signed short) (2) -32 768 - 32 767
unsigned short int (2) 0 - 65 535
int	(по факту он же signed int, signed) (4)	-2 147 483 648 - 2 147 483 647
unsigned int (4) 0 - 4 294 967 295
long int (4) -2 147 483 648 - 2 147 483 647
unsigned long int (4) 0 - 4 294 967 295
long long (8) −9 223 372 036 854 775 807 - 9 223 372 036 854 775 807
unsigned long long (8) 0 - 18 446 744 073 709 551 615

типы данных с плавающей точкой
float (4) -2 147 483 648.0 - 2 147 483 647.0
long float (8) -9 223 372 036 854 775 808 .0 - 9 223 372 036 854 775 807.0
double (8) -9 223 372 036 854 775 808 .0 - 9 223 372 036 854 775 807.0

void: тип без значения
*/
}

