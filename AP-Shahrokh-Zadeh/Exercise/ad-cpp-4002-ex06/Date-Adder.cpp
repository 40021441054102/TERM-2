#include <iostream>

using namespace std;

class convertDate
{
    int _year;
    int _month;
    int _day;
    public:
        //- Constructive
        convertDate();
        convertDate(int, int, int);
        convertDate(const convertDate &);
        //- Destructor
        ~convertDate();
        //- Operator
        convertDate operator+(int &);
        //- Methods
        void getDate();
        void showDate();
};

convertDate::convertDate()
{
    _year = 1400;
    _month = 1;
    _day = 1;
}

convertDate::convertDate(int usrYear, int usrMonth, int usrDay)
{
    _year = usrYear;
    if (usrMonth > 0 && usrMonth < 13)
    {
        _month = usrMonth;
    }
    else
    {
       _month = 1;
    }
    if (_month < 7)
    {
        if (usrDay > 0 && usrDay < 32)
        {
            _day = usrDay;
        }
        else
        {
            _day = 1;
        }
    }
    else
    {
        if (usrDay > 0 && usrDay < 31)
        {
            _day = usrDay;
        }
        else 
        {
            _day = 1;
        }
    }

}

convertDate::convertDate(const convertDate &_date)
{
    _year = _date._year;
    _month = _date._month;
    _day = _date._day;
}

convertDate::~convertDate()
{
    cout << endl << "Object Died" << endl;
}


void convertDate::getDate()
{
    cout << "Year ? "; cin >> _year;
    cout << "Month ? "; cin >> _month;
    cout << "Day ? "; cin >> _day;
}

void convertDate::showDate()
{
    cout << "\033[1;96mYour Time is \033[0m:\033[1;32m";
    cout << endl << _year << " - " << _month << " - " << _day << "\033[0m" << endl; 
}

convertDate convertDate::operator+(int &usrNum)
{
    int _temp = _day + usrNum;
    if (_month >= 1 || _month <= 6)
    {
        this->_day = _temp;
        this->_month = _temp / 31 + _month;
        this->_day = _temp % 31;
    }
    else
    {
        this->_day = _temp;
        this->_month = _temp / 30 + _month;
        this->_day = _temp % 30;
    }
    return *this;
}

int main()
{
	convertDate t1, t2;
	t1.getDate();
	int usrNum;
	cout<<"\033[1;33mEnter Howmuch You Want to Add \033[0m:\033[1;36m "; cin >> usrNum;
	t2 = t1 + usrNum;
    cout << endl;
	cout << " \033[0m-\033[1:96m Before \033[0m:" << endl;
	t1.showDate();
	cout << "\033[0m-\033[1:96m After \033[0m:" << endl;
	t2.showDate();
	return 0;
}

