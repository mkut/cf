#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool comp(const pair<int, int>& left, const pair<int, int>& right)
{
	return left.second > right.second;
}

int main()
{
	int n, v;
	cin >> n >> v;
	
	vector<pair<int, int> > kayak, catamaran;
	for(int i = 1; i <= n; i++)
	{
		int type, value;
		cin >> type >> value;
		if(type == 1) kayak.push_back(pair<int, int>(i, value));
		else catamaran.push_back(pair<int, int>(i, value));
	}
	sort(kayak.begin(), kayak.end(), comp);
	sort(catamaran.begin(), catamaran.end(), comp);
	
	int _max = 0;
	vector<pair<int, int> >::iterator it_k = kayak.begin(), it_c = catamaran.begin();
	for(; it_k != kayak.end() && v > 0; it_k++)
	{
		_max += it_k->second;
		v--;
	}
	for(; it_c != catamaran.end() && v > 1; it_c++)
	{
		_max += it_c->second;
		v-=2;
	}
	it_k--;
	for(;it_c != catamaran.end() && it_k != kayak.begin()-1 ; it_k-=2)
	{
		if(v == 1)
		{
			if(it_k->second < it_c->second)
			{
				_max += it_c->second - it_k->second;
				it_c++;
				it_k++;
				v = 0;
			}
			else break;
			continue;
		}
		if(it_k == kayak.begin()) break;
		if(it_k->second + (it_k-1)->second < it_c->second)
		{
			_max += it_c->second - it_k->second - (it_k-1)->second;
			it_c++;
		}
		else break;
	}
	cout << _max << endl;
	it_c--;
	vector<int> output;
	for(; it_k+1 != kayak.begin(); it_k--)
	{
		output.push_back(it_k->first);
	}
	for(; it_c+1 != catamaran.begin(); it_c--)
	{
		output.push_back(it_c->first);
	}
	for(vector<int>::iterator it = output.begin(); it != output.end(); it++)
	{
		cout << (it == output.begin() ? "" : " ") << (*it);
	}
	cout << endl;
	
	return 0;
}