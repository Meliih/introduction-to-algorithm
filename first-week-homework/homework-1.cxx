#include <iostream>

using namespace std;

void duzucgen(int b) { //duzucgen basan fonksiyon tanimladim
    int yildiz=1; //baslangicta 1 yıldız basilacagi icin 1 tanimlandi
	int	bosluk=b/2+1; 
	
	
		for(int k=0;k<b/2+1;k++) {
		
			for (int s=0;s<bosluk-1;s++) {
			cout << " ";
			}
			
			for (int s=0;s<yildiz;s++) {
			cout << "*";
			}
		
		cout <<endl;
		bosluk--; // bosluklar birer birer azaliyor
		yildiz+=2; //yildizlar ikiser ikiser artar
	
		}
	}
	
void tersucgen(int c) {
	
	int bosluk=0; //ters ucgen oldugundan bosluk sayisi 0 ile baslar
	int yildiz=c;//yildiz sayisi kullanicinin girdigi sayidan baslar
	int k=0;
	while(k<c/2+1) {
		int s=0,t=0;//
		while(s<bosluk) {
			cout << " ";
			s++;
		}
		while(t<yildiz) {
			cout << "*";
			t++;
		}
		cout <<endl;
		bosluk++;
		yildiz-=2;
		k++;
	}
}

void elmas(int deger) { // duz ucgen ile ters ucgeni birlestirince elmas sekli ortaya cikar
	duzucgen(deger);
	tersucgen(deger);
}
int main () {
int a,b,c,d,temp=0;

while (1){
	cout << "Bir sekil seciniz" << endl << "1: Duz ucgen\n2: Ters ucgen\n3: Elmas\n0: Cikis" << endl;
	cin >> a;

    switch (a) {
		case 1:
       
        cout << "\n3-15 arasinda bir sayi giriniz";
        cin >> b;
        if (b>=3 && b<=15 &&b%2==1) {
			duzucgen(b);
			return 0;							//GIRILEN SAYILAR KONTROL EDILIR
		}										//GIRILEN SAYIYA GORE UYARI VERIR
		
		else if (b%2==0 && b>3 && b<15 ) {
			cout << "Cift sayi girdiniz" << endl << "Tek sayi giriniz" << endl << endl;
			temp++;	
		}		
		else if (b%2==0 && (b<3 || b>15)) {
			cout << "Araligin disinda bir cift sayi girdiniz " <<endl;
			cout << "Lutfen aralik dahilinde bir tek sayi giriniz" <<endl<<endl;
			temp++;
		}
		else if (b %2==1 && (b>15 || b <3)) {
			cout << "Araligin disinda bir tek sayi girdiniz" << endl;
			cout << "Lutfen aralik dahilinde bir tek sayi giriniz" <<endl<<endl;
			temp++;	
		}
		break;

        case 2:
        cout << "\n3-15 arasinda bir  sayi giriniz\n";
        cin >> c;
		if (c>=3 && c<=15 && c%2==1) {   
			tersucgen(c); 		
			return 0;  
		}	
		else if (c%2==0 && c>3 && c<15 ) {
			cout << "Cift sayi girdiniz" << endl << "Tek sayi giriniz"<<endl << endl;
			temp++;	
		}
		
		else if (c%2==0 && (c<3 || c>15)) {
			cout << "Araligin disinda bir cift sayi girdiniz " <<endl;
			cout << "Lutfen aralik dahilinde bir tek sayi giriniz" <<endl<<endl;
			temp++;
		}
		else if (c %2==1 && (c>15 || c <3)) {
			cout << "Araligin disinda bir tek sayi girdiniz" << endl;
			cout << "Lutfen aralik dahilinde bir tek sayi giriniz" <<endl<<endl;
			temp++;	
		}
		break;
	
        case 3:
        cout << "\n5-15 arasinda bir sayi giriniz\n"<<endl;
        cin >> d;   
		if (d>=5 && d<=15 &&d%2==1) {
			duzucgen(d);
			return 0;
		}
		
		else if (d%2==0 && d>5 && d<15 ) {
			cout << "Cift sayi girdiniz" << endl<<"Tek sayi giriniz" <<endl<<endl;
			temp++;	
		}
		
		else if (d%2==0 && (d<5 || d>15)) {
			cout << "Araligin disinda bir cift sayi girdiniz " <<endl;
			cout << "Lutfen aralik dahilinde bir tek sayi giriniz" <<endl<<endl;
			temp++;
		}
		else if (d %2==1 && (d>15 || d <5)) {
			cout << "Araligin disinda bir tek sayi girdiniz" << endl;
			cout << "Lutfen aralik dahilinde bir tek sayi giriniz" <<endl<<endl;
			temp++;	
		}
		break;
		
        case 0:   return 0;
        break;
    }
    
		if(temp==3 ) return 0;//yanlıs girme sayisi 3 olduysa return edip programi kapatir
}
return 0;
}
