#include <iostream>
#include <cmath>
using namespace std;

class Point
{
	private:
		double x,y;
	public:
		void set(double, double);
		void display();
		Point();
};

void Point::set(double _x, double _y)
{
	x = _x;
	y = _y;
}

void Point::display()
{
	cout << endl;
	cout << "X : " << x << endl;
	cout << "Y : " << y << endl;
}

Point::Point()
{
	x = 1;
	y = 1;
}

class Circle : public Point
{
	private:
		double radius;
		Point shape;
	public:
		double Area();
		double Perimeter();
		void set(double);
		double accessRadius() {return radius;}
		void show();
		Circle();
};

double Circle::Area()
{
	return (pow(radius, 2) * M_PI);
}

double Circle::Perimeter()
{
	return (2 * M_PI * radius);
}

void Circle::show()
{
	cout << "Radius : " << accessRadius() << endl;
	cout << endl;
	cout << "Area : " << Area() << endl;
	cout << "Perimeter : " << Perimeter() << endl;
}

void Circle::set(double _r)
{
	radius = _r;
	double _x,_y;
	cout << "\033[1;36mEnter x Position and y Position\033[0m :\033[1;33m " << endl; 
	cout << "\033[1;32m- \033[0m"; cin >> _x;
	cout << "\033[1;32m- \033[0m"; cin >> _y;
	shape.set(_x, _y);
	shape.display();
	show();
}

Circle::Circle()
{
	radius = 1;
}

int main()
{
	double r;
	cout << "\033[1;36mEnter Radius of Your Circle\033[0m :\033[1;33m "; cin >> r;
	Circle object;
	object.set(r);	
}