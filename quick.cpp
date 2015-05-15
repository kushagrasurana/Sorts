/* Iterative quick Sort
 * Time Complexity -
 * Worst case -- O(n^2)
 * Best case  -- O(n)
 * Avg Case   -- O(nlogn)
 * Space Complexitty -- O(n)
 */
#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace::std;

void quick_sort(vector<int> &in)
{
	int i,j,k,temp,l,r,p,low,high;
	stack<pair<int,int> > calls;
	calls.push(make_pair(0,in.size()-1)); // initial function call, covering the whole array
	while(!calls.empty())
	{
		low = calls.top().first;
		high = calls.top().second;
		if(low>=high)
		{
			cout<<"invalid"<<calls.top().first<<">="<<calls.top().second<<endl;
			calls.pop();
			
			continue;
		}
		p=low; // make first element as pivot
		r=high;
		cout<<"p,r="<<p<<" "<<r<<endl;
		l=p+1;
		while(l<r)
		{
			while(in[l]<in[p] && l<high)
				l++;
			while(in[r]>=in[p] && r>low)
				r--;
			cout<<"swap"<<l<<"with"<<r<<endl;
			if(l<r)
			{
				temp=in[r];
				in[r]=in[l];
				in[l]=temp;
			}
		}
		temp = in[p];
		in[p]=in[r];
		in[r]=temp;
		cout<<"gives the array"<<endl;
		for(int x=0;x<in.size();x++)
			cout<<in[x]<<" ";
		cout<<endl;
		calls.pop();
		calls.push(make_pair(low,r-1));
		calls.push(make_pair(r+1,high));
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
	quick_sort(in);
	cout<<"Sorted output is"<<endl;

	for(int i=0;i<n;i++)
		cout<<in.at(i)<<" ";

	cout<<endl;
	return 0;
}