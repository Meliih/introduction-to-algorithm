#pragma once
#include <array>

// !!!!!!!!!!!!!!!! BU SAYFADA DUZENLEME YAPMAYINIZ !!!!!!!!!!!!!!!!

using namespace std;

// 2-boyutlu bir uzayda bir noktanýn gösterilmesini saðlayan yapý (struct)
typedef struct Point_st {
	/* Sýnýflarda varsayýlan eriþim düzenleyicisi (access modifier) PRIVATE,
	 * yapýlarda ise PUBLIC olarak tanýmlýdýr.
	 */
	array<double, 2> coords;

	// Noktanýn x, ve y konumlarýna farklý bir þekilde eriþim imkaný saðlanmýþtýr
	double& x = coords[0]; // Referanslar ya burada yapýldýðý gibi tanýmlandýðýnda ilklendirilmeli ya da üye ilklendirme söz dizimi içinde bu iþlem yapýlmalýdýr 
	double& y = coords[1]; // Sonrasýnda referansýn gösterdiði yer deðiþtirilemez ama gösterdiði yerdeki deðer deðiþtirilebilir.

	// Diðer bir nokta ile Euclidean uzaklýðýný veren bir üye fonksiyon
	inline double distanceTo(const Point_st& other) const
	{
		return sqrt((other.x - x) * (other.x - x) + (other.y - y) * (other.y - y));
	}

	/* Yapýlarda da constructor ve diðer üye fonksiyonlarý/operatörleri tanýmlayabilirsiniz.
	 * Aþaðýdaki yapici fonksiyonlarda uye ilklendirme soz dizimi kullanmaktadir ve
	 * bu fonksiyonlar boþ bir ana bloða sahiptirler.
	 */
	Point_st(double x = 0, double y = 0) : coords{ x , y } //, x{ coords[0] }, y{ coords[1] } //Yukarýda verilen ilklendirmeyi kapatýp referanslarý burada da ilklendirebilirsiniz.
	{
		/* Bilerek boþ býrakýlmýþtýr. */
	}

	// Dönüþtüren yapýcý
	Point_st(const array<double, 2>& coords) : coords{ coords }//, x{ this->coords[0] }, y{ this->coords[1] }  //Yukarýda verilen ilklendirmeyi kapatýp referanslarý burada da ilklendirebilirsiniz.
	{
		/* Bilerek boþ býrakýlmýþtýr. */
	}
} Point;
