﻿#include "pch.h"
#include <iostream>


#include <stack> // подключаем библиотеку для использования стека 
#include <queue> // подключили библиотеку для использования очереди 
#include <deque> // подключили библиотеку для использования дека 
#include <string> 
#include <list> // подключили библиотеку для использования списка
#include <set> // подключили библиотеку для использования множества
#include <map> // подключили библиотеку для использования ассоциативного массива

using std::cout;
using std::endl;
using std::cin;
using std::list;
using std::set;
using std::stack;
using std::queue;
using std::deque;
using std::string;



/*
	Стек — это структура данных, которая работает
	по принципу FILO(first in — last out; первый пришел — последний ушел).

	В стеке нет индексов,т.е. нельзя обратиться к определенному элементу.
	Каждый элемент имеет указатель на следующий элемент.
	Головной элемент указывает на NULL.

	Достоинство: операции удаления и добавления элемента делаются за const время.

	

std::stack<int> stackInt;//stack <тип данных> <имя>; -создание стека 
int i = 0, a = 0;
std::cout « "Введите 5 целых чисел: " « std::endl;
while (i != 5) {
	std::cin » a;
	stackInt.push(a); // добавляем введенное число 
	i++;
}

if (stackInt.empty()) // проверяем пуст ли стек (нет) 
std::cout « "Стек не пуст";

std::cout « "Верхний элемент стека: " « stackInt.top() « std::endl;
stackInt.pop(); // удаляем верхний элемент 

std::cout « "Новый верхний элемент: " « stackInt.top()« std::endl;*/
/*
	Очередь — это структура данных, которая построена по принципу
	LILO (last in — last out: последним пришел — последним вышел).
	*/

	/*std::queue <int> MyQueue; // создали очередь
	std::cout « "Введите 7 чисел: " « std::endl;
	for (i = 0; i < 7; i++) {
		std::cin » a;
		MyQueue.push(a); // добавляем в очередь элементы
	}
	std::cout « std::endl;
	std::cout « "Первый элемент в очереди: " « MyQueue.front() « std::endl;
	MyQueue.pop(); // удаляем элемент из очереди
	std::cout « "Первый элемент (после удаления): " « MyQueue.front() « std::endl;

	if (!MyQueue.empty()) // проверяем пуста ли очередь (нет)
		std::cout « "Очередь не пуста!";
	/*
	Очередь с приоритетом (priority_queue) — это обычная очередь,
	но в ней новый элемент добавляется в такое место,
	чтобы очередь была отсортирована по убыванию.
	*/

	/*	std::priority_queue <int> priority_q; // объявляем приоритетную очередь

		std::cout « "Введите 7 чисел: " « std::endl;
		for (i = 0; i < 7; i++) {
			std::cin » a;
			priority_q.push(a); // добавляем элементы в очередь
			std::copy(MyQueue.front(), MyQueue.back(), std::ostream_iterator<int>(cout, " "));
		}
		// выводим первый
		std::cout « "Первый элемент очереди: " « priority_q.top();
		queue*/

int main()
{
	setlocale(LC_ALL, "rus");
	{ stack <int> stack1;
	string s1;
	int i = 0;
	cout << "введите выражение" << endl;
	cin >> s1;
	while (s1[i] != '\0')
	{
		if (s1[i] == '(' || s1[i] == '{' || s1[i] == '[')
		{
			stack1.push(s1[i]);
		}
		if (((s1[i] == ')') && (stack1.top() == '(')) || ((s1[i] == '}') && (stack1.top() == '{')) || ((s1[i] == ']') && (stack1.top() == ']')))
		{
			stack1.pop();
		}
		i++;
	};
	if (stack1.empty() == true)
	{
		cout << "скобки расставлены  правильно";
	}
	else
	{
		cout << "скобки расставлены не правильно";

	}
	}

	{
		queue <string> nine;
		queue <string> ten;
		queue <string> eleven;
		int n = 0;
		int sizenine = 0;
		int sizeten = 0;
		int sizeeleven = 0;
		string s2;
		cout << "введите количество учеников" << endl;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cout << i + 1 << "ученик" << endl;
			s2.clear();
			cin.clear(); // походу с помощью этого костыля можно вытащить один единственный символ перевода строки. get
			//боже, эта бандура реально сработала. все дело было в переводе строки. однако на печать оно выводится отвратительно. 
			getline(cin, s2);  //cin >> s2; при таком варианте эта бандура не берет пробелы
			//эта бандура теперь работает прям как я. то есть хреново и через раз. говорят нельзя смешивать getline и >> 
			//надо вернуться к этому позже
			// возможно проблема в неизвлеченном символе перевода строки. 
			//
			if (s2[0] == '1')
			{
				if (s2[1] == '0')
				{
					ten.push(s2);
					sizeten++;
					
				}
				else
				{
					eleven.push(s2);
					sizeeleven++;
					
				}
			}
			if (s2[0] == '9')
			{
				nine.push(s2);
				sizenine++;
				
			}
		}

		cout << "9 класс" << endl;
		for (int j = 0; j < sizenine; j++)
		{
			cout << nine.front() << endl;
			nine.push(nine.front());
			nine.pop();
		};
		cout << "10 класс" << endl;
		for (int j = 0; j < sizeten; j++)
		{
			cout << ten.front() << endl;
			ten.push(ten.front());
			ten.pop();
		};
		cout << "11 класс" << endl;
		for (int j = 0; j < sizeeleven; j++)
		{
			cout << eleven.front() << endl;
			eleven.push(eleven.front());
			eleven.pop();
		};
	}
}

	/*Деком (англ. deque – аббревиатура от double-ended queue, двухсторонняя очередь)
	называется структура данных, в которую можно
	удалять и добавлять элементы 
как в начало, так и в конец. 

Дек хранится в памяти так же, как и очередь. 
*/ 

