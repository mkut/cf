/* aoj header */

long long binomial(long long n, long long m)
{
	long long ret = 1;
	for(int i = 1; i <= m; i++)
		ret = ret * (n+1-i) / i;
	return ret;
}

struct node
{
	int id;
	vector<node*> lower;
	vector<int> lower_lst;
	long long solve()
	{
		long long ret = 1;
		long long size = 0;
		for(int i = 0; i < lower.size(); i++)
		{
			ret *= lower[i]->solve();
			int lower_size = lower[i]->lower_lst.size();
			ret *= binomial(size
		}
	}
};

int main()
{
	int n, y, m; cin >> n >> y >> m;

	return 0;
}
