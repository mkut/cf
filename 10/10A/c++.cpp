#include <iostream>
#include <vector>
#include <map>
#include <bitset>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main()
{
	int n, p1, p2, p3, t1, t2;
	cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;
	vector<int> begin(n), end(n);
	for(int i = 0; i < n; i++)
	{
		cin >> begin[i] >> end[i];
	}
	int sum = (end[n-1] - begin[0]) * p1;
	
	for(int i = 0; i < n-1; i++)
	{
		int red = max(begin[i+1]-end[i] - t1, 0) * (p1 - p2) + max(begin[i+1]-end[i] - t1 - t2, 0) * (p2 - p3);
		sum -= red;
	}
	cout << sum << endl;
	return 0;
}
