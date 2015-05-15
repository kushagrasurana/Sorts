/* Selection Sort
 * sequence - hi = [2.25*hi-1], h1 = 1
 * Time Complexity -
 * Worst case -- O(n^2)
 * Best case  -- O(nlog^2n)
 * Avg Case   -- unkown, better than n^2
 * Space Complexitty -- O(n)
 */
#include <iostream>
#include <vector>
using namespace::std;

void shell_sort(vector <int> &in)
{
	int temp,i,j,k,h=1;
	vector<int> gap;
	while(h<in.size())
	{
		gap.push_back(h);
		h = static_cast<int>(2.25*h);
	}
	for(k=gap.size()-1;k>=0;k--)
	{
		h=gap[k];
		for(i=h;i<in.size();i++)
		{
			j=i;
			while(j>=h && in[j]<in[j-h])
			{
				temp = in[j];
				in[j] = in[j-h];
				in[j-h] = temp;
				j-=h;
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
	shell_sort(in);

	for(int i=0;i<n;i++)
		cout<<in.at(i)<<" ";

	cout<<endl;
	return 0;
}