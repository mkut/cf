#include <iostream>
#include <vector>
#include <map>
#include <bitset>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> h(n+1);
	h[n] = 100000000;
	for(int i = 0; i < n; i++)
		cin >> h[i];
	
	vector<int> ln(n);
	int _max = 1;
	vector<int> lst;
	int begin = 0, end = 0;
	priority_queue<int, vector<int>, greater<int> > low, passlow;
	priority_queue<int> high, passhigh;
	for(; end < n+1; end++)
	{
		low.push(h[end]);
		high.push(h[end]);
		if(high.top() - low.top() > k)
		{
			if(_max < end - begin)
			{
				_max = end - begin;
				lst = vector<int>();
				lst.push_back(begin);
			}
			else if(_max == end - begin)
			{
				lst.push_back(begin);
			}
		}
		while(high.top() - low.top() > k)
		{
			if(high.top() == h[begin])
				high.pop();
			else passhigh.push(h[begin]);
			while(!passhigh.empty() && high.top() == passhigh.top())
			{
				high.pop();
				passhigh.pop();
			}
			if(low.top() == h[begin])
				low.pop();
			else passlow.push(h[begin]);
			while(!passlow.empty() && low.top() == passlow.top())
			{
				low.pop();
				passlow.pop();
			}
			begin++;
		}
	}
	cout << _max << " " << lst.size() << endl;
	for(int i = 0; i < lst.size(); i++)
	{
		cout << lst[i]+1 << " " << lst[i]+_max << endl;
	}
	return 0;
}
