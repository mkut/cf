#include <iostream>
using namespace std;

int main()
{
	int d, sum;
	cin >> d >> sum;
	int _min = 0, _max = 0;
	int mint[30], maxt[30];
	for(int i = 0; i < d; i++)
	{
		cin >> mint[i] >> maxt[i];
		_min += mint[i];
		_max += maxt[i];
	}
	if(_min <= sum && sum <= _max)
	{
		cout << "YES" << endl;
		for(int i = 0; i < d; i++)
		{
			if(maxt[i]-mint[i] <= sum-_min)
			{
				cout << maxt[i];
				sum -= maxt[i]-mint[i];
			}
			else
			{
				cout << mint[i] + sum-_min;
				sum = _min;
			}
			cout << " ";
		}
		cout <<endl;
	}
	else cout << "NO" << endl;
	return 0;
}