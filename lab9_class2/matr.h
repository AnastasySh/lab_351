#pragma once
class matrix
{
public:
	int getstrok();
	int getstolb();
	void input();
	matrix transp();
	matrix summmatr(matrix matr2);
	matrix multmatr(matrix matr2);
	int getelement(int i, int j);
	void print();
	matrix();
	~matrix();

private:
	int matr[10][10];
	int stolb;
	int strok;
	
};