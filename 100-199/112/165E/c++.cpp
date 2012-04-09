#include <milib/template/aoj>
#include <vector>

class solver {
	vector<int> a;
	vector<int> ans;
public:
	solver(vector<int>& a) : a(a), ans(1<<22, -1) {
		for (int i = 0; i < a.size(); i++) {
			add(((1<<22)-1) ^ a[i], a[i]);
		}
	}
	void solve() {
		for (int i = 0; i < a.size(); i++) {
			cout << (i > 0 ? " " : "") << ans[a[i]];
		}
		cout << endl;
	}
private:
	void add(int x, int y) {
		if (ans[x] != -1) {
			return;
		}
		ans[x] = y;
		for (int i = 0; i < 22; i++) {
			if ((x >> i) & 1) {
				add(x ^ (1<<i), y);
			}
		}
	}
};

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	solver prob(a);
	prob.solve();

	return 0;
}
