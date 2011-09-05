#include <milib/template/aoj>
#include <vector>
#include <map>
#include <set>
#include <milib/io/vector>
#include <milib/math/make_primes>
#include <milib/math/prime_factorize>

struct point
{
	int x, y;
	friend istream& operator>>(istream& os, point& p) {
		return cin >> p.x >> p.y;
	}
};

class solver
{
private:
	int n;
	vector<point> data;
	vector<int> ans;
	vector<int> dp;
public:
	//>>[solver
	n
	data[n]:point
	//>>]
	//<<[solver
	ans+_'\n':int
	//<<]
	void solve()
	{
		dp = vector<int>(100010, -1);
		ans = vector<int>(n);
		vector<int> primes;
		make_primes<1000>(primes);
		each(i : n)
		{
			divisor div = prime_factorize(data[i].x, primes);
			do {
				int div_i = div.to_ll();
				if(dp[div_i] < i - data[i].y)
					ans[i]++;
				dp[div_i] = i;
				div++;
			} while(div.to_ll() != 1);
		}
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
}
