/*если метод не большой можно писать прямо в классе
синтаксис объявления объекта
имя_класса объект1;
объект1.свойство1 = 1;
объект1.метод1 ();
ПРИМЕР:
vehicle car;
car.speed = 123;
car.chckreg ();
Класс получается как переменные. сложный тип состоит из полей.
некоторым полям класса можно закрывать доступ
к полям public можно обращаться везде(из методов класса и снаружи
где виден объект)
к полям private нельзя.
КЛАССЫ
Свойство - переменная в составе класса
Метод - функция в составе класса
Полиморфизм: экземпляры одного класса ведут
себя по разному
КОНСТРУКТОРЫ И ДЕСТРУКТОРЫ
СТРУКТУРА ДАННЫХ
 в классе есть приватность, а в структуре нет*/


#include "pch.h"
 //#include "stdafx.h"
#include <iostream>
using namespace std;

class Vehicle
{
private:
public:
	double speed;
	char regnumber[6] = { 0 };
	unsigned char capacity;

	bool check_reg_num()
	{
		for (int i = 0; i < 6; i++)
		{
			if (regnumber[i] != 0)
			{
				return true;

			}

		}
		return false;

	}



};
class user_data
{
private:
	char first_name[255];
	char second_name[255];
	char str_passport[11];
	char str_date[11];

public:
	user_data();
	user_data(char p_f_name[255], char p_second_name[255], char p_str_passport[10], char p_str_birthdate[10]);
	user_data(char p_f_name[255], char p_second_name[255]);
	~user_data

	bool set_first_name(char p_first_name[10]) //нужна проверка на знаки (можно только -)
	{
		for (int i = 0; i < 10; i++)
		{
			while (p_first_name[i] != '\0')
			{
				if ((p_first_name[i] >= 97 && p_first_name[i] <= 122) || (p_first_name[i] == '-'))
				{
					first_name[i] = p_first_name[i];
				}
				else
				{
					return false;
				}
				i++;
			}
			return true;
		}
	};

	bool set_second_name(char p_second_name[10])
	{
		for (int i = 0; i < 10; i++)
		{
			while (p_second_name[i] != '\0')
			{
				if ((p_second_name[i] >= 97 && p_second_name[i] <= 122) || (p_second_name[i] == '-'))
				{
					second_name[i] = p_second_name[i];
				}
				else
				{
					return false;
				}
				i++;
			}
			return true;
		}
	};

	bool set_date(char p_date[10]) // должно соответствовать формату 00.00.0000
	{
		if (p_date[2] == 46 && p_date[5] == 46)
		{
			for (int j = 0; j < 10; j++)
			{
				if (str_date[j] > 48 && str_date[j] < 57)
				{
					str_date[j] = p_date[j];
				}
				else
				{
					return false;
				};

				if (j == 2 || j == 5)
				{
					str_date[j] = '.'; j++;
				}
			}
		}
		else
		{
			return false;
		};
		return true;
	};

	bool set_passport(char p_passport[10]) // только цифры без разделения
	{
		for (int i = 0; i < 10; i++)
			if (p_passport[i] > 48 && p_passport[i] < 57)
			{
				str_passport[i] = p_passport[i];
			}
			else
			{
				return false;
			}
		return true;
	};


};


//user_data(); конструктор
//~user_data(); деструктор
// массивы нельзя присваивать. конструкторы деструкторы прописываются вне main и вне класса

int main()
{
	user_data birth;
	char birth_array[11] = "19.04.1998";
	if (birth.set_date(birth_array)) {
		std::cout << "False";
	}
	else {
		std::cout << "Good";
	}
}
}

user_data::user_data()
{

};

user_data::user_data(char p_first_name[255], char p_second_name[255], char p_str_passport[10], char p_str_birthdate[10])
{
	set_first_name(p_first_name);
	set_second_name(p_second_name);
	set_passport(p_str_passport);
	set_date(p_str_date);
	if (first_name != (char*)' '&& second_name != (char*) ' '&& str_passport != (char*)' '&& str_date != (char*) ' ')
		std::cout << "norm\n";

};

user_data::user_data(char p_first_name[255], char p_second_name[255])
{
	set_first_name(p_first_name);
	set_second_name(p_second_name);
	if (first_name != (char*)' '&& second_name != (char*) ' ')
		std::cout << "norm\n";
};
user_data::~user_data()
{

};
