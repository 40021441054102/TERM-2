#include <iostream>
#include <string.h>
using namespace std;

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// in barname ebteda vorudi ra be horufe kuchak tabdil karde ta be size horuf hasas nabashad
// pas az an vorudi ra reverse karde va character be character ba vorudi ghable moghayese mikonad
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

//prototypes
int lowercase(char []);
int palindromic_check(char []);

//main function
int main()
{
	char input[200],ref[200];
	cout<<"\n\033[1;93mWelcome \t\033[0m";
	cout<<"\n\033[1;33mPlease Enter Your Word or Sentence : \t\033[0m";
	cin.getline(input,200);
	palindromic_check(input);
	return 0;
}

//palindromic checker function
int palindromic_check(char input[])
{
	int count_1,count_2,count;
	char temp,ref[200];
	lowercase(input);
	count_1 = strlen(input) - 1;
	count = strlen(input) - 1;
	strcpy(ref,input);
	for (count_2 = 0; count_2 < count_1; count_2++,count_1--)
	{
		temp = input[count_2];
		input[count_2] = input[count_1];
		input[count_1] = temp;
	}
	cout<<"\n\033[1;94mregular input --> "<<ref;
	cout<<"\n\033[1;94mreversed input --> "<<input;
	int i = 0,point = 0;
	while (i < count)
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
	}
	if (point == count)
	{
		cout<<"\n\033[1;92mfortunately it is palindromic !\033[0m";
	}
	else
	{
		cout<<"\n\033[1;91munfortunately it isn't palindromic !\033[0m";
	}
	return 0;
}

//lowercase function
int lowercase(char input[])
{
	for (int i = 0; i < strlen(input); i++)
	{
		if ('A' <= input[i] && input[i] <= 'Z')
		{
			input[i] += 32;
		}
	}
	return 0;
}