#pragma once
#include <iostream>

using namespace std;


class Complex
{
public:
	Complex();//Default Constructor

	Complex(int a, int b);

	Complex(string array); //Conversion Constructor
	
	explicit Complex(int i)    : real(i), imaginary(i) {} //Conversion Constructor

	explicit Complex(double i)  : real(i), imaginary(i) {} //Conversion Constructor

	void showInfo();

	void setReal(const int a);

	void setImaginary(const int a);

	int getReal() const ;

	int getImaginary() const ;

	void add(Complex& variable);

	void subtract(Complex& variable);

	void divide(Complex& variable);

private:
	int real;
	int imaginary;

};

