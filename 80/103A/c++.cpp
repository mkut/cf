#include <milib/template/aoj>
#include <milib/io/vector>

class solver
{
private:
	vector<int> vi;
	long long ans;
public:
	//>>[solver
	vi[]:int
	//>>]
	//<<[solver
	ans
	//<<]
	void solve()
	{
		ans = vi.size();
		each(i : vi.size())
			ans += (long long)(i+1) * (vi[i] - 1);
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
