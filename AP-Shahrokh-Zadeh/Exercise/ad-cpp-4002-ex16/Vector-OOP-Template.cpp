#include <iostream>
using namespace std;

template <class __type>
class Vector
{
	private:
		__type *vector;
		int size;
	public:
		Vector();
		Vector(int);
		~Vector();
		void set();
		void display();
};

template <class __type>
Vector<__type>::Vector()
{
	vector = 0;
	size = 0;
}

template <class __type>
Vector<__type>::Vector(int _size)
{
    size = _size;
    vector = new __type[size];
}

template <class __type>
Vector<__type>::~Vector()
{
	delete [] vector;
}

template <class __type>
void Vector<__type>::set()
{
	cout << "\033[1;36mArray Size\033[0m : "; cin >> size;
	cout << "\033[1;32mEnter Inputs\033[0m :" << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> vector[i];
	}
}

template <class __type>
void Vector<__type>::display()
{
	for (int i = 0; i < size; i++)
	{
		cout << vector[i] << " ";
	}
}

int main()
{
	Vector <float> object1(1);
	object1.set();
	object1.display();
	Vector <int>object2(1);
	object2.set();
	object2.display();
}