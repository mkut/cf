#include <iostream>
#include <vector>
#include <map>
#include <bitset>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main()
{
	/*
	int n;
	cin >> n;
	int ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			for(int k = 1; k <= n; k++)
				if(i * j != k && (i * j - k) % 9 == 0)
					ans++;
	cout << ans << endl;
	*/
	
	int t[9][9];
	int u[9] = {};
	for(int i = 0; i < 9; i++)
		for(int j = 0; j < 9; j++)
		{
			t[i][j] = (i*j+8) % 9 + 1;
			u[(i*j)%9]++;
		}
	
	int n;
	cin >> n;
	long long ans = (n/9) * (n/9) * (n/9) * 9 * 9;
	for(int i = 1; i < n%9+1; i++)
	{
		for(int j = 1; j < n%9+1; j++)
		{
			if(t[i][j] <= n%9)
			{
				ans+=(n/9+1)*(n/9+1)*(n/9+1) - (n/9)*(n/9)*(n/9);
			}
			
		}
	}
	for(int i = 1; i <= n; i++)
	{
		ans -= n / i;
	}
	cout << ans << endl;
	
	return 0;
	
}
