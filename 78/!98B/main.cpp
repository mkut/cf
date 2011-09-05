#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

unsigned long long log2ceil(unsigned long long x)
{
	unsigned long long ret = 0;
	for(x--; x; x>>=1, ret++);
	return ret;
}
unsigned long long pow2(unsigned long long x)
{
	return 1ULL << x;
}
unsigned long long gcd(unsigned long long x, unsigned long long y)
{
	return y == 0ULL ? x : gcd(y, x % y);
}

int main()
{
	unsigned long long n; cin >> n;
	unsigned long long t = 0;
	while(!(n&1)) t++, n>>=1;
	unsigned long long b = log2ceil(n);
	unsigned long long k = pow2(b) * b;
	unsigned long long _gcd = gcd(k, n);
	k /= _gcd;
	n /= _gcd;
	cout << k + t * n << "/" << n << endl;
	return 0;
}
