#include <iostream>
#include <cstdio>
#include <algorithm>
#include <sstream>
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


class solver
{
private:
	vector<string> vs;
	vector<string> ans;
public:
	friend istream& operator>>(istream& is, solver& cl){
		is >> vector_reader<string >(cl.vs, vector_reader<string>::FORMAT_LEN_VEC);
		return is;
	}
	friend ostream& operator<<(ostream& os, solver& cl){
		os << vector_writer<string >(cl.ans, '\n') << endl;
		return os;
	}
	int ipow(int x, int y)
	{
		int ret = 1;
		for(int i = 0; i < y; i++)
			ret *= x;
		return ret;
	}
	int atoi(string str)
	{
		stringstream ss;
		ss << str;
		int ret;
		ss >> ret;
		return ret;
	}
	int stoi (string str)
	{
		int ret = 0;
		for(int i = 0; i < str.length(); i++)
			ret = ret * 26 + str[i] - 'A';
		for(int i = 0; i < str.length(); i++)
			ret += ipow(26, i);
		return ret;
	}
	string itos(int x, int len)
	{
		string ret(len, 'A');
		for(int i = len-1; i >= 0; i--)
		{
			ret[i] = x % 26 + 'A';
			x /= 26;
		}
		return ret;
	}
	string itos(int x)
	{
		string ret;
		int len;
		for(len = 0; x >= ipow(26, len); len++)
			x -= ipow(26, len);
		return itos(x, len);
	}
	bool isrc(string str)
	{
		bool cur_num = true;
		int change = 0;
		for(int i = 0; i < str.length(); i++)
			if(cur_num && str[i] >= 'A' && str[i] <= 'Z')
				cur_num = false, change++;
			else if(!cur_num && str[i] >= '0' && str[i] <= '9')
				cur_num = true, change++;
		return change > 2;
	}
	string conv(string str)
	{
		if(isrc(str))
		{
			int col = atoi(str.substr(str.find("C")+1));
			int row = atoi(str.substr(1, str.find("C")-1));
			stringstream ss;
			ss << itos(col) << row;
			return ss.str();
		}
		else
		{
			int pos;
			for(pos = 0; str[pos] >= 'A' && str[pos] <= 'Z'; pos++);
			int col = stoi(str.substr(0, pos));
			int row = atoi(str.substr(pos));
			stringstream ss;
			ss << "R" << row << "C" << col;
			return ss.str();
		}
	}
	void solve()
	{
		for(int i = 0; i < vs.size(); i++)
			ans.push_back(conv(vs[i]));
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
