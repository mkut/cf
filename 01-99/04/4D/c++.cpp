#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<pair<int,int>, int> card;

class solver
{
  public:
	vector<card> cs;
	vector<int> ans;
	vector<int> prev;
	
	solver(vector<card> cs)
	{
		this->cs = cs;
		this->ans = vector<int>(cs.size());
		this->prev = vector<int>(cs.size());
	}
	
	int solve()
	{
		int __max = -1;
		int max_origin = 0;
		ans[0] = 0;
		for(int i = 1; i < cs.size(); i++)
		{
			int _max = -1;
			int _prev = 0;
			for(int j = 0; j < i; j++)
			{
				if(ans[j] > _max && cs[i].first.second > cs[j].first.second && cs[i].first.first > cs[j].first.first)
				{
					_max = ans[j];
					_prev = j;
				}
			}
			ans[i] = _max + 1;
			prev[i] = _prev;
			if(ans[i] > __max)
			{
				__max = ans[i];
				max_origin = i;
			}
		}
		return max_origin;
	}
};

bool operator<(card& a, card& b)
{
	return a.first.first < b.first.second;
}

int main()
{
	int n, w, h;
	cin >> n >> w >> h;
	vector<card> cs;
	cs.push_back(card(pair<int,int>(w, h), 0));
	for(int i = 1; i <= n; i++)
	{
		int tw, th;
		cin >> tw >> th;
		if(tw > w && th > h) cs.push_back(card(pair<int,int>(tw, th), i));
	}
	sort(cs.begin(), cs.end());
	solver prob(cs);
	
	int origin = prob.solve();
	cout << prob.ans[origin] << endl;
	
	vector<int> ans;
	for(int i = origin; i != 0; i = prob.prev[i])
	{
		ans.push_back(prob.cs[i].second);
	}
	reverse(ans.begin(), ans.end());
	for(int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
	
	return 0;
}