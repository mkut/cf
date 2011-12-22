#include <milib/template/aoj>
#include <milib/io/vector>
#include <map>

class solver {
private:
	string str, ansTrace;
	int k, ans;
	vector<vector<int> > dp, dp2;
	vector<vector<pair<int,int> > > tr;
	vector<vector<pair<int,int> > > tr2;
public:
	//>>[solver
	str
	k
	//>>]
	//<<[solver
	ans
	ansTrace
	//<<]
	void solve() {
		int n = str.length();
		dp = vector<vector<int> >(n, vector<int>(n));
		each(i : 0 .. n)
			each(j : i .. n)
				dp[i][j] = f(i, j);
		dp2 = vector<vector<int> >(n+1, vector<int>(k+1, 1<<30));
		tr = vector<vector<pair<int,int> > >(n+1, vector<pair<int, int> >(k+1));
		tr2 = vector<vector<pair<int,int> > >(n+1, vector<pair<int,int> >(k+1));
		tr = tr2;
		dp2[0][0] = 0;
		each(i : 1 ... k)
		{
			each(j : i-1 ... n)
				each(m : j+1 ... n)
					if (dp2[m][i] > dp2[j][i-1] + dp[j][m-1])
					{
						dp2[m][i] = dp2[j][i-1] + dp[j][m-1];
						tr2[m][i] = pair<int,int>(j, i-1);
						tr[m][i] = pair<int,int>(j, m);
					}
		}

		ans = 1<<30;
		each(i : 1 ... k)
		{
			if (ans > dp2[n][i]) {
				ans = dp2[n][i];
				ansTrace = "";
				for(int j = n, m = i ; j != 0; ) {
					ansTrace = j == n ? "" : "+" + ansTrace;
					ansTrace = fix(str.substr(tr[j][m].first, tr[j][m].second - tr[j][m].first)) + ansTrace;
					int next_j = tr2[j][m].first;
					int next_m = tr2[j][m].second;
					j = next_j;
					m = next_m;
				}
			}
		}
	}

	int f(int a, int b) {
		int ret = 0;
		for (int i = a, j = b; i < j; i++, j--) {
			ret += str[i] == str[j] ? 0 : 1;
		}
		return ret;
	}

	string fix(string s) {
		for (int i = 0, j = s.length() - 1; i < j; i++, j--)
			if (s[i] != s[j])
				s[i] = s[j];
		return s;
	}
};

int main() {
	solver prob;
	while (cin >> prob) {
		prob.solve();
		cout << prob;
		break;
	}
	return 0;
}
