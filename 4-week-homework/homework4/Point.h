#pragma once
#include <array>

// !!!!!!!!!!!!!!!! BU SAYFADA DUZENLEME YAPMAYINIZ !!!!!!!!!!!!!!!!

using namespace std;

// 2-boyutlu bir uzayda bir noktan�n g�sterilmesini sa�layan yap� (struct)
typedef struct Point_st {
	/* S�n�flarda varsay�lan eri�im d�zenleyicisi (access modifier) PRIVATE,
	 * yap�larda ise PUBLIC olarak tan�ml�d�r.
	 */
	array<double, 2> coords;

	// Noktan�n x, ve y konumlar�na farkl� bir �ekilde eri�im imkan� sa�lanm��t�r
	double& x = coords[0]; // Referanslar ya burada yap�ld��� gibi tan�mland���nda ilklendirilmeli ya da �ye ilklendirme s�z dizimi i�inde bu i�lem yap�lmal�d�r 
	double& y = coords[1]; // Sonras�nda referans�n g�sterdi�i yer de�i�tirilemez ama g�sterdi�i yerdeki de�er de�i�tirilebilir.

	// Di�er bir nokta ile Euclidean uzakl���n� veren bir �ye fonksiyon
	inline double distanceTo(const Point_st& other) const
	{
		return sqrt((other.x - x) * (other.x - x) + (other.y - y) * (other.y - y));
	}

	/* Yap�larda da constructor ve di�er �ye fonksiyonlar�/operat�rleri tan�mlayabilirsiniz.
	 * A�a��daki yapici fonksiyonlarda uye ilklendirme soz dizimi kullanmaktadir ve
	 * bu fonksiyonlar bo� bir ana blo�a sahiptirler.
	 */
	Point_st(double x = 0, double y = 0) : coords{ x , y } //, x{ coords[0] }, y{ coords[1] } //Yukar�da verilen ilklendirmeyi kapat�p referanslar� burada da ilklendirebilirsiniz.
	{
		/* Bilerek bo� b�rak�lm��t�r. */
	}

	// D�n��t�ren yap�c�
	Point_st(const array<double, 2>& coords) : coords{ coords }//, x{ this->coords[0] }, y{ this->coords[1] }  //Yukar�da verilen ilklendirmeyi kapat�p referanslar� burada da ilklendirebilirsiniz.
	{
		/* Bilerek bo� b�rak�lm��t�r. */
	}
} Point;
