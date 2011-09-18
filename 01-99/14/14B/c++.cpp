#include <iostream>
#include <vector>
#include <map>
#include <bitset>
#include <stdlib.h>
#include <algorithm>
using namespace std;

pair<int,int> u(pair<int,int> a, pair<int,int> b)
{
	return pair<int,int>(max(a.first, b.first), min(a.second, b.second));
}

int main()
{
	int n, x0;
	cin >> n >> x0;
	
	pair<int,int> range(0,1000);
	for(int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		range = u(range, pair<int,int>(min(a,b),max(a,b)));
	}
	
	if(range.first > range.second)
		cout << -1 << endl;
	else if(range.first <= x0 && x0 <= range.second)
		cout << 0 << endl;
	else
		cout << min(abs(x0 - range.first), abs(x0 - range.second)) << endl;
	
	return 0;
}
