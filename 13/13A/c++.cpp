#include <iostream>
#include <vector>
#include <map>
#include <bitset>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int gcd(int x, int y){
	return x % y == 0 ? y : gcd(y, x % y);
}

int main()
{
	int n;
	cin >> n;
	int sum = 0;
	for(int i = 2; i < n; i++)
	{
		int t = n;
		while(t)
		{
			sum += t % i;
			t /= i;
		}
	}
	cout << sum / gcd(sum, n - 2) << "/" << (n - 2) / gcd(sum, n - 2) << endl;
	
	return 0;
}
