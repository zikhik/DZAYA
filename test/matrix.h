#pragma once
#ifndef matrix_h
#define matrix_h
#include <iostream>
#include "matrixexception.h"
using namespace std;

template <typename SomeValueType>
class Matrix;

template <typename SomeValueType>
std::ostream &operator << (std::ostream &out, const Matrix<SomeValueType> &temp);
template <typename SomeValueType>
std::istream &operator >> (std::istream &input, Matrix<SomeValueType> &matr);
template <typename SomeValueType>
class Matrix
{
public:
	Matrix<SomeValueType>() :n(0), m(0), matrix(nullptr) {};
	Matrix(unsigned int rows, unsigned int columns);
	Matrix(const Matrix &copy);
	~Matrix<SomeValueType>();
	Matrix operator + (const Matrix&);
	Matrix operator - (const Matrix&);
	Matrix operator * (const Matrix&);
	Matrix &operator = (const Matrix&);
	bool operator == (const Matrix&);
	SomeValueType* operator [] (unsigned int);
	unsigned int Rows() const;
	unsigned int Columns() const;
	friend std::ostream &operator << <>(std::ostream &out, const Matrix<SomeValueType> &temp);
	friend std::istream &operator >> <>(std::istream &input, Matrix<SomeValueType> &matr);
private:
	SomeValueType **matrix;
	unsigned int n;	
	unsigned int m;	
};
#include "matrix.cpp"
#endif
