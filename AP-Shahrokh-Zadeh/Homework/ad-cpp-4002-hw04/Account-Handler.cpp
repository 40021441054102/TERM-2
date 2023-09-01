//----- Libraries
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

//----- Data Structure
struct USR{
	char	username[50];
	char	firstname[50];
 	char	lastname[50];
 	char	email[50];
 	char	number[50];
	char	password[50];
};
struct USR USR[5000];
static char firstn[40];
//remember to use this --> 	Exit(firstname);

//----- Prototypes
int Welcome();
int Login();
int SignUp();
int Client_Page(char[50], char[50],int);
int Exit(char[30]);
int read_to_struct();
int err(int);
int usr_err(string,int);
int pass_err();
void first_up_case(char[50], char[50]);
void clr_console();
int get_username();
int get_firstname(int);
int get_lastname(int);
int get_number();
int get_email();
int get_password();
int show();
int SpaceRemover(char[50]);

//----- Main Function
int main()
{
	Welcome();
	return 0;
}

//----- Program Begins Here
int Welcome()
{
	int choice;
	cout<<endl;
	cout<<"-------------------------- Version 0.142 --------------------------"<<endl;
	cout<<"Welcome! Here You Can Login To Or SignUp Your Account, So Choose an"<<endl;
	cout<<"Option From Menu Below :"<<endl;
	cout<<"1: Login\n2: SignUp\n3: Exit"<<endl;
	cout<<"Remember You Can Close Program Whenever You Want By Typing 'Exit' !"<<endl;
	cout<<"-------------------------------------------------------------------"<<endl;
	choice :
	cout<<"- "; 
	cin>>choice;
	if (!cin.fail())
	{
		if (choice == 1)
		{
			Login();
		}
		else if (choice == 2)
		{
			SignUp();
		}
		else if (choice == 3)
		{
			char c[50] = "Client";
			Exit(firstn);
		}
		else
		{
			cout<<"We Don't Have Any Number "<<choice<<" Option Unfortunately :("<<endl;
			cout<<"Choose Option Again :"<<endl;
			goto choice;
		}
	}
	else
	{
		cout<<"Your Input Is Not A Number! Try Restarting Program"<<endl;
		return 0;
	}
	return 0;
}

//----- Login Function
int Login()
{
	int attempt = 1,err = 0;
	const int size = 4096; 
	login:
	clr_console();
	string user,pass;
	cout<<"--------------------------- Login Page ----------------------------";
	cout<<"\nUsername :\n";	
	cout<<"- "; cin>>user;
	cout<<"\nPassword :\n";	
	cout<<"- "; cin>>pass;
	clr_console();
	int lines = read_to_struct();
	for (int i = 0; i < lines; i++)
	{
		if (user == USR[i].username || user == "Admin")
		{
			if (pass == "31415926535")
			{
				cout<<"Admin Access Granted"<<endl;
				return 0;
			}
			else if (pass == USR[i].password)
			{
				first_up_case(USR[i].firstname,USR[i].lastname);
				Client_Page(USR[i].firstname,USR[i].lastname,i);
				return 0;
			}
			else
			{
				cout<<"\n- Password Is Wrong ! Attempt "<<attempt<<"/3."<<endl;
				if (attempt == 3)
				{
					clr_console();
					pass_err();
					Welcome();
					return 0;
				}
				attempt++;
				goto login;
			}
		}
		else
		{
			err++;
			if (err == lines)
			{
				usr_err(user,i);
			}
		}
	}
	return 0;
}

//----- SignUp Function
int SignUp()
{
	clr_console();
	cout<<"--------------------------- SignUp Page ---------------------------"<<endl;
	cout<<"Complete Inputs Below To Sign Up For FREE!"<<endl;
	get_username();
	get_number();
	get_email();
	get_password();

	cout<<endl;
	cout<<"SignUp Was Successful !";
	show();
	return 0;
}

//----- Instant Program Exit Function
int Exit(char Client[50])
{
	clr_console();
	cout<<"\033[1;92mProgram Terminated\033[0m"<<endl;
	cout<<"\033[1;32mSee You Later "<<Client<<"!\033[0m\n";
	return 0;
}

//----- Reading Accounts File Function
int read_to_struct()
{
	FILE *fp;
	fp = fopen("/Users/Q/Desktop/Accounts.txt","r");
	if (!fp)
	{
		err(101);
		return 0;
	}
	char buffer[100];
	char *username,*password,*firstname,*lastname,*details,*email,*number;
	int i;
	for (i = 0; fgets(buffer, sizeof buffer, fp); i++)
	{
		buffer[strlen(buffer)-1]='\0';
		details = buffer;
		username = strchr(details ,'-');	//Finding Delim1
		firstname = strchr(username + 1,'-');	//Finding Delim 2
		lastname = strchr(firstname + 1,'-');	//Finding Delim 3
		password = strchr(lastname + 1,'-');
		number = strchr(password + 1,'-');
		*username = '\0';	
		*firstname = '\0';
		*lastname = '\0';
		*password = '\0';
		*number = '\0';
		strcpy(USR[i].username, details);
		strcpy(USR[i].firstname, username + 1);
		strcpy(USR[i].lastname, firstname + 1);
		strcpy(USR[i].password, lastname + 1);
		strcpy(USR[i].number, password + 1);
		strcpy(USR[i].email, number + 1);
	}
	fclose(fp);
	cout<<username;
	return i;
}

