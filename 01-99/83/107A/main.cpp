#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#include <vector>
#include <utility>

pair<int, int> solve(vector<int>& viout, vector<int>& viin, vector<int>& vito, vector<int>& vifrom, int x, int _min, vector<int>& done)
{
	if(done[x])
		return pair<int, int>(-1, -1);
	done[x] = 1;
	if(viout[x] == 0)
		return pair<int, int>(x, _min);
	return solve(viout, viin, vito, vifrom, vito[x], min(_min, viout[x]), done);
}

int main()
{
	int n, p;
	cin >> n >> p;

	vector<int> viout(n), viin(n), vito(n), vifrom(n);
	for(int i = 0; i < p; i++)
	{
		int a, b, d; cin >> a >> b >> d;
		a--; b--;
		viout[a] = d; vito[a] = b;
		viin[b] = d; vifrom[b] = a;
	}
	vector<int> ans_a, ans_b, ans_c;
	vector<int> done(n);
	for(int i = 0; i < n; i++)
	{
		if(viin[i] == 0 && viout[i] != 0)
		{
			pair<int,int> p = solve(viout, viin, vito, vifrom, i, 100000000, done);
			if(p.first != -1)
			{
				ans_a.push_back(i);
				ans_b.push_back(p.first);
				ans_c.push_back(p.second);
			}
		}
	}
	cout << ans_a.size() << endl;
	for(int i = 0; i < ans_a.size(); i++)
		cout << ans_a[i] + 1 << " " << ans_b[i] + 1 << " " << ans_c[i] << endl;
	return 0;
}
