#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

class solver {
private:
	string str, a1, a2;
public:
	friend istream& operator>>(istream& is, solver& cl){
		is >> cl.str;
		return is;
	}
	friend ostream& operator<<(ostream& os, solver& cl){
		os << cl.a1 << endl;
		os << cl.a2 << endl;
		return os;
	}
	void solve() {
		vector<int> count(10);
		for(int i = 0; i < str.length(); i++)
			count[str[i] - '0']++;
		a1 = a2 = "";
		int sc = -1;
		for(int i = 1; i < 10; i++) {
			string ta1, ta2;
			int tsc = f(i, count, ta1, ta2);
			if (tsc > sc) {
				sc = tsc;
				a1 = ta1;
				a2 = ta2;
			}
		}
		reverse(a1.begin(), a1.end());
		reverse(a2.begin(), a2.end());
	}

	int f(int x, vector<int> c, string& a1, string& a2) {
		if (c[x] == 0 || c[10-x] == 0) {
			a1 = a2 = make(c);
			return 0;
		}
		vector<int> c1 = c;
		vector<int> c2 = c;
		c1[x]--;
		c2[10-x]--;
		a1 += '0' + x;
		a2 += '0' + 10 - x;
		return g(c1, c2, a1, a2) + 1;
	}

	int g(vector<int> c1, vector<int> c2, string& a1, string& a2) {
		int ret = 0;
		for (int i = 0; i < 10; ) {
			if (c1[i] == 0 || c2[9-i] == 0) {
				i++;
				continue;
			}
			c1[i]--;
			c2[9-i]--;
			a1 += '0' + i;
			a2 += '0' + 9 - i;
			ret++;
		}
		int nc = min(c1[0], c2[0]);
		a1 = string(nc, '0') + a1;
		a2 = string(nc, '0') + a2;
		ret += nc;
		c1[0] -= nc;
		c2[0] -= nc;
		a1 += make(c1);
		a2 += make(c2);
		return ret;
	}

	string make(vector<int> c) {
		string ret = "";
		for(int i = 0; i < 10; i++) {
			ret += string(c[i], '0' + i);
		}
		return ret;
	}
};

int main() {
	solver prob;
	while(cin >> prob) {
		prob.solve();
		cout << prob;
		break;
	}
	return 0;
}
