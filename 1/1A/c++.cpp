#include <milib/template/aoj>

class solver
{
private:
	long long n, m, a;
	long long ans;
public:
	//>>[solver
	n m a
	//>>]
	//<<[solver
	ans
	//<<]
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