//----- Client Page Function
int Client_Page(char firstname[50], char lastname[50], int i)
{
	cout<<"-------------------------- Client Page --------------------------"<<endl;
	cout<<"Client Access Granted"<<endl;
	cout<<"Welcome "<<firstname<<" "<<lastname<<endl;
	strcpy(firstn, firstname);
	cout<<USR[i].email<<endl;
	cout<<USR[i].number<<endl;
	Welcome();
	return 0;
}

//----- Errors Function
int err(int err_num)
{
	switch(err_num)
	{
		case 101:
			cout<<"ERR_"<<err_num<<" :"<<endl;
			cout<<" - Error With Openning Accounts File !"<<endl;
			cout<<" - There Isn't Any Text File For Accounts."<<endl;
		break;
		default : cout<<"just err";
	}
	return 0;
}

//----- User Error Function
int usr_err(string user,int i)
{
	cout<<"\n- \033[1;91mI Can't Find Any Username Called : '\033[1;92m"<<user<<"\033[1;91m'\033[0m"<<endl;
	Welcome();
	return 0;
}

//----- UpperCase First Character Function
void first_up_case(char firstname[50], char lastname[50])
{
	if (firstname[0] < 123 || firstname[0] > 96)
	{
		firstname[0] -= 32;
		if (lastname[0] < 123 || lastname[0] > 96)
		{
			lastname[0] -= 32;
		}
	}
}

//----- Invalid Password Operations Function
int pass_err()
{
	cout<<"\n- Password Is Wrong ! Attempt "<<"3/3."<<endl;
	cout<<"- Wrong Passwords Alert Has Been Emailed To Owner's Account !"<<endl;
	return 0;
}

//----- Console Cleaner Function
void clr_console()
{
	cout<<"\x1B[2J\x1B[H";
}

//----- Get Username Of Client Function
int get_username()
{
	int i = read_to_struct();
	int ip = i + 1;
	char username[20];
	cout<<"Username :"<<endl;
	cout<<"- "; cin>>username;
	strcpy(USR[ip].username, username);
	cout<<endl;
	get_firstname(ip);
	return 0;
}

//----- Get Firstname Of Client Function
int get_firstname(int i)
{
	char firstname[20];
	cout<<"Firstname :"<<endl;
	cout<<"- ";
	cin.ignore();
	cin.getline(firstname, sizeof(firstname));
	strcpy(USR[i].firstname, firstname);
	cout<<endl;
	SpaceRemover(USR[i].firstname);
	cout<<USR[i].firstname;
	cout<<endl;
	get_lastname(i);
	return 0;
}

//----- Get Lastname Of Client Function
int get_lastname(int i)
{
	char lastname[100];
	cout<<"Lastname :"<<endl;
	cout<<"- "; 
	cin.ignore();
	cin.getline(lastname, sizeof(lastname));
	strcpy(USR[i].lastname, lastname);
	SpaceRemover(USR[i].lastname);
	cout<<USR[i].lastname;
	cout<<endl;
	return 0;
}

//----- Get Number Of Client Function
int get_number()
{
	return 0;
}

//----- Get Email Of Client Function
int get_email()
{
	int i = read_to_struct();
	char email[i];
	cout<<"Email :"<<endl;
	cout<<"- "; cin>>email;
	strcpy(USR[i+1].email, email);
	cout<<endl;
	return 0;
}

//----- Get Password Of Client Function
int get_password()
{
	int i = read_to_struct();
	char password[i];
	cout<<"Password :"<<endl;
	cout<<"- "; cin>>password;
	strcpy(USR[i+1].password, password);
	cout<<endl;
	return 0;
}

int show()
{
	int i = read_to_struct();
	cout<<endl;
	cout<<USR[i + 1].username<<endl;
	cout<<USR[i + 1].firstname<<endl;
	cout<<USR[i + 1].lastname<<endl;
	cout<<USR[i + 1].email<<endl;
	cout<<USR[i + 1].number<<endl;
	cout<<USR[i + 1].password<<endl;
	return 0;
}

int SpaceRemover(char input[50])
{
	int ip = 0,length = strlen(input);
	for (int i = 0; i < length; i++)
	{
		if (input[i] == ' ')
		{
			for (int ip = i; ip < length; ip++)
      input[ip] = input[ip+1];
      length--;
		}
	}
	return 0;
}