#include <iostream>
using namespace std;

class Student {
	
private:
	string name;
	int note;

public:
	
	Student (string isim,int notu) { //constructor
		name = isim;
		note = notu;
	}
	
	void setName (string isim) {
		name = isim;
	}
	void setNote (int notu) {
		note = notu;
	}
	
	string getName () {
		return name;
	}
	int getNote () {
		return note;
	}
	
	void showInfo() {
		cout << "Isim :" << name <<endl;
		cout << "Notu :" << note <<endl; 
	}
	
};



int main () {
	
	Student student1("Melih",90);
	student1.showInfo();
}
