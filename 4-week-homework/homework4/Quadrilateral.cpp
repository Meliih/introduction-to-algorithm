#include "Quadrilateral.h"
#include <array>
#include <string>
#include <map>
#include "Point.h"
#include <iostream>
#include <stdexcept>



Quadrilateral::Quadrilateral(const Point& a, const Point& c, const Color& color)
{
	setA(a);
	setC(c);

	pts[1].x = c.x;
	pts[1].y = a.y;
	pts[3].y = c.y;
	pts[3].x = a.x;

	this->color = color;
	isValid();
}

Quadrilateral::Quadrilateral(const Point& a, double width, double height, const Color& color)
{
	pts[0].x = a.x;
	pts[0].y = a.y;
	pts[1].x = a.x + width;
	pts[1].y = a.y;
	pts[2].x = pts[1].x;
	pts[2].y = pts[1].y + height;
	pts[3].x = a.x;
	pts[3].y = pts[2].y;
	this->color = color;
	isValid();
}

Quadrilateral::Quadrilateral(const Point& a, const Point& b, const Point& c, const Point& d, const Color& color)
{
	pts[0].x = a.x;
	pts[0].y = a.y;
	pts[1].x = b.x;
	pts[1].y = b.y;
	pts[2].x = c.x;
	pts[2].y = c.y;
	pts[3].x = d.x;
	pts[3].y = d.y;
	this->color = color;
	//isValid();
}

Quadrilateral::Quadrilateral(const array<Point, NUMBER_OF_CORNERS>& pts, const Color& color)
{
	this->pts[0].x = pts[0].x;
	this->pts[0].y = pts[0].y;
	this->pts[1].x = pts[1].x;
	this->pts[1].y = pts[1].y;
	this->pts[2].x = pts[2].x;
	this->pts[2].y = pts[2].y;
	this->pts[3].x = pts[3].x;
	this->pts[3].y = pts[3].y;
	this->color = color;
	isValid();
}

Quadrilateral::Color Quadrilateral::getColor() const noexcept
{

	return (color);
}

string Quadrilateral::getColorAsString() const noexcept
{
	return Quadrilateral::colorToStringMap.at(color);
}

double Quadrilateral::getPerimeter() const noexcept
{
	double a_b = sqrt((pts[0].x - pts[1].x) * (pts[0].x - pts[1].x) + (pts[0].y - pts[1].y) * (pts[0].y - pts[1].y));
	double a_d = sqrt((pts[0].x - pts[3].x) * (pts[0].x - pts[3].x) + (pts[0].y - pts[3].y) * (pts[0].y - pts[3].y));
	double b_c = sqrt((pts[1].x - pts[2].x) * (pts[1].x - pts[2].x) + (pts[1].y - pts[2].y) * (pts[1].y - pts[2].y));
	double c_d = sqrt((pts[2].x - pts[3].x) * (pts[2].x - pts[3].x) + (pts[2].y - pts[3].y) * (pts[2].y - pts[3].y));

	return a_b * 2 + a_d * 2;
}

bool Quadrilateral::isValid() const
{
	double a_b = sqrt((pts[0].x - pts[1].x) * (pts[0].x - pts[1].x) + (pts[0].y - pts[1].y) * (pts[0].y - pts[1].y));
	double a_d = sqrt((pts[0].x - pts[3].x) * (pts[0].x - pts[3].x) + (pts[0].y - pts[3].y) * (pts[0].y - pts[3].y));
	double b_c = sqrt((pts[1].x - pts[2].x) * (pts[1].x - pts[2].x) + (pts[1].y - pts[2].y) * (pts[1].y - pts[2].y));
	double c_d = sqrt((pts[2].x - pts[3].x) * (pts[2].x - pts[3].x) + (pts[2].y - pts[3].y) * (pts[2].y - pts[3].y));

	try {
		if (a_b == c_d && a_d == b_c && a_b > 0 && a_d > 0 && b_c > 0 && c_d > 0) {
			return true;
		}
		else {
			throw "Dortgen Gecerli Degil";
		}
	}
	catch (const std::invalid_argument & ia) {
		std::cerr << "Invalid argument: " << ia.what() << endl;
		return false;
	}
}

bool Quadrilateral::setA(const Point& pt)
{
	pts[0].x = pt.x;
	pts[0].y = pt.y;
	return false;
}

bool Quadrilateral::setB(const Point& pt)
{
	pts[1].x = pt.x;
	pts[1].y = pt.y;
	return false;
}

bool Quadrilateral::setC(const Point& pt)
{
	pts[2].x = pt.x;
	pts[2].y = pt.y;
	return false;
}

bool Quadrilateral::setD(const Point& pt)
{
	pts[3].x = pt.x;
	pts[3].y = pt.y;
	return false;
}

double Quadrilateral::printInfo() const noexcept
{
	std::cout << "Rectangle" << endl;
	std::cout << "Number of Points : 4" << endl;
	std::cout << "(" << pts[0].x << ", " << pts[0].y << "),";
	std::cout << "(" << pts[1].x << ", " << pts[1].y << "),";
	std::cout << "(" << pts[2].x << ", " << pts[2].y << "),";
	std::cout << "(" << pts[3].x << ", " << pts[3].y << ")" << endl;
	std::cout << "Peripheral: " << getPerimeter() << endl;
	std::cout << "Color" << Quadrilateral::colorToStringMap.at(color) << endl;
	return 0.0;
}

Point Quadrilateral::getA() const noexcept
{

	return pts[0];
}

Point Quadrilateral::getB() const noexcept
{
	return pts[1];
}

Point Quadrilateral::getC() const noexcept
{
	return pts[2];
}

Point Quadrilateral::getD() const noexcept
{
	return pts[3];
}

