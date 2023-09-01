#include <iostream>
#include <string>
using namespace std;

class Computer
{
	protected:
		double price;
		double weight;
		string brand;
		string model;
	public:
		Computer();
		~Computer();
};

Computer::Computer()
{
	price = 1;
	weight = 1;
	brand = "Apple";
	model = "MVVK2";
}

Computer::~Computer()
{
	price = 0;
	weight = 0;
	brand = " ";
	model = " ";
}

class Laptop : public Computer
{
	private:
		double battery;
	public:
		Laptop();
		~Laptop();
		void disp1();
};

Laptop::Laptop()
{
	price = 3000;
	weight = 1.2;
	brand = "Apple";
	model = "MVVK2";
	battery = 100;
}

Laptop::~Laptop()
{
	battery = 0;
}

void Laptop::disp1()
{
	cout << endl;
	cout << "-- Laptop :" << endl;
	cout << "- price : " << price << endl;
	cout << "- weight : " << weight << endl;
	cout << "- brand : " << brand << endl;
	cout << "- model : " << model << endl;
	cout << "- battery : " << battery << endl;
}

class Desktop : public Computer
{
	private:
		string monitor;
	public:
		Desktop();
		~Desktop();
		void disp2();
};

Desktop::Desktop()
{
	price = 5000;
	weight = 3.4;
	brand = "Apple";
	model = "MVVN1";
	monitor = "Retina";
}

Desktop::~Desktop()
{
	monitor = " ";
}

void Desktop::disp2()
{
	cout << endl;
	cout << "-- Desktop :" << endl;
	cout << "- price : " << price << endl;
	cout << "- weight : " << weight << endl;
	cout << "- brand : " << brand << endl;
	cout << "- model : " << model << endl;
	cout << "- monitor : " << monitor << endl;
}

int main()
{
	Laptop Mac;
	Desktop iMac;
	Mac.disp1();
	iMac.disp2();
	return 0;
}