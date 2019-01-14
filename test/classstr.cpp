#define _CRT_SECURE_NO_WARNINGS

#include "pch.h"
#include <iostream>
#include <string>
#include <cstring>
#include "classstr.h"


str::str()//�������.��������. ������� �����������
{
	std::cout << "������� ���������" << std::endl;
	std::string s1;
	getline(std::cin, s1);
	strok = new char[s1.length()+1];
	size = (s1.length()+1);
	for (int i = 0; i < size; i++)
	{
		strok[i] = s1[i];
	};
};
str::~str() // ����� ������ ������� ����������
{
	delete[]strok;
};
str::str(char* a) //�������. ��������. ����������� ���������� �� ������� �����
{
	size = strlen(a)+1;
	strok = new char[size];
	for (int i=0; i < size; i++)
	{
		strok[i] = a[i];
	};
};
str::str(const str &s1) //�������. ��������. ��� ���� ����� ������� ����������� ����������� ����� �������� ����� � ���������
{
	size = s1.size;
	strok = new char[size];
	for (int i = 0; i < size; i++)
	{
		strok[i] = s1.strok[i];
	};
};
str::str(std::string s1) //�������.��������. ����������� ���������� �� �++ ������
{
	size = s1.length() + 1;
	strok = new char[size];
	for (int i = 0; i < size; i++)
	{
		strok[i] = s1[i];
	};
	/*const char *copyC; //������� �������� � ��� ��� �_str �������� ������ � const_char *, � �� �� �������������� � �������� char* �� ������
	copyC = s1.c_str(); //��� ������� �� ���������� ��� ������ �� �������� �++
	strcpy(strok,copyC); // � ��� �� �������� �
	size = strlen(strok);*/
	};
int str::getsize() //�������.��������. ������� ������� �������
{
	return size;
};
void str::clear() // �������. ��������. �������� ����� ������
{
	char *newstrok = new char[0];
	size = 0;
	*newstrok = 0;
	delete[] strok;
	strok = newstrok;

};
void str::add(std::string s1) //������ ��������� ������ ����� ��� ������ �++ � ������ �� ������� � �����������
{
	int q = s1.length();
	char *newstrok = new char[size + q + 1]; // ������� ����� ������������ ������
	for (int i = 0; i < size-1; i++)// ������ ����� size-1
	{
		newstrok[i] = strok[i];
	}
	//strcpy(newstrok, strok); // �������� ���� �������� �������
	for (int i = size-1; i < size + q; i++)
	{
		newstrok[i] = s1[i - (size-1)];
	}
	size = size + q; // ������ �������� �������
	delete[]strok;
	strok = newstrok;
	};
void str::add(char*a) //�������.��������.
{
	int q =strlen(a);
	char *newstrok = new char[size + q + 1]; // ������� ����� ������������ ������
	for (int i = 0; i < size-1; i++)
	{
		newstrok[i] = strok[i];
	}
	//strcpy(newstrok, strok); // �������� ���� �������� �������
	for (int i = size-1; i < size + q; i++)
	{
		newstrok[i] = a[i - (size-1)];
	}
	size = size + q; // ������ �������� �������
	delete[]strok;
	strok = newstrok;
};
void str::insert(std::string s1) // ��������. ��������� ������ ������ � �������� ������� (� ���������) ������������������ �������� ��� ������ �++
// ��� �������� ���� �������� ��� ��������(����� ��� ������) � �� ����� �������
{
	std::cout << "������� ������" << std::endl;
	for (int i = 0; i < size-1; i++)//-1 � �������� ������� ����� � �������
	{
		std::cout  << " (" <<i <<") " << strok[i];
	};
	std::cout << std::endl;
	std::cout << "������� �������, � ������� �������� �������" << std::endl;
	LAZHA:
	int y = 0;
	std::cin >> y;
	if (y<0 || y>size)
	{
		std::cout << "������� ����� ������� ��� ���" << std::endl;
			goto LAZHA;
	}
	
	int q = s1.length(); // �������� ���������� ������ � ������ ������� ����� ���������
	/*char *bufer = new char[q + 1]; // ������� ������ ��� �������� ������
	const char *copyC; //����� �������� ������ � ������ �����
	copyC = s1.c_str();
	strcpy(bufer, copyC); // �������� ������ � ���� ������� �����*/
	char *newstrok = new char[size + q + 1]; // �������� ������ ��� ����� ������
	char *tail = new char[size-y]; //������� ������ ��� �����
	strcpy(newstrok, strok); // �������� ������
	for (int i = y; i < size; i++) //�������� �����
	{
		tail[i - y] = newstrok[i];
	}
	for (int i = y; i < q + 2; i++) // 1 �� �������������� �������� ������ ������� ��������� ��� � ����� ������
	{
		newstrok[i] = s1[i - y];
	}	
	size = size + q;// ������ ������ �� �����
	for (int i = y+q; i < size; i++) // ����������� �����
	{
		newstrok[i] = tail[i - y-q];
	}
	delete[] strok;
	strok = newstrok;
	
};
//������ ���� ������ �� ������ ������ �� ��������� ���������� ������ 
//��� ��� ������� ������ ���� �������� �� ������ ������. �� ���� ������� �� ���������� � ��������� ������
// ������ ���� ��� ������� ������� ��� ��� �������
// ������ ���� ���������� + � ������� �� ������� << 
//������ ��� ���������� � ������������
void str::find() //������������ ����� ������������������ ����� ��� ������ �++ � ������ ������
{
};
void str::save() //���������� � ����
{
};
void str::load() //������ �� �����
{
};
void str::test() // �������. ��������. ����� �� ������
{ 
	std::cout << "������� ������ ������" << std::endl;
	std::cout << size-1 << std::endl;
	std::cout << "������� ������" << std::endl;
		for (int i = 0; i < size; i++)
		{
			std::cout << strok[i];
		};
		std::cout << std::endl;
};