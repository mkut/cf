#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
	int N;
	cin >> N;
	map<int, int> L;
	int Max = 0;
	for(int i = 0; i < N; i++)
	{
		int tmp; cin >> tmp;
		L[tmp]++;
		Max = max(Max, L[tmp]);
	}
	
	cout << Max << " " << L.size() << endl;
	
	return 0;
}
