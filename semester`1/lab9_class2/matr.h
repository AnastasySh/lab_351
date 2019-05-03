#pragma once
class matrix
{
public:
	int getstrok();
	int getstolb();
	void input();
	void transp();
	void summmatr(matrix matr2);
	void multmatr(matrix matr2);
	int getelement(int i, int j);
	void print();
	matrix();
	~matrix();

private:
	int matr[10][10];
	int stolb;
	int strok;
	
};