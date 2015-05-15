/* Bubble Sort
 * Time Complexity -
 * Worst case -- O(n^2)
 * Best case  -- O(n)
 * Avg Case   -- O(n^2)
 * Space Complexitty -- O(n)
 */
#include <iostream>
#include <vector> 
using namespace::std;

void bubble_sort(vector<int> &in)
{
	int temp;
	bool swap;
	for(int i=0;i<in.size();i++)
	{
		swap = false;
		for(int j=1;j<in.size()-i;j++)
		{
			if (in[j]<in[j-1])
			{
				temp = in[j];
				in[j] = in[j-1];
				in[j-1] = temp;
				swap = true;
			}
		}
		if (!swap) /* If no swap has taken place, we need to stop */
			break;
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
	bubble_sort(in);

	for(int i=0;i<n;i++)
		cout<<in.at(i)<<" ";

	cout<<endl;
	return 0;
}