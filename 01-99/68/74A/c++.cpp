#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int n; cin >> n;
	string ret;
	int _max = -99999999;
	for(int i = 0; i < n; i++)
	{
		string name;
		int plus, minus, a, b, c, d, e;
		cin >> name >> plus >> minus >> a >> b >> c >> d >> e;
		int score = plus * 100 - minus * 50 + a + b + c + d + e;
		if(score > _max)
			_max = score, ret = name;
	}
	cout << ret << endl;

	return 0;
}
