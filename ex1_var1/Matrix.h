#pragma once
#include <iostream>
#include <iomanip>
#include "Vector.h"
using namespace std;
const size_t rows = 5;
const size_t cols = 5;

class Matrix{
public:

	double** arr2D;
	
	Matrix();//����������� 

	double** remakeArray2D();
	void printArray2D();


	void setAt(int i, int j, double val);
	double at(int i, int j) const;

	double** operator++ (); //����������: ���������� ���������
	double** operator-- (); //����������: ���������� ���������
	Matrix& operator++(int N); //����������: ����������� ���������
	Matrix& operator--(int N); //����������: ����������� ���������

	~Matrix(); //�������������
};

