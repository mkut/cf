#include <milib/template/aoj>
#include <map>

typedef long long ll;

class solver
{
private:
	vector<ll> v;
	map<int, ll> count;
	ll ans;
public:
	//>>[solver
	v[]:ll
	//>>]
	//<<[solver
	ans
	//<<]
	void solve()
	{
		each(it : v of vector<ll>)
			count[*it]++;
		ans = 0;
		each(it : count of map<int, ll>)
			if(it->first == 0)
				ans += it->second * (it->second - 1);
			else
				ans += it->second * count[- it->first];
		ans /= 2;
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
