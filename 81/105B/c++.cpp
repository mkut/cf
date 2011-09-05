/* aoj header */
#include <vector>

void gen_sets(vector<vector<int> >& ret, vector<int> cur, int n, int k)
{
	if(n <= 0)
		return;
	if(n == 1)
	{
		cur.push_back(k);
		ret.push_back(cur);
		return;
	}
	cur.push_back(0);
	for(int i = 0; i <= k; i++)
	{
		cur.back() = i;
		gen_sets(ret, cur, n-1, k-i);
	}
}

int popcount(int j, int n)
{
	int ret = 0;
	for(int i = 0; i < n; i++)
		if(j>>i&1)
			ret++;
	return ret;
}

int main()
{
	int n, k, A; cin >> n >> k >> A;
	vector<int> levels(n), loyals(n);
	for(int i = 0; i < n; i++)
		cin >> levels[i] >> loyals[i];

	vector<vector<int> > sets;
	gen_sets(sets, vector<int>(), n, k);

	double ans = 0;
	for(int i = 0; i < sets.size(); i++)
	{
		double prob = 1.0;
		for(int j = 0; j < 1<<n; j++)
		{
			if(popcount(j, n) <= n/2)
			{
				double prob2 = 1.0;
				for(int k = 0; k < n; k++)
				{
					if(j>>k&1)
						prob2 *= min(100, loyals[k] + sets[i][k]*10) / 100.0;
					else
						prob2 *= (100 - min(100, loyals[k] + sets[i][k]*10)) / 100.0;
				}
				int sum = 0;
				for(int k = 0; k < n; k++)
				{
					if(!(j>>k&1))
						sum += levels[k];
				}
				prob2 *= 1.0 * sum / (A+sum);
				prob -= prob2;
			}
		}
		ans = max(ans, prob);
	}
	printf("%.10f\n", ans);

	return 0;
}
