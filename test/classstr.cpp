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
	const char *copyC;
	copyC = s1.c_str(); 
	strcpy(strok, copyC); 
	size = strlen(strok);
};
str::~str() // ����� ������ ������� ����������
{
	delete[]strok;
};
str::str(char* a) //�������. ��������. ���� �������. ����������� ���������� �� ������� �����
{
	int q = strlen(a);
	strok = new char[q+1];
	strcpy(strok, a);
	/*int q = strlen(a); //������-�� �� �������� ������ ������ ��� ����. ��, ������ ��������� ��������� ���������� ������� ����������
	strok = new char[q]; //�� � ���������� ���� ���� ���������� �����. 
	std::ZeroMemory();
	for (int i=0; i < q; i++)
	{
		strok[i] = a[i];
	};*/
	size = strlen(strok);
};
str::str(const str &s1) //�������. ��������. ���� �������. ��� ���� ����� ������� ����������� ����������� ����� �������� ����� � ���������
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
	strok = new char[s1.length()+1];
	const char *copyC; //������� �������� � ��� ��� �_str �������� ������ � const_char *, � �� �� �������������� � �������� char* �� ������
	copyC = s1.c_str(); //��� ������� �� ���������� ��� ������ �� �������� �++
	strcpy(strok,copyC); // � ��� �� �������� �
	size = strlen(strok);
	};
int str::getsize() //�������.��������. ������� ������� �������
{
	return size;
};
void str::clear() // �������� ��������. �������� ����� ������
{
	int q = getsize();
	for (int i=0; i < q; i++)
	{
		strok[i] = 0;
	};
	
};
void str::add(std::string s1) //������ ��������� ������ ����� ��� ������ �++ � ������ �� ������� � �����������
{
	int q = s1.length();
	char *newstrok = new char[size +q+1]; // ������� ����� ������������ ������
	strcpy(newstrok, strok); // �������� ���� �������� �������
	delete[] strok; // ������� ������. �������� ����� �� ����� ������. ������ ���� � ���, ��� �� ������ �������� ������ ��� ������� ������ ��������� ������. ������� ���������, ��� ����. 
	const char *copyC; // ������ ����� ��� ����������� ������
	copyC = s1.c_str(); 
	char *a = new char[q]; 
	strcpy(a, copyC);
	strcat(newstrok, a);
	/*for (int i = size + 1; i <= size + q; i++)
	{
		newstrok[i] = a[i - (size + 1)];
	}//��������� � ����� ������ �������� ������*/
	size = size+q; // ������ �������� �������
	strok = newstrok;
	
};
void str::add(char*a) //�������.��������.
{
	int q =strlen(a);
	char *newstrok = new char[size + q + 1]; // ������� ����� ������������ ������
	strcpy(newstrok, strok); // �������� ���� �������� �������
	delete[]strok;
	strcat(newstrok, a);
	size = size + q; // ������ �������� �������
	strok = newstrok;
};
void str::insert(std::string s1) // ��������� ������ ������ � �������� ������� (� ���������) ������������������ �������� ��� ������ �++
{
	std::cout << "������� ������" << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << strok[i] << " (" <<i <<") ";
	};
	std::cout << std::endl;
	std::cout << "������� �������, � ������� �������� �������" << std::endl;
	LAZHA:
	int n = 0;
	std::cin >> n;
	if (n<0 || n>size)
	{
		std::cout << "���� ����� ��, ������� ����� ������� ��� ���" << std::endl;
			goto LAZHA;
	}
	int q = s1.length(); // �������� ���������� ������ � ������ ������� ����� ���������
	char *bufer = new char[q + 1]; // ������� ������ ��� �������� ������
	const char *copyC; //����� �������� ������ � ������ �����
	copyC = s1.c_str();
	strcpy(bufer, copyC); // �������� ������ � ���� ������� �����
	char *newstrok = new char[size + q + 1]; // �������� ������ ��� ����� ������
	char *tail = new char[size - n]; //������� ������ ��� �����
	size = size + q + 1; //������ ������ �� �����
	strcpy(newstrok, strok); // �������� ������
	for (int i = n; i < q + 1; i++) //�������� ����� 
	{
		tail[i - n] = newstrok[i];
	}
	for (int i = n; i < q + 1; i++) // �������� ������ ������� ��������� ��� � ����� ������
	{
		newstrok[i] = bufer[i - n];
	}	
	for (int i = n+q; i <= size; i++) // ����������� �����
	{
		newstrok[i] = tail[i - n-q];
	}
	//strcat(newstrok, tail); // ��������� 
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
	std::cout << size<< std::endl;
	std::cout << "������� ������" << std::endl;
		for (int i = 0; i < size; i++)
		{
			std::cout << strok[i];
		};
		std::cout << std::endl;
};