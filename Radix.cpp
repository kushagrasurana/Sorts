/* Radix Sort (stable)
 * Time Complexity -
 * Worst case -- O(dn) , d is maximum number of digits. 
 * Best case  -- O(nlogn)
 * Space Complexitty -- O(n)
 */
#include <iostream>
#include <vector>
#include <climits>
using namespace::std;

void count_sort(vector<int> &in, int *output, int ten)
{
	int count[10], i, temp, new_index = 0;
	
	for(i = 0; i<10; i++)
		count[i]=0;

	for(i = 0; i<in.size(); i++)
		count[ (in[i]%ten)/(ten/10) ]++;

	for(i = 0; i<10; i++)
	{
		int swap = count[i];
		count[i] = new_index;
		new_index += swap;
	}

	for(i = 0; i<in.size(); i++)
	{
		output[ count[ (in[i]%ten)/(ten/10) ] ] = in[i];
		count[ (in[i]%ten)/(ten/10) ] += 1;
	}

	for(int i = 0;i<in.size();i++)
		in[i] = output[i];
}

void _radix_sort(vector <int> &in)
{
	int output[in.size()], digit_count = 0, maximum = INT_MIN, i;
	for (i=0; i<in.size(); i++)
		if(in[i] > maximum)
			maximum = in[i];

	maximum *= 10;
	for (int i=10; i<=maximum; i*=10)
		count_sort(in, output, i);
}

void radix_sort(vector<int> &in)
{
	vector<int> pos, neg;
	int in_index = 0;
	for (int i=0; i<in.size(); i++)
	{
		if(in[i] >= 0)
			pos.push_back(in[i]);
		else
			neg.push_back( (-1*in[i]) );
	}

	_radix_sort(pos);
	_radix_sort(neg);

	for(int i = neg.size()-1; i>=0; i--)
	{
		in[in_index] = -1*neg[i];
		in_index++;
	}
	for(int i = 0; i<pos.size(); i++)
	{
		in[in_index] = pos[i];
		in_index++;
	}
}

int main()
{
	int n;
	cin>>n;
	vector <int> in;
	for(int i=0; i<n; i++)
	{ 
		int input;
		cin>>input;
		in.push_back(input);
	}
	radix_sort(in);

	for(int i=0; i<n; i++)
		cout<<in.at(i)<<" ";

	cout<<endl;
	return 0;
}