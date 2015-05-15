/* Bottom up Merge Sort
 * Time Complexity -
 * Worst case -- O(nlogn)
 * Best case  -- O(n)
 * Avg Case   -- O(nlogn)
 * Space Complexitty -- O(2n)
 * can be improved
 */
#include <iostream>
#include <vector>
#include <climits>
using namespace::std;

void merge_sort(vector <int> &in)
{
	vector <int> copy(in.begin(),in.end());
	int i,j,k,l,r,alt=1;
	 for (i=1;i<in.size();i*=2) // i is the width of subarray to be sorted
	{
		for(j=0; j<in.size(); j+=2*i)
		{
			// merge section
			l=j; 
			r=j+i;
			for(k=0;k<2*i && j+k<in.size();k++)
			{
				if(alt)  // vector to use. saves repeated copying
				{
					if( (r>=j+2*i || r>=in.size()) || (l<j+i && in[l]<in[r]) )
					{
						copy[j+k]=in[l];
						l++;
					}
					else
					{
						copy[j+k]=in[r];
						r++;
					}
				}
				else
				{
					if( (r>=j+2*i || r>=in.size()) || (l<j+i && copy[l]<copy[r]) )
					{
						in[j+k]=copy[l];
						l++;
					}
					else
					{
						in[j+k]=copy[r];
						r++;
					}
				}
			}
		}
		alt^=1;
	}
	if(!alt)
		for(i=0;i<in.size();i++)
			in[i]=copy[i];
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
	merge_sort(in);

	for(int i=0;i<n;i++)
		cout<<in.at(i)<<" ";

	cout<<endl;
	return 0;
}