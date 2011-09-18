#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cassert>
using namespace std;//

template<class T>//
istream& operator>>(istream& is, vector<T>& v);//
template<class T>//
ostream& operator<<(ostream& os, vector<T>& v);//
template<class T>//
class vector_reader;//
template<class T>//
class vector_writer;//

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
private:
	vector<T>& v;
	int size;
public:
	vector_reader(vector<T>& v, int size) : v(v), size(size) {}
	friend istream& operator>>(istream& is, vector_reader vr) {
		vr.v = vector<T>(vr.size);
		return is >> vr.v;
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


template<int N>//
vector<int>& make_primes(vector<int>& ret);//

template<int N>
vector<int>& make_primes(vector<int>& ret) {
	ret = vector<int>();
	bool notprime[N] = {true, true};
	for(int i = 2; i < N; i++) {
		if(!notprime[i]) {
			for(int j = i+i; j < N; j+=i)
				notprime[j] = true;
			ret.push_back(i);
		}
	}
	return ret;
}

class multi_adic {
protected:
	vector<int> adic;
	vector<int> value;
public:
	multi_adic(vector<int> adic) : adic(adic), value(adic.size()) { }
	multi_adic& operator=(long long x) {
		for(int i = 0; i < adic.size(); i++) {
			value[i] = x % adic[i];
			x /= adic[i];
		}
		return *this;
	}
	multi_adic operator+(long long x) {
		multi_adic ret = *this;
		for(int i = 0; i < adic.size(); i++) {
			x += ret.value[i];
			ret.value[i] = x % adic[i];
			x /= adic[i];
		}
		return ret;
	}
	multi_adic operator+(multi_adic x) {
		multi_adic ret = *this;
		int carry = 0;
		for(int i = 0; i < adic.size(); i++) {
			carry += ret.value[i] + x.value[i];
			ret.value[i] = carry % adic[i];
			carry /= adic[i];
		}
		return ret;
	}
	multi_adic operator++(int) {
		multi_adic ret = *this;
		*this = *this + 1;
		return ret;
	}
	const vector<int>& get_value() {
		return value;
	}
};

class divisor : multi_adic {
private:
	vector<int> prime;
public:
	divisor(vector<int> prime, vector<int> exp)
		: prime(prime), multi_adic(exp) {
		assert(prime.size() == exp.size());
	}
	divisor operator++(int) {
		divisor ret = *this;
		multi_adic::operator++(1);
		return ret;
	}
	long long to_ll() {
		long long ret = 1;
		for(int i = 0; i < adic.size(); i++) {
			for(int j = 0; j < value[i]; j++) {
				ret *= prime[i];
			}
		}
		return ret;
	}
};

divisor prime_factorize(int x, vector<int>& primes) {
	vector<int> prime, exp;
	for(int i = 0; x > 2 && i < primes.size(); i++) {
		if(x % primes[i] == 0) {
			prime.push_back(primes[i]);
			exp.push_back(1);
			for(; x % primes[i] == 0; x /= primes[i]) {
				exp.back()++;
			}
		}
	}
	if(x != 1) {
		prime.push_back(x);
		exp.push_back(2);
	}
	return divisor(prime, exp);
}

struct point
{
	int x, y;
	friend istream& operator>>(istream& os, point& p) {
		return cin >> p.x >> p.y;
	}
};

class solver
{
private:
	int n;
	vector<point> data;
	vector<int> ans;
	vector<int> dp;
public:
	friend istream& operator>>(istream& is, solver& cl){
		is >> cl.n;
		is >> vector_reader<point >(cl.data, cl.n);
		return is;
	}
	friend ostream& operator<<(ostream& os, solver& cl){
		os << vector_writer<int >(cl.ans, '\n') << endl;
		return os;
	}
	void solve()
	{
		dp = vector<int>(100010, -1);
		ans = vector<int>(n);
		vector<int> primes;
		make_primes<1000>(primes);
		for(int i = 0; i < n; i++)
		{
			divisor div = prime_factorize(data[i].x, primes);
			do {
				int div_i = div.to_ll();
				if(dp[div_i] < i - data[i].y)
					ans[i]++;
				dp[div_i] = i;
				div++;
			} while(div.to_ll() != 1);
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
	}
}
