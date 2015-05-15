/* Selection Sort
 * Time Complexity -
 * Worst case -- O(n^2)
 * Best case  -- O(n)
 * Avg Case   -- O(n^2)
 * Space Complexitty -- O(n)
 */
#include <iostream>
#include <vector>
#include <climits>
using namespace::std;

void insertion_sort(vector <int> &in)
{
	int temp,i,j,k;
	for(int i=1;i<in.size();i++)
	{
		j=i;
		while(j>0 && in[j]<in[j-1] )
		{
			temp = in[j];
			in[j] = in[j-1];
			in[j-1] = temp;
			j--;
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
	insertion_sort(in);

	for(int i=0;i<n;i++)
		cout<<in.at(i)<<" ";

	cout<<endl;
	return 0;
}