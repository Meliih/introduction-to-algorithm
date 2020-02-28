#include <iostream>
using namespace std;

class Personnel {
	
private:
	
	string name;
	string surname;
	int age;
	int salary;
	
public:
	
	void setName (string isim) {
		name = isim;
	}
	void setSurname (string soyisim) {
		surname = soyisim;
	}
	void setAge (int yas) {
		if (0 >age || age> 150) 
		cout << "Boyle bir deger giremezsiniz";
		else {
			age = yas;
		}	
		
	}
	void setSalary (int maas ) {
		salary = maas;
	}
	
	string getName () {
		return name;
	}
	string getSurname () {
		return surname;
	}
	int getAge () {
		return age;
	}
	int getSalary () {
		return salary;
	}
};


int main () {
	
	Personnel * personnel = new Personnel();
	
	personnel-> setName("Melih");
	personnel -> setSurname("Kahraman");
	personnel -> setAge(19);
	personnel -> setSalary(3000);
	
	cout << personnel->getName() << endl;
	cout << personnel->getSurname() << endl;
	cout << personnel->getAge() << endl;
	cout << personnel->getSalary() << endl;
	
}
