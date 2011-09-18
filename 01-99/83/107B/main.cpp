#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#include <cmath>

double mult_range_div(int x, int y, int x2)
{
	double ret = 1;
	for(int i = x, j = x2; i <= y; i++, j++)
		ret *= i, ret /= j;
	return ret;
}

int main()
{
	int n, m, h; cin >> n >> m >> h;
	n--; h--;
	int en = 0, fr = -1;
	for(int i = 0; i < m; i++)
	{
		int tmp; cin >> tmp;
		if(i == h)
			fr += tmp;
		else
			en += tmp;
	}

	double ans;
	if (fr + en >= n)
		ans = 1 - mult_range_div(en - n + 1, en, en + fr - n + 1);
	else
		ans = -1;
	printf("%.10f", ans);
	cout << endl;
	
	return 0;
}
