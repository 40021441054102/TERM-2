#include <iostream>

using namespace std;

template <typename summation>
summation sumFunction(summation input[10], int length)
{
	summation base = 0;
	for (int i = 0; i < length; i++)
	{
		base = base + input[i];
	}
	return base;
}

int main()
{
	int length;
	cout << "\033[1;36mPlease Enter Howmany Numbers Do You Want to Sum \033[0m:" << endl;
	cin >> length;
	double array[length];
	cout << "\033[1;36mEnter Numbers (Type Space Between Them)\033[0m:" << endl;
	for (int i = 0; i < length; i++)
	{
		cin >> array[i];
	}
	cout << "\033[1;36mSummation is \033[0m:\033[1;96m " << sumFunction(array, length) << endl;
	return 0;
}
