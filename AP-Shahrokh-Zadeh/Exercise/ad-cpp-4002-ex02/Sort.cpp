#define ssize 3
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
//struct
struct emp{
	char *name;
	char *family;
	int salary;
};
//main function
int main()
{
	emp s[ssize];
	int temp;
	for (int i = 0; i < ssize; i++)
	{
		cout<<"\n\033[1;36memployee\033[0m #"<< (i+1) <<"\n\n";
		s[i].name = new char[21];
		cout<<"name : "; 
		cin>>s[i].name;
		s[i].family = new char[21];
		cout<<"family : "; 
		cin>>s[i].family;
		cout<<"salary : "; 
		cin>>s[i].salary;
	}
	for(int ip = 0 ;ip < ssize - 1; ip++)
	{
		for(int iq = 0; iq < ssize - 1;iq++)
		{
			if(s[iq].salary > s[iq+1].salary)
			{
				temp = s[iq].salary;
				s[iq].salary = s[iq+1].salary;
				s[iq+1].salary = temp;
			}
		}
	}
	cout<<"\n\033[1;32mlist of salaries \033[0m:\n\n";
	for(int i = 0; i < ssize; i++)
	{
		cout<<"\033[1;36m "<<s[i].name<<"\033[1;36m "<<s[i].family<<"\033[1;30m \033[0mwith salary of \033[1;33m"<<s[i].salary<<"\033[1;36m \033[0mhas the rank of \033[1;32m#"<<(i+1)<<endl;
	}
	cin.ignore();
}
