#include <iostream>
using namespace std;

//prototype
int BMMFunc(int,int);

int main()
{
	int r=1,BMM,num2;
	cout<<"\n\033[1;33mFrist Number :\t\033[0m";
	cin>>BMM;
	cout<<"\n\033[1;33mSecond Number :\t\033[0m";
	cin>>num2;
	cout<<"\n\033[1;36mBMM :\t\033[0m"<<BMMFunc(BMM,num2);
	// by Ramtin.qb
	cin.ignore();	
}

int BMMFunc(int BMM, int num2)
{
	if(num2==0){
		return BMM;
	}
	else{
		return BMMFunc(num2,BMM%num2);
	}
}



