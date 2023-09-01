#include <iostream>
#include <string>
using namespace std;
//struct
//t stands for time
struct time{
	int h; //stands for hour
	int m; //stands for minute
	int s; //stands for seconds
};
//main function
int main()
{
	struct time t;
	int err = 0;
	cout<<"\n\033[1;92mGive me time inputs \033[0m: ";
	cout<<"\n Hour : ";
	cin>>t.h;
	cout<<"\n Minute : ";
	cin>>t.m;
	cout<<"\n Second : ";
	cin>>t.s;
	cout<<"\n";
	if (t.h > 23 || t.h < 0)
	{
		cout<<"\033[1;31minvalid \033[1;36mhour\033[1;31m data input : "<<"\033[1;36m "<<t.h<<"\033[1;33m:\033[1;37m"<<t.m<<"\033[1;33m:\033[1;37m"<<t.s<<endl;
		err++;
	}
	if (t.m > 59 || t.m < 0)
	{
		cout<<"\033[1;31minvalid \033[1;36mminute\033[1;31m data input : "<<"\033[1;37m "<<t.h<<"\033[1;33m:\033[1;36m"<<t.m<<"\033[1;33m:\033[1;37m"<<t.s<<endl;
		err++;
	}
	if (t.s > 59 || t.s < 0)
	{
		cout<<"\033[1;31minvalid \033[1;36msecond\033[1;31m data input : "<<"\033[1;37m "<<t.h<<"\033[1;33m:\033[1;37m"<<t.m<<"\033[1;33m:\033[1;36m"<<t.s<<endl;
		err++;
	}
	if (err > 0)
	return 0;
	cout<<"\033[1;92minputs are correct ! \n";
	cout<<"\033[1;32mloading ...\033[0m\n";
	//24h format
	cout<<"\n\033[1;36m24h format\033[0m :\n";
	cout<<"\033[1;37m "<<t.h<<"\033[1;33m:\033[1;37m"<<t.m<<"\033[1;33m:\033[1;37m"<<t.s;
	//AM - PM format
	cout<<"\n\n\033[1;36mAM - PM format\033[0m :\n";
	if (t.h < 13)
	{
		cout<<"\033[1;37m "<<t.h<<"\033[1;33m:\033[1;37m"<<t.m<<"\033[1;33m:\033[1;37m"<<t.s<<"\033[1;36m AM";
	}
	if (t.h > 12)
	{
		t.h -= 12;
		cout<<"\033[1;37m "<<t.h<<"\033[1;33m:\033[1;37m"<<t.m<<"\033[1;33m:\033[1;37m"<<t.s<<"\033[1;36m PM";
	}
	cout<<endl;
	cin.ignore();

}