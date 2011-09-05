#include <iostream>
#include <vector>
#include <map>
#include <bitset>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<string> draw(n);
	for(int i = 0; i < n; i++)
		cin >> draw[i];
	
	for(int i = 0; i < 2; i++)
	{
		while(draw.size() > 0)
		{
			bool chk = false;
			for(int j = 0; j < draw[0].length(); j++)
				if(draw[0][j] == '*')
				{
					chk = true;
					break;
				}
			if(!chk)
				draw.erase(draw.begin());
			else
				break;
		}
		reverse(draw.begin(), draw.end());
	}
	for(int i = 0; i < 2; i++)
	{
		if(draw.size() == 0)
			break;
		while(draw[0].length() > 0)
		{
			bool chk = false;
			for(int j = 0; j < draw.size(); j++)
				if(draw[j][0] == '*')
				{
					chk = true;
					break;
				}
			if(!chk)
				for(int j = 0; j < draw.size(); j++)
					draw[j] = draw[j].substr(1);
			else
				break;
		}
		for(int j = 0; j < draw.size(); j++)
			reverse(draw[j].begin(), draw[j].end());
	}
	
	for(int i = 0; i < draw.size(); i++)
	{
		for(int j = 0; j < draw[i].size(); j++)
			cout << draw[i][j];
		cout << endl;
	}
	
	return 0;
}
