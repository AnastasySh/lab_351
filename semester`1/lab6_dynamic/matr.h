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
	friend matrix operator+(matrix& matrA, matrix& matrB);
private:
	int ** matr;
	int stolb;
	int strok;

};