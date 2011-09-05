#include <iostream>
#include <vector>
#include <map>
#include <bitset>
#include <stdlib.h>
#include <algorithm>
using namespace std;

void draw(vector<char>& colors, vector<string>& office, int i, int j, char c)
{
	if(i < 0 || i >= office.size() || j < 0 || j >= office[0].length())
		return;
	if(office[i][j] == c)
	{
		office[i][j] = '.';
		draw(colors, office, i-1, j, c);
		draw(colors, office, i+1, j, c);
		draw(colors, office, i, j-1, c);
		draw(colors, office, i, j+1, c);
	}
	else if(office[i][j] != '.')
	{
		if(count(colors.begin(), colors.end(), office[i][j]) == 0)
		{
			colors.push_back(office[i][j]);
			office[i][j] = '.';
		}
	}
}

int main()
{
	int n, m;
	char c;
	cin >> n >> m >> c;
	vector<string> office(n);
	for(int i = 0; i < n; i++)
		cin >> office[i];
	vector<char> colors;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(office[i][j] == c)
			{
				draw(colors, office, i, j, c);
				cout << colors.size() << endl;
				return 0;
			}
		}
	}
}
