#include <milib/template/aoj>

int main()
{
	long long n, x, y;
	cin >> n >> x >> y;
	if(n > y)
	{
		cout << -1 << endl;
	}
	else if((y - n + 1) * (y - n + 1) + (n-1) >= x)
	{
		cout << y - n + 1 << endl;
		for(int i = 1; i < n; i++)
			cout << 1 << endl;
	}
	else
	{
		cout << -1 << endl;
	}
	return 0;
}
