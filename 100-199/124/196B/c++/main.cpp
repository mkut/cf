#include <iostream>
#include <vector>
using namespace std;

class solver {
	vector<string> maze;
	vector<int> memo;
	vector<char> visited;
	int n, m;
public:
	solver(vector<string>& maze) : maze(maze), memo(1600*1600), visited(1600*1600) {}
	bool solve() {
		n = maze.size();
		m = maze[0].size();
		int x, y;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (maze[i][j] == 'S') x = i, y = j;
		return solve(x, y);
	}
	bool solve(int x, int y) {
		const int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
		int p = x * 1600 + y;
		int pp = (x % n + n) % n * 1600 + (y % m + m) % m;
		if (maze[pp/1600][pp%1600] == '#')
			return false;
		else if (visited[pp]) {
			return memo[pp] != p;
		}
		memo[pp] = p;
		visited[pp]= true;
		for (int i = 0; i < 4; i++) if (solve(x+dx[i], y+dy[i])) return true;
		return false;
	}
};

int main() {
	int n, m; cin >> n >> m;
	vector<string> maze(n);
	for (int i = 0; i < n; i++) cin >> maze[i];
	solver prob(maze);
	bool ans = prob.solve();
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
