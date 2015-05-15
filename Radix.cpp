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

void radix_sort(vector<int> &in)
{
	int temp,max,maxi,j;
	
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
	radix_sort(in);

	for(int i=0;i<n;i++)
		cout<<in.at(i)<<" ";

	cout<<endl;
	return 0;
}