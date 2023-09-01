#include <iostream>
using namespace std;

class Triple
{
	private:
		double x;
		double y;
		double z;
	public:
		Triple();
		Triple(double, double, double);
		void set(double, double, double);
		double xGet() {return x;}
		double yGet() {return y;}
		double zGet() {return z;}
		Triple operator + (const Triple &);
		Triple operator = (double);
		Triple operator ++ (int);
		void display();
};

Triple::Triple()
{
	x = 1;
	y = 1;
	z = 1;
}

Triple::Triple(double _x, double _y, double _z)
{
	x = _x;
	y = _y;
	z = _z;
}

void Triple::set(double _x, double _y, double _z)
{
	x = _x;
	y = _y;
	z = _z;
}

Triple Triple::operator+ (const Triple &object)
{
	Triple temp;
	temp.x = this -> x + object.x;
	temp.y = this -> y + object.y;
	temp.z = this -> z + object.z;
	return temp;
}

Triple Triple::operator= (double value)
{
	Triple temp;
	temp.x = this -> x;
	temp.y = this -> y;
	temp.z = this -> z;
	return temp;
}

Triple Triple::operator++ (int)
{
	Triple temp;
	temp.x = ++this -> x;
	temp.y = ++this -> y;
	temp.z = ++this -> z;
	return temp;
}

void Triple::display()
{
	cout << endl;
	cout << "\033[1;32m--------------------\033[0m" << endl;
	cout << "\033[0m- \033[1;36mx \033[0m: \033[1;36m" << x << endl;
	cout << "\033[0m- \033[1;36my \033[0m: \033[1;36m" << y << endl;
	cout << "\033[0m- \033[1;36mz \033[0m: \033[1;36m" << z << endl;
	cout << "\033[1;32m--------------------\033[0m" << endl;
}

int main()
{
	double objectX,objectY,objectZ;
	cout << "\033[1;36mEnter Object #1 Values \033[0m:" << endl;
	cout << "\033[0m - \033[1;36mx \033[0m: "; cin >> objectX;
	cout << "\033[0m - \033[1;36my \033[0m: "; cin >> objectY;
	cout << "\033[0m - \033[1;36mz \033[0m: "; cin >> objectZ;
	Triple object1;
	Triple object2(9, 8, 7);
	Triple object3;
	object3.set(objectX, objectY, objectZ);

	cout << "Values of Object #2 Gained by Accessors" << endl;
	cout << "x : " << object2.xGet() << endl;
	cout << "y : " << object2.yGet() << endl;
	cout << "z : " << object2.zGet() << endl;

	cout << "\033[1;32m - \033[0mObject #1" << endl;
	object1.display();
	cout << "\033[1;32m - \033[0mObject #2" << endl;
	object2.display();
	cout << "\033[1;32m - \033[0mObject #3" << endl;
	object3.display();

	cout << endl;
	cout << "#3 = #1 + #2" << endl;
	object3 = object1 + object2;
	cout << "\033[1;32m - \033[0mObject #3" << endl;
	object3.display();

	cout << endl;
	cout << "#1 = #2" << endl;
	object1 = object2;
	cout << "\033[1;32m - \033[0mObject #1" << endl;
	object1.display();
	cout << "\033[1;32m - \033[0mObject #2" << endl;
	object2.display();

	cout << endl;
	cout << "#3 ++" << endl;
	object3++;
	cout << "\033[1;32m - \033[0mObject #3" << endl;
	object3.display();

	cout << "Last Output" << endl;
	cout << "\033[1;32m - \033[0mObject #1" << endl;
	object1.display();
	cout << "\033[1;32m - \033[0mObject #2" << endl;
	object2.display();
	cout << "\033[1;32m - \033[0mObject #3" << endl;
	object3.display();
	return 0;
}