
//don't use goto on ever cost
#include <iostream>
#define month 30
using namespace std;
class Account
{
	private :
		static int Client_ID;
		static char Client_Name[40];
		static double Client_Balance;
		static float Benefit;
	public :
		Account(int, double, char[40], float);
		Account();
		double Withdraw();
		double Deposit();
		double getBalance();
		double getBenef();
		double setBenef(double ben)
		{
			Benefit = ben;
			return 0;
		}
		~Account()
		{
			Client_ID = 0;
			for (int i = 0; i < sizeof(Client_Name); i++)
			{
				Client_Name[i] = '-';
			}
			Client_Balance = 0;
			Benefit = 0;
			cout<<endl;
		}
};

// problem 1 --> to give static you should define it via another function 
// problem 2 --> why in Account() i cant see given data ?
// - answer : because i should make all datas static so can go through functions
float Account::Benefit = 0;
double Account::Client_Balance = 0;
int Account::Client_ID = 0;
char Account::Client_Name[40] = "\0";
// and we cant type static in place of " int" 

//-- Constructor 1:
Account::Account(int ID, double Bal, char Name[40], float Benef)
{
	Client_ID = ID;
	strcpy(Client_Name, Name);
	Client_Balance = Bal;
	Benefit = Benef;
	//Tip : constructor only works 1 time when you define class and ceate and object
}

Account::Account()
{
	pos:
	cin.ignore();
	cout<<"\x1B[2J\x1B[H";
	cout<<endl;
	info :
	int x;
	cout<<"\033[1;33mOptions \033[0m:"<<endl;
	cout<<"\033[1;33m 1.\033[0m Withdraw"<<endl;
	cout<<"\033[1;33m 2.\033[0m Deposit"<<endl;
	cout<<"\033[1;33m 3.\033[0m Balance"<<endl;
	cout<<"\033[1;33m 4.\033[0m Benefit"<<endl;
	cout<<"\033[1;33m 5.\033[0m Exit"<<endl;
	cout<<"-\033[1;36m Choice\033[0m :\t"; cin>>x;
	switch(x)
	{
		case 1 :
			Withdraw();
			goto pos;
		break;
		case 2 :
			Deposit();
			goto pos;
		break;
		case 3 :
			getBalance();
			goto pos;
		break;
		case 4 :
			getBenef();
			goto pos;
		break;
		case 5 :
			goto end;
		break;
		default :
		cout<<"\x1B[2J\x1B[H";
		cout<<"\033[1;31m ERR :\033[0m We Don't Have Any Option Number "<<x<<" !"<<endl;
		cin.ignore();
		goto info;
	}	
	end:
	cout<<"\x1B[2J\x1B[H";
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"\033[1;36m██████╗░██╗░░░██╗███████╗          ██████╗░██╗░░░██╗███████╗"<<endl;
	cout<<"\033[1;36m██╔══██╗╚██╗░██╔╝██╔════╝          ██╔══██╗╚██╗░██╔╝██╔════╝"<<endl;
	cout<<"\033[1;36m██████╦╝░╚████╔╝░█████╗░░          ██████╦╝░╚████╔╝░█████╗░░\033[1;33m          Program Closed !"<<endl;
	cout<<"\033[1;36m██╔══██╗░░╚██╔╝░░██╔══╝░░          ██╔══██╗░░╚██╔╝░░██╔══╝░░"<<endl;
	cout<<"\033[1;36m██████╦╝░░░██║░░░███████╗          ██████╦╝░░░██║░░░███████╗"<<endl;
	cout<<"\033[1;36m╚═════╝░░░░╚═╝░░░╚══════╝          ╚═════╝░░░░╚═╝░░░╚══════╝"<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
}

//-- Options :

