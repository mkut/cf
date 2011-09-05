#include <iostream>
#include <vector>
#include <map>
#include <bitset>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main()
{
	long long a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	bool ok = false;
	ok |= c == 0 && d > 0;
	ok |= a == 0 && b > 0 && d > 0;
	ok |= b * d * f > a * c * e;
	cout << (ok ? "Ron" : "Hermione") << endl;
	return 0;
}
