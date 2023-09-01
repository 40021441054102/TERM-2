#include <iostream>
using namespace std;

class Student
{
	private:
		long double SNO;
	public:
		long double accessSNO();
		Student()
		{
			SNO = 40021441054102;
		}
};

class Test
{
	private:
		int Mark;
	public:
		int accessMark();
		Test()
		{
			Mark = 18;
		}
};

class Sports
{
	private:
		int Score;
	public:
		int accessScore();
		Sports()
		{
			Score = 40;
		}
};

class Result : public Test, public Sports
{
	private:
		int total;
	public:
		void Display();
};

long double Student::accessSNO()
{
	return SNO;
}

int Test::accessMark()
{
	return Mark;
}

int Sports::accessScore()
{
	return Score;
}

void Result::Display()
{
	Student st;
	Sports sp;
	Test t;
	total = sp.accessScore() + t.accessMark();
	cout << st.accessSNO() << endl;
	cout << t.accessMark() << endl;
	cout << sp.accessScore() << endl;
	cout << total << endl;
}

int main()
{
	Result res;
	res.Display();
	return 0; 
}