#include "Complex.h"
#include <iostream>
#include <string>

using namespace std;

Complex::Complex() {		//Default Constructor
	real = 0;
	imaginary = 0;
}

Complex::Complex(int a, int b) {	
	real = a;
	imaginary = b;
}
Complex::Complex(string array) {
	int i, j =-1;
	int size = array.length();
	int imaginaryT;
	string tempReal, tempImaginary;
	for (i = 0; i < size; i++) {

		if (array[i] == '+') {
			j = 1;
			break;
		}
		else if (array[i] == '-') {
			j = -1;
			break;
		}
		else if (array[i] == ' ') {

		}
		else {
			tempReal += array[i];
		}
	}

	for (; i < size; i++) {

		if (array[i] == ' ') {

		}
		else {
			tempImaginary += array[i];
		}

	}

	real = stoi(tempReal);
	imaginaryT = stoi(tempImaginary);
	imaginary = imaginaryT;


}

void Complex::showInfo() {
	if (imaginary > 0)
		cout << real << "+" <<

		imaginary << "i" << endl;

	else if (imaginary == 0)
		cout << real << endl;

	else
		cout << real << "" << imaginary << "i" << endl;
}
void Complex::setReal(const int a) {
	real = a;
}
void Complex::setImaginary(const int a) {
	imaginary = a;
}

int Complex::getReal() const {

	return real;
}
int Complex::getImaginary() const {

	return imaginary;
}

void Complex::add(Complex & variable)  {

	int resultReal = real + variable.real;
	int resultImaginary = imaginary + variable.imaginary;

	if (resultImaginary > 0)
		cout << resultReal << "+" <<
		resultImaginary << "i" << endl;

	else if (resultImaginary == 0)
		cout << resultReal << endl;

	else
		cout << resultReal << "" << resultImaginary << "i" << endl;
}

void Complex::subtract(Complex& variable) {

	int resultReal = real - variable.real;
	int resultImaginary = imaginary - variable.imaginary;

	if (resultImaginary > 0)
		cout << resultReal << "+" <<
		resultImaginary << "i" << endl;

	else if (resultImaginary == 0)
		cout << resultReal << endl;

	else
		cout << resultReal << "" << resultImaginary << "i" << endl;

}
void Complex::divide(Complex& variable) {


	if (variable.imaginary == 0) {
		cout << "0'a bolme hatasi";
		return;
	}
	double realt = real;
	double imaginaryt = imaginary;
	double resultReal = realt / variable.real;
	double resultImaginary = imaginaryt / variable.imaginary;

	if (resultImaginary > 0)
		cout << resultReal << "+" <<
		resultImaginary << "i" << endl;

	else if (resultImaginary == 0)
		cout << resultReal << endl;

	else
		cout << resultReal << "" << resultImaginary << "i" << endl;

}
