#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int main()
{
	string from, to;
	cin >> from >> to;
	
	cout << max(abs(from[0]-to[0]), abs(from[1]-to[1])) << endl;
	while(from != to)
	{
		if(from[0] < to[0]){ cout << "R"; from[0]++; }
		if(from[0] > to[0]){ cout << "L"; from[0]--; }
		if(from[1] < to[1]){ cout << "U"; from[1]++; }
		if(from[1] > to[1]){ cout << "D"; from[1]--; }
		cout << endl;
	}
	
	return 0;
}