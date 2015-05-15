#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace::std;

int main()
{
	int n;
	long long limit;
	//cout<<"enter no of nos"<<endl;
	cin>>n;
	//cout<<"enter limit of random number"<<endl;
	cin>>limit;
	limit++;
	srand(time(NULL));
	for(int i=0;i<n;i++)
		cout<<rand()%limit<<" ";
}