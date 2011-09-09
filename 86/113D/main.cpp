#include <iostream>
#include <cstdio>
#include <algorithm>
#include <sys/time.h>
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


struct point {
	int x, y;
	friend istream& operator>>(istream& is, point& p) {
		return is >> p.x >> p.y;
	}
};

class solver
{
private:
	int n, m, a, b;
	vector<point> vp;
	vector<double> ps;
	vector<double> ans;
public:
	friend istream& operator>>(istream& is, solver& cl){
		is >> cl.n >> cl.m >> cl.a >> cl.b;
		is >> vector_reader<point >(cl.vp, vector_reader<point>::FORMAT_VEC, vector_reader<point>::ARG_LENGTH, cl.m);
		is >> vector_reader<double >(cl.ps, vector_reader<double>::FORMAT_VEC, vector_reader<double>::ARG_LENGTH, cl.n);
		return is;
	}
	friend ostream& operator<<(ostream& os, solver& cl){
		os << vector_writer<double >(cl.ans, '\n') << endl;
		return os;
	}
	solver() : vp(), ps() {}
	void solve()
	{
		a--; b--;
		vector<vector<int> > lnk(n);
		vector<vector<double> > prob(n, vector<double>(n));
		for(vector<point>::iterator it = vp.begin(); it != vp.end(); ++it)
		{
			lnk[it->x-1].push_back(it->y-1);
			lnk[it->y-1].push_back(it->x-1);
		}
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if(i == j)
					prob[i][j] = ps[i];
				else if(find(lnk[i].begin(), lnk[i].end(), j) != lnk[i].end())
					prob[i][j] = (1 - ps[i]) / lnk[i].size();
		double A[256][256] = {};
		double B[256][256] = {};
		for(int cnt = 0, i = 0; i < n; i++)
			for(int j = i; j < n; j++, cnt++)
				if(i == j)
					A[cnt][cnt] = 1;
				else
					for(int cnt2 = 0, ii = 0; ii < n; ii++)
						for(int jj = ii; jj < n; jj++, cnt2++)
							if(ii == jj)
								A[cnt2][cnt] = prob[i][ii] * prob[j][jj];
							else
								A[cnt2][cnt] = prob[i][ii] * prob[j][jj] + prob[i][jj] * prob[j][ii];
		int ns = n * (n+1) / 2;
		for(int it = 0; it < 17; it++)
		{
			for(int i = 0; i < ns; i++)
				for(int j = 0; j < ns; j++)
					for(int k = 0; k < ns; k++)
						B[i][j] += A[i][k] * A[k][j];
			for(int j = 0; j < ns; j++)
			{
				double s = 0;
				for(int i = 0; i < ns; i++)
				{
					A[i][j] = B[i][j];
					B[i][j] = 0;
					if(A[i][j] < 1e-20)
						A[i][j] = 0;
					s += A[i][j];
				}
				for(int i = 0; i < ns; i++)
					A[i][j] /= s;
			}
		}
		vector<double> I(ns), J(ns);
		for(int cnt = 0, i = 0; i < n; i++)
			for(int j = i; j < n; j++, cnt++)
				if(i == a && j == b || i == b && j == a)
					I[cnt] = 1;
		for(int i = 0; i < ns; i++)
			for(int j = 0; j < ns; j++)
				J[i] += A[i][j] * I[j];

		ans = vector<double>(n);
		for(int cnt = 0, i = 0; i < n; i++)
			for(int j = i; j < n; j++, cnt++)
				if(i == j)
					ans[i] = J[cnt];
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
