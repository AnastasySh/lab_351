// lab5classcpp.cpp: определяет точку входа для консольного приложения.
//
/*если метод не большой можно писать прямо в классе*/
/*синтаксис объявления объекта
имя_класса объект1;
объект1.свойство1 = 1;
объект1.метод1 ();
ПРИМЕР:
vehicle car;
car.speed = 123;
car.chckreg ();
Класс получается как переменные. сложный тип состоит из полей.*/

/*некоторым полям класса можно закрывать доступ
к полям public можно обращаться везде(из методов класса и снаружи
где виден объект)
к полям private нельзя */
/*Классы
Свойство - переменная в составе класса
Метод - функция в составе класса
Полиморфизм: экземпляры одного класса ведут
себя по разному
*/
/*конструкторы и деструкторы
когда пишется вне класса 
*/
/*структура данных. в классе есть приватность, а в структуре нет*/
#include "stdafx.h"
#include <iostream>
using namespace std;
/*struct student
{
	unsigned int 
	unsigned int
};*/
class user_data
{
private:
	char first_name[255];
	char second_name[255];
	char str_passport[11];
	char str_date[11];

public:
	user_data::user_data()
	{
	}
	user_data::~user_data()
	{
	}
	user_data::user_data(char p_first_name[255], char p_second_name[255], char p_str_passport[11], char p_str_date[11])
	{
	}

	bool set_first_name(char p_first_name[10]) //нужна проверка на знаки (можно только -)
	{
	//set вроде как должна задавать значение
		for (int i = 0; i < 10; i++)
			if (first_name[i] >= 65 && first_name[i] <= 90 ||
				first_name[i] >= 97 && first_name[i] <= 122)
			{
				cout << "correct" << endl;
			};
		return false;
	};

	bool set_second_name(char p_second_name[10])
	{
		for (int i = 0; i < 10; i++)
			if (second_name[i] >= 65 && second_name[i] <= 90 ||
				second_name[i] >= 97 && second_name[i] <= 122)
			{
				cout << "correct" << endl;
			};
		
		return false;
		};
	
	bool set_date(char p_date[10])
		// должно соответствовать формату 00.00.0000
	{
		for (int j = 0; j < 10; j++)
		{
			if (str_date[2] != 46 || str_date[5] != 46) /*в итоге он выдает кучу ошибок об отсутствии(?) точек*/
			{
				cout << "error t" << endl;
			};
			if (str_date[j] < 48 && str_date[j] > 57)
			{
				cout << "error" << endl;
			};
		};
		return true;
	};
	bool set_passport(char p_pasport[10])
		// только цифры без разделения
	{
		for (int i = 0; i < 10; i++)
			if (str_passport[i] < 48 && str_passport[i] > 57)
			{
				return false;
			};

		return true;
	};
};

class vehicle
{
private: /*спецификаторы доступа. можно получить доступ из main*/
public: /*из main до этого спецификатора не добраться*/
	double speed;
	char regnum[6] = { 0 };
	unsigned char capacity;
	bool chckreg() {};
	
};
//user_data(); конструктор
//~user_data(); деструктор
// массивы нельзя присваивать. конструкторы деструкторы прописываются вне main и вне класса

user_data::user_data(char p_first_name[255], char p_second_name[255], char p_str_passport[11], char p_str_date[11])
{ //first_name=p_name
	/*чет там вызывается через set*/
};
int main()
{
	/*user_data user1, user2 ("ivanov", "ivan", "1234567891", "11.11.1111")*/
	
	/*user_data ash;
	char str_date[11] = "00.00.0000";
	char str_passport[11] = "1234567891";
	char first_name[255] = "anastasy";
	char second_name[255] = "shipilova";

	ash.set_second_name(first_name);
	ash.set_first_name(second_name);
	ash.set_passport(str_passport);
	ash.set_date(str_date);*/
		
	
	return 0;
}

