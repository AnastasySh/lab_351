#define _CRT_SECURE_NO_WARNINGS

#include "pch.h"
#include <iostream>
#include <string>
#include <cstring>
#include "classstr.h"


str::str()//СДЕЛАНО.РАБОТАЕТ. нулевой конструктор
{
	std::cout << "введите выражение" << std::endl;
	std::string s1;
	getline(std::cin, s1);
	strok = new char[s1.length()+1];
	const char *copyC;
	copyC = s1.c_str(); 
	strcpy(strok, copyC); 
	size = strlen(strok);
};
str::~str() // вроде сделан нулевой деструктор
{
	delete[]strok;
};
str::str(char* a) //СДЕЛАНО. РАБОТАЕТ. ЕСТЬ ВОПРОСЫ. конструктор копирующий из массива чаров
{
	int q = strlen(a);
	strok = new char[q+1];
	strcpy(strok, a);
	/*int q = strlen(a); //почему-то он выделяет больше памяти чем надо. да, первые несколько элементов забиваются нужными значениями
	strok = new char[q]; //но в дальнейшем идут тупа непонятные знаки. 
	std::ZeroMemory();
	for (int i=0; i < q; i++)
	{
		strok[i] = a[i];
	};*/
	size = strlen(strok);
};
str::str(const str &s1) //СДЕЛАНО. РАБОТАЕТ. ЕСТЬ ВОПРОСЫ. для того чтобы сделать конструктор копирования нужно написать конст и амперсант
{
	size = s1.size;
	strok = new char[size];
	for (int i = 0; i < size; i++)
	{
		strok[i] = s1.strok[i];
	};
};
str::str(std::string s1) //СДЕЛАНО.РАБОТАЕТ. конструктор копирующий из с++ строки
{
	strok = new char[s1.length()+1];
	const char *copyC; //великая проблема в том что с_str копирует только в const_char *, а он не приравнивается в обычному char* на прямую
	copyC = s1.c_str(); //эта бандура из библиотеки для работы со строками с++
	strcpy(strok,copyC); // а это со строками С
	size = strlen(strok);
	};
int str::getsize() //СДЕЛАНО.РАБОТАЕТ. возврат размера массива
{
	return size;
};
void str::clear() // СДЕЛАНОю РАБОТАЕТ. очищение нашей строки
{
	int q = getsize();
	for (int i=0; i < q; i++)
	{
		strok[i] = 0;
	};
	
};
void str::add(std::string s1) //должно принимать массив чаров или строку с++ и делать их склейку с изначальной
{
	int q = s1.length();
	char *newstrok = new char[size +q+1]; // создаем новый динамический массив
	strcpy(newstrok, strok); // копируем туда значение старого
	delete[] strok; // удаляем старый. вылетает какая то лютая ошибка. ошибка была в том, что мы забыли выделить память под нулевой символ окончания строки. костыли построены, все норм. 
	const char *copyC; // делаем магию для копирования строки
	copyC = s1.c_str(); 
	char *a = new char[q]; 
	strcpy(a, copyC);
	strcat(newstrok, a);
	/*for (int i = size + 1; i <= size + q; i++)
	{
		newstrok[i] = a[i - (size + 1)];
	}//добавляем в новый массив значение строки*/
	size = size+q; // меняем значение размера
	strok = newstrok;
	
};
void str::add(char*a) //СДЕЛАНО.РАБОТАЕТ.
{
	int q =strlen(a);
	char *newstrok = new char[size + q + 1]; // создаем новый динамический массив
	strcpy(newstrok, strok); // копируем туда значение старого
	delete[]strok;
	strcat(newstrok, a);
	size = size + q; // меняем значение размера
	strok = newstrok;
};
void str::insert(std::string s1) // вставляет внутри строки в заданную позицию (в параметре) последовательность символов или строку с++
{
	std::cout << "текущая строка" << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << strok[i] << " (" <<i <<") ";
	};
	std::cout << std::endl;
	std::cout << "введите позицию, с которой начнется вставка" << std::endl;
	LAZHA:
	int n = 0;
	std::cin >> n;
	if (n<0 || n>size)
	{
		std::cout << "лажа какая то, введите номер позиции еще раз" << std::endl;
			goto LAZHA;
	}
	int q = s1.length(); // выясняем количество знаков в строке которую будем добавлять
	char *bufer = new char[q + 1]; // создаем массив для перегона строки
	const char *copyC; //магия перевода строки в массив чаров
	copyC = s1.c_str();
	strcpy(bufer, copyC); // приводим строку к виду массива чаров
	char *newstrok = new char[size + q + 1]; // выделяем память под новую строку
	char *tail = new char[size - n]; //создаем массив под хвост
	size = size + q + 1; //меняем размер на новый
	strcpy(newstrok, strok); // копитуем старое
	for (int i = n; i < q + 1; i++) //копируем хвост 
	{
		tail[i - n] = newstrok[i];
	}
	for (int i = n; i < q + 1; i++) // копируем строку которую впихиваем уже в новую строку
	{
		newstrok[i] = bufer[i - n];
	}	
	for (int i = n+q; i <= size; i++) // приклеиваем хвост
	{
		newstrok[i] = tail[i - n-q];
	}
	//strcat(newstrok, tail); // склеиваем 
	delete[] strok;
	strok = newstrok;
};
//должна быть защита от чтения записи за пределами выделенной памяти 
//все это счастье должно быть защищено от утечки памяти. то есть следить за выделением и удалением памяти
// должен быть код который красиво все это покажет
// должны быть перегрузки + и ввывода на консоль << 
//методы для шифрования и дешифрования
void str::find() //осуществляет поиск последовательности чаров или строки с++ в строке класса
{
};
void str::save() //сохранение в фаил
{
};
void str::load() //чтение из файла
{
};
void str::test() // СДЕЛАНО. РАБОТАЕТ. вывод на печать
{ 
	std::cout << "текущий размер строки" << std::endl;
	std::cout << size<< std::endl;
	std::cout << "текущая строка" << std::endl;
		for (int i = 0; i < size; i++)
		{
			std::cout << strok[i];
		};
		std::cout << std::endl;
};