/* Selection Sort
 * Time Complexity -
 * Worst case -- O(n^2)
 * Best case  -- O(n^2)
 * Avg Case   -- O(n^2)
 * Space Complexitty -- O(n)
 */
#include <iostream>
#include <vector>
#include <climits>
using namespace::std;

void selection_sort(vector<int> &in)
{
	int temp,max,maxi,j;
	for(int i=0;i<in.size();i++)
	{
		max=INT_MIN;
		for(j=0;j<in.size()-i;j++)
		{
			if(in[j]>max)
			{
				max=in[j];
				maxi=j;
			}
		}
		temp = in[maxi];
		in[maxi] = in[j-1];
		in[j-1] = temp;
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
	selection_sort(in);

	for(int i=0;i<n;i++)
		cout<<in.at(i)<<" ";

	cout<<endl;
	return 0;
}