#include <iostream>
#include <string>

using namespace std;

class Personnel {
	
	public:
	string name;
	string surname;
	int age;
	int salary;
	
	void showInfo () {
		
		cout << "Adi " << name << endl;
		cout << "Soyadi " << surname << endl;
		cout << "Yasi " << age << endl;
		cout << "Maasi " << salary << endl;
	}
	
};


int main () {
	
	Personnel employee;
	
	employee.name = "Melih";
	employee.surname = "Kahraman";
	employee.age = 19;
	employee.salary = 3000;
	
	employee.showInfo();
	
	
	
}