//- Withdraw :
double Account::Withdraw()
{
	cout<<"\x1B[2J\x1B[H";
	int payment;
	cout<<"\033[1;36mYour Balance Is\033[0m : \033[1;33m"<<Client_Balance<<endl;
	cout<<"\033[1;36m - \033[0mEnter Howmuch Do You Want To Withdraw \033[1;36m:\t"<<endl;
	cout<<" - \033[0m"; cin>>payment;
	if (payment > Client_Balance)
	{
		cout<<"\033[1;31m ERR :\033[0m You Don't Have Enough Money To Withdraw"<<endl;
		cin.ignore();
		return 0;
	}
	Client_Balance -= payment;
	cout<<"\033[1;32mDone !\033[0m"<<endl;
	cout<<"\033[1;36mYour Balance Is Now \033[0m: \033[1;33m"<<Client_Balance<<"\033[0m "<<endl;
	cout<<"\033[1;37mType Something To Close \033[1;36m:\033[0m\t";
	cin.ignore();
	return 0;
}

//- Deposite
double Account::Deposit()
{
	cout<<"\x1B[2J\x1B[H";
	int payment;
	cout<<"\033[1;36mYour Balance Is\033[0m : \033[1;33m"<<Client_Balance<<endl;
	cout<<"\033[1;36m - \033[0mEnter Howmuch Do You Want To Deposit \033[1;36m:\t"<<endl;
	cout<<" - \033[0m"; cin>>payment;
	if (payment < 0)
	{
		cout<<"\033[1;31m ERR :\033[0m You Can't Deposite Negative Amount"<<endl;
		cin.ignore();
		return 0;
	}
	Client_Balance += payment;
	cout<<"\033[1;32mDone !\033[0m"<<endl;
	cout<<"\033[1;36mYour Balance Is Now \033[0m: \033[1;33m"<<Client_Balance<<"\033[0m "<<endl;
	cout<<"\033[1;37mType Something To Close \033[1;36m:\033[0m\t";
	cin.ignore();
	return 0;
}

//- Balance
double Account::getBalance()
{
	float days;
	double bal = Client_Balance,bal2 = Client_Balance;
	cout<<"\x1B[2J\x1B[H";
	cout<<"\033[1;36mEnter Days \033[0m:\t\033[1;32m"; cin>>days;
	cout<<"\033[1;36mYour Balance Is Now \033[0m: \033[1;33m"<<Client_Balance<<endl;
	cout<<"\033[1;36mAfter Calculating Benefit..."<<endl;
	float x = days / 365;
	bal += (Benefit * bal) * x;
	bal2 = (Benefit * bal) * 30 / 365;
	cout<<"\033[1;36mYour Balance Will Be \033[0m: \033[1;33m"<<bal<<endl;
	cout<<"\033[1;36mMonthly Benefit is \033[0m:\033[1;32m\t"<<bal2<<endl;
	cout<<"\033[1;37mType Something To Close \033[1;36m:\033[0m\t";
	cin.ignore();
	return 0;
}

//-
double Account::getBenef()
{
	double ben;
	cout<<"\033[1;36mEnter Client Benefit (In Year) \033[0m:\t";
	cin>>ben;
	pos2 :
	if (ben > 1 || ben < 0)
	{
		cout<<"\033[1;31m ERR :\033[0m This Amount Of Benefit Isn't Our Option !"<<endl;
		cin.ignore();
		goto pos2;
	}
	setBenef(ben);
	return 0;
}




int main()
{
	int ID;
	double Bal;
	float Benef;
	char Name[40];
	cout<<"\033[1;33mWelcome ! Please Enter Info"<<endl;

	//-- Client Name :
	cout<<"\033[1;36mEnter Client Name \033[0m:\t";
	cin.getline(Name, sizeof(Name));
	cout<<endl;

	//-- Client ID :
	cout<<"\033[1;36mEnter Client ID \033[0m:\t";
	cin>>ID;
	cout<<endl;

	//-- Client Balance :
	pos1:
	cout<<"\033[1;36mEnter Client Balance \033[0m:\t";
	cin>>Bal;
	if (Bal < 0)
	{
		cout<<"\033[1;31m ERR :\033[0m Balance Can't Be Negative !"<<endl;
		cin.ignore();
		goto pos1;
	}
	cout<<endl;

	//-- Class Use :
	Account Client(ID,Bal,Name,Benef);
	Account Money;
}