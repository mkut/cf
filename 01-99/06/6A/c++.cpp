#include <iostream>
#include <vector>
#include <map>
#include <bitset>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> vi(4);
	for(int i = 0; i < 4; i++)
		cin >> vi[i];
	sort(vi.begin(), vi.end());
	int ans = 0;
	if(vi[0] + vi[1] > vi[2])
		ans = 2;
	else if(vi[0] + vi[1] == vi[2])
		ans = 1;
	if(vi[1] + vi[2] > vi[3])
		ans = max(ans, 2);
	else if(vi[1] + vi[2] == vi[3])
		ans = max(ans, 1);
	
	cout << (ans == 0 ? "IMPOSSIBLE" : (ans == 1 ? "SEGMENT" : "TRIANGLE")) << endl;
		
	return 0;
}
