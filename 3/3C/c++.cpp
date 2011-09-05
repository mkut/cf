#include <iostream>
#include <map>
using namespace std;

class solver
{
	map<string, string> ans;
	
  public:
	solver()
	{
		_solve(".........", true);
	}
	
	
	string solve(string str)
	{
		if(ans.count(str) != 0) return ans[str];
		return "illegal";
	}
	
  private:
	void _solve(string str, bool first)
	{
		if(ans.count(str) != 0) return;
		
		if(win(str) != "")
		{
			ans[str] = win(str);
			return;
		}
		else ans[str] = first ? "first" : "second";
		
		for(int i = 0; i < 9; i++)
		{
			if(str[i] == '.')
			{
				string tstr = str;
				tstr[i] = first ? 'X' : '0';
				_solve(tstr, !first);
			}
		}
	}
	
	string win(string str)
	{
		int check[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
		for(int i = 0; i < 8; i++)
		{
			if(str[check[i][0]] == str[check[i][1]] && str[check[i][0]] == str[check[i][2]] && str[check[i][0]] != '.')
			{
				return str[check[i][0]] == 'X' ? "the first player won" : "the second player won";
			}
		}
		for(int i = 0; i < 9; i++)
		{
			if(str[i] == '.') return "";
		}
		return "draw";
	}
};

int main()
{
	solver prob;
	
	string input[3];
	cin >> input[0] >> input[1] >> input[2];
	cout << prob.solve(input[0] + input[1] + input[2]) << endl;
	return 0;
}