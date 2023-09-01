#include <iostream>
#include <string.h>
using namespace std;

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// in barname ebteda vorudi ra be horufe kuchak tabdil karde ta be size horuf hasas nabashad
// pas az an vorudi ra reverse karde va character be character ba vorudi ghable moghayese mikonad
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

//prototypes
int lowercase(char [], int);
int reverser(char [], int, int, char);
int palindromic_check(char [], int, int, int, char []);

//main function
int main()
{
	char input[200],ref[200];
	cout<<"\n\033[1;93mWelcome \t\033[0m";
	cout<<"\n\033[1;33mPlease Enter Your Word or Sentence : \t\033[0m";
	cin.getline(input,200);
	lowercase(input,0);
	strcpy(ref,input);
	char temp;
	int count_1 = strlen(input) - 1;
	int count = count_1 ;
	reverser(input,count_1,0,temp);
	cout<<"\n\033[1;32mLowerCasing ...";
	cout<<"\n\033[1;94mregular input --> "<<ref;
	cout<<"\n\033[1;94mreversed input --> "<<input;
	palindromic_check(input,count,0,0,ref);
	return 0;
}

//palindromic checker function
int palindromic_check(char input[], int count, int point, int i, char ref[])
{
	/*
	Debugger :
		cout<<endl;
		cout<<input<<endl;
		cout<<count<<endl;
		cout<<point<<endl;
		cout<<i<<endl;
		cout<<ref<<endl;
	*/
	if (i > count)
	{
		if (point == count + 1)
		{
			cout<<"\n\033[1;32m\n░░░░░░░░░░░░▄▄ \033[0m"<<"";
			cout<<"\033[1;32m\n░░░░░░░░░░░█░░█ \033[0m"<<"";
			cout<<"\033[1;32m\n░░░░░░░░░░░█░░█ \033[0m"<<"";
			cout<<"\033[1;32m\n░░░░░░░░░░█░░░█ \033[0m"<<"";
			cout<<"\033[1;32m\n░░░░░░░░░█░░░░█ \033[0m"<<"";
			cout<<"\033[1;32m\n███████▄▄█░░░░░██████▄ \033[0m"<<"";
			cout<<"\033[1;32m\n▓▓▓▓▓▓█░░░░░░░░░░░░░░█ \033[0m"<<"";
			cout<<"\033[1;32m\n▓▓▓▓▓▓█░░░░░░░░░░░░░░█ \033[0m"<<"";
			cout<<"\033[1;32m\n▓▓▓▓▓▓█░░░░░░░░░░░░░░█ \033[0m"<<"";
			cout<<"\033[1;32m\n▓▓▓▓▓▓█░░░░░░░░░░░░░░█ \033[0m"<<"";
			cout<<"\033[1;32m\n▓▓▓▓▓▓█░░░░░░░░░░░░░░█ \033[0m"<<"";
			cout<<"\033[1;32m\n▓▓▓▓▓▓█████░░░░░░░░░█ \033[0m"<<"";
			cout<<"\033[1;32m\n██████▀░░░░▀▀██████▀ \033[0m"<<"";
			cout<<"\n\n\033[1;92mfortunately it is palindromic !\033[0m";
		}
		else
		{
			cout<<"\n\033[1;31m\n███████▄▄███████████▄ \033[0m"<<"";
			cout<<"\033[1;31m\n▓▓▓▓▓▓█░░░░░░░░░░░░░░█ \033[0m"<<"";
			cout<<"\033[1;31m\n▓▓▓▓▓▓█░░░░░░░░░░░░░░█ \033[0m"<<"";
			cout<<"\033[1;31m\n▓▓▓▓▓▓█░░░░░░░░░░░░░░█ \033[0m"<<"";
			cout<<"\033[1;31m\n▓▓▓▓▓▓█░░░░░░░░░░░░░░█ \033[0m"<<"";
			cout<<"\033[1;31m\n▓▓▓▓▓▓█░░░░░░░░░░░░░░█ \033[0m"<<"";
			cout<<"\033[1;31m\n▓▓▓▓▓▓███░░░░░░░░░░░░█ \033[0m"<<"";
			cout<<"\033[1;31m\n██████▀░░█░░░░██████▀ \033[0m"<<"";
			cout<<"\033[1;31m\n░░░░░░░░░█░░░░█ \033[0m"<<"";
			cout<<"\033[1;31m\n░░░░░░░░░░█░░░█ \033[0m"<<"";
			cout<<"\033[1;31m\n░░░░░░░░░░░█░░█ \033[0m"<<"";
			cout<<"\033[1;31m\n░░░░░░░░░░░█░░█ \033[0m"<<"";
			cout<<"\033[1;31m\n░░░░░░░░░░░░▀▀ \033[0m"<<"";
			cout<<"\n\n\033[1;91munfortunately it isn't palindromic !\033[0m";
		}
		return 0;
	}
	else
	{
		if (ref[i] == input[i])
		{
			point++;
		}
		else
		{
			point--;
		}
		i++;
		return palindromic_check(input, count, point, i, ref);
	}
}

//reverser function
int reverser(char input[], int c1, int c2, char temp)
{	
	if (c2 > strlen(input)/2 - 1)
	{
		return 0;
	}
	else
	{
		temp = input[c2];
		input[c2] = input[c1];
		input[c1] = temp;
		c2++;
		c1--;
		reverser(input,c1,c2,temp);
	}
	return 0;
}

//lowercase function
int lowercase(char input[], int i)
{
	if (i > strlen(input) - 1)
		return 0;
    else 
    {
        if ('A' <= input[i] && input[i] <= 'Z')
        {
            input[i] += 32;
        }
        i++;
        return lowercase(input,i);
    }
}