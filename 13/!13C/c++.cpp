#include <iostream>
#include <vector>
#include <map>
#include <bitset>
#include <stdlib.h>
#include <algorithm>
using namespace std;

struct State
{
	int first, second;
	State(int a, int b)
	{
		first = a;
		second = b;
	}
};

bool operator<(State a, State b)
{
	return a.first < b.first || a.first == b.first && a.second < b.second;
}

int main()
{
	int n;
	cin >> n;
	vector<int> vi(n);
	for(int i = 0; i < n; i++)
		cin >> vi[i];
	
	map<State,int> prev;
	prev[State(vi[0],1)] = 0;
	
	for(int i = 1; i < n; i++)
	{
		map<State,int> next;
		bool chk2 = true;
		for(map<State,int>::iterator it = prev.begin(); it != prev.end(); ++it)
		{
			//cout << it->first.first << "," << it->first.second << ":" << it->second << endl;
			next[State(it->first.first, it->first.second + 1)] = it->second + abs(vi[i] - it->first.first);
			if(it->first.first < vi[i])
				if(next.count(State(vi[i], 1)) > 0)
					next[State(vi[i], 1)] = min(next[State(vi[i], 1)], it->second);
				else
					next[State(vi[i], 1)] = it->second;
					
			if(it->first.first > vi[i] && chk2)
			{
				if(next.count(State(vi[i], it->first.second + 1)) > 0)
					next[State(vi[i], it->first.second + 1)] = min(next[State(vi[i], it->first.second + 1)], it->second + abs(vi[i] - it->first.first) * it->first.second);
				else
					next[State(vi[i], it->first.second + 1)] = it->second + abs(vi[i] - it->first.first) * it->first.second;
				chk2 = false;
			}
		}
		//cout << endl;
		prev = next;
	}
	
	long long ans = 1000000000*5000;
	for(map<State,int>::iterator it = prev.begin(); it != prev.end(); ++it)
	{
		//cout << it->first.first << "," << it->first.second << ":" << it->second << endl;
		ans = min(ans, (long long)it->second);
	}
	
	cout << ans << endl;
	return 0;
}
