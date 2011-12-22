#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

template<class T>
istream& operator>>(istream& is, vector<T>& v) {
	for(int i = 0; i < v.size(); i++)
		cin >> v[i];
	return is;
}
template<class T>
ostream& operator<<(ostream& os, vector<T>& v) {
	for(int i = 0; i < v; i++)
		cout << v[i];
	return os;
}

template<class T>
class vector_reader {
public:
	typedef enum { FORMAT_NONE, FORMAT_VEC, FORMAT_LEN_VEC } format;
	typedef enum { ARG_NONE, ARG_LENGTH } arg;
private:
	vector<T>& v;
	format f;
public:
	vector_reader(vector<T>& v, format f) : v(v), f(f) { }
	vector_reader(vector<T>& v, format f, arg a, int arg1) : v(v), f(f) {
		vector_reader(v, f);
		switch(a) {
		case ARG_LENGTH:
			v = vector<T>(arg1);
			break;
		}
	}
	friend istream& operator>>(istream& is, vector_reader vr) {
		int len;
		switch(vr.f) {
		case FORMAT_VEC:
			return is >> vr.v;
		case FORMAT_LEN_VEC:
			is >> len;
			vr.v = vector<T>(len);
			return is >> vr.v;
		}
	}
};
template<class T>
class vector_writer {
private:
	const vector<T>& v;
	char sep;
public:
	vector_writer(const vector<T>& v, char sep)
		: v(v), sep(sep) {}
	friend ostream& operator<<(ostream& os, vector_writer vw) {
		for(int i = 0; i < vw.v.size(); i++) {
			if(i != 0)
				os << vw.sep;
			os << vw.v[i];
		}
		return os;
	}
};


class solver {
private:
	string str, ansTrace;
	int k, ans;
	vector<vector<int> > dp, dp2;
	vector<vector<pair<int,int> > > tr;
	vector<vector<pair<int,int> > > tr2;
public:
	friend istream& operator>>(istream& is, solver& cl){
		is >> cl.str;
		is >> cl.k;
		return is;
	}
	friend ostream& operator<<(ostream& os, solver& cl){
		os << cl.ans << endl;
		os << cl.ansTrace << endl;
		return os;
	}
	void solve() {
		int n = str.length();
		dp = vector<vector<int> >(n, vector<int>(n));
		for(int i = 0 ; i <  n; i++)
			for(int j = i ; j <  n; j++)
				dp[i][j] = f(i, j);
		dp2 = vector<vector<int> >(n+1, vector<int>(k+1, 1<<30));
		tr = vector<vector<pair<int,int> > >(n+1, vector<pair<int, int> >(k+1));
		tr2 = vector<vector<pair<int,int> > >(n+1, vector<pair<int,int> >(k+1));
		tr = tr2;
		dp2[0][0] = 0;
		for(int i = 1 ; i <=  k; i++)
		{
			for(int j = i-1 ; j <=  n; j++)
				for(int m = j+1 ; m <=  n; m++)
					if (dp2[m][i] > dp2[j][i-1] + dp[j][m-1])
					{
						dp2[m][i] = dp2[j][i-1] + dp[j][m-1];
						tr2[m][i] = pair<int,int>(j, i-1);
						tr[m][i] = pair<int,int>(j, m);
					}
		}

		ans = 1<<30;
		for(int i = 1 ; i <=  k; i++)
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
