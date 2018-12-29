// lab16_mytipe.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "pch.h"
#include <iostream> 
using std::cin;
using std::cout;
using std::endl;
int * get(int & size)
{
	cout << "size" << endl;
	cin >> size;
	int *p = new int[size];
	for (int i = 0; i < size; i++)
	{
		cin >> p[i];
	}
	return p;
};
void print(int size, int *p)
{
	for (int i = 0; i < size; i++)
	{
		cout << p[i] << " ";
	}
};
int find(int size, int *p)
{
	int pmax = *p;
	for (int i = 0; i < size; i++)
	{

		if (p[i] > pmax)
		{
			pmax = p[i];
		}
	}
	return pmax;
}
/*mytype ля шаблонов функции. сигнальное слово template <typename MyType, class TT>*/
/*double find2(int *p, int size)
{
int * pmax = p;
for (p != p + size; p++;)
{
if (*p > *pmax)
{
pmax = p;
}
}
return *pmax;
}*/
int main()
{
	int size;
	int *p;
	int res;
	p = get(size);
	res = find(size, p);
	cout << "max element " << res << "\n";
	print(size, p);
	system("pause");
}
/*
#include <iostream>

template <typename MyType>
MyType myFunc(MyType * arr, int size) {
MyType res = arr[0];
for (int iter = 0; iter < size; iter++) {
if (res < arr[iter])
res = arr[iter];
}
return res;
}

/*
double myFunc(double * arr, int size) {
double res = arr[0];
for (int iter = 0; iter < size;iter++) {
if (res < arr[iter])
res = arr[iter];
}
return res;
}


int myFunc(int * arr, int size) {
int res = arr[0];
for (int iter = 0; iter < size; iter++) {
if (res < arr[iter])
res = arr[iter];
}
return res;
}

char myFunc(char * arr, int size) {
char res = arr[0];
for (int iter = 0; iter < size; iter++) {
if (res < arr[iter])
res = arr[iter];
}
return res;
}


template<typename TT>
class myList {
public:
TT element;
myList * prev;
myList * next;
myList();
myList(TT el);

myList<TT> next_elem() {
return next;
}
void print();
void push_back(TT new_elem);
};


int main() {
/* int * arrI, sizeI = 5, sizeCh = 5, sizeD = 5;
char * arrCh;
double * arrD;

arrI = new int[sizeI];
arrCh = new char[sizeCh];
arrD = new double[sizeD];

std::cout << "Input arrI";
for (int it = 0; it < sizeI; it++) {
std::cin >> arrI[it];
}
std::cout << "Input arrCh";
for (int it = 0; it < sizeCh; it++) {
std::cin >> arrCh[it];
}
std::cout << "Input arrD";
for (int it = 0; it < sizeD; it++) {
std::cin >> arrD[it];
}
std::cout << "Max element int = "<<  myFunc(arrI, sizeI);
std::cout << "Max element char = " << myFunc(arrCh, sizeCh);
std::cout << "Max element double = " << myFunc(arrD, sizeD);

myList<int> li(5);
li.push_back(4);
//li.push_back(7);
li.print();

getchar();
return 0;
}

template<typename TT>
myList<TT>::myList()
{
prev = NULL;
next = NULL;
}

template<typename TT>
myList<TT>::myList(TT el)
{
prev = NULL;
next = NULL;
element = el;
}

template<typename TT>
void myList<TT>::print()
{
myList<TT> *temp = new myList<TT>;
*temp = *this;
while (temp->prev != NULL) {
*temp = *temp->prev;
}
while (temp->next != NULL) {
std::cout << temp->element << "\t";
*temp = *temp->next;
}
std::cout << temp->element << "\t";
}

template<typename TT>
void myList<TT>::push_back(TT new_elem)
{
myList<TT> *tmp = new myList<TT>;
myList<TT> *tmp1 = new myList<TT>;
next = tmp;
*tmp1 = *this;
tmp->element = new_elem;
(tmp->prev) = tmp1;
tmp->next = NULL;
this->element = tmp->element;
this->prev = tmp->prev;
this->next = NULL;
}*/