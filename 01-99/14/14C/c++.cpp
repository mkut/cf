#include <iostream>
#include <vector>
#include <map>
#include <bitset>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main()
{
	bool ok = true;

	vector<int> tatex, yokoy;
	vector<pair<int,int> > tated, yokod;
	for(int i = 0; i < 4; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if(x1 == x2)
		{
			if(y1 == y2) ok = false;
			tatex.push_back(x1);
			tated.push_back(pair<int,int>(min(y1,y2),max(y1,y2)));
		}
		else if(y1 == y2)
		{
			yokoy.push_back(y1);
			yokod.push_back(pair<int,int>(min(x1,x2),max(x1,x2)));
		}
	}
	
	if(!ok)
	{
		cout << "NO" << endl;
		return 0;
	}
	
	if(tatex.size() != 2 || yokoy.size() != 2)
	{
		cout << "NO" << endl;
		return 0;
	}
	
	if(tated[0] != tated[1] || yokod[0] != yokod[1])
	{
		cout << "NO" << endl;
		return 0;
	}
	
	if(tated[0] != pair<int,int>(min(yokoy[0], yokoy[1]), max(yokoy[0], yokoy[1])))
	{
		cout << "NO" << endl;
		return 0;
	}
	
	if(yokod[0] != pair<int,int>(min(tatex[0], tatex[1]), max(tatex[0], tatex[1])))
	{
		cout << "NO" << endl;
		return 0;
	}
	
	cout << "YES" << endl;
	
	return 0;
}
