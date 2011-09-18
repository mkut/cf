#include <iostream>
#include <vector>
#include <map>
#include <bitset>
#include <stdlib.h>
#include <algorithm>
using namespace std;

bool next(int& x, int& y, int c, bool odd)
{
	if(x == c * 2 + 1 && y == c * 2 + 1)
		return true;
	if(odd)
	{
		if(y == c && x >= c)
		{
			x = c * 2 - x - 1;
			return false;
		}
		if(y >= c)
		{
			y = c * 2 - y + (x < c ? -1 : 1);
			x++;
			return false;
		}
		y = c * 2 - y;
		return false;
	}
	else
	{
		if(y == c + 1 && x >= c)
		{
			y--;
			x = c * 2 - x - 1;
			return false;
		}
		if(y >= c+1)
		{
			y = c * 2 - y + 1 + (x < c ? -1 : 1);
			x++;
			return false;
		}
		y = c * 2 - y + 1;
		return false;
	}
}

bool check(vector<vector<int> >& seat, int x, int y)
{
	return x > 0 && x <= seat.size() - 2 && y > 0 && y <= seat.size() - 2 && seat[x][y] == 0;
}
bool check(vector<vector<int> >& seat, int x, int y, int m)
{
	for(int i = y - m/2; i <= y + (m-1)/2; i++)
		if(!check(seat, x, i))
			return false;
	return true;
}

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> left(k);
	vector<int> right(k);
	vector<char> used(k);
	
	int c = k/2;
	for(int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		int min = 100000000;
		int ans[3] = {};
		for(int i = 0; i < k; i++)
		{
			int cost = 100000001;
			if(used[i] == 0)
			{
				if(m <= k)
				{
					cost = abs(c - i) * m + (m/2)*(m/2) + (m%2==1?m/2:0);
					if(cost < min)
					{
						min = cost;
						ans[0] = i;
						ans[1] = (c+1) - m/2;
						ans[2] = (c+1) + (m-1)/2;
					}
				}
			}
			else
			{
				if(m <= c - left[i])
				{
					cost = abs(c - i) * m + m * (m + 2 * left[i] + 1) / 2;
					if(cost < min)
					{
						min = cost;
						ans[0] = i;
						ans[1] = (c+1) - left[i] - m;
						ans[2] = (c+1) - left[i] - 1;
					}
				}
				if(m <= c - right[i])
				{
					cost = abs(c - i) * m + m * (m + 2 * right[i] + 1) / 2;
					if(cost < min)
					{
						min = cost;
						ans[0] = i;
						ans[1] = (c+1) + right[i] + 1;
						ans[2] = (c+1) + right[i] + m;
					}
				}
			}
		}
		if(min == 100000000)
			cout << -1 << endl;
		else
		{
			cout << ans[0] + 1 << " " << ans[1] << " " << ans[2] << endl;
			if(used[ans[0]] == 0)
			{
				left[ans[0]] = m / 2;
				right[ans[0]] = (m-1) / 2;
				used[ans[0]] = true;
			}
			else
			{
				if(ans[2] <= c)
				{
					left[ans[0]] += m;
				}
				else
				{
					right[ans[0]] += m;
				}
			}
		}
	}
	
	return 0;
}
