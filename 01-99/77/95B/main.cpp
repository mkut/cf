#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

class solver
{
private:
	string n;
	string ans;
public:
	friend istream& operator>>(istream& is, solver& cl){
		is >> cl.n;
		return is;
	}
	friend ostream& operator<<(ostream& os, solver& cl){
		os << cl.ans << endl;
		return os;
	}
	void solve()
	{
		ans = next_lucky(n);
		ans = next_double_lucky(ans);
		ans = next_super_lucky(ans);
	}
	string next_lucky(string x)
	{
		int four = -1;
		for(int i = 0; i < x.length(); i++)
			if(x[i] < '4')
				for(int j = i; j < x.length(); j++)
					x[j] = '4';
			else if(x[i] > '7')
				if(four != -1)
				{
					x[four] = '7';
					for(int j = four + 1; j < x.length(); j++)
						x[j] = '4';
				}
				else
				{
					x = string(x.length() + 1, '4');
				}
			else if(x[i] == '4')
				four = i;
			else if(x[i] < '7')
			{
				x[i] = '7';
				for(int j = i+1; j < x.length(); j++)
					x[j] = '4';
			}
		return x;
	}
	string next_double_lucky(string x)
	{
		if(x.length() & 1)
			return x = string(x.length()/2+1, '4') + string(x.length()/2+1, '7');
		return x;
	}
	string next_super_lucky(string x)
	{
		int m = x.length();
		vector<int> dp(m);
		int seven = 0, four = 0;
		for(int i = 0; i < m; i++)
		{
			if(x[i] == '7')
				seven++;
			else
				four++;
			dp[i] = seven;
		}
		if(four == seven)
			return x;
		if(four > seven)
		{
			for(int i = 0; four - seven > 0; i++)
				if(x[m-i-1] == '4')
					x[m-i-1] = '7', four -= 2;
			return x;
		}
		for(int i = m-1 ; i >= 0; i--)
			if(x[i] == '4' && dp[i] < m/2)
			{
				x[i] = '7';
				for(int j = 0; j < m/2 - i + dp[i]; j++)
					x[i + 1 + j] = '4';
				for(int j = 0; j < m/2 - dp[i] - 1; j++)
					x[m-1-j] = '7';
				return x;
			}
		return string(x.length()/2+1, '4') + string(x.length()/2+1, '7');
	}
};

int main()
{
	solver prob;
	while(cin >> prob)
	{
		prob.solve();
		cout << prob;
		break;
	}
	return 0;
}
