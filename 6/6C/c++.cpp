#include <iostream>
#include <vector>
#include <map>
#include <bitset>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> vi(n);
	for(int i = 0; i < n; i++)
		cin >> vi[i];
	
	int A = 0, B = 0;
	int iA = 0, iB = n-1;
		
	while(iB - iA >= 0)
	{
		if(A <= B)
			A += vi[iA++];
		else
			B += vi[iB--];
	}
	cout << iA << " " << n-iA << endl;
	
	return 0;
}
