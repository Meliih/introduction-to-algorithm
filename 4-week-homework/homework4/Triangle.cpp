#include "Triangle.h"
#include "Point.h"
#include <math.h>
#include <iostream>
#include <stdexcept>

Triangle::Triangle(const Point& a, const Point& b, const Point& c, const Color& color)
{
	setA(a);
	setB(b);
	setC(c);
	//isValid();
	this->color = color;
}

Triangle::Triangle(const vector<Point>& pts, const Color& color)
{
	setA(pts[0]);
	setB(pts[1]);
	setC(pts[2]);
	this->color = color;
}

Triangle::Triangle(const array<Point, NUMBER_OF_CORNERS>& pts, const Color& color)
{
	setA(pts[0]);
	setB(pts[0]);
	setC(pts[0]);
	this->color = color;
}

Point Triangle::getA() const noexcept
{
	return pts[0];
}

Point Triangle::getB() const noexcept
{
	return pts[1];
}

Point Triangle::getC() const noexcept
{
	return pts[2];
}

Triangle::Color Triangle::getColor() const noexcept
{
	return (color);
}

string Triangle::getColorAsString() const noexcept
{
	return Triangle::colorToStringMap.at(color);
}

double Triangle::getPerimeter() const noexcept
{
	double a_b = sqrt((pts[0].x - pts[1].x) * (pts[0].x - pts[1].x) + (pts[0].y - pts[1].y) * (pts[0].y - pts[1].y));
	double b_c = sqrt((pts[1].x - pts[2].x) * (pts[1].x - pts[2].x) + (pts[1].y - pts[2].y) * (pts[1].y - pts[2].y));
	double a_c = sqrt((pts[0].x - pts[2].x) * (pts[0].x - pts[2].x) + (pts[0].y - pts[2].y) * (pts[0].y - pts[2].y));

	return a_b + b_c + a_c;
}

bool Triangle::setA(const Point& pt)
{
	pts[0].x = pt.x;
	pts[0].y = pt.y;
	return false;
}

bool Triangle::setB(const Point& pt)
{
	pts[1].x = pt.x;
	pts[1].y = pt.y;
	return false;
}

bool Triangle::setC(const Point& pt)
{
	pts[2].x = pt.x;
	pts[2].y = pt.y;
	return false;
}

bool Triangle::isValid() const
{
	try {
		double a_b = sqrt((pts[0].x - pts[1].x) * (pts[0].x - pts[1].x) + (pts[0].y - pts[1].y) * (pts[0].y - pts[1].y));
		double b_c = sqrt((pts[1].x - pts[2].x) * (pts[1].x - pts[2].x) + (pts[1].y - pts[2].y) * (pts[1].y - pts[2].y));
		double a_c = sqrt((pts[0].x - pts[2].x) * (pts[0].x - pts[2].x) + (pts[0].y - pts[2].y) * (pts[0].y - pts[2].y));

		if (a_b + b_c > a_c&& a_b + a_c > b_c&& a_c + b_c > a_b&& a_b - b_c < a_c && a_b - a_c < b_c && b_c - a_c < a_b && a_b>0 && b_c> 0 && a_c>0) {
			return true;
		}
		else {
			throw invalid_argument("Ucgen Gecerli Degil");
		}
	}
	catch (const std::invalid_argument & ia) {
		std::cerr << "Invalid argument: " << ia.what() << endl;
	}
	return false;
}

double Triangle::printInfo() const noexcept
{
	std::cout << "Triangle" << endl;
	std::cout << "Number of Points : 3" << endl;
	std::cout << "(" << pts[0].x << ", " << pts[0].y << ")";
	std::cout << "(" << pts[1].x << ", " << pts[1].y << ")";
	std::cout << "(" << pts[2].x << ", " << pts[2].y << ")" << endl;
	std::cout << "Peripheral: " << Triangle::getPerimeter() << endl;
	std::cout << "Color" << Triangle::colorToStringMap.at(color) << endl;

	return 0;
}
