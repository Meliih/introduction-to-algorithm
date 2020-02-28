#include <iostream>
using namespace std;

class Student {
	
private:
	string name;
	int note;

public:
	
	Student () {
		this->name = "Bilgi yok";
		this->note = 0;
	}
	Student (string name) { //consturctor Overloading
		this->name =name;
		this->note =0;
	}
	
	Student (string name,int note) { //constructor
		this->name = name;
		this->note = note;
	}
	
	void setName (string name) {
		this->name = name;
	}
	void setNote (int note) {
		this->note = note;
	}
	
	string getName () {
		return name;
	}
	int getNote () {
		return note;
	}
	
	void showInfo() {
		cout << "Isim :" << name <<endl;
		cout << "Notu :" << this->note <<endl; 
	}
	
};



int main () {
	
	Student student1("Melih",90);
	Student student2("Deniz");
	Student student3;
	student1.showInfo();
	student2.showInfo();
	student3.showInfo();
}
