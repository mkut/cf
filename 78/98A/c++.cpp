/* aoj header */
#include <set>
#include <vector>
#include <string>

void add2(set<string>& done, string str, vector<int> p)
{
	string tmp(6, ' ');
	for(int i = 0; i < 6; i++)
		tmp[i] = str[p[i]];
	done.insert(tmp);
}

void add(set<string>& done, string str)
{
	int memo[6][2] = {{1,2}, {5,2}, {5,4}, {1,0}, {3,0}, {3,4}};
	vector<int> tmp(6);
	for(int i = 0; i < 6; i++)
	{
		tmp[0] = i; tmp[1] = memo[i][0]; tmp[2] = memo[i][1];
		tmp[3] = 5 - tmp[2]; tmp[4] = 5 - tmp[1]; tmp[5] = 5 - tmp[0];
		add2(done, str, tmp);
		tmp[0] = i; tmp[1] = memo[i][1]; tmp[2] = 5 - memo[i][0];
		tmp[3] = 5 - tmp[2]; tmp[4] = 5 - tmp[1]; tmp[5] = 5 - tmp[0];
		add2(done, str, tmp);
		tmp[0] = i; tmp[1] = 5 - memo[i][0]; tmp[2] = 5 - memo[i][1];
		tmp[3] = 5 - tmp[2]; tmp[4] = 5 - tmp[1]; tmp[5] = 5 - tmp[0];
		add2(done, str, tmp);
		tmp[0] = i; tmp[1] = 5 - memo[i][1]; tmp[2] = memo[i][0];
		tmp[3] = 5 - tmp[2]; tmp[4] = 5 - tmp[1]; tmp[5] = 5 - tmp[0];
		add2(done, str, tmp);
	}
}

int main()
{
	string str;
	cin >> str;
	set<string> done;
	int count = 0;
	for(int i = 0; i < 6*5*4*3*2*1; i++)
	{
		if(!done.count(str))
		{
			count++;
			add(done, str);
		}
		next_permutation(str.begin(), str.end());
	}
	cout << count << endl;

	return 0;
}
