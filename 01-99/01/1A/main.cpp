#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

class solver
{
private:
	long long n, m, a;
	long long ans;
public:
	friend istream& operator>>(istream& is, solver& cl){
		is >> cl.n >> cl.m >> cl.a;
		return is;
	}
	friend ostream& operator<<(ostream& os, solver& cl){
		os << cl.ans << endl;
		return os;
	}
	long long div_ceil(long long a, long long b) { return (a+b-1)/b; }
	void solve()
	{
		ans = div_ceil(n, a) * div_ceil(m, a);
	}
};

int main()
{
	solver prob;
	while(cin >> prob)
	{
		prob.solve();
		cout << prob;
	}
	return 0;
}
