#include <iostream>
using namespace std;

template <class d>
class Points
{
	private:
		d x,y;
	public:
		void display()
		{
			cout << "\033[1;36m- X \033[0m" << x << endl;
			cout << "\033[1;36m- Y \033[0m" << y << endl;
		}
		void set(d _x, d _y)
		{
			x = _x;
			y = _y;
		}
		void swapValues()
		{
			d temp;
			temp = x;
			x = y;
			y = temp;
		}
};

int main()
{
	Points <double>object;
	double x,y;
	cout << "\033[1;36mEnter X and Y of Your Point\033[0m : " << endl;
	cout << "\033[1;36m- X \033[0m"; cin >> x;
	cout << "\033[1;36m- Y \033[0m"; cin >> y;
	object.set(x, y);
	object.swapValues();
	object.display();
	cout << endl;
	return 0;
}