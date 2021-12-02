#pragma once
#include <iostream>
using namespace std;



class Vector{
public:

	double* arr1D;

	Vector(size_t n); //����������� 
	
	void printArray1D();

	double** transform();

	~Vector(); //�������������

	double& operator[] (const int index) { //���������� ��������� �����������
		return arr1D[index];
	}

};

