#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n, m, k; cin >> n >> m >> k; m--; k--;
	string dir; cin >> dir >> dir;
	string move; cin >> move;

	vector<char> possible[2] = {vector<char>(n), vector<char>(n)};
	int cur = 0, prev = 0;
	possible[prev][m] = 1;

	int pos_c = n, d = dir == "head" ? -1 : 1;
	for(int i = 0; i <= move.size(); i++)
	{
		if(i == move.size())
		{
			cout << "Stowaway" << endl;
			break;
		}
		if(pos_c + d < 0 || pos_c + d >= n)
			d *= -1;
		for(int j = 0; j < n; j++)
		{
			if(j-1 >= 0 && possible[prev][j-1] == 1)
				possible[cur][j] = 1;
			else if(possible[prev][j] == 1)
				possible[cur][j] = 1;
			else if(j+1 < n && possible[prev][j+1] == 1)
				possible[cur][j] = 1;
			else if(move[i] == '1')
				possible[cur][j] = 1;
		}
		
		possible[cur][pos_c] = 0;
		possible[cur][pos_c + d] = 0;

		bool done = true;
		for(int j = 0; j < n; j++)
			if(possible[cur][j])
				done = false;

		if(done)
		{
			cout << "Controller " << i+1 << endl;
			break;
		}
	}

	return 0;
}
