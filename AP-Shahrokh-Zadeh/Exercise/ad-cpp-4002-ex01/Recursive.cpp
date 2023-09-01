#include <iostream>
using namespace std;

//prototype
int SumMultFunc(int,int,int);

int main()
{
	int x,y,sum=0,j=0;
	cout<<"\n\033[1;33mFrist Number :\t\033[0m";
	cin>>x;
	cout<<"\n\033[1;33mFrist Number :\t\033[0m";
	cin>>y;
	cout<<"\n\033[1;36mIterative Answer :\t\033[0m";
		for (int i=0;i<y;i++)
		{
			sum +=x;
		}
	cout<<sum;
	cout<<"\n\033[1;36mRecursive Answer :\t\033[0m";
	cout<<SumMultFunc(x,y,j);
}
int SumMultFunc(int n1, int n2, int j)
{
    if(n1==0) 
      return j;
    else
      return SumMultFunc(n1-1,n2,n2+j);
}