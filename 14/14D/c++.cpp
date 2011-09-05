#include <iostream>
#include <vector>
#include <map>
#include <bitset>
#include <stdlib.h>
#include <algorithm>
using namespace std;

typedef bool Map[201][201];

int d(Map& tree, int pos, int prev, int depth, int* pmax)
{
	vector<int> lst(2);
	for(int i = 0; i < 201; i++)
	{
		if(i != prev && tree[pos][i])
			lst.push_back(d(tree, i, pos, depth+1, pmax));
	}
	
	sort(lst.begin(), lst.end());
	reverse(lst.begin(), lst.end());
	
	*pmax = max(*pmax, max(lst[1], depth) + lst[0]);
	
	return lst[0] + 1;
}

int main()
{
	int n;
	cin >> n;
	Map linked = {};
	for(int i = 0; i < n-1; i++)
	{
		int a, b;
		cin >> a >> b;
		
		linked[a][b] = true;
		linked[b][a] = true;
	}
	
	int ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = i+1; j <= n; j++)
		{
			if(linked[i][j])
			{
				int pmax1 = 0, pmax2 = 0;
				d(linked, i, j, 0, &pmax1);
				d(linked, j, i, 0, &pmax2);
				ans = max(ans, pmax1 * pmax2);
			}
			
		}
	
	cout << ans << endl;
	
	return 0;
}
