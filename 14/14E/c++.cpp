#include <iostream>
#include <vector>
#include <map>
#include <bitset>
#include <stdlib.h>
#include <algorithm>
using namespace std;



int solve(int p, int n, int t)
{
	static map<pair<int,int>,int> memo[4] = {};
	
	if(memo[p].count(pair<int,int>(n,t)) > 0)
		return memo[p][pair<int,int>(n,t)];
	
	if(t == 0 && n == 0)
		return 1;
	if(t == 0 || n <= 0)
		return 0;
	int sum = 0;
	switch(p)
	{
		case 3:
			sum += solve(1, n-1, t-1);
			sum += solve(3, n-2, t-1);
			sum += solve(2, n-2, t-1);
			sum += solve(3, n-3, t-1);
		case 2:
			sum += solve(2, n-1, t-1);
			sum += solve(3, n-2, t-1);
		case 1:
			sum += solve(3, n-1, t-1);
	}
	
	memo[p][pair<int,int>(n,t)] = sum;
	return sum;
}

int main()
{
	
	int n, t;
	cin >> n >> t;
	
	int ans = 0;
	for(int i = 1; i <= 3; i++)
		ans += solve(i, n-1, t*2);
	cout << ans << endl;
	
	return 0;
}
