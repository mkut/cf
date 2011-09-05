/* aoj header */

long long log2ceil(long long x)
{
	long long ret = 0;
	for(x--; x; x>>=1, ret++);
	return ret;
}
long long pow2(long long x)
{
	return 1ULL << x;
}
long long gcd(long long x, long long y)
{
	return y == 0ULL ? x : gcd(y, x % y);
}

int main()
{
	long long n; cin >> n;
	long long t = 0;
	while(!(n&1)) t++, n>>=1;
	long long b = log2ceil(n);
	long long k = pow2(b) * b;
	long long _gcd = gcd(k, n);
	k /= _gcd;
	n /= _gcd;
	cout << k + t * n << "/" << n << endl;
	return 0;
}
