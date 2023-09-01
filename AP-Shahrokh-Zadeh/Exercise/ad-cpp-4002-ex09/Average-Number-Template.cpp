#include <iostream>

using namespace std;

template <typename average>
average avgFunction(average input[10], int length)
{
	average base = 0;
	for (int i = 0; i < length; i++)
	{
		base = base + input[i];
	}
	return (base / length);
}

int main()
{
	int length;
	cout << "\033[1;36mPlease Enter Howmany Numbers Do You Want to Average \033[0m:" << endl;
	cin >> length;
	double array[length];
	cout << "\033[1;36mEnter Numbers (Type Space Between Them)\033[0m:" << endl;
	for (int i = 0; i < length; i++)
	{
		cin >> array[i];
	}
	cout << "\033[1;36mAverage is \033[0m:\033[1;96m " << avgFunction(array, length) << endl;
	return 0;
}
