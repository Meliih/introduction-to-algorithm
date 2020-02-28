#include <iostream>
using namespace std;

class Student {
	
private:
	string name;
	int note;

public:
	
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
	student1.showInfo();
}
