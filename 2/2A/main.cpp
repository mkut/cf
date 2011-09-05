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


struct hist
{
	string name;
	int point;
	friend istream& operator>>(istream& is, hist& h) {
		cin >> h.name >> h.point;
	}
};

class solver
{
private:
	vector<hist> hs;
	string ans;
public:
	friend istream& operator>>(istream& is, solver& cl){
		is >> vector_reader<hist >(cl.hs, vector_reader<hist>::FORMAT_LEN_VEC);
		return is;
	}
	friend ostream& operator<<(ostream& os, solver& cl){
		os << cl.ans << endl;
		return os;
	}
	void solve()
	{
		map<string, int> score;
		for(vector<hist>::iterator h = hs.begin(); h != hs.end(); ++h)
			score[h->name] += h->point;
		vector<string> hiname;
		int hiscore = -1000000;
		for(map<string, int>::iterator s = score.begin(); s != score.end(); ++s)
		{
			if(s->second > hiscore)
			{
				hiname = vector<string>();
				hiname.push_back(s->first);
				hiscore = s->second;
			}
			else if(s->second == hiscore)
			{
				hiname.push_back(s->first);
			}
		}
		score.clear();
		for(vector<hist>::iterator h = hs.begin(); h != hs.end(); ++h)
		{
			if(find(hiname.begin(), hiname.end(), h->name) != hiname.end())
			{
				score[h->name] += h->point;
				if(score[h->name] >= hiscore)
				{
					ans = h->name;
					return;
				}
			}
		}
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