//ЗАДАЧА 3 
/*
Проверить, является ли введенная строка палиндромом
(читается одинаково слева направо и справа налево). Использовать дек.
*/

/*

Считываем строку посимвольно. каждый символ добавляем в хвост дека.
Далее сравниваем первый и последний символ дека.
*/

//ЗАДАЧА 4 
/*
Описать структуру данных List.
Продемонстрировать работу с этой структурой:
ввод, вывод,
добавление элемента и удаление,
сортировка.
*/

//ЗАДАЧА 5 
/*
Описать структуру данных Set.
Продемонстрировать работу с этой структурой:
ввод, вывод,
добавление элемента и удаление.
*/

//ЗАДАЧА 6 
/*
Описать структуру данных map.

варь (он же ассоциативный массив) — это тот-же вектор, но с небольшими отличиями. 
В качестве индекса (который в словаре будет называться ключ) могут выступать не только числа, 
и любые другие типы данных (даже другие коллекции!). Также допустимы пропуски, если мы все-таки будем использовать
в качестве ключа целое число, например у нас может быть элемент связанный с ключем 5, но при этом отсутствовать 
элемент связанный с ключем 4.

Что все это значит на практике? Всего-лишь, то, что в квадратных скобках для ображения к элементу по 
“индексу” мы можем указывать произвольный тип, например allMyCats[“Murka”].

вектор

Вектор в C++ — это замена стандартному динамическому массиву (Динамический массив 
— это такой массив, который может и расширать и сужать свою фактическую вместимость.
Обычный массив всегда имеет фиксированную вместимость, изменить которую по ходу программы нельзя),
память для которого выделяется вручную, с помощью оператора new. Разработчики языка рекомендуют 
в использовать именно vector вместо ручного выделения памяти для массива. Это позволяет избежать утечек
памяти и облегчает работу программисту.
Для добавления нового элемента в конец вектора используется метод push_back(). 
Количество элементов определяется методом size(). Для доступа к элементам вектора можно использовать квадратные скобки [], т
акже, как и для обычных массивов.
pop_back() — удалить последний элемент
clear() — удалить все элементы вектора
empty() — проверить вектор на пустоту

Вектор можно объявить следующим образом:
std::vector<int> myVector; // мы создали пустой вектор типа int
myVector.reserve(10);      // тут мы зарезервировали память под 10 элементов типа int

Как видно из примера, вектора относятся к пространству имен std. По сути, эти две записи эквивалентны такой записи:
int myVector[10]; // обычное объявление массива

На первый взгляд, объявление вектора оказалось намного более громоздкое. Однако вектора скрывают очень мощный функционал, чего нельзя сказать об обычных массивах С++. Кроме того, вектор можно объявить и в одной строке, вот так:
std::vector<int> myVector(10);
Применение:

Лист
Мы уже знаем, что элементы вектора лежат акуратненько друг за другом, красиво и ровно.
Это дает нам как преимущества так и недостатки.

Список в этом плане полностью противоположная вещь — его элементы могут быть разбросаны по памяти как угодно.
Из-за этого мы теряем возможность быстро получить элемент по индексу, а также не можем быстро скопировать весь список, 
но получаем довольно приятную штуку — мы можем вставлять элементы за константное время в любое место.

Каждый элемент списка list, за исключением первого и последнего, связан с предшествующим и последующим элементом,
благодаря чему такой список можно проходить в двух направлениях : слева - направо и справа - налево.Принципиальное
различие между list и vector заключается в том, что list обеспечивает вставку и удаление за постоянное время в любой позиции списка.
Правда, непосредственно вставку в середину списка мы сделать не можем
Дело в том, что чтобы вставить элемент в середину списка, нужно до этой середины дойти. Список не обладает произвольными итераторами,
а те итераторы, которыми он обладает, не поддерживают операций + и —. Т. е. нельзя написать l1.begin + 1;, только потому что итераторы
у списка двунаправленные. Зато можно установить независимый итератор на любую позицию списка и уже используя его вставлять элемент.

*/

// ЗАДАЧА 7 
/*
Составить таблицу сравнения по времени выполнения операций
для дека, стека, очереди, списка, множества, массива из n элементов.
Список операций:
добавление в начало
добавление в конец
добавление в середину
удаление из начала
удаление с конца
удаление из середины
значение элемента из начала
значение элемента с конца
значение элемента из середины

system("pause");
return 0;
}*/