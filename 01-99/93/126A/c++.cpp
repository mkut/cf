#include <milib/template/aoj>

class solver
{
private:
	long long t1, t2, x1, x2, t0, y1, y2;
	string space;
public:
	//>>[solver
	t1 t2 x1 x2 t0
	//>>]
	//<<[solver
	y1 space y2
	//<<]
	void solve()
	{
		space = " ";
		y1 = 0;
		y2 = x2;
		each(i : 0...x2)
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
