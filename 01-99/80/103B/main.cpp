#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;

template<class T>
class node {
private:
	vector<node<T>*> next_nodes;
	T v;
public:
	node(T v) : v(v) {}
	node<T>& add_edge(node<T>* n) {
		next_nodes.push_back(n);
		return *this;
	}
	node<T>& next_node(int i) {
		assert(next_nodes.size() > i);
		return *next_nodes[i];
	}
	int next_node_size() {
		return next_nodes.size();
	}
	T& value() {
		return v;
	}
};

class directed_graph {
private:
	vector<node<int>*> nodes;
public:
	directed_graph(int n) : nodes(n) {
		for(int i = 0; i < n; i++) {
			nodes[i] = new node<int>(i);
		}
	}
	~directed_graph() {
		for(vector<node<int>*>::iterator it = nodes.begin(); it != nodes.end(); ++it) {
			delete *it;
		}
	}
	directed_graph& add_edge(int from, int to) {
		nodes[from]->add_edge(nodes[to]);
		return *this;
	}
	node<int>& operator[](int x) {
		return *nodes[x];
	}
	int linked_count(int n) {
		vector<char> done(nodes.size());
		return linked_count(n, done);
	}
	int linked_count(int n, vector<char>& done) {
		if(done[n])
			return 0;
		done[n] = 1;
		int ret = 1;
		for(int i = 0; i < nodes[n]->next_node_size(); i++) {
			ret += linked_count(nodes[n]->next_node(i).value(), done);
		}
		return ret;
	}
};

template<class T>
class dfs_node {
private:
	int choice;
	node<T>* n;
public:
	dfs_node(node<T>& n) : n(&n), choice(0) {}
	dfs_node next_node() {
		return dfs_node(n->next_node(choice++));
	}
	bool has_next_node() {
		return n->next_node_size() > choice;
	}
	node<T>& get_node() const {
		return *n;
	}
};

template<class T>
class dfs {
private:
	vector<dfs_node<T> > trace;
	bool (*cut)(const vector<dfs_node<T> >&);
	bool (*goal)(const vector<dfs_node<T> >&);
	bool not_found;
public:
	dfs(node<T>& init, bool (*cut)(const vector<dfs_node<T> >&), bool (*goal)(const vector<dfs_node<T> >&))
		: cut(cut), goal(goal), not_found(false) {
		trace.push_back(dfs_node<T>(init));
	}
	dfs& step() {
		if(trace.size() == 0) {
			not_found = true;
		}
		else if(cut(trace)) {
			back();
		}
		else if(trace.back().has_next_node()) {
			trace.push_back(trace.back().next_node());
		}
		else {
			back();
		}
		return *this;
	}
	dfs& back() {
		if(trace.size()) {
			trace.pop_back();
		}
		return *this;
	}
	dfs_node<T>& top() {
		return trace.back();
	}
	vector<dfs_node<T> >& search() {
		for(; !not_found && !goal(trace); step());
		return trace;
	}
};

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
	vector_reader(vector<T>& v, format f, arg a, int arg1) {
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
	friend istream& operator>>(istream& is, solver& cl){
		is >> cl.n >> vector_reader<tuple >(cl.es, vector_reader<tuple>::FORMAT_LEN_VEC);
		return is;
	}
	friend ostream& operator<<(ostream& os, solver& cl){
		os << cl.ans << endl;
		return os;
	}
	void solve()
	{
		ans = "NO";
		directed_graph G(n);
		for(vector<tuple>::iterator it = es.begin(); it != es.end(); ++it)
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
		for(int i = 0; i < ns.size() - 3; i++)
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
