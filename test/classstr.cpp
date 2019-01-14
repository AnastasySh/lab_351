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
	size = (s1.length()+1);
	for (int i = 0; i < size; i++)
	{
		strok[i] = s1[i];
	};
};
str::~str() // вроде сделан нулевой деструктор
{
	delete[]strok;
};
str::str(char* a) //СДЕЛАНО. РАБОТАЕТ. конструктор копирующий из массива чаров
{
	size = strlen(a)+1;
	strok = new char[size];
	for (int i=0; i < size; i++)
	{
		strok[i] = a[i];
	};
};
str::str(const str &s1) //СДЕЛАНО. РАБОТАЕТ. для того чтобы сделать конструктор копирования нужно написать конст и амперсант
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
	size = s1.length() + 1;
	strok = new char[size];
	for (int i = 0; i < size; i++)
	{
		strok[i] = s1[i];
	};
	/*const char *copyC; //великая проблема в том что с_str копирует только в const_char *, а он не приравнивается в обычному char* на прямую
	copyC = s1.c_str(); //эта бандура из библиотеки для работы со строками с++
	strcpy(strok,copyC); // а это со строками С
	size = strlen(strok);*/
	};
int str::getsize() //СДЕЛАНО.РАБОТАЕТ. возврат размера массива
{
	return size;
};
void str::clear() // СДЕЛАНО. РАБОТАЕТ. очищение нашей строки
{
	char *newstrok = new char[0];
	size = 0;
	*newstrok = 0;
	delete[] strok;
	strok = newstrok;

};
void str::add(std::string s1) //должно принимать массив чаров или строку с++ и делать их склейку с изначальной
{
	int q = s1.length();
	char *newstrok = new char[size + q + 1]; // создаем новый динамический массив
	for (int i = 0; i < size-1; i++)// скорее всего size-1
	{
		newstrok[i] = strok[i];
	}
	//strcpy(newstrok, strok); // копируем туда значение старого
	for (int i = size-1; i < size + q; i++)
	{
		newstrok[i] = s1[i - (size-1)];
	}
	size = size + q; // меняем значение размера
	delete[]strok;
	strok = newstrok;
	};
void str::add(char*a) //СДЕЛАНО.РАБОТАЕТ.
{
	int q =strlen(a);
	char *newstrok = new char[size + q + 1]; // создаем новый динамический массив
	for (int i = 0; i < size-1; i++)
	{
		newstrok[i] = strok[i];
	}
	//strcpy(newstrok, strok); // копируем туда значение старого
	for (int i = size-1; i < size + q; i++)
	{
		newstrok[i] = a[i - (size-1)];
	}
	size = size + q; // меняем значение размера
	delete[]strok;
	strok = newstrok;
};
void str::insert(std::string s1) // ДОДЕЛАТЬ. вставляет внутри строки в заданную позицию (в параметре) последовательность символов или строку с++
// уже передать куда вставить что вставить(какой оно длинны) и на какую позицию
{
	std::cout << "текущая строка" << std::endl;
	for (int i = 0; i < size-1; i++)//-1 и поменять местами номер и элемент
	{
		std::cout  << " (" <<i <<") " << strok[i];
	};
	std::cout << std::endl;
	std::cout << "введите позицию, с которой начнется вставка" << std::endl;
	LAZHA:
	int y = 0;
	std::cin >> y;
	if (y<0 || y>size)
	{
		std::cout << "введите номер позиции еще раз" << std::endl;
			goto LAZHA;
	}
	
	int q = s1.length(); // выясняем количество знаков в строке которую будем добавлять
	/*char *bufer = new char[q + 1]; // создаем массив для перегона строки
	const char *copyC; //магия перевода строки в массив чаров
	copyC = s1.c_str();
	strcpy(bufer, copyC); // приводим строку к виду массива чаров*/
	char *newstrok = new char[size + q + 1]; // выделяем память под новую строку
	char *tail = new char[size-y]; //создаем массив под хвост
	strcpy(newstrok, strok); // копитуем старое
	for (int i = y; i < size; i++) //копируем хвост
	{
		tail[i - y] = newstrok[i];
	}
	for (int i = y; i < q + 2; i++) // 1 не докопировалась копируем строку которую впихиваем уже в новую строку
	{
		newstrok[i] = s1[i - y];
	}	
	size = size + q;// меняем размер на новый
	for (int i = y+q; i < size; i++) // приклеиваем хвост
	{
		newstrok[i] = tail[i - y-q];
	}
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
	std::cout << size-1 << std::endl;
	std::cout << "текущая строка" << std::endl;
		for (int i = 0; i < size; i++)
		{
			std::cout << strok[i];
		};
		std::cout << std::endl;
};