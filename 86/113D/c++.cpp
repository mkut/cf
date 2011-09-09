#include <milib/template/aoj>
#include <sys/time.h>

struct point {
	int x, y;
	friend istream& operator>>(istream& is, point& p) {
		return is >> p.x >> p.y;
	}
};

class solver
{
private:
	int n, m, a, b;
	vector<point> vp;
	vector<double> ps;
	vector<double> ans;
public:
	//>>[solver
	n m a b
	vp[m]:point
	ps[n]:double
	//>>]
	//<<[solver
	ans+_'\n':double
	//<<]
	solver() : vp(), ps() {}
	void solve()
	{
		a--; b--;
		vector<vector<int> > lnk(n);
		vector<vector<double> > prob(n, vector<double>(n));
		each(it : vp of vector<point>)
		{
			lnk[it->x-1].push_back(it->y-1);
			lnk[it->y-1].push_back(it->x-1);
		}
		each(i : n)
			each(j : n)
				if(i == j)
					prob[i][j] = ps[i];
				else if(find(lnk[i].begin(), lnk[i].end(), j) != lnk[i].end())
					prob[i][j] = (1 - ps[i]) / lnk[i].size();
		double A[256][256] = {};
		double B[256][256] = {};
		for(int cnt = 0, i = 0; i < n; i++)
			for(int j = i; j < n; j++, cnt++)
				if(i == j)
					A[cnt][cnt] = 1;
				else
					for(int cnt2 = 0, ii = 0; ii < n; ii++)
						for(int jj = ii; jj < n; jj++, cnt2++)
							if(ii == jj)
								A[cnt2][cnt] = prob[i][ii] * prob[j][jj];
							else
								A[cnt2][cnt] = prob[i][ii] * prob[j][jj] + prob[i][jj] * prob[j][ii];
		int ns = n * (n+1) / 2;
		each(it : 17)
		{
			each(i : ns)
				each(j : ns)
					each(k : ns)
						B[i][j] += A[i][k] * A[k][j];
			each(j : ns)
			{
				double s = 0;
				each(i : ns)
				{
					A[i][j] = B[i][j];
					B[i][j] = 0;
					if(A[i][j] < 1e-20)
						A[i][j] = 0;
					s += A[i][j];
				}
				each(i : ns)
					A[i][j] /= s;
			}
		}
		vector<double> I(ns), J(ns);
		for(int cnt = 0, i = 0; i < n; i++)
			for(int j = i; j < n; j++, cnt++)
				if(i == a && j == b || i == b && j == a)
					I[cnt] = 1;
		each(i : ns)
			each(j : ns)
				J[i] += A[i][j] * I[j];

		ans = vector<double>(n);
		for(int cnt = 0, i = 0; i < n; i++)
			for(int j = i; j < n; j++, cnt++)
				if(i == j)
					ans[i] = J[cnt];
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
