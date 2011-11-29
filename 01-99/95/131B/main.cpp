#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
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


typedef long long ll;

class solver
{
private:
	vector<ll> v;
	map<int, ll> count;
	ll ans;
public:
	friend istream& operator>>(istream& is, solver& cl){
		is >> vector_reader<ll >(cl.v, vector_reader<ll>::FORMAT_LEN_VEC);
		return is;
	}
	friend ostream& operator<<(ostream& os, solver& cl){
		os << cl.ans << endl;
		return os;
	}
	void solve()
	{
		for(vector<ll>::iterator it = v.begin(); it != v.end(); ++it)
			count[*it]++;
		ans = 0;
		for(map<int, ll>::iterator it = count.begin(); it != count.end(); ++it)
			if(it->first == 0)
				ans += it->second * (it->second - 1);
			else
				ans += it->second * count[- it->first];
		ans /= 2;
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
