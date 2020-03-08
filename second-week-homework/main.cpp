#include "Complex.h"
#include <iostream>

using namespace std;

int main() {

	Complex a("4+4i");
	Complex b("5+5i");
	cout << "Sayilar : " << endl;
	a.showInfo();
	b.showInfo();
	cout << endl;
	cout << "Toplami  = ";
	a.add(b);
	cout << endl << "Cikarma =";
	a.subtract(b);
	cout << endl << "Bolme =";
	a.divide(b);

	

	return 0;
}