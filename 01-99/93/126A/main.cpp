#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

class solver
{
private:
	long long t1, t2, x1, x2, t0, y1, y2;
	string space;
public:
	friend istream& operator>>(istream& is, solver& cl){
		is >> cl.t1 >> cl.t2 >> cl.x1 >> cl.x2 >> cl.t0;
		return is;
	}
	friend ostream& operator<<(ostream& os, solver& cl){
		os << cl.y1 << cl.space << cl.y2 << endl;
		return os;
	}
	void solve()
	{
		space = " ";
		y1 = 0;
		y2 = x2;
		for(int i = 0; i <= x2; i++)
		{
			long long _y2 = i;
			long long _y1 = binary(0, x1 + 1, _y2);
			if((_y1 * t1 + _y2 * t2) * (y1 + y2) <= (y1 * t1 + y2 * t2) * (_y1 + _y2))
			{
				y1 = _y1;
				y2 = _y2;
			}
		}
	}

	long long binary(long long a, long long b, long long y)
	{
		if(b - a <= 1)
			return a;
		long long mid = (a + b) / 2;
		if((mid * t1 + y * t2) >= t0 * (y + mid))
			return binary(mid, b, y);
		else
			return binary(a, mid, y);
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
	return 0;
}
