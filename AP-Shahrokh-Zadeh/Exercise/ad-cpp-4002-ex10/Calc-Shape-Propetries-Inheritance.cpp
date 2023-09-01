#include <iostream>
#include <cmath>

using namespace std;
class Shape 
{
	private:
	public:
		Shape();
		~Shape();
		virtual double Area() = 0;
		virtual double Perimeter() = 0;
};

class Rectangle : public Shape
{
	private:
		double width;
		double length;
	public:
		Rectangle();
		Rectangle(double, double);
		Rectangle(const Rectangle &rect);
		~Rectangle();
		virtual double Area();
		virtual double Perimeter();
};

class Circle : public Shape
{
	private:
		double radius;
	public:
		Circle();
		Circle(double);
		Circle(const Circle &);
		~Circle();
		virtual double Area();
		virtual double Perimeter();
};

Shape::Shape()
{
	cout << "\033[1;32mObject Created !" << endl;
}

Shape::~Shape()
{
	cout << "\033[1;32mObject Dead !" << endl;
}


Rectangle::Rectangle()
{
	width = 1;
	length = 1;
}

Rectangle::Rectangle(double w, double l)
{
	width = w;
	length = l;
}

Rectangle::Rectangle(const Rectangle &rect)
{
	width = rect.width;
	length = rect.length;
}

Rectangle::~Rectangle()
{
	width = 1;
	length = 1;
}

double Rectangle::Area()
{
	return (width * length);
}

double Rectangle::Perimeter()
{
	return (2 * (width + length));
}

Circle::Circle()
{
	radius = 1;
}

Circle::Circle(double r)
{
	radius = r;
}

Circle::Circle(const Circle &circ)
{
	radius = circ.radius;
}

Circle::~Circle()
{
	radius = 1;
}

double Circle::Area()
{
	return (pow(radius, 2) * M_PI);
}

double Circle::Perimeter()
{
	return (2 * M_PI * radius);
}

int main()
{
	Shape *object;
	double objectWidth,objectLength;
	double objectRadius;
	int choice;
	cout << "\033[1;36mChoose One of Below Options \033[0m:" << endl;
	cout << "\033[1;36m 1. \033[0mRectangle" << endl;
	cout << "\033[1;36m 2. \033[0mCircle" << endl;
	cout << "\033[1;36mChoice \033[0m: "; cin >> choice;
	switch (choice)
	{
		case 1:
			cout << "\033[1;36mEnter Width and Length \033[0m:" << endl;
			cin >> objectWidth >> objectLength;
			object = new Rectangle(objectWidth, objectLength);
			cout << "\033[0m- \033[1;33mArea is \033[0m:\033[1;34m " << object -> Area() << endl;
			cout << "\033[0m- \033[1;33mPerimeter is \033[0m:\033[1;34m " << object -> Perimeter() << endl;
		break;
		case 2:
			cout << "\033[1;36mEnter Radius \033[0m:" << endl;
			cin >> objectRadius;
			object = new Circle(objectRadius);
			cout << "\033[0m- \033[1;33mArea is \033[0m:\033[1;34m " << object -> Area() << endl;
			cout << "\033[0m- \033[1;33mPerimeter is \033[0m:\033[1;34m " << object -> Perimeter() << endl;
		break;
		default:
			cout << "Wrong Option !" << endl;
	}
	return 0;
}