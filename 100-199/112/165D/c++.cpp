#include <milib/template/aoj>
#include <vector>
#include <map>

typedef pair<int,int> edge;

class segtree {
	vector<int> data;
	int n;
	int size;
public:
	static const int black = 0;
	static const int white = 1;
public:
	segtree(int size) : size(size) {
		n = extend(size);
		data = vector<int>(n*2);
		for (int i = 0; i < data.size(); i++) {
			data[i] = black;
		}
	}
	void update(int x, int value) {
		x += n;
		data[x] = value;
		for (x /= 2; x; x /= 2) {
			data[x] = max(data[x*2], data[x*2+1]);
		}
	}
	int query(int x, int y) {
		return query(x, y, 1, 0, n);
	}
	int query(int x, int y, int k, int l, int r) {
		if (y <= l || r <= x) return black;
		if (x <= l && r <= y) return data[k];
		int m = (l+r)/2;
		return max(query(x, y, k*2, l, m), query(x, y, k*2+1, m, r));
	}
private:
	int extend(int x) {
		int c = 0;
		while (x > 1) {
			c++;
			x >>= 1;
		}
		while (c--) {
			x <<= 1;
		}
		return x << 1;
	}
};

class solver {
	int n;
	int root;
	vector<segtree> segtrees;
	vector<pair<int,int> > cor_edge;
	vector<pair<int,int> > cor_node;
public:
	solver(vector<edge>& edges) : n(edges.size() + 1), cor_edge(n), cor_node(n+1) {
		vector<vector<int> > linked(n+1);
		for (int i = 0; i < n - 1; i++) {
			int x = edges[i].first;
			int y = edges[i].second;
			linked[x].push_back(i);
			linked[y].push_back(i);
		}
		root = 1;
		for (int i = 0; i < n; i++) {
			if (linked[i].size() >= 3) {
				root = i;
			}
		}
		cor_node[root] = pair<int,int>(0, 0);

		for (int i = 0; i < linked[root].size(); i++) {
			int e = linked[root][i];
			int x = opposite(edges[e], root);
			int size = 1;
			cor_edge[e] = pair<int,int>(i, 0);
			cor_node[x] = pair<int,int>(i, 1);
			for (; linked[x].size() >= 2; ) {
				e = linked[x][0] == e ? linked[x][1] : linked[x][0];
				x = opposite(edges[e], x);
				cor_edge[e] = pair<int,int>(i, size);
				cor_node[x] = pair<int,int>(i, size + 1);
				size++;
			}
			segtrees.push_back(segtree(size));
		}

	}
	void update(int e, int color) {
		int i = cor_edge[e].first;
		int j = cor_edge[e].second;
		segtrees[i].update(j, color);
	}
	int query(int x, int y) {
		int i_x = cor_node[x].first;
		int j_x = cor_node[x].second;
		int i_y = cor_node[y].first;
		int j_y = cor_node[y].second;

		if (i_x == i_y) {
			int j_min = min(j_x, j_y);
			int j_max = max(j_x, j_y);
			int color = segtrees[i_x].query(j_min, j_max);
			return color == segtree::black ? j_max - j_min : -1;
		} else {
			int color_x = segtrees[i_x].query(0, j_x);
			int color_y = segtrees[i_y].query(0, j_y);
			return max(color_x, color_y) == segtree::black ? j_x + j_y : -1;
		}
	}
private:
	int opposite(edge e, int x) {
		return e.first == x ? e.second : e.first;
	}
};

int main() {
	int n; cin >> n;
	vector<edge> edges(n);
	for (int i = 1; i < n; i++) {
		int x, y; cin >> x >> y;
		edges[i] = edge(x, y);
	}
	solver prob(edges);
	
	// query
	int m; cin >> m;
	while(m--) {
		int type; cin >> type;
		int x, y;
		switch (type) {
			case 1:
				cin >> x;
				prob.update(x, segtree::black);
				break;
			case 2:
				cin >> x;
				prob.update(x, segtree::white);
				break;
			case 3:
				cin >> x >> y;
				int ans = prob.query(x, y);
				cout << ans << endl;
				break;
		}
	}
	return 0;
}
