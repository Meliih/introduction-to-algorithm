#pragma once
#include <array>
#include <string>
#include <map>
#include "Point.h"

using namespace std;

class Quadrilateral
{
public:
	constexpr static int NUMBER_OF_CORNERS{ 4 };
	enum class Color { RED, BLUE, WHITE, BLACK, GREEN };
	const map<Quadrilateral::Color, string> colorToStringMap = {
	{ Quadrilateral::Color::RED, "Red"},
	{ Quadrilateral::Color::BLUE, "Blue" },
	{ Quadrilateral::Color::GREEN, "Green" },
	{ Quadrilateral::Color::RED, "Red" },
	{ Quadrilateral::Color::WHITE, "White" }
	};
	// Constructors

	// Bir dikd�rtgen/kare olu�turur a her zaman sol �st noktay�, c her zaman sa� alt noktay� g�sterir
	Quadrilateral(const Point& a = { 0, 0 }, const Point& c = { 1, 1 }, const Color& color = Color::GREEN);

	// Verilen en ve boy de�erlerine uygun olarak bir dikd�rtgen/kare olu�turur a her zaman sol �st noktay� g�sterir
	Quadrilateral(const Point& a, double width, double height, const Color& color = Color::GREEN);

	// Verilen noktalara g�re d�rtgen olu�turur. Bu noktalar�n bir d�rtgen olu�turdu�u kontrol edilmeldir.
	Quadrilateral(const Point& a, const Point& b, const Point& c, const Point& d, const Color& color = Color::GREEN);
	Quadrilateral(const array<Point, NUMBER_OF_CORNERS>& pts, const Color& color = Color::GREEN);

	// Referanslar
	Point& a = pts[0];
	Point& b = pts[1];
	Point& c = pts[2];
	Point& d = pts[3];

	// Getter Functions
	Point getA() const noexcept;
	Point getB() const noexcept;
	Point getC() const noexcept;
	Point getD() const noexcept;

	// D�rtgenin rengini string olarak d�nderir
	Color getColor() const noexcept;
	string getColorAsString() const noexcept;

	// D�rtgenin �evresini hesaplar ve g�nderir
	double getPerimeter() const noexcept;


	/* D�rtgen olup olmad���n� kontrol eder.
	 * Bu fonksiyonun t�m yap�c�lar ve setter fonksiyonlar i�inde do�rudan/dolayl� olarak �a�r�lmas� zorunludur.
	 * E�er verilen de�erler bir d�rtgen olu�turmuyorsa invalid_argument exception f�rlat�lmal� ve bu bu exception kontrol edilmelidir
	 * Program sonland�r�lmamal�d�r.
	 */
	bool isValid() const;

	// Setter Functions
	bool setA(const Point& pt);
	bool setB(const Point& pt);
	bool setC(const Point& pt);
	bool setD(const Point& pt);

	double printInfo() const noexcept;
	// Ekrana �unu basar:
	/* Rectangle
	   Number of points: 4
	   Points: (3.00, 4.40), (3.00, 5.00), (3.80, 5.00), (3.80, 4.40)
	   Priperhal: 2.80
	   Color: Red
	*/
private:
	array<Point, NUMBER_OF_CORNERS> pts;
	Color color;
};

