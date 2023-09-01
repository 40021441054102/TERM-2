#include <iostream>
using namespace std;
//sum of matrix cordinates
int main()
{
	int x = 3,y = 5;
	int mat[x][y],max = mat[0][0],i,ip,sum;
	cout<<"give me numbers of 3x5 matrix :"<<endl;
	cout<<"-----"<<endl;
	for(int i = 0; i < x; i++)
	{
		for(int ip = 0; ip < y; ip++)
		{
			cin>>mat[i][ip];
			if(mat[i][ip] > max)
			{
                max = mat[i][ip];
				sum = i + ip + 2;
			}
		}
		cout<<"-----"<<endl;
	}
	cout<<"\033[1;31mmaximum number is : "<<max<<endl;
	cout<<"\033[1;31msum of its cordinates : "<<sum;
	return 0;
}