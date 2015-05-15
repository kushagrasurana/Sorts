/* Count Sort (unstable version)
 * Time Complexity -
 * Worst case -- O(n)
 * Best case  -- O(n)
 * Avg Case   -- O(n)
 * Space Complexitty -- O(N+n), N is larget number of input
 */
#include <iostream>
#include <vector>
#include <climits>
using namespace::std;

void count_sort(vector <int> &in)
{
	int temp,i,j,k,min = INT_MAX,max = INT_MIN;
	/* find maximum and minimum of the input */
	for(i=0;i<in.size();i++)
	{
		if(in[i]>max)
			max=in[i];
		if(in[i]<min)
			min=in[i];
	}
	if((max-min)>10e7)
		cout<<"Data range is too high"<<endl;
	else
	{
		int count[max-min+1],j=0;
		for(i=0;i<max-min+1;i++)
			count[i]=0;
		for(i=0;i<in.size();i++)
			count[in[i]-min]++;
		for(i=0;i<(max-min+1);i++)
		{
			while(count[i])
			{
				in[j]=i+min;
				j++;
				count[i]--;
			}
		}
	}
}

int main()
{
	int n;
	cin>>n;
	vector<int> in;
	for(int i=0;i<n;i++)
	{
		int input;
		cin>>input;
		in.push_back(input);
	}
	count_sort(in);

	for(int i=0;i<n;i++)
		cout<<in.at(i)<<" ";

	cout<<endl;
	return 0;
}