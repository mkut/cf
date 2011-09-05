#include <milib/template/aoj>
#include <milib/graph/directed_graph>
#include <milib/algorithm/dfs>

struct tuple {
	int x, y;
	friend istream& operator>>(istream& is, tuple& t) {
		return cin >> t.x >> t.y;
	}
};

class solver
{
private:
	int n;
	vector<tuple> es;
	string ans;
public:
	//>>[solver
	n es[]:tuple
	//>>]
	//<<[solver
	ans
	//<<]
	void solve()
	{
		ans = "NO";
		directed_graph G(n);
		each(it : es of vector<tuple>)
		{
			it->x--; it->y--;
			G.add_edge(it->x, it->y);
			G.add_edge(it->y, it->x);
		}
		dfs<int> DFS(G[0], &cut, &goal);
		vector<dfs_node<int> >& res = DFS.search();
		if(res.size() == 0)
			return;
		res = DFS.back().search();
		res = DFS.back().search();
		if(res.size() > 0)
			return;
		if(G.linked_count(0) != n)
			return;
		ans = "FHTAGN!";
	}
	static bool goal(const vector<dfs_node<int> >& ns)
	{
		if(ns.size() < 4)
			return false;
		node<int>& last = ns.back().get_node();
		each(i : ns.size() - 3)
			if(ns[i].get_node().value() == last.value())
				return true;
		return false;
	}
	static bool cut(const vector<dfs_node<int> >& ns)
	{
		int n = ns.size();
		if(n < 3)
			return false;
		return ns[n-1].get_node().value() == ns[n-3].get_node().value();
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
