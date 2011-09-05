#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class solver
{
  private:
	int length;
	int start;
	string input;
	vector<pair<int, int> > cost;
	int costpos;
	map<int, pair<int, string> > dp_prev;
	
  public:
	solver(string input, vector<pair<int, int> > cost)
	{
		this->length = input.length();
		this->input = " " + input;
		this->cost = cost;
	}
	
	pair<int, string> solve()
	{
		if(length % 2 == 1) return pair<int, string>(-1, "");
		
		this->costpos = -1;
		start = 0;
		dp_prev[0] = pair<int, string>(0, "");
		dp_prev[2] = pair<int, string>(-1, "");
		for(int i = 1; i <= length; i++)
		{
			if(input[i] == '?')
			{
				_solveLR(i);
			}
			else if(input[i] == '(')
			{
				_solveL(i);
			}
			else if(input[i] == ')')
			{
				_solveR(i);
			}
		}
		return dp_prev[0];
	}
	
	void _solveL(int x)
	{
		start++;
		map<int, pair<int, string> > dp_cur;
		dp_cur[start-2] = pair<int, string>(-1, "");
		for(int i = start; ; i+= 2)
		{
			if(i > length - x || dp_prev.count(i+1) == 0)
			{
				dp_cur[i] = pair<int, string>(-1, "");
				break;
			}
			int _min1 = dp_prev[i-1].first == -1 ? -1 : dp_prev[i-1].first;
			dp_cur[i] = pair<int, string>(_min1, dp_prev[i-1].second + '(');
		}
		dp_prev = dp_cur;
	}
	void _solveR(int x)
	{
		start += start == 0 ? 1 : -1;
		map<int, pair<int, string> > dp_cur;
		dp_cur[start-2] = pair<int, string>(-1, "");
		for(int i = start; ; i+= 2)
		{
			if(i > length - x || dp_prev.count(i+1) == 0)
			{
				dp_cur[i] = pair<int, string>(-1, "");
				break;
			}
			int _min2 = dp_prev[i+1].first == -1 ? -1 : dp_prev[i+1].first;
			dp_cur[i] = pair<int, string>(_min2, dp_prev[i+1].second + ')');
		}
		dp_prev = dp_cur;
	}
	void _solveLR(int x)
	{
		start += start == 0 ? 1 : -1;
		map<int, pair<int, string> > dp_cur;
		costpos++;
		dp_cur[start-2] = pair<int, string>(-1, "");
		for(int i = start; ; i+= 2)
		{
			if(i > length - x || dp_prev.count(i+1) == 0)
			{
				dp_cur[i] = pair<int, string>(-1, "");
				break;
			}
			int _min1 = dp_prev[i-1].first == -1 ? -1 : dp_prev[i-1].first + cost[costpos].first;
			int _min2 = dp_prev[i+1].first == -1 ? -1 : dp_prev[i+1].first + cost[costpos].second;
			if((_min1 < _min2 && _min1 != -1) || _min2 == -1)
			{
				dp_cur[i] = pair<int, string>(_min1, dp_prev[i-1].second + '(');
			}
			else
			{
				dp_cur[i] = pair<int, string>(_min2, dp_prev[i+1].second + ')');
			}
		}
		dp_prev = dp_cur;
	}
};

int main()
{
	string input;
	vector<pair<int, int> > cost;
	cin >> input;
	
	for(int bla1, bla2; cin >> bla1 >> bla2;)
	{
		cost.push_back(pair<int, int>(bla1, bla2));
	}
	
	solver prob(input, cost);
	
	pair<int, string> ans = prob.solve();
	if(ans.first != -1)
	{
		cout << ans.first << endl << ans.second << endl;
	}
	else
	{
		cout << -1 << endl;
	}
	
	return 0;
}